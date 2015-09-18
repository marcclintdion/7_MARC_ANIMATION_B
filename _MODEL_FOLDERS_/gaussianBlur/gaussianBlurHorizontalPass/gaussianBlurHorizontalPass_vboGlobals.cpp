GLuint gaussianBlurHorizontalPass_vboID   =  300 ;

GLuint gaussianBlurHorizontalPass_SHADER;
GLuint gaussianBlurHorizontalPass_SHADER_Vertex;
GLuint gaussianBlurHorizontalPass_SHADER_Fragment;

#include "gaussianBlurHorizontalPass_VERT.cpp"
#include "gaussianBlurHorizontalPass_NORM.cpp"
#include "gaussianBlurHorizontalPass_TEX.cpp"
GLfloat     gaussianBlurHorizontalPass_POSITION[]           =  {0.0, 0.0, 0.0};
GLfloat     rotation_AXIS_gaussianBlurHorizontalPass[]      =  {0.0, 1.0, 0.0, 0.0};

GLfloat     lightPos_gaussianBlurHorizontalPass[]           =  {-1.56117, 11.9431, 10.7077};
GLfloat     lightAttenuation_gaussianBlurHorizontalPass     =   1.283;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
GLfloat    shininess_gaussianBlurHorizontalPass               = 199.733f;
GLuint     UNIFORM_shininess_gaussianBlurHorizontalPass;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


GLfloat     gaussianBlurHorizontalPass_counter2             =   0.0;
GLfloat     gaussianBlurHorizontalPass_counter3             =   0.0;
GLfloat     gaussianBlurHorizontalPass_counter4             =   0.0;
GLuint      UNIFORM_counter1_gaussianBlurHorizontalPass;

GLuint      UNIFORM_counter2_gaussianBlurHorizontalPass;

GLuint      UNIFORM_counter3_gaussianBlurHorizontalPass;

GLuint      UNIFORM_counter4_gaussianBlurHorizontalPass;

GLfloat     LightAmbient_gaussianBlurHorizontalPass[]        = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     LightDiffuse_gaussianBlurHorizontalPass[]        = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     LightSpecular_gaussianBlurHorizontalPass[]       = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialAmbient_gaussianBlurHorizontalPass[]     = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialDiffuse_gaussianBlurHorizontalPass[]     = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialEmission_gaussianBlurHorizontalPass[]    = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialSpecular_gaussianBlurHorizontalPass[]    = { 0.0, 0, 0};
GLfloat     scalegaussianBlurHorizontalPassShadowY[]         = {1.26801, 0.0, 1.26801};
