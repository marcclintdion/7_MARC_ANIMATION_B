GLuint marcRightLowerLeg_vboID   =  205 ;

GLuint marcRightLowerLeg_SHADER;
GLuint marcRightLowerLeg_SHADER_Vertex;
GLuint marcRightLowerLeg_SHADER_Fragment;

#include "marcRightLowerLeg_VERT.cpp"
#include "marcRightLowerLeg_NORM.cpp"
#include "marcRightLowerLeg_TEX.cpp"
GLfloat lightPos_marcRightLowerLeg[]               =  {3.969, 82.575, 132.685};
GLfloat lightAttenuation_marcRightLowerLeg         =   1.283;


GLfloat     marcRightLowerLeg_counter              = 0;
GLuint      UNIFORM_counter_marcRightLowerLeg;

GLfloat     LightAmbient_marcRightLowerLeg[]       = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     LightDiffuse_marcRightLowerLeg[]       = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     LightSpecular_marcRightLowerLeg[]      = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialAmbient_marcRightLowerLeg[]    = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialDiffuse_marcRightLowerLeg[]    = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialEmission_marcRightLowerLeg[]   = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialSpecular_marcRightLowerLeg[]   = { 0.0, 0, 0};
GLfloat     MaterialShininess_marcRightLowerLeg   =  10.000;
GLfloat     scalemarcRightLowerLegShadowY[]            = {1.26801, 0.0, 1.26801};
