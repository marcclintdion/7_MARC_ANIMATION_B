
//Author: Damiano Vitulli <info@spacesimulator.net>
////__>>>output texture, normal and vertex arrays added by Marc Clint Dion, Cornwall, Ont, 2007
////__>>>output everything required for rendering with vertex + fragment shading as well as simple planer shadows: M.C.D. -> Dec 2010


#include <windows.h>


#include "glut.h"
#include "load_bmp.h"
#include "load_3ds.h"
#include "object.h"
#include "fstream.h"



int screen_width=640;
int screen_height=480;

double rotation_x=0, rotation_x_increment=0.2;
double rotation_y=0, rotation_y_increment=0.7;
double rotation_z=0, rotation_z_increment=0.0;
 
int filling=1; 

GLfloat light_ambient[]= { 0.1f, 0.1f, 0.1f, 0.1f };
GLfloat light_diffuse[]= { 1.0f, 1.0f, 1.0f, 0.0f };
GLfloat light_specular[]= { 1.0f, 1.0f, 1.0f, 0.0f };
GLfloat light_position[]= { 100.0f, 0.0f, -10.0f, 1.0f };

GLfloat mat_ambient[]= { 0.2f, 0.2f, 0.2f, 0.0f };
GLfloat mat_diffuse[]= { 0.2f, 0.2f, 0.2f, 0.0f };
GLfloat mat_specular[]= { 1.0f, 1.0f, 1.0f, 0.0f };
GLfloat mat_shininess[]= { 1.0f };

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0); 
    glViewport(0,0,screen_width,screen_height);  

    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    gluPerspective(45.0f,(GLfloat)screen_width/(GLfloat)screen_height,0.0f,100.0f); 
   
	glLightfv (GL_LIGHT1, GL_AMBIENT, light_ambient);
    glLightfv (GL_LIGHT1, GL_DIFFUSE, light_diffuse);
    glLightfv (GL_LIGHT1, GL_DIFFUSE, light_specular);
    glLightfv (GL_LIGHT1, GL_POSITION, light_position);    
    glEnable (GL_LIGHT1);
    glEnable (GL_LIGHTING);

    glMaterialfv (GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv (GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv (GL_FRONT, GL_DIFFUSE, mat_specular);
    glMaterialfv (GL_FRONT, GL_POSITION, mat_shininess);    

	glShadeModel(GL_SMOOTH);                            
	glHint (GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Texture mapping perspective correction (OpenGL... thank you so much!)
    glEnable(GL_TEXTURE_2D);                            // Texture mapping ON
    glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);         // Polygon rasterization mode (polygon filled)
	glEnable(GL_CULL_FACE);                             // Enable the back face culling
    glEnable(GL_DEPTH_TEST);                            // Enable the depth test (also called z buffer)

	
     ObjLoad ("F1_F8.3ds","skull.bmp");

      
     
      GLfloat textureMapID = 573;   
      GLuint  vboID        = 573;    
                
    

//////////////////////////////////////////////////////_______GLOBALS_______///////////////////////////////////////////////////////////
//////////////////////////////////////////////////////_______GLOBALS_______///////////////////////////////////////////////////////////

system("MKDIR F1_F8");

ofstream out_vboGlobals("F1_F8/F1_F8_vboGlobals.cpp");
         
         
         out_vboGlobals << "                             GLuint F1_F8_vboID   =  " << vboID <<" ;                                        "<< "\n\n";
         out_vboGlobals << "                             GLuint F1_F8_SHADER;                                                            "<< "\n";
         out_vboGlobals << "                             GLuint F1_F8_SHADER_Vertex;                                                     "<< "\n";
         out_vboGlobals << "                             GLuint F1_F8_SHADER_Fragment;                                                   "<< "\n\n";

         out_vboGlobals << "                             #include \"F1_F8_VERT.cpp\"                                                     "<< "\n";         
         out_vboGlobals << "                             #include \"F1_F8_NORM.cpp\"                                                     "<< "\n";
         out_vboGlobals << "                             #include \"F1_F8_TEX.cpp\"                                                      "<< "\n";
        
         out_vboGlobals << "                             GLfloat     F1_F8_POSITION[]              =  {0.0, 0.0, 0.0};                   "<< "\n\n";          
         out_vboGlobals << "                             GLfloat     rotation_AXIS_F1_F8[]         =  {0.0, 1.0, 0.0, 0.0};              "<< "\n\n";          
         
         out_vboGlobals << "                             GLfloat     lightPos_F1_F8[]              =  {-1.56117, 11.9431,  10.7077};     "<< "\n";        
         out_vboGlobals << "                             GLfloat     lightAttenuation_F1_F8        =   1.283;                            "<< "\n\n";  
         out_vboGlobals << "                             GLfloat     shininess_F1_F8               = 199.733f;                           "<< "\n\n";  
         out_vboGlobals << "                             GLuint      UNIFORM_shininess_F1_F8;                                            "<< "\n";   
         out_vboGlobals << "                             //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++      "<< "\n\n";           
         
         out_vboGlobals << "                             //----------------------------------------------------------------------------- "<< "\n\n";
        
         out_vboGlobals << "                             GLfloat    F1_F8_ShadowsPosition_01[]            =  { 0.0, 0.0,0.0};            "<< "\n";
         out_vboGlobals << "                             GLfloat    F1_F8_ShadowsRotationUP_DOWN_01       =   36.2f;                     "<< "\n";
         out_vboGlobals << "                             GLfloat    F1_F8_ShadowsRotationLEFT_RIGHT_01    =   -7.00001f;                 "<< "\n";
         out_vboGlobals << "                             GLfloat    scale_F1_F8_Shadow_01                 =    2.0f;                     "<< "\n\n";         
        
         out_vboGlobals << "                             //----------------------------------------------------------------------------- "<< "\n\n";        
        
         out_vboGlobals << "                             GLfloat    F1_F8_ShadowsPosition_00[]            =  { 0.0, 0.0,0.0};            "<< "\n";
         out_vboGlobals << "                             GLfloat    F1_F8_ShadowsRotationUP_DOWN_00       =   36.2f;                     "<< "\n";
         out_vboGlobals << "                             GLfloat    F1_F8_ShadowsRotationLEFT_RIGHT_00    =   -7.00001f;                 "<< "\n";
         out_vboGlobals << "                             GLfloat    scale_F1_F8_Shadow_00                 =    2.0f;                     "<< "\n\n";         
        
         out_vboGlobals << "                             //----------------------------------------------------------------------------- "<< "\n\n";            
        
         
         out_vboGlobals << "                             GLfloat     F1_F8_counter1             =   0.0;                                  "<< "\n";           
         out_vboGlobals << "                             GLfloat     F1_F8_counter2             =   0.0;                                  "<< "\n";
         out_vboGlobals << "                             GLfloat     F1_F8_counter3             =   0.0;                                  "<< "\n";         
         out_vboGlobals << "                             GLfloat     F1_F8_counter4             =   0.0;                                  "<< "\n";         
                  
         out_vboGlobals << "                             GLuint      UNIFORM_counter1_F1_F8;                                              "<< "\n\n"; 
         out_vboGlobals << "                             GLuint      UNIFORM_counter2_F1_F8;                                              "<< "\n\n"; 
         out_vboGlobals << "                             GLuint      UNIFORM_counter3_F1_F8;                                              "<< "\n\n";          
         out_vboGlobals << "                             GLuint      UNIFORM_counter4_F1_F8;                                              "<< "\n\n";          
         
         out_vboGlobals << "                             GLfloat     LightAmbient_F1_F8[]        = { 1.0f, 1.0f, 1.0f, 1.0f};             "<< "\n";
         out_vboGlobals << "                             GLfloat     LightDiffuse_F1_F8[]        = { 1.0f, 1.0f, 1.0f, 1.0f};             "<< "\n";
         out_vboGlobals << "                             GLfloat     LightSpecular_F1_F8[]       = { 1.0f, 1.0f, 1.0f, 1.0f};             "<< "\n";
         out_vboGlobals << "                             GLfloat     MaterialAmbient_F1_F8[]     = { 1.0f, 1.0f, 1.0f, 1.0f};             "<< "\n";
         out_vboGlobals << "                             GLfloat     MaterialDiffuse_F1_F8[]     = { 1.0f, 1.0f, 1.0f, 1.0f};             "<< "\n";
         out_vboGlobals << "                             GLfloat     MaterialEmission_F1_F8[]    = { 1.0f, 1.0f, 1.0f, 1.0f};             "<< "\n";
         out_vboGlobals << "                             GLfloat     MaterialSpecular_F1_F8[]    = { 0.0, 0, 0};                          "<< "\n";
         
         out_vboGlobals << "                             GLfloat     scaleF1_F8ShadowY[]         = {1.26801, 0.0, 1.26801};               "<< "\n";

//////////////////////////////////////////////////////_______GLOBALS_______///////////////////////////////////////////////////////////
//////////////////////////////////////////////////////_______GLOBALS_______///////////////////////////////////////////////////////////
                                         //---------------------------------------------                                                 
//////////////////////////////////////////////////////________INIT_______///////////////////////////////////////////////////////////
//////////////////////////////////////////////////////________INIT_______///////////////////////////////////////////////////////////
ofstream out_vboInit("F1_F8/F1_F8_vboInit.cpp");
         
         out_vboInit << "glGenBuffersARB(1, &F1_F8_vboID);                                                                                                " << "\n";
         out_vboInit << "glBindBufferARB(GL_ARRAY_BUFFER_ARB, F1_F8_vboID);                                                                               " << "\n";
         out_vboInit << "glBufferDataARB(GL_ARRAY_BUFFER_ARB,       sizeof(F1_F8_VERT) + sizeof(F1_F8_NORM) + sizeof(F1_F8_TEX), 0, GL_STATIC_DRAW_ARB);  " << "\n";
         out_vboInit << "glBufferSubDataARB(GL_ARRAY_BUFFER_ARB, 0, sizeof(F1_F8_VERT), F1_F8_VERT);                                                      " << "\n"; 
         out_vboInit << "glBufferSubDataARB(GL_ARRAY_BUFFER_ARB,    sizeof(F1_F8_VERT),  sizeof(F1_F8_NORM), F1_F8_NORM);                                 " << "\n";
         out_vboInit << "glBufferSubDataARB(GL_ARRAY_BUFFER_ARB,    sizeof(F1_F8_VERT) + sizeof(F1_F8_NORM), sizeof(F1_F8_TEX), F1_F8_TEX);               " << "\n\n\n";
         

         out_vboInit << "    loadTexture(\"_MODEL_FOLDERS_/F1_F8/F1_F8.jpg\",        textureMap["  << textureMapID << "]);                                " << "\n";
         out_vboInit << "    loadTexture(\"_MODEL_FOLDERS_/F1_F8/F1_F8_DOT3.bmp\",   normalMap["   << textureMapID << "]);                                " << "\n";         
         out_vboInit << "  //loadTexture(\"_MODEL_FOLDERS_/F1_F8/F1_F8_BUMP.jpg\", specularMap[" << textureMapID << "]);                                  " << "\n";
//////////////////////////////////////////////////////________INIT_______///////////////////////////////////////////////////////////
//////////////////////////////////////////////////////________INIT_______///////////////////////////////////////////////////////////                                        
                                         //---------------------------------------------
                                        //--------------------------------------------- 
/////////////////////////////////////////////////////_____SHADER_SETUP_____//////////////////////////////////////////////////////////
/////////////////////////////////////////////////////_____SHADER_SETUP_____////////////////////////////////////////////////////////// 
ofstream out_SHADER_INIT("F1_F8/F1_F8_shaderInit.cpp");         

         out_SHADER_INIT << "    const char *F1_F8_SHADER_VertexStrings[1];                                                            "<< "\n";
         out_SHADER_INIT << "    const char *F1_F8_SHADER_FragmentStrings[1];                                                          "<< "\n\n";
   
         out_SHADER_INIT << "    F1_F8_SHADER_Vertex = glCreateShaderObjectARB( GL_VERTEX_SHADER_ARB );                                "<< "\n\n";    

         out_SHADER_INIT << "	 unsigned char *F1_F8_SHADER_VertexAssembly = readShaderFile( \"_MODEL_FOLDERS_/F1_F8/F1_F8.vert\" );  "<< "\n";
         out_SHADER_INIT << "    F1_F8_SHADER_VertexStrings[0] = (char*)F1_F8_SHADER_VertexAssembly;                                   "<< "\n";
         out_SHADER_INIT << "    glShaderSourceARB( F1_F8_SHADER_Vertex, 1, F1_F8_SHADER_VertexStrings, NULL );                        " << "\n";
         out_SHADER_INIT << "    glCompileShaderARB( F1_F8_SHADER_Vertex);                                                             " << "\n";
         out_SHADER_INIT << "    delete F1_F8_SHADER_VertexAssembly;                                                                   " << "\n\n";

         out_SHADER_INIT << "    F1_F8_SHADER_Fragment = glCreateShaderObjectARB( GL_FRAGMENT_SHADER_ARB );                            " << "\n\n";

         out_SHADER_INIT << "    unsigned char *F1_F8_SHADER_FragmentAssembly = readShaderFile( \"_MODEL_FOLDERS_/F1_F8/F1_F8.frag\" );" << "\n";
         out_SHADER_INIT << "    F1_F8_SHADER_FragmentStrings[0] = (char*)F1_F8_SHADER_FragmentAssembly;                               " << "\n";
         out_SHADER_INIT << "    glShaderSourceARB( F1_F8_SHADER_Fragment, 1, F1_F8_SHADER_FragmentStrings, NULL );                    " << "\n";
         out_SHADER_INIT << "    glCompileShaderARB(F1_F8_SHADER_Fragment );                                                           " << "\n\n";
    
         out_SHADER_INIT << "    delete F1_F8_SHADER_FragmentAssembly;                                                                 " << "\n\n";

         out_SHADER_INIT << "	 F1_F8_SHADER = glCreateProgramObjectARB();                                                            " << "\n\n";
         out_SHADER_INIT << "    glAttachObjectARB( F1_F8_SHADER, F1_F8_SHADER_Vertex );                                               " << "\n";
         out_SHADER_INIT << "    glAttachObjectARB( F1_F8_SHADER, F1_F8_SHADER_Fragment );                                             " << "\n\n";

         out_SHADER_INIT << "    glLinkProgramARB(F1_F8_SHADER);                                                                       " << "\n\n";  

         out_SHADER_INIT << "    UNIFORM_shininess_F1_F8 = glGetUniformLocationARB(  F1_F8_SHADER, \"shiny\" );                        " << "\n\n";          
         
         out_SHADER_INIT << "    UNIFORM_counter1_F1_F8 = glGetUniformLocationARB( F1_F8_SHADER, \"counter1\" );                       " << "\n\n";
         out_SHADER_INIT << "    UNIFORM_counter2_F1_F8 = glGetUniformLocationARB( F1_F8_SHADER, \"counter2\" );                       " << "\n\n";
         out_SHADER_INIT << "    UNIFORM_counter3_F1_F8 = glGetUniformLocationARB( F1_F8_SHADER, \"counter3\" );                       " << "\n\n";
         out_SHADER_INIT << "    UNIFORM_counter4_F1_F8 = glGetUniformLocationARB( F1_F8_SHADER, \"counter4\" );                       " << "\n\n";
         


/////////////////////////////////////////////////////_____SHADER_SETUP_____//////////////////////////////////////////////////////////
/////////////////////////////////////////////////////_____SHADER_SETUP_____////////////////////////////////////////////////////////// 
////////////////////////////////////////////////////_______VERTEX_SHADER______//////////////////////////////////////////////////////	
////////////////////////////////////////////////////_______VERTEX_SHADER______//////////////////////////////////////////////////////
ofstream out_vertexShader("F1_F8/F1_F8.vert");
         out_vertexShader << "uniform float counter1;"                                                                                           << "\n";         
         out_vertexShader << "uniform float counter2;"                                                                                           << "\n";          
         out_vertexShader << "uniform float counter3;"                                                                                           << "\n";          
         out_vertexShader << "uniform float counter4;"                                                                                           << "\n\n";          
         
         out_vertexShader << "varying vec4 position;"                                                                                           << "\n\n";

         out_vertexShader << "varying vec3 lightDir1;"                                                                                          << "\n\n";

         out_vertexShader << "varying float attenuation;"                                                                                       << "\n\n";

         out_vertexShader << "void main( void )"                                                                                                << "\n";
         out_vertexShader << "{"                                                                                                                << "\n";
         out_vertexShader << "    gl_TexCoord[0]   = gl_MultiTexCoord0;"                                                                        << "\n\n";
    
         out_vertexShader << "    position         = gl_Vertex;"                                                                                << "\n";
         out_vertexShader << "    gl_Position      = gl_ModelViewProjectionMatrix * gl_Vertex;"                                                 << "\n\n";
    
         out_vertexShader << "    lightDir1        =  normalize(gl_LightSource[0].position.xyz - position.xyz);"                                << "\n";
         out_vertexShader << "    attenuation      =  1.00 / (gl_LightSource[0].quadraticAttenuation);"                                         << "\n";
         out_vertexShader << "}" << "\n\n";
////////////////////////////////////////////////////_______VERTEX_SHADER______//////////////////////////////////////////////////////	
////////////////////////////////////////////////////_______VERTEX_SHADER______//////////////////////////////////////////////////////
                                         //---------------------------------------------
////////////////////////////////////////////////////_____FRAGMENT_SHADER_____//////////////////////////////////////////////////////	
////////////////////////////////////////////////////_____FRAGMENT_SHADER_____//////////////////////////////////////////////////////
ofstream out_fragmentShader("F1_F8/F1_F8.frag");
         
         out_fragmentShader << "uniform float counter1;"                                                                                        << "\n";         
         out_fragmentShader << "uniform float counter2;"                                                                                        << "\n";          
         out_fragmentShader << "uniform float counter3;"                                                                                        << "\n";          
         out_fragmentShader << "uniform float counter4;"                                                                                        << "\n\n";          
         
         out_fragmentShader << "varying vec4 position;"                                                                                         << "\n\n";

         out_fragmentShader << "float distance;  "                                                                                              << "\n";
         out_fragmentShader << "varying float attenuation;"                                                                                     << "\n\n";
         
         out_fragmentShader << "uniform sampler2D Texture1;"                                                                                    << "\n";         
         out_fragmentShader << "uniform sampler2D NormalMap;"                                                                                   << "\n";
         out_fragmentShader << "//uniform sampler2D Texture3;"                                                                                  << "\n\n";         
         
         out_fragmentShader << "vec4   finalcolor;"                                                                                             << "\n";         
         out_fragmentShader << "vec3   normal;"                                                                                                 << "\n";
         out_fragmentShader << "//vec4 thirdTexture;"                                                                                           << "\n\n\n";

         
         out_fragmentShader << "varying vec3 lightDir1;"                                                                                        << "\n\n";

         out_fragmentShader << "float NdotL1;"                                                                                                  << "\n\n";
        
         out_fragmentShader << "uniform float shiny;"                                                                                           << "\n\n";
         
         out_fragmentShader << "void main( void )"                                                                                              << "\n";
         out_fragmentShader << "{"                                                                                                              << "\n";
         
         out_fragmentShader << "    finalcolor                =  texture2D(Texture1,gl_TexCoord[0].xy);"                                        << "\n\n";         
         
         out_fragmentShader << "    vec3 NormalTex            =  texture2D(NormalMap,  gl_TexCoord[0].st).xyz;"                                 << "\n";
         out_fragmentShader << "    NormalTex                 = (NormalTex - 0.5) * 2.0;"                                                       << "\n";
         out_fragmentShader << "    normal                    =  normalize(NormalTex);"                                                          << "\n";
         out_fragmentShader << "    NdotL1                    =  dot(normal,lightDir1);"                                                        << "\n\n";        
         
         out_fragmentShader << "    //thirdTexture            =  texture2D(Texture3,  gl_TexCoord[0].st);"                                      << "\n\n";
         
         
         out_fragmentShader << "    float specularLight       =  pow(max(NdotL1, 0.0), shiny);"                                                  << "\n";        
         out_fragmentShader << "    finalcolor               +=  specularLight * finalcolor;"                                                    << "\n\n";        
         
         out_fragmentShader << "    finalcolor               *=  attenuation * NdotL1 * NdotL1; "                                               << "\n\n";         
         
         out_fragmentShader << "    gl_FragColor              =  finalcolor;"                                                                   << "\n\n";
         out_fragmentShader << "}"                                                                                                              << "\n";
////////////////////////////////////////////////////_____FRAGMENT_SHADER_____//////////////////////////////////////////////////////	
////////////////////////////////////////////////////_____FRAGMENT_SHADER_____//////////////////////////////////////////////////////
                                        //---------------------------------------------
//////////////////////////////////////////////////////_______RENDER_______///////////////////////////////////////////////////////////
//////////////////////////////////////////////////////_______RENDER_______///////////////////////////////////////////////////////////
ofstream out_vboRender("F1_F8/F1_F8_vboRender.cpp");
         out_vboRender << "//glPushMatrix();"                                                                                                                 << "\n";    
         out_vboRender << "              glTranslatef(moveSet[0], moveSet[1], moveSet[2]);                                                "                   << "\n";           
         out_vboRender << "              glTranslatef(F1_F8_POSITION[0], F1_F8_POSITION[1], F1_F8_POSITION[2]);"                                              << "\n";       
         out_vboRender << "              glRotatef(rotation_AXIS_F1_F8[3],rotation_AXIS_F1_F8[0], rotation_AXIS_F1_F8[1], rotation_AXIS_F1_F8[2]);"           << "\n\n";          
         
         out_vboRender << "              glPushMatrix();"                                                                                                     << "\n";         
         out_vboRender << "                   glLoadIdentity();"                                                                                              << "\n";          
         out_vboRender << "                //_ADDITIONAL_ROTATIONS_GO_HERE"                                                                                   << "\n";         
         out_vboRender << "                   glRotatef(-rotation_AXIS_F1_F8[3],rotation_AXIS_F1_F8[0], rotation_AXIS_F1_F8[1], rotation_AXIS_F1_F8[2]);"     << "\n\n";          
         out_vboRender << "                   glRotatef(-look_LEFT_RIGHT, 0, -1, 0);"                                                                         << "\n";        
         out_vboRender << "                   glTranslatef(-eyePosition[0],-eyePosition[1],-eyePosition[2]);"                                                 << "\n";           
         out_vboRender << "                   glLightfv(GL_LIGHT0,GL_POSITION,lightPos_F1_F8);"                                                               << "\n";
         out_vboRender << "                   glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_F1_F8);"                                        << "\n";
        out_vboRender << "              glPopMatrix();"                                                                                                       << "\n\n";           
         out_vboRender << "//glPopMatrix();"                                                                                                                  << "\n\n";           
         
        
         
         out_vboRender << "              glUseProgramObjectARB(F1_F8_SHADER);"                                                                                << "\n\n\n";     
         
         out_vboRender << "              glUniform1fARB( UNIFORM_shininess_F1_F8, shininess_F1_F8);"                                                          << "\n";         
         
         out_vboRender << "              glUniform1fARB( UNIFORM_counter1_F1_F8, F1_F8_counter1);"                                                            << "\n";
         out_vboRender << "              glUniform1fARB( UNIFORM_counter2_F1_F8, F1_F8_counter2);"                                                            << "\n";
         out_vboRender << "              glUniform1fARB( UNIFORM_counter3_F1_F8, F1_F8_counter3);"                                                            << "\n";         
         out_vboRender << "              glUniform1fARB( UNIFORM_counter4_F1_F8, F1_F8_counter4);"                                                            << "\n\n\n";          
         
         out_vboRender << "              glBindBufferARB(GL_ARRAY_BUFFER_ARB, F1_F8_vboID);"                                                                  << "\n\n";
         
         out_vboRender << "              glEnableClientState(GL_TEXTURE_COORD_ARRAY );"                                                                       << "\n";                 
         out_vboRender << "              glEnableClientState(GL_NORMAL_ARRAY);"                                                                               << "\n";
         out_vboRender << "              glEnableClientState(GL_VERTEX_ARRAY);"                                                                               << "\n";
            
         out_vboRender << "              glTexCoordPointer(3, GL_FLOAT, 0, (void*)(sizeof(F1_F8_VERT) + sizeof(F1_F8_NORM)));"                                << "\n";              
         out_vboRender << "              glNormalPointer(GL_FLOAT, 0, (void*)sizeof(F1_F8_VERT));"                                                            << "\n";
         out_vboRender << "              glVertexPointer(3, GL_FLOAT, 0, 0);"                                                                                 << "\n\n";

         out_vboRender << "            //Texture3_textureID = glGetUniformLocationARB(F1_F8_SHADER,\"Texture3\");"                                            << "\n";
         out_vboRender << "            //glUniform1iARB(Texture3_textureID, 2);"                                                                              << "\n";
         out_vboRender << "            //glActiveTextureARB(GL_TEXTURE2_ARB);"                                                                                << "\n";
         out_vboRender << "            //glBindTexture(GL_TEXTURE_2D,  specularMap[" << textureMapID << "]);"                                                 << "\n\n"; 
         
         out_vboRender << "              DOT3_textureID     = glGetUniformLocationARB(F1_F8_SHADER,\"NormalMap\");"                                           << "\n"; 
         out_vboRender << "              glUniform1iARB(DOT3_textureID, 1);"                                                                                  << "\n"; 
         out_vboRender << "              glActiveTextureARB(GL_TEXTURE1_ARB);"                                                                                << "\n"; 
         out_vboRender << "              glBindTexture(GL_TEXTURE_2D,  normalMap["   << textureMapID << "]);"                                                 << "\n\n";
         
         out_vboRender << "              textureID     = glGetUniformLocationARB(F1_F8_SHADER,\"Texture1\");"                                                 << "\n";
         out_vboRender << "              glUniform1iARB(textureID, 0);"                                                                                       << "\n"; 
         out_vboRender << "              glActiveTextureARB(GL_TEXTURE0_ARB);"                                                                                << "\n";
         out_vboRender << "              glBindTexture(GL_TEXTURE_2D, textureMap["   << textureMapID << "]);"                                                 << "\n\n\n";
         
 
         
         
         out_vboRender << "              glDrawArrays(GL_TRIANGLES, 0, " << object.polygons_qty*3 << ");"                                                     << "\n\n\n";
                            
         
         out_vboRender << "              glDisableClientState(GL_VERTEX_ARRAY);"                                                                              << "\n"; 
         out_vboRender << "              glDisableClientState(GL_NORMAL_ARRAY);"                                                                              << "\n";
         out_vboRender << "              glDisableClientState(GL_TEXTURE_COORD_ARRAY);"                                                                       << "\n\n";

         out_vboRender << "              glUseProgramObjectARB(0);"                                                                                           << "\n\n";
         
         
//////////////////////////////////////////////////////_______RENDER_______///////////////////////////////////////////////////////////
//////////////////////////////////////////////////////_______RENDER_______///////////////////////////////////////////////////////////

                                         //---------------------------------------------
////////////////////////////////////////////////////________SHADOWS___________//////////////////////////////////////////////////////	
////////////////////////////////////////////////////________SHADOWS___________//////////////////////////////////////////////////////                                         

ofstream out_shadows_01("F1_F8/F1_F8_vboShadow_01.cpp");         
         
         
         out_shadows_01 << "/*        glColor4f(0.4, 0.4, 0.4, 1.0);                                                                                                      "<< "\n\n";  
         
         
         out_shadows_01 << "/*        glPushMatrix();                                                                                                                     "<< "\n\n";             
        
         out_shadows_01 << "             glTranslatef(moveSet[0], -moveSet[2], 0.0f);                                                                                     "<< "\n";
         out_shadows_01 << "             glTranslatef(F1_F8_ShadowsPosition_01[0]+F1_F8_POSITION[0], F1_F8_ShadowsPosition_01[1]+F1_F8_POSITION[1], F1_F8_ShadowsPosition_01[2]+F1_F8_POSITION[2]); "<< "\n";
         out_shadows_01 << "             glRotatef(rotation_AXIS_F1_F8[3],rotation_AXIS_F1_F8[0], rotation_AXIS_F1_F8[1], rotation_AXIS_F1_F8[2]);                        "<< "\n";
         
         out_shadows_01 << "             glRotatef(F1_F8_ShadowsRotationUP_DOWN_01, 1, 0, 0);                                                                             "<< "\n";
         out_shadows_01 << "             glRotatef(F1_F8_ShadowsRotationLEFT_RIGHT_01, 0, 0, 1);                                                                          "<< "\n";
         out_shadows_01 << "             glScalef(scale_F1_F8_Shadow_01, 0.0, scale_F1_F8_Shadow_01);                                                                     "<< "\n";
   
         out_shadows_01 << "          glPopMatrix();*/                                                                                                                    "<< "\n\n";          
         
         out_shadows_01 << "             glBindBufferARB(GL_ARRAY_BUFFER_ARB, F1_F8_vboID);                                                                               "<< "\n\n";

         out_shadows_01 << "             glEnableClientState(GL_TEXTURE_COORD_ARRAY );                                                                                    "<< "\n";
         out_shadows_01 << "             glEnableClientState(GL_NORMAL_ARRAY);                                                                                            "<< "\n";
         out_shadows_01 << "             glEnableClientState(GL_VERTEX_ARRAY);                                                                                            "<< "\n";
         out_shadows_01 << "             glTexCoordPointer(3, GL_FLOAT, 0, (void*)(sizeof(F1_F8_VERT) + sizeof(F1_F8_NORM)));                                             "<< "\n";
         out_shadows_01 << "             glNormalPointer(GL_FLOAT, 0, (void*)sizeof(F1_F8_VERT));                                                                         "<< "\n";
         out_shadows_01 << "             glVertexPointer(3, GL_FLOAT, 0, 0);                                                                                              "<< "\n\n";

         out_shadows_01 << "             glDrawArrays(GL_TRIANGLES, 0, " << object.polygons_qty*3 << ");                                                                  "<< "\n\n";

         out_shadows_01 << "             glDisableClientState(GL_VERTEX_ARRAY);                                                                                           "<< "\n";
         out_shadows_01 << "             glDisableClientState(GL_NORMAL_ARRAY);                                                                                           "<< "\n";
         out_shadows_01 << "             glDisableClientState(GL_TEXTURE_COORD_ARRAY);                                                                                    "<< "\n\n";

////////////////////////////////////////////////////________SHADOWS___________//////////////////////////////////////////////////////	
////////////////////////////////////////////////////________SHADOWS___________//////////////////////////////////////////////////////                                         

                                         //---------------------------------------------
////////////////////////////////////////////////////________SHADOWS___________//////////////////////////////////////////////////////	
////////////////////////////////////////////////////________SHADOWS___________//////////////////////////////////////////////////////                                         

ofstream out_shadows_00("F1_F8/F1_F8_vboShadow_00.cpp");         
         
         
         out_shadows_00 << "/*        glColor4f(0.4, 0.4, 0.4, 1.0);                                                                                                      "<< "\n\n";          
         
         out_shadows_00 << "/*       glPushMatrix();                                                                                                                      "<< "\n\n";           
         out_shadows_00 << "             glTranslatef(moveSet[0], -moveSet[2], 0.0f);                                                                                     "<< "\n";
         out_shadows_00 << "             glTranslatef(F1_F8_ShadowsPosition_00[0]+F1_F8_POSITION[0], F1_F8_ShadowsPosition_00[1]+F1_F8_POSITION[1], F1_F8_ShadowsPosition_00[2]+F1_F8_POSITION[2]); "<< "\n";
         out_shadows_00 << "             glRotatef(rotation_AXIS_F1_F8[3],rotation_AXIS_F1_F8[0], rotation_AXIS_F1_F8[1], rotation_AXIS_F1_F8[2]);                        "<< "\n";
            
         out_shadows_00 << "             glRotatef(F1_F8_ShadowsRotationUP_DOWN_00, 1, 0, 0);                                                                             "<< "\n";
         out_shadows_00 << "             glRotatef(F1_F8_ShadowsRotationLEFT_RIGHT_00, 0, 0, 1);                                                                          "<< "\n";
         out_shadows_00 << "             glScalef(scale_F1_F8_Shadow_00, 0.0, scale_F1_F8_Shadow_00);                                                                     "<< "\n";
         out_shadows_00 << "         glPopMatrix();*/                                                                                                                     "<< "\n\n";           
         
         out_shadows_00 << "             glBindBufferARB(GL_ARRAY_BUFFER_ARB, F1_F8_vboID);                                                                               "<< "\n\n";

         out_shadows_00 << "             glEnableClientState(GL_TEXTURE_COORD_ARRAY );                                                                                    "<< "\n";
         out_shadows_00 << "             glEnableClientState(GL_NORMAL_ARRAY);                                                                                            "<< "\n";
         out_shadows_00 << "             glEnableClientState(GL_VERTEX_ARRAY);                                                                                            "<< "\n";
         out_shadows_00 << "             glTexCoordPointer(3, GL_FLOAT, 0, (void*)(sizeof(F1_F8_VERT) + sizeof(F1_F8_NORM)));                                             "<< "\n";
         out_shadows_00 << "             glNormalPointer(GL_FLOAT, 0, (void*)sizeof(F1_F8_VERT));                                                                         "<< "\n";
         out_shadows_00 << "             glVertexPointer(3, GL_FLOAT, 0, 0);                                                                                              "<< "\n\n";

         out_shadows_00 << "             glDrawArrays(GL_TRIANGLES, 0, " << object.polygons_qty*3 << ");                                                                  "<< "\n\n";
         
         out_shadows_00 << "             glDisableClientState(GL_VERTEX_ARRAY);                                                                                           "<< "\n";
         out_shadows_00 << "             glDisableClientState(GL_NORMAL_ARRAY);                                                                                           "<< "\n";
         out_shadows_00 << "             glDisableClientState(GL_TEXTURE_COORD_ARRAY);                                                                                    "<< "\n\n";

////////////////////////////////////////////////////________SHADOWS___________//////////////////////////////////////////////////////	
////////////////////////////////////////////////////________SHADOWS___________//////////////////////////////////////////////////////   


                                         //---------------------------------------------
////////////////////////////////////////////////////_____LOCATION_STRINGS_____//////////////////////////////////////////////////////	
////////////////////////////////////////////////////_____LOCATION_STRINGS_____//////////////////////////////////////////////////////
ofstream out_LOCATION_STRINGS("F1_F8/_LOCATION_STRINGS.cpp");
         
         out_LOCATION_STRINGS << "                             #include \"_MODEL_FOLDERS_/F1_F8/F1_F8_vboGlobals.cpp\"  //vboID = "    << "" << vboID <<"\n";                                              
         out_LOCATION_STRINGS << "                             #include \"_MODEL_FOLDERS_/F1_F8/F1_F8_vboRender.cpp\"   //vboID = "    << "" << vboID <<"\n";
         out_LOCATION_STRINGS << "                             #include \"_MODEL_FOLDERS_/F1_F8/F1_F8_vboInit.cpp\"     //vboID = "    << "" << vboID <<"\n";         
         out_LOCATION_STRINGS << "                             #include \"_MODEL_FOLDERS_/F1_F8/F1_F8_shaderInit.cpp\"  //vboID = "    << "" << vboID <<"\n";         
         out_LOCATION_STRINGS << "                             #include \"_MODEL_FOLDERS_/F1_F8/F1_F8_vboShadow_01.cpp\" //vboID = "   << "" << vboID <<"\n";         
         out_LOCATION_STRINGS << "                             #include \"_MODEL_FOLDERS_/F1_F8/F1_F8_vboShadow_00.cpp\" //vboID = "   << "" << vboID <<"\n";    

////////////////////////////////////////////////////_____LOCATION_STRINGS_____//////////////////////////////////////////////////////	
////////////////////////////////////////////////////_____LOCATION_STRINGS_____//////////////////////////////////////////////////////
}
void display(void)
{
    glDisable(GL_LIGHTING);
   
   
    ofstream outTexture( "F1_F8/F1_F8_TEX.cpp" );
    ofstream outNormal(  "F1_F8/F1_F8_NORM.cpp");
    ofstream outVertices("F1_F8/F1_F8_VERT.cpp");
    int j;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // This clear the background color to dark blue
    glMatrixMode(GL_MODELVIEW); // Modeling transformation
    glLoadIdentity(); // Initialize the model matrix as identity
    glTranslatef(0.0,0.0,-5); // We move the object forward (the model matrix is multiplied by the translation matrix)
    rotation_x = rotation_x + rotation_x_increment;
    rotation_y = rotation_y + rotation_y_increment;
    rotation_z = rotation_z + rotation_z_increment;
    if (rotation_x > 359) rotation_x = 0;
    if (rotation_y > 359) rotation_y = 0;
    if (rotation_z > 359) rotation_z = 0;
    glRotatef(rotation_x,1.0,0.0,0.0); // Rotations of the object (the model matrix is multiplied by the rotation matrices)
    glRotatef(rotation_y,0.0,1.0,0.0);
    glRotatef(rotation_z,0.0,0.0,1.0);
    
    if (object.id_texture!=-1) 
	{
		glBindTexture(GL_TEXTURE_2D, object.id_texture); // We set the active texture 
	    glEnable(GL_TEXTURE_2D); // Texture mapping ON
	}
	else
	    glDisable(GL_TEXTURE_2D); // Texture mapping OFF

outTexture  << "GLfloat F1_F8_TEX[]   = \n" << "{\n"    << "  //number of vertices = " << object.polygons_qty*3 << "\n\n";
outNormal   << "GLfloat F1_F8_NORM[]  = \n" << "{\n"    << "  //number of vertices = " << object.polygons_qty*3 << "\n\n";	
outVertices << "GLfloat F1_F8_VERT[]  = \n" << "{\n"    << "  //number of vertices = " << object.polygons_qty*3 << "\n\n";
    
    glBegin(GL_TRIANGLES); // glBegin and glEnd delimit the vertices that define a primitive (in our case triangles)
	for (j=0;j<object.polygons_qty;j++)
	{
		glTexCoord2f( object.mapcoord[ object.polygon[j].a ].u, object.mapcoord[ object.polygon[j].a ].v);
        outTexture << "" << object.mapcoord[ object.polygon[j].a ].u << ", ";
        outTexture << object.mapcoord[ object.polygon[j].a ].v << ", 1.0,\n";
        
        glNormal3f( object.normal[ object.polygon[j].a ].x, object.normal[ object.polygon[j].a ].y, object.normal[ object.polygon[j].a ].z);
        outNormal << "" << object.normal[ object.polygon[j].a ].x << ", ";
        outNormal << object.normal[ object.polygon[j].a ].y << ", ";
        outNormal << object.normal[ object.polygon[j].a ].z <<  ",\n";
		
		glVertex3f( object.vertex[ object.polygon[j].a ].x, object.vertex[ object.polygon[j].a ].y, object.vertex[ object.polygon[j].a ].z);

        outVertices << "" << object.vertex[ object.polygon[j].a ].x << ", ";
        outVertices << object.vertex[ object.polygon[j].a ].y << ", ";
        outVertices << object.vertex[ object.polygon[j].a ].z << ",\n";
	
        
        glTexCoord2f( object.mapcoord[ object.polygon[j].b ].u, object.mapcoord[ object.polygon[j].b ].v);
		outTexture << "" << object.mapcoord[ object.polygon[j].b ].u << ", ";
        outTexture << object.mapcoord[ object.polygon[j].b ].v << ", 1.0,\n";
        
        glNormal3f( object.normal[ object.polygon[j].b ].x, object.normal[ object.polygon[j].b ].y, object.normal[ object.polygon[j].b ].z);

        outNormal << "" << object.normal[ object.polygon[j].b ].x << ", ";
        outNormal << object.normal[ object.polygon[j].b ].y << ", ";
        outNormal << object.normal[ object.polygon[j].b ].z << ",\n";					

        glVertex3f( object.vertex[ object.polygon[j].b ].x, object.vertex[ object.polygon[j].b ].y, object.vertex[ object.polygon[j].b ].z);
					
        outVertices << "" << object.vertex[ object.polygon[j].b ].x << ", ";
        outVertices << object.vertex[ object.polygon[j].b ].y << ", ";
        outVertices << object.vertex[ object.polygon[j].b ].z << ",\n";					
        
		
        
        glTexCoord2f( object.mapcoord[ object.polygon[j].c ].u, object.mapcoord[ object.polygon[j].c ].v);
	    outTexture << "" << object.mapcoord[ object.polygon[j].c ].u << ", ";
        outTexture << object.mapcoord[ object.polygon[j].c ].v << ", 1.0,\n\n";
    	
    	
        //Normal coordinates of the third vertex
		glNormal3f( object.normal[ object.polygon[j].c ].x, object.normal[ object.polygon[j].c ].y, object.normal[ object.polygon[j].c ].z);
  
        outNormal << "" << object.normal[ object.polygon[j].c ].x << ", ";
        outNormal << object.normal[ object.polygon[j].c ].y << ", ";
        outNormal << object.normal[ object.polygon[j].c ].z << ",\n\n";

		
        glVertex3f( object.vertex[ object.polygon[j].c ].x, object.vertex[ object.polygon[j].c ].y, object.vertex[ object.polygon[j].c ].z);
					
        outVertices << "" << object.vertex[ object.polygon[j].c ].x << ", ";
        outVertices << object.vertex[ object.polygon[j].c ].y << ", ";
        outVertices << object.vertex[ object.polygon[j].c ].z << ",\n\n";
  					
	}
	
outTexture << "};\n";
outNormal << "};\n";
outVertices << "};\n";	
	
 glEnd();    
  
   
    
    //glmDraw(couch, GLM_NONE);
    
    
    glFlush(); // This force the execution of OpenGL commands
    glutSwapBuffers(); // In double buffered mode we invert the positions of the visible buffer and the writing buffer
}
void resize (int p_width, int p_height)
{
	if (screen_width==0 && screen_height==0) exit(0);
    screen_width=p_width; // We obtain the new screen width values and store it
    screen_height=p_height; // Height value

    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // We clear both the color and the depth buffer so to draw the next frame
    glViewport(0,0,screen_width,screen_height); // Viewport transformation

    glMatrixMode(GL_PROJECTION); // Projection transformation
    glLoadIdentity(); // We initialize the projection matrix as identity
    gluPerspective(45.0f,(GLfloat)screen_width/(GLfloat)screen_height,0.1f,100.0f);
glutPostRedisplay (); // This command redraw the scene (it calls the same routine of glutDisplayFunc)
}

void keyboard(unsigned char p_key, int p_x, int p_y)
{  
    switch (p_key)
    {
        case ' ':
            rotation_x_increment=0;
            rotation_y_increment=0;
            rotation_z_increment=0;
        break;
		case 'r': case 'R':
            if (filling==0)
            {
                glPolygonMode (GL_FRONT_AND_BACK, GL_FILL); // Polygon rasterization mode (polygon filled)
                filling=1;
            }   
            else 
            {
                glPolygonMode (GL_FRONT_AND_BACK, GL_LINE); // Polygon rasterization mode (polygon outlined)
                filling=0;
            }
        break;
		case 27:
			exit(0);
		break;
    }
}
void keyboard_s (int p_key, int p_x, int py)
{
    switch (p_key)
    {
        case GLUT_KEY_UP:
            rotation_x_increment = rotation_x_increment +0.005;
        break;
        case GLUT_KEY_DOWN:
            rotation_x_increment = rotation_x_increment -0.005;
        break;
        case GLUT_KEY_LEFT:
            rotation_y_increment = rotation_y_increment +0.005;
        break;
        case GLUT_KEY_RIGHT:
            rotation_y_increment = rotation_y_increment -0.005;
        break;
    }
}
/**********************************************************
 *
 * The main routine
 * 
 *********************************************************/

int main(int argc, char **argv)
{
    // We use the GLUT utility to initialize the window, to handle the input and to interact with the windows system
    glutInit(&argc, argv);    
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(screen_width,screen_height);
    glutInitWindowPosition(0,0);
    glutCreateWindow("www.spacesimulator.net - 3d engine tutorials - To exit press ESC");    
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutReshapeFunc (resize);
    glutKeyboardFunc (keyboard);
    glutSpecialFunc (keyboard_s);
    init();
    glutMainLoop();

    return(0);    
}
