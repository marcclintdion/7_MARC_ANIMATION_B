GLuint gaussianBlurVerticalPass_vboID   =  301 ;

GLuint gaussianBlurVerticalPass_SHADER;
GLuint gaussianBlurVerticalPass_SHADER_Vertex;
GLuint gaussianBlurVerticalPass_SHADER_Fragment;

#include "gaussianBlurVerticalPass_VERT.cpp"
#include "gaussianBlurVerticalPass_NORM.cpp"
#include "gaussianBlurVerticalPass_TEX.cpp"
GLfloat     gaussianBlurVerticalPass_POSITION[]           =  {0.0, 0.0, 0.0};

GLfloat     lightPos_gaussianBlurVerticalPass[]           =  {-1.56117, 11.9431, 10.7077};
GLfloat     lightAttenuation_gaussianBlurVerticalPass     =   1.283;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
GLfloat    shininess_gaussianBlurVerticalPass               = 199.733f;
GLuint     UNIFORM_shininess_gaussianBlurVerticalPass;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
GLfloat     rotation_AXIS_gaussianBlurVerticalPass[]      =  {1.0, 1.0, 1.0, 0.0};

GLfloat     gaussianBlurVerticalPass_counter2             =   0.0;
GLfloat     gaussianBlurVerticalPass_counter3             =   0.0;
GLfloat     gaussianBlurVerticalPass_counter4             =   0.0;
GLuint      UNIFORM_counter1_gaussianBlurVerticalPass;

GLuint      UNIFORM_counter2_gaussianBlurVerticalPass;

GLuint      UNIFORM_counter3_gaussianBlurVerticalPass;

GLuint      UNIFORM_counter4_gaussianBlurVerticalPass;

GLfloat     LightAmbient_gaussianBlurVerticalPass[]        = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     LightDiffuse_gaussianBlurVerticalPass[]        = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     LightSpecular_gaussianBlurVerticalPass[]       = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialAmbient_gaussianBlurVerticalPass[]     = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialDiffuse_gaussianBlurVerticalPass[]     = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialEmission_gaussianBlurVerticalPass[]    = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialSpecular_gaussianBlurVerticalPass[]    = { 0.0, 0, 0};
GLfloat     scalegaussianBlurVerticalPassShadowY[]         = {1.26801, 0.0, 1.26801};
