#define STRICT
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <process.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <iostream.h>



//using namespace std; //___used for string object

#include "headerFiles/glaux.h"

#include <GL/glu.h>
#include <GL/gl.h>

#include "headerFiles/glaux.h"
#include <fstream.h>
#include "headerFiles/glut.h"

#include "headerFiles/tga.h"

bool keys[256], keypressed[256];
bool active=true;
bool fullscreen=true;

float screenWidth  = 1280;
float screenHeight = 800;

#include "headerFiles/glext.h" 
#include "headerFiles/glext_Init_A.cpp" 

#include "headerFiles/FreeImage.h"
#include "cpp/freeImage.cpp"

#include "headerFiles/VSync.h"


#include <math.h>

//###############################################################################################################################################

#include "MATRIX_MATH.cpp"

//###############################################################################################################################################




bool        writeAnimationFile = false;  

//---------------------------------------------------------------------------------------------------------------------


const       int TEXTURE_WIDTH  = 512; 
const       int TEXTURE_HEIGHT = 512;

GLfloat     gaussianBlurHorizontalPass_counter1           =   1/512.0;
GLfloat     gaussianBlurVerticalPass_counter1             =   1/512.0;

//---------------------------------------

GLuint      fboId;
GLuint      rboId;

GLuint      gaussianBlurHorizontalPass_fboId;
GLuint      gaussianBlurVerticalPass_fboId;


#include  "_MODEL_FOLDERS_/gaussianBlur/gaussianBlurHorizontalPass/gaussianBlurHorizontalPass_vboGlobals.cpp"  //_vboID = 1

#include  "_MODEL_FOLDERS_/gaussianBlur/gaussianBlurVerticalPass/gaussianBlurVerticalPass_vboGlobals.cpp"      //_vboID = 2




//========================================================================================================================================================================    
GLfloat     modelView[16];
GLfloat     projection[16];
GLfloat     mvpMatrix[16];
GLfloat     mvpMatrixInverse[16];
GLfloat     lightMatrix[16];  
GLfloat     moveSetMatrix[16]; 

GLuint      UNIFORM_MODELVIEWPROJ;
GLuint      UNIFORM_MODELVIEWPROJ_INVERSE;
GLuint      UNIFORM_LIGHT_MATRIX;
//--------------------------------------------------

//========================================================================================================================================================================                    
                                                            GLfloat moveSet[]                                = {0.0, 0.0, 0.0};
                                                            GLfloat frameRateAdjustment                      =  1.4; 
                                                               
//========================================================================================================================================================================

                                                            GLfloat     moveAllFour[]                        =  { 0.0, -0.1, -0.430001};
                                                            //----------------------------
                                                            GLfloat     marc_TOP_VIEW[]                      =  {-0.6, 1.46, -0.54};
                                                            GLfloat     marc_PERSPECTIVE_VIEW[]              =  {0.69, 1.12, -1.29};
                                                            GLfloat     marc_FRONT_VIEW[]                    =  {-0.68, -0.5, 0};
                                                            GLfloat     marc_SIDE_VIEW[]                     =  {0.7, -0.53, 0};
                                                            //------------------------------------------------------------------------------------------------------------
                                                            GLfloat     lightPos_marc_TOP_VIEW[]             = {  0.312987, 636.999,     53.8509};
                                                            GLfloat     lightPos_marc_PERSPECTIVE_VIEW[]     = {457.315,    290.301,   -215.049};
                                                            GLfloat     lightPos_marc_FRONT_VIEW[]           = {12.913, 100, -149.049};
                                                            GLfloat     lightPos_marc_SIDE_VIEW[]            = {476.015,     95.5997,   -50.6};
                                                            //------------------------------------------------------------------------------------------------------------
                                                            
                                                            GLfloat     lightPos_4view[]                     = {-0.0, -0.971991, -0.512997};
                                                            GLfloat     lightAttenuation_4view               =   1.5;
                                                          
                                                            GLhandleARB marcDisplay_4view_SHADER;
                                                            GLhandleARB marcDisplay_4view_Vertex;
                                                            GLhandleARB marcDisplay_4view_Fragment;
                                                            
                                                            GLuint      UNIFORM_counter_marcDisplay_4view;
                                                            
                                                            GLfloat     moveOutLine[]                        = { 0.0, 0.73, 2.52};
//========================================================================================================================================================================
                                                            GLfloat     rotateTemp1 = 7.0;
                                                            GLfloat     rotateTemp2 = 0.0;


/////////////--------------------------------------------------
GLfloat    positionY = 0.0;
GLfloat    positionX = 0.0;                                  

GLfloat    boundingBox_MAIN_CHARACTER_left_edge  = -0.179;      
GLfloat    boundingBox_MAIN_CHARACTER_right_edge =  0.179; 
GLfloat    boundingBox_MAIN_CHARACTER_lower_edge =  0.01;
GLfloat    boundingBox_MAIN_CHARACTER_upper_edge =  1.253;
GLfloat    boundingBox_MAIN_CHARACTER_near_edge  =  0.179;     
GLfloat    boundingBox_MAIN_CHARACTER_far_edge   = -0.179;

int        numberOfCollisionObjects = 5;

GLfloat    left_edge_SecondaryObjects[500];
GLfloat    right_edge_SecondaryObjects[500];
GLfloat    lower_edge_SecondaryObjects[500];
GLfloat    upper_edge_SecondaryObjects[500];
GLfloat    near_edge_SecondaryObjects[500];
GLfloat    far_edge_SecondaryObjects[500];

bool       RIGHT = true;
bool       LEFT  = true;                                      
bool       UP    = true;
bool       DOWN  = true;

GLfloat    scaleCollisionBlock                     = 0.179;

bool       showCollisionBlocks                     = true;
//================================================================================================================
bool       resetKey_C                              = true;
bool       F_KEY_IS_RESET                          = true;
bool       G_KEY_IS_RESET                          = true; 
//================================================================================================================

bool       spikyBall_mainCharacterHit              = false;
               
               
GLfloat    spikyBallAddsMomentumToMainCharacter[]  = {0.0, 0.0, 0.0};
 
GLuint     collisionHitDrawnOut = 0;

GLuint     objectNumber;

GLfloat    crossHairPosition[]          = {0.0, 0.0, 0.0};



#include  "collisionBlocks.cpp"



float eyePosition[]   = {0.0, -0.0, -8.2};
float look_LEFT_RIGHT =  0.0;
float look_UP_DOWN    =  0.0;



float    spinFloat = 0.0f;



GLuint   textureMap[1000];
GLuint   normalMap[1000];
GLuint   specularMap[1000];

GLuint   cubemapTexture[1];

GLuint   g_uiCubeMapConstants[6] = 
{
    GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB,
	GL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB,
	GL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB,
	GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB,
	GL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB,
	GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB
};

char *g_cCubemaps[6] = 
{

	"CG_ENVIRO_MAPPING/terrain_posx.bmp",
	"CG_ENVIRO_MAPPING/terrain_negx.bmp",
	"CG_ENVIRO_MAPPING/terrain_posy.bmp",
	"CG_ENVIRO_MAPPING/terrain_negy.bmp",
	"CG_ENVIRO_MAPPING/terrain_posz.bmp",
	"CG_ENVIRO_MAPPING/terrain_negz.bmp"
};


void    loadCubeMap(void);
//#include "CG_ENVIRO_MAPPING/loadCubeMap.cpp"
///______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\                                 
///______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\
///______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\
///______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\                                 
///______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\
///______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\
///______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\                                 
///______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\
///______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\


HDC	hDC = NULL;
  HGLRC hRC = NULL;
    HWND hWnd = NULL;
      HINSTANCE hInstance = NULL;

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance, 
				   LPSTR lpCmdLine, int nCmdShow);
   LRESULT CALLBACK WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

      void render  (void);
        void Init    (void);
          void shutDown(void);
            unsigned char *readShaderFile(const char *fileName);
              void initShader(void);
                void ProcessKeyboard();
                 
                 void readstr(FILE *f,char *string);
////////________________________________________________________________________________________________________________________________
////////________________________________________________________________________________________________________________________________
////////________________________________________________________________________________________________________________________________
////////________________________________________________________________________________________________________________________________
////////________________________________________________________________________________________________________________________________
////////________________________________________________________________________________________________________________________________

            
//------------------------------
bool      leftMouseActivated                    = false;
bool      rightMouseActivated                   = false;
//------------------------------
GLfloat   mousePositionX                        = 0;
GLfloat   mousePositionY                        = 0;
//------------------------------
GLfloat   secondaryModelPosition[]              = {0, 0.069, -0.007};
GLfloat   scaleModel                            =  0.498; 
//------------------------------       
bool      homeButtonPushed                      = false;
bool      endButtonPushed                       = false;  
//------------------------------
GLfloat   runSlowMotion                         = 1.0;
//------------------------------
bool      hips_POSITION_AnimationSequence             = false;
//------------------------------
GLfloat   hips_POSITION_MOVE_FRAMEA[]                 = {0, 0, 0};
GLfloat   hips_POSITION_MOVE_FRAMEB[]                 = {0, 0, 0};
//------------------------------
GLfloat   hips_POSITION_SET_01[]                      = {0, 0, 0};
GLfloat   hips_POSITION_SET_02[]                      = {0, 0, 0};
GLfloat   hips_POSITION_SET_03[]                      = {0, 0, 0};
GLfloat   hips_POSITION_SET_04[]                      = {0, 0, 0};
GLfloat   hips_POSITION_SET_05[]                      = {0, 0, 0};
GLfloat   hips_POSITION_SET_06[]                      = {0, 0, 0};
GLfloat   hips_POSITION_SET_07[]                      = {0, 0, 0};
//------------------------------
int       hips_POSITION_setSelection                  = 1;
int       hips_POSITION_setSelectionLimit             = 0;
int       hips_POSITION_SelectionCount                = 0;
GLfloat   hips_POSITION_animationBlendFactor          = 0.032;
//------------------------------
GLfloat   hips_POSITION_ROTATION_FRAME_TIME[]         = { 0.04, 0.04, 0.04, 0.04, 0.04, 0.04, 0.04};
//--------------------------------------------------------------------------------------------------------------

      bool      hips_AnimationSequence               = false;     
     
      int hipsSelection                              = 0;
      GLfloat hips_POSITION[]                              = {0, 0, 0};
      GLfloat hips_ROTATE[]                          = {0.0f, 1.0f, 0.0f, 0.0f};///THETA =[4],_XYZaxis=[0][1][2]__
      GLfloat hips_ROTATE_FRAMEA[]                   = {1.0f, 0.0f, 1.0f, 0.0f};///THETA =[4],_XYZaxis=[0][1][2]__       
      GLfloat hips_ROTATE_FRAMEB[]                   = {1.0f, 0.0f, 1.0f, 0.0f};///THETA =[4],_XYZaxis=[0][1][2]__
      GLfloat hips_ROTATE_FRAME_LOOP_RESET[]         = {1.0f, 0.0f, 0.0f, 0.0f};      
      
      GLfloat hips_SET_01[]                          = {1.0f, 0.0f, 0.0f, 0.0f};
      GLfloat hips_SET_02[]                          = {1.0f, 0.0f, 0.0f, 0.0f};
      GLfloat hips_SET_03[]                          = {1.0f, 0.0f, 0.0f, 0.0f};
      GLfloat hips_SET_04[]                          = {1.0f, 0.0f, 0.0f, 0.0f};                       
      GLfloat hips_SET_05[]                          = {1.0f, 0.0f, 0.0f, 0.0f};
      GLfloat hips_SET_06[]                          = {1.0f, 0.0f, 0.0f, 0.0f};
      GLfloat hips_SET_07[]                          = {1.0f, 0.0f, 0.0f, 0.0f};
      
      bool  hips_ROTATE_X                            = false;
      bool  hips_ROTATE_Y                            = false;
      bool  hips_ROTATE_Z                            = false;

      int    setSelection_HIPS                       = 1;
      int    SelectionCount_HIPS                     = 0;
      int    setSelectionLimit_HIPS                  = 0;
      GLfloat  animationBlendFactor_HIPS             = 0.032;

      GLfloat   hips_ROTATION_FRAME_TIME[]           = { 0.04, 0.04, 0.04, 0.04, 0.04, 0.04, 0.04};
//__________________________________________________________________________________________________________________________________
      bool      torso_AnimationSequence               = false;
      
      int torsoSelection                             =  0;
      GLfloat torso_04[]                             = {0, 0.066, 0.014};
      
      GLfloat torso_ROTATE[]                         = {1.0f, 0.0f, 0.0f, 0.0f};///THETA =[4],_XYZaxis=[0][1][2]__
      GLfloat torso_ROTATE_FRAMEA[]                  = {1.0f, 0.0f, 0.0f, 0.0f};///THETA =[4],_XYZaxis=[0][1][2]__       
      GLfloat torso_ROTATE_FRAMEB[]                  = {1.0f, 0.0f, 0.0f, 0.0f};///THETA =[4],_XYZaxis=[0][1][2]__
      GLfloat torso_ROTATE_FRAME_LOOP_RESET[]        = {1.0f, 0.0f, 0.0f, 0.0f};      
      
      GLfloat torso_SET_01[]                         = {1.0f, 0.0f, 0.0f, 0.0f};
      GLfloat torso_SET_02[]                         = {1.0f, 0.0f, 0.0f, 0.0f};
      GLfloat torso_SET_03[]                         = {1.0f, 0.0f, 0.0f, 0.0f};
      GLfloat torso_SET_04[]                         = {1.0f, 0.0f, 0.0f, 0.0f};                       
      GLfloat torso_SET_05[]                         = {1.0f, 0.0f, 0.0f, 0.0f};
      GLfloat torso_SET_06[]                         = {1.0f, 0.0f, 0.0f, 0.0f};
      GLfloat torso_SET_07[]                         = {1.0f, 0.0f, 0.0f, 0.0f};
      
      bool  torso_ROTATE_X                           = false;
      bool  torso_ROTATE_Y                           = false;
      bool  torso_ROTATE_Z                           = false;

      int       setSelection_TORSO                   = 1;
      int       SelectionCount_TORSO                 = 0;
      int       setSelectionLimit_TORSO              = 0;
      GLfloat   animationBlendFactor_TORSO           = 0.032;

      GLfloat   torso_ROTATION_FRAME_TIME[]          = { 0.04, 0.04, 0.04, 0.04, 0.04, 0.04, 0.04};
//__________________________________________________________________________________________________________________________________
              
              bool      head_AnimationSequence         = false;

              
              int       headSelection                  =   0;
              GLfloat   faceMarc_04[]                  = {-0.005, 0.363999, 0.008};

              GLfloat   head_back_04[]                 = { 0, 0, 0};
                
              GLfloat   head_ROTATE[]                  = {0.0f, 1.0f, 0.0f, 0.0f};///THETA =[4],_XYZaxis=[0][1][2]__
              GLfloat   head_ROTATE_FRAMEA[]           = {0.0f, 1.0f, 0.0f, 0.0f};///THETA =[4],_XYZaxis=[0][1][2]__       
              GLfloat   head_ROTATE_FRAMEB[]           = {0.0f, 1.0f, 0.0f, 0.0f};///THETA =[4],_XYZaxis=[0][1][2]__
              GLfloat   head_ROTATE_FRAME_LOOP_RESET[] = {0.0f, 1.0f, 0.0f, 0.0f};      
              
              GLfloat   head_SET_01[]                  = {0.0f, 1.0f, 0.0f, 0.0f};
              GLfloat   head_SET_02[]                  = {0.0f, 1.0f, 0.0f, 0.0f};
              GLfloat   head_SET_03[]                  = {0.0f, 1.0f, 0.0f, 0.0f};
              GLfloat   head_SET_04[]                  = {0.0f, 1.0f, 0.0f, 0.0f};                       
              GLfloat   head_SET_05[]                  = {0.0f, 1.0f, 0.0f, 0.0f};
              GLfloat   head_SET_06[]                  = {0.0f, 1.0f, 0.0f, 0.0f};
              GLfloat   head_SET_07[]                  = {0.0f, 1.0f, 0.0f, 0.0f};
              
              bool      head_ROTATE_X                  = false;
              bool      head_ROTATE_Y                  = false;
              bool      head_ROTATE_Z                  = false;
                    

              int       setSelection_HEAD              = 1;
              int       setSelectionLimit_HEAD         = 0;
              int       SelectionCount_HEAD            = 0;
              GLfloat   animationBlendFactor_HEAD      = 0.032;

              GLfloat   head_ROTATION_FRAME_TIME[]     = { 0.04, 0.04, 0.04, 0.04, 0.04, 0.04, 0.04};
//__________________________________________________________________________________________________________________________________
      
      bool    leftUpperArm_AnimationSequence         = false;      
      
      
      int leftArmSelection                                 = 8;

      GLfloat leftUpperArm_POSITION[]                      = {0.131, 0.308999, -0.025};
      GLfloat leftUpperArm_ROTATE[]                  = {1.0f, 0.0f, 0.0f, 0.0f};///THETA =[3] __XYZaxis=[0][1][2] 
      GLfloat leftUpperArm_ROTATE_FRAMEA[]           = {1.0f, 0.0f, 0.0f, 0.0f};///THETA =[3] __XYZaxis=[0][1][2]       
      GLfloat leftUpperArm_ROTATE_FRAMEB[]           = {1.0f, 0.0f, 0.0f, 0.0f};///THETA =[3] __XYZaxis=[0][1][2]
      GLfloat leftUpperArm_ROTATE_FRAME_LOOP_RESET[] = {1.0f, 0.0f, 0.0f, 0.0f};      
      
      GLfloat leftUpperArm_SET_01[]                  = {1.0f, 0.0f, 0.0f, 0.0f};
      GLfloat leftUpperArm_SET_02[]                  = {1.0f, 0.0f, 0.0f, 0.0f};
      GLfloat leftUpperArm_SET_03[]                  = {1.0f, 0.0f, 0.0f, 0.0f};
      GLfloat leftUpperArm_SET_04[]                  = {1.0f, 0.0f, 0.0f, 0.0f};                       
      GLfloat leftUpperArm_SET_05[]                  = {1.0f, 0.0f, 0.0f, 0.0f};
      GLfloat leftUpperArm_SET_06[]                  = {1.0f, 0.0f, 0.0f, 0.0f}; 
      GLfloat leftUpperArm_SET_07[]                  = {1.0f, 0.0f, 0.0f, 0.0f};                                    

                     GLfloat leftForeArm_POSITION[]                      = {0.01, -0.168, 0.015};
                     GLfloat leftForeArm_ROTATE[]                  = {1.0f, 0.0f, 0.0f, 0.0f};///THETA =[3] __XYZaxis=[0][1][2]                     
                     GLfloat leftForeArm_ROTATE_FRAMEA[]           = {1.0f, 0.0f, 0.0f, 0.0f};///THETA =[3] __XYZaxis=[0][1][2]
                     GLfloat leftForeArm_ROTATE_FRAMEB[]           = {1.0f, 0.0f, 0.0f, 0.0f};///THETA =[3] __XYZaxis=[0][1][2]
                     GLfloat leftForeArm_ROTATE_FRAME_LOOP_RESET[] = {1.0f, 0.0f, 0.0f, 0.0f};      
                     
                     GLfloat leftForeArm_SET_01[]                  = {1.0f, 0.0f, 0.0f, 0.0f};
                     GLfloat leftForeArm_SET_02[]                  = {1.0f, 0.0f, 0.0f, 0.0f};
                     GLfloat leftForeArm_SET_03[]                  = {1.0f, 0.0f, 0.0f, 0.0f};
                     GLfloat leftForeArm_SET_04[]                  = {1.0f, 0.0f, 0.0f, 0.0f};                       
                     GLfloat leftForeArm_SET_05[]                  = {1.0f, 0.0f, 0.0f, 0.0f};
                     GLfloat leftForeArm_SET_06[]                  = {1.0f, 0.0f, 0.0f, 0.0f};
                     GLfloat leftForeArm_SET_07[]                  = {1.0f, 0.0f, 0.0f, 0.0f};
                     

                                    GLfloat leftHand_04[]                      = {-0.0119907, -0.179, 0.041};
                                    GLfloat leftHand_ROTATE[]                  = {0.0f, 1.0f, 0.0f, 0.0f};///THETA =[3] __XYZaxis=[0][1][2]         
                                    GLfloat leftHand_ROTATE_FRAMEA[]           = {0.0f, 1.0f, 0.0f, 0.0f};///THETA =[3] __XYZaxis=[0][1][2]
                                    GLfloat leftHand_ROTATE_FRAMEB[]           = {0.0f, 1.0f, 0.0f, 0.0f};///THETA =[3] __XYZaxis=[0][1][2]
                                    GLfloat leftHand_ROTATE_FRAME_LOOP_RESET[] = {0.0f, 1.0f, 0.0f, 0.0f};      
                                    
                                    GLfloat leftHand_SET_01[]                  = {0.0f, 1.0f, 0.0f, 0.0f};
                                    GLfloat leftHand_SET_02[]                  = {0.0f, 1.0f, 0.0f, 0.0f};
                                    GLfloat leftHand_SET_03[]                  = {0.0f, 1.0f, 0.0f, 0.0f};
                                    GLfloat leftHand_SET_04[]                  = {0.0f, 1.0f, 0.0f, 0.0f};                       
                                    GLfloat leftHand_SET_05[]                  = {0.0f, 1.0f, 0.0f, 0.0f};
                                    GLfloat leftHand_SET_06[]                  = {0.0f, 1.0f, 0.0f, 0.0f};
                                    GLfloat leftHand_SET_07[]                  = {0.0f, 1.0f, 0.0f, 0.0f};


bool   leftUpperArm_ROTATE_X         = false;
bool   leftUpperArm_ROTATE_Y         = false;
bool   leftUpperArm_ROTATE_Z         = false;

bool   leftForeArm_ROTATE_X          = false;
bool   leftForeArm_ROTATE_Y          = false;
bool   leftForeArm_ROTATE_Z          = false;

bool   leftHand_ROTATE_X       = false;
bool   leftHand_ROTATE_Y       = false;
bool   leftHand_ROTATE_Z       = false;

int    setSelection_LEFT_ARM         = 1;
int    SelectionCount_LEFT_ARM       = 0;
int    setSelectionLimit_LEFT_ARM    = 0;
GLfloat  animationBlendFactor_LEFT_ARM = 0.032;

GLfloat   leftArm_ROTATION_FRAME_TIME[]           = { 0.04, 0.04, 0.04, 0.04, 0.04, 0.04, 0.04};
//_________________________________________________________________________________________________________________________________
        
        bool    rightUpperArm_AnimationSequence         = false;  
        
        int rightArmSelection                       = 8;

        GLfloat rightUpperArm_04[]                      = {-0.131, 0.308999, -0.025};
        GLfloat rightUpperArm_ROTATE[]                  = {1.0f, 0.0f, 0.0f, 0.0f};///THETA =[3] __XYZaxis=[0][1][2]         
        GLfloat rightUpperArm_ROTATE_FRAMEA[]           = {1.0f, 0.0f, 0.0f, 0.0f};///THETA =[3] __XYZaxis=[0][1][2]       
        GLfloat rightUpperArm_ROTATE_FRAMEB[]           = {1.0f, 0.0f, 0.0f, 0.0f};///THETA =[3] __XYZaxis=[0][1][2]
        GLfloat rightUpperArm_ROTATE_FRAME_LOOP_RESET[] = {1.0f, 0.0f, 0.0f, 0.0f};      
        
        GLfloat rightUpperArm_SET_01[]                  = {1.0f, 0.0f, 0.0f, 0.0f};
        GLfloat rightUpperArm_SET_02[]                  = {1.0f, 0.0f, 0.0f, 0.0f};
        GLfloat rightUpperArm_SET_03[]                  = {1.0f, 0.0f, 0.0f, 0.0f};
        GLfloat rightUpperArm_SET_04[]                  = {1.0f, 0.0f, 0.0f, 0.0f};                       
        GLfloat rightUpperArm_SET_05[]                  = {1.0f, 0.0f, 0.0f, 0.0f};
        GLfloat rightUpperArm_SET_06[]                  = {1.0f, 0.0f, 0.0f, 0.0f};
        GLfloat rightUpperArm_SET_07[]                  = {1.0f, 0.0f, 0.0f, 0.0f};
                       

                       GLfloat rightForeArm_04[]                      = {-0.013, -0.168, 0.015};
                       GLfloat rightForeArm_ROTATE[]                  = { 1.0f, 0.0f, 0.0f, 0.0f};///THETA =[3] __XYZaxis=[0][1][2]  
                       GLfloat rightForeArm_ROTATE_FRAMEA[]           = { 1.0f, 0.0f, 0.0f, 0.0f};///THETA =[3] __XYZaxis=[0][1][2]       
                       GLfloat rightForeArm_ROTATE_FRAMEB[]           = { 1.0f, 0.0f, 0.0f, 0.0f};///THETA =[3] __XYZaxis=[0][1][2]
                       GLfloat rightForeArm_ROTATE_FRAME_LOOP_RESET[] = { 1.0f, 0.0f, 0.0f, 0.0f};      
                       
                       GLfloat rightForeArm_SET_01[]                  = { 1.0f, 0.0f, 0.0f, 0.0f};
                       GLfloat rightForeArm_SET_02[]                  = { 1.0f, 0.0f, 0.0f, 0.0f};
                       GLfloat rightForeArm_SET_03[]                  = { 1.0f, 0.0f, 0.0f, 0.0f};
                       GLfloat rightForeArm_SET_04[]                  = { 1.0f, 0.0f, 0.0f, 0.0f};                       
                       GLfloat rightForeArm_SET_05[]                  = { 1.0f, 0.0f, 0.0f, 0.0f};
                       GLfloat rightForeArm_SET_06[]                  = { 1.0f, 0.0f, 0.0f, 0.0f};         
                       GLfloat rightForeArm_SET_07[]                  = { 1.0f, 0.0f, 0.0f, 0.0f};    


                                      GLfloat rightHand_04[]                      = {0.0119907, -0.179, 0.041};
                                      GLfloat rightHand_ROTATE[]                  = {0.0f, 1.0f, 0.0f, 0.0f};///THETA =[3] __XYZaxis=[0][1][2] 
                                      GLfloat rightHand_ROTATE_FRAMEA[]           = {0.0f, 1.0f, 0.0f, 0.0f};///THETA =[3] __XYZaxis=[0][1][2]       
                                      GLfloat rightHand_ROTATE_FRAMEB[]           = {0.0f, 1.0f, 0.0f, 0.0f};///THETA =[3] __XYZaxis=[0][1][2]
                                      GLfloat rightHand_ROTATE_FRAME_LOOP_RESET[] = {0.0f, 1.0f, 0.0f, 0.0f};      
                                      
                                      GLfloat rightHand_SET_01[]                  = {0.0f, 1.0f, 0.0f, 0.0f};
                                      GLfloat rightHand_SET_02[]                  = {0.0f, 1.0f, 0.0f, 0.0f};
                                      GLfloat rightHand_SET_03[]                  = {0.0f, 1.0f, 0.0f, 0.0f};
                                      GLfloat rightHand_SET_04[]                  = {0.0f, 1.0f, 0.0f, 0.0f};                       
                                      GLfloat rightHand_SET_05[]                  = {0.0f, 1.0f, 0.0f, 0.0f};
                                      GLfloat rightHand_SET_06[]                  = {0.0f, 1.0f, 0.0f, 0.0f};
                                      GLfloat rightHand_SET_07[]                  = {0.0f, 1.0f, 0.0f, 0.0f};


bool  rightUpperArm_ROTATE_X            = false;
bool  rightUpperArm_ROTATE_Y            = false;
bool  rightUpperArm_ROTATE_Z            = false;

bool  rightForeArm_ROTATE_X             = false;
bool  rightForeArm_ROTATE_Y             = false;
bool  rightForeArm_ROTATE_Z             = false;

bool  rightHand_ROTATE_X          = false;
bool  rightHand_ROTATE_Y          = false;
bool  rightHand_ROTATE_Z          = false;

int    setSelection_RIGHT_ARM           = 1;
int    SelectionCount_RIGHT_ARM         = 0;
int    setSelectionLimit_RIGHT_ARM      = 0;
GLfloat  animationBlendFactor_RIGHT_ARM   = 0.032;


GLfloat   rightArm_ROTATION_FRAME_TIME[]           = { 0.04, 0.04, 0.04, 0.04, 0.04, 0.04, 0.04};
//__________________________________________________________________________________________________________________________________
       
        bool    leftUpperLeg_AnimationSequence        = false;
        int     leftLegSelection                       = 8;

        GLfloat leftUpperLeg_04[]                      = {0.066, -0.035, -0.004};
        GLfloat leftUpperLeg_ROTATE[]                  = {1.0f, 0.0f, 0.0f, 0.0f};///THETA =[3] __XYZaxis=[0][1][2]
        GLfloat leftUpperLeg_ROTATE_FRAMEA[]           = {1.0f, 0.0f, 0.0f, 0.0f};///THETA =[3] __XYZaxis=[0][1][2]       
        GLfloat leftUpperLeg_ROTATE_FRAMEB[]           = {1.0f, 0.0f, 0.0f, 0.0f};///THETA =[3] __XYZaxis=[0][1][2]
        GLfloat leftUpperLeg_ROTATE_FRAME_LOOP_RESET[] = {1.0f, 0.0f, 0.0f, 0.0f};      
        
        GLfloat leftUpperLeg_SET_01[]                  = {1.0f, 0.0f, 0.0f, 0.0f};
        GLfloat leftUpperLeg_SET_02[]                  = {1.0f, 0.0f, 0.0f, 0.0f};
        GLfloat leftUpperLeg_SET_03[]                  = {1.0f, 0.0f, 0.0f, 0.0f};
        GLfloat leftUpperLeg_SET_04[]                  = {1.0f, 0.0f, 0.0f, 0.0f};                       
        GLfloat leftUpperLeg_SET_05[]                  = {1.0f, 0.0f, 0.0f, 0.0f};
        GLfloat leftUpperLeg_SET_06[]                  = {1.0f, 0.0f, 0.0f, 0.0f};                       
        GLfloat leftUpperLeg_SET_07[]                  = {1.0f, 0.0f, 0.0f, 0.0f};             
                       

                       GLfloat leftLowerLeg_04[]                      = {0.005, -0.201, 0.011};
                       GLfloat leftLowerLeg_ROTATE[]                  = {1.0f, 0.0f, 0.0f, 0.0f};///THETA =[3] __XYZaxis=[0][1][2] 
                       GLfloat leftLowerLeg_ROTATE_FRAMEA[]           = {1.0f, 0.0f, 0.0f, 0.0f};///THETA =[3] __XYZaxis=[0][1][2]       
                       GLfloat leftLowerLeg_ROTATE_FRAMEB[]           = {1.0f, 0.0f, 0.0f, 0.0f};///THETA =[3] __XYZaxis=[0][1][2]
                       GLfloat leftLowerLeg_ROTATE_FRAME_LOOP_RESET[] = {1.0f, 0.0f, 0.0f, 0.0f};      
                       
                       GLfloat leftLowerLeg_SET_01[]                  = {1.0f, 0.0f, 0.0f, 0.0f};
                       GLfloat leftLowerLeg_SET_02[]                  = {1.0f, 0.0f, 0.0f, 0.0f};
                       GLfloat leftLowerLeg_SET_03[]                  = {1.0f, 0.0f, 0.0f, 0.0f};
                       GLfloat leftLowerLeg_SET_04[]                  = {1.0f, 0.0f, 0.0f, 0.0f};                       
                       GLfloat leftLowerLeg_SET_05[]                  = {1.0f, 0.0f, 0.0f, 0.0f};
                       GLfloat leftLowerLeg_SET_06[]                  = {1.0f, 0.0f, 0.0f, 0.0f}; 
                       GLfloat leftLowerLeg_SET_07[]                  = {1.0f, 0.0f, 0.0f, 0.0f};                

                                       GLfloat leftFoot_04[]                      = {0.001, -0.254, -0.013};
                                       GLfloat leftFoot_ROTATE[]                  = {1.0f, 0.0f, 0.0f, 0.0f};///THETA =[3] __XYZaxis=[0][1][2] 
                                       GLfloat leftFoot_ROTATE_FRAMEA[]           = {1.0f, 0.0f, 0.0f, 0.0f};///THETA =[3] __XYZaxis=[0][1][2]       
                                       GLfloat leftFoot_ROTATE_FRAMEB[]           = {1.0f, 0.0f, 0.0f, 0.0f};///THETA =[3] __XYZaxis=[0][1][2]
                                       GLfloat leftFoot_ROTATE_FRAME_LOOP_RESET[] = {1.0f, 0.0f, 0.0f, 0.0f};      
                                       
                                       GLfloat leftFoot_SET_01[]                  = {1.0f, 0.0f, 0.0f, 0.0f};
                                       GLfloat leftFoot_SET_02[]                  = {1.0f, 0.0f, 0.0f, 0.0f};
                                       GLfloat leftFoot_SET_03[]                  = {1.0f, 0.0f, 0.0f, 0.0f};
                                       GLfloat leftFoot_SET_04[]                  = {1.0f, 0.0f, 0.0f, 0.0f};                       
                                       GLfloat leftFoot_SET_05[]                  = {1.0f, 0.0f, 0.0f, 0.0f};
                                       GLfloat leftFoot_SET_06[]                  = {1.0f, 0.0f, 0.0f, 0.0f}; 
                                       GLfloat leftFoot_SET_07[]                  = {1.0f, 0.0f, 0.0f, 0.0f}; 



bool  leftUpperLeg_ROTATE_X = false;
bool  leftUpperLeg_ROTATE_Y = false;
bool  leftUpperLeg_ROTATE_Z = false;

bool  leftLowerLeg_ROTATE_X = false;
bool  leftLowerLeg_ROTATE_Y = false;
bool  leftLowerLeg_ROTATE_Z = false;

bool  leftFoot_ROTATE_X = false;
bool  leftFoot_ROTATE_Y = false;
bool  leftFoot_ROTATE_Z = false;

int    setSelection_LEFT_LEG            = 1;
int    SelectionCount_LEFT_LEG          = 0;
int    setSelectionLimit_LEFT_LEG       = 0;
GLfloat  animationBlendFactor_LEFT_LEG    = 0.032;


      GLfloat  leftLeg_ROTATION_FRAME_TIME[]           = { 0.04, 0.04, 0.04, 0.04, 0.04, 0.04, 0.04};
//__________________________________________________________________________________________________________________________________                   
      
      
        bool    rightUpperLeg_AnimationSequence         = false;
       
        int     rightLegSelection                       = 8;

        GLfloat rightLeg_04[]                           = {-0.066, -0.035, -0.004};      

        GLfloat rightUpperLeg_04[]                      = {-0.066, -0.035, -0.004}; 
        GLfloat rightUpperLeg_ROTATE[]                  = {1.0f, 0.0f, 0.0f,  0.0f};///THETA =[3] __XYZaxis=[0][1][2]
        GLfloat rightUpperLeg_ROTATE_FRAMEA[]           = {1.0f, 0.0f, 0.0f, 0.0f};///THETA =[3] __XYZaxis=[0][1][2]       
        GLfloat rightUpperLeg_ROTATE_FRAMEB[]           = {1.0f, 0.0f, 0.0f, 0.0f};///THETA =[3] __XYZaxis=[0][1][2]
        GLfloat rightUpperLeg_ROTATE_FRAME_LOOP_RESET[] = {1.0f, 0.0f, 0.0f, 0.0f};      
        
        GLfloat rightUpperLeg_SET_01[]                  = {1.0f, 0.0f, 0.0f, 0.0f};
        GLfloat rightUpperLeg_SET_02[]                  = {1.0f, 0.0f, 0.0f, 0.0f};
        GLfloat rightUpperLeg_SET_03[]                  = {1.0f, 0.0f, 0.0f, 0.0f};
        GLfloat rightUpperLeg_SET_04[]                  = {1.0f, 0.0f, 0.0f, 0.0f};                       
        GLfloat rightUpperLeg_SET_05[]                  = {1.0f, 0.0f, 0.0f, 0.0f};
        GLfloat rightUpperLeg_SET_06[]                  = {1.0f, 0.0f, 0.0f, 0.0f};                       
        GLfloat rightUpperLeg_SET_07[]                  = {1.0f, 0.0f, 0.0f, 0.0f};                       
         
 
                       GLfloat rightLowerLeg_04[]                      = {-0.005, -0.201, 0.011};
                       GLfloat rightLowerLeg_ROTATE[]                  = {1.0f, 0.0f, 0.0f,  .0f};///THETA =[3] __XYZaxis=[0][1][2] 
                       GLfloat rightLowerLeg_ROTATE_FRAMEA[]           = {1.0f, 0.0f, 0.0f, 0.0f};///THETA =[3] __XYZaxis=[0][1][2]       
                       GLfloat rightLowerLeg_ROTATE_FRAMEB[]           = {1.0f, 0.0f, 0.0f, 0.0f};///THETA =[3] __XYZaxis=[0][1][2]
                       GLfloat rightLowerLeg_ROTATE_FRAME_LOOP_RESET[] = {1.0f, 0.0f, 0.0f, 0.0f};      
                       
                       GLfloat rightLowerLeg_SET_01[]                  = {1.0f, 0.0f, 0.0f, 0.0f};
                       GLfloat rightLowerLeg_SET_02[]                  = {1.0f, 0.0f, 0.0f, 0.0f};
                       GLfloat rightLowerLeg_SET_03[]                  = {1.0f, 0.0f, 0.0f, 0.0f};
                       GLfloat rightLowerLeg_SET_04[]                  = {1.0f, 0.0f, 0.0f, 0.0f};                       
                       GLfloat rightLowerLeg_SET_05[]                  = {1.0f, 0.0f, 0.0f, 0.0f};
                       GLfloat rightLowerLeg_SET_06[]                  = {1.0f, 0.0f, 0.0f, 0.0f};                       
                       GLfloat rightLowerLeg_SET_07[]                  = {1.0f, 0.0f, 0.0f, 0.0f};          
 

                                       GLfloat rightFoot_04[]                      = {-0.001, -0.254, -0.013};      
                                       GLfloat rightFoot_ROTATE[]                  = {1.0f, 0.0f, 0.0f, 0.0f};///THETA =[3] __XYZaxis=[0][1][2]        
                                       GLfloat rightFoot_ROTATE_FRAMEA[]           = {1.0f, 0.0f, 0.0f, 0.0f};///THETA =[3] __XYZaxis=[0][1][2]       
                                       GLfloat rightFoot_ROTATE_FRAMEB[]           = {1.0f, 0.0f, 0.0f, 0.0f};///THETA =[3] __XYZaxis=[0][1][2]
                                       GLfloat rightFoot_ROTATE_FRAME_LOOP_RESET[] = {1.0f, 0.0f, 0.0f, 0.0f};      
                                       
                                       GLfloat rightFoot_SET_01[]                  = {1.0f, 0.0f, 0.0f, 0.0f};
                                       GLfloat rightFoot_SET_02[]                  = {1.0f, 0.0f, 0.0f, 0.0f};
                                       GLfloat rightFoot_SET_03[]                  = {1.0f, 0.0f, 0.0f, 0.0f};
                                       GLfloat rightFoot_SET_04[]                  = {1.0f, 0.0f, 0.0f, 0.0f};                       
                                       GLfloat rightFoot_SET_05[]                  = {1.0f, 0.0f, 0.0f, 0.0f};
                                       GLfloat rightFoot_SET_06[]                  = {1.0f, 0.0f, 0.0f, 0.0f};                       
                                       GLfloat rightFoot_SET_07[]                  = {1.0f, 0.0f, 0.0f, 0.0f};   

bool  rightUpperLeg_ROTATE_X = false;
bool  rightLowerLeg_ROTATE_X = false;
bool  rightFoot_ROTATE_X     = false;

bool  rightUpperLeg_ROTATE_Y = false;
bool  rightLowerLeg_ROTATE_Y = false;
bool  rightFoot_ROTATE_Y     = false;

bool  rightUpperLeg_ROTATE_Z = false;
bool  rightLowerLeg_ROTATE_Z = false;
bool  rightFoot_ROTATE_Z     = false;

int    setSelection_RIGHT_LEG           = 1;
int    SelectionCount_RIGHT_LEG         = 0;
int    setSelectionLimit_RIGHT_LEG      = 0;
GLfloat  animationBlendFactor_RIGHT_LEG   = 0.032;

GLfloat   rightLeg_ROTATION_FRAME_TIME[]           = { 0.04, 0.04, 0.04, 0.04, 0.04, 0.04, 0.04};
//__________________________________________________________________________________________________________________________________
//__________________________________________________________________________________________________________________________________
//__________________________________________________________________________________________________________________________________

GLfloat hipsDialogue[]                         = { 0.0,   0.0,      0.0};
GLfloat torsoDialogue[]                        = { 0.15,  0.0,      0.0};
GLfloat headDialogue[]                         = { 0.3,   0.0,      0.0};
GLfloat centerPartsDialogue[]                  = { 1.236, 0.760994, 0.0};
GLfloat centerPartsleftArmDialogueTextImage[]  = { 0.118, 0.186,   -0.01};

GLfloat leftLegDialogueA[]      = {0,0,0};
GLfloat leftLegDialogueB[]      = {.15,0,0};
GLfloat leftLegDialogueC[]      = {.3,0,0};
GLfloat leftLegDialogues[]      = {1.241, -0.318, 0};
GLfloat leftLegDialogueText[]   = {0.116, 0.184, -.01};

GLfloat rightLegDialogueA[]    = {0,0,0};
GLfloat rightLegDialogueB[]    = {.15,0,0};
GLfloat rightLegDialogueC[]    = {.3,0,0};
GLfloat rightLegDialogues[]    = {-1.45101, -0.318, 0};
GLfloat rightLegDialogueText[] = {0.116, 0.184, -.01};

GLfloat rightArmDialogueA[]    = {0,0,0};
GLfloat rightArmDialogueB[]    = {.15,0,0};
GLfloat rightArmDialogueC[]    = {.3,0,0};
GLfloat rightArmDialogues[]    = {-1.45401, 0.761994, 0};
GLfloat rightArmDialogueText[] = {0.117, 0.186, -.01};

GLfloat leftArmDialogueA[]      = {0,0,0};
GLfloat leftArmDialogueB[]      = {.15,0,0};
GLfloat leftArmDialogueC[]      = {.3,0,0};
GLfloat leftArmDialogues[]       = {1.236, 0.760994, 0};
GLfloat leftArmDialogueText[]   = {0.118, 0.186, -.01};

//------------------------------------------------------------------------------------------------------------------------------------------------


GLfloat  HUD_position[]         = { 0, -0.839999, 0};
GLfloat  HUD_rotate             = -59.7997;
GLfloat  F1_to_F8_Position[]    = {-0.74, -0.57, 0};
int      F1_to_F8_TEXTURE       = 0;
int      BODY_PART_SELECTION    = 7;

GLfloat    BODY_PART_SELECTION_COLOR_CHANGE = 0.0;

#include "animationClips/backPlate.cpp"
GLfloat  backPlatePosition[]   = {0.32, 0.19, -0.32};
GLfloat  backPlateScale        = 1.31;
bool     n_keyReset            = false;




int       positionedModelSequence = 1;



bool      loadSet_01                    = false;
bool      loadSet_02                    = false;
bool      loadSet_03                    = false;
bool      loadSet_04                    = false;
bool      loadSet_05                    = false;
bool      loadSet_06                    = false;
bool      loadSet_07                    = false;

bool      leftKeyIsReset                = true;
bool      rightKeyIsReset               = true;
bool      upKeyIsReset                  = true;
bool      downKeyIsReset                = true;
//-----------------------------------------------

//bool      runAnimationSequence          = true;
GLfloat   runAnimationForward           = 0.0;

//-----------------------------------------------


GLfloat   ARROWS_MOVE_MAIN_POSITION     = 0.0;


//------------------------------------------------------------------------------------------------------------------------------------------------
                             GLfloat rotationInfoTransparency                    = 1.0;
 
 

                             #include "_MODEL_FOLDERS_/positionedModelNumbers/zero_vboGlobals.cpp" 
                             #include "_MODEL_FOLDERS_/positionedModelNumbers/one_vboGlobals.cpp" 
                             #include "_MODEL_FOLDERS_/positionedModelNumbers/two_vboGlobals.cpp" 
                             #include "_MODEL_FOLDERS_/positionedModelNumbers/three_vboGlobals.cpp" 
                             #include "_MODEL_FOLDERS_/positionedModelNumbers/four_vboGlobals.cpp" 
                             #include "_MODEL_FOLDERS_/positionedModelNumbers/five_vboGlobals.cpp" 
                             #include "_MODEL_FOLDERS_/positionedModelNumbers/six_vboGlobals.cpp" 
                             #include "_MODEL_FOLDERS_/positionedModelNumbers/seven_vboGlobals.cpp" 
                             #include "_MODEL_FOLDERS_/positionedModelNumbers/eight_vboGlobals.cpp" 
                             #include "_MODEL_FOLDERS_/positionedModelNumbers/nine_vboGlobals.cpp" 
                             #include "_MODEL_FOLDERS_/positionedModelNumbers/decimalPoint_vboGlobals.cpp" 
                             //-----------------------------------------------
                             void      printDecimalNumbers(float InputValue);
                             GLfloat   adjustNumbersPosition_00     =  0.043;
                             GLfloat   adjustDecimalPointX          =  0.122;             
                             #include "_MODEL_FOLDERS_/positionedModelNumbers/DisplayFloat_3Dfont.cpp"             
                             //*********************************************************************************************************        
                             
                             GLhandleARB tiles_FBO_shadows;
                             GLhandleARB tiles_FBO_shadows_Vertex;
                             GLhandleARB tiles_FBO_shadows_Fragment;
                             
                             GLuint      tiles_1_vboID                           =    1;
                             GLuint      tiles_2_vboID                           =    2;                                
    
                             //-------------------------------------------------
                             GLfloat     lightPos_tiles_1[]                      =   {531.607, 711.08, -152.318};
                             GLfloat     quadraticAttenuation_tiles_1            =   1.67402;    
                             //-------------------------------------------------
                             GLfloat     quadraticAttenuation_pyramidTiles       =   1.97004;   
                             //-------------------------------------------------                            
                             GLint   UNIFORM_lightPos_02_tiles_1;
                             GLint   UNIFORM_attenuation_02;
                             //-----
                             GLfloat lightPos_02_tiles_1[]                       =  {1.0, 1.0, 1.0};
                             GLfloat quadraticAttenuation_02_tiles_1             =  10.0000001;                                 
                             //-------------------------------------------------
                             
                             #include "_MODEL_FOLDERS_/floorTiles/tiles_1_TEX.cpp"
                             #include "_MODEL_FOLDERS_/floorTiles/tiles_1_NORM.cpp"
                             #include "_MODEL_FOLDERS_/floorTiles/tiles_1_VERT.cpp"

                             //------------------------------------------------------------------------------------------                         
                          

                             GLfloat    adjustOffsetX                          =   0.0;
                             GLfloat    adjustOffsetY                          =   0.0;                             
                             
                             GLfloat    scalemarcShadow                        =   1.0;                              
                             
                             GLint      UNIFORM_displacement_X_tiles_1;
                             GLint      UNIFORM_displacement_Y_tiles_1;                             
                             
                             GLfloat    shadows_TextureDisplacement_X          =   0.0;
                             GLfloat    shadows_TextureDisplacement_Y          =   0.0;                              
                             
                             GLint      UNIFORM_offset_X_tiles_1;
                             GLint      UNIFORM_offset_Y_tiles_1;
                                                         
                             GLfloat    shadows_offset_X                       =   0.0;
                             GLfloat    shadows_offset_Y                       =   0.0;                             
                             
                             GLint      UNIFORM_displacement_X_PyramidTiles_1;                             
                             GLint      UNIFORM_displacement_Y_PyramidTiles_1;                              
                             GLint      UNIFORM_offset_X_PyramidTiles_1;
                             GLint      UNIFORM_offset_Y_PyramidTiles_1;                                              
                             GLint      UNIFORM_counter; 
                             
                             GLfloat    tilesCounter                           =   0.000;                      
                             //===================================================================================================================================== 
                             GLfloat     face_Marc_DOT3_light[]                =  {-13.5501, 100, 704.795};
                             GLfloat     quadraticAttenuationFace_Marc_DOT3    =   2.60903;                            
                             //-----------------------------
                             GLfloat     lightPos_marcTorso[]                  = {12.913, 100, -149.049};
                             GLfloat     lightAttenuation_marcTorso            =       1.76004;
                             GLfloat     MaterialShininess_marcTorso           =       5.96;   
                             //-----------------------------
                             GLfloat     LightAmbient_marcTorso[]              = { 1.0f, 1.0f, 1.0f, 1.0f};
                             GLfloat     LightDiffuse_marcTorso[]              = { 1.0f, 1.0f, 1.0f, 1.0f};
                             GLfloat     LightSpecular_marcTorso[]             = { 1.0f, 1.0f, 1.0f, 1.0f};
                             GLfloat     MaterialAmbient_marcTorso[]           = { 1.0f, 1.0f, 1.0f, 1.0f};
                             GLfloat     MaterialDiffuse_marcTorso[]           = { 1.0f, 1.0f, 1.0f, 1.0f};
                             GLfloat     MaterialEmission_marcTorso[]          = { 1.0f, 1.0f, 1.0f, 1.0f};
                             GLfloat     MaterialSpecular_marcTorso[]          = { 1.01, 0.979999, 1.18};
                             //-----------------------------
                             GLhandleARB marcWood;
                             GLhandleARB marcWood_Vertex;
                             GLhandleARB marcWood_Fragment;
                             //-----------------------------                               
                             GLuint      marcTextures[100];
                             GLuint      marcNormals[100];
                             //-----------------------------           
                             bool        showMarc                                = true;                                                                                                                     
                             bool        marcWalking                             = false;
                             bool        marcJumping                             = false;
                             bool        resetAnimation                          = false;
                             bool        spaceBarIsPressed                       = false;
                             //-----------------------------                                
                             GLfloat     marcModelPosition[]                     =  {0.0,  0.672502, 0.0};
                             GLfloat     marcRotation                            =   0.0;
                             GLfloat     marcShadow_Y_Position[]                 =  {0.0, -0.610902, 0.0};
                             //---------------------------------------------------------                                  
                             GLfloat     rotation_AXIS_marcHeadBack[]            =  {1.0, 1.0, 1.0};
                             GLfloat     marcHeadBack_POSITION[]                 =  {0.0, 0.0, 0.0};
                             //------------
                             GLfloat     headRotationDisplayValues[]             =      {0.0289999, 0.355998, 0.0999998};
                             #include    "_MODEL_FOLDERS_/marcParts/marcHeadBack/marcHeadBack_vboGlobals.cpp"        
                             //-------------------------------------------------------------------------------------- 
                             #include    "_MODEL_FOLDERS_/marcParts/marcFace/marcFace_vboGlobals.cpp"        
                             //-------------------------------------------------------------------------------------- 
                             GLfloat     torsoRotationDisplayValues[]            =      { 0.0350002, 0.229001, 0.128};
                             #include    "_MODEL_FOLDERS_/marcParts/marcTorso/marcTorso_vboGlobals.cpp"        
                             //-------------------------------------------------------------------------------------- 
                             GLfloat     hipsRotationDisplayValues[]             =      { 0.0270002, 0.0609997, 0.143};
                             #include    "_MODEL_FOLDERS_/marcParts/marcHips/marcHips_vboGlobals.cpp"        
                             //-------------------------------------------------------------------------------------- 
                             GLfloat     leftUpperArmRotationDisplayValues[]     =      { 0.151, 0.185, 0.0129997};
                             #include    "_MODEL_FOLDERS_/marcParts/marcLeftUpperArm/marcLeftUpperArm_vboGlobals.cpp"                              
                             //-------------------------------------------------------------------------------------- 
                             GLfloat     leftLowerArmRotationDisplayValues[]     =      { 0.248, 0.166, 0.0129997};
                             #include    "_MODEL_FOLDERS_/marcParts/marcLeftForeArm/marcLeftForeArm_vboGlobals.cpp"                              
                             //-------------------------------------------------------------------------------------- 
                             GLfloat     leftHandRotationDisplayValues[]         =      { 0.351999, 0.16, 0.0129997};
                             #include    "_MODEL_FOLDERS_/marcParts/marcLeftHand/marcLeftHand_vboGlobals.cpp"                                                               
                             //-------------------------------------------------------------------------------------- 
                             GLfloat     rightUpperArmRotationDisplayValues[]    =      {-0.108, 0.185, 0.0129997};
                             #include    "_MODEL_FOLDERS_/marcParts/marcRightUpperArm/marcRightUpperArm_vboGlobals.cpp"        
                             //-------------------------------------------------------------------------------------- 
                             GLfloat     rightLowerArmRotationDisplayValues[]    =      {-0.205, 0.166, 0.0129997};
                             #include    "_MODEL_FOLDERS_/marcParts/marcRightForeArm/marcRightForeArm_vboGlobals.cpp"        
                             //-------------------------------------------------------------------------------------- 
                             GLfloat     rightHandRotationDisplayValues[]        =      {-0.315999, 0.16, 0.0129997};          
                             #include    "_MODEL_FOLDERS_/marcParts/marcRightHand/marcRightHand_vboGlobals.cpp"        
                             //-------------------------------------------------------------------------------------- 
                             GLfloat     leftUpperLegRotationDisplayValues[]     =      { 0.226, -0.0200002, 0.0129997};
                             #include    "_MODEL_FOLDERS_/marcParts/marcLeftUpperLeg/marcLeftUpperLeg_vboGlobals.cpp" 
                             //-------------------------------------------------------------------------------------- 
                             GLfloat     leftLowerLegRotationDisplayValues[]     =      { 0.321999, -0.012, 0.0129997};                        
                             #include    "_MODEL_FOLDERS_/marcParts/marcLeftLowerLeg/marcLeftLowerLeg_vboGlobals.cpp" 
                             //-------------------------------------------------------------------------------------- 
                             GLfloat     leftFootRotationDisplayValues[]         =      { 0.419998, 0.049, 0.0179997};
                             #include    "_MODEL_FOLDERS_/marcParts/marcLeftBoot/marcLeftBoot_vboGlobals.cpp"                                
                             //-------------------------------------------------------------------------------------- 
                             GLfloat     rightUpperLegRotationDisplayValues[]    =      {-0.17, -0.012, 0.0129997};
                             #include    "_MODEL_FOLDERS_/marcParts/marcRightUpperLeg/marcRightUpperLeg_vboGlobals.cpp"        
                             //-------------------------------------------------------------------------------------- 
                             GLfloat     rightLowerLegRotationDisplayValues[]    =      {-0.255, -0.006, 0.0129997}; 
                             #include    "_MODEL_FOLDERS_/marcParts/marcRightLowerLeg/marcRightLowerLeg_vboGlobals.cpp"        
                             //-------------------------------------------------------------------------------------- 
                             GLfloat     rightFootRotationDisplayValues[]        =      {-0.348999, 0.058, 0.0179997};
                             #include    "_MODEL_FOLDERS_/marcParts/marcRightBoot/marcRightBoot_vboGlobals.cpp" 
                             //-------------------------------------------------------------------------------------- 
                             //------------------------------------------------------------------------------------------
                             GLfloat    lightPos_jetPackEngines[]                =     {-17.8652, 1168.03, -1643.4};
                             GLfloat    quadraticAttenuation_jetPackEngines      =        0.818;
                             #include "_MODEL_FOLDERS_/jetPack/jetPack.cpp"
                             //--------------------------------------------------------------------------------------
                             GLfloat    marc_VBO_ShadowsPosition_01[]            =       {0.0250003, 0.0139998, -4.66092};
                             GLfloat    scale_marc_VBO_Shadow_01                 =        0.5;
                             GLfloat    marc_VBO_ShadowsRotationUP_DOWN_01       =       36.2;
                             GLfloat    marc_VBO_ShadowsRotationLEFT_RIGHT_01    =       -7.00001;   
                             //--------------------------------------------------------------------------------------
                             GLfloat    marc_VBO_ShadowsPosition_00[]            =      {-0.145, -0.0610001, -5.0079};
                             GLfloat    scale_marc_VBO_Shadow_00                 =        0.296002;            
                             GLfloat    marc_VBO_ShadowsRotationUP_DOWN_00       =       36.20;
                             GLfloat    marc_VBO_ShadowsRotationLEFT_RIGHT_00    =       40.94;
                             //===================================================================================================================================== 
                             GLfloat    scalehips_POSITIONMove_00                      =  -0.1036;                                                                                 
                             //---------------------------------   
                             GLfloat    F1_F8_POSITION[]                        =  {-0.590001, -0.159, 0.574998};
                             GLfloat    rotation_AXIS_F1_F8[]                    =  {1.0, 0.0, 0.0, 35.0};        
                             //---------------------------------            
                             GLfloat    lightPos_F1_F8[]                         =  {4.03883, 45.5429, -9.79229};
                             GLfloat    lightAttenuation_F1_F8                   =   1.17699;
                             GLfloat    shininess_F1_F8                          = 199.733;                    
                             //---------------------------------                               
                             GLfloat    F1_isSet                                 =   0.0;
                             GLfloat    F2_isSet                                 =   0.0;                             
                             GLfloat    F3_isSet                                 =   0.0;                              
                             GLfloat    F4_isSet                                 =   0.0;                              
                             GLfloat    F5_isSet                                 =   0.0;                              
                             GLfloat    F6_isSet                                 =   0.0; 
                             GLfloat    F7_isSet                                 =   0.0;                               
                             GLfloat    F8_isSet                                 =   0.0;                               
                                                          
                             #include "_MODEL_FOLDERS_/F1_F8/F1_F8_vboGlobals.cpp"  //vboID = 573
                             //=====================================================================================================================================              
                             GLfloat     keyboardLayoutDialogue_POSITION[]                                    = {-3.74,    -0.3, -4.06};
                             GLfloat     keyboardLayoutDialogue_VALUES_POSITION[]                             = { 0.199996, 0.07, 0.00999766};
                             //----------
                             GLfloat     keyboardLayoutDialogue_ROTATION[]                                    = {0.0, 1.0, 0.0, 0.0};
                             GLfloat     keyboardLayoutDialogue_VALUES_ROTATION[]                             = {0.0, 1.0, 0.0, 0.0};                             
                             #include    "_MODEL_FOLDERS_/Dialogue/keyboardLayoutDialogue_vboGlobals.cpp"   //vboID = 540
                             //----------
                             GLfloat     keyboardSet_01_INFO_POSITION[]                                       = {-2.20819, 0.0551999, -1.12959};
                             GLfloat     keyboardSet_01_INFO_SCALE[]                                          = {1.95701};
                             GLfloat     keyboardSet_01_INFO_ROTATION[]                                       = { 1.0,   0.0,  0.0, -90.0};
                             //----------
                             GLfloat     hideSet_POSITION[]                                                   =  {2.34, -1.75, -3.58189}; 
                             GLfloat     hideSet_ROTATION[]                                                   =  {1.0, 0.0, 0.0, 0.0};
                             GLfloat     hideSet_ON_OFF[]                                                     = {0.0};
                             bool        hideSetPlusDialoque                                                  =  1.0;
                             GLfloat     scaleHideSetDialoque[]                                               = {0.3};
                             //----------
                             GLfloat     scalePoseIcons                                                       =   0.405501 * 2.0;
                             GLfloat     poseIcons_POSITION[]                                                 = {-2.19617, 1.16091, -3.76418};
                             GLfloat     poseIcons_POSITION_02[]                                              = {-1.38329, 1.16311, -3.76418};//0.81288
                             GLfloat     poseIcons_POSITION_03[]                                              = {-0.56485, 1.16311, -3.76418};                             
                             GLfloat     poseIcons_POSITION_04[]                                              = { 0.24803, 1.16311, -3.76418};  
                             GLfloat     poseIcons_POSITION_05[]                                              = { 1.06091, 1.16311, -3.76418};  
                             //=====================================================================================================================================  
                             GLfloat     scalebodyPartSelectIcons                                             =   0.405501;
                             GLfloat     bodyPartSelectIcons_POSITION_01[]                                    = { 2.4035,   1.36291,  -3.76418};
                             GLfloat     bodyPartSelectIcons_POSITION_02[]                                    = { 2.4035,   0.95646 , -3.76418};//0.40644 
                             GLfloat     bodyPartSelectIcons_POSITION_03[]                                    = { 2.4035,   0.55002,  -3.76418};                             
                             GLfloat     bodyPartSelectIcons_POSITION_04[]                                    = { 2.4035,   0.14358 , -3.76418};  
                             GLfloat     bodyPartSelectIcons_POSITION_05[]                                    = { 2.4035,  -0.26286,  -3.76418};                      
                             GLfloat     bodyPartSelectIcons_POSITION_06[]                                    = { 1.9971,   0.55002,  -3.76418};                             
                             GLfloat     bodyPartSelectIcons_POSITION_07[]                                    = { 1.9971,   0.14358 , -3.76418};  
                             GLfloat     bodyPartSelectIcons_POSITION_08[]                                    = { 1.9971 , -0.26286,  -3.76418};                             
                             GLfloat     bodyPartSelectIcons_POSITION_09[]                                    = { 2.0135,   1.35644,  -3.76418};//head              
                             //----------
                             GLfloat     bodyPartSelectIcons_POSITION_10[]                                    = { 1.5906 ,  .55002 , -3.76418};//leftLeg 
                             GLfloat     bodyPartSelectIcons_POSITION_11[]                                    = { 1.5906 ,  .55002-0.40644 , -3.76418};                      
                             GLfloat     bodyPartSelectIcons_POSITION_12[]                                    = { 1.5906 ,  .55002-0.40644-0.40644 , -3.76418};                            
                             //----------
                             GLfloat     bodyPartSelectIcons_POSITION_13[]                                    = { 1.5906-0.40644 ,  .55002 , -3.76418};//rightLeg  
                             GLfloat     bodyPartSelectIcons_POSITION_14[]                                    = { 1.5906-0.40644 ,  .55002-0.40644 , -3.76418};                            
                             GLfloat     bodyPartSelectIcons_POSITION_15[]                                    = { 1.5906-0.40644 ,  .55002-0.40644-0.40644 , -3.76418};            
                                                          
                             //=====================================================================================================================================                         
                             GLfloat     keyboardLeft_POSITION[]                                              = {-0.1332,   0.0888, 1.1877};
                             GLfloat     keyboard_SCALE[]                                                     =  {2.44597};
                             GLfloat     keyboardLeft_ROTATION[]                                              =  {1.0, 0.0, 0.0, -90.0};
                             #include    "_MODEL_FOLDERS_/dialogue/keyboard/keyboardLeft_vboGlobals.cpp"                                       //vboID = 600
                             GLfloat     keyboardRight_POSITION[]                                             =  {0.0, 0.0, 0.0};
                             GLfloat     keyboardRight_ROTATION[]                                             =  {0.0, 1.0, 0.0, 0.0};                             
                             #include    "_MODEL_FOLDERS_/dialogue/keyboard/keyboardRight_vboGlobals.cpp"                                      //vboID = 601
                             //=====================================================================================================================================        
                             
                             //====================================================================================                                          
                             #include "_MODEL_FOLDERS_/iconPlates_x4/iconPlates_x4_Globals.cpp"                                                                
                             //====================================================================================                                          

                             //=====================================================================================================================================         
        
        
        
        
        
        
        
        #include "SHADERtech.cpp"
        #include "cpp/winInit.cpp"
       
         GLuint  SPECULAR_textureID;
         GLuint  DOT3_textureID;
         GLuint  textureID;
 //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//#########################################################################################################################################################################
//#########################################################################################################################################################################
//#########################################################################################################################################################################
//#########################################################################################################################################################################
//#########################################################################################################################################################################
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------



#define BUFFER_OFFSET(i) ((char *)NULL + (i)) 

void Init( void )
{
	GLuint PixelFormat;
	
    PIXELFORMATDESCRIPTOR pfd;
	memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));

    pfd.nSize      = sizeof(PIXELFORMATDESCRIPTOR);
    pfd.nVersion   = 1;
    pfd.dwFlags    = PFD_DRAW_TO_WINDOW |PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 32;
    pfd.cDepthBits = 32;
	
	hDC = GetDC( hWnd );
	PixelFormat = ChoosePixelFormat( hDC, &pfd );
	SetPixelFormat( hDC, PixelFormat, &pfd);
	hRC = wglCreateContext( hDC );
	wglMakeCurrent( hDC, hRC );

	glEnable( GL_TEXTURE_2D );
	glEnable( GL_DEPTH_TEST );
    glDepthFunc(GL_LEQUAL);	
	
    glClearColor( 0.0f, 0.0f, 0.0f, 0.5f );

                  glMatrixMode( GL_PROJECTION );
                  glLoadIdentity();
                  gluPerspective( 45.24, screenWidth / screenHeight, 0.1, 1000);


    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glAlphaFunc(GL_GREATER,0.1f);
                             
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);   

    GLfloat spot_direction[] = {0.0, 0.0, 0.0 };//////////////////___________LIGHT0
     glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, (float)0.007);////_______LIGHT0
      glLightf (GL_LIGHT0, GL_LINEAR_ATTENUATION, (float)0.01);//////________LIGHT0
       glLightf (GL_LIGHT0, GL_CONSTANT_ATTENUATION,(float).003);/////_______LIGHT0
                 

//////////////////////////////////////////////////////////////////////////////////////////////////////////
     glGenBuffers    = (PFNGLGENBUFFERSPROC)   wglGetProcAddress("glGenBuffers");
     glBindBuffer    = (PFNGLBINDBUFFERPROC)   wglGetProcAddress("glBindBuffer");
     glBufferData    = (PFNGLBUFFERDATAPROC)   wglGetProcAddress("glBufferData");
     glBufferSubData = (PFNGLBUFFERSUBDATAPROC)wglGetProcAddress("glBufferSubData");
     glDeleteBuffers = (PFNGLDELETEBUFFERSPROC)wglGetProcAddress("glDeleteBuffers");
//////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////
     glGenBuffers(1, &tiles_1_vboID);
     glBindBuffer(GL_ARRAY_BUFFER, tiles_1_vboID);
     glBufferData(GL_ARRAY_BUFFER,       sizeof(tiles_1_VERT) + sizeof(tiles_1_NORM) + sizeof(tiles_1_TEX), 0, GL_STATIC_DRAW);
     glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(tiles_1_VERT),  tiles_1_VERT); 
     glBufferSubData(GL_ARRAY_BUFFER,    sizeof(tiles_1_VERT),  sizeof(tiles_1_NORM),  tiles_1_NORM);
     glBufferSubData(GL_ARRAY_BUFFER,    sizeof(tiles_1_VERT) + sizeof(tiles_1_NORM),  sizeof(tiles_1_TEX), tiles_1_TEX);
//////////////////////////////////////////////////////////////////////////////////////////////////////////  


glEnable(GL_LIGHT0);

   
 //--------------------------------------------------------------------------------------;
   look_LEFT_RIGHT = 0;
   look_UP_DOWN    = 23.5;
   eyePosition[0]  = 0;
   eyePosition[1]  = -0.9;
   eyePosition[2]  = -3.39159;
 //--------------------------------------------------------------------------------------;
   hips_POSITION[0]  = 0;
   hips_POSITION[1]  = 0;
   hips_POSITION[2]  = 0;
 //--------------------------------------------------------------------------------------;
   shadows_TextureDisplacement_X = -0.51661;;
   shadows_TextureDisplacement_Y = 0;
 //--------------------------------------------------------------------------------------;
 
 
//--------------------------------------------------------------------------
#ifdef WIN32    
    #include "headerFiles/glext_Init_B.cpp" 
#endif



loadTexture("_MODEL_FOLDERS_/floorTiles/floorTile_1_DOT3.jpg",                        normalMap[180]);

loadTexture("_MODEL_FOLDERS_/floorTiles/floorTile_1.jpg",                             textureMap[180]);
loadTexture("_MODEL_FOLDERS_/floorTiles/floorTile_2.jpg",                             textureMap[181]);
loadTexture("_MODEL_FOLDERS_/floorTiles/floorTile_3.jpg",                             textureMap[182]);
loadTexture("_MODEL_FOLDERS_/floorTiles/floorTile_4.jpg",                             textureMap[183]);
loadTexture("_MODEL_FOLDERS_/floorTiles/floorTile_5.jpg",                             textureMap[184]);
loadTexture("_MODEL_FOLDERS_/floorTiles/floorTile_6.jpg",                             textureMap[185]);

#include "_MODEL_FOLDERS_/marcParts/marcHeadBack/marcHeadBack_vboInit.cpp"                    //textureMap[200]
#include "_MODEL_FOLDERS_/marcParts/marcFace/marcFace_vboInit.cpp"                            //textureMap[201]
#include "_MODEL_FOLDERS_/marcParts/marcTorso/marcTorso_vboInit.cpp"                          //normalMap[202]
#include "_MODEL_FOLDERS_/marcParts/marcHips/marcHips_vboInit.cpp"                            //textureMap[203]
#include "_MODEL_FOLDERS_/marcParts/marcRightUpperLeg/marcRightUpperLeg_vboInit.cpp"          //textureMap[204] 
#include "_MODEL_FOLDERS_/marcParts/marcRightLowerLeg/marcRightLowerLeg_vboInit.cpp"          //textureMap[205]  
#include "_MODEL_FOLDERS_/marcParts/marcRightUpperArm/marcRightUpperArm_vboInit.cpp"          //textureMap[206]
#include "_MODEL_FOLDERS_/marcParts/marcRightForeArm/marcRightForeArm_vboInit.cpp"            //textureMap[207]
#include "_MODEL_FOLDERS_/marcParts/marcRightHand/marcRightHand_vboInit.cpp"                  //textureMap[212]
#include "_MODEL_FOLDERS_/marcParts/marcLeftUpperArm/marcLeftUpperArm_vboInit.cpp"            //textureMap[213]
#include "_MODEL_FOLDERS_/marcParts/marcLeftForeArm/marcLeftForeArm_vboInit.cpp"              //textureMap[214]
#include "_MODEL_FOLDERS_/marcParts/marcLeftHand/marcLeftHand_vboInit.cpp"                    //textureMap[215]
#include "_MODEL_FOLDERS_/marcParts/marcRightBoot/marcRightBoot_vboInit.cpp"                  //textureMap[208]
#include "_MODEL_FOLDERS_/marcParts/marcLeftUpperLeg/marcLeftUpperLeg_vboInit.cpp"            //textureMap[209]   
#include "_MODEL_FOLDERS_/marcParts/marcLeftLowerLeg/marcLeftLowerLeg_vboInit.cpp"            //textureMap[210]  
#include "_MODEL_FOLDERS_/marcParts/marcLeftBoot/marcLeftBoot_vboInit.cpp"                    //textureMap[211]                    

#include "_MODEL_FOLDERS_/jetPack/jetPackVestStraps/jetPackVestStraps_vboInit.cpp"            //textureMap[220] 
#include "_MODEL_FOLDERS_/jetPack/jetPacksideHandles/jetPacksideHandles_vboInit.cpp"          //normalMap[222]);
#include "_MODEL_FOLDERS_/jetPack/jetPackBindings/jetPackBindings_vboInit.cpp"                //textureMap[221]);
#include "_MODEL_FOLDERS_/jetPack/jetPackTopCones/jetPackTopCones_vboInit.cpp"                //normalMap[225]);
#include "_MODEL_FOLDERS_/jetPack/jetPackMiddleEngines/jetPackMiddleEngines_vboInit.cpp"      //normalMap[224]);   
#include "_MODEL_FOLDERS_/jetPack/jetPackNozzels/jetPackNozzels_vboInit.cpp"                  //normalMap[223]);


#include "_MODEL_FOLDERS_/F1_F8/F1_F8_vboInit.cpp"     //vboID = 573

#include "_MODEL_FOLDERS_/dialogue/keyboardLayoutDialogue_vboInit.cpp"                                      //vboID = 540//texmap= 540//texmap= 541//texmap= 54....//
#include "_MODEL_FOLDERS_/dialogue/keyboard/keyboardLeft_vboInit.cpp"               //vboID = 600
#include "_MODEL_FOLDERS_/dialogue/keyboard/keyboardRight_vboInit.cpp"                  //vboID = 601
//---------------------------------------------------------------------------------------------------   
    loadTexture("_MODEL_FOLDERS_/poseIcons/armsForwardShouldersBack.jpg",     textureMap[541]);
    loadTexture("_MODEL_FOLDERS_/poseIcons/armsBackTiltedIn.jpg",             textureMap[542]);
    loadTexture("_MODEL_FOLDERS_/poseIcons/armsUpShouldersBack.jpg",          textureMap[543]);
    loadTexture("_MODEL_FOLDERS_/poseIcons/armsOutShouldersBack.jpg",         textureMap[544]);
    loadTexture("_MODEL_FOLDERS_/poseIcons/armsOutShouldersForward.jpg",      textureMap[545]);
    //---------------------------------------------------------------------------------
    loadTexture("_MODEL_FOLDERS_/poseIcons/hips.jpg",                         textureMap[583]);
    //-----------------------
    loadTexture("_MODEL_FOLDERS_/poseIcons/torso.jpg",                        textureMap[584]);
    //-----------------------
    loadTexture("_MODEL_FOLDERS_/poseIcons/leftArmUpper.jpg",                 textureMap[585]);
    loadTexture("_MODEL_FOLDERS_/poseIcons/leftArmLower.jpg",                 textureMap[586]);
    loadTexture("_MODEL_FOLDERS_/poseIcons/leftHand.jpg",                     textureMap[587]);
    //-----------------------
    loadTexture("_MODEL_FOLDERS_/poseIcons/rightArmUpper.jpg",                textureMap[588]);
    loadTexture("_MODEL_FOLDERS_/poseIcons/rightArmLower.jpg",                textureMap[589]);
    loadTexture("_MODEL_FOLDERS_/poseIcons/rightHand.jpg",                    textureMap[590]);    
    //-----------------------
    loadTexture("_MODEL_FOLDERS_/poseIcons/head.jpg",                         textureMap[591]);       
    //-----------------------
    loadTexture("_MODEL_FOLDERS_/poseIcons/leftLegUpper.jpg",                 textureMap[592]);
    loadTexture("_MODEL_FOLDERS_/poseIcons/leftLegLower.jpg",                 textureMap[593]);
    loadTexture("_MODEL_FOLDERS_/poseIcons/leftFoot.jpg",                     textureMap[594]);
    //-----------------------
    loadTexture("_MODEL_FOLDERS_/poseIcons/rightLegUpper.jpg",                textureMap[595]);
    loadTexture("_MODEL_FOLDERS_/poseIcons/rightLegLower.jpg",                textureMap[596]);
    loadTexture("_MODEL_FOLDERS_/poseIcons/rightFoot.jpg",                    textureMap[597]);
//---------------------------------------------------------------------------------------------------------------------------------------------
#include "_MODEL_FOLDERS_/positionedModelNumbers/zero_vboInit.cpp"
#include "_MODEL_FOLDERS_/positionedModelNumbers/one_vboInit.cpp"                
#include "_MODEL_FOLDERS_/positionedModelNumbers/two_vboInit.cpp"    
#include "_MODEL_FOLDERS_/positionedModelNumbers/three_vboInit.cpp"    
#include "_MODEL_FOLDERS_/positionedModelNumbers/four_vboInit.cpp" 
#include "_MODEL_FOLDERS_/positionedModelNumbers/five_vboInit.cpp"
#include "_MODEL_FOLDERS_/positionedModelNumbers/six_vboInit.cpp"    
#include "_MODEL_FOLDERS_/positionedModelNumbers/seven_vboInit.cpp" 
#include "_MODEL_FOLDERS_/positionedModelNumbers/eight_vboInit.cpp"   
#include "_MODEL_FOLDERS_/positionedModelNumbers/nine_vboInit.cpp"   
  

#include "_MODEL_FOLDERS_/positionedModelNumbers/decimalPoint_vboInit.cpp"   
//====================================================================================  
#include "_MODEL_FOLDERS_/iconPlates_x4/iconPlates_x4_Init.cpp"                                                                   
//====================================================================================                                          

//----------------------------------------------------------------------------------------------------------------------------
   
//-------------------------------------------------------------------=====================================================
//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------  
        glGenFramebuffersEXT                     = (PFNGLGENFRAMEBUFFERSEXTPROC)wglGetProcAddress("glGenFramebuffersEXT");
        glDeleteFramebuffersEXT                  = (PFNGLDELETEFRAMEBUFFERSEXTPROC)wglGetProcAddress("glDeleteFramebuffersEXT");
        glBindFramebufferEXT                     = (PFNGLBINDFRAMEBUFFEREXTPROC)wglGetProcAddress("glBindFramebufferEXT");
        glCheckFramebufferStatusEXT              = (PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC)wglGetProcAddress("glCheckFramebufferStatusEXT");
        glGetFramebufferAttachmentParameterivEXT = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC)wglGetProcAddress("glGetFramebufferAttachmentParameterivEXT");
        glGenerateMipmapEXT                      = (PFNGLGENERATEMIPMAPEXTPROC)wglGetProcAddress("glGenerateMipmapEXT");
        glFramebufferTexture2DEXT                = (PFNGLFRAMEBUFFERTEXTURE2DEXTPROC)wglGetProcAddress("glFramebufferTexture2DEXT");
        glFramebufferRenderbufferEXT             = (PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC)wglGetProcAddress("glFramebufferRenderbufferEXT");
        glGenRenderbuffersEXT                    = (PFNGLGENRENDERBUFFERSEXTPROC)wglGetProcAddress("glGenRenderbuffersEXT");
        glDeleteRenderbuffersEXT                 = (PFNGLDELETERENDERBUFFERSEXTPROC)wglGetProcAddress("glDeleteRenderbuffersEXT");
        glBindRenderbufferEXT                    = (PFNGLBINDRENDERBUFFEREXTPROC)wglGetProcAddress("glBindRenderbufferEXT");
        glRenderbufferStorageEXT                 = (PFNGLRENDERBUFFERSTORAGEEXTPROC)wglGetProcAddress("glRenderbufferStorageEXT");    
    
//---------------------------------------------------

    
        glGenTextures(1, &textureMap[0]);
        glBindTexture(GL_TEXTURE_2D, textureMap[0]);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,     GL_CLAMP_TO_EDGE);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,     GL_CLAMP_TO_EDGE);
        //glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP,    GL_TRUE);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, TEXTURE_WIDTH, TEXTURE_HEIGHT, 0, GL_BGRA, GL_UNSIGNED_BYTE, 0);
        glBindTexture(GL_TEXTURE_2D, 0);    
    
        glGenFramebuffersEXT(1, &fboId);
        glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, fboId);

        glGenRenderbuffersEXT(1, &rboId);
        glBindRenderbufferEXT(GL_RENDERBUFFER_EXT, rboId);
        glRenderbufferStorageEXT(GL_RENDERBUFFER_EXT, GL_DEPTH_COMPONENT, TEXTURE_WIDTH, TEXTURE_HEIGHT);
        glBindRenderbufferEXT(GL_RENDERBUFFER_EXT, 0);

        glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT, GL_TEXTURE_2D, textureMap[0], 0);

        glFramebufferRenderbufferEXT(GL_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT_EXT, GL_RENDERBUFFER_EXT, rboId);
        
        glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
//---------------------------------------------------

    
    glGenTextures(1, &textureMap[1]);
    glBindTexture(GL_TEXTURE_2D, textureMap[1]);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,     GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,     GL_CLAMP_TO_EDGE);
  //glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP,    GL_TRUE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE, TEXTURE_WIDTH, TEXTURE_HEIGHT, 0, GL_LUMINANCE, GL_UNSIGNED_BYTE, 0);
    glBindTexture(GL_TEXTURE_2D, 0);    
    
    glGenFramebuffersEXT(1, &gaussianBlurHorizontalPass_fboId);
    glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, gaussianBlurHorizontalPass_fboId);
    glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT, GL_TEXTURE_2D, textureMap[1], 0);
    glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);

    #include "_MODEL_FOLDERS_/gaussianBlur/gaussianBlurHorizontalPass/gaussianBlurHorizontalPass_vboInit.cpp"     //vboID = 300

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    glGenTextures(1, &textureMap[2]);
    glBindTexture(GL_TEXTURE_2D, textureMap[2]);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,     GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,     GL_CLAMP_TO_EDGE);
  //glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP,    GL_TRUE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE, TEXTURE_WIDTH, TEXTURE_HEIGHT, 0, GL_LUMINANCE, GL_UNSIGNED_BYTE, 0);
    glBindTexture(GL_TEXTURE_2D, 0);    
    
    glGenFramebuffersEXT(1, &gaussianBlurVerticalPass_fboId);
    glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, gaussianBlurVerticalPass_fboId);
    glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT, GL_TEXTURE_2D, textureMap[2], 0);
    glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);

    #include "_MODEL_FOLDERS_/gaussianBlur/gaussianBlurVerticalPass/gaussianBlurVerticalPass_vboInit.cpp"     //vboID = 301

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




SetVSyncState(true);

}
        
         
//----------------------------------------------------------------------------------------------------------------------------------@@@@@@@@@@@@@@@@@@@@@@
//----------------------------------------------------------------------------------------------------------------------------------@@@@@@@@@@@@@@@@@@@@@@
//----------------------------------------------------------------------------------------------------------------------------------@@@@@@@@@@@@@@@@@@@@@@
//----------------------------------------------------------------------------------------------------------------------------------@@@@@@@@@@@@@@@@@@@@@@
//----------------------------------------------------------------------------------------------------------------------------------@@@@@@@@@@@@@@@@@@@@@@
//----------------------------------------------------------------------------------------------------------------------------------@@@@@@@@@@@@@@@@@@@@@@
//----------------------------------------------------------------------------------------------------------------------------------@@@@@@@@@@@@@@@@@@@@@@
//----------------------------------------------------------------------------------------------------------------------------------@@@@@@@@@@@@@@@@@@@@@@
//----------------------------------------------------------------------------------------------------------------------------------@@@@@@@@@@@@@@@@@@@@@@
//----------------------------------------------------------------------------------------------------------------------------------@@@@@@@@@@@@@@@@@@@@@@
//----------------------------------------------------------------------------------------------------------------------------------@@@@@@@@@@@@@@@@@@@@@@
//----------------------------------------------------------------------------------------------------------------------------------@@@@@@@@@@@@@@@@@@@@@@
//----------------------------------------------------------------------------------------------------------------------------------@@@@@@@@@@@@@@@@@@@@@@
//----------------------------------------------------------------------------------------------------------------------------------@@@@@@@@@@@@@@@@@@@@@@
//----------------------------------------------------------------------------------------------------------------------------------@@@@@@@@@@@@@@@@@@@@@@
//----------------------------------------------------------------------------------------------------------------------------------@@@@@@@@@@@@@@@@@@@@@@
//----------------------------------------------------------------------------------------------------------------------------------@@@@@@@@@@@@@@@@@@@@@@
//----------------------------------------------------------------------------------------------------------------------------------@@@@@@@@@@@@@@@@@@@@@@
//----------------------------------------------------------------------------------------------------------------------------------@@@@@@@@@@@@@@@@@@@@@@


void render(void)//////////////////////_______RENDER_____RENDER____RENDER_______RENDER_____RENDER____RENDER_______RENDER_____RENDER____RENDER
{      
  
     //#include "animationFiles/runTimeAnimation.cpp"
     #include "_MODEL_FOLDERS_/marcParts/marcAnimations/animationFiles/ME_AnimationSet.cpp"
   
     if(hips_POSITION_AnimationSequence)
     {
          if(hips_POSITION_animationBlendFactor >= 0.0f && hips_POSITION_animationBlendFactor <= 1.0f)
          {
              hips_POSITION[0]     =      hips_POSITION_MOVE_FRAMEA[0] * (1 - hips_POSITION_animationBlendFactor) 
                                   +      hips_POSITION_MOVE_FRAMEB[0] *      hips_POSITION_animationBlendFactor;        
             
              hips_POSITION[1]     =      hips_POSITION_MOVE_FRAMEA[1] * (1 - hips_POSITION_animationBlendFactor) 
                                   +      hips_POSITION_MOVE_FRAMEB[1] *      hips_POSITION_animationBlendFactor; 
        
              hips_POSITION[2]     =      hips_POSITION_MOVE_FRAMEA[2] * (1 - hips_POSITION_animationBlendFactor) 
                                   +      hips_POSITION_MOVE_FRAMEB[2] *      hips_POSITION_animationBlendFactor;
          }
          if(hips_POSITION_animationBlendFactor >= 1.0f)
          {
             hips_POSITION_setSelection ++;
             hips_POSITION_animationBlendFactor = 0;
             //reset_LoadSet        = true;
          }
          if(hips_POSITION_setSelection == hips_POSITION_setSelectionLimit + 1)
          {
             hips_POSITION_setSelection      = 1;
             hips_POSITION_AnimationSequence = false;
          }   
     
           
          hips_POSITION_animationBlendFactor += hips_POSITION_ROTATION_FRAME_TIME[hips_POSITION_setSelection-1]; 
          
          //hips_POSITION_animationBlendFactor += hips_POSITION_FRAME_TIME_01 * runSlowMotion;
          //oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
         
          if(hips_POSITION_setSelection == 1 )
          {
               hips_POSITION_SET_01[0] = hips_POSITION_MOVE_FRAMEA[0];
               hips_POSITION_SET_01[1] = hips_POSITION_MOVE_FRAMEA[1];                   
               hips_POSITION_SET_01[2] = hips_POSITION_MOVE_FRAMEA[2];
          }
          if(hips_POSITION_setSelection == 2)
          {
               hips_POSITION_SET_02[0] = hips_POSITION_MOVE_FRAMEA[0];
               hips_POSITION_SET_02[1] = hips_POSITION_MOVE_FRAMEA[1];                   
               hips_POSITION_SET_02[2] = hips_POSITION_MOVE_FRAMEA[2];
          }     
          if(hips_POSITION_setSelection == 3)
          {
               hips_POSITION_SET_03[0] = hips_POSITION_MOVE_FRAMEA[0];
               hips_POSITION_SET_03[1] = hips_POSITION_MOVE_FRAMEA[1];                   
               hips_POSITION_SET_03[2] = hips_POSITION_MOVE_FRAMEA[2];
          }     
          if(hips_POSITION_setSelection == 4)
          {
               hips_POSITION_SET_04[0] = hips_POSITION_MOVE_FRAMEA[0];
               hips_POSITION_SET_04[1] = hips_POSITION_MOVE_FRAMEA[1];                   
               hips_POSITION_SET_04[2] = hips_POSITION_MOVE_FRAMEA[2];
          }     
          if(hips_POSITION_setSelection == 5)
          {
               hips_POSITION_SET_05[0] = hips_POSITION_MOVE_FRAMEA[0];
               hips_POSITION_SET_05[1] = hips_POSITION_MOVE_FRAMEA[1];                   
               hips_POSITION_SET_05[2] = hips_POSITION_MOVE_FRAMEA[2];
          }      
          if(hips_POSITION_setSelection == 6)
          {
               hips_POSITION_SET_06[0] = hips_POSITION_MOVE_FRAMEA[0];
               hips_POSITION_SET_06[1] = hips_POSITION_MOVE_FRAMEA[1];                   
               hips_POSITION_SET_06[2] = hips_POSITION_MOVE_FRAMEA[2];
          }         
          if(hips_POSITION_setSelection == 7)
          {
               hips_POSITION_SET_07[0] = hips_POSITION_MOVE_FRAMEA[0];
               hips_POSITION_SET_07[1] = hips_POSITION_MOVE_FRAMEA[1];                   
               hips_POSITION_SET_07[2] = hips_POSITION_MOVE_FRAMEA[2];
          }           
          //oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo     
     }        
     //----------------------------------------------------------------------------------------------------------------------------------    
     if(hips_AnimationSequence)         
     {   
         if(animationBlendFactor_HIPS >= 0.0f && animationBlendFactor_HIPS <= 1.0f)
         {     
             hips_ROTATE[3]      =      hips_ROTATE_FRAMEA[3] 
                                 * (1 - animationBlendFactor_HIPS) 
                                 +      hips_ROTATE_FRAMEB[3] 
                                 *      animationBlendFactor_HIPS;        
        
             hips_ROTATE[0]      =      hips_ROTATE_FRAMEA[0] 
                                 * (1 - animationBlendFactor_HIPS) 
                                 +      hips_ROTATE_FRAMEB[0] 
                                 *      animationBlendFactor_HIPS; 
        
             hips_ROTATE[1]      =      hips_ROTATE_FRAMEA[1] 
                                 * (1 - animationBlendFactor_HIPS) 
                                 +      hips_ROTATE_FRAMEB[1] 
                                 *      animationBlendFactor_HIPS;
        
             hips_ROTATE[2]      =      hips_ROTATE_FRAMEA[2] 
                                 * (1 - animationBlendFactor_HIPS) 
                                 +      hips_ROTATE_FRAMEB[2] 
                                 *      animationBlendFactor_HIPS;    
         }
         if(animationBlendFactor_HIPS >= 1.0f)
         {
             setSelection_HIPS ++;
             animationBlendFactor_HIPS = 0.0f;
         }
         if(setSelection_HIPS == setSelectionLimit_HIPS+1)
         {
             setSelection_HIPS = 0;
             hips_AnimationSequence = false;
         }
        
         animationBlendFactor_HIPS += hips_ROTATION_FRAME_TIME[setSelection_HIPS - 1];
         
         // animationBlendFactor_HIPS       += HIPS_FRAME_TIME_01 * runSlowMotion;       
         //oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
       
       
          if(setSelection_HIPS == 1)
          {
               hips_SET_01[0] = hips_ROTATE_FRAMEA[0];
               hips_SET_01[1] = hips_ROTATE_FRAMEA[1];                   
               hips_SET_01[2] = hips_ROTATE_FRAMEA[2];
               hips_SET_01[3] = hips_ROTATE_FRAMEA[3];          
          }
          if(setSelection_HIPS == 2)
          {
               hips_SET_02[0] = hips_ROTATE_FRAMEA[0];
               hips_SET_02[1] = hips_ROTATE_FRAMEA[1];                   
               hips_SET_02[2] = hips_ROTATE_FRAMEA[2];
               hips_SET_02[3] = hips_ROTATE_FRAMEA[3];         
          }     
          if(setSelection_HIPS == 3)
          {
               hips_SET_03[0] = hips_ROTATE_FRAMEA[0];
               hips_SET_03[1] = hips_ROTATE_FRAMEA[1];                   
               hips_SET_03[2] = hips_ROTATE_FRAMEA[2];
               hips_SET_03[3] = hips_ROTATE_FRAMEA[3];             
          }     
          if(setSelection_HIPS == 4)
          {
               hips_SET_04[0] = hips_ROTATE_FRAMEA[0];
               hips_SET_04[1] = hips_ROTATE_FRAMEA[1];                   
               hips_SET_04[2] = hips_ROTATE_FRAMEA[2];
               hips_SET_04[3] = hips_ROTATE_FRAMEA[3];             
          }     
          if(setSelection_HIPS == 5)
          {
               hips_SET_05[0] = hips_ROTATE_FRAMEA[0];
               hips_SET_05[1] = hips_ROTATE_FRAMEA[1];                   
               hips_SET_05[2] = hips_ROTATE_FRAMEA[2];
               hips_SET_05[3] = hips_ROTATE_FRAMEA[3];             
          }      
          if(setSelection_HIPS == 6)
          {
               hips_SET_06[0] = hips_ROTATE_FRAMEA[0];
               hips_SET_06[1] = hips_ROTATE_FRAMEA[1];                   
               hips_SET_06[2] = hips_ROTATE_FRAMEA[2];
               hips_SET_06[3] = hips_ROTATE_FRAMEA[3];             
          }         
          if(setSelection_HIPS == 7)
          {
               hips_SET_07[0] = hips_ROTATE_FRAMEA[0];
               hips_SET_07[1] = hips_ROTATE_FRAMEA[1];                   
               hips_SET_07[2] = hips_ROTATE_FRAMEA[2];
               hips_SET_07[3] = hips_ROTATE_FRAMEA[3];             
          }           
          //oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo      
     
     }
     //----------------------------------------------------------------------------------------------------------------------------------      
     if(torso_AnimationSequence)
     {        
         if(animationBlendFactor_TORSO >= 0.0f && animationBlendFactor_TORSO <= 1.0f)
         {    
              torso_ROTATE[3]           =      torso_ROTATE_FRAMEA[3]           
                                        * (1 - animationBlendFactor_TORSO) 
                                        +      torso_ROTATE_FRAMEB[3]           
                                        *      animationBlendFactor_TORSO;        
        
              torso_ROTATE[0]           =      torso_ROTATE_FRAMEA[0]           
                                        * (1 - animationBlendFactor_TORSO) 
                                        +      torso_ROTATE_FRAMEB[0]           
                                        *      animationBlendFactor_TORSO; 
        
              torso_ROTATE[1]           =      torso_ROTATE_FRAMEA[1]           
                                        * (1 - animationBlendFactor_TORSO) 
                                        +      torso_ROTATE_FRAMEB[1]           
                                        *      animationBlendFactor_TORSO;
        
              torso_ROTATE[2]           =      torso_ROTATE_FRAMEA[2]           
                                        * (1 - animationBlendFactor_TORSO) 
                                        +      torso_ROTATE_FRAMEB[2]           
                                        *      animationBlendFactor_TORSO;     
         }    
         if(animationBlendFactor_TORSO >= 1.0f)
         {
              setSelection_TORSO ++;
              animationBlendFactor_TORSO = 0.0f;
         }
         if(setSelection_TORSO == setSelectionLimit_TORSO+1)
         {
              setSelection_TORSO = 0;
              torso_AnimationSequence = false;
         }
         animationBlendFactor_TORSO      += torso_ROTATION_FRAME_TIME[setSelection_TORSO - 1];  
          //oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
    
          if(setSelection_TORSO == 1)
          {
               torso_SET_01[0] = torso_ROTATE_FRAMEA[0];
               torso_SET_01[1] = torso_ROTATE_FRAMEA[1];                   
               torso_SET_01[2] = torso_ROTATE_FRAMEA[2];
               torso_SET_01[3] = torso_ROTATE_FRAMEA[3];          
          }
          if(setSelection_TORSO == 2)
          {
               torso_SET_02[0] = torso_ROTATE_FRAMEA[0];
               torso_SET_02[1] = torso_ROTATE_FRAMEA[1];                   
               torso_SET_02[2] = torso_ROTATE_FRAMEA[2];
               torso_SET_02[3] = torso_ROTATE_FRAMEA[3];          
          }     
          if(setSelection_TORSO == 3)
          {
               torso_SET_03[0] = torso_ROTATE_FRAMEA[0];
               torso_SET_03[1] = torso_ROTATE_FRAMEA[1];                   
               torso_SET_03[2] = torso_ROTATE_FRAMEA[2];
               torso_SET_03[3] = torso_ROTATE_FRAMEA[3];          
          }     
          if(setSelection_TORSO == 4)
          {
               torso_SET_04[0] = torso_ROTATE_FRAMEA[0];
               torso_SET_04[1] = torso_ROTATE_FRAMEA[1];                   
               torso_SET_04[2] = torso_ROTATE_FRAMEA[2];
               torso_SET_04[3] = torso_ROTATE_FRAMEA[3];          
          }     
          if(setSelection_TORSO == 5)
          {
               torso_SET_05[0] = torso_ROTATE_FRAMEA[0];
               torso_SET_05[1] = torso_ROTATE_FRAMEA[1];                   
               torso_SET_05[2] = torso_ROTATE_FRAMEA[2];
               torso_SET_05[3] = torso_ROTATE_FRAMEA[3];          
          }      
          if(setSelection_TORSO == 6)
          {
               torso_SET_06[0] = torso_ROTATE_FRAMEA[0];
               torso_SET_06[1] = torso_ROTATE_FRAMEA[1];                   
               torso_SET_06[2] = torso_ROTATE_FRAMEA[2];
               torso_SET_06[3] = torso_ROTATE_FRAMEA[3];          
          }         
          if(setSelection_TORSO == 7)
          {
               torso_SET_07[0] = torso_ROTATE_FRAMEA[0];
               torso_SET_07[1] = torso_ROTATE_FRAMEA[1];                   
               torso_SET_07[2] = torso_ROTATE_FRAMEA[2];
               torso_SET_07[3] = torso_ROTATE_FRAMEA[3];          
          }         
         //oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo      
     }    
     //----------------------------------------------------------------------------------------------------------------------------------     
     if(head_AnimationSequence)
     {  
         if(animationBlendFactor_HEAD >= 0.0f && animationBlendFactor_HEAD <= 1.0f)
         {                          
                head_ROTATE[3]            = head_ROTATE_FRAMEA[3] * (1 - animationBlendFactor_HEAD) 
                                          + head_ROTATE_FRAMEB[3] * animationBlendFactor_HEAD;        
        
                head_ROTATE[0]            = head_ROTATE_FRAMEA[0] * (1 - animationBlendFactor_HEAD) 
                                          + head_ROTATE_FRAMEB[0] * animationBlendFactor_HEAD; 
        
                head_ROTATE[1]            = head_ROTATE_FRAMEA[1] * (1 - animationBlendFactor_HEAD) 
                                          + head_ROTATE_FRAMEB[1] * animationBlendFactor_HEAD;
        
                head_ROTATE[2]            = head_ROTATE_FRAMEA[2] * (1 - animationBlendFactor_HEAD) 
                                          + head_ROTATE_FRAMEB[2] * animationBlendFactor_HEAD; 
         }
         if(animationBlendFactor_HEAD >= 1.0f)
         {
               setSelection_HEAD ++;
               animationBlendFactor_HEAD = 0.0f;
         }
         if(setSelection_HEAD == setSelectionLimit_HEAD+1)
         {
               setSelection_HEAD = 0;
               head_AnimationSequence = false;
         }
         animationBlendFactor_HEAD         += head_ROTATION_FRAME_TIME[setSelectionLimit_HEAD - 1];  
          //oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
     
          if(setSelection_HEAD == 1)
          {
               head_SET_01[0] = head_ROTATE_FRAMEA[0];
               head_SET_01[1] = head_ROTATE_FRAMEA[1];                   
               head_SET_01[2] = head_ROTATE_FRAMEA[2];
               head_SET_01[3] = head_ROTATE_FRAMEA[3];          
          }
          if(setSelection_HEAD == 2)
          {
               head_SET_02[0] = head_ROTATE_FRAMEA[0];
               head_SET_02[1] = head_ROTATE_FRAMEA[1];                   
               head_SET_02[2] = head_ROTATE_FRAMEA[2];
               head_SET_02[3] = head_ROTATE_FRAMEA[3];
          }     
          if(setSelection_HEAD == 3)
          {
               head_SET_03[0] = head_ROTATE_FRAMEA[0];
               head_SET_03[1] = head_ROTATE_FRAMEA[1];                   
               head_SET_03[2] = head_ROTATE_FRAMEA[2];
               head_SET_03[3] = head_ROTATE_FRAMEA[3];          
          }     
          if(setSelection_HEAD == 4)
          {
               head_SET_04[0] = head_ROTATE_FRAMEA[0];
               head_SET_04[1] = head_ROTATE_FRAMEA[1];                   
               head_SET_04[2] = head_ROTATE_FRAMEA[2];
               head_SET_04[3] = head_ROTATE_FRAMEA[3];          
          }     
          if(setSelection_HEAD == 5)
          {
               head_SET_05[0] = head_ROTATE_FRAMEA[0];
               head_SET_05[1] = head_ROTATE_FRAMEA[1];                   
               head_SET_05[2] = head_ROTATE_FRAMEA[2];
               head_SET_05[3] = head_ROTATE_FRAMEA[3];          
          }      
          if(setSelection_HEAD == 6)
          {
               head_SET_06[0] = head_ROTATE_FRAMEA[0];
               head_SET_06[1] = head_ROTATE_FRAMEA[1];                   
               head_SET_06[2] = head_ROTATE_FRAMEA[2];
               head_SET_06[3] = head_ROTATE_FRAMEA[3];          
          }         
          if(setSelection_HEAD == 7)
          {
               head_SET_07[0] = head_ROTATE_FRAMEA[0];
               head_SET_07[1] = head_ROTATE_FRAMEA[1];                   
               head_SET_07[2] = head_ROTATE_FRAMEA[2];
               head_SET_07[3] = head_ROTATE_FRAMEA[3];          
          }          
          //oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo      
     }
//----------------------------------------------------------------------------------------------------------------------------------
     if(leftUpperArm_AnimationSequence)
     {         
         if(animationBlendFactor_LEFT_ARM >= 0.0f && animationBlendFactor_LEFT_ARM <= 1.0f)
         {    
              leftUpperArm_ROTATE[3]    = leftUpperArm_ROTATE_FRAMEA[3]    * (1 - animationBlendFactor_LEFT_ARM) 
                                        + leftUpperArm_ROTATE_FRAMEB[3]    *      animationBlendFactor_LEFT_ARM;        
        
              leftUpperArm_ROTATE[0]    = leftUpperArm_ROTATE_FRAMEA[0]    * (1 - animationBlendFactor_LEFT_ARM) 
                                        + leftUpperArm_ROTATE_FRAMEB[0]    *      animationBlendFactor_LEFT_ARM; 
        
              leftUpperArm_ROTATE[1]    = leftUpperArm_ROTATE_FRAMEA[1]    * (1 - animationBlendFactor_LEFT_ARM) 
                                        + leftUpperArm_ROTATE_FRAMEB[1]    *      animationBlendFactor_LEFT_ARM;
        
              leftUpperArm_ROTATE[2]    = leftUpperArm_ROTATE_FRAMEA[2]    * (1 - animationBlendFactor_LEFT_ARM) 
                                        + leftUpperArm_ROTATE_FRAMEB[2]    *      animationBlendFactor_LEFT_ARM;
                                         
              leftForeArm_ROTATE[3]     = leftForeArm_ROTATE_FRAMEA[3]     * (1 - animationBlendFactor_LEFT_ARM) 
                                        + leftForeArm_ROTATE_FRAMEB[3]     *      animationBlendFactor_LEFT_ARM;        
        
              leftForeArm_ROTATE[0]     = leftForeArm_ROTATE_FRAMEA[0]     * (1 - animationBlendFactor_LEFT_ARM) 
                                        + leftForeArm_ROTATE_FRAMEB[0]     *      animationBlendFactor_LEFT_ARM; 
        
              leftForeArm_ROTATE[1]     = leftForeArm_ROTATE_FRAMEA[1]     * (1 - animationBlendFactor_LEFT_ARM) 
                                        + leftForeArm_ROTATE_FRAMEB[1]     *      animationBlendFactor_LEFT_ARM;
        
              leftForeArm_ROTATE[2]     = leftForeArm_ROTATE_FRAMEA[2]     * (1 - animationBlendFactor_LEFT_ARM) 
                                        + leftForeArm_ROTATE_FRAMEB[2]     *      animationBlendFactor_LEFT_ARM;                                          
              
              leftHand_ROTATE[3]  = leftHand_ROTATE_FRAMEA[3]  * (1 - animationBlendFactor_LEFT_ARM) 
                                        + leftHand_ROTATE_FRAMEB[3]  *      animationBlendFactor_LEFT_ARM;        
        
              leftHand_ROTATE[0]  = leftHand_ROTATE_FRAMEA[0]  * (1 - animationBlendFactor_LEFT_ARM) 
                                        + leftHand_ROTATE_FRAMEB[0]  *      animationBlendFactor_LEFT_ARM; 
        
              leftHand_ROTATE[1]  = leftHand_ROTATE_FRAMEA[1]  * (1 - animationBlendFactor_LEFT_ARM) 
                                        + leftHand_ROTATE_FRAMEB[1]  *      animationBlendFactor_LEFT_ARM;
        
              leftHand_ROTATE[2]  = leftHand_ROTATE_FRAMEA[2]  * (1 - animationBlendFactor_LEFT_ARM) 
                                        + leftHand_ROTATE_FRAMEB[2]  *      animationBlendFactor_LEFT_ARM;      
          }    
         
          if(animationBlendFactor_LEFT_ARM >= 1.0f)
          {
               setSelection_LEFT_ARM ++;
               animationBlendFactor_LEFT_ARM = 0.0f;
          }
          if(setSelection_LEFT_ARM == setSelectionLimit_LEFT_ARM + 1)
          {
               setSelection_LEFT_ARM = 0;
               leftUpperArm_AnimationSequence = false;
          }
         
          animationBlendFactor_LEFT_ARM  += leftArm_ROTATION_FRAME_TIME[setSelectionLimit_LEFT_ARM - 1];
          //oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
       
          if(setSelection_LEFT_ARM == 1)
          {
               leftUpperArm_SET_01[0] = leftUpperArm_ROTATE_FRAMEA[0];
               leftUpperArm_SET_01[1] = leftUpperArm_ROTATE_FRAMEA[1];                   
               leftUpperArm_SET_01[2] = leftUpperArm_ROTATE_FRAMEA[2];
               leftUpperArm_SET_01[3] = leftUpperArm_ROTATE_FRAMEA[3];               
               //----------------------------------------------------------------
               leftForeArm_SET_01[0] = leftForeArm_ROTATE_FRAMEA[0];
               leftForeArm_SET_01[1] = leftForeArm_ROTATE_FRAMEA[1];                   
               leftForeArm_SET_01[2] = leftForeArm_ROTATE_FRAMEA[2];
               leftForeArm_SET_01[3] = leftForeArm_ROTATE_FRAMEA[3];               
               //----------------------------------------------------------------
               leftHand_SET_01[0] = leftHand_ROTATE_FRAMEA[0];
               leftHand_SET_01[1] = leftHand_ROTATE_FRAMEA[1];                   
               leftHand_SET_01[2] = leftHand_ROTATE_FRAMEA[2];            
               leftHand_SET_01[3] = leftHand_ROTATE_FRAMEA[3];    
          }
          if(setSelection_LEFT_ARM == 2)
          {
               leftUpperArm_SET_02[0] = leftUpperArm_ROTATE_FRAMEA[0];
               leftUpperArm_SET_02[1] = leftUpperArm_ROTATE_FRAMEA[1];                   
               leftUpperArm_SET_02[2] = leftUpperArm_ROTATE_FRAMEA[2];
               leftUpperArm_SET_02[3] = leftUpperArm_ROTATE_FRAMEA[3];               
               //----------------------------------------------------------------          
               leftForeArm_SET_02[0] = leftForeArm_ROTATE_FRAMEA[0];
               leftForeArm_SET_02[1] = leftForeArm_ROTATE_FRAMEA[1];                   
               leftForeArm_SET_02[2] = leftForeArm_ROTATE_FRAMEA[2];
               leftForeArm_SET_02[3] = leftForeArm_ROTATE_FRAMEA[3];              
               //----------------------------------------------------------------              
               leftHand_SET_02[0] = leftHand_ROTATE_FRAMEA[0];
               leftHand_SET_02[1] = leftHand_ROTATE_FRAMEA[1];                   
               leftHand_SET_02[2] = leftHand_ROTATE_FRAMEA[2];          
               leftHand_SET_02[3] = leftHand_ROTATE_FRAMEA[3];            
          }     
          if(setSelection_LEFT_ARM == 3)
          {
               leftUpperArm_SET_03[0] = leftUpperArm_ROTATE_FRAMEA[0];
               leftUpperArm_SET_03[1] = leftUpperArm_ROTATE_FRAMEA[1];                   
               leftUpperArm_SET_03[2] = leftUpperArm_ROTATE_FRAMEA[2];
               leftUpperArm_SET_03[3] = leftUpperArm_ROTATE_FRAMEA[3];               
               //----------------------------------------------------------------          
               leftForeArm_SET_03[0] = leftForeArm_ROTATE_FRAMEA[0];
               leftForeArm_SET_03[1] = leftForeArm_ROTATE_FRAMEA[1];                   
               leftForeArm_SET_03[2] = leftForeArm_ROTATE_FRAMEA[2];
               leftForeArm_SET_03[3] = leftForeArm_ROTATE_FRAMEA[3];               
               //----------------------------------------------------------------         
               leftHand_SET_03[0] = leftHand_ROTATE_FRAMEA[0];
               leftHand_SET_03[1] = leftHand_ROTATE_FRAMEA[1];                   
               leftHand_SET_03[2] = leftHand_ROTATE_FRAMEA[2];           
               leftHand_SET_03[3] = leftHand_ROTATE_FRAMEA[3];         
         }     
          if(setSelection_LEFT_ARM == 4)
          {
               leftUpperArm_SET_04[0] = leftUpperArm_ROTATE_FRAMEA[0];
               leftUpperArm_SET_04[1] = leftUpperArm_ROTATE_FRAMEA[1];                   
               leftUpperArm_SET_04[2] = leftUpperArm_ROTATE_FRAMEA[2];
               leftUpperArm_SET_04[3] = leftUpperArm_ROTATE_FRAMEA[3];               
               //----------------------------------------------------------------          
               leftForeArm_SET_04[0] = leftForeArm_ROTATE_FRAMEA[0];
               leftForeArm_SET_04[1] = leftForeArm_ROTATE_FRAMEA[1];                   
               leftForeArm_SET_04[2] = leftForeArm_ROTATE_FRAMEA[2];
               leftForeArm_SET_04[3] = leftForeArm_ROTATE_FRAMEA[3];               
               //----------------------------------------------------------------          
               leftHand_SET_04[0] = leftHand_ROTATE_FRAMEA[0];
               leftHand_SET_04[1] = leftHand_ROTATE_FRAMEA[1];                   
               leftHand_SET_04[2] = leftHand_ROTATE_FRAMEA[2];            
               leftHand_SET_04[3] = leftHand_ROTATE_FRAMEA[3];          
          }     
          if(setSelection_LEFT_ARM == 5)
          {
               leftUpperArm_SET_05[0] = leftUpperArm_ROTATE_FRAMEA[0];
               leftUpperArm_SET_05[1] = leftUpperArm_ROTATE_FRAMEA[1];                   
               leftUpperArm_SET_05[2] = leftUpperArm_ROTATE_FRAMEA[2];
               leftUpperArm_SET_05[3] = leftUpperArm_ROTATE_FRAMEA[3];               
               //----------------------------------------------------------------          
               leftForeArm_SET_05[0] = leftForeArm_ROTATE_FRAMEA[0];
               leftForeArm_SET_05[1] = leftForeArm_ROTATE_FRAMEA[1];                   
               leftForeArm_SET_05[2] = leftForeArm_ROTATE_FRAMEA[2];
               leftForeArm_SET_05[3] = leftForeArm_ROTATE_FRAMEA[3];               
               //----------------------------------------------------------------               
               leftHand_SET_05[0] = leftHand_ROTATE_FRAMEA[0];
               leftHand_SET_05[1] = leftHand_ROTATE_FRAMEA[1];                   
               leftHand_SET_05[2] = leftHand_ROTATE_FRAMEA[2];            
               leftHand_SET_05[3] = leftHand_ROTATE_FRAMEA[3];          
          }      
          if(setSelection_LEFT_ARM == 6)
          {
               leftUpperArm_SET_06[0] = leftUpperArm_ROTATE_FRAMEA[0];
               leftUpperArm_SET_06[1] = leftUpperArm_ROTATE_FRAMEA[1];                   
               leftUpperArm_SET_06[2] = leftUpperArm_ROTATE_FRAMEA[2];
               leftUpperArm_SET_06[3] = leftUpperArm_ROTATE_FRAMEA[3];               
               //----------------------------------------------------------------         
               leftForeArm_SET_06[0] = leftForeArm_ROTATE_FRAMEA[0];
               leftForeArm_SET_06[1] = leftForeArm_ROTATE_FRAMEA[1];                   
               leftForeArm_SET_06[2] = leftForeArm_ROTATE_FRAMEA[2];
               leftForeArm_SET_06[3] = leftForeArm_ROTATE_FRAMEA[3];               
               //----------------------------------------------------------------          
               leftHand_SET_06[0] = leftHand_ROTATE_FRAMEA[0];
               leftHand_SET_06[1] = leftHand_ROTATE_FRAMEA[1];                   
               leftHand_SET_06[2] = leftHand_ROTATE_FRAMEA[2];           
               leftHand_SET_06[3] = leftHand_ROTATE_FRAMEA[3];            
          }         
          if(setSelection_LEFT_ARM == 7)
          {
               leftUpperArm_SET_07[0] = leftUpperArm_ROTATE_FRAMEA[0];
               leftUpperArm_SET_07[1] = leftUpperArm_ROTATE_FRAMEA[1];                   
               leftUpperArm_SET_07[2] = leftUpperArm_ROTATE_FRAMEA[2];
               leftUpperArm_SET_07[3] = leftUpperArm_ROTATE_FRAMEA[3];               
               //----------------------------------------------------------------         
               leftForeArm_SET_07[0] = leftForeArm_ROTATE_FRAMEA[0];
               leftForeArm_SET_07[1] = leftForeArm_ROTATE_FRAMEA[1];                   
               leftForeArm_SET_07[2] = leftForeArm_ROTATE_FRAMEA[2];
               leftForeArm_SET_07[3] = leftForeArm_ROTATE_FRAMEA[3];               
               //----------------------------------------------------------------          
               leftHand_SET_07[0] = leftHand_ROTATE_FRAMEA[0];
               leftHand_SET_07[1] = leftHand_ROTATE_FRAMEA[1];                   
               leftHand_SET_07[2] = leftHand_ROTATE_FRAMEA[2];           
               leftHand_SET_07[3] = leftHand_ROTATE_FRAMEA[3];            
          }          
          //oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo      
     
     }        
     //----------------------------------------------------------------------------------------------------------------------------------      
     if(rightUpperArm_AnimationSequence)
     {     
         if(animationBlendFactor_RIGHT_ARM >= 0.0f && animationBlendFactor_RIGHT_ARM <= 1.0f)
         {     
              rightUpperArm_ROTATE[3]   = rightUpperArm_ROTATE_FRAMEA[3]   * (1 - animationBlendFactor_RIGHT_ARM) 
                                        + rightUpperArm_ROTATE_FRAMEB[3]   * animationBlendFactor_RIGHT_ARM;        
        
              rightUpperArm_ROTATE[0]   = rightUpperArm_ROTATE_FRAMEA[0]   * (1 - animationBlendFactor_RIGHT_ARM) 
                                        + rightUpperArm_ROTATE_FRAMEB[0]   * animationBlendFactor_RIGHT_ARM; 
              
              rightUpperArm_ROTATE[1]   = rightUpperArm_ROTATE_FRAMEA[1]   * (1 - animationBlendFactor_RIGHT_ARM) 
                                        + rightUpperArm_ROTATE_FRAMEB[1]   * animationBlendFactor_RIGHT_ARM;
        
              rightUpperArm_ROTATE[2]   = rightUpperArm_ROTATE_FRAMEA[2]   * (1 - animationBlendFactor_RIGHT_ARM) 
                                        + rightUpperArm_ROTATE_FRAMEB[2]   * animationBlendFactor_RIGHT_ARM;
                                  
              rightForeArm_ROTATE[3]    = rightForeArm_ROTATE_FRAMEA[3]    * (1 - animationBlendFactor_RIGHT_ARM) 
                                        + rightForeArm_ROTATE_FRAMEB[3]    * animationBlendFactor_RIGHT_ARM;        
        
              rightForeArm_ROTATE[0]    = rightForeArm_ROTATE_FRAMEA[0]    * (1 - animationBlendFactor_RIGHT_ARM) 
                                        + rightForeArm_ROTATE_FRAMEB[0]    * animationBlendFactor_RIGHT_ARM; 
        
              rightForeArm_ROTATE[1]    = rightForeArm_ROTATE_FRAMEA[1]    * (1 - animationBlendFactor_RIGHT_ARM) 
                                        + rightForeArm_ROTATE_FRAMEB[1]    * animationBlendFactor_RIGHT_ARM;
        
              rightForeArm_ROTATE[2]    = rightForeArm_ROTATE_FRAMEA[2]    * (1 - animationBlendFactor_RIGHT_ARM) 
                                        + rightForeArm_ROTATE_FRAMEB[2]    * animationBlendFactor_RIGHT_ARM;                                          
                                  
              rightHand_ROTATE[3] = rightHand_ROTATE_FRAMEA[3] * (1 - animationBlendFactor_RIGHT_ARM) 
                                        + rightHand_ROTATE_FRAMEB[3] * animationBlendFactor_RIGHT_ARM;        
        
              rightHand_ROTATE[0] = rightHand_ROTATE_FRAMEA[0] * (1 - animationBlendFactor_RIGHT_ARM) 
                                        + rightHand_ROTATE_FRAMEB[0] * animationBlendFactor_RIGHT_ARM; 
        
              rightHand_ROTATE[1] = rightHand_ROTATE_FRAMEA[1] * (1 - animationBlendFactor_RIGHT_ARM) 
                                        + rightHand_ROTATE_FRAMEB[1] * animationBlendFactor_RIGHT_ARM;
        
              rightHand_ROTATE[2] = rightHand_ROTATE_FRAMEA[2] * (1 - animationBlendFactor_RIGHT_ARM) 
                                        + rightHand_ROTATE_FRAMEB[2] * animationBlendFactor_RIGHT_ARM;    
         }
         if(animationBlendFactor_RIGHT_ARM >= 1.0f)
         {
             setSelection_RIGHT_ARM ++;
             animationBlendFactor_RIGHT_ARM = 0.0f;
         }
    
         if(setSelection_RIGHT_ARM == setSelectionLimit_RIGHT_ARM + 1)
         {
             setSelection_RIGHT_ARM = 0;
             rightUpperArm_AnimationSequence = false;
         }
         animationBlendFactor_RIGHT_ARM += rightArm_ROTATION_FRAME_TIME[setSelectionLimit_RIGHT_ARM - 1];
          //oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
          //oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
       
          if(setSelection_RIGHT_ARM == 1)
          {
               rightUpperArm_SET_01[0] = rightUpperArm_ROTATE_FRAMEA[0];
               rightUpperArm_SET_01[1] = rightUpperArm_ROTATE_FRAMEA[1];                   
               rightUpperArm_SET_01[2] = rightUpperArm_ROTATE_FRAMEA[2];
               rightUpperArm_SET_01[3] = rightUpperArm_ROTATE_FRAMEA[3];               
               //----------------------------------------------------------------
               rightForeArm_SET_01[0] = rightForeArm_ROTATE_FRAMEA[0];
               rightForeArm_SET_01[1] = rightForeArm_ROTATE_FRAMEA[1];                   
               rightForeArm_SET_01[2] = rightForeArm_ROTATE_FRAMEA[2];
               rightForeArm_SET_01[3] = rightForeArm_ROTATE_FRAMEA[3];               
               //----------------------------------------------------------------
               rightHand_SET_01[0] = rightHand_ROTATE_FRAMEA[0];
               rightHand_SET_01[1] = rightHand_ROTATE_FRAMEA[1];                   
               rightHand_SET_01[2] = rightHand_ROTATE_FRAMEA[2];            
               rightHand_SET_01[3] = rightHand_ROTATE_FRAMEA[3];    
          }
          if(setSelection_RIGHT_ARM == 2)
          {
               rightUpperArm_SET_02[0] = rightUpperArm_ROTATE_FRAMEA[0];
               rightUpperArm_SET_02[1] = rightUpperArm_ROTATE_FRAMEA[1];                   
               rightUpperArm_SET_02[2] = rightUpperArm_ROTATE_FRAMEA[2];
               rightUpperArm_SET_02[3] = rightUpperArm_ROTATE_FRAMEA[3];               
               //----------------------------------------------------------------          
               rightForeArm_SET_02[0] = rightForeArm_ROTATE_FRAMEA[0];
               rightForeArm_SET_02[1] = rightForeArm_ROTATE_FRAMEA[1];                   
               rightForeArm_SET_02[2] = rightForeArm_ROTATE_FRAMEA[2];
               rightForeArm_SET_02[3] = rightForeArm_ROTATE_FRAMEA[3];              
               //----------------------------------------------------------------              
               rightHand_SET_02[0] = rightHand_ROTATE_FRAMEA[0];
               rightHand_SET_02[1] = rightHand_ROTATE_FRAMEA[1];                   
               rightHand_SET_02[2] = rightHand_ROTATE_FRAMEA[2];          
               rightHand_SET_02[3] = rightHand_ROTATE_FRAMEA[3];            
          }     
          if(setSelection_RIGHT_ARM == 3)
          {
               rightUpperArm_SET_03[0] = rightUpperArm_ROTATE_FRAMEA[0];
               rightUpperArm_SET_03[1] = rightUpperArm_ROTATE_FRAMEA[1];                   
               rightUpperArm_SET_03[2] = rightUpperArm_ROTATE_FRAMEA[2];
               rightUpperArm_SET_03[3] = rightUpperArm_ROTATE_FRAMEA[3];               
               //----------------------------------------------------------------          
               rightForeArm_SET_03[0] = rightForeArm_ROTATE_FRAMEA[0];
               rightForeArm_SET_03[1] = rightForeArm_ROTATE_FRAMEA[1];                   
               rightForeArm_SET_03[2] = rightForeArm_ROTATE_FRAMEA[2];
               rightForeArm_SET_03[3] = rightForeArm_ROTATE_FRAMEA[3];               
               //----------------------------------------------------------------         
               rightHand_SET_03[0] = rightHand_ROTATE_FRAMEA[0];
               rightHand_SET_03[1] = rightHand_ROTATE_FRAMEA[1];                   
               rightHand_SET_03[2] = rightHand_ROTATE_FRAMEA[2];           
               rightHand_SET_03[3] = rightHand_ROTATE_FRAMEA[3];         
         }     
          if(setSelection_RIGHT_ARM == 4)
          {
               rightUpperArm_SET_04[0] = rightUpperArm_ROTATE_FRAMEA[0];
               rightUpperArm_SET_04[1] = rightUpperArm_ROTATE_FRAMEA[1];                   
               rightUpperArm_SET_04[2] = rightUpperArm_ROTATE_FRAMEA[2];
               rightUpperArm_SET_04[3] = rightUpperArm_ROTATE_FRAMEA[3];               
               //----------------------------------------------------------------          
               rightForeArm_SET_04[0] = rightForeArm_ROTATE_FRAMEA[0];
               rightForeArm_SET_04[1] = rightForeArm_ROTATE_FRAMEA[1];                   
               rightForeArm_SET_04[2] = rightForeArm_ROTATE_FRAMEA[2];
               rightForeArm_SET_04[3] = rightForeArm_ROTATE_FRAMEA[3];               
               //----------------------------------------------------------------          
               rightHand_SET_04[0] = rightHand_ROTATE_FRAMEA[0];
               rightHand_SET_04[1] = rightHand_ROTATE_FRAMEA[1];                   
               rightHand_SET_04[2] = rightHand_ROTATE_FRAMEA[2];            
               rightHand_SET_04[3] = rightHand_ROTATE_FRAMEA[3];          
          }     
          if(setSelection_RIGHT_ARM == 5)
          {
               rightUpperArm_SET_05[0] = rightUpperArm_ROTATE_FRAMEA[0];
               rightUpperArm_SET_05[1] = rightUpperArm_ROTATE_FRAMEA[1];                   
               rightUpperArm_SET_05[2] = rightUpperArm_ROTATE_FRAMEA[2];
               rightUpperArm_SET_05[3] = rightUpperArm_ROTATE_FRAMEA[3];               
               //----------------------------------------------------------------          
               rightForeArm_SET_05[0] = rightForeArm_ROTATE_FRAMEA[0];
               rightForeArm_SET_05[1] = rightForeArm_ROTATE_FRAMEA[1];                   
               rightForeArm_SET_05[2] = rightForeArm_ROTATE_FRAMEA[2];
               rightForeArm_SET_05[3] = rightForeArm_ROTATE_FRAMEA[3];               
               //----------------------------------------------------------------               
               rightHand_SET_05[0] = rightHand_ROTATE_FRAMEA[0];
               rightHand_SET_05[1] = rightHand_ROTATE_FRAMEA[1];                   
               rightHand_SET_05[2] = rightHand_ROTATE_FRAMEA[2];            
               rightHand_SET_05[3] = rightHand_ROTATE_FRAMEA[3];          
          }      
          if(setSelection_RIGHT_ARM == 6)
          {
               rightUpperArm_SET_06[0] = rightUpperArm_ROTATE_FRAMEA[0];
               rightUpperArm_SET_06[1] = rightUpperArm_ROTATE_FRAMEA[1];                   
               rightUpperArm_SET_06[2] = rightUpperArm_ROTATE_FRAMEA[2];
               rightUpperArm_SET_06[3] = rightUpperArm_ROTATE_FRAMEA[3];               
               //----------------------------------------------------------------         
               rightForeArm_SET_06[0] = rightForeArm_ROTATE_FRAMEA[0];
               rightForeArm_SET_06[1] = rightForeArm_ROTATE_FRAMEA[1];                   
               rightForeArm_SET_06[2] = rightForeArm_ROTATE_FRAMEA[2];
               rightForeArm_SET_06[3] = rightForeArm_ROTATE_FRAMEA[3];               
               //----------------------------------------------------------------          
               rightHand_SET_06[0] = rightHand_ROTATE_FRAMEA[0];
               rightHand_SET_06[1] = rightHand_ROTATE_FRAMEA[1];                   
               rightHand_SET_06[2] = rightHand_ROTATE_FRAMEA[2];           
               rightHand_SET_06[3] = rightHand_ROTATE_FRAMEA[3];            
          }         
          if(setSelection_RIGHT_ARM == 7)
          {
               rightUpperArm_SET_07[0] = rightUpperArm_ROTATE_FRAMEA[0];
               rightUpperArm_SET_07[1] = rightUpperArm_ROTATE_FRAMEA[1];                   
               rightUpperArm_SET_07[2] = rightUpperArm_ROTATE_FRAMEA[2];
               rightUpperArm_SET_07[3] = rightUpperArm_ROTATE_FRAMEA[3];               
               //----------------------------------------------------------------         
               rightForeArm_SET_07[0] = rightForeArm_ROTATE_FRAMEA[0];
               rightForeArm_SET_07[1] = rightForeArm_ROTATE_FRAMEA[1];                   
               rightForeArm_SET_07[2] = rightForeArm_ROTATE_FRAMEA[2];
               rightForeArm_SET_07[3] = rightForeArm_ROTATE_FRAMEA[3];               
               //----------------------------------------------------------------          
               rightHand_SET_07[0] = rightHand_ROTATE_FRAMEA[0];
               rightHand_SET_07[1] = rightHand_ROTATE_FRAMEA[1];                   
               rightHand_SET_07[2] = rightHand_ROTATE_FRAMEA[2];           
               rightHand_SET_07[3] = rightHand_ROTATE_FRAMEA[3];            
          }           
          //oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo      
     }
     //----------------------------------------------------------------------------------------------------------------------------------
     if(leftUpperLeg_AnimationSequence)
     {  
       
       
        if(animationBlendFactor_LEFT_LEG >= 0.0f && animationBlendFactor_LEFT_LEG <= 1.0f)
        {    

             leftUpperLeg_ROTATE[3]    = leftUpperLeg_ROTATE_FRAMEA[3]    * (1 - animationBlendFactor_LEFT_LEG) 
                                       + leftUpperLeg_ROTATE_FRAMEB[3]    * animationBlendFactor_LEFT_LEG;        
        
             leftUpperLeg_ROTATE[0]    = leftUpperLeg_ROTATE_FRAMEA[0]    * (1 - animationBlendFactor_LEFT_LEG) 
                                       + leftUpperLeg_ROTATE_FRAMEB[0]    * animationBlendFactor_LEFT_LEG; 
        
             leftUpperLeg_ROTATE[1]    = leftUpperLeg_ROTATE_FRAMEA[1]    * (1 - animationBlendFactor_LEFT_LEG) 
                                       + leftUpperLeg_ROTATE_FRAMEB[1]    * animationBlendFactor_LEFT_LEG;
        
             leftUpperLeg_ROTATE[2]    = leftUpperLeg_ROTATE_FRAMEA[2]    * (1 - animationBlendFactor_LEFT_LEG) 
                                       + leftUpperLeg_ROTATE_FRAMEB[2]    * animationBlendFactor_LEFT_LEG;
             
             leftLowerLeg_ROTATE[3]    = leftLowerLeg_ROTATE_FRAMEA[3]    * (1 - animationBlendFactor_LEFT_LEG) 
                                       + leftLowerLeg_ROTATE_FRAMEB[3]    * animationBlendFactor_LEFT_LEG;        
        
             leftLowerLeg_ROTATE[0]    = leftLowerLeg_ROTATE_FRAMEA[0]    * (1 - animationBlendFactor_LEFT_LEG) 
                                       + leftLowerLeg_ROTATE_FRAMEB[0]    * animationBlendFactor_LEFT_LEG; 
        
             leftLowerLeg_ROTATE[1]    = leftLowerLeg_ROTATE_FRAMEA[1]    * (1 - animationBlendFactor_LEFT_LEG) 
                                       + leftLowerLeg_ROTATE_FRAMEB[1]    * animationBlendFactor_LEFT_LEG;
        
             leftLowerLeg_ROTATE[2]    = leftLowerLeg_ROTATE_FRAMEA[2]    * (1 - animationBlendFactor_LEFT_LEG) 
                                       + leftLowerLeg_ROTATE_FRAMEB[2]    * animationBlendFactor_LEFT_LEG;                                          
             
             leftFoot_ROTATE[3]        = leftFoot_ROTATE_FRAMEA[3]        * (1 - animationBlendFactor_LEFT_LEG) 
                                       + leftFoot_ROTATE_FRAMEB[3]        * animationBlendFactor_LEFT_LEG;        
        
             leftFoot_ROTATE[0]        = leftFoot_ROTATE_FRAMEA[0]        * (1 - animationBlendFactor_LEFT_LEG) 
                                       + leftFoot_ROTATE_FRAMEB[0]        * animationBlendFactor_LEFT_LEG; 
        
             leftFoot_ROTATE[1]        = leftFoot_ROTATE_FRAMEA[1]        * (1 - animationBlendFactor_LEFT_LEG) 
                                       + leftFoot_ROTATE_FRAMEB[1]        * animationBlendFactor_LEFT_LEG;
        
             leftFoot_ROTATE[2]        = leftFoot_ROTATE_FRAMEA[2]        * (1 - animationBlendFactor_LEFT_LEG) 
                                       + leftFoot_ROTATE_FRAMEB[2]        * animationBlendFactor_LEFT_LEG;     
        }    
        if(animationBlendFactor_LEFT_LEG >= 1.0f)
        {
             setSelection_LEFT_LEG ++;
             animationBlendFactor_LEFT_LEG = 0.0f;
        }
        if(setSelection_LEFT_LEG == setSelectionLimit_LEFT_LEG+1)
        {
             setSelection_LEFT_LEG =0;
             leftUpperLeg_AnimationSequence = false;
        }
        animationBlendFactor_LEFT_LEG     += leftLeg_ROTATION_FRAME_TIME[setSelectionLimit_LEFT_LEG - 1];
          //oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
          if(setSelection_LEFT_LEG == 1)
          {
               leftUpperLeg_SET_01[0] = leftUpperLeg_ROTATE_FRAMEA[0];
               leftUpperLeg_SET_01[1] = leftUpperLeg_ROTATE_FRAMEA[1];                   
               leftUpperLeg_SET_01[2] = leftUpperLeg_ROTATE_FRAMEA[2];
               leftUpperLeg_SET_01[3] = leftUpperLeg_ROTATE_FRAMEA[3];
          }
          if(setSelection_LEFT_LEG == 2)
          {
               leftUpperLeg_SET_02[0] = leftUpperLeg_ROTATE_FRAMEA[0];
               leftUpperLeg_SET_02[1] = leftUpperLeg_ROTATE_FRAMEA[1];                   
               leftUpperLeg_SET_02[2] = leftUpperLeg_ROTATE_FRAMEA[2];
               leftUpperLeg_SET_02[3] = leftUpperLeg_ROTATE_FRAMEA[3];
          }     
          if(setSelection_LEFT_LEG == 3)
          {
               leftUpperLeg_SET_03[0] = leftUpperLeg_ROTATE_FRAMEA[0];
               leftUpperLeg_SET_03[1] = leftUpperLeg_ROTATE_FRAMEA[1];                   
               leftUpperLeg_SET_03[2] = leftUpperLeg_ROTATE_FRAMEA[2];
               leftUpperLeg_SET_03[3] = leftUpperLeg_ROTATE_FRAMEA[3];
          }     
          if(setSelection_LEFT_LEG == 4)
          {
               leftUpperLeg_SET_04[0] = leftUpperLeg_ROTATE_FRAMEA[0];
               leftUpperLeg_SET_04[1] = leftUpperLeg_ROTATE_FRAMEA[1];                   
               leftUpperLeg_SET_04[2] = leftUpperLeg_ROTATE_FRAMEA[2];
               leftUpperLeg_SET_04[3] = leftUpperLeg_ROTATE_FRAMEA[3];
          }     
          if(setSelection_LEFT_LEG == 5)
          {
               leftUpperLeg_SET_05[0] = leftUpperLeg_ROTATE_FRAMEA[0];
               leftUpperLeg_SET_05[1] = leftUpperLeg_ROTATE_FRAMEA[1];                   
               leftUpperLeg_SET_05[2] = leftUpperLeg_ROTATE_FRAMEA[2];
               leftUpperLeg_SET_05[3] = leftUpperLeg_ROTATE_FRAMEA[3];
          }      
          if(setSelection_LEFT_LEG == 6)
          {
               leftUpperLeg_SET_06[0] = leftUpperLeg_ROTATE_FRAMEA[0];
               leftUpperLeg_SET_06[1] = leftUpperLeg_ROTATE_FRAMEA[1];                   
               leftUpperLeg_SET_06[2] = leftUpperLeg_ROTATE_FRAMEA[2];
               leftUpperLeg_SET_06[3] = leftUpperLeg_ROTATE_FRAMEA[3];
          }         
          if(setSelection_LEFT_LEG == 7)
          {
               leftUpperLeg_SET_07[0] = leftUpperLeg_ROTATE_FRAMEA[0];
               leftUpperLeg_SET_07[1] = leftUpperLeg_ROTATE_FRAMEA[1];                   
               leftUpperLeg_SET_07[2] = leftUpperLeg_ROTATE_FRAMEA[2];
               leftUpperLeg_SET_07[3] = leftUpperLeg_ROTATE_FRAMEA[3];
          }          
          //oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo      
          if(setSelection_LEFT_LEG == 1)
          {
               leftLowerLeg_SET_01[0] = leftLowerLeg_ROTATE_FRAMEA[0];
               leftLowerLeg_SET_01[1] = leftLowerLeg_ROTATE_FRAMEA[1];                   
               leftLowerLeg_SET_01[2] = leftLowerLeg_ROTATE_FRAMEA[2];
               leftLowerLeg_SET_01[3] = leftLowerLeg_ROTATE_FRAMEA[3];
          }
          if(setSelection_LEFT_LEG == 2)
          {
               leftLowerLeg_SET_02[0] = leftLowerLeg_ROTATE_FRAMEA[0];
               leftLowerLeg_SET_02[1] = leftLowerLeg_ROTATE_FRAMEA[1];                   
               leftLowerLeg_SET_02[2] = leftLowerLeg_ROTATE_FRAMEA[2];
               leftLowerLeg_SET_02[3] = leftLowerLeg_ROTATE_FRAMEA[3];
          }     
          if(setSelection_LEFT_LEG == 3)
          {
               leftLowerLeg_SET_03[0] = leftLowerLeg_ROTATE_FRAMEA[0];
               leftLowerLeg_SET_03[1] = leftLowerLeg_ROTATE_FRAMEA[1];                   
               leftLowerLeg_SET_03[2] = leftLowerLeg_ROTATE_FRAMEA[2];
               leftLowerLeg_SET_03[3] = leftLowerLeg_ROTATE_FRAMEA[3];
          }     
          if(setSelection_LEFT_LEG == 4)
          {
               leftLowerLeg_SET_04[0] = leftLowerLeg_ROTATE_FRAMEA[0];
               leftLowerLeg_SET_04[1] = leftLowerLeg_ROTATE_FRAMEA[1];                   
               leftLowerLeg_SET_04[2] = leftLowerLeg_ROTATE_FRAMEA[2];
               leftLowerLeg_SET_04[3] = leftLowerLeg_ROTATE_FRAMEA[3];
          }     
          if(setSelection_LEFT_LEG == 5)
          {
               leftLowerLeg_SET_05[0] = leftLowerLeg_ROTATE_FRAMEA[0];
               leftLowerLeg_SET_05[1] = leftLowerLeg_ROTATE_FRAMEA[1];                   
               leftLowerLeg_SET_05[2] = leftLowerLeg_ROTATE_FRAMEA[2];
               leftLowerLeg_SET_05[3] = leftLowerLeg_ROTATE_FRAMEA[3];
          }      
          if(setSelection_LEFT_LEG == 6)
          {
               leftLowerLeg_SET_06[0] = leftLowerLeg_ROTATE_FRAMEA[0];
               leftLowerLeg_SET_06[1] = leftLowerLeg_ROTATE_FRAMEA[1];                   
               leftLowerLeg_SET_06[2] = leftLowerLeg_ROTATE_FRAMEA[2];
               leftLowerLeg_SET_06[3] = leftLowerLeg_ROTATE_FRAMEA[3];
          }         
          if(setSelection_LEFT_LEG == 7)
          {
               leftLowerLeg_SET_07[0] = leftLowerLeg_ROTATE_FRAMEA[0];
               leftLowerLeg_SET_07[1] = leftLowerLeg_ROTATE_FRAMEA[1];                   
               leftLowerLeg_SET_07[2] = leftLowerLeg_ROTATE_FRAMEA[2];
               leftLowerLeg_SET_07[3] = leftLowerLeg_ROTATE_FRAMEA[3];
          }           
          //oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo      
          if(setSelection_LEFT_LEG == 1)
          {
               leftFoot_SET_01[0] = leftFoot_ROTATE_FRAMEA[0];
               leftFoot_SET_01[1] = leftFoot_ROTATE_FRAMEA[1];                   
               leftFoot_SET_01[2] = leftFoot_ROTATE_FRAMEA[2];
               leftFoot_SET_01[3] = leftFoot_ROTATE_FRAMEA[3];
          }
          if(setSelection_LEFT_LEG == 2)
          {
               leftFoot_SET_02[0] = leftFoot_ROTATE_FRAMEA[0];
               leftFoot_SET_02[1] = leftFoot_ROTATE_FRAMEA[1];                   
               leftFoot_SET_02[2] = leftFoot_ROTATE_FRAMEA[2];
               leftFoot_SET_02[3] = leftFoot_ROTATE_FRAMEA[3];
          }     
          if(setSelection_LEFT_LEG == 3)
          {
               leftFoot_SET_03[0] = leftFoot_ROTATE_FRAMEA[0];
               leftFoot_SET_03[1] = leftFoot_ROTATE_FRAMEA[1];                   
               leftFoot_SET_03[2] = leftFoot_ROTATE_FRAMEA[2];
               leftFoot_SET_03[3] = leftFoot_ROTATE_FRAMEA[3];
          }     
          if(setSelection_LEFT_LEG == 4)
          {
               leftFoot_SET_04[0] = leftFoot_ROTATE_FRAMEA[0];
               leftFoot_SET_04[1] = leftFoot_ROTATE_FRAMEA[1];                   
               leftFoot_SET_04[2] = leftFoot_ROTATE_FRAMEA[2];
               leftFoot_SET_04[3] = leftFoot_ROTATE_FRAMEA[3];
          }     
          if(setSelection_LEFT_LEG == 5)
          {
               leftFoot_SET_05[0] = leftFoot_ROTATE_FRAMEA[0];
               leftFoot_SET_05[1] = leftFoot_ROTATE_FRAMEA[1];                   
               leftFoot_SET_05[2] = leftFoot_ROTATE_FRAMEA[2];
               leftFoot_SET_05[3] = leftFoot_ROTATE_FRAMEA[3];
          }      
          if(setSelection_LEFT_LEG == 6)
          {
               leftFoot_SET_06[0] = leftFoot_ROTATE_FRAMEA[0];
               leftFoot_SET_06[1] = leftFoot_ROTATE_FRAMEA[1];                   
               leftFoot_SET_06[2] = leftFoot_ROTATE_FRAMEA[2];
               leftFoot_SET_06[3] = leftFoot_ROTATE_FRAMEA[3];
          }         
          if(setSelection_LEFT_LEG == 7)
          {
               leftFoot_SET_07[0] = leftFoot_ROTATE_FRAMEA[0];
               leftFoot_SET_07[1] = leftFoot_ROTATE_FRAMEA[1];                   
               leftFoot_SET_07[2] = leftFoot_ROTATE_FRAMEA[2];
               leftFoot_SET_07[3] = leftFoot_ROTATE_FRAMEA[3];
          }             
          //oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo    
    }    
        //----------------------------------------------------------------------------------------------------------------------------------        
     if(rightUpperLeg_AnimationSequence)
     {          
       
        if(animationBlendFactor_RIGHT_LEG >= 0.0f && animationBlendFactor_RIGHT_LEG <= 1.0f)
        {     
            rightUpperLeg_ROTATE[3]   = rightUpperLeg_ROTATE_FRAMEA[3] * (1 - animationBlendFactor_RIGHT_LEG) 
                                      + rightUpperLeg_ROTATE_FRAMEB[3] * animationBlendFactor_RIGHT_LEG;        
        
            rightUpperLeg_ROTATE[0]   = rightUpperLeg_ROTATE_FRAMEA[0]   * (1 - animationBlendFactor_RIGHT_LEG) 
                                      + rightUpperLeg_ROTATE_FRAMEB[0]   * animationBlendFactor_RIGHT_LEG; 
        
            rightUpperLeg_ROTATE[1]   = rightUpperLeg_ROTATE_FRAMEA[1]   * (1 - animationBlendFactor_RIGHT_LEG) 
                                      + rightUpperLeg_ROTATE_FRAMEB[1]   * animationBlendFactor_RIGHT_LEG;
        
            rightUpperLeg_ROTATE[2]   = rightUpperLeg_ROTATE_FRAMEA[2]   * (1 - animationBlendFactor_RIGHT_LEG) 
                                      + rightUpperLeg_ROTATE_FRAMEB[2]   * animationBlendFactor_RIGHT_LEG;
                                  
            rightLowerLeg_ROTATE[3]   = rightLowerLeg_ROTATE_FRAMEA[3]   * (1 - animationBlendFactor_RIGHT_LEG) 
                                      + rightLowerLeg_ROTATE_FRAMEB[3]   * animationBlendFactor_RIGHT_LEG;        
        
            rightLowerLeg_ROTATE[0]   = rightLowerLeg_ROTATE_FRAMEA[0]   * (1 - animationBlendFactor_RIGHT_LEG) 
                                      + rightLowerLeg_ROTATE_FRAMEB[0]   * animationBlendFactor_RIGHT_LEG; 
        
            rightLowerLeg_ROTATE[1]   = rightLowerLeg_ROTATE_FRAMEA[1]   * (1 - animationBlendFactor_RIGHT_LEG) 
                                      + rightLowerLeg_ROTATE_FRAMEB[1]   * animationBlendFactor_RIGHT_LEG;
        
            rightLowerLeg_ROTATE[2]   = rightLowerLeg_ROTATE_FRAMEA[2]   * (1 - animationBlendFactor_RIGHT_LEG) 
                                      + rightLowerLeg_ROTATE_FRAMEB[2]   * animationBlendFactor_RIGHT_LEG;                                          
                                  
            rightFoot_ROTATE[3]       = rightFoot_ROTATE_FRAMEA[3]       * (1 - animationBlendFactor_RIGHT_LEG) 
                                      + rightFoot_ROTATE_FRAMEB[3]       * animationBlendFactor_RIGHT_LEG;        
        
            rightFoot_ROTATE[0]       = rightFoot_ROTATE_FRAMEA[0]       * (1 - animationBlendFactor_RIGHT_LEG) 
                                      + rightFoot_ROTATE_FRAMEB[0]       * animationBlendFactor_RIGHT_LEG; 
        
            rightFoot_ROTATE[1]       = rightFoot_ROTATE_FRAMEA[1]       * (1 - animationBlendFactor_RIGHT_LEG) 
                                      + rightFoot_ROTATE_FRAMEB[1]       * animationBlendFactor_RIGHT_LEG;
        
            rightFoot_ROTATE[2]       = rightFoot_ROTATE_FRAMEA[2]       * (1 - animationBlendFactor_RIGHT_LEG) 
                                      + rightFoot_ROTATE_FRAMEB[2]       * animationBlendFactor_RIGHT_LEG; 
        }
        if(animationBlendFactor_RIGHT_LEG >= 1.0f)
        {
            setSelection_RIGHT_LEG ++;
            animationBlendFactor_RIGHT_LEG = 0.0f;
        }
        if(setSelection_RIGHT_LEG == setSelectionLimit_RIGHT_LEG + 1)
        {
            setSelection_RIGHT_LEG = 0;
            rightUpperLeg_AnimationSequence = false;
        }
        animationBlendFactor_RIGHT_LEG       +=  rightLeg_ROTATION_FRAME_TIME[setSelectionLimit_RIGHT_LEG - 1];  
          //oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
          if(setSelection_RIGHT_LEG == 1)
          {
               rightUpperLeg_SET_01[0] = rightUpperLeg_ROTATE_FRAMEA[0];
               rightUpperLeg_SET_01[1] = rightUpperLeg_ROTATE_FRAMEA[1];                   
               rightUpperLeg_SET_01[2] = rightUpperLeg_ROTATE_FRAMEA[2];
               rightUpperLeg_SET_01[3] = rightUpperLeg_ROTATE_FRAMEA[3];
          }
          if(setSelection_RIGHT_LEG == 2)
          {
               rightUpperLeg_SET_02[0] = rightUpperLeg_ROTATE_FRAMEA[0];
               rightUpperLeg_SET_02[1] = rightUpperLeg_ROTATE_FRAMEA[1];                   
               rightUpperLeg_SET_02[2] = rightUpperLeg_ROTATE_FRAMEA[2];
               rightUpperLeg_SET_02[3] = rightUpperLeg_ROTATE_FRAMEA[3];
          }     
          if(setSelection_RIGHT_LEG == 3)
          {
               rightUpperLeg_SET_03[0] = rightUpperLeg_ROTATE_FRAMEA[0];
               rightUpperLeg_SET_03[1] = rightUpperLeg_ROTATE_FRAMEA[1];                   
               rightUpperLeg_SET_03[2] = rightUpperLeg_ROTATE_FRAMEA[2];
               rightUpperLeg_SET_03[3] = rightUpperLeg_ROTATE_FRAMEA[3];
          }     
          if(setSelection_RIGHT_LEG == 4)
          {
               rightUpperLeg_SET_04[0] = rightUpperLeg_ROTATE_FRAMEA[0];
               rightUpperLeg_SET_04[1] = rightUpperLeg_ROTATE_FRAMEA[1];                   
               rightUpperLeg_SET_04[2] = rightUpperLeg_ROTATE_FRAMEA[2];
               rightUpperLeg_SET_04[3] = rightUpperLeg_ROTATE_FRAMEA[3];
          }     
          if(setSelection_RIGHT_LEG == 5)
          {
               rightUpperLeg_SET_05[0] = rightUpperLeg_ROTATE_FRAMEA[0];
               rightUpperLeg_SET_05[1] = rightUpperLeg_ROTATE_FRAMEA[1];                   
               rightUpperLeg_SET_05[2] = rightUpperLeg_ROTATE_FRAMEA[2];
               rightUpperLeg_SET_05[3] = rightUpperLeg_ROTATE_FRAMEA[3];
          }      
          if(setSelection_RIGHT_LEG == 6)
          {
               rightUpperLeg_SET_06[0] = rightUpperLeg_ROTATE_FRAMEA[0];
               rightUpperLeg_SET_06[1] = rightUpperLeg_ROTATE_FRAMEA[1];                   
               rightUpperLeg_SET_06[2] = rightUpperLeg_ROTATE_FRAMEA[2];
               rightUpperLeg_SET_06[3] = rightUpperLeg_ROTATE_FRAMEA[3];
          }         
          if(setSelection_RIGHT_LEG == 7)
          {
               rightUpperLeg_SET_07[0] = rightUpperLeg_ROTATE_FRAMEA[0];
               rightUpperLeg_SET_07[1] = rightUpperLeg_ROTATE_FRAMEA[1];                   
               rightUpperLeg_SET_07[2] = rightUpperLeg_ROTATE_FRAMEA[2];
               rightUpperLeg_SET_07[3] = rightUpperLeg_ROTATE_FRAMEA[3];
          }          
          //oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo      
          if(setSelection_RIGHT_LEG == 1)
          {
               rightLowerLeg_SET_01[0] = rightLowerLeg_ROTATE_FRAMEA[0];
               rightLowerLeg_SET_01[1] = rightLowerLeg_ROTATE_FRAMEA[1];                   
               rightLowerLeg_SET_01[2] = rightLowerLeg_ROTATE_FRAMEA[2];
               rightLowerLeg_SET_01[3] = rightLowerLeg_ROTATE_FRAMEA[3];
          }
          if(setSelection_RIGHT_LEG == 2)
          {
               rightLowerLeg_SET_02[0] = rightLowerLeg_ROTATE_FRAMEA[0];
               rightLowerLeg_SET_02[1] = rightLowerLeg_ROTATE_FRAMEA[1];                   
               rightLowerLeg_SET_02[2] = rightLowerLeg_ROTATE_FRAMEA[2];
               rightLowerLeg_SET_02[3] = rightLowerLeg_ROTATE_FRAMEA[3];
          }     
          if(setSelection_RIGHT_LEG == 3)
          {
               rightLowerLeg_SET_03[0] = rightLowerLeg_ROTATE_FRAMEA[0];
               rightLowerLeg_SET_03[1] = rightLowerLeg_ROTATE_FRAMEA[1];                   
               rightLowerLeg_SET_03[2] = rightLowerLeg_ROTATE_FRAMEA[2];
               rightLowerLeg_SET_03[3] = rightLowerLeg_ROTATE_FRAMEA[3];
          }     
          if(setSelection_RIGHT_LEG == 4)
          {
               rightLowerLeg_SET_04[0] = rightLowerLeg_ROTATE_FRAMEA[0];
               rightLowerLeg_SET_04[1] = rightLowerLeg_ROTATE_FRAMEA[1];                   
               rightLowerLeg_SET_04[2] = rightLowerLeg_ROTATE_FRAMEA[2];
               rightLowerLeg_SET_04[3] = rightLowerLeg_ROTATE_FRAMEA[3];
          }     
          if(setSelection_RIGHT_LEG == 5)
          {
               rightLowerLeg_SET_05[0] = rightLowerLeg_ROTATE_FRAMEA[0];
               rightLowerLeg_SET_05[1] = rightLowerLeg_ROTATE_FRAMEA[1];                   
               rightLowerLeg_SET_05[2] = rightLowerLeg_ROTATE_FRAMEA[2];
               rightLowerLeg_SET_05[3] = rightLowerLeg_ROTATE_FRAMEA[3];
          }      
          if(setSelection_RIGHT_LEG == 6)
          {
               rightLowerLeg_SET_06[0] = rightLowerLeg_ROTATE_FRAMEA[0];
               rightLowerLeg_SET_06[1] = rightLowerLeg_ROTATE_FRAMEA[1];                   
               rightLowerLeg_SET_06[2] = rightLowerLeg_ROTATE_FRAMEA[2];
               rightLowerLeg_SET_06[3] = rightLowerLeg_ROTATE_FRAMEA[3];
          }         
          if(setSelection_RIGHT_LEG == 7)
          {
               rightLowerLeg_SET_07[0] = rightLowerLeg_ROTATE_FRAMEA[0];
               rightLowerLeg_SET_07[1] = rightLowerLeg_ROTATE_FRAMEA[1];                   
               rightLowerLeg_SET_07[2] = rightLowerLeg_ROTATE_FRAMEA[2];
               rightLowerLeg_SET_07[3] = rightLowerLeg_ROTATE_FRAMEA[3];
          }           
          //oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo      
          if(setSelection_RIGHT_LEG == 1)
          {
               rightFoot_SET_01[0] = rightFoot_ROTATE_FRAMEA[0];
               rightFoot_SET_01[1] = rightFoot_ROTATE_FRAMEA[1];                   
               rightFoot_SET_01[2] = rightFoot_ROTATE_FRAMEA[2];
               rightFoot_SET_01[3] = rightFoot_ROTATE_FRAMEA[3];
          }
          if(setSelection_RIGHT_LEG == 2)
          {
               rightFoot_SET_02[0] = rightFoot_ROTATE_FRAMEA[0];
               rightFoot_SET_02[1] = rightFoot_ROTATE_FRAMEA[1];                   
               rightFoot_SET_02[2] = rightFoot_ROTATE_FRAMEA[2];
               rightFoot_SET_02[3] = rightFoot_ROTATE_FRAMEA[3];
          }     
          if(setSelection_RIGHT_LEG == 3)
          {
               rightFoot_SET_03[0] = rightFoot_ROTATE_FRAMEA[0];
               rightFoot_SET_03[1] = rightFoot_ROTATE_FRAMEA[1];                   
               rightFoot_SET_03[2] = rightFoot_ROTATE_FRAMEA[2];
               rightFoot_SET_03[3] = rightFoot_ROTATE_FRAMEA[3];
          }     
          if(setSelection_RIGHT_LEG == 4)
          {
               rightFoot_SET_04[0] = rightFoot_ROTATE_FRAMEA[0];
               rightFoot_SET_04[1] = rightFoot_ROTATE_FRAMEA[1];                   
               rightFoot_SET_04[2] = rightFoot_ROTATE_FRAMEA[2];
               rightFoot_SET_04[3] = rightFoot_ROTATE_FRAMEA[3];
          }     
          if(setSelection_RIGHT_LEG == 5)
          {
               rightFoot_SET_05[0] = rightFoot_ROTATE_FRAMEA[0];
               rightFoot_SET_05[1] = rightFoot_ROTATE_FRAMEA[1];                   
               rightFoot_SET_05[2] = rightFoot_ROTATE_FRAMEA[2];
               rightFoot_SET_05[3] = rightFoot_ROTATE_FRAMEA[3];
          }      
          if(setSelection_RIGHT_LEG == 6)
          {
               rightFoot_SET_06[0] = rightFoot_ROTATE_FRAMEA[0];
               rightFoot_SET_06[1] = rightFoot_ROTATE_FRAMEA[1];                   
               rightFoot_SET_06[2] = rightFoot_ROTATE_FRAMEA[2];
               rightFoot_SET_06[3] = rightFoot_ROTATE_FRAMEA[3];
          }         
          if(setSelection_RIGHT_LEG == 7)
          {
               rightFoot_SET_07[0] = rightFoot_ROTATE_FRAMEA[0];
               rightFoot_SET_07[1] = rightFoot_ROTATE_FRAMEA[1];                   
               rightFoot_SET_07[2] = rightFoot_ROTATE_FRAMEA[2];
               rightFoot_SET_07[3] = rightFoot_ROTATE_FRAMEA[3];
          }          
          //oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo    
    }





     if(loadSet_01)
     {
         #include "animationFiles/loadSet_01.c"   
     }
     if(loadSet_02)
     {
         #include "animationFiles/loadSet_02.c"   
     }
     if(loadSet_03)
     {
         #include "animationFiles/loadSet_03.c"   
     }     
     if(loadSet_04)
     {
         #include "animationFiles/loadSet_04.c"   
     } 
     if(loadSet_05)
     {
         #include "animationFiles/loadSet_05.c"   
     }
     if(loadSet_06)
     {
         #include "animationFiles/loadSet_06.c"   
     }     
     if(loadSet_07)
     {
         #include "animationFiles/loadSet_07.c"   
     }           
///////___________############################################################################
///////___________############################################################################
///////___________############################################################################
///////___________############################################################################
///////___________############################################################################
///////___________############################################################################               




/*

if(showMarc)
{
   if(marcJumping)//--->>ME_animationSequencing.cpp
   {
       if(resetAnimation)
       {
           hips_POSITION_setSelection         = 1;
           setSelection_LEFT_ARM                 = 1;
           setSelection_RIGHT_ARM                = 1;
           setSelection_LEFT_LEG                 = 1;
           setSelection_RIGHT_LEG                = 1;                                    
           setSelection_HEAD                     = 1;
           setSelection_TORSO                    = 1;
           setSelection_HIPS                     = 1;
                                    
           resetAnimation = false;
       }
      
       #include "_MODEL_FOLDERS_/marcParts/marcAnimations/animationFiles/ME_Animation_JUMP.cpp"
       #include "_MODEL_FOLDERS_/marcParts/marcAnimations/animationFiles/ME_animationSequencing.cpp"
       marcWalking = false;
   }
   if(marcWalking)
   {
       if(resetAnimation)
       {
           hips_POSITION_setSelection         = 1;
           setSelection_LEFT_ARM                 = 1;
           setSelection_RIGHT_ARM                = 1;
           setSelection_LEFT_LEG                 = 1;
           setSelection_RIGHT_LEG                = 1;                                    
           setSelection_HEAD                     = 1;
           setSelection_TORSO                    = 1;
           setSelection_HIPS                     = 1;
                                    
           resetAnimation = false;
       }
       #include "_MODEL_FOLDERS_/marcParts/marcAnimations/animationFiles/ME_AnimationSet.cpp"
       #include "_MODEL_FOLDERS_/marcParts/marcAnimations/animationFiles/ME_animationSequencing.cpp" 
   }

} 
*/
//------------------------------------------------------------------------------- --------------------------------------------------------   
                            
//==========================================================================================================================================================
//==========================================================================================================================================================
//==========================================================================================================================================================                              
///////////////________FRAMEBUFFER_SHADOWS_BEGINS_HERE________________FRAMEBUFFER_SHADOWS_BEGINS_HERE________________FRAMEBUFFER_SHADOWS_BEGINS_HERE________
///////////////________FRAMEBUFFER_SHADOWS_BEGINS_HERE________________FRAMEBUFFER_SHADOWS_BEGINS_HERE________________FRAMEBUFFER_SHADOWS_BEGINS_HERE________
///////////////________FRAMEBUFFER_SHADOWS_BEGINS_HERE________________FRAMEBUFFER_SHADOWS_BEGINS_HERE________________FRAMEBUFFER_SHADOWS_BEGINS_HERE________
///////////////________FRAMEBUFFER_SHADOWS_BEGINS_HERE________________FRAMEBUFFER_SHADOWS_BEGINS_HERE________________FRAMEBUFFER_SHADOWS_BEGINS_HERE________
///////////////________FRAMEBUFFER_SHADOWS_BEGINS_HERE________________FRAMEBUFFER_SHADOWS_BEGINS_HERE________________FRAMEBUFFER_SHADOWS_BEGINS_HERE________
///////////////________FRAMEBUFFER_SHADOWS_BEGINS_HERE________________FRAMEBUFFER_SHADOWS_BEGINS_HERE________________FRAMEBUFFER_SHADOWS_BEGINS_HERE________
///////////////________FRAMEBUFFER_SHADOWS_BEGINS_HERE________________FRAMEBUFFER_SHADOWS_BEGINS_HERE________________FRAMEBUFFER_SHADOWS_BEGINS_HERE________
///////////////________FRAMEBUFFER_SHADOWS_BEGINS_HERE________________FRAMEBUFFER_SHADOWS_BEGINS_HERE________________FRAMEBUFFER_SHADOWS_BEGINS_HERE________
///////////////________FRAMEBUFFER_SHADOWS_BEGINS_HERE________________FRAMEBUFFER_SHADOWS_BEGINS_HERE________________FRAMEBUFFER_SHADOWS_BEGINS_HERE________
///////////////________FRAMEBUFFER_SHADOWS_BEGINS_HERE________________FRAMEBUFFER_SHADOWS_BEGINS_HERE________________FRAMEBUFFER_SHADOWS_BEGINS_HERE________
///////////////________FRAMEBUFFER_SHADOWS_BEGINS_HERE________________FRAMEBUFFER_SHADOWS_BEGINS_HERE________________FRAMEBUFFER_SHADOWS_BEGINS_HERE________
///////////////________FRAMEBUFFER_SHADOWS_BEGINS_HERE________________FRAMEBUFFER_SHADOWS_BEGINS_HERE________________FRAMEBUFFER_SHADOWS_BEGINS_HERE________                              
//==========================================================================================================================================================
//==========================================================================================================================================================
//==========================================================================================================================================================                              
/*  
 
                              glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, fboId);
                              glFramebufferRenderbufferEXT(GL_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT_EXT, GL_RENDERBUFFER_EXT, rboId);

                              glViewport(0, 0, TEXTURE_WIDTH, TEXTURE_HEIGHT);
                              glMatrixMode(GL_PROJECTION);
                              glLoadIdentity();
                              
                              gluPerspective(0.0f, (float)(TEXTURE_WIDTH) / TEXTURE_HEIGHT, 1.0f, 1000.0f);
                          
                              glMatrixMode(GL_MODELVIEW);
                              
                              glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                                       
                              glClearColor(0.2, 0.2, 0.2, 0.0);
                              glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );  
        
        glDisable(GL_BLEND);
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_DEPTH_TEST);          
        glEnable(GL_CULL_FACE);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                          //-----------------------------
                                                  glLoadIdentity();
                                          //-----------------------------
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

 
                  glColor4f(1.0, 1.0, 1.0, 1.0); 
          
             glUseProgramObjectARB(marcDisplay_4view_SHADER);
             
             glLightfv(GL_LIGHT0,GL_POSITION, lightPos_4view);
             glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_4view);
            
          
             glTranslatef(moveAllFour[0], moveAllFour[1], moveAllFour[2]);
             glTranslatef(marc_TOP_VIEW[0], marc_TOP_VIEW[1], marc_TOP_VIEW[2]);
             glRotatef(-90, 1, 0, 0); 
             glScalef(scale_marc_VBO_Shadow_01, scale_marc_VBO_Shadow_01, scale_marc_VBO_Shadow_01);
             //glTranslatef(-hips_POSITION[0], -hips_POSITION[1], -hips_POSITION[2]);
             glRotatef(marcRotation, 0, 1, 0);           
             
             #include "displayMarcModelShadows_01.cpp"  
             
              
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                          //-----------------------------
                                                  glLoadIdentity();
                                          //-----------------------------
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      
             
          
             glTranslatef(moveAllFour[0], moveAllFour[1], moveAllFour[2]);
             glTranslatef(marc_PERSPECTIVE_VIEW[0], marc_PERSPECTIVE_VIEW[1], marc_PERSPECTIVE_VIEW[2]);
             glRotatef(-45, 0, 1, 0); 
             //glRotatef( 20, 1, 0, 0);  
             glScalef(scale_marc_VBO_Shadow_01, scale_marc_VBO_Shadow_01, scale_marc_VBO_Shadow_01);
             //glTranslatef(-hips_POSITION[0], -hips_POSITION[1], -hips_POSITION[2]);
             glRotatef(marcRotation, 0, 1, 0); 
               
             #include "displayMarcModelShadows_01.cpp"                

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                          //-----------------------------
                                                  glLoadIdentity();
                                          //-----------------------------
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            
            
          
             glTranslatef(moveAllFour[0], moveAllFour[1], moveAllFour[2]);
             glTranslatef(marc_FRONT_VIEW[0], marc_FRONT_VIEW[1], marc_FRONT_VIEW[2]);
             //glRotatef(marc_VBO_ShadowsRotationUP_DOWN_01, 1, 0, 0); 
             //glRotatef(marc_VBO_ShadowsRotationLEFT_RIGHT_01, 0, 0, 1);  
             glScalef(scale_marc_VBO_Shadow_01, scale_marc_VBO_Shadow_01, scale_marc_VBO_Shadow_01);
             //glTranslatef(-hips_POSITION[0], -hips_POSITION[1], -hips_POSITION[2]);
             glRotatef(marcRotation, 0, 1, 0);           
             
             #include "displayMarcModelShadows_01.cpp"  
             
              
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                          //-----------------------------
                                                  glLoadIdentity();
                                          //-----------------------------
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      
             
           
             glTranslatef(moveAllFour[0], moveAllFour[1], moveAllFour[2]);
             glTranslatef(marc_SIDE_VIEW[0], marc_SIDE_VIEW[1], marc_SIDE_VIEW[2]);
             glRotatef(-90, 0, 1, 0); 
             //glRotatef(marc_VBO_ShadowsRotationLEFT_RIGHT_00, 0, 0, 1);  
             glScalef(scale_marc_VBO_Shadow_01, scale_marc_VBO_Shadow_01, scale_marc_VBO_Shadow_01);
             //glTranslatef(-hips_POSITION[0], -hips_POSITION[1], -hips_POSITION[2]);
             glRotatef(marcRotation, 0, 1, 0); 
               
             #include "displayMarcModelShadows_01.cpp"                

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                          //-----------------------------
                                                  glLoadIdentity();
                                          //-----------------------------
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////







        glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0); //-----------------------F.B.O.

        glColor4f(1.0, 1.0, 1.0, 1.0); 

*/

//==========================================================================================================================================================
//==========================================================================================================================================================
//==========================================================================================================================================================                              
///////////////________FRAMEBUFFER_SHADOWS_ENDS_HERE________________FRAMEBUFFER_SHADOWS_ENDS_HERE________________FRAMEBUFFER_SHADOWS_ENDS_HERE________
///////////////________FRAMEBUFFER_SHADOWS_ENDS_HERE________________FRAMEBUFFER_SHADOWS_ENDS_HERE________________FRAMEBUFFER_SHADOWS_ENDS_HERE________
///////////////________FRAMEBUFFER_SHADOWS_ENDS_HERE________________FRAMEBUFFER_SHADOWS_ENDS_HERE________________FRAMEBUFFER_SHADOWS_ENDS_HERE________
///////////////________FRAMEBUFFER_SHADOWS_ENDS_HERE________________FRAMEBUFFER_SHADOWS_ENDS_HERE________________FRAMEBUFFER_SHADOWS_ENDS_HERE________
///////////////________FRAMEBUFFER_SHADOWS_ENDS_HERE________________FRAMEBUFFER_SHADOWS_ENDS_HERE________________FRAMEBUFFER_SHADOWS_ENDS_HERE________
///////////////________FRAMEBUFFER_SHADOWS_ENDS_HERE________________FRAMEBUFFER_SHADOWS_ENDS_HERE________________FRAMEBUFFER_SHADOWS_ENDS_HERE________
///////////////________FRAMEBUFFER_SHADOWS_ENDS_HERE________________FRAMEBUFFER_SHADOWS_ENDS_HERE________________FRAMEBUFFER_SHADOWS_ENDS_HERE________
///////////////________FRAMEBUFFER_SHADOWS_ENDS_HERE________________FRAMEBUFFER_SHADOWS_ENDS_HERE________________FRAMEBUFFER_SHADOWS_ENDS_HERE________
///////////////________FRAMEBUFFER_SHADOWS_ENDS_HERE________________FRAMEBUFFER_SHADOWS_ENDS_HERE________________FRAMEBUFFER_SHADOWS_ENDS_HERE________
///////////////________FRAMEBUFFER_SHADOWS_ENDS_HERE________________FRAMEBUFFER_SHADOWS_ENDS_HERE________________FRAMEBUFFER_SHADOWS_ENDS_HERE________
///////////////________FRAMEBUFFER_SHADOWS_ENDS_HERE________________FRAMEBUFFER_SHADOWS_ENDS_HERE________________FRAMEBUFFER_SHADOWS_ENDS_HERE________
///////////////________FRAMEBUFFER_SHADOWS_ENDS_HERE________________FRAMEBUFFER_SHADOWS_ENDS_HERE________________FRAMEBUFFER_SHADOWS_ENDS_HERE________                              
//==========================================================================================================================================================
//==========================================================================================================================================================
//==========================================================================================================================================================                                
                        /*     
                              glViewport(0, 0, TEXTURE_WIDTH, TEXTURE_HEIGHT);
                              glMatrixMode(GL_PROJECTION);
                              glLoadIdentity();
                              
                              gluPerspective(45.0f, (float)(TEXTURE_WIDTH) / TEXTURE_HEIGHT, 1.0f, 1000.0f);
                          
                              glMatrixMode(GL_MODELVIEW);
 
                              glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, gaussianBlurHorizontalPass_fboId);//-----F.B.O.__HORIZONTAL_BLUR

                              glClearColor(1, 1, 1, 0);
                              glClear (GL_COLOR_BUFFER_BIT);                

                              
                              
                              //------------------------------------------------------------------------------------------------------------------------
                              
                              #include "_MODEL_FOLDERS_/gaussianBlur/gaussianBlurHorizontalPass/gaussianBlurHorizontalPass_vboRender.cpp"   //vboID = 1
                              
                              //------------------------------------------------------------------------------------------------------------------------
                              
                              
                              glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);    //--------------------------------F.B.O.__HORIZONTAL_BLUR             
//==========================================================================================================================================================
//==========================================================================================================================================================
//==========================================================================================================================================================                               
                              
                              glViewport(0, 0, TEXTURE_WIDTH, TEXTURE_HEIGHT);
                              glMatrixMode(GL_PROJECTION);
                              glLoadIdentity();
                              
                              gluPerspective(45.0f, (float)(TEXTURE_WIDTH) / TEXTURE_HEIGHT, 1.0f, 1000.0f);
                          
                              glMatrixMode(GL_MODELVIEW);
 
                              glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, gaussianBlurVerticalPass_fboId);//-----F.B.O.__VERTICAL_BLUR

                              glClearColor(1, 1, 1, 0);
                              glClear (GL_COLOR_BUFFER_BIT);                
             
                              //------------------------------------------------------------------------------------------------------------------------
                              
                              #include "_MODEL_FOLDERS_/gaussianBlur/gaussianBlurVerticalPass/gaussianBlurVerticalPass_vboRender.cpp"   //vboID = 1
                              
                              //------------------------------------------------------------------------------------------------------------------------                              
                              
                              glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);    //--------------------------------F.B.O.__VERTICAL_BLUR             

*/
//==========================================================================================================================================================
//==========================================================================================================================================================
//==========================================================================================================================================================                               
//==========================================================================================================================================================
//==========================================================================================================================================================
//==========================================================================================================================================================                                
//==========================================================================================================================================================
//==========================================================================================================================================================
//==========================================================================================================================================================                                
//==========================================================================================================================================================
//==========================================================================================================================================================
//==========================================================================================================================================================                              
                              
                              
                              
                              
                              
                              
                              
                              
                              
                              glClearColor(0.0, 0.0, 0.0, 0.5);
                              glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT); 
    
                              glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
                              glEnable(GL_LINE_SMOOTH);
                              glViewport(0, 0, GLint(screenWidth), GLint(screenHeight));
                              glMatrixMode(GL_PROJECTION );
                              glLoadIdentity();
                              gluPerspective(45.24, screenWidth / screenHeight, 0.1, 1000);
                              
                              glTranslatef(eyePosition[0], eyePosition[1], eyePosition[2]);
                              glRotatef(look_UP_DOWN, 1, 0, 0); 
                              glRotatef(look_LEFT_RIGHT, 0, 1, 0);
                              
                              glMatrixMode(GL_MODELVIEW);
                                                               
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                          //-----------------------------
                                                  glLoadIdentity();
                                          //-----------------------------
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////  

              glEnable(GL_TEXTURE_2D);
              glEnable(GL_DEPTH_TEST);
        
//-------------------------------------------------------------------------------------------------------------------------------------------------------
                  //---------------------------------------------------------------------------------------------------------_FLOOR_TILES
                  //---------------------------------------------------------------------------------------------------------_FLOOR_TILES          
          
         
if(hideSetPlusDialoque == 0.0)   
{//______________________________________________BEGIN_HIDE_SET_DIALOGUE---
         
    LoadPerspective(projection, 45, screenWidth / screenHeight, 0.1, 10000);

//====================================================================================                                          
//#include "_MODEL_FOLDERS_/iconPlates_x4/iconPlates_x4_Render.cpp"                                                                 
//====================================================================================                                          


            
          
          
          
          
                  //---------------------------------------------------------------------------------------------------------_FLOOR_TILES
//---------------------------------------------------------------------------------------------------------------------------_FLOOR_TILES
//-------------------------------------------------------------------------------------------------------------------------------------------------------       


                                                       glDisable(GL_BLEND);

//================================================================================================================
                                          //===============================
                                                  glLoadIdentity();
                                          //===============================
//================================================================================================================
       
       
       
             //---------------------------------------
             lightPos_marcTorso[0]   =    12.913;
             lightPos_marcTorso[1]   =   100.0;      
             lightPos_marcTorso[2]   =  -149.049;  
             //---------------------------------------
     
     glEnable(GL_TEXTURE_2D);            
                                
glPushMatrix();  
   glTranslatef(marcModelPosition[0], marcModelPosition[1], marcModelPosition[2]);
   glRotatef(marcRotation, 0.0, 1.0, 0.0);            
  
        glTranslatef(hips_POSITION[0],     hips_POSITION[1],     hips_POSITION[2]);
        glRotatef(   hips_ROTATE[3], hips_ROTATE[0], hips_ROTATE[1], hips_ROTATE[2]);   

                         
                            glPushMatrix();
                                 glLoadIdentity();
                                 glRotatef(-hips_ROTATE[3], -hips_ROTATE[0], -hips_ROTATE[1], hips_ROTATE[2]);                                  
                                 glRotatef(marcRotation, 0.0, 1.0, 0.0); 
                                 glRotatef(-look_LEFT_RIGHT, 0.0, -1.0, 0.0);
                                 glTranslatef(-eyePosition[0],-eyePosition[1],-eyePosition[2]);
                                 glLightfv(GL_LIGHT0,GL_POSITION,lightPos_marcTorso);
                                 glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_marcTorso);
                            glPopMatrix();
                            //-------------------------------------------------------------------------------------------
                            if(BODY_PART_SELECTION == 5)
                            { 
                                   MaterialDiffuse_marcTorso[0] = 2.0;
                                   rotationInfoTransparency     = 1.0;
                            }
                            else                 
                            {
                                   MaterialDiffuse_marcTorso[0] = 1.0;
                                   rotationInfoTransparency     = 0.2;
                            
                            }                
                            //-------------------------------------------------------------------------------------------
                            
                            
                            #include "_MODEL_FOLDERS_/marcParts/marcHips/marcHips_vboRender.cpp" //_________________________________ALL_WOOD_SHADERS_ARE_LINKED_TO_THE_TORSO_SHADER 
                        
                                              /////--------------------------------___HUD_START___-----------------------------------                       
                                        if(hideSetPlusDialoque == 0.0)   
                                        {//------------------------------------------BEGIN_HIDE_SET_DIALOGUE-------                                              
                                              glPushMatrix(); 
                                                        glTranslatef(hipsRotationDisplayValues[0], hipsRotationDisplayValues[1], hipsRotationDisplayValues[2]); 
                                                        glRotatef(180, 0.0, 1.0, 0.0);
                                                        glDisable(GL_TEXTURE_2D);
                                                        glDisable(GL_CULL_FACE);
                                                        glColor4f(1.0f,1.0f,1.0f,rotationInfoTransparency);
                                                        glScalef(.4,.4,.4);
                                                        glEnable(GL_BLEND);
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, 0.097, 0);
                                                             printDecimalNumbers(hips_ROTATE[3]);
                                                        glPopMatrix(); 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.071+.05, 0);
                                                             printDecimalNumbers(hips_ROTATE[0]);
                                                        glPopMatrix();                                 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.238+.10, 0);
                                                             printDecimalNumbers(hips_ROTATE[1]);
                                                        glPopMatrix();
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.410998+.15, 0);
                                                             printDecimalNumbers(hips_ROTATE[2]);
                                                        glPopMatrix();
                                                        glDisable(GL_BLEND);
                                                        glEnable(GL_CULL_FACE);
                                                        glEnable(GL_TEXTURE_2D);
                                               glPopMatrix();
                                         }//------------------------------------------END_HIDE_SET_DIALOGUE-------      
                                              /////--------------------------------___HUD_START___-----------------------------------     

                 /////////////+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++  
                 /////////////+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++  
                 /////////////+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++  
                 /////////////+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++                           
                             glPushMatrix(); 
                                       glTranslatef(torso_04[0], torso_04[1], torso_04[2]);
                                       glRotatef(torso_ROTATE[3], torso_ROTATE[0], torso_ROTATE[1], torso_ROTATE[2]);  
                            
                                          glPushMatrix();
                                              glLoadIdentity();
                                              //
                                              glRotatef(-torso_ROTATE[3], -torso_ROTATE[0], -torso_ROTATE[1], torso_ROTATE[2]);                                                
                                              glRotatef(-hips_ROTATE[3],  -hips_ROTATE[0],  -hips_ROTATE[1],  hips_ROTATE[2]);                                 
                                              glRotatef( marcRotation, 0, 1, 0); 
                                              glRotatef(-look_LEFT_RIGHT, 0, -1, 0);
                                              glTranslatef(-eyePosition[0],-eyePosition[1],-eyePosition[2]);
                                              glLightfv(GL_LIGHT0,GL_POSITION,lightPos_marcTorso);
                                              glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_marcTorso);
                                         glPopMatrix();          
                                         //-----------------------------------------------------------------------------------
                                               if(BODY_PART_SELECTION == 6)
                                               { 
                                                    MaterialDiffuse_marcTorso[0] = 2.0;
                                                    rotationInfoTransparency     = 1.0;
                                               }
                                               else                 
                                               {
                                                    MaterialDiffuse_marcTorso[0] = 1.0;
                                                    rotationInfoTransparency     = 0.2;
                                               }      
                                               #include "_MODEL_FOLDERS_/marcParts/marcTorso/marcTorso_vboRender.cpp"  //_________________________________ALL_WOOD_SHADERS_ARE_LINKED_TO_THE_TORSO_SHADER
                                              /////--------------------------------___HUD_START___-----------------------------------                       
                                              /////--------------------------------___HUD_START___-----------------------------------                       
                                              if(hideSetPlusDialoque == 0.0)   
                                              {//______________________________________________BEGIN_HIDE_SET_DIALOGUE____                                              
                                                   glPushMatrix(); 
                                                        glTranslatef(torsoRotationDisplayValues[0], torsoRotationDisplayValues[1], torsoRotationDisplayValues[2]); 
                                                        glRotatef(180, 0.0, 1.0, 0.0);
                                                        glDisable(GL_TEXTURE_2D);
                                                        glDisable(GL_CULL_FACE);
                                                        glColor4f(1.0f,1.0f,1.0f,rotationInfoTransparency);
                                                        glScalef(.4,.4,.4);
                                                        glEnable(GL_BLEND);
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, 0.097, 0);
                                                             printDecimalNumbers(torso_ROTATE[3]);
                                                        glPopMatrix(); 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.071+.05, 0);
                                                             printDecimalNumbers(torso_ROTATE[0]);
                                                        glPopMatrix();                                 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.238+.10, 0);
                                                             printDecimalNumbers(torso_ROTATE[1]);
                                                        glPopMatrix();
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.410998+.15, 0);
                                                             printDecimalNumbers(torso_ROTATE[2]);
                                                        glPopMatrix();
                                                        glEnable(GL_CULL_FACE);
                                                        glDisable(GL_BLEND);
                                                        glEnable(GL_TEXTURE_2D);
                                                   glPopMatrix();
                                              }
                       /////--------------------------------___HUD_FINISH___-----------------------------------                    
                 
                 /////////////+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++                                              
                 /////////////+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++  
                 /////////////+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++  
                 /////////////+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++                                              
                                            
                                            glPushMatrix();
                                                   glTranslatef(faceMarc_04[0], faceMarc_04[1], faceMarc_04[2]);
                                                   glRotatef(head_ROTATE[3], head_ROTATE[0], head_ROTATE[1], head_ROTATE[2]);         
                                                   glDisable(GL_BLEND);
                                                      
                                                      glPushMatrix();
                                                           glLoadIdentity();
                                                           //
                                                           glRotatef(-head_ROTATE[3],  -head_ROTATE[0],   -head_ROTATE[1],  head_ROTATE[2]);                                                            
                                                           glRotatef(-torso_ROTATE[3], -torso_ROTATE[0],  -torso_ROTATE[1], torso_ROTATE[2]);                                                           
                                                           glRotatef(-hips_ROTATE[3],  -hips_ROTATE[0],   -hips_ROTATE[1],  hips_ROTATE[2]);                                                           
                                                           glRotatef(marcRotation, 0, 1, 0); 
                                                           glRotatef(-look_LEFT_RIGHT, 0, -1, 0);
                                                           glTranslatef(-eyePosition[0],-eyePosition[1],-eyePosition[2]);                                                   
                                                           glLightfv (GL_LIGHT0,GL_POSITION, face_Marc_DOT3_light);
                                                           glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, quadraticAttenuationFace_Marc_DOT3);
                                                      glPopMatrix();                        
                                              
                                                     #include "_MODEL_FOLDERS_/marcParts/marcFace/marcFace_vboRender.cpp"  
                                                                                
                                                       glPushMatrix();
                                                            glLoadIdentity();
                                                            //
                                                            glRotatef(-head_ROTATE[3],  -head_ROTATE[0],  -head_ROTATE[1],  head_ROTATE[2]);                                                             
                                                            glRotatef(-torso_ROTATE[3], -torso_ROTATE[0], -torso_ROTATE[1], torso_ROTATE[2]);                                                            
                                                            glRotatef(-hips_ROTATE[3],  -hips_ROTATE[0],  -hips_ROTATE[1],  hips_ROTATE[2]);                                                            
                                                            glRotatef(marcRotation, 0, 1, 0); 
                                                            glRotatef(-look_LEFT_RIGHT, 0, -1, 0);
                                                            glTranslatef(-eyePosition[0],-eyePosition[1],-eyePosition[2]);                                              
                                                            glLightfv(GL_LIGHT0,GL_POSITION,lightPos_marcTorso);
                                                            glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_marcTorso);
                                                       glPopMatrix();                          
                                               if(BODY_PART_SELECTION == 7)
                                               { 
                                                    MaterialDiffuse_marcTorso[0] = 2.0;
                                                    rotationInfoTransparency     = 1.0;
                                               }
                                               else                 
                                               {
                                                    MaterialDiffuse_marcTorso[0] = 1.0;
                                                    rotationInfoTransparency     = 0.2;
                                               }    
                                              /////--------------------------------___HUD_START___-----------------------------------                       
                                              /////--------------------------------___HUD_START___-----------------------------------                       
                                              if(hideSetPlusDialoque == 0.0)   
                                              {//______________________________________________BEGIN_HIDE_SET_DIALOGUE____                                              
                                                    glPushMatrix(); 
                                                        glTranslatef(headRotationDisplayValues[0], headRotationDisplayValues[1], headRotationDisplayValues[2]); 
                                                        glRotatef(180, 0.0, 1.0, 0.0);
                                                        glDisable(GL_TEXTURE_2D);
                                                        glDisable(GL_CULL_FACE);
                                                        glColor4f(1.0f,1.0f,1.0f,rotationInfoTransparency);
                                                        glScalef(.4,.4,.4);
                                                        glEnable(GL_BLEND);
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, 0.097, 0);
                                                             printDecimalNumbers(head_ROTATE[3]);
                                                        glPopMatrix(); 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.071+.05, 0);
                                                             printDecimalNumbers(head_ROTATE[0]);
                                                        glPopMatrix();                                 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.238+.10, 0);
                                                             printDecimalNumbers(head_ROTATE[1]);
                                                        glPopMatrix();
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.410998+.15, 0);
                                                             printDecimalNumbers(head_ROTATE[2]);
                                                        glPopMatrix();
                                                        glEnable(GL_CULL_FACE);
                                                        glDisable(GL_BLEND);
                                                        glEnable(GL_TEXTURE_2D);
                                                    glPopMatrix();
                                               }//______________________________________________END_HIDE_SET_DIALOGUE____  
                                              /////--------------------------------___HUD_FINISH___-----------------------------------                                                        
                                                     #include "_MODEL_FOLDERS_/marcParts/marcHeadBack/marcHeadBack_vboRender.cpp" //_________________________________ALL_WOOD_SHADERS_ARE_LINKED_TO_THE_TORSO_SHADER
                                            
                                            glPopMatrix();
                              glPopMatrix();        
                            
                              
                              
////////////_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO
////////////_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO
////////////_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM
////////////_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM
////////////_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM
glPushMatrix();
      
    glTranslatef(torso_04[0], torso_04[1], torso_04[2]);
    glRotatef(torso_ROTATE[3], torso_ROTATE[0], torso_ROTATE[1], torso_ROTATE[2]);   
        
        glPushMatrix(); 
            glTranslatef(leftUpperArm_POSITION[0], leftUpperArm_POSITION[1], leftUpperArm_POSITION[2]);           
            glRotatef(leftUpperArm_ROTATE[3], leftUpperArm_ROTATE[0], leftUpperArm_ROTATE[1], leftUpperArm_ROTATE[2]);        
                            
                            glPushMatrix();
                                 glLoadIdentity();
                                 glRotatef(-leftUpperArm_ROTATE[3],  -leftUpperArm_ROTATE[0], -leftUpperArm_ROTATE[1], leftUpperArm_ROTATE[2]);                                 
                                 glRotatef(-torso_ROTATE[3],         -torso_ROTATE[0],        -torso_ROTATE[1],        torso_ROTATE[2]);                                 
                                 glRotatef(-hips_ROTATE[3],          -hips_ROTATE[0],         -hips_ROTATE[1],         hips_ROTATE[2]);                                 
                                 glRotatef(marcRotation, 0, 1, 0); 
                                 glRotatef(-look_LEFT_RIGHT, 0, -1, 0);
                                 glTranslatef(-eyePosition[0],-eyePosition[1],-eyePosition[2]); 
                                 glLightfv(GL_LIGHT0,GL_POSITION,lightPos_marcTorso);
                                 glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_marcTorso);            
                            glPopMatrix();    

                                               if(BODY_PART_SELECTION == 1 && leftArmSelection == 8)
                                               { 
                                                    MaterialDiffuse_marcTorso[0] = 2.0;
                                                    rotationInfoTransparency     = 1.0;
                                               }
                                               else                 
                                               {
                                                    MaterialDiffuse_marcTorso[0] = 1.0;
                                                    rotationInfoTransparency     = 0.2;
                                               }                 
                    
                                     /////--------------------------------___HUD_START___-----------------------------------                       
                                              /////--------------------------------___HUD_START___-----------------------------------                       
                                              if(hideSetPlusDialoque == 0.0)   
                                              {//______________________________________________BEGIN_HIDE_SET_DIALOGUE____                                             
                                                   glPushMatrix(); 
                                                        glTranslatef(leftUpperArmRotationDisplayValues[0], leftUpperArmRotationDisplayValues[1], leftUpperArmRotationDisplayValues[2]); 
                                                        glRotatef(180, 0.0, 1.0, 0.0);
                                                        //glDisable(GL_DEPTH_TEST);
                                                        //glDisable(GL_CULL_FACE);
                                                        glDisable(GL_TEXTURE_2D);
                                                        glDisable(GL_CULL_FACE);
                                                        glColor4f(1.0f,1.0f,1.0f,rotationInfoTransparency);
                                                        glScalef(.4,.4,.4);
                                                        glEnable(GL_BLEND);
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, 0.097, 0);
                                                             printDecimalNumbers(leftUpperArm_ROTATE[3]);
                                                        glPopMatrix(); 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.071+.05, 0);
                                                             printDecimalNumbers(leftUpperArm_ROTATE[0]);
                                                        glPopMatrix();                                 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.238+.10, 0);
                                                             printDecimalNumbers(leftUpperArm_ROTATE[1]);
                                                        glPopMatrix();
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.410998+.15, 0);
                                                             printDecimalNumbers(leftUpperArm_ROTATE[2]);
                                                        glPopMatrix();
                                                        glEnable(GL_CULL_FACE);
                                                        glDisable(GL_BLEND);
                                                        glEnable(GL_TEXTURE_2D);
                                                        //glEnable(GL_CULL_FACE);
                                                        //glEnable(GL_DEPTH_TEST);                
                                                  glPopMatrix();
                                              }//______________________________________________END_HIDE_SET_DIALOGUE____ 
                                    /////--------------------------------___HUD_FINISH___-----------------------------------                     
                    //------------------------------------------------------------------------------------------------------------------------------                    
                    #include "_MODEL_FOLDERS_/marcParts/marcLeftUpperArm/marcLeftUpperArm_vboRender.cpp"  //_ALL_WOOD_SHADERS_ARE_LINKED_TO_THE_TORSO_SHADER
  
 
                       glPushMatrix(); 
                            glTranslatef(leftForeArm_POSITION[0], leftForeArm_POSITION[1], leftForeArm_POSITION[2]);             
                            glRotatef(leftForeArm_ROTATE[3], leftForeArm_ROTATE[0], leftForeArm_ROTATE[1], leftForeArm_ROTATE[2]);       
                            
                            glPushMatrix();
                                 glLoadIdentity();
                                 //
                            
                                 glRotatef(-leftForeArm_ROTATE[3],  -leftForeArm_ROTATE[0],  -leftForeArm_ROTATE[1],  leftForeArm_ROTATE[2]);                                 
                                 glRotatef(-leftUpperArm_ROTATE[3], -leftUpperArm_ROTATE[0], -leftUpperArm_ROTATE[1], leftUpperArm_ROTATE[2]);                                  
                                 glRotatef(-torso_ROTATE[3],        -torso_ROTATE[0],        -torso_ROTATE[1],        torso_ROTATE[2]); 
                                 glRotatef(-hips_ROTATE[3],         -hips_ROTATE[0],         -hips_ROTATE[1],         hips_ROTATE[2]);                                 
                                 glRotatef(marcRotation, 0, 1, 0); 
                                 glRotatef(-look_LEFT_RIGHT, 0, -1, 0);
                                 glTranslatef(-eyePosition[0],-eyePosition[1],-eyePosition[2]); 
                                 glLightfv(GL_LIGHT0,GL_POSITION,lightPos_marcTorso);
                                 glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_marcTorso);
                            glPopMatrix();                                 
                            //------------------------------------------------------
                                               if(BODY_PART_SELECTION == 1 && leftArmSelection == 9)
                                               { 
                                                    MaterialDiffuse_marcTorso[0] = 2.0;
                                                    rotationInfoTransparency     = 1.0;
                                               }
                                               else                 
                                               {
                                                    MaterialDiffuse_marcTorso[0] = 1.0;
                                                    rotationInfoTransparency     = 0.2;
                                               }                          
                            /////--------------------------------___HUD_START___-----------------------------------                       
                                              if(hideSetPlusDialoque == 0.0)   
                                              {//______________________________________________BEGIN_HIDE_SET_DIALOGUE____                                                                                                  
                                                   glPushMatrix(); 
                                                        glTranslatef(leftLowerArmRotationDisplayValues[0], leftLowerArmRotationDisplayValues[1], leftLowerArmRotationDisplayValues[2]); 
                                                        glRotatef(180, 0.0, 1.0, 0.0);
                                                        //glDisable(GL_DEPTH_TEST);
                                                        //glDisable(GL_CULL_FACE);
                                                        glDisable(GL_TEXTURE_2D);
                                                        glDisable(GL_CULL_FACE);
                                                        glColor4f(1.0f,1.0f,1.0f,rotationInfoTransparency);
                                                        glScalef(.4,.4,.4);
                                                        glEnable(GL_BLEND);
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, 0.097, 0);
                                                             printDecimalNumbers(leftForeArm_ROTATE[3]);
                                                        glPopMatrix(); 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.071+.05, 0);
                                                             printDecimalNumbers(leftForeArm_ROTATE[0]);
                                                        glPopMatrix();                                 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.238+.10, 0);
                                                             printDecimalNumbers(leftForeArm_ROTATE[1]);
                                                        glPopMatrix();
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.410998+.15, 0);
                                                             printDecimalNumbers(leftForeArm_ROTATE[2]);
                                                        glPopMatrix();
                                                        glEnable(GL_CULL_FACE);
                                                        glDisable(GL_BLEND);
                                                        glEnable(GL_TEXTURE_2D);
                                                        //glEnable(GL_CULL_FACE);
                                                        //glEnable(GL_DEPTH_TEST);                
                                                    glPopMatrix();
                                               }//______________________________________________END_HIDE_SET_DIALOGUE____ 
                                /////--------------------------------___HUD_FINISH___-----------------------------------                                
                            #include "_MODEL_FOLDERS_/marcParts/marcLeftForeArm/marcLeftForeArm_vboRender.cpp"  //_________________________________ALL_WOOD_SHADERS_ARE_LINKED_TO_THE_TORSO_SHADER
                                          glTranslatef(leftHand_04[0], leftHand_04[1], leftHand_04[2]);             
                                          glRotatef(leftHand_ROTATE[3], leftHand_ROTATE[0], leftHand_ROTATE[1], leftHand_ROTATE[2]);         
                                                      
                                          glPushMatrix();
                                               glLoadIdentity();
                                               //
                                               glRotatef(-leftHand_ROTATE[3], -leftHand_ROTATE[0], -leftHand_ROTATE[1], leftHand_ROTATE[2]);                                               
                                               glRotatef(-leftForeArm_ROTATE[3],    -leftForeArm_ROTATE[0],    -leftForeArm_ROTATE[1],    leftForeArm_ROTATE[2]);                                               
                                               glRotatef(-leftUpperArm_ROTATE[3],   -leftUpperArm_ROTATE[0],   -leftUpperArm_ROTATE[1],   leftUpperArm_ROTATE[2]);                                                
                                               glRotatef(-torso_ROTATE[3],          -torso_ROTATE[0],          -torso_ROTATE[1],          torso_ROTATE[2]);                                               
                                               glRotatef(-hips_ROTATE[3],           -hips_ROTATE[0],           -hips_ROTATE[1],           hips_ROTATE[2]);                                               
                                               glRotatef(marcRotation, 0, 1, 0); 
                                               glRotatef(-look_LEFT_RIGHT, 0, -1, 0);
                                               glTranslatef(-eyePosition[0],-eyePosition[1],-eyePosition[2]); 
                                               glLightfv(GL_LIGHT0,GL_POSITION,lightPos_marcTorso);
                                               glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_marcTorso);   
                                          glPopMatrix();     
                                          //------------------------------------------------------
                                               if(BODY_PART_SELECTION == 1 && leftArmSelection == 0)
                                               { 
                                                    MaterialDiffuse_marcTorso[0] = 2.0;
                                                    rotationInfoTransparency     = 1.0;
                                               }
                                               else                 
                                               {
                                                    MaterialDiffuse_marcTorso[0] = 1.0;
                                                    rotationInfoTransparency     = 0.2;
                                               }                          
                                               /////--------------------------------___HUD_START___-----------------------------------                                                
                                              if(hideSetPlusDialoque == 0.0)   
                                              {//______________________________________________BEGIN_HIDE_SET_DIALOGUE____                                                     
                                                    glPushMatrix(); 
                                                        glTranslatef(leftHandRotationDisplayValues[0], leftHandRotationDisplayValues[1], leftHandRotationDisplayValues[2]); 
                                                        glRotatef(180, 0.0, 1.0, 0.0);
                                                        //glDisable(GL_DEPTH_TEST);
                                                        //glDisable(GL_CULL_FACE);
                                                        glDisable(GL_TEXTURE_2D);
                                                        glDisable(GL_CULL_FACE);
                                                        glColor4f(1.0f,1.0f,1.0f,rotationInfoTransparency);
                                                        glScalef(.4,.4,.4);
                                                        glEnable(GL_BLEND);
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, 0.097, 0);
                                                             printDecimalNumbers(leftHand_ROTATE[3]);
                                                        glPopMatrix(); 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.071+.05, 0);
                                                             printDecimalNumbers(leftHand_ROTATE[0]);
                                                        glPopMatrix();                                 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.238+.1, 0);
                                                             printDecimalNumbers(leftHand_ROTATE[1]);
                                                        glPopMatrix();
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.410998+.15, 0);
                                                             printDecimalNumbers(leftHand_ROTATE[2]);
                                                        glPopMatrix();
                                                        glEnable(GL_CULL_FACE);
                                                        glDisable(GL_BLEND);
                                                        glEnable(GL_TEXTURE_2D);
                                                        //glEnable(GL_CULL_FACE);
                                                        //glEnable(GL_DEPTH_TEST);                
                                                    glPopMatrix();
                                               }
                                /////--------------------------------___HUD_FINISH___-----------------------------------   
                                               if(BODY_PART_SELECTION == 1 && leftArmSelection == 0)
                                               { 
                                                    MaterialDiffuse_marcTorso[0] = 2.0;
                                                    rotationInfoTransparency     = 1.0;
                                               }
                                               else                 
                                               {
                                                    MaterialDiffuse_marcTorso[0] = 1.0;
                                                    rotationInfoTransparency     = 0.2;
                                               }  
                                          #include "_MODEL_FOLDERS_/marcParts/marcLeftHand/marcLeftHand_vboRender.cpp" //_________________________________ALL_WOOD_SHADERS_ARE_LINKED_TO_THE_TORSO_SHADER 

                                          

    glPopMatrix();              
  glPopMatrix();
glPopMatrix();
////////////_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM
////////////_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM
////////////_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM            
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                    
////////////_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM
////////////_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM
////////////_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM
glPushMatrix();
    
    glTranslatef(torso_04[0], torso_04[1], torso_04[2]);
   
    glRotatef(torso_ROTATE[3], torso_ROTATE[0], torso_ROTATE[1], torso_ROTATE[2]); 
       
       glPushMatrix(); 
           glTranslatef(rightUpperArm_04[0], rightUpperArm_04[1], rightUpperArm_04[2]);             
           glRotatef(rightUpperArm_ROTATE[3], rightUpperArm_ROTATE[0], rightUpperArm_ROTATE[1], rightUpperArm_ROTATE[2]);   
                           
                           
                            glPushMatrix();
                                 glLoadIdentity();
                                 glRotatef(-rightUpperArm_ROTATE[3],     -rightUpperArm_ROTATE[0], -rightUpperArm_ROTATE[1], rightUpperArm_ROTATE[2]);                                 
                                 glRotatef(-torso_ROTATE[3],             -torso_ROTATE[0],         -torso_ROTATE[1],         torso_ROTATE[2]);                                 
                                 glRotatef(-hips_ROTATE[3],              -hips_ROTATE[0],          -hips_ROTATE[1],          hips_ROTATE[2]);                                 
                                 glRotatef(marcRotation, 0, 1, 0); 
                                 glRotatef(-look_LEFT_RIGHT, 0, -1, 0);
                                 glTranslatef(-eyePosition[0],-eyePosition[1],-eyePosition[2]);                  
                                 glLightfv(GL_LIGHT0,GL_POSITION,lightPos_marcTorso);
                                 glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_marcTorso);
                            glPopMatrix();
                 
                                               if(BODY_PART_SELECTION == 2 && rightArmSelection == 8)
                                               { 
                                                    MaterialDiffuse_marcTorso[0] = 2.0;
                                                    rotationInfoTransparency     = 1.0;
                                               }
                                               else                 
                                               {
                                                    MaterialDiffuse_marcTorso[0] = 1.0;
                                                    rotationInfoTransparency     = 0.2;
                                               }   
                                                      /////--------------------------------___HUD_START___-----------------------------------                       
                                              if(hideSetPlusDialoque == 0.0)   
                                              {//______________________________________________BEGIN_HIDE_SET_DIALOGUE____                                                   
                                                    glPushMatrix(); 
                                                        glTranslatef(rightUpperArmRotationDisplayValues[0], rightUpperArmRotationDisplayValues[1], rightUpperArmRotationDisplayValues[2]); 
                                                        glRotatef(180, 0.0, 1.0, 0.0);
                                                        //glDisable(GL_DEPTH_TEST);
                                                        //glDisable(GL_CULL_FACE);
                                                        glDisable(GL_TEXTURE_2D);
                                                        glDisable(GL_CULL_FACE);
                                                        glColor4f(1.0f,1.0f,1.0f,rotationInfoTransparency);
                                                        glScalef(.4,.4,.4);
                                                        glEnable(GL_BLEND);
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, 0.097, 0);
                                                             printDecimalNumbers(rightUpperArm_ROTATE[3]);
                                                        glPopMatrix(); 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.071+.05, 0);
                                                             printDecimalNumbers(rightUpperArm_ROTATE[0]);
                                                        glPopMatrix();                                 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.238+.10, 0);
                                                             printDecimalNumbers(rightUpperArm_ROTATE[1]);
                                                        glPopMatrix();
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.410998+.15, 0);
                                                             printDecimalNumbers(rightUpperArm_ROTATE[2]);
                                                        glPopMatrix();
                                                        glEnable(GL_CULL_FACE);
                                                        glDisable(GL_BLEND);
                                                        glEnable(GL_TEXTURE_2D);
                                                        //glEnable(GL_CULL_FACE);
                                                        //glEnable(GL_DEPTH_TEST);                
                                                    glPopMatrix();
                                               }//______________________________________________END_HIDE_SET_DIALOGUE____ 
                                    /////--------------------------------___HUD_FINISH___-----------------------------------   
                     #include "_MODEL_FOLDERS_/marcParts/marcRightUpperArm/marcRightUpperArm_vboRender.cpp"  //_________________________________ALL_WOOD_SHADERS_ARE_LINKED_TO_THE_TORSO_SHADER


                    
                     glPushMatrix(); 
                              glTranslatef(rightForeArm_04[0], rightForeArm_04[1], rightForeArm_04[2]);             
                              glRotatef(rightForeArm_ROTATE[3], rightForeArm_ROTATE[0], rightForeArm_ROTATE[1], rightForeArm_ROTATE[2]);    
                            
                            glPushMatrix();
                                 glLoadIdentity();
                                 //
                                 
                                 glRotatef(-rightForeArm_ROTATE[3],     -rightForeArm_ROTATE[0],  -rightForeArm_ROTATE[1],    rightForeArm_ROTATE[2]);                                  
                                 glRotatef(-rightUpperArm_ROTATE[3],    -rightUpperArm_ROTATE[0], -rightUpperArm_ROTATE[1],   rightUpperArm_ROTATE[2]);                                
                                 glRotatef(-torso_ROTATE[3],            -torso_ROTATE[0],         -torso_ROTATE[1],           torso_ROTATE[2]);                                 
                                 glRotatef(-hips_ROTATE[3],             -hips_ROTATE[0],          -hips_ROTATE[1],            hips_ROTATE[2]);                                 
                                 glRotatef(marcRotation, 0, 1, 0); 
                                 glRotatef(-look_LEFT_RIGHT, 0, -1, 0);
                                 glTranslatef(-eyePosition[0],-eyePosition[1],-eyePosition[2]);                                               
                                glLightfv(GL_LIGHT0,GL_POSITION,lightPos_marcTorso);
                                glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_marcTorso);
                            glPopMatrix();                                

                                               if(BODY_PART_SELECTION == 2 && rightArmSelection == 9)
                                               { 
                                                    MaterialDiffuse_marcTorso[0] = 2.0;
                                                    rotationInfoTransparency     = 1.0;
                                               }
                                               else                 
                                               {
                                                    MaterialDiffuse_marcTorso[0] = 1.0;
                                                    rotationInfoTransparency     = 0.2;
                                               }                          
                            /////--------------------------------___HUD_START___-----------------------------------                       
                                              if(hideSetPlusDialoque == 0.0)   
                                              {//______________________________________________BEGIN_HIDE_SET_DIALOGUE____                                                    
                                                   glPushMatrix(); 
                                                        glTranslatef(rightLowerArmRotationDisplayValues[0], rightLowerArmRotationDisplayValues[1], rightLowerArmRotationDisplayValues[2]); 
                                                        glRotatef(180, 0.0, 1.0, 0.0);
                                                        //glDisable(GL_DEPTH_TEST);
                                                        //glDisable(GL_CULL_FACE);
                                                        glDisable(GL_TEXTURE_2D);
                                                        glDisable(GL_CULL_FACE);
                                                        glColor4f(1.0f,1.0f,1.0f,rotationInfoTransparency);
                                                        glScalef(.4,.4,.4);
                                                        glEnable(GL_BLEND);
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, 0.097, 0);
                                                             printDecimalNumbers(rightForeArm_ROTATE[3]);
                                                        glPopMatrix(); 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.071+.05, 0);
                                                             printDecimalNumbers(rightForeArm_ROTATE[0]);
                                                        glPopMatrix();                                 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.238+.10, 0);
                                                             printDecimalNumbers(rightForeArm_ROTATE[1]);
                                                        glPopMatrix();
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.410998+.15, 0);
                                                             printDecimalNumbers(rightForeArm_ROTATE[2]);
                                                        glPopMatrix();
                                                        glEnable(GL_CULL_FACE);
                                                        glDisable(GL_BLEND);
                                                        glEnable(GL_TEXTURE_2D);
                                                        //glEnable(GL_CULL_FACE);
                                                        //glEnable(GL_DEPTH_TEST);                
                                                    glPopMatrix();
                                               }//______________________________________________END_HIDE_SET_DIALOGUE____ 
                                /////--------------------------------___HUD_FINISH___-----------------------------------             
                                #include "_MODEL_FOLDERS_/marcParts/marcRightForeArm/marcRightForeArm_vboRender.cpp"  //_________________________________ALL_WOOD_SHADERS_ARE_LINKED_TO_THE_TORSO_SHADER

                 
                                         glTranslatef(rightHand_04[0],  rightHand_04[1],     rightHand_04[2]);             
                                         glRotatef(rightHand_ROTATE[3], rightHand_ROTATE[0], rightHand_ROTATE[1], rightHand_ROTATE[2]);   
                                          
                                          glPushMatrix();
                                               glLoadIdentity();
                                               //
                                               glRotatef(-rightHand_ROTATE[3], -rightHand_ROTATE[0], -rightHand_ROTATE[1], rightHand_ROTATE[2]);    
                                               glRotatef(-rightForeArm_ROTATE[3],    -rightForeArm_ROTATE[0],    -rightForeArm_ROTATE[1],    rightForeArm_ROTATE[2]);
                                               glRotatef(-rightUpperArm_ROTATE[3],   -rightUpperArm_ROTATE[0],   -rightUpperArm_ROTATE[1],   rightUpperArm_ROTATE[2]);                                            
                                               glRotatef(-torso_ROTATE[3],           -torso_ROTATE[0],           -torso_ROTATE[1],           torso_ROTATE[2]);                                               
                                               glRotatef(-hips_ROTATE[3],            -hips_ROTATE[0],            -hips_ROTATE[1],            hips_ROTATE[2]);                                              
                                               glRotatef(marcRotation, 0, 1, 0); 
                                               glRotatef(-look_LEFT_RIGHT, 0, -1, 0);
                                               glTranslatef(-eyePosition[0],-eyePosition[1],-eyePosition[2]);                                          
                                               glLightfv(GL_LIGHT0,GL_POSITION,lightPos_marcTorso);
                                               glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_marcTorso);  
                                          glPopMatrix();                                         
            
                                               if(BODY_PART_SELECTION == 2 && rightArmSelection == 0)
                                               { 
                                                    MaterialDiffuse_marcTorso[0] = 2.0;
                                                    rotationInfoTransparency     = 1.0;
                                               }
                                               else                 
                                               {
                                                    MaterialDiffuse_marcTorso[0] = 1.0;
                                                    rotationInfoTransparency     = 0.2;
                                               } 
                                          /////--------------------------------___HUD_START___-----------------------------------                       
                                              if(hideSetPlusDialoque == 0.0)   
                                              {//______________________________________________BEGIN_HIDE_SET_DIALOGUE____                                                    
                                                   glPushMatrix(); 
                                                        glTranslatef(rightHandRotationDisplayValues[0], rightHandRotationDisplayValues[1], rightHandRotationDisplayValues[2]); 
                                                        glRotatef(180, 0.0, 1.0, 0.0);
                                                        //glDisable(GL_DEPTH_TEST);
                                                        //glDisable(GL_CULL_FACE);
                                                        glDisable(GL_TEXTURE_2D);
                                                        glDisable(GL_CULL_FACE);
                                                        glColor4f(1.0f,1.0f,1.0f,rotationInfoTransparency);
                                                        glScalef(.4,.4,.4);
                                                        glEnable(GL_BLEND);
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, 0.097, 0);
                                                             printDecimalNumbers(rightHand_ROTATE[3]);
                                                        glPopMatrix(); 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.071+.05, 0);
                                                             printDecimalNumbers(rightHand_ROTATE[0]);
                                                        glPopMatrix();                                 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.238+.1, 0);
                                                             printDecimalNumbers(rightHand_ROTATE[1]);
                                                        glPopMatrix();
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.410998+.15, 0);
                                                             printDecimalNumbers(rightHand_ROTATE[2]);
                                                        glPopMatrix();
                                                        glEnable(GL_CULL_FACE);
                                                        glDisable(GL_BLEND);
                                                        glEnable(GL_TEXTURE_2D);
                                                        //glEnable(GL_CULL_FACE);
                                                        //glEnable(GL_DEPTH_TEST);                
                                                    glPopMatrix();
                                               }//______________________________________________END_HIDE_SET_DIALOGUE____     
                                /////--------------------------------___HUD_FINISH___-----------------------------------                                          
                                         #include "_MODEL_FOLDERS_/marcParts/marcRightHand/marcRightHand_vboRender.cpp"  //_________________________________ALL_WOOD_SHADERS_ARE_LINKED_TO_THE_TORSO_SHADER
       glPopMatrix();
   glPopMatrix();
glPopMatrix();            
////////////_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM
////////////_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM
////////////_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////            
////////////_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG
////////////_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG
////////////_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG
glPushMatrix(); 
    
    glPushMatrix(); 
         glTranslatef(leftUpperLeg_04[0], leftUpperLeg_04[1], leftUpperLeg_04[2]);             
         glRotatef(leftUpperLeg_ROTATE[3], leftUpperLeg_ROTATE[0], leftUpperLeg_ROTATE[1], leftUpperLeg_ROTATE[2]); 

                            glPushMatrix();
                                 glLoadIdentity();
                                 glRotatef(-leftUpperLeg_ROTATE[3], -leftUpperLeg_ROTATE[0], -leftUpperLeg_ROTATE[1], leftUpperLeg_ROTATE[2]);                                 
                                 glRotatef(-hips_ROTATE[3],         -hips_ROTATE[0],         -hips_ROTATE[1],         hips_ROTATE[2]);                                 
                                 glRotatef(marcRotation, 0, 1, 0); 
                                 glRotatef(-look_LEFT_RIGHT, 0, -1, 0);
                                 glTranslatef(-eyePosition[0],-eyePosition[1],-eyePosition[2]);             
                                 glLightfv(GL_LIGHT0,GL_POSITION,lightPos_marcTorso);
                                 glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_marcTorso);
                            glPopMatrix();                 

                                               if(BODY_PART_SELECTION == 3 && leftLegSelection == 8)
                                               { 
                                                    MaterialDiffuse_marcTorso[0] = 2.0;
                                                    rotationInfoTransparency     = 1.0;
                                               }
                                               else                 
                                               {
                                                    MaterialDiffuse_marcTorso[0] = 1.0;
                                                    rotationInfoTransparency     = 0.2;
                                               }   
                                     /////--------------------------------___HUD_START___-----------------------------------                       
                                              if(hideSetPlusDialoque == 0.0)   
                                              {//______________________________________________BEGIN_HIDE_SET_DIALOGUE____                                                    
                                                   glPushMatrix(); 
                                                        glTranslatef(leftUpperLegRotationDisplayValues[0], leftUpperLegRotationDisplayValues[1], leftUpperLegRotationDisplayValues[2]); 
                                                        glRotatef(180, 0.0, 1.0, 0.0);
                                                        //glDisable(GL_DEPTH_TEST);
                                                        //glDisable(GL_CULL_FACE);
                                                        glDisable(GL_TEXTURE_2D);
                                                        glDisable(GL_CULL_FACE);
                                                        glColor4f(1.0f,1.0f,1.0f,rotationInfoTransparency);
                                                        glScalef(.4,.4,.4);
                                                        glEnable(GL_BLEND);
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, 0.097, 0);
                                                             printDecimalNumbers(leftUpperLeg_ROTATE[3]);
                                                        glPopMatrix(); 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.071+.05, 0);
                                                             printDecimalNumbers(leftUpperLeg_ROTATE[0]);
                                                        glPopMatrix();                                 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.238+.10, 0);
                                                             printDecimalNumbers(leftUpperLeg_ROTATE[1]);
                                                        glPopMatrix();
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.410998+.15, 0);
                                                             printDecimalNumbers(leftUpperLeg_ROTATE[2]);
                                                        glPopMatrix();
                                                        glEnable(GL_CULL_FACE);
                                                        glDisable(GL_BLEND);
                                                        glEnable(GL_TEXTURE_2D);
                                                        //glEnable(GL_CULL_FACE);
                                                        //glEnable(GL_DEPTH_TEST);                
                                                    glPopMatrix();
                                               }//______________________________________________END_HIDE_SET_DIALOGUE____
                                    /////--------------------------------___HUD_FINISH___-----------------------------------                             
                             
                             #include "_MODEL_FOLDERS_/marcParts/marcLeftUpperLeg/marcLeftUpperLeg_vboRender.cpp"  //_________________________________ALL_WOOD_SHADERS_ARE_LINKED_TO_THE_TORSO_SHADER



                    glPushMatrix(); 
                               glTranslatef(leftLowerLeg_04[0], leftLowerLeg_04[1], leftLowerLeg_04[2]);             
                               glRotatef(leftLowerLeg_ROTATE[3], leftLowerLeg_ROTATE[0], leftLowerLeg_ROTATE[1], leftLowerLeg_ROTATE[2]);   
                            
                            glPushMatrix();
                                 glLoadIdentity();
                                 //
                                 
                                 glRotatef(-leftLowerLeg_ROTATE[3], -leftLowerLeg_ROTATE[0], -leftLowerLeg_ROTATE[1], leftLowerLeg_ROTATE[2]);                                 
                                 glRotatef(-leftUpperLeg_ROTATE[3], -leftUpperLeg_ROTATE[0], -leftUpperLeg_ROTATE[1], leftUpperLeg_ROTATE[2]);                                  
                                 glRotatef(-hips_ROTATE[3],         -hips_ROTATE[0],         -hips_ROTATE[1],         hips_ROTATE[2]);                                 
                                 glRotatef(marcRotation, 0, 1, 0); 
                                 glRotatef(-look_LEFT_RIGHT, 0, -1, 0);
                                 glTranslatef(-eyePosition[0],-eyePosition[1],-eyePosition[2]);                               
                                 glLightfv(GL_LIGHT0,GL_POSITION,lightPos_marcTorso);
                                 glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_marcTorso);   
                            glPopMatrix();                               

                                               if(BODY_PART_SELECTION == 3 && leftLegSelection == 9)
                                               { 
                                                    MaterialDiffuse_marcTorso[0] = 2.0;
                                                    rotationInfoTransparency     = 1.0;
                                               }
                                               else                 
                                               {
                                                    MaterialDiffuse_marcTorso[0] = 1.0;
                                                    rotationInfoTransparency     = 0.2;
                                               }                         
                                     /////--------------------------------___HUD_START___-----------------------------------                       
                                              if(hideSetPlusDialoque == 0.0)   
                                              {//______________________________________________BEGIN_HIDE_SET_DIALOGUE____                                                    
                                                   glPushMatrix(); 
                                                        glTranslatef(leftLowerLegRotationDisplayValues[0], leftLowerLegRotationDisplayValues[1], leftLowerLegRotationDisplayValues[2]); 
                                                        glRotatef(180, 0.0, 1.0, 0.0);
                                                        //glDisable(GL_DEPTH_TEST);
                                                        //glDisable(GL_CULL_FACE);
                                                        glDisable(GL_TEXTURE_2D);
                                                        glDisable(GL_CULL_FACE);
                                                        glColor4f(1.0f,1.0f,1.0f,rotationInfoTransparency);
                                                        glScalef(.4,.4,.4);
                                                        glEnable(GL_BLEND);
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, 0.097, 0);
                                                             printDecimalNumbers(leftLowerLeg_ROTATE[3]);
                                                        glPopMatrix(); 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.071+.05, 0);
                                                             printDecimalNumbers(leftLowerLeg_ROTATE[0]);
                                                        glPopMatrix();                                 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.238+.10, 0);
                                                             printDecimalNumbers(leftLowerLeg_ROTATE[1]);
                                                        glPopMatrix();
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.410998+.15, 0);
                                                             printDecimalNumbers(leftLowerLeg_ROTATE[2]);
                                                        glPopMatrix();
                                                        glEnable(GL_CULL_FACE);
                                                        glDisable(GL_BLEND);
                                                        glEnable(GL_TEXTURE_2D);
                                                        //glEnable(GL_CULL_FACE);
                                                        //glEnable(GL_DEPTH_TEST);                
                                                    glPopMatrix();
                                               }//______________________________________________END_HIDE_SET_DIALOGUE____  
                                    /////--------------------------------___HUD_FINISH___-----------------------------------                             
                                                          
                             #include "_MODEL_FOLDERS_/marcParts/marcLeftLowerLeg/marcLeftLowerLeg_vboRender.cpp"  //_________________________________ALL_WOOD_SHADERS_ARE_LINKED_TO_THE_TORSO_SHADER

       
                                                  glTranslatef(leftFoot_04[0], leftFoot_04[1], leftFoot_04[2]);             
                                                  glRotatef(leftFoot_ROTATE[3], leftFoot_ROTATE[0], leftFoot_ROTATE[1], leftFoot_ROTATE[2]); 
                                                 
                                                 glPushMatrix();
                                                      glLoadIdentity();
                                                      //
                                                      glRotatef(-leftFoot_ROTATE[3], -leftFoot_ROTATE[0], -leftFoot_ROTATE[1], leftFoot_ROTATE[2]);                                                       
                                                      glRotatef(-leftLowerLeg_ROTATE[3], -leftLowerLeg_ROTATE[0], -leftLowerLeg_ROTATE[1], leftLowerLeg_ROTATE[2]);                                                       
                                                      glRotatef(-leftUpperLeg_ROTATE[3], -leftUpperLeg_ROTATE[0], -leftUpperLeg_ROTATE[1], leftUpperLeg_ROTATE[2]);                                                       
                                                      glRotatef(-hips_ROTATE[3],         -hips_ROTATE[0],         -hips_ROTATE[1],         hips_ROTATE[2]);                                                     
                                                      glRotatef(marcRotation, 0, 1, 0); 
                                                      glRotatef(-look_LEFT_RIGHT, 0, -1, 0);
                                                      glTranslatef(-eyePosition[0],-eyePosition[1],-eyePosition[2]);                                                  
                                                      glLightfv(GL_LIGHT0,GL_POSITION,lightPos_marcTorso);
                                                      glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_marcTorso);     
                                                 glPopMatrix();                                                  

                                               if(BODY_PART_SELECTION == 3 && leftLegSelection == 0)
                                               { 
                                                    MaterialDiffuse_marcTorso[0] = 2.0;
                                                    rotationInfoTransparency     = 1.0;
                                               }
                                               else                 
                                               {
                                                    MaterialDiffuse_marcTorso[0] = 1.0;
                                                    rotationInfoTransparency     = 0.2;
                                               }                                                 
                                     /////--------------------------------___HUD_START___-----------------------------------                       
                                              if(hideSetPlusDialoque == 0.0)   
                                              {//______________________________________________BEGIN_HIDE_SET_DIALOGUE____                                                    
                                                   glPushMatrix(); 
                                                        glTranslatef(leftFootRotationDisplayValues[0], leftFootRotationDisplayValues[1], leftFootRotationDisplayValues[2]); 
                                                        glRotatef(180, 0.0, 1.0, 0.0);
                                                        //glDisable(GL_DEPTH_TEST);
                                                        //glDisable(GL_CULL_FACE);
                                                        glDisable(GL_TEXTURE_2D);
                                                        glDisable(GL_CULL_FACE);
                                                        glColor4f(1.0f,1.0f,1.0f,rotationInfoTransparency);
                                                        glScalef(.4,.4,.4);
                                                        glEnable(GL_BLEND);
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, 0.097, 0);
                                                             printDecimalNumbers(leftFoot_ROTATE[3]);
                                                        glPopMatrix(); 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.071+.05, 0);
                                                             printDecimalNumbers(leftFoot_ROTATE[0]);
                                                        glPopMatrix();                                 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.238+.10, 0);
                                                             printDecimalNumbers(leftFoot_ROTATE[1]);
                                                        glPopMatrix();
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.410998+.15, 0);
                                                             printDecimalNumbers(leftFoot_ROTATE[2]);
                                                        glPopMatrix();
                                                        glEnable(GL_CULL_FACE);
                                                        glDisable(GL_BLEND);
                                                        glEnable(GL_TEXTURE_2D);
                                                        //glEnable(GL_CULL_FACE);
                                                        //glEnable(GL_DEPTH_TEST);                
                                                    glPopMatrix();
                                               }//______________________________________________BEGIN_HIDE_SET_DIALOGUE____
                                    /////--------------------------------___HUD_FINISH___-----------------------------------                                                     
                                                 #include "_MODEL_FOLDERS_/marcParts/marcLeftBoot/marcLeftBoot_vboRender.cpp"  //_________________________________ALL_WOOD_SHADERS_ARE_LINKED_TO_THE_TORSO_SHADER

 

      glPopMatrix();
   glPopMatrix();
glPopMatrix(); 
////////////_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG
////////////_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG
////////////_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG
////////////_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG
////////////_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG
glPushMatrix();
           glPushMatrix(); 
                  glTranslatef(rightUpperLeg_04[0], rightUpperLeg_04[1], rightUpperLeg_04[2]);             
                  glRotatef(rightUpperLeg_ROTATE[3], rightUpperLeg_ROTATE[0], rightUpperLeg_ROTATE[1], rightUpperLeg_ROTATE[2]);      
           
                            glPushMatrix();
                                 glLoadIdentity();
                                 glRotatef(-rightUpperLeg_ROTATE[3], -rightUpperLeg_ROTATE[0], -rightUpperLeg_ROTATE[1], rightUpperLeg_ROTATE[2]);                                 
                                 glRotatef(-hips_ROTATE[3],          -hips_ROTATE[0],          -hips_ROTATE[1],          hips_ROTATE[2]);                                 
                                 glRotatef(marcRotation, 0, 1, 0); 
                                 glRotatef(-look_LEFT_RIGHT, 0, -1, 0);
                                 glTranslatef(-eyePosition[0],-eyePosition[1],-eyePosition[2]);                          
                                 glLightfv(GL_LIGHT0,GL_POSITION,lightPos_marcTorso);
                                 glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_marcTorso);
                            glPopMatrix();
                            
                                               if(BODY_PART_SELECTION == 4 && rightLegSelection == 8)
                                               { 
                                                    MaterialDiffuse_marcTorso[0] = 2.0;
                                                    rotationInfoTransparency     = 1.0;
                                               }
                                               else                 
                                               {
                                                    MaterialDiffuse_marcTorso[0] = 1.0;
                                                    rotationInfoTransparency     = 0.2;
                                               }   
                                     /////--------------------------------___HUD_START___-----------------------------------                       
                                              if(hideSetPlusDialoque == 0.0)   
                                              {//______________________________________________BEGIN_HIDE_SET_DIALOGUE____                                                    
                                                    glPushMatrix(); 
                                                        glTranslatef(rightUpperLegRotationDisplayValues[0], rightUpperLegRotationDisplayValues[1], rightUpperLegRotationDisplayValues[2]); 
                                                        glRotatef(180, 0.0, 1.0, 0.0);
                                                        //glDisable(GL_DEPTH_TEST);
                                                        //glDisable(GL_CULL_FACE);
                                                        glDisable(GL_TEXTURE_2D);
                                                        glColor4f(1.0f,1.0f,1.0f,rotationInfoTransparency);
                                                        glScalef(.4,.4,.4);
                                                        glEnable(GL_BLEND);
                                                        glDisable(GL_CULL_FACE);
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, 0.097, 0);
                                                             printDecimalNumbers(rightUpperLeg_ROTATE[3]);
                                                        glPopMatrix(); 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.071+.05, 0);
                                                             printDecimalNumbers(rightUpperLeg_ROTATE[0]);
                                                        glPopMatrix();                                 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.238+.10, 0);
                                                             printDecimalNumbers(rightUpperLeg_ROTATE[1]);
                                                        glPopMatrix();
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.410998+.15, 0);
                                                             printDecimalNumbers(rightUpperLeg_ROTATE[2]);
                                                        glPopMatrix();
                                                        glEnable(GL_CULL_FACE);
                                                        glDisable(GL_BLEND);
                                                        glEnable(GL_TEXTURE_2D);
                                                        //glEnable(GL_CULL_FACE);
                                                        //glEnable(GL_DEPTH_TEST);                
                                                    glPopMatrix();
                                               }//______________________________________________END_HIDE_SET_DIALOGUE____  
                                    /////--------------------------------___HUD_FINISH___-----------------------------------                                
                             
                             #include "_MODEL_FOLDERS_/marcParts/marcRightUpperLeg/marcRightUpperLeg_vboRender.cpp"      //_________________________________ALL_WOOD_SHADERS_ARE_LINKED_TO_THE_TORSO_SHADER    
                                            
                                    glPushMatrix(); 
                                            glTranslatef(rightLowerLeg_04[0], rightLowerLeg_04[1], rightLowerLeg_04[2]);             
                                            glRotatef(rightLowerLeg_ROTATE[3], rightLowerLeg_ROTATE[0], rightLowerLeg_ROTATE[1], rightLowerLeg_ROTATE[2]);     
                            glPushMatrix();
                                 glLoadIdentity();
                                 //
                                 glRotatef(-rightLowerLeg_ROTATE[3], -rightLowerLeg_ROTATE[0], -rightLowerLeg_ROTATE[1], rightLowerLeg_ROTATE[2]);                                 
                                 glRotatef(-rightUpperLeg_ROTATE[3], -rightUpperLeg_ROTATE[0], -rightUpperLeg_ROTATE[1], rightUpperLeg_ROTATE[2]);                                 
                                 glRotatef(-hips_ROTATE[3],          -hips_ROTATE[0],          -hips_ROTATE[1],          hips_ROTATE[2]);                                 
                                 glRotatef(marcRotation, 0, 1, 0); 
                                 glRotatef(-look_LEFT_RIGHT, 0, -1, 0);
                                 glTranslatef(-eyePosition[0],-eyePosition[1],-eyePosition[2]);                                            
                                 glLightfv(GL_LIGHT0,GL_POSITION,lightPos_marcTorso);
                                 glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_marcTorso);                                            
                            glPopMatrix();                

                                               if(BODY_PART_SELECTION == 4 && rightLegSelection == 9)
                                               { 
                                                    MaterialDiffuse_marcTorso[0] = 2.0;
                                                    rotationInfoTransparency     = 1.0;
                                               }
                                               else                 
                                               {
                                                    MaterialDiffuse_marcTorso[0] = 1.0;
                                                    rotationInfoTransparency     = 0.2;
                                               }                       
                                     /////--------------------------------___HUD_START___-----------------------------------                       
                                              if(hideSetPlusDialoque == 0.0)   
                                              {//______________________________________________BEGIN_HIDE_SET_DIALOGUE____                                                    
                                                    glPushMatrix(); 
                                                        glTranslatef(rightLowerLegRotationDisplayValues[0], rightLowerLegRotationDisplayValues[1], rightLowerLegRotationDisplayValues[2]); 
                                                        glRotatef(180, 0.0, 1.0, 0.0);
                                                        //glDisable(GL_DEPTH_TEST);
                                                        //glDisable(GL_CULL_FACE);
                                                        glDisable(GL_TEXTURE_2D);
                                                        glDisable(GL_CULL_FACE);
                                                        glColor4f(1.0f,1.0f,1.0f,rotationInfoTransparency);
                                                        glScalef(.4,.4,.4);
                                                        glEnable(GL_BLEND);
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, 0.097, 0);
                                                             printDecimalNumbers(rightLowerLeg_ROTATE[3]);
                                                        glPopMatrix(); 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.071+.05, 0);
                                                             printDecimalNumbers(rightLowerLeg_ROTATE[0]);
                                                        glPopMatrix();                                 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.238+.10, 0);
                                                             printDecimalNumbers(rightLowerLeg_ROTATE[1]);
                                                        glPopMatrix();
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.410998+.15, 0);
                                                             printDecimalNumbers(rightLowerLeg_ROTATE[2]);
                                                        glPopMatrix();
                                                        glDisable(GL_BLEND);
                                                        glEnable(GL_CULL_FACE);
                                                        glEnable(GL_TEXTURE_2D);
                                                        //glEnable(GL_CULL_FACE);
                                                        //glEnable(GL_DEPTH_TEST);                
                                                   glPopMatrix();
                                               }//______________________________________________END_HIDE_SET_DIALOGUE____ 
                                    /////--------------------------------___HUD_FINISH___-----------------------------------                             
                             #include "_MODEL_FOLDERS_/marcParts/marcRightLowerLeg/marcRightLowerLeg_vboRender.cpp" //_________________________________ALL_WOOD_SHADERS_ARE_LINKED_TO_THE_TORSO_SHADER
                          
   
                      
                                                            glTranslatef(rightFoot_04[0], rightFoot_04[1], rightFoot_04[2]);             
                                                            glRotatef(rightFoot_ROTATE[3], rightFoot_ROTATE[0], rightFoot_ROTATE[1], rightFoot_ROTATE[2]);       
                           
                                                              glPushMatrix();
                                                                   glLoadIdentity();
                                                                   //
                                                                   glRotatef(-rightFoot_ROTATE[3], -rightFoot_ROTATE[0], -rightFoot_ROTATE[1], rightFoot_ROTATE[2]);                                                                    
                                                                   glRotatef(-rightLowerLeg_ROTATE[3], -rightLowerLeg_ROTATE[0], -rightLowerLeg_ROTATE[1], rightLowerLeg_ROTATE[2]);                                                                   
                                                                   glRotatef(-rightUpperLeg_ROTATE[3], -rightUpperLeg_ROTATE[0], -rightUpperLeg_ROTATE[1], rightUpperLeg_ROTATE[2]);                                                                   
                                                                   glRotatef(-hips_ROTATE[3],          -hips_ROTATE[0],          -hips_ROTATE[1],          hips_ROTATE[2]);                                                                   
                                                                   glRotatef(marcRotation, 0, 1, 0); 
                                                                   glRotatef(-look_LEFT_RIGHT, 0, -1, 0);
                                                                   glTranslatef(-eyePosition[0],-eyePosition[1],-eyePosition[2]);                                                            
                                                                   glLightfv(GL_LIGHT0,GL_POSITION,lightPos_marcTorso);
                                                                   glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_marcTorso);   
                                                              glPopMatrix();                           

                                                              if(BODY_PART_SELECTION == 4 && rightLegSelection == 0)
                                                              { 
                                                                    MaterialDiffuse_marcTorso[0] = 2.0;
                                                                    rotationInfoTransparency     = 1.0;
                                                              }
                                                              else                 
                                                              {
                                                                    MaterialDiffuse_marcTorso[0] = 1.0;
                                                                    rotationInfoTransparency     = 0.2;
                                                              }                                    
                                                              /////--------------------------------___HUD_START___-----------------------------------                       
                                                              if(hideSetPlusDialoque == 0.0)   
                                                              {//______________________________________________BEGIN_HIDE_SET_DIALOGUE____                                                                            
                                                                       glPushMatrix(); 
                                                                                 glTranslatef(rightFootRotationDisplayValues[0], rightFootRotationDisplayValues[1], rightFootRotationDisplayValues[2]); 
                                                                                 glRotatef(180, 0.0, 1.0, 0.0);
                                                                                 //glDisable(GL_DEPTH_TEST);
                                                                                 //glDisable(GL_CULL_FACE);
                                                                                 glDisable(GL_TEXTURE_2D);
                                                                                 glDisable(GL_CULL_FACE);                      
                                                                                 glColor4f(1.0f,1.0f,1.0f,rotationInfoTransparency);
                                                                                 glScalef(.4,.4,.4);
                                                                                 glEnable(GL_BLEND);
                                                                                 glPushMatrix(); 
                                                                                      glTranslatef(0.0f, 0.097, 0);
                                                                                      printDecimalNumbers(rightFoot_ROTATE[3]);
                                                                                 glPopMatrix(); 
                                                                                 glPushMatrix(); 
                                                                                     glTranslatef(0.0f, -0.071+.05, 0);
                                                                                      printDecimalNumbers(rightFoot_ROTATE[0]);
                                                                                 glPopMatrix();                                 
                                                                                 glPushMatrix(); 
                                                                                      glTranslatef(0.0f, -0.238+.10, 0);
                                                                                      printDecimalNumbers(rightFoot_ROTATE[1]);
                                                                                 glPopMatrix();
                                                                                 glPushMatrix(); 
                                                                                      glTranslatef(0.0f, -0.410998+.15, 0);
                                                                                      printDecimalNumbers(rightFoot_ROTATE[2]);
                                                                                 glPopMatrix();
                                                                                 glDisable(GL_BLEND);
                                                                                 glEnable(GL_CULL_FACE);
                                                                                 glEnable(GL_TEXTURE_2D);
                                                                                 //glEnable(GL_CULL_FACE);
                                                                                 //glEnable(GL_DEPTH_TEST);                
                                                                        glPopMatrix();
                                                                }//______________________________________________END_HIDE_SET_DIALOGUE____   
                                                              /////--------------------------------___HUD_FINISH___-----------------------------------                                                                 
                                                              #include "_MODEL_FOLDERS_/marcParts/marcRightBoot/marcRightBoot_vboRender.cpp" //_________________________________ALL_WOOD_SHADERS_ARE_LINKED_TO_THE_TORSO_SHADER 

                        
     
       
                                    glPopMatrix(); 
             glPopMatrix();
       glPopMatrix();


////////////_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG
////////////_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG
////////////_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG      
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   glTranslatef(torso_04[0],  torso_04[1], torso_04[2]);
   glRotatef(torso_ROTATE[3], torso_ROTATE[0], torso_ROTATE[1], torso_ROTATE[2]); 

                                                      
                                                        glTranslatef(jetPackPosition[0], jetPackPosition[1], jetPackPosition[2]);     
                                                                    
                                                                    glPushMatrix();
                                                                          glLoadIdentity();
                                                                          //
                                                                          glRotatef(-torso_ROTATE[3], -torso_ROTATE[0], -torso_ROTATE[1], torso_ROTATE[2]);                                                                          
                                                                          glRotatef(-hips_ROTATE[3],  -hips_ROTATE[0],  -hips_ROTATE[1],  hips_ROTATE[2]);                                                                          
                                                                          glRotatef(marcRotation, 0, 1, 0); 
                                                                          glRotatef(-look_LEFT_RIGHT, 0, -1, 0);
                                                                          glTranslatef(-eyePosition[0],-eyePosition[1],-eyePosition[2]);                                                                      
                                                                          glLightfv (GL_LIGHT0,GL_POSITION, lightPos_jetPackEngines);
                                                                          glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, quadraticAttenuation_jetPackEngines);
                                                                    glPopMatrix();     

                                                                    #include "_MODEL_FOLDERS_/jetPack/jetPackTopCones/jetPackTopCones_vboRender.cpp" 
                                                             ////////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

                                                                    #include "_MODEL_FOLDERS_/jetPack/jetPackMiddleEngines/jetPackMiddleEngines_vboRender.cpp"                         
                                                             ////////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    

                                                                    #include "_MODEL_FOLDERS_/jetPack/jetPackNozzels/jetPackNozzels_vboRender.cpp"  
                                                             ////////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
     

                                                                    #include "_MODEL_FOLDERS_/jetPack/jetPackBindings/jetPackBindings_vboRender.cpp"  
                                                             ////////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                                                                

                                                                    
                                                                    #include "_MODEL_FOLDERS_/jetPack/jetPacksideHandles/jetPacksideHandles_vboRender.cpp"  
                                                     
                                                             ////////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 

                                                                    #include "_MODEL_FOLDERS_/jetPack/jetPackVestStraps/jetPackVestStraps_vboRender.cpp"  
                                                    
                                                   
glPopMatrix(); 


}//______________________________________________END_HIDE_SET_DIALOGUE____                                         



//================================================================================================================
                                          //===============================
                                                  glLoadIdentity();
                                          //===============================
//================================================================================================================



if(hideSetPlusDialoque == 0.0)   
{//______________________________________________BEGIN_HIDE_SET_DIALOGUE____



      
/*      glPushMatrix();
              glTranslatef(keyboardLayoutDialogue_POSITION[0], keyboardLayoutDialogue_POSITION[1], keyboardLayoutDialogue_POSITION[2]);
              glRotatef(keyboardLayoutDialogue_ROTATION[3], keyboardLayoutDialogue_ROTATION[0], keyboardLayoutDialogue_ROTATION[1], keyboardLayoutDialogue_ROTATION[2]);
              glScalef(0.9, 0.9, 0.9);
              glActiveTextureARB(GL_TEXTURE0_ARB);
              glBindTexture(GL_TEXTURE_2D, textureMap[540]);
              #include "_MODEL_FOLDERS_/dialogue/keyboardLayoutDialogue_vboRender.cpp"    //vboID = 540
                   glPushMatrix(); 
                       glTranslatef(keyboardLayoutDialogue_VALUES_POSITION[0], keyboardLayoutDialogue_VALUES_POSITION[1], keyboardLayoutDialogue_VALUES_POSITION[2]);
                       glRotatef(180.0, 0.0, 1.0, 0.0);
                       glScalef(3.0, 3.0, 3.0);
                       glColor4f(1.0, 0.0, 0.0, 1.0);
                       printDecimalNumbers(keyboardLayout);
                   glPopMatrix();
      glPopMatrix();
      //------------------------------------------------------------------------------------------------------------------------
      if(keyboardLayout == 1)
      {     
                    glColor4f(1.0, 1.0, 1.0, 1.0);
                    glPushMatrix();
                          glTranslatef(keyboardLeft_POSITION[0], keyboardLeft_POSITION[1], keyboardLeft_POSITION[2]);
                          glRotatef(keyboardLeft_ROTATION[3],keyboardLeft_ROTATION[0], keyboardLeft_ROTATION[1], keyboardLeft_ROTATION[2]);
                          glScalef(keyboard_SCALE[0], keyboard_SCALE[0], keyboard_SCALE[0]);
                          #include "_MODEL_FOLDERS_/dialogue/keyboard/keyboardLeft_vboRender.cpp"   //vboID = 600
                          glTranslatef(keyboardRight_POSITION[0], keyboardRight_POSITION[1], keyboardRight_POSITION[2]);
                          #include "_MODEL_FOLDERS_/dialogue/keyboard/keyboardRight_vboRender.cpp"   //vboID = 601
                    
                    glPopMatrix();
                   
                    
      
      
      }

*/


glColor4f(1.0, 1.0, 1.0, 1.0);
                                    //--------------------------------------------------------------------------------------------------------------
                                    glPushMatrix();
                                         glRotatef(-look_LEFT_RIGHT, 0, 1, 0);               
                                         glRotatef(-look_UP_DOWN, 1, 0, 0); 
                                         glTranslatef(-eyePosition[0], -eyePosition[1], -eyePosition[2]);
                                         glTranslatef(bodyPartSelectIcons_POSITION_01[0], bodyPartSelectIcons_POSITION_01[1], bodyPartSelectIcons_POSITION_01[2]);
                                         glScalef(scalebodyPartSelectIcons, scalebodyPartSelectIcons, scalebodyPartSelectIcons);
                                         glBindBuffer(GL_ARRAY_BUFFER_ARB, keyboardLayoutDialogue_vboID);

                                         glEnableClientState(GL_TEXTURE_COORD_ARRAY );
                                         glEnableClientState(GL_NORMAL_ARRAY);
                                         glEnableClientState(GL_VERTEX_ARRAY);
                                         glTexCoordPointer(3, GL_FLOAT, 0, (void*)(sizeof(keyboardLayoutDialogue_VERT) + sizeof(keyboardLayoutDialogue_NORM)));
                                         glNormalPointer(GL_FLOAT, 0, (void*)sizeof(keyboardLayoutDialogue_VERT));
                                         glVertexPointer(3, GL_FLOAT, 0, 0);

                                         glActiveTextureARB(GL_TEXTURE0_ARB);
                                         glBindTexture(GL_TEXTURE_2D, textureMap[583]);

                                         glDrawArrays(GL_TRIANGLES, 0, 6);

                                         glDisableClientState(GL_VERTEX_ARRAY);
                                         glDisableClientState(GL_NORMAL_ARRAY);
                                         glDisableClientState(GL_TEXTURE_COORD_ARRAY);
                                   glPopMatrix();
                                   //--------------------------------------------------------------------------------------------------------------
                                   glPushMatrix();
                                         glRotatef(-look_LEFT_RIGHT, 0, 1, 0);               
                                         glRotatef(-look_UP_DOWN, 1, 0, 0); 
                                         glTranslatef(-eyePosition[0], -eyePosition[1], -eyePosition[2]);
                                         glTranslatef(bodyPartSelectIcons_POSITION_02[0], bodyPartSelectIcons_POSITION_02[1], bodyPartSelectIcons_POSITION_02[2]);
                                         glScalef(scalebodyPartSelectIcons, scalebodyPartSelectIcons, scalebodyPartSelectIcons);
                                         glBindBuffer(GL_ARRAY_BUFFER_ARB, keyboardLayoutDialogue_vboID);

                                         glEnableClientState(GL_TEXTURE_COORD_ARRAY );
                                         glEnableClientState(GL_NORMAL_ARRAY);
                                         glEnableClientState(GL_VERTEX_ARRAY);
                                         glTexCoordPointer(3, GL_FLOAT, 0, (void*)(sizeof(keyboardLayoutDialogue_VERT) + sizeof(keyboardLayoutDialogue_NORM)));
                                         glNormalPointer(GL_FLOAT, 0, (void*)sizeof(keyboardLayoutDialogue_VERT));
                                         glVertexPointer(3, GL_FLOAT, 0, 0);

                                         glActiveTextureARB(GL_TEXTURE0_ARB);
                                         glBindTexture(GL_TEXTURE_2D, textureMap[584]);

                                         glDrawArrays(GL_TRIANGLES, 0, 6);

                                         glDisableClientState(GL_VERTEX_ARRAY);
                                         glDisableClientState(GL_NORMAL_ARRAY);
                                         glDisableClientState(GL_TEXTURE_COORD_ARRAY);
                                   glPopMatrix();
                                   //--------------------------------------------------------------------------------------------------------------
                                   glPushMatrix();
                                         glRotatef(-look_LEFT_RIGHT, 0, 1, 0);               
                                         glRotatef(-look_UP_DOWN, 1, 0, 0); 
                                         glTranslatef(-eyePosition[0], -eyePosition[1], -eyePosition[2]);
                                         glTranslatef(bodyPartSelectIcons_POSITION_03[0], bodyPartSelectIcons_POSITION_03[1], bodyPartSelectIcons_POSITION_03[2]);
                                         glScalef(scalebodyPartSelectIcons, scalebodyPartSelectIcons, scalebodyPartSelectIcons);
                                         glBindBuffer(GL_ARRAY_BUFFER_ARB, keyboardLayoutDialogue_vboID);

                                         glEnableClientState(GL_TEXTURE_COORD_ARRAY );
                                         glEnableClientState(GL_NORMAL_ARRAY);
                                         glEnableClientState(GL_VERTEX_ARRAY);
                                         glTexCoordPointer(3, GL_FLOAT, 0, (void*)(sizeof(keyboardLayoutDialogue_VERT) + sizeof(keyboardLayoutDialogue_NORM)));
                                         glNormalPointer(GL_FLOAT, 0, (void*)sizeof(keyboardLayoutDialogue_VERT));
                                         glVertexPointer(3, GL_FLOAT, 0, 0);

                                         glActiveTextureARB(GL_TEXTURE0_ARB);
                                         glBindTexture(GL_TEXTURE_2D, textureMap[585]);

                                         glDrawArrays(GL_TRIANGLES, 0, 6);

                                         glDisableClientState(GL_VERTEX_ARRAY);
                                         glDisableClientState(GL_NORMAL_ARRAY);
                                         glDisableClientState(GL_TEXTURE_COORD_ARRAY);
                                   glPopMatrix();
                                   //--------------------------------------------------------------------------------------------------------------
                                   glPushMatrix();
                                         glRotatef(-look_LEFT_RIGHT, 0, 1, 0);               
                                         glRotatef(-look_UP_DOWN, 1, 0, 0); 
                                         glTranslatef(-eyePosition[0], -eyePosition[1], -eyePosition[2]);
                                         glTranslatef(bodyPartSelectIcons_POSITION_04[0], bodyPartSelectIcons_POSITION_04[1], bodyPartSelectIcons_POSITION_04[2]);
                                         glScalef(scalebodyPartSelectIcons, scalebodyPartSelectIcons, scalebodyPartSelectIcons);
                                         glBindBuffer(GL_ARRAY_BUFFER_ARB, keyboardLayoutDialogue_vboID);

                                         glEnableClientState(GL_TEXTURE_COORD_ARRAY );
                                         glEnableClientState(GL_NORMAL_ARRAY);
                                         glEnableClientState(GL_VERTEX_ARRAY);
                                         glTexCoordPointer(3, GL_FLOAT, 0, (void*)(sizeof(keyboardLayoutDialogue_VERT) + sizeof(keyboardLayoutDialogue_NORM)));
                                         glNormalPointer(GL_FLOAT, 0, (void*)sizeof(keyboardLayoutDialogue_VERT));
                                         glVertexPointer(3, GL_FLOAT, 0, 0);

                                         glActiveTextureARB(GL_TEXTURE0_ARB);
                                         glBindTexture(GL_TEXTURE_2D, textureMap[586]);

                                         glDrawArrays(GL_TRIANGLES, 0, 6);

                                         glDisableClientState(GL_VERTEX_ARRAY);
                                         glDisableClientState(GL_NORMAL_ARRAY);
                                         glDisableClientState(GL_TEXTURE_COORD_ARRAY);
                                   glPopMatrix();
                                   //--------------------------------------------------------------------------------------------------------------
                                   glPushMatrix();
                                         glRotatef(-look_LEFT_RIGHT, 0, 1, 0);               
                                         glRotatef(-look_UP_DOWN, 1, 0, 0); 
                                         glTranslatef(-eyePosition[0], -eyePosition[1], -eyePosition[2]);
                                         glTranslatef(bodyPartSelectIcons_POSITION_05[0], bodyPartSelectIcons_POSITION_05[1], bodyPartSelectIcons_POSITION_05[2]);
                                         glScalef(scalebodyPartSelectIcons, scalebodyPartSelectIcons, scalebodyPartSelectIcons);
                                         glBindBuffer(GL_ARRAY_BUFFER_ARB, keyboardLayoutDialogue_vboID);

                                         glEnableClientState(GL_TEXTURE_COORD_ARRAY );
                                         glEnableClientState(GL_NORMAL_ARRAY);
                                         glEnableClientState(GL_VERTEX_ARRAY);
                                         glTexCoordPointer(3, GL_FLOAT, 0, (void*)(sizeof(keyboardLayoutDialogue_VERT) + sizeof(keyboardLayoutDialogue_NORM)));
                                         glNormalPointer(GL_FLOAT, 0, (void*)sizeof(keyboardLayoutDialogue_VERT));
                                         glVertexPointer(3, GL_FLOAT, 0, 0);

                                         glActiveTextureARB(GL_TEXTURE0_ARB);
                                         glBindTexture(GL_TEXTURE_2D, textureMap[587]);

                                         glDrawArrays(GL_TRIANGLES, 0, 6);

                                         glDisableClientState(GL_VERTEX_ARRAY);
                                         glDisableClientState(GL_NORMAL_ARRAY);
                                         glDisableClientState(GL_TEXTURE_COORD_ARRAY);
                                   glPopMatrix();
                                   //--------------------------------------------------------------------------------------------------------------
                                   glPushMatrix();
                                         glRotatef(-look_LEFT_RIGHT, 0, 1, 0);               
                                         glRotatef(-look_UP_DOWN, 1, 0, 0); 
                                         glTranslatef(-eyePosition[0], -eyePosition[1], -eyePosition[2]);
                                         glTranslatef(bodyPartSelectIcons_POSITION_06[0], bodyPartSelectIcons_POSITION_06[1], bodyPartSelectIcons_POSITION_06[2]);
                                         glScalef(scalebodyPartSelectIcons, scalebodyPartSelectIcons, scalebodyPartSelectIcons);
                                         glBindBuffer(GL_ARRAY_BUFFER_ARB, keyboardLayoutDialogue_vboID);

                                         glEnableClientState(GL_TEXTURE_COORD_ARRAY );
                                         glEnableClientState(GL_NORMAL_ARRAY);
                                         glEnableClientState(GL_VERTEX_ARRAY);
                                         glTexCoordPointer(3, GL_FLOAT, 0, (void*)(sizeof(keyboardLayoutDialogue_VERT) + sizeof(keyboardLayoutDialogue_NORM)));
                                         glNormalPointer(GL_FLOAT, 0, (void*)sizeof(keyboardLayoutDialogue_VERT));
                                         glVertexPointer(3, GL_FLOAT, 0, 0);

                                         glActiveTextureARB(GL_TEXTURE0_ARB);
                                         glBindTexture(GL_TEXTURE_2D, textureMap[588]);

                                         glDrawArrays(GL_TRIANGLES, 0, 6);

                                         glDisableClientState(GL_VERTEX_ARRAY);
                                         glDisableClientState(GL_NORMAL_ARRAY);
                                         glDisableClientState(GL_TEXTURE_COORD_ARRAY);
                                   glPopMatrix();
                                   //--------------------------------------------------------------------------------------------------------------                                                                       
                                   glPushMatrix();
                                         glRotatef(-look_LEFT_RIGHT, 0, 1, 0);               
                                         glRotatef(-look_UP_DOWN, 1, 0, 0); 
                                         glTranslatef(-eyePosition[0], -eyePosition[1], -eyePosition[2]);
                                         glTranslatef(bodyPartSelectIcons_POSITION_07[0], bodyPartSelectIcons_POSITION_07[1], bodyPartSelectIcons_POSITION_07[2]);
                                         glScalef(scalebodyPartSelectIcons, scalebodyPartSelectIcons, scalebodyPartSelectIcons);
                                         glBindBuffer(GL_ARRAY_BUFFER_ARB, keyboardLayoutDialogue_vboID);

                                         glEnableClientState(GL_TEXTURE_COORD_ARRAY );
                                         glEnableClientState(GL_NORMAL_ARRAY);
                                         glEnableClientState(GL_VERTEX_ARRAY);
                                         glTexCoordPointer(3, GL_FLOAT, 0, (void*)(sizeof(keyboardLayoutDialogue_VERT) + sizeof(keyboardLayoutDialogue_NORM)));
                                         glNormalPointer(GL_FLOAT, 0, (void*)sizeof(keyboardLayoutDialogue_VERT));
                                         glVertexPointer(3, GL_FLOAT, 0, 0);

                                         glActiveTextureARB(GL_TEXTURE0_ARB);
                                         glBindTexture(GL_TEXTURE_2D, textureMap[589]);

                                         glDrawArrays(GL_TRIANGLES, 0, 6);

                                         glDisableClientState(GL_VERTEX_ARRAY);
                                         glDisableClientState(GL_NORMAL_ARRAY);
                                         glDisableClientState(GL_TEXTURE_COORD_ARRAY);
                                   glPopMatrix();
                                   //--------------------------------------------------------------------------------------------------------------                                                                       
                                   glPushMatrix();
                                         glRotatef(-look_LEFT_RIGHT, 0, 1, 0);               
                                         glRotatef(-look_UP_DOWN, 1, 0, 0); 
                                         glTranslatef(-eyePosition[0], -eyePosition[1], -eyePosition[2]);
                                         glTranslatef(bodyPartSelectIcons_POSITION_08[0], bodyPartSelectIcons_POSITION_08[1], bodyPartSelectIcons_POSITION_08[2]);
                                         glScalef(scalebodyPartSelectIcons, scalebodyPartSelectIcons, scalebodyPartSelectIcons);
                                         glBindBuffer(GL_ARRAY_BUFFER_ARB, keyboardLayoutDialogue_vboID);

                                         glEnableClientState(GL_TEXTURE_COORD_ARRAY );
                                         glEnableClientState(GL_NORMAL_ARRAY);
                                         glEnableClientState(GL_VERTEX_ARRAY);
                                         glTexCoordPointer(3, GL_FLOAT, 0, (void*)(sizeof(keyboardLayoutDialogue_VERT) + sizeof(keyboardLayoutDialogue_NORM)));
                                         glNormalPointer(GL_FLOAT, 0, (void*)sizeof(keyboardLayoutDialogue_VERT));
                                         glVertexPointer(3, GL_FLOAT, 0, 0);

                                         glActiveTextureARB(GL_TEXTURE0_ARB);
                                         glBindTexture(GL_TEXTURE_2D, textureMap[590]);

                                         glDrawArrays(GL_TRIANGLES, 0, 6);

                                         glDisableClientState(GL_VERTEX_ARRAY);
                                         glDisableClientState(GL_NORMAL_ARRAY);
                                         glDisableClientState(GL_TEXTURE_COORD_ARRAY);
                                   glPopMatrix();
                                   //--------------------------------------------------------------------------------------------------------------                                                                       
                                   glPushMatrix();
                                         glRotatef(-look_LEFT_RIGHT, 0, 1, 0);               
                                         glRotatef(-look_UP_DOWN, 1, 0, 0); 
                                         glTranslatef(-eyePosition[0], -eyePosition[1], -eyePosition[2]);
                                         glTranslatef(bodyPartSelectIcons_POSITION_09[0], bodyPartSelectIcons_POSITION_09[1], bodyPartSelectIcons_POSITION_09[2]);
                                         glScalef(scalebodyPartSelectIcons, scalebodyPartSelectIcons, scalebodyPartSelectIcons);
                                         glBindBuffer(GL_ARRAY_BUFFER_ARB, keyboardLayoutDialogue_vboID);

                                         glEnableClientState(GL_TEXTURE_COORD_ARRAY );
                                         glEnableClientState(GL_NORMAL_ARRAY);
                                         glEnableClientState(GL_VERTEX_ARRAY);
                                         glTexCoordPointer(3, GL_FLOAT, 0, (void*)(sizeof(keyboardLayoutDialogue_VERT) + sizeof(keyboardLayoutDialogue_NORM)));
                                         glNormalPointer(GL_FLOAT, 0, (void*)sizeof(keyboardLayoutDialogue_VERT));
                                         glVertexPointer(3, GL_FLOAT, 0, 0);

                                         glActiveTextureARB(GL_TEXTURE0_ARB);
                                         glBindTexture(GL_TEXTURE_2D, textureMap[591]);

                                         glDrawArrays(GL_TRIANGLES, 0, 6);

                                         glDisableClientState(GL_VERTEX_ARRAY);
                                         glDisableClientState(GL_NORMAL_ARRAY);
                                         glDisableClientState(GL_TEXTURE_COORD_ARRAY);
                                   glPopMatrix();
                                   //--------------------------------------------------------------------------------------------------------------                                                                       
                                   glPushMatrix();
                                         glRotatef(-look_LEFT_RIGHT, 0, 1, 0);               
                                         glRotatef(-look_UP_DOWN, 1, 0, 0); 
                                         glTranslatef(-eyePosition[0], -eyePosition[1], -eyePosition[2]);
                                         glTranslatef(bodyPartSelectIcons_POSITION_10[0], bodyPartSelectIcons_POSITION_10[1], bodyPartSelectIcons_POSITION_10[2]);
                                         glScalef(scalebodyPartSelectIcons, scalebodyPartSelectIcons, scalebodyPartSelectIcons);
                                         glBindBuffer(GL_ARRAY_BUFFER_ARB, keyboardLayoutDialogue_vboID);

                                         glEnableClientState(GL_TEXTURE_COORD_ARRAY );
                                         glEnableClientState(GL_NORMAL_ARRAY);
                                         glEnableClientState(GL_VERTEX_ARRAY);
                                         glTexCoordPointer(3, GL_FLOAT, 0, (void*)(sizeof(keyboardLayoutDialogue_VERT) + sizeof(keyboardLayoutDialogue_NORM)));
                                         glNormalPointer(GL_FLOAT, 0, (void*)sizeof(keyboardLayoutDialogue_VERT));
                                         glVertexPointer(3, GL_FLOAT, 0, 0);

                                         glActiveTextureARB(GL_TEXTURE0_ARB);
                                         glBindTexture(GL_TEXTURE_2D, textureMap[592]);

                                         glDrawArrays(GL_TRIANGLES, 0, 6);

                                         glDisableClientState(GL_VERTEX_ARRAY);
                                         glDisableClientState(GL_NORMAL_ARRAY);
                                         glDisableClientState(GL_TEXTURE_COORD_ARRAY);
                                   glPopMatrix();
                                   //--------------------------------------------------------------------------------------------------------------                                                                       
                                   glPushMatrix();
                                         glRotatef(-look_LEFT_RIGHT, 0, 1, 0);               
                                         glRotatef(-look_UP_DOWN, 1, 0, 0); 
                                         glTranslatef(-eyePosition[0], -eyePosition[1], -eyePosition[2]);
                                         glTranslatef(bodyPartSelectIcons_POSITION_11[0], bodyPartSelectIcons_POSITION_11[1], bodyPartSelectIcons_POSITION_11[2]);
                                         glScalef(scalebodyPartSelectIcons, scalebodyPartSelectIcons, scalebodyPartSelectIcons);
                                         glBindBuffer(GL_ARRAY_BUFFER_ARB, keyboardLayoutDialogue_vboID);

                                         glEnableClientState(GL_TEXTURE_COORD_ARRAY );
                                         glEnableClientState(GL_NORMAL_ARRAY);
                                         glEnableClientState(GL_VERTEX_ARRAY);
                                         glTexCoordPointer(3, GL_FLOAT, 0, (void*)(sizeof(keyboardLayoutDialogue_VERT) + sizeof(keyboardLayoutDialogue_NORM)));
                                         glNormalPointer(GL_FLOAT, 0, (void*)sizeof(keyboardLayoutDialogue_VERT));
                                         glVertexPointer(3, GL_FLOAT, 0, 0);

                                         glActiveTextureARB(GL_TEXTURE0_ARB);
                                         glBindTexture(GL_TEXTURE_2D, textureMap[593]);

                                         glDrawArrays(GL_TRIANGLES, 0, 6);

                                         glDisableClientState(GL_VERTEX_ARRAY);
                                         glDisableClientState(GL_NORMAL_ARRAY);
                                         glDisableClientState(GL_TEXTURE_COORD_ARRAY);
                                   glPopMatrix();
                                   //--------------------------------------------------------------------------------------------------------------                                                                                                                             
                                   glPushMatrix();
                                         glRotatef(-look_LEFT_RIGHT, 0, 1, 0);               
                                         glRotatef(-look_UP_DOWN, 1, 0, 0); 
                                         glTranslatef(-eyePosition[0], -eyePosition[1], -eyePosition[2]);
                                         glTranslatef(bodyPartSelectIcons_POSITION_12[0], bodyPartSelectIcons_POSITION_12[1], bodyPartSelectIcons_POSITION_12[2]);
                                         glScalef(scalebodyPartSelectIcons, scalebodyPartSelectIcons, scalebodyPartSelectIcons);
                                         glBindBuffer(GL_ARRAY_BUFFER_ARB, keyboardLayoutDialogue_vboID);

                                         glEnableClientState(GL_TEXTURE_COORD_ARRAY );
                                         glEnableClientState(GL_NORMAL_ARRAY);
                                         glEnableClientState(GL_VERTEX_ARRAY);
                                         glTexCoordPointer(3, GL_FLOAT, 0, (void*)(sizeof(keyboardLayoutDialogue_VERT) + sizeof(keyboardLayoutDialogue_NORM)));
                                         glNormalPointer(GL_FLOAT, 0, (void*)sizeof(keyboardLayoutDialogue_VERT));
                                         glVertexPointer(3, GL_FLOAT, 0, 0);

                                         glActiveTextureARB(GL_TEXTURE0_ARB);
                                         glBindTexture(GL_TEXTURE_2D, textureMap[594]);

                                         glDrawArrays(GL_TRIANGLES, 0, 6);

                                         glDisableClientState(GL_VERTEX_ARRAY);
                                         glDisableClientState(GL_NORMAL_ARRAY);
                                         glDisableClientState(GL_TEXTURE_COORD_ARRAY);
                                   glPopMatrix();
                                   //--------------------------------------------------------------------------------------------------------------                                                                                                                             
                                   glPushMatrix();
                                         glRotatef(-look_LEFT_RIGHT, 0, 1, 0);               
                                         glRotatef(-look_UP_DOWN, 1, 0, 0); 
                                         glTranslatef(-eyePosition[0], -eyePosition[1], -eyePosition[2]);
                                         glTranslatef(bodyPartSelectIcons_POSITION_13[0], bodyPartSelectIcons_POSITION_13[1], bodyPartSelectIcons_POSITION_13[2]);
                                         glScalef(scalebodyPartSelectIcons, scalebodyPartSelectIcons, scalebodyPartSelectIcons);
                                         glBindBuffer(GL_ARRAY_BUFFER_ARB, keyboardLayoutDialogue_vboID);

                                         glEnableClientState(GL_TEXTURE_COORD_ARRAY );
                                         glEnableClientState(GL_NORMAL_ARRAY);
                                         glEnableClientState(GL_VERTEX_ARRAY);
                                         glTexCoordPointer(3, GL_FLOAT, 0, (void*)(sizeof(keyboardLayoutDialogue_VERT) + sizeof(keyboardLayoutDialogue_NORM)));
                                         glNormalPointer(GL_FLOAT, 0, (void*)sizeof(keyboardLayoutDialogue_VERT));
                                         glVertexPointer(3, GL_FLOAT, 0, 0);

                                         glActiveTextureARB(GL_TEXTURE0_ARB);
                                         glBindTexture(GL_TEXTURE_2D, textureMap[595]);

                                         glDrawArrays(GL_TRIANGLES, 0, 6);

                                         glDisableClientState(GL_VERTEX_ARRAY);
                                         glDisableClientState(GL_NORMAL_ARRAY);
                                         glDisableClientState(GL_TEXTURE_COORD_ARRAY);
                                   glPopMatrix();
                                   //--------------------------------------------------------------------------------------------------------------                                                                                                                             
                                   glPushMatrix();
                                         glRotatef(-look_LEFT_RIGHT, 0, 1, 0);               
                                         glRotatef(-look_UP_DOWN, 1, 0, 0); 
                                         glTranslatef(-eyePosition[0], -eyePosition[1], -eyePosition[2]);
                                         glTranslatef(bodyPartSelectIcons_POSITION_14[0], bodyPartSelectIcons_POSITION_14[1], bodyPartSelectIcons_POSITION_14[2]);
                                         glScalef(scalebodyPartSelectIcons, scalebodyPartSelectIcons, scalebodyPartSelectIcons);
                                         glBindBuffer(GL_ARRAY_BUFFER_ARB, keyboardLayoutDialogue_vboID);

                                         glEnableClientState(GL_TEXTURE_COORD_ARRAY );
                                         glEnableClientState(GL_NORMAL_ARRAY);
                                         glEnableClientState(GL_VERTEX_ARRAY);
                                         glTexCoordPointer(3, GL_FLOAT, 0, (void*)(sizeof(keyboardLayoutDialogue_VERT) + sizeof(keyboardLayoutDialogue_NORM)));
                                         glNormalPointer(GL_FLOAT, 0, (void*)sizeof(keyboardLayoutDialogue_VERT));
                                         glVertexPointer(3, GL_FLOAT, 0, 0);

                                         glActiveTextureARB(GL_TEXTURE0_ARB);
                                         glBindTexture(GL_TEXTURE_2D, textureMap[596]);

                                         glDrawArrays(GL_TRIANGLES, 0, 6);

                                         glDisableClientState(GL_VERTEX_ARRAY);
                                         glDisableClientState(GL_NORMAL_ARRAY);
                                         glDisableClientState(GL_TEXTURE_COORD_ARRAY);
                                   glPopMatrix();
                                   //--------------------------------------------------------------------------------------------------------------                                                                                                                             

                                   glPushMatrix();
                                         glRotatef(-look_LEFT_RIGHT, 0, 1, 0);               
                                         glRotatef(-look_UP_DOWN, 1, 0, 0); 
                                         glTranslatef(-eyePosition[0], -eyePosition[1], -eyePosition[2]);
                                         glTranslatef(bodyPartSelectIcons_POSITION_15[0], bodyPartSelectIcons_POSITION_15[1], bodyPartSelectIcons_POSITION_15[2]);
                                         glScalef(scalebodyPartSelectIcons, scalebodyPartSelectIcons, scalebodyPartSelectIcons);
                                         glBindBuffer(GL_ARRAY_BUFFER_ARB, keyboardLayoutDialogue_vboID);

                                         glEnableClientState(GL_TEXTURE_COORD_ARRAY );
                                         glEnableClientState(GL_NORMAL_ARRAY);
                                         glEnableClientState(GL_VERTEX_ARRAY);
                                         glTexCoordPointer(3, GL_FLOAT, 0, (void*)(sizeof(keyboardLayoutDialogue_VERT) + sizeof(keyboardLayoutDialogue_NORM)));
                                         glNormalPointer(GL_FLOAT, 0, (void*)sizeof(keyboardLayoutDialogue_VERT));
                                         glVertexPointer(3, GL_FLOAT, 0, 0);

                                         glActiveTextureARB(GL_TEXTURE0_ARB);
                                         glBindTexture(GL_TEXTURE_2D, textureMap[597]);

                                         glDrawArrays(GL_TRIANGLES, 0, 6);

                                         glDisableClientState(GL_VERTEX_ARRAY);
                                         glDisableClientState(GL_NORMAL_ARRAY);
                                         glDisableClientState(GL_TEXTURE_COORD_ARRAY);
                                   glPopMatrix();
                                   //--------------------------------------------------------------------------------------------------------------                                                                                                                             


//==================================================================================================================================================                               
                                    glColor4f(1.0, 1.0, 1.0, 1.0);
                                    //--------------------------------------------------------------------------------------------------------------
                                    glPushMatrix();
                                         glRotatef(-look_LEFT_RIGHT, 0, 1, 0);               
                                         glRotatef(-look_UP_DOWN, 1, 0, 0); 
                                         glTranslatef(-eyePosition[0], -eyePosition[1], -eyePosition[2]);
                                         glTranslatef(poseIcons_POSITION[0], poseIcons_POSITION[1], poseIcons_POSITION[2]);
                                         glScalef(scalePoseIcons, scalePoseIcons, scalePoseIcons);
                                         glBindBuffer(GL_ARRAY_BUFFER_ARB, keyboardLayoutDialogue_vboID);

                                         glEnableClientState(GL_TEXTURE_COORD_ARRAY );
                                         glEnableClientState(GL_NORMAL_ARRAY);
                                         glEnableClientState(GL_VERTEX_ARRAY);
                                         glTexCoordPointer(3, GL_FLOAT, 0, (void*)(sizeof(keyboardLayoutDialogue_VERT) + sizeof(keyboardLayoutDialogue_NORM)));
                                         glNormalPointer(GL_FLOAT, 0, (void*)sizeof(keyboardLayoutDialogue_VERT));
                                         glVertexPointer(3, GL_FLOAT, 0, 0);

                                         glActiveTextureARB(GL_TEXTURE0_ARB);
                                         glBindTexture(GL_TEXTURE_2D, textureMap[541]);

                                         glDrawArrays(GL_TRIANGLES, 0, 6);

                                         glDisableClientState(GL_VERTEX_ARRAY);
                                         glDisableClientState(GL_NORMAL_ARRAY);
                                         glDisableClientState(GL_TEXTURE_COORD_ARRAY);
                                   glPopMatrix();
                                   //--------------------------------------------------------------------------------------------------------------
                                    glColor4f(1.0, 1.0, 1.0, 1.0);
                                    //--------------------------------------------------------------------------------------------------------------
                                    glPushMatrix();
                                         glRotatef(-look_LEFT_RIGHT, 0, 1, 0);               
                                         glRotatef(-look_UP_DOWN, 1, 0, 0); 
                                         glTranslatef(-eyePosition[0], -eyePosition[1], -eyePosition[2]);
                                         glTranslatef(poseIcons_POSITION_02[0], poseIcons_POSITION_02[1], poseIcons_POSITION_02[2]);
                                         glScalef(scalePoseIcons, scalePoseIcons, scalePoseIcons);
                                         glBindBuffer(GL_ARRAY_BUFFER_ARB, keyboardLayoutDialogue_vboID);

                                         glEnableClientState(GL_TEXTURE_COORD_ARRAY );
                                         glEnableClientState(GL_NORMAL_ARRAY);
                                         glEnableClientState(GL_VERTEX_ARRAY);
                                         glTexCoordPointer(3, GL_FLOAT, 0, (void*)(sizeof(keyboardLayoutDialogue_VERT) + sizeof(keyboardLayoutDialogue_NORM)));
                                         glNormalPointer(GL_FLOAT, 0, (void*)sizeof(keyboardLayoutDialogue_VERT));
                                         glVertexPointer(3, GL_FLOAT, 0, 0);

                                         glActiveTextureARB(GL_TEXTURE0_ARB);
                                         glBindTexture(GL_TEXTURE_2D, textureMap[542]);

                                         glDrawArrays(GL_TRIANGLES, 0, 6);

                                         glDisableClientState(GL_VERTEX_ARRAY);
                                         glDisableClientState(GL_NORMAL_ARRAY);
                                         glDisableClientState(GL_TEXTURE_COORD_ARRAY);
                                   glPopMatrix();
                                   //--------------------------------------------------------------------------------------------------------------
                                    glPushMatrix();
                                         glRotatef(-look_LEFT_RIGHT, 0, 1, 0);               
                                         glRotatef(-look_UP_DOWN, 1, 0, 0); 
                                         glTranslatef(-eyePosition[0], -eyePosition[1], -eyePosition[2]);
                                         glTranslatef(poseIcons_POSITION_03[0], poseIcons_POSITION_03[1], poseIcons_POSITION_03[2]);
                                         glScalef(scalePoseIcons, scalePoseIcons, scalePoseIcons);
                                         glBindBuffer(GL_ARRAY_BUFFER_ARB, keyboardLayoutDialogue_vboID);

                                         glEnableClientState(GL_TEXTURE_COORD_ARRAY );
                                         glEnableClientState(GL_NORMAL_ARRAY);
                                         glEnableClientState(GL_VERTEX_ARRAY);
                                         glTexCoordPointer(3, GL_FLOAT, 0, (void*)(sizeof(keyboardLayoutDialogue_VERT) + sizeof(keyboardLayoutDialogue_NORM)));
                                         glNormalPointer(GL_FLOAT, 0, (void*)sizeof(keyboardLayoutDialogue_VERT));
                                         glVertexPointer(3, GL_FLOAT, 0, 0);

                                         glActiveTextureARB(GL_TEXTURE0_ARB);
                                         glBindTexture(GL_TEXTURE_2D, textureMap[543]);

                                         glDrawArrays(GL_TRIANGLES, 0, 6);

                                         glDisableClientState(GL_VERTEX_ARRAY);
                                         glDisableClientState(GL_NORMAL_ARRAY);
                                         glDisableClientState(GL_TEXTURE_COORD_ARRAY);
                                   glPopMatrix();
                                //--------------------------------------------------------------------------------------------------------------
                                   glPushMatrix();
                                         glRotatef(-look_LEFT_RIGHT, 0, 1, 0);               
                                         glRotatef(-look_UP_DOWN, 1, 0, 0); 
                                         glTranslatef(-eyePosition[0], -eyePosition[1], -eyePosition[2]);
                                         glTranslatef(poseIcons_POSITION_04[0], poseIcons_POSITION_04[1], poseIcons_POSITION_04[2]);
                                         glScalef(scalePoseIcons, scalePoseIcons, scalePoseIcons);
                                         glBindBuffer(GL_ARRAY_BUFFER_ARB, keyboardLayoutDialogue_vboID);

                                         glEnableClientState(GL_TEXTURE_COORD_ARRAY );
                                         glEnableClientState(GL_NORMAL_ARRAY);
                                         glEnableClientState(GL_VERTEX_ARRAY);
                                         glTexCoordPointer(3, GL_FLOAT, 0, (void*)(sizeof(keyboardLayoutDialogue_VERT) + sizeof(keyboardLayoutDialogue_NORM)));
                                         glNormalPointer(GL_FLOAT, 0, (void*)sizeof(keyboardLayoutDialogue_VERT));
                                         glVertexPointer(3, GL_FLOAT, 0, 0);

                                         glActiveTextureARB(GL_TEXTURE0_ARB);
                                         glBindTexture(GL_TEXTURE_2D, textureMap[544]);

                                         glDrawArrays(GL_TRIANGLES, 0, 6);

                                         glDisableClientState(GL_VERTEX_ARRAY);
                                         glDisableClientState(GL_NORMAL_ARRAY);
                                         glDisableClientState(GL_TEXTURE_COORD_ARRAY);
                                   glPopMatrix();
                                   //--------------------------------------------------------------------------------------------------------------
                                   glPushMatrix();
                                         glRotatef(-look_LEFT_RIGHT, 0, 1, 0);               
                                         glRotatef(-look_UP_DOWN, 1, 0, 0); 
                                         glTranslatef(-eyePosition[0], -eyePosition[1], -eyePosition[2]);
                                         glTranslatef(poseIcons_POSITION_05[0], poseIcons_POSITION_05[1], poseIcons_POSITION_05[2]);
                                         glScalef(scalePoseIcons, scalePoseIcons, scalePoseIcons);
                                         glBindBuffer(GL_ARRAY_BUFFER_ARB, keyboardLayoutDialogue_vboID);

                                         glEnableClientState(GL_TEXTURE_COORD_ARRAY );
                                         glEnableClientState(GL_NORMAL_ARRAY);
                                         glEnableClientState(GL_VERTEX_ARRAY);
                                         glTexCoordPointer(3, GL_FLOAT, 0, (void*)(sizeof(keyboardLayoutDialogue_VERT) + sizeof(keyboardLayoutDialogue_NORM)));
                                         glNormalPointer(GL_FLOAT, 0, (void*)sizeof(keyboardLayoutDialogue_VERT));
                                         glVertexPointer(3, GL_FLOAT, 0, 0);

                                         glActiveTextureARB(GL_TEXTURE0_ARB);
                                         glBindTexture(GL_TEXTURE_2D, textureMap[545]);

                                         glDrawArrays(GL_TRIANGLES, 0, 6);

                                         glDisableClientState(GL_VERTEX_ARRAY);
                                         glDisableClientState(GL_NORMAL_ARRAY);
                                         glDisableClientState(GL_TEXTURE_COORD_ARRAY);
                                   glPopMatrix();

                  //========================================================================================================================================================
                    glRotatef(-look_LEFT_RIGHT, 0 , 1, 0); 
                    glRotatef(-look_UP_DOWN, 1, 0, 0); 
                    
                    glColor4f(1.0, 1.0, 1.0, 1.0);
                    glPushMatrix();
                           glTranslatef(hideSet_POSITION[0], hideSet_POSITION[1],     hideSet_POSITION[2]);
                           glRotatef(hideSet_ROTATION[3], hideSet_ROTATION[0], hideSet_ROTATION[1], hideSet_ROTATION[2]);
                           glScalef(scaleHideSetDialoque[0], scaleHideSetDialoque[0], scaleHideSetDialoque[0]);
                           glActiveTextureARB(GL_TEXTURE0_ARB);
                           glBindTexture(GL_TEXTURE_2D, textureMap[580]);
                           #include "_MODEL_FOLDERS_/dialogue/keyboardLayoutDialogue_vboRender.cpp"    //vboID = 580
                    glPopMatrix();
                  //--------------------------------------------------------------------------------------------------------------      
                    glPushMatrix();
                         glTranslatef(hips_POSITION[0], hips_POSITION[1], hips_POSITION[2]);                                                
                         glTranslatef(F1_F8_POSITION[0], F1_F8_POSITION[1], F1_F8_POSITION[2]);
                         glRotatef(rotation_AXIS_F1_F8[3],rotation_AXIS_F1_F8[0], rotation_AXIS_F1_F8[1], rotation_AXIS_F1_F8[2]);

                         glPushMatrix();
                              glLoadIdentity();
                              //_ADDITIONAL_ROTATIONS_GO_HERE
                              glRotatef(rotation_AXIS_F1_F8[3],rotation_AXIS_F1_F8[0], rotation_AXIS_F1_F8[1], rotation_AXIS_F1_F8[2]);
                              glLightfv(GL_LIGHT0,GL_POSITION,lightPos_F1_F8);
                              glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_F1_F8);
                         glPopMatrix();
                         #include "_MODEL_FOLDERS_/F1_F8/F1_F8_vboRender.cpp"   //vboID = 573
                    glPopMatrix();  
                  //========================================================================================================================================================





}//______________________________________________END_HIDE_SET_DIALOGUE____


//================================================================================================================
                                          //===============================
                                                  glLoadIdentity();
                                          //===============================
//================================================================================================================


if(hideSetPlusDialoque == 1.0)   
{//______________________________________________BEGIN_HIDE_SET_DIALOGUE---
              //glUseProgramObjectARB(marcDisplay_4view_SHADER);


                              
                               glRotatef(-look_LEFT_RIGHT, 0 , 1, 0); 
                               glRotatef(-look_UP_DOWN, 1, 0, 0); 
                             


              glEnable(GL_TEXTURE_2D);
              glEnable(GL_DEPTH_TEST);
 
                  glColor4f(1.0, 1.0, 1.0, 1.0); 
          
             glUseProgramObjectARB(marcTorso_SHADER);
             
             glLightfv(GL_LIGHT0,GL_POSITION,lightPos_marcTorso);
             glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_marcTorso);
            

       //==========================================================================================================================================
       glPushMatrix();
          
             glTranslatef(moveAllFour[0], moveAllFour[1], moveAllFour[2]);
             glTranslatef(marc_TOP_VIEW[0], marc_TOP_VIEW[1], marc_TOP_VIEW[2]);
             glRotatef( 97, 1, 0, 0); 
             glRotatef( -6, 0, 0, 1);
             //---------------------------------------
             lightPos_marcTorso[0]   =   lightPos_marc_TOP_VIEW[0];
             lightPos_marcTorso[1]   =   lightPos_marc_TOP_VIEW[1];      
             lightPos_marcTorso[2]   =   lightPos_marc_TOP_VIEW[2];
             //---------------------------------------
             #include "render_4_view.cpp"  
             
       glPopMatrix();
       //----------------------------------------------------------------------------------------------------------
       glPushMatrix();             
          
             glTranslatef(moveAllFour[0], moveAllFour[1], moveAllFour[2]);
             glTranslatef(marc_PERSPECTIVE_VIEW[0], marc_PERSPECTIVE_VIEW[1], marc_PERSPECTIVE_VIEW[2]);
             
             glRotatef(70, 1, 0, 0); 
             glRotatef(-45, 0, 1, 0); 
             glRotatef(20, 0, 0, 1); 
             //---------------------------------------
             lightPos_marcTorso[0]   =   lightPos_marc_PERSPECTIVE_VIEW[0];
             lightPos_marcTorso[1]   =   lightPos_marc_PERSPECTIVE_VIEW[1];      
             lightPos_marcTorso[2]   =   lightPos_marc_PERSPECTIVE_VIEW[2];
             //---------------------------------------
             #include "render_4_view.cpp"                
             
       glPopMatrix();
       //----------------------------------------------------------------------------------------------------------     
       glPushMatrix();            
          
             glTranslatef(moveAllFour[0], moveAllFour[1], moveAllFour[2]);
             glTranslatef(marc_FRONT_VIEW[0], marc_FRONT_VIEW[1], marc_FRONT_VIEW[2]);
             glRotatef( 7, 0, 1, 0); 
             //---------------------------------------
             lightPos_marcTorso[0]   =   lightPos_marc_FRONT_VIEW[0];
             lightPos_marcTorso[1]   =   lightPos_marc_FRONT_VIEW[1];      
             lightPos_marcTorso[2]   =   lightPos_marc_FRONT_VIEW[2];
             //---------------------------------------             
             #include "render_4_view.cpp"  

       glPopMatrix();      
       //----------------------------------------------------------------------------------------------------------     
       glPushMatrix();           
             glTranslatef(moveAllFour[0], moveAllFour[1], moveAllFour[2]);
             glTranslatef(marc_SIDE_VIEW[0], marc_SIDE_VIEW[1], marc_SIDE_VIEW[2]);
             glRotatef(-90, 0, 1, 0); 
             //---------------------------------------
             lightPos_marcTorso[0]   =   lightPos_marc_SIDE_VIEW[0];
             lightPos_marcTorso[1]   =   lightPos_marc_SIDE_VIEW[1];      
             lightPos_marcTorso[2]   =   lightPos_marc_SIDE_VIEW[2];
             //---------------------------------------             
             #include "render_4_view.cpp"                
      
       glPopMatrix();
//================================================================================================================
                                          //===============================
                                                  glLoadIdentity();
                                          //===============================
//================================================================================================================

       glRotatef(-look_LEFT_RIGHT, 0 , 1, 0); 
       glRotatef(-look_UP_DOWN, 1, 0, 0);

       glDisable(GL_TEXTURE_2D);
       glDisable(GL_CULL_FACE);
       glColor3f(1.0,1.0,1.0);
       
       glTranslatef(moveOutLine[0], moveOutLine[1], moveOutLine[2]);
       glBegin(GL_LINES);
            glVertex3f(-1.0,  1.0, -2.0);
            glVertex3f( 1.0,  1.0, -2.0);
            glVertex3f( 1.0, -1.0, -2.0);
            glVertex3f(-1.0, -1.0, -2.0);
       glEnd();

       glEnable(GL_CULL_FACE);
       glEnable(GL_TEXTURE_2D);

}











SwapBuffers( hDC );

}

/////////////_____ProcessKeyboard()________ProcessKeyboard()_________ProcessKeyboard()______ProcessKeyboard()___////////////////
/////////////_____ProcessKeyboard()________ProcessKeyboard()_________ProcessKeyboard()______ProcessKeyboard()___////////////////
/////////////_____ProcessKeyboard()________ProcessKeyboard()_________ProcessKeyboard()______ProcessKeyboard()___////////////////
/////////////_____ProcessKeyboard()________ProcessKeyboard()_________ProcessKeyboard()______ProcessKeyboard()___////////////////

bool H_isPressed = false;

void ProcessKeyboard()								
{
//////////////////////////////////////_______________LIGHT_POS   
   
   
/*
    if (keys['D']) 			
	{
           marc_TOP_VIEW[0]                     +=   .01;
    }
    if (keys['A']) 			
    {
           marc_TOP_VIEW[0]                     -=   .01;
    }
    if (keys['W']) 			
	{
           marc_TOP_VIEW[1]                    +=   .01;
    }
    if (keys['S']) 				
    {
           marc_TOP_VIEW[1]                    -=   .01;
    }
    if (keys['E']) 			
	{
           marc_TOP_VIEW[2]                    +=   .01;
    }
    if (keys['Q']) 				
    {
           marc_TOP_VIEW[2]                    -=   .01;
    }  
//============================================================================================================
    if (keys['L']) 			
	{
           marc_PERSPECTIVE_VIEW[0]                     +=   .01;
    }
    if (keys['J']) 			
    {
           marc_PERSPECTIVE_VIEW[0]                     -=   .01;
    }
    if (keys['I']) 			
	{
           marc_PERSPECTIVE_VIEW[1]                    +=   .01;
    }
    if (keys['K']) 				
    {
           marc_PERSPECTIVE_VIEW[1]                    -=   .01;
    }
    if (keys['O']) 			
	{
           marc_PERSPECTIVE_VIEW[2]                    +=   .01;
    }
    if (keys['U']) 				
    {
           marc_PERSPECTIVE_VIEW[2]                    -=   .01;
    } 
*/    
    if (keys['D']) 			
	{
           moveOutLine[0]                     +=   0.01;
    }
    if (keys['A']) 			
    {
           moveOutLine[0]                     -=   0.01;
    }
    if (keys['W']) 			
	{
           moveOutLine[1]                    +=   0.01;
    }
    if (keys['S']) 				
    {
           moveOutLine[1]                    -=   0.01;
    }
    if (keys['E']) 			
	{
           moveOutLine[2]                    +=   0.01;
    }
    if (keys['Q']) 				
    {
           moveOutLine[2]                    -=   0.01;
    }  
//============================================================================================================
/*    if (keys['L']) 			
	{
           hideSet_POSITION[0]                     +=   .01;
    }
    if (keys['J']) 			
    {
           hideSet_POSITION[0]                     -=   .01;
    }
    if (keys['I']) 			
	{
           hideSet_POSITION[1]                    +=   .01;
    }
    if (keys['K']) 				
    {
           hideSet_POSITION[1]                    -=   .01;
    }
    if (keys['O']) 			
	{
           hideSet_POSITION[2]                    +=   .01;
    }
    if (keys['U']) 				
    {
           hideSet_POSITION[2]                    -=   .01;
    } 
*/  

//#include "_MODEL_FOLDERS_/iconPlates_x4/iconPlates_x4_Keyboard.cpp"                                                               
//====================================================================================                                          
 
 
 
//============================================================================================================    
    if (keys['N']) 			
	{
         lightAttenuation_4view += .01;
    }
    if (keys['M']) 			
    {
         lightAttenuation_4view -= .01;
    }  
    //--------------------------------------------------------------------------------------   
	if (keys['X']) 			
	{
         rotateTemp1            += 1.01;
    }
    if (keys['Z']) 			
    {
         rotateTemp1            -= 1.01;
    }
	//--------------------------------------------------------------------------------------
    if (keys['V']) 			
	{
         rotateTemp2            += 1.01;
    }
    if (keys['C']) 			
    {
         rotateTemp2            -= 1.01;
    } 
    
    
    //======================================================================================================================================   
    if (keys[VK_F8]) 			
	{
        ofstream out("lightPosition.cpp");
        
        F8_isSet                             = 1.0;  
        
        
        out << "                             GLfloat     moveOutLine[]                 =  {"  << moveOutLine[0]   << ", "   << moveOutLine[1] << ", " << moveOutLine [2] << "};\n"; 
        out << "                             GLfloat     hideSet_POSITION[]       =  {"  << hideSet_POSITION[0]   << ", "   << hideSet_POSITION[1] << ", " << hideSet_POSITION [2] << "};\n";             
              
       
       out << "                             GLfloat     lightAttenuation_4view    =       "  << lightAttenuation_4view   << ";\n";         
        
        out << "                             GLfloat     rotateTemp1               =       "  << rotateTemp1              << ";\n";         
                
        out << "                             GLfloat     rotateTemp2               =       "  << rotateTemp2              << ";\n";         
                
        
        //out << "                             GLfloat     MaterialShininess_marcTorso         =       "  << MaterialShininess_marcTorso  << ";\n";         

        //--------------------------------------------------------------------------------------        
        out << " //--------------------------------------------------------------------------------------"<< ";\n";    
        out << "   look_LEFT_RIGHT = "  << look_LEFT_RIGHT   << ";\n";
        out << "   look_UP_DOWN    = "  << look_UP_DOWN      << ";\n";
        out << "   eyePosition[0]  = "  << eyePosition[0]    << ";\n";
        out << "   eyePosition[1]  = "  << eyePosition[1]    << ";\n";
        out << "   eyePosition[2]  = "  << eyePosition[2]    << ";\n";
        //--------------------------------------------------------------------------------------          
        out << " //--------------------------------------------------------------------------------------"<< ";\n";    
        out << "   hips_POSITION[0]  = "  << hips_POSITION[0]    << ";\n";
        out << "   hips_POSITION[1]  = "  << hips_POSITION[1]    << ";\n";
        out << "   hips_POSITION[2]  = "  << hips_POSITION[2]    << ";\n";        
        //--------------------------------------------------------------------------------------   
        out << " //--------------------------------------------------------------------------------------"<< ";\n";          
        out << "   shadows_TextureDisplacement_X = " << shadows_TextureDisplacement_X << ";\n"; 
        out << "   shadows_TextureDisplacement_Y = " << shadows_TextureDisplacement_Y << ";\n";         
        out << " //--------------------------------------------------------------------------------------"<< ";\n";          
        //--------------------------------------------------------------------------------------            
    }
    //======================================================================================================================================   
    if (keys[VK_F9]) 			
	{
           ofstream outPose("modelPose.cpp");
        
              
           
           outPose   <<    "                    hips_ROTATE[3]             = " <<  hips_ROTATE[3] << ";\n";
           outPose   <<    "                    hips_ROTATE[0]             = " <<   hips_ROTATE[0] << ";\n";
           outPose   <<    "                    hips_ROTATE[1]             = " <<  hips_ROTATE[1]<< ";\n";
           outPose   <<    "                    hips_ROTATE[2]             = " <<   hips_ROTATE[2] << ";\n\n";
               
           outPose   <<    "                    torso_ROTATE[3]             = " <<  torso_ROTATE[3]<< ";\n";
           outPose   <<    "                    torso_ROTATE[0]             = " <<  torso_ROTATE[0] << ";\n";
           outPose   <<    "                    torso_ROTATE[1]             = " <<  torso_ROTATE[1]<< ";\n";
           outPose   <<    "                    torso_ROTATE[2]             = " <<  torso_ROTATE[2] << ";\n\n";
             
           outPose   <<    "                    head_ROTATE[3]             = " <<  head_ROTATE[3] << ";\n";
           outPose   <<    "                    head_ROTATE[0]             = " <<  head_ROTATE[0]<< ";\n";
           outPose   <<    "                    head_ROTATE[1]             = " <<  head_ROTATE[1] << ";\n";
           outPose   <<    "                    head_ROTATE[2]             = " <<  head_ROTATE[2]  << ";\n\n";    
   
           outPose   <<    "                    leftUpperArm_ROTATE[3]             = " <<  leftUpperArm_ROTATE[3] << ";\n";
           outPose   <<    "                    leftUpperArm_ROTATE[0]             = " <<  leftUpperArm_ROTATE[0] << ";\n";
           outPose   <<    "                    leftUpperArm_ROTATE[1]             = " <<  leftUpperArm_ROTATE[1]<< ";\n";
           outPose   <<    "                    leftUpperArm_ROTATE[2]             = " <<  leftUpperArm_ROTATE[2]<< ";\n\n";
    
           outPose   <<    "                    leftForeArm_ROTATE[3]             = " <<  leftForeArm_ROTATE[3] << ";\n";
           outPose   <<    "                    leftForeArm_ROTATE[0]             = " <<  leftForeArm_ROTATE[0]<< ";\n";
           outPose   <<    "                    leftForeArm_ROTATE[1]             = " <<  leftForeArm_ROTATE[1]<< ";\n";
           outPose   <<    "                    leftForeArm_ROTATE[2]             = " <<  leftForeArm_ROTATE[2] << ";\n\n";
    
           outPose   <<    "                    leftHand_ROTATE[3]             = " <<  leftHand_ROTATE[3] << ";\n";
           outPose   <<    "                    leftHand_ROTATE[0]             = " <<  leftHand_ROTATE[0]<< ";\n";
           outPose   <<    "                    leftHand_ROTATE[1]             = " <<  leftHand_ROTATE[1]<< ";\n";
           outPose   <<    "                    leftHand_ROTATE[2]             = " <<  leftHand_ROTATE[2]  << ";\n\n";
         
           outPose   <<    "                    rightUpperArm_ROTATE[3]             = " <<  rightUpperArm_ROTATE[3] << ";\n";
           outPose   <<    "                    rightUpperArm_ROTATE[0]             = " <<  rightUpperArm_ROTATE[0]  << ";\n";
           outPose   <<    "                    rightUpperArm_ROTATE[1]             = " <<  rightUpperArm_ROTATE[1]  << ";\n";
           outPose   <<    "                    rightUpperArm_ROTATE[2]             = " <<  rightUpperArm_ROTATE[2] << ";\n\n";
    
           outPose   <<    "                    rightForeArm_ROTATE[3]             = " <<  rightForeArm_ROTATE[3] << ";\n";
           outPose   <<    "                    rightForeArm_ROTATE[0]             = " <<  rightForeArm_ROTATE[0]<< ";\n";
           outPose   <<    "                    rightForeArm_ROTATE[1]             = " <<  rightForeArm_ROTATE[1] << ";\n";
           outPose   <<    "                    rightForeArm_ROTATE[2]             = " <<  rightForeArm_ROTATE[2]<< ";\n\n";
    
           outPose   <<    "                    rightHand_ROTATE[3]             = " << rightHand_ROTATE[3]  << ";\n";
           outPose   <<    "                    rightHand_ROTATE[0]             = " <<  rightHand_ROTATE[0] << ";\n";
           outPose   <<    "                    rightHand_ROTATE[1]             = " << rightHand_ROTATE[1]  << ";\n";
           outPose   <<    "                    rightHand_ROTATE[2]             = " <<  rightHand_ROTATE[2]  << ";\n\n";
           
           outPose   <<    "                    leftUpperLeg_ROTATE[3]             = " <<  leftUpperLeg_ROTATE[3]  << ";\n";
           outPose   <<    "                    leftUpperLeg_ROTATE[0]             = " <<  leftUpperLeg_ROTATE[0]   << ";\n";
           outPose   <<    "                    leftUpperLeg_ROTATE[1]             = " <<  leftUpperLeg_ROTATE[1]      << ";\n";
           outPose   <<    "                    leftUpperLeg_ROTATE[2]             = " <<  leftUpperLeg_ROTATE[2]<< ";\n\n";
    
           outPose   <<    "                    leftLowerLeg_ROTATE[3]             = " <<  leftLowerLeg_ROTATE[3] << ";\n";
           outPose   <<    "                    leftLowerLeg_ROTATE[0]             = " <<  leftLowerLeg_ROTATE[0]<< ";\n";
           outPose   <<    "                    leftLowerLeg_ROTATE[1]             = " <<  leftLowerLeg_ROTATE[1]    << ";\n";
           outPose   <<    "                    leftLowerLeg_ROTATE[2]             = " <<  leftLowerLeg_ROTATE[2]     << ";\n\n";
    
           outPose   <<    "                    leftFoot_ROTATE[3]             = " <<  leftFoot_ROTATE[3]  << ";\n";
           outPose   <<    "                    leftFoot_ROTATE[0]             = " <<  leftFoot_ROTATE[0]  << ";\n";
           outPose   <<    "                    leftFoot_ROTATE[1]             = " <<  leftFoot_ROTATE[1]<< ";\n";
           outPose   <<    "                    leftFoot_ROTATE[2]             = " <<   leftFoot_ROTATE[2]  << ";\n\n";                 
           
           outPose   <<    "                    rightUpperLeg_ROTATE[3]             = " <<  rightUpperLeg_ROTATE[3] << ";\n";
           outPose   <<    "                    rightUpperLeg_ROTATE[0]             = " <<  rightUpperLeg_ROTATE[0]<< ";\n";
           outPose   <<    "                    rightUpperLeg_ROTATE[1]             = " <<  rightUpperLeg_ROTATE[1]  << ";\n";
           outPose   <<    "                    rightUpperLeg_ROTATE[2]             = " <<  rightUpperLeg_ROTATE[2] << ";\n\n";
    
           outPose   <<    "                    rightLowerLeg_ROTATE[3]             = " <<  rightLowerLeg_ROTATE[3] << ";\n";
           outPose   <<    "                    rightLowerLeg_ROTATE[0]             = " << rightLowerLeg_ROTATE[0]    << ";\n";
           outPose   <<    "                    rightLowerLeg_ROTATE[1]             = " <<  rightLowerLeg_ROTATE[1]<< ";\n";
           outPose   <<    "                    rightLowerLeg_ROTATE[2]             = " <<  rightLowerLeg_ROTATE[2]<< ";\n\n";
    
           outPose   <<    "                    rightFoot_ROTATE[3]             = " <<  rightFoot_ROTATE[3]<< ";\n";
           outPose   <<    "                    rightFoot_ROTATE[0]             = " <<   rightFoot_ROTATE[0] << ";\n";
           outPose   <<    "                    rightFoot_ROTATE[1]             = " <<   rightFoot_ROTATE[1]<< ";\n";
           outPose   <<    "                    rightFoot_ROTATE[2]             = " <<  rightFoot_ROTATE[2]<< ";\n\n";
                  
        
        
        
    }





if (!keys['F']) 			
{
     F_KEY_IS_RESET  = true;
}   
//-------   
if (keys['F'] && F_KEY_IS_RESET) 			
{
     F_KEY_IS_RESET = false;
     hideSetPlusDialoque = false;
}
//-------

if (!keys['G']) 			
{
     G_KEY_IS_RESET  = true;
}   
//-------   
if (keys['G'] && G_KEY_IS_RESET) 				
{
    G_KEY_IS_RESET = false;
    hideSetPlusDialoque = true;   
}  

//=============================================== 

if (keys['R']) 			
{
       look_LEFT_RIGHT = 0;
       look_UP_DOWN    = 23.5;
}   
//===============================================     

 
if(keys['1'] && !keys[VK_SHIFT])
       BODY_PART_SELECTION = 1;      
if(keys['2'] && !keys[VK_SHIFT])
       BODY_PART_SELECTION = 2; 
if(keys['3'] && !keys[VK_SHIFT])
       BODY_PART_SELECTION = 3;
if(keys['4'] && !keys[VK_SHIFT])
       BODY_PART_SELECTION = 4;        
if(keys['5'] && !keys[VK_SHIFT])
       BODY_PART_SELECTION = 5;        
if(keys['6'] && !keys[VK_SHIFT])
       BODY_PART_SELECTION = 6;        
if(keys['7'] && !keys[VK_SHIFT])
       BODY_PART_SELECTION = 7;        
       
        
#include "bodyPartMovementKeys.cpp"

////////////////////////////////////////////______HIPS__TORSO__HEAD______^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
////////////////////////////////////////////______HIPS__TORSO__HEAD______^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
////////////////////////////////////////////______HIPS__TORSO__HEAD______^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
////////////////////////////////////////////______HIPS__TORSO__HEAD______^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
////////////////////////////////////////////______HIPS__TORSO__HEAD______^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//---------------------------------------------------¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾
//---------------------------------------------------¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾
//---------------------------------------------------¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾
//---------------------------------------------------¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾
//---------------------------------------------------¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾
//---------------------------------------------------¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾
//---------------------------------------------------¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾
//---------------------------------------------------¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾
//---------------------------------------------------¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾
//---------------------------------------------------¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾
//---------------------------------------------------¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾
//---------------------------------------------------¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾
//---------------------------------------------------¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾
//---------------------------------------------------¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾
//---------------------------------------------------¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾
//---------------------------------------------------¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾¾
               if(keys[VK_SPACE])
               {    
                     hips_POSITION_AnimationSequence          = true;
                     hips_AnimationSequence             = true;
                     torso_AnimationSequence            = true;
                     head_AnimationSequence             = true;      
                     leftUpperArm_AnimationSequence     = true;         
                     rightUpperArm_AnimationSequence    = true;  
                     leftUpperLeg_AnimationSequence     = true;      
                     rightUpperLeg_AnimationSequence    = true;               
               }      

               //-----------------------------------------------------------------
               if (keys['Y']) 			
               {
                   //runSlowMotion    = 1.00;
               }
               //-----------------------------------------------------------------
               if (keys['H']) 			
               {
                  // runSlowMotion    = 0.1;
               }  
               //-----------------------------------------------------------------
               if (keys['B']) 			
               {
                   runSlowMotion    = 0.01;
               }                 
               //-----------------------------------------------------------------
               if (keys['H']) 			
               {
                   runAnimationForward    = 0.0;
               }      
               
               if (!keys['H']) 			
               {
                   runAnimationForward    = 1.0;
               }    

//----------------------------------------------------------------------------------------------
/*    
    if(BODY_PART_SELECTION == 0 && keys['G'] && hips_POSITION_FRAME_TIME_01 > 0.0)
    {
            hips_POSITION_FRAME_TIME_01 -= 0.001;
    }
    if(BODY_PART_SELECTION == 0 && keys['H'])
    {
            hips_POSITION_FRAME_TIME_01 += 0.001;
    }    
    //---------------------------------------------------------------------------------
    if(BODY_PART_SELECTION == 1 && keys['G'] && LEFT_ARM_FRAME_TIME_01 > 0.0)
    {
            LEFT_ARM_FRAME_TIME_01 -= 0.001;
    }    
    if(BODY_PART_SELECTION == 1 && keys['H'])
    {
            LEFT_ARM_FRAME_TIME_01 += 0.001;
    }      
    //---------------------------------------------------------------------------------    
    if(BODY_PART_SELECTION == 2 && keys['G'] && RIGHT_ARM_FRAME_TIME_01 > 0.0)
    {
            RIGHT_ARM_FRAME_TIME_01 -= 0.001;
    }  
    if(BODY_PART_SELECTION == 2 && keys['H'])
    {
            RIGHT_ARM_FRAME_TIME_01 += 0.001;
    }  
    //--------------------------------------------------------------------------------- 
    if(BODY_PART_SELECTION == 3 && keys['G'] && LEFT_LEG_FRAME_TIME_01 > 0.0)
    {
            LEFT_LEG_FRAME_TIME_01 -= 0.001;
    
    }    
    if(BODY_PART_SELECTION == 3 && keys['H'])
    {
            LEFT_LEG_FRAME_TIME_01 += 0.001;
    }
    //---------------------------------------------------------------------------------
    if(BODY_PART_SELECTION == 4 && keys['G'] && RIGHT_LEG_FRAME_TIME_01 > 0.0)
    {
            RIGHT_LEG_FRAME_TIME_01 -= 0.001;
    }
    if(BODY_PART_SELECTION == 4 && keys['H'])
    {
            RIGHT_LEG_FRAME_TIME_01 += 0.001;
    }
    //---------------------------------------------------------------------------------       
    if(BODY_PART_SELECTION == 5 && keys['G'] && HIPS_FRAME_TIME_01 > 0.0)
    {
            HIPS_FRAME_TIME_01      -= 0.001;              
    }    
    if(BODY_PART_SELECTION == 5 && keys['H'])
    {
            HIPS_FRAME_TIME_01  += 0.001;                  
    }    
    //---------------------------------------------------------------------------------  
    if(BODY_PART_SELECTION == 6 && keys['G'] && TORSO_FRAME_TIME_01 > 0.0)
    {
            TORSO_FRAME_TIME_01 -= 0.001;
    }    
    if(BODY_PART_SELECTION == 6 && keys['H'])
    {
            TORSO_FRAME_TIME_01 += 0.001;
    }    
    //--------------------------------------------------------------------------------- 
    if(BODY_PART_SELECTION == 7 && keys['G'] && HEAD_FRAME_TIME_01 > 0.0)
    {
           HEAD_FRAME_TIME_01       -= 0.001;           
    }    
    if(BODY_PART_SELECTION == 7 && keys['H'])
    {
           HEAD_FRAME_TIME_01  += 0.001;                
    } 
*/    
    //---------------------------------------------------------------------------------   
    
    if (keys['1'] && keys[VK_SHIFT]) 			
	{      
        loadSet_01 = true;
    }
    if (!keys['1'] || !keys[VK_SHIFT]) 			
	{      
        loadSet_01 = false;
    }
    //-------------------------------   
    if (keys['2'] && keys[VK_SHIFT]) 			
	{      
        loadSet_02 = true;
    }
    if (!keys['2'] || !keys[VK_SHIFT]) 			
	{      
        loadSet_02 = false;
    }    
    //-------------------------------
    if (keys['3'] && keys[VK_SHIFT]) 			
	{      
        loadSet_03 = true;
    }
    if (!keys['3'] || !keys[VK_SHIFT]) 			
	{      
        loadSet_03 = false;
    }    
    //-------------------------------    
    if (keys['4'] && keys[VK_SHIFT]) 			
	{      
        loadSet_04 = true;
    }
    if (!keys['4'] || !keys[VK_SHIFT]) 			
	{      
        loadSet_04 = false;
    }     
    //-------------------------------  
    if (keys['5'] && keys[VK_SHIFT]) 			
	{      
        loadSet_05 = true;
    }
    if (!keys['5'] || !keys[VK_SHIFT]) 			
	{      
        loadSet_05 = false;
    }  
    //-------------------------------
    if (keys['6'] && keys[VK_SHIFT]) 			
	{      
        loadSet_06 = true;
    }
    if (!keys['6'] || !keys[VK_SHIFT]) 			
	{      
        loadSet_06 = false;
    }
   //-------------------------------
    if (keys['7'] && keys[VK_SHIFT]) 			
	{      
        loadSet_07 = true;
    }
    if (!keys['7'] || !keys[VK_SHIFT]) 			
	{      
        loadSet_07 = false;
    }

/////////++++++++++++------------------////____X_Y_Z_____AXIS___ON/OFF______///++++++++++++------------------//////
/////////++++++++++++------------------////____X_Y_Z_____AXIS___ON/OFF______///++++++++++++------------------//////
/////////++++++++++++------------------////____X_Y_Z_____AXIS___ON/OFF______///++++++++++++------------------//////    
   
    if (keys[VK_HOME] && !homeButtonPushed) 			
	{
        positionedModelSequence -=  1;
        homeButtonPushed = true;
    }
    if (keys[VK_END] && !endButtonPushed) 			
    {
        positionedModelSequence +=  1;
        endButtonPushed = true;    
    }     
    if (!keys[VK_HOME]) 			
	{
        homeButtonPushed = false;
    }
    if (!keys[VK_END]) 			
    {
        endButtonPushed = false;    
    }    
   
    if (keys['X']) 				
    {
        leftUpperArm_ROTATE_X      = true;
        leftForeArm_ROTATE_X       = true;   
        leftHand_ROTATE_X    = true;
        
         rightUpperArm_ROTATE_X    = true;
         rightForeArm_ROTATE_X     = true;   
         rightHand_ROTATE_X  = true;
                 
         leftUpperLeg_ROTATE_X     = true;
         leftLowerLeg_ROTATE_X     = true;
         leftFoot_ROTATE_X         = true;
             
         rightUpperLeg_ROTATE_X    = true;
         rightLowerLeg_ROTATE_X    = true;
         rightFoot_ROTATE_X        = true;    
    
         hips_ROTATE_X             = true;    
         torso_ROTATE_X            = true;    
         head_ROTATE_X             = true;    
    }
    //------------------------------------    
    if (!keys['X']) 				
    {
         leftUpperArm_ROTATE_X     = false;
         leftForeArm_ROTATE_X      = false;
         leftHand_ROTATE_X   = false;
           
         rightUpperArm_ROTATE_X    = false;
         rightForeArm_ROTATE_X     = false;
         rightHand_ROTATE_X  = false;    
    
         leftUpperLeg_ROTATE_X     = false;
         leftLowerLeg_ROTATE_X     = false;
         leftFoot_ROTATE_X         = false;    

         rightUpperLeg_ROTATE_X    = false;
         rightLowerLeg_ROTATE_X    = false;
         rightFoot_ROTATE_X        = false;
         
         hips_ROTATE_X             = false;
         torso_ROTATE_X            = false;                      
         head_ROTATE_X = false;    
    }    
//-------------------------------------------------    
//-------------------------------------------------    
	if (keys['Y']) 			
	{
         leftUpperArm_ROTATE_Y     = true;
         leftForeArm_ROTATE_Y      = true;   
         leftHand_ROTATE_Y   = true;

         rightUpperArm_ROTATE_Y    = true;
         rightForeArm_ROTATE_Y     = true;   
         rightHand_ROTATE_Y  = true;
                 
         leftUpperLeg_ROTATE_Y     = true;
         leftLowerLeg_ROTATE_Y     = true;
         leftFoot_ROTATE_Y         = true;   

         rightUpperLeg_ROTATE_Y    = true;
         rightLowerLeg_ROTATE_Y    = true;
         rightFoot_ROTATE_Y        = true;    
    
         hips_ROTATE_Y             = true;   
         torso_ROTATE_Y            = true;    
         head_ROTATE_Y             = true;    
    }
    //------------------------------------    
	if (!keys['Y']) 			
	{
         leftUpperArm_ROTATE_Y     = false;
         leftForeArm_ROTATE_Y      = false;
         leftHand_ROTATE_Y   = false;   

         rightUpperArm_ROTATE_Y    = false;
         rightForeArm_ROTATE_Y     = false;
         rightHand_ROTATE_Y  = false;    
    
         leftUpperLeg_ROTATE_Y     = false;
         leftLowerLeg_ROTATE_Y     = false;
         leftFoot_ROTATE_Y         = false;   
    
         rightUpperLeg_ROTATE_Y    = false;
         rightLowerLeg_ROTATE_Y    = false;
         rightFoot_ROTATE_Y        = false; 
         
         hips_ROTATE_Y             = false;            
         torso_ROTATE_Y            = false;    
         head_ROTATE_Y = false;    
    }    
//-------------------------------------------------    
//-------------------------------------------------    
    if (keys['Z']) 			
    {
        leftUpperArm_ROTATE_Z      = true;
        leftForeArm_ROTATE_Z       = true;  
        leftHand_ROTATE_Z    = true;

         rightUpperArm_ROTATE_Z    = true;
         rightForeArm_ROTATE_Z     = true;  
         rightHand_ROTATE_Z  = true;   

         leftUpperLeg_ROTATE_Z     = true;
         leftLowerLeg_ROTATE_Z     = true;
         leftFoot_ROTATE_Z         = true;   

         rightUpperLeg_ROTATE_Z    = true;
         rightLowerLeg_ROTATE_Z    = true;
         rightFoot_ROTATE_Z        = true;    
   
         hips_ROTATE_Z             = true;  
         torso_ROTATE_Z            = true;    
         head_ROTATE_Z             = true;    
    }    
    //------------------------------------    
    if (!keys['Z']) 			
    {
         leftUpperArm_ROTATE_Z     = false;
         leftForeArm_ROTATE_Z      = false;
         leftHand_ROTATE_Z   = false;   

         rightUpperArm_ROTATE_Z    = false;
         rightForeArm_ROTATE_Z     = false;
         rightHand_ROTATE_Z  = false;    
    
         leftUpperLeg_ROTATE_Z     = false;
         leftLowerLeg_ROTATE_Z     = false;
         leftFoot_ROTATE_Z         = false; 

         rightUpperLeg_ROTATE_Z    = false;
         rightLowerLeg_ROTATE_Z    = false;
         rightFoot_ROTATE_Z        = false;    
   
         hips_ROTATE_Z             = false;   
         torso_ROTATE_Z            = false;    
         head_ROTATE_Z = false;    
    } 
    
        
/////////++++++++++++------------------////____X_Y_Z_____AXIS___ON/OFF______///++++++++++++------------------//////
/////////++++++++++++------------------////____X_Y_Z_____AXIS___ON/OFF______///++++++++++++------------------//////
/////////++++++++++++------------------////____X_Y_Z_____AXIS___ON/OFF______///++++++++++++------------------//////    
    
    if(keys[VK_F1])
    {
           F1_isSet                             = 1.0;                                                                                                
           
           writeAnimationFile                   = true;         
  
           
           hips_POSITION_setSelectionLimit   = 1;    
           hips_POSITION_SelectionCount      = 1;
           
           SelectionCount_LEFT_ARM              = 1;
           setSelectionLimit_LEFT_ARM           = 1;                
           setSelectionLimit_HEAD               = 1;
           SelectionCount_HEAD                  = 1;  
           SelectionCount_TORSO                 = 1;
           setSelectionLimit_TORSO              = 1;
           SelectionCount_HIPS                  = 1;
           setSelectionLimit_HIPS               = 1;        
           SelectionCount_RIGHT_ARM             = 1;
           setSelectionLimit_RIGHT_ARM          = 1;           
           SelectionCount_LEFT_LEG              = 1;
           setSelectionLimit_LEFT_LEG           = 1; 
           SelectionCount_RIGHT_LEG             = 1;
           setSelectionLimit_RIGHT_LEG          = 1;                      
           
           F1_to_F8_TEXTURE                     = 1;
           //--------------------------------------------------------                     

            
           //--------------------------------------------------------            
           hips_POSITION_SET_01[0]           = hips_POSITION[0];
           hips_POSITION_SET_01[1]           = hips_POSITION[1];           
           hips_POSITION_SET_01[2]           = hips_POSITION[2];            
           //--------------------------------------------------------                      
           hips_SET_01[3]                       = hips_ROTATE[3];
           hips_SET_01[0]                       = hips_ROTATE[0];
           hips_SET_01[1]                       = hips_ROTATE[1];
           hips_SET_01[2]                       = hips_ROTATE[2];
           //--------------------------------------------------------                     
           torso_SET_01[3]                      = torso_ROTATE[3];
           torso_SET_01[0]                      = torso_ROTATE[0];
           torso_SET_01[1]                      = torso_ROTATE[1];
           torso_SET_01[2]                      = torso_ROTATE[2];
           //-------------------------------------------------------
           head_SET_01[3]                       = head_ROTATE[3];
           head_SET_01[0]                       = head_ROTATE[0];
           head_SET_01[1]                       = head_ROTATE[1];
           head_SET_01[2]                       = head_ROTATE[2];
           //-------------------------------------------------------         
           leftUpperArm_SET_01[3]               = leftUpperArm_ROTATE[3];
           leftUpperArm_SET_01[0]               = leftUpperArm_ROTATE[0];
           leftUpperArm_SET_01[1]               = leftUpperArm_ROTATE[1];
           leftUpperArm_SET_01[2]               = leftUpperArm_ROTATE[2];
           
           leftForeArm_SET_01[3]                = leftForeArm_ROTATE[3];
           leftForeArm_SET_01[0]                = leftForeArm_ROTATE[0];
           leftForeArm_SET_01[1]                = leftForeArm_ROTATE[1];
           leftForeArm_SET_01[2]                = leftForeArm_ROTATE[2];
           
           leftHand_SET_01[3]             = leftHand_ROTATE[3];
           leftHand_SET_01[0]             = leftHand_ROTATE[0];
           leftHand_SET_01[1]             = leftHand_ROTATE[1];
           leftHand_SET_01[2]             = leftHand_ROTATE[2];
           //------------------------------------------------------        
           rightUpperArm_SET_01[3]              = rightUpperArm_ROTATE[3];
           rightUpperArm_SET_01[0]              = rightUpperArm_ROTATE[0];
           rightUpperArm_SET_01[1]              = rightUpperArm_ROTATE[1];
           rightUpperArm_SET_01[2]              = rightUpperArm_ROTATE[2];
           
           rightForeArm_SET_01[3]               = rightForeArm_ROTATE[3];
           rightForeArm_SET_01[0]               = rightForeArm_ROTATE[0];
           rightForeArm_SET_01[1]               = rightForeArm_ROTATE[1];
           rightForeArm_SET_01[2]               = rightForeArm_ROTATE[2];
           
           rightHand_SET_01[3]            = rightHand_ROTATE[3];
           rightHand_SET_01[0]            = rightHand_ROTATE[0];
           rightHand_SET_01[1]            = rightHand_ROTATE[1];
           rightHand_SET_01[2]            = rightHand_ROTATE[2];
           //-----------------------------------------------------       
           leftUpperLeg_SET_01[3]               = leftUpperLeg_ROTATE[3];
           leftUpperLeg_SET_01[0]               = leftUpperLeg_ROTATE[0];
           leftUpperLeg_SET_01[1]               = leftUpperLeg_ROTATE[1];
           leftUpperLeg_SET_01[2]               = leftUpperLeg_ROTATE[2];
           
           leftLowerLeg_SET_01[3]               = leftLowerLeg_ROTATE[3];
           leftLowerLeg_SET_01[0]               = leftLowerLeg_ROTATE[0];
           leftLowerLeg_SET_01[1]               = leftLowerLeg_ROTATE[1];
           leftLowerLeg_SET_01[2]               = leftLowerLeg_ROTATE[2];
           
           leftFoot_SET_01[3]                   = leftFoot_ROTATE[3];
           leftFoot_SET_01[0]                   = leftFoot_ROTATE[0];
           leftFoot_SET_01[1]                   = leftFoot_ROTATE[1];
           leftFoot_SET_01[2]                   = leftFoot_ROTATE[2];                                             
           //----------------------------------------------------- 
           rightUpperLeg_SET_01[3]              = rightUpperLeg_ROTATE[3];
           rightUpperLeg_SET_01[0]              = rightUpperLeg_ROTATE[0];
           rightUpperLeg_SET_01[1]              = rightUpperLeg_ROTATE[1];
           rightUpperLeg_SET_01[2]              = rightUpperLeg_ROTATE[2];
           
           rightLowerLeg_SET_01[3]              = rightLowerLeg_ROTATE[3];
           rightLowerLeg_SET_01[0]              = rightLowerLeg_ROTATE[0];
           rightLowerLeg_SET_01[1]              = rightLowerLeg_ROTATE[1];
           rightLowerLeg_SET_01[2]              = rightLowerLeg_ROTATE[2];
           
           rightFoot_SET_01[3]                  = rightFoot_ROTATE[3];
           rightFoot_SET_01[0]                  = rightFoot_ROTATE[0];
           rightFoot_SET_01[1]                  = rightFoot_ROTATE[1];
           rightFoot_SET_01[2]                  = rightFoot_ROTATE[2];
    }
//------------------------------------------------------------------------------          
    if(keys[VK_F2])
    {
           
           F2_isSet                             = 1.0;            
           
           writeAnimationFile                   = true;           
           
     
        
        
           hips_POSITION_setSelectionLimit  = 2;    
           hips_POSITION_SelectionCount     = 2;
           SelectionCount_LEFT_ARM     = 2;
           setSelectionLimit_LEFT_ARM  = 2;           
           setSelectionLimit_HEAD      = 2;
           SelectionCount_HEAD         = 2;            
           SelectionCount_TORSO        = 2;
           setSelectionLimit_TORSO     = 2;
           SelectionCount_HIPS         = 2;
           setSelectionLimit_HIPS      = 2; 
           SelectionCount_RIGHT_ARM    = 2;
           setSelectionLimit_RIGHT_ARM = 2;                      
           SelectionCount_LEFT_LEG     = 2;
           setSelectionLimit_LEFT_LEG  = 2; 
           SelectionCount_RIGHT_LEG    = 2;
           setSelectionLimit_RIGHT_LEG = 2;           
          
           F1_to_F8_TEXTURE     = 2;           

          
          
           hips_POSITION_SET_02[0]  = hips_POSITION[0];
           hips_POSITION_SET_02[1]  = hips_POSITION[1];           
           hips_POSITION_SET_02[2]  = hips_POSITION[2];            
           
           leftUpperArm_SET_02[3] = leftUpperArm_ROTATE[3];
           leftUpperArm_SET_02[0] = leftUpperArm_ROTATE[0];
           leftUpperArm_SET_02[1] = leftUpperArm_ROTATE[1];
           leftUpperArm_SET_02[2] = leftUpperArm_ROTATE[2];
           
           leftForeArm_SET_02[3]  = leftForeArm_ROTATE[3];
           leftForeArm_SET_02[0]  = leftForeArm_ROTATE[0];
           leftForeArm_SET_02[1]  = leftForeArm_ROTATE[1];
           leftForeArm_SET_02[2]  = leftForeArm_ROTATE[2];            

           leftHand_SET_02[3]  = leftHand_ROTATE[3];
           leftHand_SET_02[0]  = leftHand_ROTATE[0];
           leftHand_SET_02[1]  = leftHand_ROTATE[1];
           leftHand_SET_02[2]  = leftHand_ROTATE[2];
           //-----------------------------------------------------  
           rightUpperArm_SET_02[3] = rightUpperArm_ROTATE[3];
           rightUpperArm_SET_02[0] = rightUpperArm_ROTATE[0];
           rightUpperArm_SET_02[1] = rightUpperArm_ROTATE[1];
           rightUpperArm_SET_02[2] = rightUpperArm_ROTATE[2];
           
           rightForeArm_SET_02[3]  = rightForeArm_ROTATE[3];
           rightForeArm_SET_02[0]  = rightForeArm_ROTATE[0];
           rightForeArm_SET_02[1]  = rightForeArm_ROTATE[1];
           rightForeArm_SET_02[2]  = rightForeArm_ROTATE[2];            

           rightHand_SET_02[3]  = rightHand_ROTATE[3];
           rightHand_SET_02[0]  = rightHand_ROTATE[0];
           rightHand_SET_02[1]  = rightHand_ROTATE[1];
           rightHand_SET_02[2]  = rightHand_ROTATE[2];           
           //-----------------------------------------------------            
           leftUpperLeg_SET_02[3] = leftUpperLeg_ROTATE[3];
           leftUpperLeg_SET_02[0] = leftUpperLeg_ROTATE[0];
           leftUpperLeg_SET_02[1] = leftUpperLeg_ROTATE[1];
           leftUpperLeg_SET_02[2] = leftUpperLeg_ROTATE[2];
           
           leftLowerLeg_SET_02[3]  = leftLowerLeg_ROTATE[3];
           leftLowerLeg_SET_02[0]  = leftLowerLeg_ROTATE[0];
           leftLowerLeg_SET_02[1]  = leftLowerLeg_ROTATE[1];
           leftLowerLeg_SET_02[2]  = leftLowerLeg_ROTATE[2];
           
           leftFoot_SET_02[3]  = leftFoot_ROTATE[3];
           leftFoot_SET_02[0]  = leftFoot_ROTATE[0];
           leftFoot_SET_02[1]  = leftFoot_ROTATE[1];
           leftFoot_SET_02[2]  = leftFoot_ROTATE[2];           
           //-----------------------------------------------------             
           rightUpperLeg_SET_02[3] = rightUpperLeg_ROTATE[3];
           rightUpperLeg_SET_02[0] = rightUpperLeg_ROTATE[0];
           rightUpperLeg_SET_02[1] = rightUpperLeg_ROTATE[1];
           rightUpperLeg_SET_02[2] = rightUpperLeg_ROTATE[2];
           
           rightLowerLeg_SET_02[3]  = rightLowerLeg_ROTATE[3];
           rightLowerLeg_SET_02[0]  = rightLowerLeg_ROTATE[0];
           rightLowerLeg_SET_02[1]  = rightLowerLeg_ROTATE[1];
           rightLowerLeg_SET_02[2]  = rightLowerLeg_ROTATE[2];
           
           rightFoot_SET_02[3]  = rightFoot_ROTATE[3];
           rightFoot_SET_02[0]  = rightFoot_ROTATE[0];
           rightFoot_SET_02[1]  = rightFoot_ROTATE[1];
           rightFoot_SET_02[2]  = rightFoot_ROTATE[2];           
           //----------------------------------------------------- 
            
           hips_SET_02[3] = hips_ROTATE[3];
           hips_SET_02[0] = hips_ROTATE[0];
           hips_SET_02[1] = hips_ROTATE[1];
           hips_SET_02[2] = hips_ROTATE[2];           
           //-----------------------------------------------------            
           torso_SET_02[3] = torso_ROTATE[3];
           torso_SET_02[0] = torso_ROTATE[0];
           torso_SET_02[1] = torso_ROTATE[1];
           torso_SET_02[2] = torso_ROTATE[2];           
           //----------------------------------------------------- 
           head_SET_02[3] = head_ROTATE[3];
           head_SET_02[0] = head_ROTATE[0];
           head_SET_02[1] = head_ROTATE[1];
           head_SET_02[2] = head_ROTATE[2];           
           //----------------------------------------------------- 
           
    
    }
//------------------------------------------------------------------------------     
    if(keys[VK_F3])
    {
           F3_isSet                             = 1.0;            
           
           writeAnimationFile                   = true;         
   
           
           hips_POSITION_setSelectionLimit  = 3;
           hips_POSITION_SelectionCount     = 3;
                      
           SelectionCount_LEFT_ARM     = 3;
           setSelectionLimit_LEFT_ARM  = 3;           
           setSelectionLimit_HEAD      = 3;
           SelectionCount_HEAD         = 3;            
           SelectionCount_TORSO        = 3;
           setSelectionLimit_TORSO     = 3;           
           SelectionCount_HIPS         = 3;
           setSelectionLimit_HIPS      = 3; 
           SelectionCount_RIGHT_ARM    = 3;
           setSelectionLimit_RIGHT_ARM = 3;           
           SelectionCount_LEFT_LEG     = 3;
           setSelectionLimit_LEFT_LEG  = 3; 
           SelectionCount_RIGHT_LEG    = 3;
           setSelectionLimit_RIGHT_LEG = 3;                                  
           
           F1_to_F8_TEXTURE     = 3;

           
           hips_POSITION_SET_03[0]  = hips_POSITION[0];
           hips_POSITION_SET_03[1]  = hips_POSITION[1];           
           hips_POSITION_SET_03[2]  = hips_POSITION[2];            
           
           leftUpperArm_SET_03[3] = leftUpperArm_ROTATE[3];
           leftUpperArm_SET_03[0] = leftUpperArm_ROTATE[0];
           leftUpperArm_SET_03[1] = leftUpperArm_ROTATE[1];
           leftUpperArm_SET_03[2] = leftUpperArm_ROTATE[2];                       

           leftForeArm_SET_03[3]  = leftForeArm_ROTATE[3];
           leftForeArm_SET_03[0]  = leftForeArm_ROTATE[0];
           leftForeArm_SET_03[1]  = leftForeArm_ROTATE[1];
           leftForeArm_SET_03[2]  = leftForeArm_ROTATE[2];          

           leftHand_SET_03[3]  = leftHand_ROTATE[3];
           leftHand_SET_03[0]  = leftHand_ROTATE[0];
           leftHand_SET_03[1]  = leftHand_ROTATE[1];
           leftHand_SET_03[2]  = leftHand_ROTATE[2];
           //-----------------------------------------------------  
           rightUpperArm_SET_03[3] = rightUpperArm_ROTATE[3];
           rightUpperArm_SET_03[0] = rightUpperArm_ROTATE[0];
           rightUpperArm_SET_03[1] = rightUpperArm_ROTATE[1];
           rightUpperArm_SET_03[2] = rightUpperArm_ROTATE[2];                       

           rightForeArm_SET_03[3]  = rightForeArm_ROTATE[3];
           rightForeArm_SET_03[0]  = rightForeArm_ROTATE[0];
           rightForeArm_SET_03[1]  = rightForeArm_ROTATE[1];
           rightForeArm_SET_03[2]  = rightForeArm_ROTATE[2];          

           rightHand_SET_03[3]  = rightHand_ROTATE[3];
           rightHand_SET_03[0]  = rightHand_ROTATE[0];
           rightHand_SET_03[1]  = rightHand_ROTATE[1];
           rightHand_SET_03[2]  = rightHand_ROTATE[2];
           //-----------------------------------------------------            
           leftUpperLeg_SET_03[3] = leftUpperLeg_ROTATE[3];
           leftUpperLeg_SET_03[0] = leftUpperLeg_ROTATE[0];
           leftUpperLeg_SET_03[1] = leftUpperLeg_ROTATE[1];
           leftUpperLeg_SET_03[2] = leftUpperLeg_ROTATE[2];
           
           leftLowerLeg_SET_03[3]  = leftLowerLeg_ROTATE[3];
           leftLowerLeg_SET_03[0]  = leftLowerLeg_ROTATE[0];
           leftLowerLeg_SET_03[1]  = leftLowerLeg_ROTATE[1];
           leftLowerLeg_SET_03[2]  = leftLowerLeg_ROTATE[2];
           
           leftFoot_SET_03[3]  = leftFoot_ROTATE[3];
           leftFoot_SET_03[0]  = leftFoot_ROTATE[0];
           leftFoot_SET_03[1]  = leftFoot_ROTATE[1];
           leftFoot_SET_03[2]  = leftFoot_ROTATE[2];           
           //-----------------------------------------------------                                  
           rightUpperLeg_SET_03[3] = rightUpperLeg_ROTATE[3];
           rightUpperLeg_SET_03[0] = rightUpperLeg_ROTATE[0];
           rightUpperLeg_SET_03[1] = rightUpperLeg_ROTATE[1];
           rightUpperLeg_SET_03[2] = rightUpperLeg_ROTATE[2];
           
           rightLowerLeg_SET_03[3]  = rightLowerLeg_ROTATE[3];
           rightLowerLeg_SET_03[0]  = rightLowerLeg_ROTATE[0];
           rightLowerLeg_SET_03[1]  = rightLowerLeg_ROTATE[1];
           rightLowerLeg_SET_03[2]  = rightLowerLeg_ROTATE[2];
           
           rightFoot_SET_03[3]  = rightFoot_ROTATE[3];
           rightFoot_SET_03[0]  = rightFoot_ROTATE[0];
           rightFoot_SET_03[1]  = rightFoot_ROTATE[1];
           rightFoot_SET_03[2]  = rightFoot_ROTATE[2];           
           //-----------------------------------------------------             
           hips_SET_03[3]  = hips_ROTATE[3];
           hips_SET_03[0]  = hips_ROTATE[0];
           hips_SET_03[1]  = hips_ROTATE[1];
           hips_SET_03[2]  = hips_ROTATE[2];           
           //----------------------------------------------------- 
           torso_SET_03[3]  = torso_ROTATE[3];
           torso_SET_03[0]  = torso_ROTATE[0];
           torso_SET_03[1]  = torso_ROTATE[1];
           torso_SET_03[2]  = torso_ROTATE[2];           
           //----------------------------------------------------- 
           head_SET_03[3]  = head_ROTATE[3];
           head_SET_03[0]  = head_ROTATE[0];
           head_SET_03[1]  = head_ROTATE[1];
           head_SET_03[2]  = head_ROTATE[2];           
           //----------------------------------------------------- 
    }    
//------------------------------------------------------------------------------     
    if(keys[VK_F4])
    {
           F4_isSet                             = 1.0;            
           
           writeAnimationFile                   = true;           
      
          
           hips_POSITION_setSelectionLimit  = 4;
           hips_POSITION_SelectionCount     = 4;
                     
           SelectionCount_LEFT_ARM     = 4;
           setSelectionLimit_LEFT_ARM  = 4;           
           setSelectionLimit_HEAD      = 4;
           SelectionCount_HEAD         = 4;            
           SelectionCount_TORSO        = 4;
           setSelectionLimit_TORSO     = 4;          
           SelectionCount_HIPS         = 4;
           setSelectionLimit_HIPS      = 4; 
           SelectionCount_RIGHT_ARM    = 4;
           setSelectionLimit_RIGHT_ARM = 4;           
           SelectionCount_LEFT_LEG     = 4;
           setSelectionLimit_LEFT_LEG  = 4; 
           SelectionCount_RIGHT_LEG    = 4;
           setSelectionLimit_RIGHT_LEG = 4;                                 
           
           F1_to_F8_TEXTURE            = 4;

           hips_POSITION_SET_04[0]  = hips_POSITION[0];
           hips_POSITION_SET_04[1]  = hips_POSITION[1];           
           hips_POSITION_SET_04[2]  = hips_POSITION[2];           
          
           leftUpperArm_SET_04[3] = leftUpperArm_ROTATE[3];
           leftUpperArm_SET_04[0] = leftUpperArm_ROTATE[0];
           leftUpperArm_SET_04[1] = leftUpperArm_ROTATE[1];
           leftUpperArm_SET_04[2] = leftUpperArm_ROTATE[2];       
 
           leftForeArm_SET_04[3]  = leftForeArm_ROTATE[3];
           leftForeArm_SET_04[0]  = leftForeArm_ROTATE[0];
           leftForeArm_SET_04[1]  = leftForeArm_ROTATE[1];
           leftForeArm_SET_04[2]  = leftForeArm_ROTATE[2]; 

           leftHand_SET_04[3]  = leftHand_ROTATE[3];
           leftHand_SET_04[0]  = leftHand_ROTATE[0];
           leftHand_SET_04[1]  = leftHand_ROTATE[1];
           leftHand_SET_04[2]  = leftHand_ROTATE[2];
                      //-----------------------------------------------------              
           rightUpperArm_SET_04[3] = rightUpperArm_ROTATE[3];
           rightUpperArm_SET_04[0] = rightUpperArm_ROTATE[0];
           rightUpperArm_SET_04[1] = rightUpperArm_ROTATE[1];
           rightUpperArm_SET_04[2] = rightUpperArm_ROTATE[2];       
 
           rightForeArm_SET_04[3]  = rightForeArm_ROTATE[3];
           rightForeArm_SET_04[0]  = rightForeArm_ROTATE[0];
           rightForeArm_SET_04[1]  = rightForeArm_ROTATE[1];
           rightForeArm_SET_04[2]  = rightForeArm_ROTATE[2]; 

           rightHand_SET_04[3]  = rightHand_ROTATE[3];
           rightHand_SET_04[0]  = rightHand_ROTATE[0];
           rightHand_SET_04[1]  = rightHand_ROTATE[1];
           rightHand_SET_04[2]  = rightHand_ROTATE[2];            
                      //-----------------------------------------------------             
           leftUpperLeg_SET_04[3] = leftUpperLeg_ROTATE[3];
           leftUpperLeg_SET_04[0] = leftUpperLeg_ROTATE[0];
           leftUpperLeg_SET_04[1] = leftUpperLeg_ROTATE[1];
           leftUpperLeg_SET_04[2] = leftUpperLeg_ROTATE[2];
           
           leftLowerLeg_SET_04[3]  = leftLowerLeg_ROTATE[3];
           leftLowerLeg_SET_04[0]  = leftLowerLeg_ROTATE[0];
           leftLowerLeg_SET_04[1]  = leftLowerLeg_ROTATE[1];
           leftLowerLeg_SET_04[2]  = leftLowerLeg_ROTATE[2];
           
           leftFoot_SET_04[3]  = leftFoot_ROTATE[3];
           leftFoot_SET_04[0]  = leftFoot_ROTATE[0];
           leftFoot_SET_04[1]  = leftFoot_ROTATE[1];
           leftFoot_SET_04[2]  = leftFoot_ROTATE[2]; 
                      //-----------------------------------------------------    
           rightUpperLeg_SET_04[3] = rightUpperLeg_ROTATE[3];
           rightUpperLeg_SET_04[0] = rightUpperLeg_ROTATE[0];
           rightUpperLeg_SET_04[1] = rightUpperLeg_ROTATE[1];
           rightUpperLeg_SET_04[2] = rightUpperLeg_ROTATE[2];
           
           rightLowerLeg_SET_04[3]  = rightLowerLeg_ROTATE[3];
           rightLowerLeg_SET_04[0]  = rightLowerLeg_ROTATE[0];
           rightLowerLeg_SET_04[1]  = rightLowerLeg_ROTATE[1];
           rightLowerLeg_SET_04[2]  = rightLowerLeg_ROTATE[2];
           
           rightFoot_SET_04[3]  = rightFoot_ROTATE[3];
           rightFoot_SET_04[0]  = rightFoot_ROTATE[0];
           rightFoot_SET_04[1]  = rightFoot_ROTATE[1];
           rightFoot_SET_04[2]  = rightFoot_ROTATE[2]; 
                      //-----------------------------------------------------    
          
           hips_SET_04[3]  = hips_ROTATE[3];
           hips_SET_04[0]  = hips_ROTATE[0];
           hips_SET_04[1]  = hips_ROTATE[1];
           hips_SET_04[2]  = hips_ROTATE[2]; 
                      //----------------------------------------------------- 
         
           torso_SET_04[3]  = torso_ROTATE[3];
           torso_SET_04[0]  = torso_ROTATE[0];
           torso_SET_04[1]  = torso_ROTATE[1];
           torso_SET_04[2]  = torso_ROTATE[2]; 
                      //----------------------------------------------------- 
         
           head_SET_04[3]  = head_ROTATE[3];
           head_SET_04[0]  = head_ROTATE[0];
           head_SET_04[1]  = head_ROTATE[1];
           head_SET_04[2]  = head_ROTATE[2]; 
                      //----------------------------------------------------- 
    }    
//------------------------------------------------------------------------------     
    if(keys[VK_F5])
    {
           F5_isSet                             = 1.0;        
       
           writeAnimationFile                   = true;          

           hips_POSITION_setSelectionLimit  = 5;
           hips_POSITION_SelectionCount     = 5;
           
           SelectionCount_LEFT_ARM     = 5;
           setSelectionLimit_LEFT_ARM  = 5;           
           setSelectionLimit_HEAD      = 5;
           SelectionCount_HEAD         = 5;            
           SelectionCount_TORSO        = 5;
           setSelectionLimit_TORSO     = 5;          
           SelectionCount_HIPS         = 5;
           setSelectionLimit_HIPS      = 5; 
           SelectionCount_RIGHT_ARM    = 5;
           setSelectionLimit_RIGHT_ARM = 5;           
           SelectionCount_LEFT_LEG     = 5;
           setSelectionLimit_LEFT_LEG  = 5; 
           SelectionCount_RIGHT_LEG    = 5;
           setSelectionLimit_RIGHT_LEG = 5;                                 
           
           F1_to_F8_TEXTURE            = 5;

           hips_POSITION_SET_05[0]  = hips_POSITION[0];
           hips_POSITION_SET_05[1]  = hips_POSITION[1];           
           hips_POSITION_SET_05[2]  = hips_POSITION[2];           
          
           leftUpperArm_SET_05[3] = leftUpperArm_ROTATE[3];
           leftUpperArm_SET_05[0] = leftUpperArm_ROTATE[0];
           leftUpperArm_SET_05[1] = leftUpperArm_ROTATE[1];
           leftUpperArm_SET_05[2] = leftUpperArm_ROTATE[2];       
 
           leftForeArm_SET_05[3]  = leftForeArm_ROTATE[3];
           leftForeArm_SET_05[0]  = leftForeArm_ROTATE[0];
           leftForeArm_SET_05[1]  = leftForeArm_ROTATE[1];
           leftForeArm_SET_05[2]  = leftForeArm_ROTATE[2]; 

           leftHand_SET_05[3]  = leftHand_ROTATE[3];
           leftHand_SET_05[0]  = leftHand_ROTATE[0];
           leftHand_SET_05[1]  = leftHand_ROTATE[1];
           leftHand_SET_05[2]  = leftHand_ROTATE[2];
                      //-----------------------------------------------------              
           rightUpperArm_SET_05[3] = rightUpperArm_ROTATE[3];
           rightUpperArm_SET_05[0] = rightUpperArm_ROTATE[0];
           rightUpperArm_SET_05[1] = rightUpperArm_ROTATE[1];
           rightUpperArm_SET_05[2] = rightUpperArm_ROTATE[2];       
 
           rightForeArm_SET_05[3]  = rightForeArm_ROTATE[3];
           rightForeArm_SET_05[0]  = rightForeArm_ROTATE[0];
           rightForeArm_SET_05[1]  = rightForeArm_ROTATE[1];
           rightForeArm_SET_05[2]  = rightForeArm_ROTATE[2]; 

           rightHand_SET_05[3]  = rightHand_ROTATE[3];
           rightHand_SET_05[0]  = rightHand_ROTATE[0];
           rightHand_SET_05[1]  = rightHand_ROTATE[1];
           rightHand_SET_05[2]  = rightHand_ROTATE[2];            
                      //-----------------------------------------------------             
           leftUpperLeg_SET_05[3] = leftUpperLeg_ROTATE[3];
           leftUpperLeg_SET_05[0] = leftUpperLeg_ROTATE[0];
           leftUpperLeg_SET_05[1] = leftUpperLeg_ROTATE[1];
           leftUpperLeg_SET_05[2] = leftUpperLeg_ROTATE[2];
           
           leftLowerLeg_SET_05[3]  = leftLowerLeg_ROTATE[3];
           leftLowerLeg_SET_05[0]  = leftLowerLeg_ROTATE[0];
           leftLowerLeg_SET_05[1]  = leftLowerLeg_ROTATE[1];
           leftLowerLeg_SET_05[2]  = leftLowerLeg_ROTATE[2];
           
           leftFoot_SET_05[3]  = leftFoot_ROTATE[3];
           leftFoot_SET_05[0]  = leftFoot_ROTATE[0];
           leftFoot_SET_05[1]  = leftFoot_ROTATE[1];
           leftFoot_SET_05[2]  = leftFoot_ROTATE[2]; 
                      //-----------------------------------------------------    
           rightUpperLeg_SET_05[3] = rightUpperLeg_ROTATE[3];
           rightUpperLeg_SET_05[0] = rightUpperLeg_ROTATE[0];
           rightUpperLeg_SET_05[1] = rightUpperLeg_ROTATE[1];
           rightUpperLeg_SET_05[2] = rightUpperLeg_ROTATE[2];
           
           rightLowerLeg_SET_05[3]  = rightLowerLeg_ROTATE[3];
           rightLowerLeg_SET_05[0]  = rightLowerLeg_ROTATE[0];
           rightLowerLeg_SET_05[1]  = rightLowerLeg_ROTATE[1];
           rightLowerLeg_SET_05[2]  = rightLowerLeg_ROTATE[2];
           
           rightFoot_SET_05[3]  = rightFoot_ROTATE[3];
           rightFoot_SET_05[0]  = rightFoot_ROTATE[0];
           rightFoot_SET_05[1]  = rightFoot_ROTATE[1];
           rightFoot_SET_05[2]  = rightFoot_ROTATE[2]; 
                      //-----------------------------------------------------    
          
           hips_SET_05[3]  = hips_ROTATE[3];
           hips_SET_05[0]  = hips_ROTATE[0];
           hips_SET_05[1]  = hips_ROTATE[1];
           hips_SET_05[2]  = hips_ROTATE[2]; 
                      //----------------------------------------------------- 
         
           torso_SET_05[3]  = torso_ROTATE[3];
           torso_SET_05[0]  = torso_ROTATE[0];
           torso_SET_05[1]  = torso_ROTATE[1];
           torso_SET_05[2]  = torso_ROTATE[2]; 
                      //----------------------------------------------------- 
         
           head_SET_05[3]  = head_ROTATE[3];
           head_SET_05[0]  = head_ROTATE[0];
           head_SET_05[1]  = head_ROTATE[1];
           head_SET_05[2]  = head_ROTATE[2]; 
                      //----------------------------------------------------- 
    }
//------------------------------------------------------------------------------     
    if(keys[VK_F6])
    {
           F6_isSet                             = 1.0;           
          
           writeAnimationFile                   = true;          

           hips_POSITION_setSelectionLimit  = 6;
           hips_POSITION_SelectionCount     = 6;
           
           SelectionCount_LEFT_ARM     = 6;
           setSelectionLimit_LEFT_ARM  = 6;           
           setSelectionLimit_HEAD      = 6;
           SelectionCount_HEAD         = 6;            
           SelectionCount_TORSO        = 6;
           setSelectionLimit_TORSO     = 6;          
           SelectionCount_HIPS         = 6;
           setSelectionLimit_HIPS      = 6; 
           SelectionCount_RIGHT_ARM    = 6;
           setSelectionLimit_RIGHT_ARM = 6;           
           SelectionCount_LEFT_LEG     = 6;
           setSelectionLimit_LEFT_LEG  = 6; 
           SelectionCount_RIGHT_LEG    = 6;
           setSelectionLimit_RIGHT_LEG = 6;                                 
           
           F1_to_F8_TEXTURE            = 6;

           hips_POSITION_SET_06[0]  = hips_POSITION[0];
           hips_POSITION_SET_06[1]  = hips_POSITION[1];           
           hips_POSITION_SET_06[2]  = hips_POSITION[2];           
          
           leftUpperArm_SET_06[3] = leftUpperArm_ROTATE[3];
           leftUpperArm_SET_06[0] = leftUpperArm_ROTATE[0];
           leftUpperArm_SET_06[1] = leftUpperArm_ROTATE[1];
           leftUpperArm_SET_06[2] = leftUpperArm_ROTATE[2];       
 
           leftForeArm_SET_06[3]  = leftForeArm_ROTATE[3];
           leftForeArm_SET_06[0]  = leftForeArm_ROTATE[0];
           leftForeArm_SET_06[1]  = leftForeArm_ROTATE[1];
           leftForeArm_SET_06[2]  = leftForeArm_ROTATE[2]; 

           leftHand_SET_06[3]  = leftHand_ROTATE[3];
           leftHand_SET_06[0]  = leftHand_ROTATE[0];
           leftHand_SET_06[1]  = leftHand_ROTATE[1];
           leftHand_SET_06[2]  = leftHand_ROTATE[2];
                      //-----------------------------------------------------              
           rightUpperArm_SET_06[3] = rightUpperArm_ROTATE[3];
           rightUpperArm_SET_06[0] = rightUpperArm_ROTATE[0];
           rightUpperArm_SET_06[1] = rightUpperArm_ROTATE[1];
           rightUpperArm_SET_06[2] = rightUpperArm_ROTATE[2];       
 
           rightForeArm_SET_06[3]  = rightForeArm_ROTATE[3];
           rightForeArm_SET_06[0]  = rightForeArm_ROTATE[0];
           rightForeArm_SET_06[1]  = rightForeArm_ROTATE[1];
           rightForeArm_SET_06[2]  = rightForeArm_ROTATE[2]; 

           rightHand_SET_06[3]  = rightHand_ROTATE[3];
           rightHand_SET_06[0]  = rightHand_ROTATE[0];
           rightHand_SET_06[1]  = rightHand_ROTATE[1];
           rightHand_SET_06[2]  = rightHand_ROTATE[2];            
                      //-----------------------------------------------------             
           leftUpperLeg_SET_06[3] = leftUpperLeg_ROTATE[3];
           leftUpperLeg_SET_06[0] = leftUpperLeg_ROTATE[0];
           leftUpperLeg_SET_06[1] = leftUpperLeg_ROTATE[1];
           leftUpperLeg_SET_06[2] = leftUpperLeg_ROTATE[2];
           
           leftLowerLeg_SET_06[3]  = leftLowerLeg_ROTATE[3];
           leftLowerLeg_SET_06[0]  = leftLowerLeg_ROTATE[0];
           leftLowerLeg_SET_06[1]  = leftLowerLeg_ROTATE[1];
           leftLowerLeg_SET_06[2]  = leftLowerLeg_ROTATE[2];
           
           leftFoot_SET_06[3]  = leftFoot_ROTATE[3];
           leftFoot_SET_06[0]  = leftFoot_ROTATE[0];
           leftFoot_SET_06[1]  = leftFoot_ROTATE[1];
           leftFoot_SET_06[2]  = leftFoot_ROTATE[2]; 
                      //-----------------------------------------------------    
           rightUpperLeg_SET_06[3] = rightUpperLeg_ROTATE[3];
           rightUpperLeg_SET_06[0] = rightUpperLeg_ROTATE[0];
           rightUpperLeg_SET_06[1] = rightUpperLeg_ROTATE[1];
           rightUpperLeg_SET_06[2] = rightUpperLeg_ROTATE[2];
           
           rightLowerLeg_SET_06[3]  = rightLowerLeg_ROTATE[3];
           rightLowerLeg_SET_06[0]  = rightLowerLeg_ROTATE[0];
           rightLowerLeg_SET_06[1]  = rightLowerLeg_ROTATE[1];
           rightLowerLeg_SET_06[2]  = rightLowerLeg_ROTATE[2];
           
           rightFoot_SET_06[3]  = rightFoot_ROTATE[3];
           rightFoot_SET_06[0]  = rightFoot_ROTATE[0];
           rightFoot_SET_06[1]  = rightFoot_ROTATE[1];
           rightFoot_SET_06[2]  = rightFoot_ROTATE[2]; 
                      //-----------------------------------------------------    
          
           hips_SET_06[3]  = hips_ROTATE[3];
           hips_SET_06[0]  = hips_ROTATE[0];
           hips_SET_06[1]  = hips_ROTATE[1];
           hips_SET_06[2]  = hips_ROTATE[2]; 
                      //----------------------------------------------------- 
         
           torso_SET_06[3]  = torso_ROTATE[3];
           torso_SET_06[0]  = torso_ROTATE[0];
           torso_SET_06[1]  = torso_ROTATE[1];
           torso_SET_06[2]  = torso_ROTATE[2]; 
                      //----------------------------------------------------- 
         
           head_SET_06[3]  = head_ROTATE[3];
           head_SET_06[0]  = head_ROTATE[0];
           head_SET_06[1]  = head_ROTATE[1];
           head_SET_06[2]  = head_ROTATE[2]; 
                      //----------------------------------------------------- 
    }
    
//------------------------------------------------------------------------------     
    if(keys[VK_F7])
    {
           F7_isSet                             = 1.0;           
          
           writeAnimationFile                   = true;          

           hips_POSITION_setSelectionLimit  = 7;
           hips_POSITION_SelectionCount     = 7;
           
           SelectionCount_LEFT_ARM     = 7;
           setSelectionLimit_LEFT_ARM  = 7;           
           setSelectionLimit_HEAD      = 7;
           SelectionCount_HEAD         = 7;            
           SelectionCount_TORSO        = 7;
           setSelectionLimit_TORSO     = 7;          
           SelectionCount_HIPS         = 7;
           setSelectionLimit_HIPS      = 7; 
           SelectionCount_RIGHT_ARM    = 7;
           setSelectionLimit_RIGHT_ARM = 7;           
           SelectionCount_LEFT_LEG     = 7;
           setSelectionLimit_LEFT_LEG  = 7; 
           SelectionCount_RIGHT_LEG    = 7;
           setSelectionLimit_RIGHT_LEG = 7;                                 
           
           F1_to_F8_TEXTURE            = 7;

           hips_POSITION_SET_07[0]  = hips_POSITION[0];
           hips_POSITION_SET_07[1]  = hips_POSITION[1];           
           hips_POSITION_SET_07[2]  = hips_POSITION[2];           
          
           leftUpperArm_SET_07[3] = leftUpperArm_ROTATE[3];
           leftUpperArm_SET_07[0] = leftUpperArm_ROTATE[0];
           leftUpperArm_SET_07[1] = leftUpperArm_ROTATE[1];
           leftUpperArm_SET_07[2] = leftUpperArm_ROTATE[2];       
 
           leftForeArm_SET_07[3]  = leftForeArm_ROTATE[3];
           leftForeArm_SET_07[0]  = leftForeArm_ROTATE[0];
           leftForeArm_SET_07[1]  = leftForeArm_ROTATE[1];
           leftForeArm_SET_07[2]  = leftForeArm_ROTATE[2]; 

           leftHand_SET_07[3]  = leftHand_ROTATE[3];
           leftHand_SET_07[0]  = leftHand_ROTATE[0];
           leftHand_SET_07[1]  = leftHand_ROTATE[1];
           leftHand_SET_07[2]  = leftHand_ROTATE[2];
                      //-----------------------------------------------------              
           rightUpperArm_SET_07[3] = rightUpperArm_ROTATE[3];
           rightUpperArm_SET_07[0] = rightUpperArm_ROTATE[0];
           rightUpperArm_SET_07[1] = rightUpperArm_ROTATE[1];
           rightUpperArm_SET_07[2] = rightUpperArm_ROTATE[2];       
 
           rightForeArm_SET_07[3]  = rightForeArm_ROTATE[3];
           rightForeArm_SET_07[0]  = rightForeArm_ROTATE[0];
           rightForeArm_SET_07[1]  = rightForeArm_ROTATE[1];
           rightForeArm_SET_07[2]  = rightForeArm_ROTATE[2]; 

           rightHand_SET_07[3]  = rightHand_ROTATE[3];
           rightHand_SET_07[0]  = rightHand_ROTATE[0];
           rightHand_SET_07[1]  = rightHand_ROTATE[1];
           rightHand_SET_07[2]  = rightHand_ROTATE[2];            
                      //-----------------------------------------------------             
           leftUpperLeg_SET_07[3] = leftUpperLeg_ROTATE[3];
           leftUpperLeg_SET_07[0] = leftUpperLeg_ROTATE[0];
           leftUpperLeg_SET_07[1] = leftUpperLeg_ROTATE[1];
           leftUpperLeg_SET_07[2] = leftUpperLeg_ROTATE[2];
           
           leftLowerLeg_SET_07[3]  = leftLowerLeg_ROTATE[3];
           leftLowerLeg_SET_07[0]  = leftLowerLeg_ROTATE[0];
           leftLowerLeg_SET_07[1]  = leftLowerLeg_ROTATE[1];
           leftLowerLeg_SET_07[2]  = leftLowerLeg_ROTATE[2];
           
           leftFoot_SET_07[3]  = leftFoot_ROTATE[3];
           leftFoot_SET_07[0]  = leftFoot_ROTATE[0];
           leftFoot_SET_07[1]  = leftFoot_ROTATE[1];
           leftFoot_SET_07[2]  = leftFoot_ROTATE[2]; 
                      //-----------------------------------------------------    
           rightUpperLeg_SET_07[3] = rightUpperLeg_ROTATE[3];
           rightUpperLeg_SET_07[0] = rightUpperLeg_ROTATE[0];
           rightUpperLeg_SET_07[1] = rightUpperLeg_ROTATE[1];
           rightUpperLeg_SET_07[2] = rightUpperLeg_ROTATE[2];
           
           rightLowerLeg_SET_07[3]  = rightLowerLeg_ROTATE[3];
           rightLowerLeg_SET_07[0]  = rightLowerLeg_ROTATE[0];
           rightLowerLeg_SET_07[1]  = rightLowerLeg_ROTATE[1];
           rightLowerLeg_SET_07[2]  = rightLowerLeg_ROTATE[2];
           
           rightFoot_SET_07[3]  = rightFoot_ROTATE[3];
           rightFoot_SET_07[0]  = rightFoot_ROTATE[0];
           rightFoot_SET_07[1]  = rightFoot_ROTATE[1];
           rightFoot_SET_07[2]  = rightFoot_ROTATE[2]; 
                      //-----------------------------------------------------    
          
           hips_SET_07[3]  = hips_ROTATE[3];
           hips_SET_07[0]  = hips_ROTATE[0];
           hips_SET_07[1]  = hips_ROTATE[1];
           hips_SET_07[2]  = hips_ROTATE[2]; 
                      //----------------------------------------------------- 
         
           torso_SET_07[3]  = torso_ROTATE[3];
           torso_SET_07[0]  = torso_ROTATE[0];
           torso_SET_07[1]  = torso_ROTATE[1];
           torso_SET_07[2]  = torso_ROTATE[2]; 
                      //----------------------------------------------------- 
         
           head_SET_07[3]  = head_ROTATE[3];
           head_SET_07[0]  = head_ROTATE[0];
           head_SET_07[1]  = head_ROTATE[1];
           head_SET_07[2]  = head_ROTATE[2]; 
                      //----------------------------------------------------- 
    }    
//---------------------------------------------------------------------------------------
    if (keys[VK_HOME] && !homeButtonPushed) 			
	{
        positionedModelSequence -=  1;
        homeButtonPushed = true;
    }
    if (keys[VK_END] && !endButtonPushed) 			
    {
        positionedModelSequence +=  1;
        endButtonPushed = true;    
    }     
    if (!keys[VK_HOME]) 			
	{
        homeButtonPushed = false;
    }
    if (!keys[VK_END]) 			
    {
        endButtonPushed = false;    
    } 
//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
        
         //#include "_MODEL_FOLDERS_/marcParts/marc_KEYBOARD_CONTROLS.cpp"

//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
 
 
 
    if(writeAnimationFile)
    {//______________________________________________________________________________________________________BEGIN_WRITE_ANIMATION
          writeAnimationFile                   = false; 
          
          ofstream out("_MODEL_FOLDERS_/marcParts/marcAnimations/animationFiles/ME_AnimationSet.cpp");    

          //-------------------------------------------------------------------------------------------------          
          out << "hips_POSITION_setSelectionLimit  = " << hips_POSITION_setSelectionLimit <<  ";\n";    
          out << "hips_POSITION_SelectionCount     = " << hips_POSITION_SelectionCount    << ";\n\n\n";           
          //-------------------------------------------------------------------------------------------------         
          out << "setSelectionLimit_HEAD              = " << setSelectionLimit_HEAD             <<  ";\n";    
          out << "SelectionCount_HEAD                 = " << SelectionCount_HEAD                << ";\n\n\n";           
          //-------------------------------------------------------------------------------------------------          
          out << "setSelectionLimit_TORSO             = " << setSelectionLimit_TORSO            <<  ";\n";    
          out << "SelectionCount_TORSO                = " << SelectionCount_TORSO               << ";\n\n\n"; 
          //-------------------------------------------------------------------------------------------------          
          out << "setSelectionLimit_HIPS              = " << setSelectionLimit_HIPS             <<  ";\n";    
          out << "SelectionCount_HIPS                 = " << SelectionCount_HIPS                << ";\n\n\n";                              
          //-------------------------------------------------------------------------------------------------         
          out << "setSelectionLimit_LEFT_ARM          = " << setSelectionLimit_LEFT_ARM         <<  ";\n";    
          out << "SelectionCount_LEFT_ARM             = " << SelectionCount_LEFT_ARM            << ";\n\n\n";                 
          //-------------------------------------------------------------------------------------------------
          out << "setSelectionLimit_RIGHT_ARM         = " << setSelectionLimit_RIGHT_ARM        <<  ";\n";    
          out << "SelectionCount_RIGHT_ARM            = " << SelectionCount_RIGHT_ARM           << ";\n\n\n";
          //-------------------------------------------------------------------------------------------------   
          out << "setSelectionLimit_LEFT_LEG          = " << setSelectionLimit_LEFT_LEG         <<  ";\n";    
          out << "SelectionCount_LEFT_LEG             = " << SelectionCount_LEFT_LEG            << ";\n\n\n";                 
          //-------------------------------------------------------------------------------------------------
          out << "setSelectionLimit_RIGHT_LEG         = " << setSelectionLimit_RIGHT_LEG        <<  ";\n";    
          out << "SelectionCount_RIGHT_LEG            = " << SelectionCount_RIGHT_LEG           << ";\n\n\n";                    
          //-------------------------------------------------------------------------------------------------  
//################################################################################################################################################  
//################################################################################################################################################  



          
          //////////////////////____MAIN__POSITION___////////////////////////////////////////////////////////////////////   
          out << "if(hips_POSITION_setSelection == 1)" <<  "\n{\n";
          
          out << "    hips_POSITION_MOVE_FRAMEA[0]     = "  <<   hips_POSITION_SET_01[0]  <<  ";\n";
          out << "    hips_POSITION_MOVE_FRAMEA[1]     = "  <<   hips_POSITION_SET_01[1]  <<  ";\n";                   
          out << "    hips_POSITION_MOVE_FRAMEA[2]     = "  <<   hips_POSITION_SET_01[2]  <<  ";\n";
                      
          out << "    hips_POSITION_MOVE_FRAMEB[0]     = "  <<   hips_POSITION_SET_02[0]  <<  ";\n";
          out << "    hips_POSITION_MOVE_FRAMEB[1]     = "  <<   hips_POSITION_SET_02[1]  <<  ";\n";                    
          out << "    hips_POSITION_MOVE_FRAMEB[2]     = "  <<   hips_POSITION_SET_02[2]  <<  ";\n}\n";           
          
          
          //////////////////////____MAIN__POSITION___////////////////////////////////////////////////////////////////////           
         
          //////////////////////////________LEFT___ARM____///////////////////////////////////////////////////////          
          out << "if(setSelection_LEFT_ARM == 1)" <<  "\n{";

                 out << "    leftUpperArm_ROTATE_FRAMEA[3]   = "  <<  leftUpperArm_SET_01[3]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[0]   = "  <<  leftUpperArm_SET_01[0]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[1]   = "  <<  leftUpperArm_SET_01[1]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[2]   = "  <<  leftUpperArm_SET_01[2]     <<  ";\n";
                 
                 out << "    leftUpperArm_ROTATE_FRAMEB[3]   = "  <<  leftUpperArm_SET_02[3]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEB[0]   = "  <<  leftUpperArm_SET_02[0]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEB[1]   = "  <<  leftUpperArm_SET_02[1]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEB[2]   = "  <<  leftUpperArm_SET_02[2]     <<  ";\n";
                 ///_<subPart>_////                 
                 out << "    leftForeArm_ROTATE_FRAMEA[3]   = "  <<  leftForeArm_SET_01[3]     <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEA[0]   = "  <<  leftForeArm_SET_01[0]     <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEA[1]   = "  <<  leftForeArm_SET_01[1]     <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEA[2]   = "  <<  leftForeArm_SET_01[2]     <<  ";\n";
                 
                 out << "    leftForeArm_ROTATE_FRAMEB[3]   = "  <<  leftForeArm_SET_02[3]     <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEB[0]   = "  <<  leftForeArm_SET_02[0]     <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEB[1]   = "  <<  leftForeArm_SET_02[1]     <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEB[2]   = "  <<  leftForeArm_SET_02[2]     <<  ";\n";                           
                 ///_<subPart>_////          
                 out << "    leftHand_ROTATE_FRAMEA[3]   = "  <<  leftHand_SET_01[3]     <<  ";\n";
                 out << "    leftHand_ROTATE_FRAMEA[0]   = "  <<  leftHand_SET_01[0]     <<  ";\n";
                 out << "    leftHand_ROTATE_FRAMEA[1]   = "  <<  leftHand_SET_01[1]     <<  ";\n";
                 out << "    leftHand_ROTATE_FRAMEA[2]   = "  <<  leftHand_SET_01[2]     <<  ";\n";
                 
                 out << "    leftHand_ROTATE_FRAMEB[3]   = "  <<  leftHand_SET_02[3]     <<  ";\n";
                 out << "    leftHand_ROTATE_FRAMEB[0]   = "  <<  leftHand_SET_02[0]     <<  ";\n";
                 out << "    leftHand_ROTATE_FRAMEB[1]   = "  <<  leftHand_SET_02[1]     <<  ";\n";
                 out << "    leftHand_ROTATE_FRAMEB[2]   = "  <<  leftHand_SET_02[2]     <<  ";\n}\n";           
          //////////////////////////________LEFT___ARM____///////////////////////////////////////////////////////      
          
          
          //////////////////////////________RIGHT____ARM____///////////////////////////////////////////////////////           
          out << "if(setSelection_RIGHT_ARM == 1)" <<  "\n{";
                 out << "    rightUpperArm_ROTATE_FRAMEA[3]   = "  <<  rightUpperArm_SET_01[3]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[0]   = "  <<  rightUpperArm_SET_01[0]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[1]   = "  <<  rightUpperArm_SET_01[1]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[2]   = "  <<  rightUpperArm_SET_01[2]     <<  ";\n";
                 
                 out << "    rightUpperArm_ROTATE_FRAMEB[3]   = "  <<  rightUpperArm_SET_02[3]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEB[0]   = "  <<  rightUpperArm_SET_02[0]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEB[1]   = "  <<  rightUpperArm_SET_02[1]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEB[2]   = "  <<  rightUpperArm_SET_02[2]     <<  ";\n";
                 ///_<subPart>_////                 
                 out << "    rightForeArm_ROTATE_FRAMEA[3]   = "  <<  rightForeArm_SET_01[3]     <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEA[0]   = "  <<  rightForeArm_SET_01[0]     <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEA[1]   = "  <<  rightForeArm_SET_01[1]     <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEA[2]   = "  <<  rightForeArm_SET_01[2]     <<  ";\n";
                 
                 out << "    rightForeArm_ROTATE_FRAMEB[3]   = "  <<  rightForeArm_SET_02[3]     <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEB[0]   = "  <<  rightForeArm_SET_02[0]     <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEB[1]   = "  <<  rightForeArm_SET_02[1]     <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEB[2]   = "  <<  rightForeArm_SET_02[2]     <<  ";\n";                           
                 ///_<subPart>_////          
                 out << "    rightHand_ROTATE_FRAMEA[3]   = "  <<  rightHand_SET_01[3]     <<  ";\n";
                 out << "    rightHand_ROTATE_FRAMEA[0]   = "  <<  rightHand_SET_01[0]     <<  ";\n";
                 out << "    rightHand_ROTATE_FRAMEA[1]   = "  <<  rightHand_SET_01[1]     <<  ";\n";
                 out << "    rightHand_ROTATE_FRAMEA[2]   = "  <<  rightHand_SET_01[2]     <<  ";\n";
                 
                 out << "    rightHand_ROTATE_FRAMEB[3]   = "  <<  rightHand_SET_02[3]     <<  ";\n";
                 out << "    rightHand_ROTATE_FRAMEB[0]   = "  <<  rightHand_SET_02[0]     <<  ";\n";
                 out << "    rightHand_ROTATE_FRAMEB[1]   = "  <<  rightHand_SET_02[1]     <<  ";\n";
                 out << "    rightHand_ROTATE_FRAMEB[2]   = "  <<  rightHand_SET_02[2]     <<  ";\n}\n";           
           //////////////////////////________RIGHT___ARM____//////////////////////////////////////////////////////// 
           
         
           //////////////////////////________LEFT___ARM____///////////////////////////////////////////////////////          
           out << "if(setSelection_LEFT_LEG == 1)" <<  "\n{";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[3]   = "  <<  leftUpperLeg_SET_01[3]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[0]   = "  <<  leftUpperLeg_SET_01[0]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[1]   = "  <<  leftUpperLeg_SET_01[1]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[2]   = "  <<  leftUpperLeg_SET_01[2]     <<  ";\n";
                 
                 out << "    leftUpperLeg_ROTATE_FRAMEB[3]   = "  <<  leftUpperLeg_SET_02[3]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[0]   = "  <<  leftUpperLeg_SET_02[0]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[1]   = "  <<  leftUpperLeg_SET_02[1]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[2]   = "  <<  leftUpperLeg_SET_02[2]     <<  ";\n";
                 
                 out << "    leftLowerLeg_ROTATE_FRAMEA[3]   = "  <<  leftLowerLeg_SET_01[3]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEA[0]   = "  <<  leftLowerLeg_SET_01[0]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEA[1]   = "  <<  leftLowerLeg_SET_01[1]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEA[2]   = "  <<  leftLowerLeg_SET_01[2]     <<  ";\n";
                 
                 out << "    leftLowerLeg_ROTATE_FRAMEB[3]   = "  <<  leftLowerLeg_SET_02[3]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[0]   = "  <<  leftLowerLeg_SET_02[0]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[1]   = "  <<  leftLowerLeg_SET_02[1]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[2]   = "  <<  leftLowerLeg_SET_02[2]     <<  ";\n";                           
          
                 out << "    leftFoot_ROTATE_FRAMEA[3]       = "  <<  leftFoot_SET_01[3]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEA[0]       = "  <<  leftFoot_SET_01[0]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEA[1]       = "  <<  leftFoot_SET_01[1]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEA[2]       = "  <<  leftFoot_SET_01[2]     <<  ";\n";
                 
                 out << "    leftFoot_ROTATE_FRAMEB[3]       = "  <<  leftFoot_SET_02[3]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[0]       = "  <<  leftFoot_SET_02[0]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[1]       = "  <<  leftFoot_SET_02[1]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[2]       = "  <<  leftFoot_SET_02[2]     <<  ";\n}\n";            
          //////////////////////////________LEFT___ARM____///////////////////////////////////////////////////////      
          
          
          //////////////////////////________RIGHT____ARM____///////////////////////////////////////////////////////           
          out << "if(setSelection_RIGHT_LEG == 1)" <<  "\n{";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[3]   = "  <<  rightUpperLeg_SET_01[3]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[0]   = "  <<  rightUpperLeg_SET_01[0]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[1]   = "  <<  rightUpperLeg_SET_01[1]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[2]   = "  <<  rightUpperLeg_SET_01[2]     <<  ";\n";
                 
                 out << "    rightUpperLeg_ROTATE_FRAMEB[3]   = "  <<  rightUpperLeg_SET_02[3]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[0]   = "  <<  rightUpperLeg_SET_02[0]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[1]   = "  <<  rightUpperLeg_SET_02[1]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[2]   = "  <<  rightUpperLeg_SET_02[2]     <<  ";\n";
                
                 out << "    rightLowerLeg_ROTATE_FRAMEA[3]   = "  <<  rightLowerLeg_SET_01[3]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEA[0]   = "  <<  rightLowerLeg_SET_01[0]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEA[1]   = "  <<  rightLowerLeg_SET_01[1]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEA[2]   = "  <<  rightLowerLeg_SET_01[2]     <<  ";\n";
                 
                 out << "    rightLowerLeg_ROTATE_FRAMEB[3]   = "  <<  rightLowerLeg_SET_02[3]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[0]   = "  <<  rightLowerLeg_SET_02[0]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[1]   = "  <<  rightLowerLeg_SET_02[1]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[2]   = "  <<  rightLowerLeg_SET_02[2]     <<  ";\n";                           
        
                 out << "    rightFoot_ROTATE_FRAMEA[3]   = "  <<  rightFoot_SET_01[3]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEA[0]   = "  <<  rightFoot_SET_01[0]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEA[1]   = "  <<  rightFoot_SET_01[1]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEA[2]   = "  <<  rightFoot_SET_01[2]     <<  ";\n";
                 
                 out << "    rightFoot_ROTATE_FRAMEB[3]   = "  <<  rightFoot_SET_02[3]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[0]   = "  <<  rightFoot_SET_02[0]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[1]   = "  <<  rightFoot_SET_02[1]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[2]   = "  <<  rightFoot_SET_02[2]     <<  ";\n}\n";           
           //////////////////////////________RIGHT___ARM____////////////////////////////////////////////////////////            
        
          
           //////////////////////____HEAD__POSITION___////////////////////////////////////////////////////////////////////   
           out << "if(setSelection_HEAD == 1)" <<  "\n{\n";
          
                 out << "    head_ROTATE_FRAMEA[3]   = "  <<  head_SET_01[3]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEA[0]   = "  <<  head_SET_01[0]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEA[1]   = "  <<  head_SET_01[1]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEA[2]   = "  <<  head_SET_01[2]     <<  ";\n";          

                 out << "    head_ROTATE_FRAMEB[3]   = "  <<  head_SET_02[3]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[0]   = "  <<  head_SET_02[0]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[1]   = "  <<  head_SET_02[1]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[2]   = "  <<  head_SET_02[2]     <<  ";\n}\n";              
          //////////////////////____HEAD__POSITION___////////////////////////////////////////////////////////////////////           
           
         
          //////////////////////____TORSO__POSITION___////////////////////////////////////////////////////////////////////   
          out << "if(setSelection_TORSO == 1)" <<  "\n{\n";
                 out << "    torso_ROTATE_FRAMEA[3]   = "  <<  torso_SET_01[3]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEA[0]   = "  <<  torso_SET_01[0]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEA[1]   = "  <<  torso_SET_01[1]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEA[2]   = "  <<  torso_SET_01[2]     <<  ";\n";          

                 out << "    torso_ROTATE_FRAMEB[3]   = "  <<  torso_SET_02[3]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[0]   = "  <<  torso_SET_02[0]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[1]   = "  <<  torso_SET_02[1]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[2]   = "  <<  torso_SET_02[2]     <<  ";\n}\n";             
          //////////////////////____TORSO__POSITION___////////////////////////////////////////////////////////////////////           
          
          //////////////////////____HIPS__POSITION___////////////////////////////////////////////////////////////////////   
          out << "if(setSelection_HIPS == 1)" <<  "\n{\n";
                 out << "    hips_ROTATE_FRAMEA[3]   = "  <<  hips_SET_01[3]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEA[0]   = "  <<  hips_SET_01[0]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEA[1]   = "  <<  hips_SET_01[1]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEA[2]   = "  <<  hips_SET_01[2]     <<  ";\n";          
          
                 out << "    hips_ROTATE_FRAMEB[3]   = "  <<  hips_SET_02[3]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[0]   = "  <<  hips_SET_02[0]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[1]   = "  <<  hips_SET_02[1]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[2]   = "  <<  hips_SET_02[2]     <<  ";\n}\n";             
          //////////////////////____HIPS__POSITION___//////////////////////////////////////////////////////////////////// 
                 
//################################################################################################################################################  
//################################################################################################################################################           

         

          
          //////////////////////____MAIN__POSITION___////////////////////////////////////////////////////////////////////      
          out << "if(hips_POSITION_setSelection == 2)" <<  "\n{\n";
              out << "    hips_POSITION_MOVE_FRAMEA[0]         = "  <<  hips_POSITION_SET_02[0]         <<  ";\n";
              out << "    hips_POSITION_MOVE_FRAMEA[1]         = "  <<  hips_POSITION_SET_02[1]         <<  ";\n";                 
              out << "    hips_POSITION_MOVE_FRAMEA[2]         = "  <<  hips_POSITION_SET_02[2]         <<  ";\n\n";
          out << "   if(hips_POSITION_SelectionCount == 2)" <<  "\n{\n";          
              out << "   hips_POSITION_MOVE_FRAMEB[0]          = "  <<   hips_POSITION_SET_01[0]  <<  ";\n";
              out << "   hips_POSITION_MOVE_FRAMEB[1]          = "  <<   hips_POSITION_SET_01[1]  <<  ";\n";                   
              out << "   hips_POSITION_MOVE_FRAMEB[2]          = "  <<   hips_POSITION_SET_01[2]  <<  ";\n}\n";
          out << "     else " <<  "\n    {\n";          
              out << "    hips_POSITION_MOVE_FRAMEB[0]         = "  <<   hips_POSITION_SET_03[0]  <<  ";\n";
              out << "    hips_POSITION_MOVE_FRAMEB[1]         = "  <<   hips_POSITION_SET_03[1]  <<  ";\n";                      
              out << "    hips_POSITION_MOVE_FRAMEB[2]         = "  <<   hips_POSITION_SET_03[2]  <<  ";\n}\n}\n";          
          //////////////////////____MAIN__POSITION___//////////////////////////////////////////////////////////////// 
                        
                           
          //////////////////////____LEFT___ARM___////////////////////////////////////////////////////////////////////          
          out << "if(setSelection_LEFT_ARM == 2)" <<  "\n{\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[3]     = "  <<  leftUpperArm_SET_02[3]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[0]     = "  <<  leftUpperArm_SET_02[0]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[1]     = "  <<  leftUpperArm_SET_02[1]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[2]     = "  <<  leftUpperArm_SET_02[2]     <<  ";\n";
                
                 out << "    leftForeArm_ROTATE_FRAMEA[3]      = "  <<  leftForeArm_SET_02[3]      <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEA[0]      = "  <<  leftForeArm_SET_02[0]      <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEA[1]      = "  <<  leftForeArm_SET_02[1]      <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEA[2]      = "  <<  leftForeArm_SET_02[2]      <<  ";\n";                 
          
                 out << "    leftHand_ROTATE_FRAMEA[3]   = "  <<  leftHand_SET_02[3]     <<  ";\n";
                 out << "    leftHand_ROTATE_FRAMEA[0]   = "  <<  leftHand_SET_02[0]     <<  ";\n";
                 out << "    leftHand_ROTATE_FRAMEA[1]   = "  <<  leftHand_SET_02[1]     <<  ";\n";
                 out << "    leftHand_ROTATE_FRAMEA[2]   = "  <<  leftHand_SET_02[2]     <<  ";\n";          
          
          out << "     if(SelectionCount_LEFT_ARM == 2)" <<  "\n    {\n";          
                 out << "    leftUpperArm_ROTATE_FRAMEB[3]     = "  <<  leftUpperArm_SET_01[3]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEB[0]     = "  <<  leftUpperArm_SET_01[0]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEB[1]     = "  <<  leftUpperArm_SET_01[1]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEB[2]     = "  <<  leftUpperArm_SET_01[2]     <<  ";\n";           
                 
                 out << "    leftForeArm_ROTATE_FRAMEB[3]      = "  <<  leftForeArm_SET_01[3]     <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEB[0]      = "  <<  leftForeArm_SET_01[0]     <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEB[1]      = "  <<  leftForeArm_SET_01[1]     <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEB[2]      = "  <<  leftForeArm_SET_01[2]     <<  ";\n";         
                
                out << "    leftHand_ROTATE_FRAMEB[3]    = "  <<  leftHand_SET_01[3]     <<  ";\n";
                out << "    leftHand_ROTATE_FRAMEB[0]    = "  <<  leftHand_SET_01[0]     <<  ";\n";
                out << "    leftHand_ROTATE_FRAMEB[1]    = "  <<  leftHand_SET_01[1]     <<  ";\n";
                out << "    leftHand_ROTATE_FRAMEB[2]    = "  <<  leftHand_SET_01[2]     <<  ";\n}\n";           
          out << "     else " <<  "\n    {\n";          
                out << "    leftUpperArm_ROTATE_FRAMEB[3]      = "  <<  leftUpperArm_SET_03[3]     <<  ";\n";
                out << "    leftUpperArm_ROTATE_FRAMEB[0]      = "  <<  leftUpperArm_SET_03[0]     <<  ";\n";
                out << "    leftUpperArm_ROTATE_FRAMEB[1]      = "  <<  leftUpperArm_SET_03[1]     <<  ";\n";
                out << "    leftUpperArm_ROTATE_FRAMEB[2]      = "  <<  leftUpperArm_SET_03[2]     <<  ";\n";          
               
                out << "    leftForeArm_ROTATE_FRAMEB[3]       = "  <<  leftForeArm_SET_03[3]     <<  ";\n";
                out << "    leftForeArm_ROTATE_FRAMEB[0]       = "  <<  leftForeArm_SET_03[0]     <<  ";\n";
                out << "    leftForeArm_ROTATE_FRAMEB[1]       = "  <<  leftForeArm_SET_03[1]     <<  ";\n";
                out << "    leftForeArm_ROTATE_FRAMEB[2]       = "  <<  leftForeArm_SET_03[2]     <<  ";\n";                          
                         
                out << "    leftHand_ROTATE_FRAMEB[3]    = "  <<  leftHand_SET_03[3]     <<  ";\n";
                out << "    leftHand_ROTATE_FRAMEB[0]    = "  <<  leftHand_SET_03[0]     <<  ";\n";
                out << "    leftHand_ROTATE_FRAMEB[1]    = "  <<  leftHand_SET_03[1]     <<  ";\n";
                out << "    leftHand_ROTATE_FRAMEB[2]    = "  <<  leftHand_SET_03[2]     <<  ";\n}\n}\n";         
          //////////////////////____LEFT___ARM___////////////////////////////////////////////////////////////////////           
          
          //////////////////////____RIGHT___ARM___////////////////////////////////////////////////////////////////////          
          out << "if(setSelection_RIGHT_ARM == 2)" <<  "\n{\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[3]   = "  <<  rightUpperArm_SET_02[3]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[0]   = "  <<  rightUpperArm_SET_02[0]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[1]   = "  <<  rightUpperArm_SET_02[1]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[2]   = "  <<  rightUpperArm_SET_02[2]     <<  ";\n";
                
                 out << "    rightForeArm_ROTATE_FRAMEA[3]    = "  <<  rightForeArm_SET_02[3]      <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEA[0]    = "  <<  rightForeArm_SET_02[0]      <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEA[1]    = "  <<  rightForeArm_SET_02[1]      <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEA[2]    = "  <<  rightForeArm_SET_02[2]      <<  ";\n";                 
          
                 out << "    rightHand_ROTATE_FRAMEA[3]   = "  <<  rightHand_SET_02[3]     <<  ";\n";
                 out << "    rightHand_ROTATE_FRAMEA[0]   = "  <<  rightHand_SET_02[0]     <<  ";\n";
                 out << "    rightHand_ROTATE_FRAMEA[1]   = "  <<  rightHand_SET_02[1]     <<  ";\n";
                 out << "    rightHand_ROTATE_FRAMEA[2]   = "  <<  rightHand_SET_02[2]     <<  ";\n";          
          
          out << "     if(SelectionCount_RIGHT_ARM == 2)" <<  "\n    {\n";          
                 out << "    rightUpperArm_ROTATE_FRAMEB[3]   = "  <<  rightUpperArm_SET_01[3]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEB[0]   = "  <<  rightUpperArm_SET_01[0]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEB[1]   = "  <<  rightUpperArm_SET_01[1]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEB[2]   = "  <<  rightUpperArm_SET_01[2]     <<  ";\n";           
                 
                 out << "    rightForeArm_ROTATE_FRAMEB[3]   = "  <<  rightForeArm_SET_01[3]     <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEB[0]   = "  <<  rightForeArm_SET_01[0]     <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEB[1]   = "  <<  rightForeArm_SET_01[1]     <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEB[2]   = "  <<  rightForeArm_SET_01[2]     <<  ";\n";         
                
                out << "    rightHand_ROTATE_FRAMEB[3]   = "  <<  rightHand_SET_01[3]     <<  ";\n";
                out << "    rightHand_ROTATE_FRAMEB[0]   = "  <<  rightHand_SET_01[0]     <<  ";\n";
                out << "    rightHand_ROTATE_FRAMEB[1]   = "  <<  rightHand_SET_01[1]     <<  ";\n";
                out << "    rightHand_ROTATE_FRAMEB[2]   = "  <<  rightHand_SET_01[2]     <<  ";\n}\n";           
          out << "     else " <<  "\n    {\n";          
                out << "    rightUpperArm_ROTATE_FRAMEB[3]   = "  <<  rightUpperArm_SET_03[3]     <<  ";\n";
                out << "    rightUpperArm_ROTATE_FRAMEB[0]   = "  <<  rightUpperArm_SET_03[0]     <<  ";\n";
                out << "    rightUpperArm_ROTATE_FRAMEB[1]   = "  <<  rightUpperArm_SET_03[1]     <<  ";\n";
                out << "    rightUpperArm_ROTATE_FRAMEB[2]   = "  <<  rightUpperArm_SET_03[2]     <<  ";\n";          
               
                out << "    rightForeArm_ROTATE_FRAMEB[3]   = "  <<  rightForeArm_SET_03[3]     <<  ";\n";
                out << "    rightForeArm_ROTATE_FRAMEB[0]   = "  <<  rightForeArm_SET_03[0]     <<  ";\n";
                out << "    rightForeArm_ROTATE_FRAMEB[1]   = "  <<  rightForeArm_SET_03[1]     <<  ";\n";
                out << "    rightForeArm_ROTATE_FRAMEB[2]   = "  <<  rightForeArm_SET_03[2]     <<  ";\n";                          
                         
                out << "    rightHand_ROTATE_FRAMEB[3]   = "  <<  rightHand_SET_03[3]     <<  ";\n";
                out << "    rightHand_ROTATE_FRAMEB[0]   = "  <<  rightHand_SET_03[0]     <<  ";\n";
                out << "    rightHand_ROTATE_FRAMEB[1]   = "  <<  rightHand_SET_03[1]     <<  ";\n";
                out << "    rightHand_ROTATE_FRAMEB[2]   = "  <<  rightHand_SET_03[2]     <<  ";\n}\n}\n";         
          //////////////////////____RIGHT___ARM___////////////////////////////////////////////////////////////////////           
                      
          //////////////////////____LEFT___LEG___////////////////////////////////////////////////////////////////////          
          out << "if(setSelection_LEFT_LEG == 2)" <<  "\n{\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[3]   = "  <<  leftUpperLeg_SET_02[3]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[0]   = "  <<  leftUpperLeg_SET_02[0]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[1]   = "  <<  leftUpperLeg_SET_02[1]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[2]   = "  <<  leftUpperLeg_SET_02[2]     <<  ";\n";
         
                 out << "    leftLowerLeg_ROTATE_FRAMEA[3]   = "  <<  leftLowerLeg_SET_02[3]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEA[0]   = "  <<  leftLowerLeg_SET_02[0]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEA[1]   = "  <<  leftLowerLeg_SET_02[1]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEA[2]   = "  <<  leftLowerLeg_SET_02[2]     <<  ";\n";                 
             
                 out << "    leftFoot_ROTATE_FRAMEA[3]   = "  <<  leftFoot_SET_02[3]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEA[0]   = "  <<  leftFoot_SET_02[0]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEA[1]   = "  <<  leftFoot_SET_02[1]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEA[2]   = "  <<  leftFoot_SET_02[2]     <<  ";\n";          
          
          out << "     if(SelectionCount_LEFT_LEG == 2)" <<  "\n    {\n";          
                 out << "    leftUpperLeg_ROTATE_FRAMEB[3]   = "  <<  leftUpperLeg_SET_01[3]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[0]   = "  <<  leftUpperLeg_SET_01[0]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[1]   = "  <<  leftUpperLeg_SET_01[1]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[2]   = "  <<  leftUpperLeg_SET_01[2]     <<  ";\n";           
                    
                 out << "    leftLowerLeg_ROTATE_FRAMEB[3]   = "  <<  leftLowerLeg_SET_01[3]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[0]   = "  <<  leftLowerLeg_SET_01[0]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[1]   = "  <<  leftLowerLeg_SET_01[1]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[2]   = "  <<  leftLowerLeg_SET_01[2]     <<  ";\n";         
                      
                 out << "    leftFoot_ROTATE_FRAMEB[3]   = "  <<  leftFoot_SET_01[3]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[0]   = "  <<  leftFoot_SET_01[0]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[1]   = "  <<  leftFoot_SET_01[1]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[2]   = "  <<  leftFoot_SET_01[2]      <<  ";\n}\n";             
          out << "     else " <<  "\n    {\n";          
        
                 out << "    leftUpperLeg_ROTATE_FRAMEB[3]   = "  <<  leftUpperLeg_SET_03[3]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[0]   = "  <<  leftUpperLeg_SET_03[0]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[1]   = "  <<  leftUpperLeg_SET_03[1]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[2]   = "  <<  leftUpperLeg_SET_03[2]     <<  ";\n";          
                                                 
                 out << "    leftLowerLeg_ROTATE_FRAMEB[3]   = "  <<  leftLowerLeg_SET_03[3]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[0]   = "  <<  leftLowerLeg_SET_03[0]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[1]   = "  <<  leftLowerLeg_SET_03[1]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[2]   = "  <<  leftLowerLeg_SET_03[2]     <<  ";\n";                          
                             
                 out << "    leftFoot_ROTATE_FRAMEB[3]   = "  <<  leftFoot_SET_03[3]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[0]   = "  <<  leftFoot_SET_03[0]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[1]   = "  <<  leftFoot_SET_03[1]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[2]   = "  <<  leftFoot_SET_03[2]     <<  ";\n}\n}\n";              
          //////////////////////____LEFT___LEG___////////////////////////////////////////////////////////////////////           
          
          //////////////////////____RIGHT___LEG__////////////////////////////////////////////////////////////////////          
          out << "if(setSelection_RIGHT_LEG == 2)" <<  "\n{\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[3]   = "  <<  rightUpperLeg_SET_02[3]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[0]   = "  <<  rightUpperLeg_SET_02[0]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[1]   = "  <<  rightUpperLeg_SET_02[1]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[2]   = "  <<  rightUpperLeg_SET_02[2]     <<  ";\n";
                            
                 out << "    rightLowerLeg_ROTATE_FRAMEA[3]   = "  <<  rightLowerLeg_SET_02[3]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEA[0]   = "  <<  rightLowerLeg_SET_02[0]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEA[1]   = "  <<  rightLowerLeg_SET_02[1]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEA[2]   = "  <<  rightLowerLeg_SET_02[2]     <<  ";\n";                 
           
                 out << "    rightFoot_ROTATE_FRAMEA[3]   = "  <<  rightFoot_SET_02[3]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEA[0]   = "  <<  rightFoot_SET_02[0]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEA[1]   = "  <<  rightFoot_SET_02[1]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEA[2]   = "  <<  rightFoot_SET_02[2]     <<  ";\n";        
          
          out << "     if(SelectionCount_RIGHT_LEG == 2)" <<  "\n    {\n";          
                 out << "    rightUpperLeg_ROTATE_FRAMEB[3]   = "  <<  rightUpperLeg_SET_01[3]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[0]   = "  <<  rightUpperLeg_SET_01[0]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[1]   = "  <<  rightUpperLeg_SET_01[1]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[2]   = "  <<  rightUpperLeg_SET_01[2]     <<  ";\n";           
                      
                 out << "    rightLowerLeg_ROTATE_FRAMEB[3]   = "  <<  rightLowerLeg_SET_01[3]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[0]   = "  <<  rightLowerLeg_SET_01[0]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[1]   = "  <<  rightLowerLeg_SET_01[1]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[2]   = "  <<  rightLowerLeg_SET_01[2]     <<  ";\n";         
                     
                 out << "    rightFoot_ROTATE_FRAMEB[3]   = "  <<  rightFoot_SET_01[3]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[0]   = "  <<  rightFoot_SET_01[0]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[1]   = "  <<  rightFoot_SET_01[1]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[2]   = "  <<  rightFoot_SET_01[2]      <<  ";\n}\n";          
          out << "     else " <<  "\n    {\n";          
                 out << "    rightUpperLeg_ROTATE_FRAMEB[3]   = "  <<  rightUpperLeg_SET_03[3]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[0]   = "  <<  rightUpperLeg_SET_03[0]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[1]   = "  <<  rightUpperLeg_SET_03[1]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[2]   = "  <<  rightUpperLeg_SET_03[2]     <<  ";\n";          
                                              
                 out << "    rightLowerLeg_ROTATE_FRAMEB[3]   = "  <<  rightLowerLeg_SET_03[3]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[0]   = "  <<  rightLowerLeg_SET_03[0]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[1]   = "  <<  rightLowerLeg_SET_03[1]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[2]   = "  <<  rightLowerLeg_SET_03[2]     <<  ";\n";                          
                            
                 out << "    rightFoot_ROTATE_FRAMEB[3]   = "  <<  rightFoot_SET_03[3]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[0]   = "  <<  rightFoot_SET_03[0]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[1]   = "  <<  rightFoot_SET_03[1]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[2]   = "  <<  rightFoot_SET_03[2]     <<  ";\n}\n}\n";              
          //////////////////////____RIGHT___ARM___////////////////////////////////////////////////////////////////////           
         
          //////////////////////____HEAD__POSITION___////////////////////////////////////////////////////////////////////      
          out << "if(setSelection_HEAD == 2)" <<  "\n{\n";
                 out << "    head_ROTATE_FRAMEA[3]   = "  <<  head_SET_02[3]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEA[0]   = "  <<  head_SET_02[0]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEA[1]   = "  <<  head_SET_02[1]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEA[2]   = "  <<  head_SET_02[2]     <<  ";\n"; 
          
          out << "   if(SelectionCount_HEAD == 2)" <<  "\n{\n";          
                 out << "    head_ROTATE_FRAMEB[3]   = "  <<  head_SET_01[3]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[0]   = "  <<  head_SET_01[0]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[1]   = "  <<  head_SET_01[1]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[2]   = "  <<  head_SET_01[2]     <<  ";\n}\n";   
          
          out << "     else " <<  "\n    {\n";          
                 out << "    head_ROTATE_FRAMEB[3]   = "  <<  head_SET_03[3]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[0]   = "  <<  head_SET_03[0]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[1]   = "  <<  head_SET_03[1]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[2]   = "  <<  head_SET_03[2]     <<  ";\n}\n}\n";        
          //////////////////////____HEAD__POSITION___////////////////////////////////////////////////////////////////          

          //////////////////////____TORSO__POSITION___////////////////////////////////////////////////////////////////////      
          out << "if(setSelection_TORSO == 2)" <<  "\n{\n";
                 out << "    torso_ROTATE_FRAMEA[3]   = "  <<  torso_SET_02[3]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEA[0]   = "  <<  torso_SET_02[0]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEA[1]   = "  <<  torso_SET_02[1]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEA[2]   = "  <<  torso_SET_02[2]     <<  ";\n"; 
          
          out << "   if(SelectionCount_TORSO == 2)" <<  "\n{\n";          
                 out << "    torso_ROTATE_FRAMEB[3]   = "  <<  torso_SET_01[3]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[0]   = "  <<  torso_SET_01[0]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[1]   = "  <<  torso_SET_01[1]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[2]   = "  <<  torso_SET_01[2]     <<  ";\n}\n";  
          
          out << "     else " <<  "\n    {\n";          
                 out << "    torso_ROTATE_FRAMEB[3]   = "  <<  torso_SET_03[3]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[0]   = "  <<  torso_SET_03[0]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[1]   = "  <<  torso_SET_03[1]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[2]   = "  <<  torso_SET_03[2]     <<  ";\n}\n}\n";        
          //////////////////////____TORSO__POSITION___////////////////////////////////////////////////////////////////          
        
          //////////////////////____HIPS__POSITION___////////////////////////////////////////////////////////////////////      
          out << "if(setSelection_HIPS == 2)" <<  "\n{\n";
                 out << "    hips_ROTATE_FRAMEA[3]   = "  <<  hips_SET_02[3]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEA[0]   = "  <<  hips_SET_02[0]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEA[1]   = "  <<  hips_SET_02[1]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEA[2]   = "  <<  hips_SET_02[2]     <<  ";\n"; 
          
          out << "   if(SelectionCount_HIPS == 2)" <<  "\n{\n";          
                 out << "    hips_ROTATE_FRAMEB[3]   = "  <<  hips_SET_01[3]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[0]   = "  <<  hips_SET_01[0]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[1]   = "  <<  hips_SET_01[1]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[2]   = "  <<  hips_SET_01[2]     <<  ";\n}\n";  
          
          out << "     else " <<  "\n    {\n";          
                 out << "    hips_ROTATE_FRAMEB[3]   = "  <<  hips_SET_03[3]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[0]   = "  <<  hips_SET_03[0]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[1]   = "  <<  hips_SET_03[1]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[2]   = "  <<  hips_SET_03[2]     <<  ";\n}\n}\n";    
          //////////////////////____HIPS__POSITION___//////////////////////////////////////////////////////////////// 
                   
//################################################################################################################################################
          
       
      //////////////////////____MAIN__POSITION___////////////////////////////////////////////////////////////////////           
          
          out << "if(hips_POSITION_setSelection == 3)" <<  "\n{\n";
                 out << "    hips_POSITION_MOVE_FRAMEA[0]      = "  <<  hips_POSITION_SET_03[0]  <<  ";\n";
                 out << "    hips_POSITION_MOVE_FRAMEA[1]      = "  <<  hips_POSITION_SET_03[1]  <<  ";\n";                     
                 out << "    hips_POSITION_MOVE_FRAMEA[2]      = "  <<  hips_POSITION_SET_03[2]  <<  ";\n\n";          
          
          out << "     if(hips_POSITION_SelectionCount == 3)" <<  "\n    {\n";          
                 out << "    hips_POSITION_MOVE_FRAMEB[0]      = "  <<  hips_POSITION_SET_01[0]  <<  ";\n";
                 out << "    hips_POSITION_MOVE_FRAMEB[1]      = "  <<  hips_POSITION_SET_01[1]  <<  ";\n";                      
                 out << "    hips_POSITION_MOVE_FRAMEB[2]      = "  <<  hips_POSITION_SET_01[2]  <<  ";\n}\n";          
          
          out << "     else" <<  "\n    {\n";
                 out << "    hips_POSITION_MOVE_FRAMEB[0]      = "  <<  hips_POSITION_SET_04[0]  <<  ";\n";
                 out << "    hips_POSITION_MOVE_FRAMEB[1]      = "  <<  hips_POSITION_SET_04[1]  <<  ";\n";                      
                 out << "    hips_POSITION_MOVE_FRAMEB[2]      = "  <<  hips_POSITION_SET_04[2]  <<  ";\n}\n}\n";           
          //////////////////////____MAIN__POSITION___////////////////////////////////////////////////////////////////////          
         
          //////////////////////____LEFT___ARM___////////////////////////////////////////////////////////////////////          
          out << "if(setSelection_LEFT_ARM == 3)" <<  "\n{\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[3]   = "  <<  leftUpperArm_SET_03[3]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[0]   = "  <<  leftUpperArm_SET_03[0]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[1]   = "  <<  leftUpperArm_SET_03[1]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[2]   = "  <<  leftUpperArm_SET_03[2]     <<  ";\n";
                          
                 out << "    leftForeArm_ROTATE_FRAMEA[3]    = "  <<  leftForeArm_SET_03[3]      <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEA[0]    = "  <<  leftForeArm_SET_03[0]      <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEA[1]    = "  <<  leftForeArm_SET_03[1]      <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEA[2]    = "  <<  leftForeArm_SET_03[2]      <<  ";\n";          
                   
                 out << "    leftHand_ROTATE_FRAMEA[3] = "  <<  leftHand_SET_03[3]   <<  ";\n";
                 out << "    leftHand_ROTATE_FRAMEA[0] = "  <<  leftHand_SET_03[0]   <<  ";\n";
                 out << "    leftHand_ROTATE_FRAMEA[1] = "  <<  leftHand_SET_03[1]   <<  ";\n";
                 out << "    leftHand_ROTATE_FRAMEA[2] = "  <<  leftHand_SET_03[2]   <<  ";\n\n";         
          out << "     if(SelectionCount_LEFT_ARM == 3)" <<  "\n    {\n";          
                 out << "    leftUpperArm_ROTATE_FRAMEB[3]   = "  <<  leftUpperArm_SET_01[3]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEB[0]   = "  <<  leftUpperArm_SET_01[0]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEB[1]   = "  <<  leftUpperArm_SET_01[1]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEB[2]   = "  <<  leftUpperArm_SET_01[2]     <<  ";\n";          
                   
                 out << "    leftForeArm_ROTATE_FRAMEB[3]   = "  <<  leftForeArm_SET_01[3]     <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEB[0]   = "  <<  leftForeArm_SET_01[0]     <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEB[1]   = "  <<  leftForeArm_SET_01[1]     <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEB[2]   = "  <<  leftForeArm_SET_01[2]     <<  ";\n";          
         
                 out << "    leftHand_ROTATE_FRAMEB[3]   = "  <<  leftHand_SET_01[3]     <<  ";\n";
                 out << "    leftHand_ROTATE_FRAMEB[0]   = "  <<  leftHand_SET_01[0]     <<  ";\n";
                 out << "    leftHand_ROTATE_FRAMEB[1]   = "  <<  leftHand_SET_01[1]     <<  ";\n";
                 out << "    leftHand_ROTATE_FRAMEB[2]   = "  <<  leftHand_SET_01[2]     <<  ";\n}\n";       
          
          out << "     else" <<  "\n    {\n";
                 out << "    leftUpperArm_ROTATE_FRAMEB[3]   = "  <<  leftUpperArm_SET_04[3]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEB[0]   = "  <<  leftUpperArm_SET_04[0]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEB[1]   = "  <<  leftUpperArm_SET_04[1]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEB[2]   = "  <<  leftUpperArm_SET_04[2]     <<  ";\n";          
           
                 out << "    leftForeArm_ROTATE_FRAMEB[3]   = "  <<  leftForeArm_SET_04[3]     <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEB[0]   = "  <<  leftForeArm_SET_04[0]     <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEB[1]   = "  <<  leftForeArm_SET_04[1]     <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEB[2]   = "  <<  leftForeArm_SET_04[2]     <<  ";\n";          
            
                 out << "    leftHand_ROTATE_FRAMEB[3]   = "  <<  leftHand_SET_04[3]     <<  ";\n";
                 out << "    leftHand_ROTATE_FRAMEB[0]   = "  <<  leftHand_SET_04[0]     <<  ";\n";
                 out << "    leftHand_ROTATE_FRAMEB[1]   = "  <<  leftHand_SET_04[1]     <<  ";\n";
                 out << "    leftHand_ROTATE_FRAMEB[2]   = "  <<  leftHand_SET_04[2]     <<  ";\n}\n}\n";
          //////////////////////____LEFT___ARM___////////////////////////////////////////////////////////////////////          
          
          //////////////////////____RIGHT___ARM___////////////////////////////////////////////////////////////////////          
          out << "if(setSelection_RIGHT_ARM == 3)" <<  "\n{\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[3]   = "  <<  rightUpperArm_SET_03[3]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[0]   = "  <<  rightUpperArm_SET_03[0]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[1]   = "  <<  rightUpperArm_SET_03[1]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[2]   = "  <<  rightUpperArm_SET_03[2]     <<  ";\n";
                          
                 out << "    rightForeArm_ROTATE_FRAMEA[3]    = "  <<  rightForeArm_SET_03[3]      <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEA[0]    = "  <<  rightForeArm_SET_03[0]      <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEA[1]    = "  <<  rightForeArm_SET_03[1]      <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEA[2]    = "  <<  rightForeArm_SET_03[2]      <<  ";\n";          
                   
                 out << "    rightHand_ROTATE_FRAMEA[3] = "  <<  rightHand_SET_03[3]   <<  ";\n";
                 out << "    rightHand_ROTATE_FRAMEA[0] = "  <<  rightHand_SET_03[0]   <<  ";\n";
                 out << "    rightHand_ROTATE_FRAMEA[1] = "  <<  rightHand_SET_03[1]   <<  ";\n";
                 out << "    rightHand_ROTATE_FRAMEA[2] = "  <<  rightHand_SET_03[2]   <<  ";\n\n";         
          out << "     if(SelectionCount_RIGHT_ARM == 3)" <<  "\n    {\n";          
                 out << "    rightUpperArm_ROTATE_FRAMEB[3]   = "  <<  rightUpperArm_SET_01[3]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEB[0]   = "  <<  rightUpperArm_SET_01[0]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEB[1]   = "  <<  rightUpperArm_SET_01[1]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEB[2]   = "  <<  rightUpperArm_SET_01[2]     <<  ";\n";          
                   
                 out << "    rightForeArm_ROTATE_FRAMEB[3]   = "  <<  rightForeArm_SET_01[3]     <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEB[0]   = "  <<  rightForeArm_SET_01[0]     <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEB[1]   = "  <<  rightForeArm_SET_01[1]     <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEB[2]   = "  <<  rightForeArm_SET_01[2]     <<  ";\n";          
         
                 out << "    rightHand_ROTATE_FRAMEB[3]   = "  <<  rightHand_SET_01[3]     <<  ";\n";
                 out << "    rightHand_ROTATE_FRAMEB[0]   = "  <<  rightHand_SET_01[0]     <<  ";\n";
                 out << "    rightHand_ROTATE_FRAMEB[1]   = "  <<  rightHand_SET_01[1]     <<  ";\n";
                 out << "    rightHand_ROTATE_FRAMEB[2]   = "  <<  rightHand_SET_01[2]     <<  ";\n}\n";       
          
          out << "     else" <<  "\n    {\n";
                 out << "    rightUpperArm_ROTATE_FRAMEB[3]   = "  <<  rightUpperArm_SET_04[3]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEB[0]   = "  <<  rightUpperArm_SET_04[0]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEB[1]   = "  <<  rightUpperArm_SET_04[1]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEB[2]   = "  <<  rightUpperArm_SET_04[2]     <<  ";\n";          
           
                 out << "    rightForeArm_ROTATE_FRAMEB[3]   = "  <<  rightForeArm_SET_04[3]     <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEB[0]   = "  <<  rightForeArm_SET_04[0]     <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEB[1]   = "  <<  rightForeArm_SET_04[1]     <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEB[2]   = "  <<  rightForeArm_SET_04[2]     <<  ";\n";          
            
                 out << "    rightHand_ROTATE_FRAMEB[3]   = "  <<  rightHand_SET_04[3]     <<  ";\n";
                 out << "    rightHand_ROTATE_FRAMEB[0]   = "  <<  rightHand_SET_04[0]     <<  ";\n";
                 out << "    rightHand_ROTATE_FRAMEB[1]   = "  <<  rightHand_SET_04[1]     <<  ";\n";
                 out << "    rightHand_ROTATE_FRAMEB[2]   = "  <<  rightHand_SET_04[2]     <<  ";\n}\n}\n";
          //////////////////////____RIGHT___ARM___////////////////////////////////////////////////////////////////////          

          //////////////////////____LEFT___LEG___////////////////////////////////////////////////////////////////////          
          out << "if(setSelection_LEFT_LEG == 3)" <<  "\n{\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[3]   = "  <<  leftUpperLeg_SET_03[3]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[0]   = "  <<  leftUpperLeg_SET_03[0]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[1]   = "  <<  leftUpperLeg_SET_03[1]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[2]   = "  <<  leftUpperLeg_SET_03[2]     <<  ";\n";
                  
                 out << "    leftLowerLeg_ROTATE_FRAMEA[3]   = "  <<  leftLowerLeg_SET_03[3]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEA[0]   = "  <<  leftLowerLeg_SET_03[0]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEA[1]   = "  <<  leftLowerLeg_SET_03[1]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEA[2]   = "  <<  leftLowerLeg_SET_03[2]     <<  ";\n";          
           
                 out << "    leftFoot_ROTATE_FRAMEA[3]   = "  <<  leftFoot_SET_03[3]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEA[0]   = "  <<  leftFoot_SET_03[0]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEA[1]   = "  <<  leftFoot_SET_03[1]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEA[2]   = "  <<  leftFoot_SET_03[2]     <<  ";\n";         
          out << "     if(SelectionCount_LEFT_LEG == 3)" <<  "\n    {\n";          
                 out << "    leftUpperLeg_ROTATE_FRAMEB[3]   = "  <<  leftUpperLeg_SET_01[3]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[0]   = "  <<  leftUpperLeg_SET_01[0]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[1]   = "  <<  leftUpperLeg_SET_01[1]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[2]   = "  <<  leftUpperLeg_SET_01[2]     <<  ";\n";          
            
                 out << "    leftLowerLeg_ROTATE_FRAMEB[3]   = "  <<  leftLowerLeg_SET_01[3]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[0]   = "  <<  leftLowerLeg_SET_01[0]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[1]   = "  <<  leftLowerLeg_SET_01[1]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[2]   = "  <<  leftLowerLeg_SET_01[2]     <<  ";\n";          
  
                 out << "    leftFoot_ROTATE_FRAMEB[3]   = "  <<  leftFoot_SET_01[3]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[0]   = "  <<  leftFoot_SET_01[0]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[1]   = "  <<  leftFoot_SET_01[1]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[2]   = "  <<  leftFoot_SET_01[2]     <<  ";\n}\n";     
          
          out << "     else" <<  "\n    {\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[3]   = "  <<  leftUpperLeg_SET_04[3]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[0]   = "  <<  leftUpperLeg_SET_04[0]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[1]   = "  <<  leftUpperLeg_SET_04[1]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[2]   = "  <<  leftUpperLeg_SET_04[2]     <<  ";\n";          
            
                 out << "    leftLowerLeg_ROTATE_FRAMEB[3]   = "  <<  leftLowerLeg_SET_04[3]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[0]   = "  <<  leftLowerLeg_SET_04[0]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[1]   = "  <<  leftLowerLeg_SET_04[1]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[2]   = "  <<  leftLowerLeg_SET_04[2]     <<  ";\n";          
           
                 out << "    leftFoot_ROTATE_FRAMEB[3]   = "  <<  leftFoot_SET_04[3]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[0]   = "  <<  leftFoot_SET_04[0]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[1]   = "  <<  leftFoot_SET_04[1]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[2]   = "  <<  leftFoot_SET_04[2]     <<  ";\n}\n}\n";
          //////////////////////____LEFT___LEG___////////////////////////////////////////////////////////////////////          
          
          //////////////////////____RIGHT___LEG___////////////////////////////////////////////////////////////////////          
          out << "if(setSelection_RIGHT_LEG == 3)" <<  "\n{\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[3]   = "  <<  rightUpperLeg_SET_03[3]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[0]   = "  <<  rightUpperLeg_SET_03[0]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[1]   = "  <<  rightUpperLeg_SET_03[1]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[2]   = "  <<  rightUpperLeg_SET_03[2]     <<  ";\n";
                 
                 out << "    rightLowerLeg_ROTATE_FRAMEA[3]   = "  <<  rightLowerLeg_SET_03[3]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEA[0]   = "  <<  rightLowerLeg_SET_03[0]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEA[1]   = "  <<  rightLowerLeg_SET_03[1]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEA[2]   = "  <<  rightLowerLeg_SET_03[2]     <<  ";\n";          
           
                 out << "    rightFoot_ROTATE_FRAMEA[3]   = "  <<  rightFoot_SET_03[3]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEA[0]   = "  <<  rightFoot_SET_03[0]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEA[1]   = "  <<  rightFoot_SET_03[1]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEA[2]   = "  <<  rightFoot_SET_03[2]     <<  ";\n";          
          out << "     if(SelectionCount_RIGHT_LEG == 3)" <<  "\n    {\n";          
                out << "     rightUpperLeg_ROTATE_FRAMEB[3]   = "  <<  rightUpperLeg_SET_01[3]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[0]   = "  <<  rightUpperLeg_SET_01[0]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[1]   = "  <<  rightUpperLeg_SET_01[1]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[2]   = "  <<  rightUpperLeg_SET_01[2]     <<  ";\n";          
           
                 out << "    rightLowerLeg_ROTATE_FRAMEB[3]   = "  <<  rightLowerLeg_SET_01[3]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[0]   = "  <<  rightLowerLeg_SET_01[0]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[1]   = "  <<  rightLowerLeg_SET_01[1]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[2]   = "  <<  rightLowerLeg_SET_01[2]     <<  ";\n";          
 
                 out << "    rightFoot_ROTATE_FRAMEB[3]   = "  <<  rightFoot_SET_01[3]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[0]   = "  <<  rightFoot_SET_01[0]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[1]   = "  <<  rightFoot_SET_01[1]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[2]   = "  <<  rightFoot_SET_01[2]     <<  ";\n}\n";     
          
          out << "     else" <<  "\n    {\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[3]   = "  <<  rightUpperLeg_SET_04[3]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[0]   = "  <<  rightUpperLeg_SET_04[0]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[1]   = "  <<  rightUpperLeg_SET_04[1]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[2]   = "  <<  rightUpperLeg_SET_04[2]     <<  ";\n";          
         
                 out << "    rightLowerLeg_ROTATE_FRAMEB[3]   = "  <<  rightLowerLeg_SET_04[3]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[0]   = "  <<  rightLowerLeg_SET_04[0]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[1]   = "  <<  rightLowerLeg_SET_04[1]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[2]   = "  <<  rightLowerLeg_SET_04[2]     <<  ";\n";          
            
                 out << "    rightFoot_ROTATE_FRAMEB[3]   = "  <<  rightFoot_SET_04[3]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[0]   = "  <<  rightFoot_SET_04[0]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[1]   = "  <<  rightFoot_SET_04[1]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[2]   = "  <<  rightFoot_SET_04[2]     <<  ";\n}\n}\n";
          //////////////////////____RIGHT___LEG___////////////////////////////////////////////////////////////////////  
      
          //////////////////////____HEAD__POSITION___////////////////////////////////////////////////////////////////////           
          out << "if(setSelection_HEAD == 3)" <<  "\n{\n";
                 out << "    head_ROTATE_FRAMEA[3]   = "  <<  head_SET_03[3]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEA[0]   = "  <<  head_SET_03[0]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEA[1]   = "  <<  head_SET_03[1]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEA[2]   = "  <<  head_SET_03[2]     <<  ";\n";         
          out << "     if(SelectionCount_HEAD == 3)" <<  "\n    {\n";          
                 out << "    head_ROTATE_FRAMEB[3]   = "  <<  head_SET_01[3]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[0]   = "  <<  head_SET_01[0]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[1]   = "  <<  head_SET_01[1]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[2]   = "  <<  head_SET_01[2]     <<  ";\n}\n";         
          out << "     else" <<  "\n    {\n";
                 out << "    head_ROTATE_FRAMEB[3]   = "  <<  head_SET_04[3]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[0]   = "  <<  head_SET_04[0]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[1]   = "  <<  head_SET_04[1]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[2]   = "  <<  head_SET_04[2]     <<  ";\n}\n}\n";       
          //////////////////////____HEAD__POSITION___////////////////////////////////////////////////////////////////////          
           
           //////////////////////____TORSO__POSITION___////////////////////////////////////////////////////////////////////           
          out << "if(setSelection_TORSO == 3)" <<  "\n{\n";
                 out << "    torso_ROTATE_FRAMEA[3]   = "  <<  torso_SET_03[3]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEA[0]   = "  <<  torso_SET_03[0]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEA[1]   = "  <<  torso_SET_03[1]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEA[2]   = "  <<  torso_SET_03[2]     <<  ";\n";       
          out << "     if(SelectionCount_TORSO == 3)" <<  "\n    {\n";          
                 out << "    torso_ROTATE_FRAMEB[3]   = "  <<  torso_SET_01[3]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[0]   = "  <<  torso_SET_01[0]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[1]   = "  <<  torso_SET_01[1]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[2]   = "  <<  torso_SET_01[2]     <<  ";\n}\n";       
          out << "     else" <<  "\n    {\n";
                 out << "    torso_ROTATE_FRAMEB[3]   = "  <<  torso_SET_04[3]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[0]   = "  <<  torso_SET_04[0]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[1]   = "  <<  torso_SET_04[1]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[2]   = "  <<  torso_SET_04[2]     <<  ";\n}\n}\n";    
          //////////////////////____TORSO__POSITION___////////////////////////////////////////////////////////////////////          

          //////////////////////____HIPS__POSITION___////////////////////////////////////////////////////////////////////           
          out << "if(setSelection_HIPS == 3)" <<  "\n{\n";
                 out << "    hips_ROTATE_FRAMEA[3]   = "  <<  hips_SET_03[3]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEA[0]   = "  <<  hips_SET_03[0]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEA[1]   = "  <<  hips_SET_03[1]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEA[2]   = "  <<  hips_SET_03[2]     <<  ";\n";    
          out << "     if(SelectionCount_HIPS == 3)" <<  "\n    {\n";          
                 out << "    hips_ROTATE_FRAMEB[3]   = "  <<  hips_SET_01[3]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[0]   = "  <<  hips_SET_01[0]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[1]   = "  <<  hips_SET_01[1]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[2]   = "  <<  hips_SET_01[2]     <<  ";\n}\n";       
          out << "     else" <<  "\n    {\n";
                 out << "    hips_ROTATE_FRAMEB[3]   = "  <<  hips_SET_04[3]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[0]   = "  <<  hips_SET_04[0]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[1]   = "  <<  hips_SET_04[1]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[2]   = "  <<  hips_SET_04[2]    <<  ";\n}\n}\n";  
          //////////////////////____HIPS__POSITION___////////////////////////////////////////////////////////////////////  
          
//################################################################################################################################################           





          //////////////////////____MAIN__POSITION___////////////////////////////////////////////////////////////////////      
          out << "if(hips_POSITION_setSelection == 4)" <<  "\n{\n";
              out << "    hips_POSITION_MOVE_FRAMEA[0]         = "  <<  hips_POSITION_SET_04[0]         <<  ";\n";
              out << "    hips_POSITION_MOVE_FRAMEA[1]         = "  <<  hips_POSITION_SET_04[1]         <<  ";\n";                 
              out << "    hips_POSITION_MOVE_FRAMEA[2]         = "  <<  hips_POSITION_SET_04[2]         <<  ";\n\n";
          out << "   if(hips_POSITION_SelectionCount == 4)" <<  "\n{\n";          
              out << "   hips_POSITION_MOVE_FRAMEB[0]          = "  <<   hips_POSITION_SET_01[0]  <<  ";\n";
              out << "   hips_POSITION_MOVE_FRAMEB[1]          = "  <<   hips_POSITION_SET_01[1]  <<  ";\n";                   
              out << "   hips_POSITION_MOVE_FRAMEB[2]          = "  <<   hips_POSITION_SET_01[2]  <<  ";\n}\n";
          out << "     else " <<  "\n    {\n";          
              out << "    hips_POSITION_MOVE_FRAMEB[0]         = "  <<   hips_POSITION_SET_05[0]  <<  ";\n";
              out << "    hips_POSITION_MOVE_FRAMEB[1]         = "  <<   hips_POSITION_SET_05[1]  <<  ";\n";                      
              out << "    hips_POSITION_MOVE_FRAMEB[2]         = "  <<   hips_POSITION_SET_05[2]  <<  ";\n}\n}\n";          
          //////////////////////____MAIN__POSITION___//////////////////////////////////////////////////////////////// 
                        
          //////////////////////____LEFT___ARM___////////////////////////////////////////////////////////////////////          
          out << "if(setSelection_LEFT_ARM == 4)" <<  "\n{\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[3]     = "  <<  leftUpperArm_SET_04[3]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[0]     = "  <<  leftUpperArm_SET_04[0]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[1]     = "  <<  leftUpperArm_SET_04[1]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[2]     = "  <<  leftUpperArm_SET_04[2]     <<  ";\n";
                
                 out << "    leftForeArm_ROTATE_FRAMEA[3]      = "  <<  leftForeArm_SET_04[3]      <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEA[0]      = "  <<  leftForeArm_SET_04[0]      <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEA[1]      = "  <<  leftForeArm_SET_04[1]      <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEA[2]      = "  <<  leftForeArm_SET_04[2]      <<  ";\n";                 
          
                 out << "    leftHand_ROTATE_FRAMEA[3]   = "  <<  leftHand_SET_04[3]     <<  ";\n";
                 out << "    leftHand_ROTATE_FRAMEA[0]   = "  <<  leftHand_SET_04[0]     <<  ";\n";
                 out << "    leftHand_ROTATE_FRAMEA[1]   = "  <<  leftHand_SET_04[1]     <<  ";\n";
                 out << "    leftHand_ROTATE_FRAMEA[2]   = "  <<  leftHand_SET_04[2]     <<  ";\n";          
          
          out << "     if(SelectionCount_LEFT_ARM == 4)" <<  "\n    {\n";          
                 out << "    leftUpperArm_ROTATE_FRAMEB[3]     = "  <<  leftUpperArm_SET_01[3]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEB[0]     = "  <<  leftUpperArm_SET_01[0]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEB[1]     = "  <<  leftUpperArm_SET_01[1]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEB[2]     = "  <<  leftUpperArm_SET_01[2]     <<  ";\n";           
                 
                 out << "    leftForeArm_ROTATE_FRAMEB[3]      = "  <<  leftForeArm_SET_01[3]     <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEB[0]      = "  <<  leftForeArm_SET_01[0]     <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEB[1]      = "  <<  leftForeArm_SET_01[1]     <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEB[2]      = "  <<  leftForeArm_SET_01[2]     <<  ";\n";         
                
                out << "    leftHand_ROTATE_FRAMEB[3]    = "  <<  leftHand_SET_01[3]     <<  ";\n";
                out << "    leftHand_ROTATE_FRAMEB[0]    = "  <<  leftHand_SET_01[0]     <<  ";\n";
                out << "    leftHand_ROTATE_FRAMEB[1]    = "  <<  leftHand_SET_01[1]     <<  ";\n";
                out << "    leftHand_ROTATE_FRAMEB[2]    = "  <<  leftHand_SET_01[2]     <<  ";\n}\n";           
          out << "     else " <<  "\n    {\n";          
                out << "    leftUpperArm_ROTATE_FRAMEB[3]      = "  <<  leftUpperArm_SET_05[3]     <<  ";\n";
                out << "    leftUpperArm_ROTATE_FRAMEB[0]      = "  <<  leftUpperArm_SET_05[0]     <<  ";\n";
                out << "    leftUpperArm_ROTATE_FRAMEB[1]      = "  <<  leftUpperArm_SET_05[1]     <<  ";\n";
                out << "    leftUpperArm_ROTATE_FRAMEB[2]      = "  <<  leftUpperArm_SET_05[2]     <<  ";\n";          
               
                out << "    leftForeArm_ROTATE_FRAMEB[3]       = "  <<  leftForeArm_SET_05[3]     <<  ";\n";
                out << "    leftForeArm_ROTATE_FRAMEB[0]       = "  <<  leftForeArm_SET_05[0]     <<  ";\n";
                out << "    leftForeArm_ROTATE_FRAMEB[1]       = "  <<  leftForeArm_SET_05[1]     <<  ";\n";
                out << "    leftForeArm_ROTATE_FRAMEB[2]       = "  <<  leftForeArm_SET_05[2]     <<  ";\n";                          
                         
                out << "    leftHand_ROTATE_FRAMEB[3]    = "  <<  leftHand_SET_05[3]     <<  ";\n";
                out << "    leftHand_ROTATE_FRAMEB[0]    = "  <<  leftHand_SET_05[0]     <<  ";\n";
                out << "    leftHand_ROTATE_FRAMEB[1]    = "  <<  leftHand_SET_05[1]     <<  ";\n";
                out << "    leftHand_ROTATE_FRAMEB[2]    = "  <<  leftHand_SET_05[2]     <<  ";\n}\n}\n";         
          //////////////////////____LEFT___ARM___////////////////////////////////////////////////////////////////////           
          
          //////////////////////____RIGHT___ARM___////////////////////////////////////////////////////////////////////          
          out << "if(setSelection_RIGHT_ARM == 4)" <<  "\n{\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[3]   = "  <<  rightUpperArm_SET_04[3]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[0]   = "  <<  rightUpperArm_SET_04[0]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[1]   = "  <<  rightUpperArm_SET_04[1]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[2]   = "  <<  rightUpperArm_SET_04[2]     <<  ";\n";
                
                 out << "    rightForeArm_ROTATE_FRAMEA[3]    = "  <<  rightForeArm_SET_04[3]      <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEA[0]    = "  <<  rightForeArm_SET_04[0]      <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEA[1]    = "  <<  rightForeArm_SET_04[1]      <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEA[2]    = "  <<  rightForeArm_SET_04[2]      <<  ";\n";                 
          
                 out << "    rightHand_ROTATE_FRAMEA[3]   = "  <<  rightHand_SET_04[3]     <<  ";\n";
                 out << "    rightHand_ROTATE_FRAMEA[0]   = "  <<  rightHand_SET_04[0]     <<  ";\n";
                 out << "    rightHand_ROTATE_FRAMEA[1]   = "  <<  rightHand_SET_04[1]     <<  ";\n";
                 out << "    rightHand_ROTATE_FRAMEA[2]   = "  <<  rightHand_SET_04[2]     <<  ";\n";          
          
          out << "     if(SelectionCount_RIGHT_ARM == 4)" <<  "\n    {\n";          
                 out << "    rightUpperArm_ROTATE_FRAMEB[3]   = "  <<  rightUpperArm_SET_01[3]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEB[0]   = "  <<  rightUpperArm_SET_01[0]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEB[1]   = "  <<  rightUpperArm_SET_01[1]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEB[2]   = "  <<  rightUpperArm_SET_01[2]     <<  ";\n";           
                 
                 out << "    rightForeArm_ROTATE_FRAMEB[3]   = "  <<  rightForeArm_SET_01[3]     <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEB[0]   = "  <<  rightForeArm_SET_01[0]     <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEB[1]   = "  <<  rightForeArm_SET_01[1]     <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEB[2]   = "  <<  rightForeArm_SET_01[2]     <<  ";\n";         
                
                out << "    rightHand_ROTATE_FRAMEB[3]   = "  <<  rightHand_SET_01[3]     <<  ";\n";
                out << "    rightHand_ROTATE_FRAMEB[0]   = "  <<  rightHand_SET_01[0]     <<  ";\n";
                out << "    rightHand_ROTATE_FRAMEB[1]   = "  <<  rightHand_SET_01[1]     <<  ";\n";
                out << "    rightHand_ROTATE_FRAMEB[2]   = "  <<  rightHand_SET_01[2]     <<  ";\n}\n";           
          out << "     else " <<  "\n    {\n";          
                out << "    rightUpperArm_ROTATE_FRAMEB[3]   = "  <<  rightUpperArm_SET_05[3]     <<  ";\n";
                out << "    rightUpperArm_ROTATE_FRAMEB[0]   = "  <<  rightUpperArm_SET_05[0]     <<  ";\n";
                out << "    rightUpperArm_ROTATE_FRAMEB[1]   = "  <<  rightUpperArm_SET_05[1]     <<  ";\n";
                out << "    rightUpperArm_ROTATE_FRAMEB[2]   = "  <<  rightUpperArm_SET_05[2]     <<  ";\n";          
               
                out << "    rightForeArm_ROTATE_FRAMEB[3]   = "  <<  rightForeArm_SET_05[3]     <<  ";\n";
                out << "    rightForeArm_ROTATE_FRAMEB[0]   = "  <<  rightForeArm_SET_05[0]     <<  ";\n";
                out << "    rightForeArm_ROTATE_FRAMEB[1]   = "  <<  rightForeArm_SET_05[1]     <<  ";\n";
                out << "    rightForeArm_ROTATE_FRAMEB[2]   = "  <<  rightForeArm_SET_05[2]     <<  ";\n";                          
                         
                out << "    rightHand_ROTATE_FRAMEB[3]   = "  <<  rightHand_SET_05[3]     <<  ";\n";
                out << "    rightHand_ROTATE_FRAMEB[0]   = "  <<  rightHand_SET_05[0]     <<  ";\n";
                out << "    rightHand_ROTATE_FRAMEB[1]   = "  <<  rightHand_SET_05[1]     <<  ";\n";
                out << "    rightHand_ROTATE_FRAMEB[2]   = "  <<  rightHand_SET_05[2]     <<  ";\n}\n}\n";         
          //////////////////////____RIGHT___ARM___////////////////////////////////////////////////////////////////////           
                      
          //////////////////////____LEFT___LEG___////////////////////////////////////////////////////////////////////          
          out << "if(setSelection_LEFT_LEG == 4)" <<  "\n{\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[3]   = "  <<  leftUpperLeg_SET_04[3]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[0]   = "  <<  leftUpperLeg_SET_04[0]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[1]   = "  <<  leftUpperLeg_SET_04[1]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[2]   = "  <<  leftUpperLeg_SET_04[2]     <<  ";\n";
         
                 out << "    leftLowerLeg_ROTATE_FRAMEA[3]   = "  <<  leftLowerLeg_SET_04[3]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEA[0]   = "  <<  leftLowerLeg_SET_04[0]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEA[1]   = "  <<  leftLowerLeg_SET_04[1]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEA[2]   = "  <<  leftLowerLeg_SET_04[2]     <<  ";\n";                 
             
                 out << "    leftFoot_ROTATE_FRAMEA[3]   = "  <<  leftFoot_SET_04[3]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEA[0]   = "  <<  leftFoot_SET_04[0]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEA[1]   = "  <<  leftFoot_SET_04[1]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEA[2]   = "  <<  leftFoot_SET_04[2]     <<  ";\n";          
          
          out << "     if(SelectionCount_LEFT_LEG == 4)" <<  "\n    {\n";          
                 out << "    leftUpperLeg_ROTATE_FRAMEB[3]   = "  <<  leftUpperLeg_SET_01[3]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[0]   = "  <<  leftUpperLeg_SET_01[0]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[1]   = "  <<  leftUpperLeg_SET_01[1]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[2]   = "  <<  leftUpperLeg_SET_01[2]     <<  ";\n";           
                    
                 out << "    leftLowerLeg_ROTATE_FRAMEB[3]   = "  <<  leftLowerLeg_SET_01[3]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[0]   = "  <<  leftLowerLeg_SET_01[0]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[1]   = "  <<  leftLowerLeg_SET_01[1]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[2]   = "  <<  leftLowerLeg_SET_01[2]     <<  ";\n";         
                      
                 out << "    leftFoot_ROTATE_FRAMEB[3]   = "  <<  leftFoot_SET_01[3]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[0]   = "  <<  leftFoot_SET_01[0]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[1]   = "  <<  leftFoot_SET_01[1]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[2]   = "  <<  leftFoot_SET_01[2]      <<  ";\n}\n";             
          out << "     else " <<  "\n    {\n";          
        
                 out << "    leftUpperLeg_ROTATE_FRAMEB[3]   = "  <<  leftUpperLeg_SET_05[3]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[0]   = "  <<  leftUpperLeg_SET_05[0]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[1]   = "  <<  leftUpperLeg_SET_05[1]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[2]   = "  <<  leftUpperLeg_SET_05[2]     <<  ";\n";          
                                                 
                 out << "    leftLowerLeg_ROTATE_FRAMEB[3]   = "  <<  leftLowerLeg_SET_05[3]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[0]   = "  <<  leftLowerLeg_SET_05[0]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[1]   = "  <<  leftLowerLeg_SET_05[1]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[2]   = "  <<  leftLowerLeg_SET_05[2]     <<  ";\n";                          
                             
                 out << "    leftFoot_ROTATE_FRAMEB[3]   = "  <<  leftFoot_SET_05[3]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[0]   = "  <<  leftFoot_SET_05[0]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[1]   = "  <<  leftFoot_SET_05[1]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[2]   = "  <<  leftFoot_SET_05[2]     <<  ";\n}\n}\n";              
          //////////////////////____LEFT___LEG___////////////////////////////////////////////////////////////////////           
          
          //////////////////////____RIGHT___LEG__////////////////////////////////////////////////////////////////////          
          out << "if(setSelection_RIGHT_LEG == 4)" <<  "\n{\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[3]   = "  <<  rightUpperLeg_SET_04[3]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[0]   = "  <<  rightUpperLeg_SET_04[0]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[1]   = "  <<  rightUpperLeg_SET_04[1]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[2]   = "  <<  rightUpperLeg_SET_04[2]     <<  ";\n";
                            
                 out << "    rightLowerLeg_ROTATE_FRAMEA[3]   = "  <<  rightLowerLeg_SET_04[3]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEA[0]   = "  <<  rightLowerLeg_SET_04[0]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEA[1]   = "  <<  rightLowerLeg_SET_04[1]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEA[2]   = "  <<  rightLowerLeg_SET_04[2]     <<  ";\n";                 
           
                 out << "    rightFoot_ROTATE_FRAMEA[3]   = "  <<  rightFoot_SET_04[3]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEA[0]   = "  <<  rightFoot_SET_04[0]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEA[1]   = "  <<  rightFoot_SET_04[1]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEA[2]   = "  <<  rightFoot_SET_04[2]     <<  ";\n";        
          
          out << "     if(SelectionCount_RIGHT_LEG == 4)" <<  "\n    {\n";          
                 out << "    rightUpperLeg_ROTATE_FRAMEB[3]   = "  <<  rightUpperLeg_SET_01[3]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[0]   = "  <<  rightUpperLeg_SET_01[0]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[1]   = "  <<  rightUpperLeg_SET_01[1]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[2]   = "  <<  rightUpperLeg_SET_01[2]     <<  ";\n";           
                      
                 out << "    rightLowerLeg_ROTATE_FRAMEB[3]   = "  <<  rightLowerLeg_SET_01[3]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[0]   = "  <<  rightLowerLeg_SET_01[0]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[1]   = "  <<  rightLowerLeg_SET_01[1]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[2]   = "  <<  rightLowerLeg_SET_01[2]     <<  ";\n";         
                     
                 out << "    rightFoot_ROTATE_FRAMEB[3]   = "  <<  rightFoot_SET_01[3]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[0]   = "  <<  rightFoot_SET_01[0]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[1]   = "  <<  rightFoot_SET_01[1]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[2]   = "  <<  rightFoot_SET_01[2]      <<  ";\n}\n";          
          out << "     else " <<  "\n    {\n";          
                 out << "    rightUpperLeg_ROTATE_FRAMEB[3]   = "  <<  rightUpperLeg_SET_05[3]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[0]   = "  <<  rightUpperLeg_SET_05[0]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[1]   = "  <<  rightUpperLeg_SET_05[1]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[2]   = "  <<  rightUpperLeg_SET_05[2]     <<  ";\n";          
                                              
                 out << "    rightLowerLeg_ROTATE_FRAMEB[3]   = "  <<  rightLowerLeg_SET_05[3]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[0]   = "  <<  rightLowerLeg_SET_05[0]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[1]   = "  <<  rightLowerLeg_SET_05[1]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[2]   = "  <<  rightLowerLeg_SET_05[2]     <<  ";\n";                          
                            
                 out << "    rightFoot_ROTATE_FRAMEB[3]   = "  <<  rightFoot_SET_05[3]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[0]   = "  <<  rightFoot_SET_05[0]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[1]   = "  <<  rightFoot_SET_05[1]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[2]   = "  <<  rightFoot_SET_05[2]     <<  ";\n}\n}\n";              
          //////////////////////____RIGHT___ARM___////////////////////////////////////////////////////////////////////           
         
          //////////////////////____HEAD__POSITION___////////////////////////////////////////////////////////////////////      
          out << "if(setSelection_HEAD == 4)" <<  "\n{\n";
                 out << "    head_ROTATE_FRAMEA[3]   = "  <<  head_SET_04[3]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEA[0]   = "  <<  head_SET_04[0]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEA[1]   = "  <<  head_SET_04[1]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEA[2]   = "  <<  head_SET_04[2]     <<  ";\n"; 
          
          out << "   if(SelectionCount_HEAD == 4)" <<  "\n{\n";          
                 out << "    head_ROTATE_FRAMEB[3]   = "  <<  head_SET_01[3]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[0]   = "  <<  head_SET_01[0]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[1]   = "  <<  head_SET_01[1]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[2]   = "  <<  head_SET_01[2]     <<  ";\n}\n";   
          
          out << "     else " <<  "\n    {\n";          
                 out << "    head_ROTATE_FRAMEB[3]   = "  <<  head_SET_05[3]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[0]   = "  <<  head_SET_05[0]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[1]   = "  <<  head_SET_05[1]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[2]   = "  <<  head_SET_05[2]     <<  ";\n}\n}\n";        
          //////////////////////____HEAD__POSITION___////////////////////////////////////////////////////////////////          

        
          //////////////////////____TORSO__POSITION___////////////////////////////////////////////////////////////////////      
          out << "if(setSelection_TORSO == 4)" <<  "\n{\n";
                 out << "    torso_ROTATE_FRAMEA[3]   = "  <<  torso_SET_04[3]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEA[0]   = "  <<  torso_SET_04[0]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEA[1]   = "  <<  torso_SET_04[1]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEA[2]   = "  <<  torso_SET_04[2]     <<  ";\n"; 
          
          out << "   if(SelectionCount_TORSO == 4)" <<  "\n{\n";          
                 out << "    torso_ROTATE_FRAMEB[3]   = "  <<  torso_SET_01[3]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[0]   = "  <<  torso_SET_01[0]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[1]   = "  <<  torso_SET_01[1]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[2]   = "  <<  torso_SET_01[2]     <<  ";\n}\n";  
          
          out << "     else " <<  "\n    {\n";          
                 out << "    torso_ROTATE_FRAMEB[3]   = "  <<  torso_SET_05[3]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[0]   = "  <<  torso_SET_05[0]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[1]   = "  <<  torso_SET_05[1]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[2]   = "  <<  torso_SET_05[2]     <<  ";\n}\n}\n";        
          //////////////////////____TORSO__POSITION___////////////////////////////////////////////////////////////////          
        
          //////////////////////____HIPS__POSITION___////////////////////////////////////////////////////////////////////      
          out << "if(setSelection_HIPS == 4)" <<  "\n{\n";
                 out << "    hips_ROTATE_FRAMEA[3]   = "  <<  hips_SET_04[3]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEA[0]   = "  <<  hips_SET_04[0]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEA[1]   = "  <<  hips_SET_04[1]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEA[2]   = "  <<  hips_SET_04[2]     <<  ";\n"; 
          
          out << "   if(SelectionCount_HIPS == 4)" <<  "\n{\n";          
                 out << "    hips_ROTATE_FRAMEB[3]   = "  <<  hips_SET_01[3]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[0]   = "  <<  hips_SET_01[0]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[1]   = "  <<  hips_SET_01[1]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[2]   = "  <<  hips_SET_01[2]     <<  ";\n}\n";  
          
          out << "     else " <<  "\n    {\n";          
                 out << "    hips_ROTATE_FRAMEB[3]   = "  <<  hips_SET_05[3]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[0]   = "  <<  hips_SET_05[0]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[1]   = "  <<  hips_SET_05[1]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[2]   = "  <<  hips_SET_05[2]     <<  ";\n}\n}\n";    
          //////////////////////____HIPS__POSITION___//////////////////////////////////////////////////////////////// 
                   
//################################################################################################################################################
//################################################################################################################################################           

        
          
    
        
          //////////////////////____MAIN__POSITION___////////////////////////////////////////////////////////////////////      
          out << "if(hips_POSITION_setSelection == 5)" <<  "\n{\n";
              out << "    hips_POSITION_MOVE_FRAMEA[0]         = "  <<  hips_POSITION_SET_05[0]         <<  ";\n";
              out << "    hips_POSITION_MOVE_FRAMEA[1]         = "  <<  hips_POSITION_SET_05[1]         <<  ";\n";                 
              out << "    hips_POSITION_MOVE_FRAMEA[2]         = "  <<  hips_POSITION_SET_05[2]         <<  ";\n\n";
          out << "   if(hips_POSITION_SelectionCount == 5)" <<  "\n{\n";          
              out << "   hips_POSITION_MOVE_FRAMEB[0]          = "  <<   hips_POSITION_SET_01[0]  <<  ";\n";
              out << "   hips_POSITION_MOVE_FRAMEB[1]          = "  <<   hips_POSITION_SET_01[1]  <<  ";\n";                   
              out << "   hips_POSITION_MOVE_FRAMEB[2]          = "  <<   hips_POSITION_SET_01[2]  <<  ";\n}\n";
          out << "     else " <<  "\n    {\n";          
              out << "    hips_POSITION_MOVE_FRAMEB[0]         = "  <<   hips_POSITION_SET_06[0]  <<  ";\n";
              out << "    hips_POSITION_MOVE_FRAMEB[1]         = "  <<   hips_POSITION_SET_06[1]  <<  ";\n";                      
              out << "    hips_POSITION_MOVE_FRAMEB[2]         = "  <<   hips_POSITION_SET_06[2]  <<  ";\n}\n}\n";          
          //////////////////////____MAIN__POSITION___//////////////////////////////////////////////////////////////// 
                        
                           
          //////////////////////____LEFT___ARM___////////////////////////////////////////////////////////////////////          
          out << "if(setSelection_LEFT_ARM == 5)" <<  "\n{\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[3]     = "  <<  leftUpperArm_SET_05[3]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[0]     = "  <<  leftUpperArm_SET_05[0]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[1]     = "  <<  leftUpperArm_SET_05[1]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[2]     = "  <<  leftUpperArm_SET_05[2]     <<  ";\n";
                
                 out << "    leftForeArm_ROTATE_FRAMEA[3]      = "  <<  leftForeArm_SET_05[3]      <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEA[0]      = "  <<  leftForeArm_SET_05[0]      <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEA[1]      = "  <<  leftForeArm_SET_05[1]      <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEA[2]      = "  <<  leftForeArm_SET_05[2]      <<  ";\n";                 
          
                 out << "    leftHand_ROTATE_FRAMEA[3]   = "  <<  leftHand_SET_05[3]     <<  ";\n";
                 out << "    leftHand_ROTATE_FRAMEA[0]   = "  <<  leftHand_SET_05[0]     <<  ";\n";
                 out << "    leftHand_ROTATE_FRAMEA[1]   = "  <<  leftHand_SET_05[1]     <<  ";\n";
                 out << "    leftHand_ROTATE_FRAMEA[2]   = "  <<  leftHand_SET_05[2]     <<  ";\n";          
          
          out << "     if(SelectionCount_LEFT_ARM == 5)" <<  "\n    {\n";          
                 out << "    leftUpperArm_ROTATE_FRAMEB[3]     = "  <<  leftUpperArm_SET_01[3]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEB[0]     = "  <<  leftUpperArm_SET_01[0]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEB[1]     = "  <<  leftUpperArm_SET_01[1]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEB[2]     = "  <<  leftUpperArm_SET_01[2]     <<  ";\n";           
                 
                 out << "    leftForeArm_ROTATE_FRAMEB[3]      = "  <<  leftForeArm_SET_01[3]     <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEB[0]      = "  <<  leftForeArm_SET_01[0]     <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEB[1]      = "  <<  leftForeArm_SET_01[1]     <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEB[2]      = "  <<  leftForeArm_SET_01[2]     <<  ";\n";         
                
                out << "    leftHand_ROTATE_FRAMEB[3]    = "  <<  leftHand_SET_01[3]     <<  ";\n";
                out << "    leftHand_ROTATE_FRAMEB[0]    = "  <<  leftHand_SET_01[0]     <<  ";\n";
                out << "    leftHand_ROTATE_FRAMEB[1]    = "  <<  leftHand_SET_01[1]     <<  ";\n";
                out << "    leftHand_ROTATE_FRAMEB[2]    = "  <<  leftHand_SET_01[2]     <<  ";\n}\n";           
          out << "     else " <<  "\n    {\n";          
                out << "    leftUpperArm_ROTATE_FRAMEB[3]      = "  <<  leftUpperArm_SET_06[3]     <<  ";\n";
                out << "    leftUpperArm_ROTATE_FRAMEB[0]      = "  <<  leftUpperArm_SET_06[0]     <<  ";\n";
                out << "    leftUpperArm_ROTATE_FRAMEB[1]      = "  <<  leftUpperArm_SET_06[1]     <<  ";\n";
                out << "    leftUpperArm_ROTATE_FRAMEB[2]      = "  <<  leftUpperArm_SET_06[2]     <<  ";\n";          
               
                out << "    leftForeArm_ROTATE_FRAMEB[3]       = "  <<  leftForeArm_SET_06[3]     <<  ";\n";
                out << "    leftForeArm_ROTATE_FRAMEB[0]       = "  <<  leftForeArm_SET_06[0]     <<  ";\n";
                out << "    leftForeArm_ROTATE_FRAMEB[1]       = "  <<  leftForeArm_SET_06[1]     <<  ";\n";
                out << "    leftForeArm_ROTATE_FRAMEB[2]       = "  <<  leftForeArm_SET_06[2]     <<  ";\n";                          
                         
                out << "    leftHand_ROTATE_FRAMEB[3]    = "  <<  leftHand_SET_06[3]     <<  ";\n";
                out << "    leftHand_ROTATE_FRAMEB[0]    = "  <<  leftHand_SET_06[0]     <<  ";\n";
                out << "    leftHand_ROTATE_FRAMEB[1]    = "  <<  leftHand_SET_06[1]     <<  ";\n";
                out << "    leftHand_ROTATE_FRAMEB[2]    = "  <<  leftHand_SET_06[2]     <<  ";\n}\n}\n";         
          //////////////////////____LEFT___ARM___////////////////////////////////////////////////////////////////////           
          
          //////////////////////____RIGHT___ARM___////////////////////////////////////////////////////////////////////          
          out << "if(setSelection_RIGHT_ARM == 5)" <<  "\n{\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[3]   = "  <<  rightUpperArm_SET_05[3]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[0]   = "  <<  rightUpperArm_SET_05[0]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[1]   = "  <<  rightUpperArm_SET_05[1]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[2]   = "  <<  rightUpperArm_SET_05[2]     <<  ";\n";
                
                 out << "    rightForeArm_ROTATE_FRAMEA[3]    = "  <<  rightForeArm_SET_05[3]      <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEA[0]    = "  <<  rightForeArm_SET_05[0]      <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEA[1]    = "  <<  rightForeArm_SET_05[1]      <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEA[2]    = "  <<  rightForeArm_SET_05[2]      <<  ";\n";                 
          
                 out << "    rightHand_ROTATE_FRAMEA[3]   = "  <<  rightHand_SET_05[3]     <<  ";\n";
                 out << "    rightHand_ROTATE_FRAMEA[0]   = "  <<  rightHand_SET_05[0]     <<  ";\n";
                 out << "    rightHand_ROTATE_FRAMEA[1]   = "  <<  rightHand_SET_05[1]     <<  ";\n";
                 out << "    rightHand_ROTATE_FRAMEA[2]   = "  <<  rightHand_SET_05[2]     <<  ";\n";          
          
          out << "     if(SelectionCount_RIGHT_ARM == 5)" <<  "\n    {\n";          
                 out << "    rightUpperArm_ROTATE_FRAMEB[3]   = "  <<  rightUpperArm_SET_01[3]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEB[0]   = "  <<  rightUpperArm_SET_01[0]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEB[1]   = "  <<  rightUpperArm_SET_01[1]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEB[2]   = "  <<  rightUpperArm_SET_01[2]     <<  ";\n";           
                 
                 out << "    rightForeArm_ROTATE_FRAMEB[3]   = "  <<  rightForeArm_SET_01[3]     <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEB[0]   = "  <<  rightForeArm_SET_01[0]     <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEB[1]   = "  <<  rightForeArm_SET_01[1]     <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEB[2]   = "  <<  rightForeArm_SET_01[2]     <<  ";\n";         
                
                out << "    rightHand_ROTATE_FRAMEB[3]   = "  <<  rightHand_SET_01[3]     <<  ";\n";
                out << "    rightHand_ROTATE_FRAMEB[0]   = "  <<  rightHand_SET_01[0]     <<  ";\n";
                out << "    rightHand_ROTATE_FRAMEB[1]   = "  <<  rightHand_SET_01[1]     <<  ";\n";
                out << "    rightHand_ROTATE_FRAMEB[2]   = "  <<  rightHand_SET_01[2]     <<  ";\n}\n";           
          out << "     else " <<  "\n    {\n";          
                out << "    rightUpperArm_ROTATE_FRAMEB[3]   = "  <<  rightUpperArm_SET_06[3]     <<  ";\n";
                out << "    rightUpperArm_ROTATE_FRAMEB[0]   = "  <<  rightUpperArm_SET_06[0]     <<  ";\n";
                out << "    rightUpperArm_ROTATE_FRAMEB[1]   = "  <<  rightUpperArm_SET_06[1]     <<  ";\n";
                out << "    rightUpperArm_ROTATE_FRAMEB[2]   = "  <<  rightUpperArm_SET_06[2]     <<  ";\n";          
               
                out << "    rightForeArm_ROTATE_FRAMEB[3]   = "  <<  rightForeArm_SET_06[3]     <<  ";\n";
                out << "    rightForeArm_ROTATE_FRAMEB[0]   = "  <<  rightForeArm_SET_06[0]     <<  ";\n";
                out << "    rightForeArm_ROTATE_FRAMEB[1]   = "  <<  rightForeArm_SET_06[1]     <<  ";\n";
                out << "    rightForeArm_ROTATE_FRAMEB[2]   = "  <<  rightForeArm_SET_06[2]     <<  ";\n";                          
                         
                out << "    rightHand_ROTATE_FRAMEB[3]   = "  <<  rightHand_SET_06[3]     <<  ";\n";
                out << "    rightHand_ROTATE_FRAMEB[0]   = "  <<  rightHand_SET_06[0]     <<  ";\n";
                out << "    rightHand_ROTATE_FRAMEB[1]   = "  <<  rightHand_SET_06[1]     <<  ";\n";
                out << "    rightHand_ROTATE_FRAMEB[2]   = "  <<  rightHand_SET_06[2]     <<  ";\n}\n}\n";         
          //////////////////////____RIGHT___ARM___////////////////////////////////////////////////////////////////////           
                      
          //////////////////////____LEFT___LEG___////////////////////////////////////////////////////////////////////          
          out << "if(setSelection_LEFT_LEG == 5)" <<  "\n{\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[3]   = "  <<  leftUpperLeg_SET_05[3]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[0]   = "  <<  leftUpperLeg_SET_05[0]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[1]   = "  <<  leftUpperLeg_SET_05[1]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[2]   = "  <<  leftUpperLeg_SET_05[2]     <<  ";\n";
         
                 out << "    leftLowerLeg_ROTATE_FRAMEA[3]   = "  <<  leftLowerLeg_SET_05[3]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEA[0]   = "  <<  leftLowerLeg_SET_05[0]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEA[1]   = "  <<  leftLowerLeg_SET_05[1]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEA[2]   = "  <<  leftLowerLeg_SET_05[2]     <<  ";\n";                 
             
                 out << "    leftFoot_ROTATE_FRAMEA[3]   = "  <<  leftFoot_SET_05[3]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEA[0]   = "  <<  leftFoot_SET_05[0]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEA[1]   = "  <<  leftFoot_SET_05[1]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEA[2]   = "  <<  leftFoot_SET_05[2]     <<  ";\n";          
          
          out << "     if(SelectionCount_LEFT_LEG == 5)" <<  "\n    {\n";          
                 out << "    leftUpperLeg_ROTATE_FRAMEB[3]   = "  <<  leftUpperLeg_SET_01[3]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[0]   = "  <<  leftUpperLeg_SET_01[0]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[1]   = "  <<  leftUpperLeg_SET_01[1]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[2]   = "  <<  leftUpperLeg_SET_01[2]     <<  ";\n";           
                    
                 out << "    leftLowerLeg_ROTATE_FRAMEB[3]   = "  <<  leftLowerLeg_SET_01[3]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[0]   = "  <<  leftLowerLeg_SET_01[0]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[1]   = "  <<  leftLowerLeg_SET_01[1]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[2]   = "  <<  leftLowerLeg_SET_01[2]     <<  ";\n";         
                      
                 out << "    leftFoot_ROTATE_FRAMEB[3]   = "  <<  leftFoot_SET_01[3]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[0]   = "  <<  leftFoot_SET_01[0]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[1]   = "  <<  leftFoot_SET_01[1]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[2]   = "  <<  leftFoot_SET_01[2]      <<  ";\n}\n";             
          out << "     else " <<  "\n    {\n";          
        
                 out << "    leftUpperLeg_ROTATE_FRAMEB[3]   = "  <<  leftUpperLeg_SET_06[3]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[0]   = "  <<  leftUpperLeg_SET_06[0]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[1]   = "  <<  leftUpperLeg_SET_06[1]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[2]   = "  <<  leftUpperLeg_SET_06[2]     <<  ";\n";          
                                                 
                 out << "    leftLowerLeg_ROTATE_FRAMEB[3]   = "  <<  leftLowerLeg_SET_06[3]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[0]   = "  <<  leftLowerLeg_SET_06[0]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[1]   = "  <<  leftLowerLeg_SET_06[1]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[2]   = "  <<  leftLowerLeg_SET_06[2]     <<  ";\n";                          
                             
                 out << "    leftFoot_ROTATE_FRAMEB[3]   = "  <<  leftFoot_SET_06[3]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[0]   = "  <<  leftFoot_SET_06[0]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[1]   = "  <<  leftFoot_SET_06[1]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[2]   = "  <<  leftFoot_SET_06[2]     <<  ";\n}\n}\n";              
          //////////////////////____LEFT___LEG___////////////////////////////////////////////////////////////////////           
          
          //////////////////////____RIGHT___LEG__////////////////////////////////////////////////////////////////////          
          out << "if(setSelection_RIGHT_LEG == 5)" <<  "\n{\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[3]   = "  <<  rightUpperLeg_SET_05[3]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[0]   = "  <<  rightUpperLeg_SET_05[0]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[1]   = "  <<  rightUpperLeg_SET_05[1]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[2]   = "  <<  rightUpperLeg_SET_05[2]     <<  ";\n";
                            
                 out << "    rightLowerLeg_ROTATE_FRAMEA[3]   = "  <<  rightLowerLeg_SET_05[3]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEA[0]   = "  <<  rightLowerLeg_SET_05[0]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEA[1]   = "  <<  rightLowerLeg_SET_05[1]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEA[2]   = "  <<  rightLowerLeg_SET_05[2]     <<  ";\n";                 
           
                 out << "    rightFoot_ROTATE_FRAMEA[3]   = "  <<  rightFoot_SET_05[3]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEA[0]   = "  <<  rightFoot_SET_05[0]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEA[1]   = "  <<  rightFoot_SET_05[1]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEA[2]   = "  <<  rightFoot_SET_05[2]     <<  ";\n";        
          
          out << "     if(SelectionCount_RIGHT_LEG == 5)" <<  "\n    {\n";          
                 out << "    rightUpperLeg_ROTATE_FRAMEB[3]   = "  <<  rightUpperLeg_SET_01[3]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[0]   = "  <<  rightUpperLeg_SET_01[0]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[1]   = "  <<  rightUpperLeg_SET_01[1]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[2]   = "  <<  rightUpperLeg_SET_01[2]     <<  ";\n";           
                      
                 out << "    rightLowerLeg_ROTATE_FRAMEB[3]   = "  <<  rightLowerLeg_SET_01[3]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[0]   = "  <<  rightLowerLeg_SET_01[0]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[1]   = "  <<  rightLowerLeg_SET_01[1]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[2]   = "  <<  rightLowerLeg_SET_01[2]     <<  ";\n";         
                     
                 out << "    rightFoot_ROTATE_FRAMEB[3]   = "  <<  rightFoot_SET_01[3]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[0]   = "  <<  rightFoot_SET_01[0]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[1]   = "  <<  rightFoot_SET_01[1]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[2]   = "  <<  rightFoot_SET_01[2]      <<  ";\n}\n";          
          out << "     else " <<  "\n    {\n";          
                 out << "    rightUpperLeg_ROTATE_FRAMEB[3]   = "  <<  rightUpperLeg_SET_06[3]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[0]   = "  <<  rightUpperLeg_SET_06[0]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[1]   = "  <<  rightUpperLeg_SET_06[1]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[2]   = "  <<  rightUpperLeg_SET_06[2]     <<  ";\n";          
                                              
                 out << "    rightLowerLeg_ROTATE_FRAMEB[3]   = "  <<  rightLowerLeg_SET_06[3]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[0]   = "  <<  rightLowerLeg_SET_06[0]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[1]   = "  <<  rightLowerLeg_SET_06[1]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[2]   = "  <<  rightLowerLeg_SET_06[2]     <<  ";\n";                          
                            
                 out << "    rightFoot_ROTATE_FRAMEB[3]   = "  <<  rightFoot_SET_06[3]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[0]   = "  <<  rightFoot_SET_06[0]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[1]   = "  <<  rightFoot_SET_06[1]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[2]   = "  <<  rightFoot_SET_06[2]     <<  ";\n}\n}\n";              
          //////////////////////____RIGHT___ARM___////////////////////////////////////////////////////////////////////           
         
          //////////////////////____HEAD__POSITION___////////////////////////////////////////////////////////////////////      
          out << "if(setSelection_HEAD == 5)" <<  "\n{\n";
                 out << "    head_ROTATE_FRAMEA[3]   = "  <<  head_SET_05[3]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEA[0]   = "  <<  head_SET_05[0]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEA[1]   = "  <<  head_SET_05[1]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEA[2]   = "  <<  head_SET_05[2]     <<  ";\n"; 
          
          out << "   if(SelectionCount_HEAD == 5)" <<  "\n{\n";          
                 out << "    head_ROTATE_FRAMEB[3]   = "  <<  head_SET_01[3]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[0]   = "  <<  head_SET_01[0]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[1]   = "  <<  head_SET_01[1]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[2]   = "  <<  head_SET_01[2]     <<  ";\n}\n";   
          
          out << "     else " <<  "\n    {\n";          
                 out << "    head_ROTATE_FRAMEB[3]   = "  <<  head_SET_06[3]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[0]   = "  <<  head_SET_06[0]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[1]   = "  <<  head_SET_06[1]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[2]   = "  <<  head_SET_06[2]     <<  ";\n}\n}\n";        
          //////////////////////____HEAD__POSITION___////////////////////////////////////////////////////////////////          

        
          //////////////////////____TORSO__POSITION___////////////////////////////////////////////////////////////////////      
          out << "if(setSelection_TORSO == 5)" <<  "\n{\n";
                 out << "    torso_ROTATE_FRAMEA[3]   = "  <<  torso_SET_05[3]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEA[0]   = "  <<  torso_SET_05[0]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEA[1]   = "  <<  torso_SET_05[1]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEA[2]   = "  <<  torso_SET_05[2]     <<  ";\n"; 
          
          out << "   if(SelectionCount_TORSO == 5)" <<  "\n{\n";          
                 out << "    torso_ROTATE_FRAMEB[3]   = "  <<  torso_SET_01[3]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[0]   = "  <<  torso_SET_01[0]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[1]   = "  <<  torso_SET_01[1]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[2]   = "  <<  torso_SET_01[2]     <<  ";\n}\n";  
          
          out << "     else " <<  "\n    {\n";          
                 out << "    torso_ROTATE_FRAMEB[3]   = "  <<  torso_SET_06[3]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[0]   = "  <<  torso_SET_06[0]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[1]   = "  <<  torso_SET_06[1]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[2]   = "  <<  torso_SET_06[2]     <<  ";\n}\n}\n";        
          //////////////////////____TORSO__POSITION___////////////////////////////////////////////////////////////////          
        
          //////////////////////____HIPS__POSITION___////////////////////////////////////////////////////////////////////      
          out << "if(setSelection_HIPS == 5)" <<  "\n{\n";
                 out << "    hips_ROTATE_FRAMEA[3]   = "  <<  hips_SET_05[3]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEA[0]   = "  <<  hips_SET_05[0]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEA[1]   = "  <<  hips_SET_05[1]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEA[2]   = "  <<  hips_SET_05[2]     <<  ";\n"; 
          
          out << "   if(SelectionCount_HIPS == 5)" <<  "\n{\n";          
                 out << "    hips_ROTATE_FRAMEB[3]   = "  <<  hips_SET_01[3]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[0]   = "  <<  hips_SET_01[0]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[1]   = "  <<  hips_SET_01[1]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[2]   = "  <<  hips_SET_01[2]     <<  ";\n}\n";  
          
          out << "     else " <<  "\n    {\n";          
                 out << "    hips_ROTATE_FRAMEB[3]   = "  <<  hips_SET_06[3]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[0]   = "  <<  hips_SET_06[0]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[1]   = "  <<  hips_SET_06[1]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[2]   = "  <<  hips_SET_06[2]     <<  ";\n}\n}\n";    
          //////////////////////____HIPS__POSITION___//////////////////////////////////////////////////////////////// 
                   
//################################################################################################################################################  
//################################################################################################################################################  

//################################################################################################################################################
//################################################################################################################################################           

        
          
    
        
          //////////////////////____MAIN__POSITION___////////////////////////////////////////////////////////////////////      
          out << "if(hips_POSITION_setSelection == 6)" <<  "\n{\n";
              out << "    hips_POSITION_MOVE_FRAMEA[0]         = "  <<  hips_POSITION_SET_06[0]         <<  ";\n";
              out << "    hips_POSITION_MOVE_FRAMEA[1]         = "  <<  hips_POSITION_SET_06[1]         <<  ";\n";                 
              out << "    hips_POSITION_MOVE_FRAMEA[2]         = "  <<  hips_POSITION_SET_06[2]         <<  ";\n\n";
          out << "   if(hips_POSITION_SelectionCount == 6)" <<  "\n{\n";          
              out << "   hips_POSITION_MOVE_FRAMEB[0]          = "  <<   hips_POSITION_SET_01[0]  <<  ";\n";
              out << "   hips_POSITION_MOVE_FRAMEB[1]          = "  <<   hips_POSITION_SET_01[1]  <<  ";\n";                   
              out << "   hips_POSITION_MOVE_FRAMEB[2]          = "  <<   hips_POSITION_SET_01[2]  <<  ";\n}\n";
          out << "     else " <<  "\n    {\n";          
              out << "    hips_POSITION_MOVE_FRAMEB[0]         = "  <<   hips_POSITION_SET_07[0]  <<  ";\n";
              out << "    hips_POSITION_MOVE_FRAMEB[1]         = "  <<   hips_POSITION_SET_07[1]  <<  ";\n";                      
              out << "    hips_POSITION_MOVE_FRAMEB[2]         = "  <<   hips_POSITION_SET_07[2]  <<  ";\n}\n}\n";          
          //////////////////////____MAIN__POSITION___//////////////////////////////////////////////////////////////// 
                        
                           
          //////////////////////____LEFT___ARM___////////////////////////////////////////////////////////////////////          
          out << "if(setSelection_LEFT_ARM == 6)" <<  "\n{\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[3]     = "  <<  leftUpperArm_SET_06[3]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[0]     = "  <<  leftUpperArm_SET_06[0]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[1]     = "  <<  leftUpperArm_SET_06[1]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[2]     = "  <<  leftUpperArm_SET_06[2]     <<  ";\n";
                
                 out << "    leftForeArm_ROTATE_FRAMEA[3]      = "  <<  leftForeArm_SET_06[3]      <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEA[0]      = "  <<  leftForeArm_SET_06[0]      <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEA[1]      = "  <<  leftForeArm_SET_06[1]      <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEA[2]      = "  <<  leftForeArm_SET_06[2]      <<  ";\n";                 
          
                 out << "    leftHand_ROTATE_FRAMEA[3]   = "  <<  leftHand_SET_06[3]     <<  ";\n";
                 out << "    leftHand_ROTATE_FRAMEA[0]   = "  <<  leftHand_SET_06[0]     <<  ";\n";
                 out << "    leftHand_ROTATE_FRAMEA[1]   = "  <<  leftHand_SET_06[1]     <<  ";\n";
                 out << "    leftHand_ROTATE_FRAMEA[2]   = "  <<  leftHand_SET_06[2]     <<  ";\n";          
          
          out << "     if(SelectionCount_LEFT_ARM == 6)" <<  "\n    {\n";          
                 out << "    leftUpperArm_ROTATE_FRAMEB[3]     = "  <<  leftUpperArm_SET_01[3]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEB[0]     = "  <<  leftUpperArm_SET_01[0]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEB[1]     = "  <<  leftUpperArm_SET_01[1]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEB[2]     = "  <<  leftUpperArm_SET_01[2]     <<  ";\n";           
                 
                 out << "    leftForeArm_ROTATE_FRAMEB[3]      = "  <<  leftForeArm_SET_01[3]     <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEB[0]      = "  <<  leftForeArm_SET_01[0]     <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEB[1]      = "  <<  leftForeArm_SET_01[1]     <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEB[2]      = "  <<  leftForeArm_SET_01[2]     <<  ";\n";         
                
                out << "    leftHand_ROTATE_FRAMEB[3]    = "  <<  leftHand_SET_01[3]     <<  ";\n";
                out << "    leftHand_ROTATE_FRAMEB[0]    = "  <<  leftHand_SET_01[0]     <<  ";\n";
                out << "    leftHand_ROTATE_FRAMEB[1]    = "  <<  leftHand_SET_01[1]     <<  ";\n";
                out << "    leftHand_ROTATE_FRAMEB[2]    = "  <<  leftHand_SET_01[2]     <<  ";\n}\n";           
          out << "     else " <<  "\n    {\n";          
                out << "    leftUpperArm_ROTATE_FRAMEB[3]      = "  <<  leftUpperArm_SET_07[3]     <<  ";\n";
                out << "    leftUpperArm_ROTATE_FRAMEB[0]      = "  <<  leftUpperArm_SET_07[0]     <<  ";\n";
                out << "    leftUpperArm_ROTATE_FRAMEB[1]      = "  <<  leftUpperArm_SET_07[1]     <<  ";\n";
                out << "    leftUpperArm_ROTATE_FRAMEB[2]      = "  <<  leftUpperArm_SET_07[2]     <<  ";\n";          
               
                out << "    leftForeArm_ROTATE_FRAMEB[3]       = "  <<  leftForeArm_SET_07[3]     <<  ";\n";
                out << "    leftForeArm_ROTATE_FRAMEB[0]       = "  <<  leftForeArm_SET_07[0]     <<  ";\n";
                out << "    leftForeArm_ROTATE_FRAMEB[1]       = "  <<  leftForeArm_SET_07[1]     <<  ";\n";
                out << "    leftForeArm_ROTATE_FRAMEB[2]       = "  <<  leftForeArm_SET_07[2]     <<  ";\n";                          
                         
                out << "    leftHand_ROTATE_FRAMEB[3]    = "  <<  leftHand_SET_07[3]     <<  ";\n";
                out << "    leftHand_ROTATE_FRAMEB[0]    = "  <<  leftHand_SET_07[0]     <<  ";\n";
                out << "    leftHand_ROTATE_FRAMEB[1]    = "  <<  leftHand_SET_07[1]     <<  ";\n";
                out << "    leftHand_ROTATE_FRAMEB[2]    = "  <<  leftHand_SET_07[2]     <<  ";\n}\n}\n";         
          //////////////////////____LEFT___ARM___////////////////////////////////////////////////////////////////////           
          
          //////////////////////____RIGHT___ARM___////////////////////////////////////////////////////////////////////          
          out << "if(setSelection_RIGHT_ARM == 6)" <<  "\n{\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[3]   = "  <<  rightUpperArm_SET_06[3]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[0]   = "  <<  rightUpperArm_SET_06[0]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[1]   = "  <<  rightUpperArm_SET_06[1]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[2]   = "  <<  rightUpperArm_SET_06[2]     <<  ";\n";
                
                 out << "    rightForeArm_ROTATE_FRAMEA[3]    = "  <<  rightForeArm_SET_06[3]      <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEA[0]    = "  <<  rightForeArm_SET_06[0]      <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEA[1]    = "  <<  rightForeArm_SET_06[1]      <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEA[2]    = "  <<  rightForeArm_SET_06[2]      <<  ";\n";                 
          
                 out << "    rightHand_ROTATE_FRAMEA[3]   = "  <<  rightHand_SET_06[3]     <<  ";\n";
                 out << "    rightHand_ROTATE_FRAMEA[0]   = "  <<  rightHand_SET_06[0]     <<  ";\n";
                 out << "    rightHand_ROTATE_FRAMEA[1]   = "  <<  rightHand_SET_06[1]     <<  ";\n";
                 out << "    rightHand_ROTATE_FRAMEA[2]   = "  <<  rightHand_SET_06[2]     <<  ";\n";          
          
          out << "     if(SelectionCount_RIGHT_ARM == 6)" <<  "\n    {\n";          
                 out << "    rightUpperArm_ROTATE_FRAMEB[3]   = "  <<  rightUpperArm_SET_01[3]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEB[0]   = "  <<  rightUpperArm_SET_01[0]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEB[1]   = "  <<  rightUpperArm_SET_01[1]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEB[2]   = "  <<  rightUpperArm_SET_01[2]     <<  ";\n";           
                 
                 out << "    rightForeArm_ROTATE_FRAMEB[3]   = "  <<  rightForeArm_SET_01[3]     <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEB[0]   = "  <<  rightForeArm_SET_01[0]     <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEB[1]   = "  <<  rightForeArm_SET_01[1]     <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEB[2]   = "  <<  rightForeArm_SET_01[2]     <<  ";\n";         
                
                out << "    rightHand_ROTATE_FRAMEB[3]   = "  <<  rightHand_SET_01[3]     <<  ";\n";
                out << "    rightHand_ROTATE_FRAMEB[0]   = "  <<  rightHand_SET_01[0]     <<  ";\n";
                out << "    rightHand_ROTATE_FRAMEB[1]   = "  <<  rightHand_SET_01[1]     <<  ";\n";
                out << "    rightHand_ROTATE_FRAMEB[2]   = "  <<  rightHand_SET_01[2]     <<  ";\n}\n";           
          out << "     else " <<  "\n    {\n";          
                out << "    rightUpperArm_ROTATE_FRAMEB[3]   = "  <<  rightUpperArm_SET_07[3]     <<  ";\n";
                out << "    rightUpperArm_ROTATE_FRAMEB[0]   = "  <<  rightUpperArm_SET_07[0]     <<  ";\n";
                out << "    rightUpperArm_ROTATE_FRAMEB[1]   = "  <<  rightUpperArm_SET_07[1]     <<  ";\n";
                out << "    rightUpperArm_ROTATE_FRAMEB[2]   = "  <<  rightUpperArm_SET_07[2]     <<  ";\n";          
               
                out << "    rightForeArm_ROTATE_FRAMEB[3]   = "  <<  rightForeArm_SET_07[3]     <<  ";\n";
                out << "    rightForeArm_ROTATE_FRAMEB[0]   = "  <<  rightForeArm_SET_07[0]     <<  ";\n";
                out << "    rightForeArm_ROTATE_FRAMEB[1]   = "  <<  rightForeArm_SET_07[1]     <<  ";\n";
                out << "    rightForeArm_ROTATE_FRAMEB[2]   = "  <<  rightForeArm_SET_07[2]     <<  ";\n";                          
                         
                out << "    rightHand_ROTATE_FRAMEB[3]   = "  <<  rightHand_SET_07[3]     <<  ";\n";
                out << "    rightHand_ROTATE_FRAMEB[0]   = "  <<  rightHand_SET_07[0]     <<  ";\n";
                out << "    rightHand_ROTATE_FRAMEB[1]   = "  <<  rightHand_SET_07[1]     <<  ";\n";
                out << "    rightHand_ROTATE_FRAMEB[2]   = "  <<  rightHand_SET_07[2]     <<  ";\n}\n}\n";         
          //////////////////////____RIGHT___ARM___////////////////////////////////////////////////////////////////////           
                      
          //////////////////////____LEFT___LEG___////////////////////////////////////////////////////////////////////          
          out << "if(setSelection_LEFT_LEG == 6)" <<  "\n{\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[3]   = "  <<  leftUpperLeg_SET_06[3]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[0]   = "  <<  leftUpperLeg_SET_06[0]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[1]   = "  <<  leftUpperLeg_SET_06[1]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[2]   = "  <<  leftUpperLeg_SET_06[2]     <<  ";\n";
         
                 out << "    leftLowerLeg_ROTATE_FRAMEA[3]   = "  <<  leftLowerLeg_SET_06[3]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEA[0]   = "  <<  leftLowerLeg_SET_06[0]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEA[1]   = "  <<  leftLowerLeg_SET_06[1]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEA[2]   = "  <<  leftLowerLeg_SET_06[2]     <<  ";\n";                 
             
                 out << "    leftFoot_ROTATE_FRAMEA[3]   = "  <<  leftFoot_SET_06[3]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEA[0]   = "  <<  leftFoot_SET_06[0]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEA[1]   = "  <<  leftFoot_SET_06[1]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEA[2]   = "  <<  leftFoot_SET_06[2]     <<  ";\n";          
          
          out << "     if(SelectionCount_LEFT_LEG == 6)" <<  "\n    {\n";          
                 out << "    leftUpperLeg_ROTATE_FRAMEB[3]   = "  <<  leftUpperLeg_SET_01[3]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[0]   = "  <<  leftUpperLeg_SET_01[0]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[1]   = "  <<  leftUpperLeg_SET_01[1]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[2]   = "  <<  leftUpperLeg_SET_01[2]     <<  ";\n";           
                    
                 out << "    leftLowerLeg_ROTATE_FRAMEB[3]   = "  <<  leftLowerLeg_SET_01[3]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[0]   = "  <<  leftLowerLeg_SET_01[0]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[1]   = "  <<  leftLowerLeg_SET_01[1]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[2]   = "  <<  leftLowerLeg_SET_01[2]     <<  ";\n";         
                      
                 out << "    leftFoot_ROTATE_FRAMEB[3]   = "  <<  leftFoot_SET_01[3]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[0]   = "  <<  leftFoot_SET_01[0]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[1]   = "  <<  leftFoot_SET_01[1]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[2]   = "  <<  leftFoot_SET_01[2]      <<  ";\n}\n";             
          out << "     else " <<  "\n    {\n";          
        
                 out << "    leftUpperLeg_ROTATE_FRAMEB[3]   = "  <<  leftUpperLeg_SET_07[3]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[0]   = "  <<  leftUpperLeg_SET_07[0]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[1]   = "  <<  leftUpperLeg_SET_07[1]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[2]   = "  <<  leftUpperLeg_SET_07[2]     <<  ";\n";          
                                                 
                 out << "    leftLowerLeg_ROTATE_FRAMEB[3]   = "  <<  leftLowerLeg_SET_07[3]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[0]   = "  <<  leftLowerLeg_SET_07[0]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[1]   = "  <<  leftLowerLeg_SET_07[1]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[2]   = "  <<  leftLowerLeg_SET_07[2]     <<  ";\n";                          
                             
                 out << "    leftFoot_ROTATE_FRAMEB[3]   = "  <<  leftFoot_SET_07[3]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[0]   = "  <<  leftFoot_SET_07[0]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[1]   = "  <<  leftFoot_SET_07[1]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[2]   = "  <<  leftFoot_SET_07[2]     <<  ";\n}\n}\n";              
          //////////////////////____LEFT___LEG___////////////////////////////////////////////////////////////////////           
          
          //////////////////////____RIGHT___LEG__////////////////////////////////////////////////////////////////////          
          out << "if(setSelection_RIGHT_LEG == 6)" <<  "\n{\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[3]   = "  <<  rightUpperLeg_SET_06[3]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[0]   = "  <<  rightUpperLeg_SET_06[0]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[1]   = "  <<  rightUpperLeg_SET_06[1]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[2]   = "  <<  rightUpperLeg_SET_06[2]     <<  ";\n";
                            
                 out << "    rightLowerLeg_ROTATE_FRAMEA[3]   = "  <<  rightLowerLeg_SET_06[3]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEA[0]   = "  <<  rightLowerLeg_SET_06[0]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEA[1]   = "  <<  rightLowerLeg_SET_06[1]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEA[2]   = "  <<  rightLowerLeg_SET_06[2]     <<  ";\n";                 
           
                 out << "    rightFoot_ROTATE_FRAMEA[3]   = "  <<  rightFoot_SET_06[3]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEA[0]   = "  <<  rightFoot_SET_06[0]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEA[1]   = "  <<  rightFoot_SET_06[1]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEA[2]   = "  <<  rightFoot_SET_06[2]     <<  ";\n";        
          
          out << "     if(SelectionCount_RIGHT_LEG == 6)" <<  "\n    {\n";          
                 out << "    rightUpperLeg_ROTATE_FRAMEB[3]   = "  <<  rightUpperLeg_SET_01[3]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[0]   = "  <<  rightUpperLeg_SET_01[0]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[1]   = "  <<  rightUpperLeg_SET_01[1]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[2]   = "  <<  rightUpperLeg_SET_01[2]     <<  ";\n";           
                      
                 out << "    rightLowerLeg_ROTATE_FRAMEB[3]   = "  <<  rightLowerLeg_SET_01[3]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[0]   = "  <<  rightLowerLeg_SET_01[0]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[1]   = "  <<  rightLowerLeg_SET_01[1]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[2]   = "  <<  rightLowerLeg_SET_01[2]     <<  ";\n";         
                     
                 out << "    rightFoot_ROTATE_FRAMEB[3]   = "  <<  rightFoot_SET_01[3]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[0]   = "  <<  rightFoot_SET_01[0]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[1]   = "  <<  rightFoot_SET_01[1]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[2]   = "  <<  rightFoot_SET_01[2]      <<  ";\n}\n";          
          out << "     else " <<  "\n    {\n";          
                 out << "    rightUpperLeg_ROTATE_FRAMEB[3]   = "  <<  rightUpperLeg_SET_07[3]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[0]   = "  <<  rightUpperLeg_SET_07[0]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[1]   = "  <<  rightUpperLeg_SET_07[1]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[2]   = "  <<  rightUpperLeg_SET_07[2]     <<  ";\n";          
                                              
                 out << "    rightLowerLeg_ROTATE_FRAMEB[3]   = "  <<  rightLowerLeg_SET_07[3]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[0]   = "  <<  rightLowerLeg_SET_07[0]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[1]   = "  <<  rightLowerLeg_SET_07[1]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[2]   = "  <<  rightLowerLeg_SET_07[2]     <<  ";\n";                          
                            
                 out << "    rightFoot_ROTATE_FRAMEB[3]   = "  <<  rightFoot_SET_07[3]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[0]   = "  <<  rightFoot_SET_07[0]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[1]   = "  <<  rightFoot_SET_07[1]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[2]   = "  <<  rightFoot_SET_07[2]     <<  ";\n}\n}\n";              
          //////////////////////____RIGHT___ARM___////////////////////////////////////////////////////////////////////           
         
          //////////////////////____HEAD__POSITION___////////////////////////////////////////////////////////////////////      
          out << "if(setSelection_HEAD == 6)" <<  "\n{\n";
                 out << "    head_ROTATE_FRAMEA[3]   = "  <<  head_SET_06[3]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEA[0]   = "  <<  head_SET_06[0]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEA[1]   = "  <<  head_SET_06[1]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEA[2]   = "  <<  head_SET_06[2]     <<  ";\n"; 
          
          out << "   if(SelectionCount_HEAD == 6)" <<  "\n{\n";          
                 out << "    head_ROTATE_FRAMEB[3]   = "  <<  head_SET_01[3]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[0]   = "  <<  head_SET_01[0]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[1]   = "  <<  head_SET_01[1]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[2]   = "  <<  head_SET_01[2]     <<  ";\n}\n";   
          
          out << "     else " <<  "\n    {\n";          
                 out << "    head_ROTATE_FRAMEB[3]   = "  <<  head_SET_07[3]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[0]   = "  <<  head_SET_07[0]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[1]   = "  <<  head_SET_07[1]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[2]   = "  <<  head_SET_07[2]     <<  ";\n}\n}\n";        
          //////////////////////____HEAD__POSITION___////////////////////////////////////////////////////////////////          

        
          //////////////////////____TORSO__POSITION___////////////////////////////////////////////////////////////////////      
          out << "if(setSelection_TORSO == 6)" <<  "\n{\n";
                 out << "    torso_ROTATE_FRAMEA[3]   = "  <<  torso_SET_06[3]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEA[0]   = "  <<  torso_SET_06[0]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEA[1]   = "  <<  torso_SET_06[1]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEA[2]   = "  <<  torso_SET_06[2]     <<  ";\n"; 
          
          out << "   if(SelectionCount_TORSO == 6)" <<  "\n{\n";          
                 out << "    torso_ROTATE_FRAMEB[3]   = "  <<  torso_SET_01[3]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[0]   = "  <<  torso_SET_01[0]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[1]   = "  <<  torso_SET_01[1]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[2]   = "  <<  torso_SET_01[2]     <<  ";\n}\n";  
          
          out << "     else " <<  "\n    {\n";          
                 out << "    torso_ROTATE_FRAMEB[3]   = "  <<  torso_SET_07[3]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[0]   = "  <<  torso_SET_07[0]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[1]   = "  <<  torso_SET_07[1]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[2]   = "  <<  torso_SET_07[2]     <<  ";\n}\n}\n";        
          //////////////////////____TORSO__POSITION___////////////////////////////////////////////////////////////////          
        
          //////////////////////____HIPS__POSITION___////////////////////////////////////////////////////////////////////      
          out << "if(setSelection_HIPS == 6)" <<  "\n{\n";
                 out << "    hips_ROTATE_FRAMEA[3]   = "  <<  hips_SET_06[3]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEA[0]   = "  <<  hips_SET_06[0]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEA[1]   = "  <<  hips_SET_06[1]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEA[2]   = "  <<  hips_SET_06[2]     <<  ";\n"; 
          
          out << "   if(SelectionCount_HIPS == 6)" <<  "\n{\n";          
                 out << "    hips_ROTATE_FRAMEB[3]   = "  <<  hips_SET_01[3]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[0]   = "  <<  hips_SET_01[0]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[1]   = "  <<  hips_SET_01[1]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[2]   = "  <<  hips_SET_01[2]     <<  ";\n}\n";  
          
          out << "     else " <<  "\n    {\n";          
                 out << "    hips_ROTATE_FRAMEB[3]   = "  <<  hips_SET_07[3]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[0]   = "  <<  hips_SET_07[0]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[1]   = "  <<  hips_SET_07[1]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[2]   = "  <<  hips_SET_07[2]     <<  ";\n}\n}\n";    
          //////////////////////____HIPS__POSITION___//////////////////////////////////////////////////////////////// 
//################################################################################################################################################  
//################################################################################################################################################  

      
          //////////////////////____MAIN__POSITION___////////////////////////////////////////////////////////////////////   
          out << "if(hips_POSITION_setSelection == 7)" <<  "\n{\n";
          
          out << "    hips_POSITION_MOVE_FRAMEA[0]     = "  <<   hips_POSITION_SET_07[0]  <<  ";\n";
          out << "    hips_POSITION_MOVE_FRAMEA[1]     = "  <<   hips_POSITION_SET_07[1]  <<  ";\n";                   
          out << "    hips_POSITION_MOVE_FRAMEA[2]     = "  <<   hips_POSITION_SET_07[2]  <<  ";\n";
                      
          out << "    hips_POSITION_MOVE_FRAMEB[0]     = "  <<   hips_POSITION_SET_01[0]  <<  ";\n";
          out << "    hips_POSITION_MOVE_FRAMEB[1]     = "  <<   hips_POSITION_SET_01[1]  <<  ";\n";                    
          out << "    hips_POSITION_MOVE_FRAMEB[2]     = "  <<   hips_POSITION_SET_01[2]  <<  ";\n}\n";           
          //////////////////////____MAIN__POSITION___////////////////////////////////////////////////////////////////////           
         
          //////////////////////////________LEFT___ARM____///////////////////////////////////////////////////////          
          out << "if(setSelection_LEFT_ARM == 7)" <<  "\n{";

                   
                 out << "    leftUpperArm_ROTATE_FRAMEA[3]   = "  <<  leftUpperArm_SET_07[3]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[0]   = "  <<  leftUpperArm_SET_07[0]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[1]   = "  <<  leftUpperArm_SET_07[1]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[2]   = "  <<  leftUpperArm_SET_07[2]     <<  ";\n";
                 
                 out << "    leftUpperArm_ROTATE_FRAMEB[3]   = "  <<  leftUpperArm_SET_01[3]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEB[0]   = "  <<  leftUpperArm_SET_01[0]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEB[1]   = "  <<  leftUpperArm_SET_01[1]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEB[2]   = "  <<  leftUpperArm_SET_01[2]     <<  ";\n";
                 ///_<subPart>_////                 
                 out << "    leftForeArm_ROTATE_FRAMEA[3]   = "  <<  leftForeArm_SET_07[3]     <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEA[0]   = "  <<  leftForeArm_SET_07[0]     <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEA[1]   = "  <<  leftForeArm_SET_07[1]     <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEA[2]   = "  <<  leftForeArm_SET_07[2]     <<  ";\n";
                 
                 out << "    leftForeArm_ROTATE_FRAMEB[3]   = "  <<  leftForeArm_SET_01[3]     <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEB[0]   = "  <<  leftForeArm_SET_01[0]     <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEB[1]   = "  <<  leftForeArm_SET_01[1]     <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEB[2]   = "  <<  leftForeArm_SET_01[2]     <<  ";\n";                           
                 ///_<subPart>_////          
                 out << "    leftHand_ROTATE_FRAMEA[3]   = "  <<  leftHand_SET_07[3]     <<  ";\n";
                 out << "    leftHand_ROTATE_FRAMEA[0]   = "  <<  leftHand_SET_07[0]     <<  ";\n";
                 out << "    leftHand_ROTATE_FRAMEA[1]   = "  <<  leftHand_SET_07[1]     <<  ";\n";
                 out << "    leftHand_ROTATE_FRAMEA[2]   = "  <<  leftHand_SET_07[2]     <<  ";\n";
                 
                 out << "    leftHand_ROTATE_FRAMEB[3]   = "  <<  leftHand_SET_01[3]     <<  ";\n";
                 out << "    leftHand_ROTATE_FRAMEB[0]   = "  <<  leftHand_SET_01[0]     <<  ";\n";
                 out << "    leftHand_ROTATE_FRAMEB[1]   = "  <<  leftHand_SET_01[1]     <<  ";\n";
                 out << "    leftHand_ROTATE_FRAMEB[2]   = "  <<  leftHand_SET_01[2]     <<  ";\n}\n";           
          //////////////////////////________LEFT___ARM____///////////////////////////////////////////////////////      
          
          
          //////////////////////////________RIGHT____ARM____///////////////////////////////////////////////////////           
          out << "if(setSelection_RIGHT_ARM == 7)" <<  "\n{";
                 out << "    rightUpperArm_ROTATE_FRAMEA[3]   = "  <<  rightUpperArm_SET_07[3]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[0]   = "  <<  rightUpperArm_SET_07[0]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[1]   = "  <<  rightUpperArm_SET_07[1]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[2]   = "  <<  rightUpperArm_SET_07[2]     <<  ";\n";
                 
                 out << "    rightUpperArm_ROTATE_FRAMEB[3]   = "  <<  rightUpperArm_SET_01[3]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEB[0]   = "  <<  rightUpperArm_SET_01[0]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEB[1]   = "  <<  rightUpperArm_SET_01[1]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEB[2]   = "  <<  rightUpperArm_SET_01[2]     <<  ";\n";
                 ///_<subPart>_////                 
                 out << "    rightForeArm_ROTATE_FRAMEA[3]   = "  <<  rightForeArm_SET_07[3]     <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEA[0]   = "  <<  rightForeArm_SET_07[0]     <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEA[1]   = "  <<  rightForeArm_SET_07[1]     <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEA[2]   = "  <<  rightForeArm_SET_07[2]     <<  ";\n";
                 
                 out << "    rightForeArm_ROTATE_FRAMEB[3]   = "  <<  rightForeArm_SET_01[3]     <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEB[0]   = "  <<  rightForeArm_SET_01[0]     <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEB[1]   = "  <<  rightForeArm_SET_01[1]     <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEB[2]   = "  <<  rightForeArm_SET_01[2]     <<  ";\n";                           
                 ///_<subPart>_////          
                 out << "    rightHand_ROTATE_FRAMEA[3]   = "  <<  rightHand_SET_07[3]     <<  ";\n";
                 out << "    rightHand_ROTATE_FRAMEA[0]   = "  <<  rightHand_SET_07[0]     <<  ";\n";
                 out << "    rightHand_ROTATE_FRAMEA[1]   = "  <<  rightHand_SET_07[1]     <<  ";\n";
                 out << "    rightHand_ROTATE_FRAMEA[2]   = "  <<  rightHand_SET_07[2]     <<  ";\n";
                 
                 out << "    rightHand_ROTATE_FRAMEB[3]   = "  <<  rightHand_SET_01[3]     <<  ";\n";
                 out << "    rightHand_ROTATE_FRAMEB[0]   = "  <<  rightHand_SET_01[0]     <<  ";\n";
                 out << "    rightHand_ROTATE_FRAMEB[1]   = "  <<  rightHand_SET_01[1]     <<  ";\n";
                 out << "    rightHand_ROTATE_FRAMEB[2]   = "  <<  rightHand_SET_01[2]     <<  ";\n}\n";           
           //////////////////////////________RIGHT___ARM____//////////////////////////////////////////////////////// 
           
           //////////////////////////________LEFT___ARM____///////////////////////////////////////////////////////          
           out << "if(setSelection_LEFT_LEG == 7)" <<  "\n{";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[3]   = "  <<  leftUpperLeg_SET_07[3]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[0]   = "  <<  leftUpperLeg_SET_07[0]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[1]   = "  <<  leftUpperLeg_SET_07[1]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[2]   = "  <<  leftUpperLeg_SET_07[2]     <<  ";\n";
                 
                 out << "    leftUpperLeg_ROTATE_FRAMEB[3]   = "  <<  leftUpperLeg_SET_01[3]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[0]   = "  <<  leftUpperLeg_SET_01[0]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[1]   = "  <<  leftUpperLeg_SET_01[1]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[2]   = "  <<  leftUpperLeg_SET_01[2]     <<  ";\n";
                 
                 out << "    leftLowerLeg_ROTATE_FRAMEA[3]   = "  <<  leftLowerLeg_SET_07[3]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEA[0]   = "  <<  leftLowerLeg_SET_07[0]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEA[1]   = "  <<  leftLowerLeg_SET_07[1]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEA[2]   = "  <<  leftLowerLeg_SET_07[2]     <<  ";\n";
                 
                 out << "    leftLowerLeg_ROTATE_FRAMEB[3]   = "  <<  leftLowerLeg_SET_01[3]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[0]   = "  <<  leftLowerLeg_SET_01[0]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[1]   = "  <<  leftLowerLeg_SET_01[1]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[2]   = "  <<  leftLowerLeg_SET_01[2]     <<  ";\n";                           
          
                 out << "    leftFoot_ROTATE_FRAMEA[3]       = "  <<  leftFoot_SET_07[3]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEA[0]       = "  <<  leftFoot_SET_07[0]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEA[1]       = "  <<  leftFoot_SET_07[1]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEA[2]       = "  <<  leftFoot_SET_07[2]     <<  ";\n";
                 
                 out << "    leftFoot_ROTATE_FRAMEB[3]       = "  <<  leftFoot_SET_01[3]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[0]       = "  <<  leftFoot_SET_01[0]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[1]       = "  <<  leftFoot_SET_01[1]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[2]       = "  <<  leftFoot_SET_01[2]     <<  ";\n}\n";            
          //////////////////////////________LEFT___ARM____///////////////////////////////////////////////////////      
          
          //////////////////////////________RIGHT____ARM____///////////////////////////////////////////////////////           
          out << "if(setSelection_RIGHT_LEG == 7)" <<  "\n{";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[3]   = "  <<  rightUpperLeg_SET_07[3]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[0]   = "  <<  rightUpperLeg_SET_07[0]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[1]   = "  <<  rightUpperLeg_SET_07[1]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[2]   = "  <<  rightUpperLeg_SET_07[2]     <<  ";\n";
                 
                 out << "    rightUpperLeg_ROTATE_FRAMEB[3]   = "  <<  rightUpperLeg_SET_01[3]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[0]   = "  <<  rightUpperLeg_SET_01[0]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[1]   = "  <<  rightUpperLeg_SET_01[1]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[2]   = "  <<  rightUpperLeg_SET_01[2]     <<  ";\n";
                
                 out << "    rightLowerLeg_ROTATE_FRAMEA[3]   = "  <<  rightLowerLeg_SET_07[3]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEA[0]   = "  <<  rightLowerLeg_SET_07[0]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEA[1]   = "  <<  rightLowerLeg_SET_07[1]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEA[2]   = "  <<  rightLowerLeg_SET_07[2]     <<  ";\n";
                 
                 out << "    rightLowerLeg_ROTATE_FRAMEB[3]   = "  <<  rightLowerLeg_SET_01[3]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[0]   = "  <<  rightLowerLeg_SET_01[0]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[1]   = "  <<  rightLowerLeg_SET_01[1]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[2]   = "  <<  rightLowerLeg_SET_01[2]     <<  ";\n";                           
        
                 out << "    rightFoot_ROTATE_FRAMEA[3]   = "  <<  rightFoot_SET_07[3]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEA[0]   = "  <<  rightFoot_SET_07[0]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEA[1]   = "  <<  rightFoot_SET_07[1]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEA[2]   = "  <<  rightFoot_SET_07[2]     <<  ";\n";
                 
                 out << "    rightFoot_ROTATE_FRAMEB[3]   = "  <<  rightFoot_SET_01[3]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[0]   = "  <<  rightFoot_SET_01[0]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[1]   = "  <<  rightFoot_SET_01[1]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[2]   = "  <<  rightFoot_SET_01[2]     <<  ";\n}\n";           
           //////////////////////////________RIGHT___ARM____////////////////////////////////////////////////////////            
        
           //////////////////////____HEAD__POSITION___////////////////////////////////////////////////////////////////////   
           out << "if(setSelection_HEAD == 7)" <<  "\n{\n";
          
                 out << "    head_ROTATE_FRAMEA[3]   = "  <<  head_SET_07[3]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEA[0]   = "  <<  head_SET_07[0]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEA[1]   = "  <<  head_SET_07[1]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEA[2]   = "  <<  head_SET_07[2]     <<  ";\n";          

                 out << "    head_ROTATE_FRAMEB[3]   = "  <<  head_SET_01[3]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[0]   = "  <<  head_SET_01[0]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[1]   = "  <<  head_SET_01[1]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[2]   = "  <<  head_SET_01[2]     <<  ";\n}\n";              
           //////////////////////____HEAD__POSITION___////////////////////////////////////////////////////////////////////           
           
           //////////////////////____TORSO__POSITION___////////////////////////////////////////////////////////////////////   
           out << "if(setSelection_TORSO == 7)" <<  "\n{\n";
                 out << "    torso_ROTATE_FRAMEA[3]   = "  <<  torso_SET_07[3]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEA[0]   = "  <<  torso_SET_07[0]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEA[1]   = "  <<  torso_SET_07[1]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEA[2]   = "  <<  torso_SET_07[2]     <<  ";\n";          

                 out << "    torso_ROTATE_FRAMEB[3]   = "  <<  torso_SET_01[3]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[0]   = "  <<  torso_SET_01[0]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[1]   = "  <<  torso_SET_01[1]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[2]   = "  <<  torso_SET_01[2]     <<  ";\n}\n";             
          //////////////////////____TORSO__POSITION___////////////////////////////////////////////////////////////////////           
          
          //////////////////////____HIPS__POSITION___////////////////////////////////////////////////////////////////////   
          out << "if(setSelection_HIPS == 7)" <<  "\n{\n";
                 out << "    hips_ROTATE_FRAMEA[3]   = "  <<  hips_SET_07[3]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEA[0]   = "  <<  hips_SET_07[0]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEA[1]   = "  <<  hips_SET_07[1]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEA[2]   = "  <<  hips_SET_07[2]     <<  ";\n";          
          
                 out << "    hips_ROTATE_FRAMEB[3]   = "  <<  hips_SET_01[3]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[0]   = "  <<  hips_SET_01[0]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[1]   = "  <<  hips_SET_01[1]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[2]   = "  <<  hips_SET_01[2]     <<  ";\n}\n";             
          //////////////////////____HIPS__POSITION___//////////////////////////////////////////////////////////////////// 
      
    
    }////______________________________________________________________________________________________________BEGIN_WRITE_ANIMATION
 

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    if(keys['P'])
    {
          ofstream out("_MODEL_FOLDERS_/marcParts/animations/animationFrameCapture_01.cpp");  
          //--------------------------------------------------------------------------------------------------------
          out << "                    hips_ROTATE[3]                       = "  <<   hips_ROTATE[3]              <<  ";\n";          
          out << "                    hips_ROTATE[0]                       = "  <<   hips_ROTATE[0]              <<  ";\n";
          out << "                    hips_ROTATE[1]                       = "  <<   hips_ROTATE[1]              <<  ";\n";                   
          out << "                    hips_ROTATE[2]                       = "  <<   hips_ROTATE[2]              <<  ";\n\n";
          //--------------------------------------------------------------------------------------------------------
          out << "                    torso_ROTATE[3]                      = "  <<   torso_ROTATE[3]             <<  ";\n";
          out << "                    torso_ROTATE[0]                      = "  <<   torso_ROTATE[0]             <<  ";\n";
          out << "                    torso_ROTATE[1]                      = "  <<   torso_ROTATE[1]             <<  ";\n";
          out << "                    torso_ROTATE[2]                      = "  <<   torso_ROTATE[2]             <<  ";\n\n";              
          //--------------------------------------------------------------------------------------------------------
          out << "                    head_ROTATE[3]                       = "  <<   head_ROTATE[3]              <<  ";\n";
          out << "                    head_ROTATE[0]                       = "  <<   head_ROTATE[0]              <<  ";\n";
          out << "                    head_ROTATE[1]                       = "  <<   head_ROTATE[1]              <<  ";\n";
          out << "                    head_ROTATE[2]                       = "  <<   head_ROTATE[2]              <<  ";\n\n";             
          //--------------------------------------------------------------------------------------------------------
          out << "                    leftUpperArm_ROTATE[3]               = "  <<   leftUpperArm_ROTATE[3]      <<  ";\n";          
          out << "                    leftUpperArm_ROTATE[0]               = "  <<   leftUpperArm_ROTATE[0]      <<  ";\n";
          out << "                    leftUpperArm_ROTATE[1]               = "  <<   leftUpperArm_ROTATE[1]      <<  ";\n";                   
          out << "                    leftUpperArm_ROTATE[2]               = "  <<   leftUpperArm_ROTATE[2]      <<  ";\n\n";
          //---------------------------------------
          out << "                    leftForeArm_ROTATE[3]                = "  <<   leftForeArm_ROTATE[3]       <<  ";\n";
          out << "                    leftForeArm_ROTATE[0]                = "  <<   leftForeArm_ROTATE[0]       <<  ";\n";
          out << "                    leftForeArm_ROTATE[1]                = "  <<   leftForeArm_ROTATE[1]       <<  ";\n";
          out << "                    leftForeArm_ROTATE[2]                = "  <<   leftForeArm_ROTATE[2]       <<  ";\n\n";              
          //--------------------------------------- 
          out << "                    leftHand_ROTATE[3]             = "  <<   leftHand_ROTATE[3]    <<  ";\n";
          out << "                    leftHand_ROTATE[0]             = "  <<   leftHand_ROTATE[0]    <<  ";\n";
          out << "                    leftHand_ROTATE[1]             = "  <<   leftHand_ROTATE[1]    <<  ";\n";
          out << "                    leftHand_ROTATE[2]             = "  <<   leftHand_ROTATE[2]    <<  ";\n\n";   
          //--------------------------------------------------------------------------------------------------------
          out << "                    rightUpperArm_ROTATE[3]              = "  <<  rightUpperArm_ROTATE[3]      <<  ";\n";
          out << "                    rightUpperArm_ROTATE[0]              = "  <<  rightUpperArm_ROTATE[0]      <<  ";\n";
          out << "                    rightUpperArm_ROTATE[1]              = "  <<  rightUpperArm_ROTATE[1]      <<  ";\n";
          out << "                    rightUpperArm_ROTATE[2]              = "  <<  rightUpperArm_ROTATE[2]      <<  ";\n\n";        
          //--------------------------------------
          out << "                    rightForeArm_ROTATE[3]               = "  <<  rightForeArm_ROTATE[3]       <<  ";\n";
          out << "                    rightForeArm_ROTATE[0]               = "  <<  rightForeArm_ROTATE[0]       <<  ";\n";
          out << "                    rightForeArm_ROTATE[1]               = "  <<  rightForeArm_ROTATE[1]       <<  ";\n";
          out << "                    rightForeArm_ROTATE[2]               = "  <<  rightForeArm_ROTATE[2]       <<  ";\n\n";           
          //--------------------------------------         
          out << "                    rightHand_ROTATE[3]            = "  <<  rightHand_ROTATE[3]    <<  ";\n";
          out << "                    rightHand_ROTATE[0]            = "  <<  rightHand_ROTATE[0]    <<  ";\n";
          out << "                    rightHand_ROTATE[1]            = "  <<  rightHand_ROTATE[1]    <<  ";\n";
          out << "                    rightHand_ROTATE[2]            = "  <<  rightHand_ROTATE[2]    <<  ";\n\n";    
          //--------------------------------------------------------------------------------------------------------  
          out << "                    leftUpperLeg_ROTATE[3]               = "  <<  leftUpperLeg_ROTATE[3]       <<  ";\n";
          out << "                    leftUpperLeg_ROTATE[0]               = "  <<  leftUpperLeg_ROTATE[0]       <<  ";\n";
          out << "                    leftUpperLeg_ROTATE[1]               = "  <<  leftUpperLeg_ROTATE[1]       <<  ";\n";
          out << "                    leftUpperLeg_ROTATE[2]               = "  <<  leftUpperLeg_ROTATE[2]       <<  ";\n\n";
          //--------------------------------------
          out << "                    leftLowerLeg_ROTATE[3]               = "  <<  leftLowerLeg_ROTATE[3]       <<  ";\n";
          out << "                    leftLowerLeg_ROTATE[0]               = "  <<  leftLowerLeg_ROTATE[0]       <<  ";\n";
          out << "                    leftLowerLeg_ROTATE[1]               = "  <<  leftLowerLeg_ROTATE[1]       <<  ";\n";
          out << "                    leftLowerLeg_ROTATE[2]               = "  <<  leftLowerLeg_ROTATE[2]       <<  ";\n\n";          
          //--------------------------------------
          out << "                    leftFoot_ROTATE[3]                   = "  <<  leftFoot_ROTATE[3]           <<  ";\n";
          out << "                    leftFoot_ROTATE[0]                   = "  <<  leftFoot_ROTATE[0]           <<  ";\n";
          out << "                    leftFoot_ROTATE[1]                   = "  <<  leftFoot_ROTATE[1]           <<  ";\n";
          out << "                    leftFoot_ROTATE[2]                   = "  <<  leftFoot_ROTATE[2]           <<  ";\n\n";           
          //--------------------------------------------------------------------------------------------------------          
          out << "                    rightUpperLeg_ROTATE[3]              = "  <<  rightUpperLeg_ROTATE[3]      <<  ";\n";
          out << "                    rightUpperLeg_ROTATE[0]              = "  <<  rightUpperLeg_ROTATE[0]      <<  ";\n";
          out << "                    rightUpperLeg_ROTATE[1]              = "  <<  rightUpperLeg_ROTATE[1]      <<  ";\n";
          out << "                    rightUpperLeg_ROTATE[2]              = "  <<  rightUpperLeg_ROTATE[2]      <<  ";\n\n";
          //--------------------------------------
          out << "                    rightLowerLeg_ROTATE[3]              = "  <<  rightLowerLeg_ROTATE[3]      <<  ";\n";
          out << "                    rightLowerLeg_ROTATE[0]              = "  <<  rightLowerLeg_ROTATE[0]      <<  ";\n";
          out << "                    rightLowerLeg_ROTATE[1]              = "  <<  rightLowerLeg_ROTATE[1]      <<  ";\n";
          out << "                    rightLowerLeg_ROTATE[2]              = "  <<  rightLowerLeg_ROTATE[2]      <<  ";\n\n";           
          //--------------------------------------         
          out << "                    rightFoot_ROTATE[3]                  = "  <<  rightFoot_ROTATE[3]          <<  ";\n";
          out << "                    rightFoot_ROTATE[0]                  = "  <<  rightFoot_ROTATE[0]          <<  ";\n";
          out << "                    rightFoot_ROTATE[1]                  = "  <<  rightFoot_ROTATE[1]          <<  ";\n";
          out << "                    rightFoot_ROTATE[2]                  = "  <<  rightFoot_ROTATE[2]          <<  ";\n\n";           
          //--------------------------------------------------------------------------------------------------------    
    
}         

if(keys['T'])
{
      #include"_MODEL_FOLDERS_/marcParts/animations/animationFrameCapture_01.cpp"
}    
//---------------------------------------------------------------------------------------------------------------------------------    

    
    
//////////---------**************************************************************
//////////---------**************************************************************
//////////---------**************************************************************
//////////---------**************************************************************
//////////---------**************************************************************
//////////---------**************************************************************    
    
    
    if (!keys[VK_LEFT])
    {  
          leftKeyIsReset  = true;
    }
    if (keys[VK_LEFT] && leftKeyIsReset)
	{
          leftKeyIsReset  = false;          
          
          
          if(BODY_PART_SELECTION == 7)
          {
              BODY_PART_SELECTION = 2;
              rightArmSelection   = 8;
          }                     
          else if(BODY_PART_SELECTION == 5)
          {
              BODY_PART_SELECTION = 2;
              rightArmSelection    = 0;
          }
          else if(BODY_PART_SELECTION == 6)
          {
              BODY_PART_SELECTION = 2;
              rightArmSelection    = 9;
          }          
          else if(BODY_PART_SELECTION == 2 && rightArmSelection == 8)
          {
              BODY_PART_SELECTION = 1;
              leftArmSelection   = 8;
          }
          else if(BODY_PART_SELECTION == 2 && rightArmSelection == 9)
          {
              BODY_PART_SELECTION = 1;
              leftArmSelection   = 9;
          }
          else if(BODY_PART_SELECTION == 2 && rightArmSelection == 0)
          {
              BODY_PART_SELECTION = 1;
              leftArmSelection   = 0;
          }                    
          else if(BODY_PART_SELECTION == 1 && leftArmSelection == 8)
          {
              BODY_PART_SELECTION = 7;
          }          
          else if(BODY_PART_SELECTION == 1 && leftArmSelection == 9)
          {
              BODY_PART_SELECTION = 6;
          }                          
          else if(BODY_PART_SELECTION == 4 && rightLegSelection == 8)
          {
              BODY_PART_SELECTION  = 3;
              leftLegSelection    = 8;
          }
          else if(BODY_PART_SELECTION == 4 && rightLegSelection == 9)
          {
              BODY_PART_SELECTION  = 3;
              leftLegSelection    = 9;
          }          
          else if(BODY_PART_SELECTION == 4 && rightLegSelection == 0)
          {
              BODY_PART_SELECTION  = 3;
              leftLegSelection    = 0;
          }    
          else if(BODY_PART_SELECTION == 3 && leftLegSelection == 8)
          {
              BODY_PART_SELECTION  = 4;
              rightLegSelection    = 8;
          }     
          else if(BODY_PART_SELECTION == 3 && leftLegSelection == 9)
          {
              BODY_PART_SELECTION  = 4;
              rightLegSelection    = 9;
          }
          else if(BODY_PART_SELECTION == 3 && leftLegSelection == 0)
          {
              BODY_PART_SELECTION  = 4;
              rightLegSelection    = 0;
          }               
          else if(BODY_PART_SELECTION == 1 && leftArmSelection == 0)
          {
              BODY_PART_SELECTION  = 5;
          }     
    
    }//__END__keys[VK_LEFT]
	
//////////---------**************************************************************   
   
   
   if (!keys[VK_RIGHT])
   {  
        rightKeyIsReset  = true;
   }    
    if (keys[VK_RIGHT] && rightKeyIsReset)
	{
          rightKeyIsReset  = false;          
          
          
          if(BODY_PART_SELECTION == 5)
          {
              BODY_PART_SELECTION = 1;
              leftArmSelection   = 0;
          }
          else if(BODY_PART_SELECTION == 6)
          {
              BODY_PART_SELECTION = 1;
              leftArmSelection    = 9;
          }
          else if(BODY_PART_SELECTION == 7)
          {
              BODY_PART_SELECTION  = 1;
              leftArmSelection     = 8;
          }          
          else if(BODY_PART_SELECTION == 1 && leftArmSelection == 8)
          {
              BODY_PART_SELECTION = 2;
              rightArmSelection   = 8;
          }
          else if(BODY_PART_SELECTION == 1 && leftArmSelection == 9)
          {
              BODY_PART_SELECTION = 2;
              rightArmSelection   = 9;
          }
          else if(BODY_PART_SELECTION == 1 && leftArmSelection == 0)
          {
              BODY_PART_SELECTION = 2;
              rightArmSelection   = 0;
          }           
           	
          else if(BODY_PART_SELECTION == 2 && leftArmSelection == 8)
          {
              BODY_PART_SELECTION = 7;
          }
                     
          else if(BODY_PART_SELECTION == 2 && rightArmSelection == 9)
          {
              BODY_PART_SELECTION = 6;
          }           
          else if(BODY_PART_SELECTION == 3 && leftLegSelection == 8)
          {
              BODY_PART_SELECTION  = 4;
              rightLegSelection    = 8;
          }
          else if(BODY_PART_SELECTION == 3 && leftLegSelection == 9)
          {
              BODY_PART_SELECTION  = 4;
              rightLegSelection    = 9;
          }          
          else if(BODY_PART_SELECTION == 3 && leftLegSelection == 0)
          {
              BODY_PART_SELECTION  = 4;
              rightLegSelection    = 0;
          }                      
          else if(BODY_PART_SELECTION == 4 && rightLegSelection == 8)
          {
              BODY_PART_SELECTION  = 3;
              leftLegSelection    = 8;
          }
          else if(BODY_PART_SELECTION == 4 && rightLegSelection == 9)
          {
              BODY_PART_SELECTION  = 3;
              leftLegSelection    = 9;
          } 
          else if(BODY_PART_SELECTION == 4 && rightLegSelection == 0)
          {
              BODY_PART_SELECTION  = 3;
              leftLegSelection    = 0;
          }           
          else if(BODY_PART_SELECTION == 2 && rightArmSelection == 0)
          {
              BODY_PART_SELECTION  = 5;
          }                          
 
          
              
    }//__END__keys[VK_RIGHT]
   
   
//////////---------**************************************************************    
    
    
    if (!keys[VK_UP])
    {  
         upKeyIsReset  = true;
    }  	
    if (keys[VK_UP] && upKeyIsReset)
	{
          upKeyIsReset  = false;         
          
          if(BODY_PART_SELECTION == 6)
          {
              BODY_PART_SELECTION = 7;
          }
          else if(BODY_PART_SELECTION == 5)
          {
              BODY_PART_SELECTION = 6;
          }            
          else if(BODY_PART_SELECTION == 7)
          {
              BODY_PART_SELECTION = 3;
              leftLegSelection    = 0;          
          }           
          else if(BODY_PART_SELECTION == 2 && rightArmSelection == 8)
          {
              BODY_PART_SELECTION = 7;
          }
          else if(BODY_PART_SELECTION == 2 && rightArmSelection == 9)
          {
              BODY_PART_SELECTION = 2;
              rightArmSelection   = 8;
          }
          else if(BODY_PART_SELECTION == 2 && rightArmSelection == 0)
          {
              BODY_PART_SELECTION = 2;
              rightArmSelection   = 9;
          }           
          /////////////////////////////////////////////////////
          else if(BODY_PART_SELECTION == 1 && leftArmSelection == 8)
          {
              BODY_PART_SELECTION = 7;
          }
          else if(BODY_PART_SELECTION == 1 && leftArmSelection == 9)
          {
              BODY_PART_SELECTION = 1;
              leftArmSelection    = 8;
          }
          else if(BODY_PART_SELECTION == 1 && leftArmSelection == 0)
          {
              BODY_PART_SELECTION = 1;
              leftArmSelection    = 9;
          }
/////////////////////////////////////////////////////          
          else if(BODY_PART_SELECTION == 4 && rightLegSelection == 8)
          {
              BODY_PART_SELECTION = 2;
              rightArmSelection   = 0;
          }
          else if(BODY_PART_SELECTION == 4 && rightLegSelection == 9)
          {
              BODY_PART_SELECTION = 4;
              rightLegSelection   = 8;
          }
          else if(BODY_PART_SELECTION == 4 && rightLegSelection == 0)
          {
              BODY_PART_SELECTION = 4;
              rightLegSelection   = 9;
          }           
/////////////////////////////////////////////////////
          else if(BODY_PART_SELECTION == 3 && leftLegSelection == 8)
          {
              BODY_PART_SELECTION = 1;
              leftArmSelection    = 0;
          }
          else if(BODY_PART_SELECTION == 3 && leftLegSelection == 9)
          {
              BODY_PART_SELECTION = 3;
              leftLegSelection    = 8;
          }
          else if(BODY_PART_SELECTION == 3 && leftLegSelection == 0)
          {
              BODY_PART_SELECTION = 3;
              leftLegSelection    = 9;
          }
            
          /////////////////////////////////////////////////////    
    
    
    }//__END__(keys[VK_UP]


//////////---------**************************************************************	
    if (!keys[VK_DOWN])
    {  
         downKeyIsReset  = true;
    }   
    if (keys[VK_DOWN] && downKeyIsReset)
	{
          downKeyIsReset  = false;          
    
          
          if(BODY_PART_SELECTION == 7)
          {
              BODY_PART_SELECTION = 6;
          }
          else if(BODY_PART_SELECTION == 6)
          {
              BODY_PART_SELECTION = 5;
          }
          else if(BODY_PART_SELECTION == 5)
          {
              BODY_PART_SELECTION = 3;
              leftLegSelection    = 8;
          }           
          else if(BODY_PART_SELECTION == 2 && rightArmSelection == 8)
          {
              BODY_PART_SELECTION = 2;
              rightArmSelection   = 9;
          }
          else if(BODY_PART_SELECTION == 2 && rightArmSelection == 9)
          {
              BODY_PART_SELECTION = 2;
              rightArmSelection   = 0;
          }
          else if(BODY_PART_SELECTION == 2 && rightArmSelection == 0)
          {
              BODY_PART_SELECTION = 4;
              rightLegSelection   = 8;
          }           
          /////////////////////////////////////////////////////
          else if(BODY_PART_SELECTION == 1 && leftArmSelection == 8)
          {
              BODY_PART_SELECTION = 1;
              leftArmSelection    = 9;
          }
          else if(BODY_PART_SELECTION == 1 && leftArmSelection == 9)
          {
              BODY_PART_SELECTION = 1;
              leftArmSelection    = 0;
          }
          else if(BODY_PART_SELECTION == 1 && leftArmSelection == 0)
          {
              BODY_PART_SELECTION = 3;
              leftLegSelection    = 8;
          }    
          /////////////////////////////////////////////////////    
          else if(BODY_PART_SELECTION == 4 && rightLegSelection == 8)
          {
              BODY_PART_SELECTION = 4;
              rightLegSelection   = 9;
          }
          else if(BODY_PART_SELECTION == 4 && rightLegSelection == 9)
          {
              BODY_PART_SELECTION = 4;
              rightLegSelection   = 0;
          }
          else if(BODY_PART_SELECTION == 4 && rightLegSelection == 0)
          {
              BODY_PART_SELECTION = 7;
          }           
          /////////////////////////////////////////////////////
          else if(BODY_PART_SELECTION == 3 && leftLegSelection == 8)
          {
              BODY_PART_SELECTION = 3;
              leftLegSelection    = 9;
          }
          else if(BODY_PART_SELECTION == 3 && leftLegSelection == 9)
          {
              BODY_PART_SELECTION = 3;
              leftLegSelection    = 0;
          }
          else if(BODY_PART_SELECTION == 3 && leftLegSelection == 0)
          {
              BODY_PART_SELECTION = 7;
          }    
          ///////////////////////////////////////////////////// 
                        
          /////////////////////////////////////////////////////     
    
    }//__END__(keys[VK_DOWN]
      
/*      
    if (keys['A'])
	{
          eyePosition[0]    += .05;
    }	
    if (keys['D'])
	{
          eyePosition[0]    -= .05;
    }

    if (keys['W'])
	{
          eyePosition[2] += .05;
    }
          if (keys['W'] && keys[VK_SHIFT])
	      {
                eyePosition[2] += .1;
          }    
	if (keys['S'])
	{
          eyePosition[2] -= .05;       
    }    
	      if (keys['S'] && keys[VK_SHIFT])
	      {
                eyePosition[2] -= .1;      
          }	
    
    if (keys['E'])
	{
          eyePosition[1] -= 0.05;
    }
	if (keys['Q'])
	{
          eyePosition[1] += 0.05;      
    }    
*/





}



void shutDown( void )
{
    
    //#include "_MODEL_FOLDERS_/iconPlates_x4/iconPlates_x4_Shutdown.cpp"   
    
    
    if( hRC != NULL )
	{
		wglMakeCurrent( NULL, NULL );
		wglDeleteContext( hRC );
		hRC = NULL;							
	}
    if( hDC != NULL )
	{
		ReleaseDC( hWnd, hDC );
		hDC = NULL;
	}
}













