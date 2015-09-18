GLuint marcRightUpperLeg_vboID   =  204 ;

GLuint marcRightUpperLeg_SHADER;
GLuint marcRightUpperLeg_SHADER_Vertex;
GLuint marcRightUpperLeg_SHADER_Fragment;

#include "marcRightUpperLeg_VERT.cpp"
#include "marcRightUpperLeg_NORM.cpp"
#include "marcRightUpperLeg_TEX.cpp"
GLfloat lightPos_marcRightUpperLeg[]               =  {3.969, 82.575, 132.685};
GLfloat lightAttenuation_marcRightUpperLeg         =   1.283;


GLfloat     marcRightUpperLeg_counter              = 0;
GLuint      UNIFORM_counter_marcRightUpperLeg;

GLfloat     LightAmbient_marcRightUpperLeg[]       = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     LightDiffuse_marcRightUpperLeg[]       = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     LightSpecular_marcRightUpperLeg[]      = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialAmbient_marcRightUpperLeg[]    = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialDiffuse_marcRightUpperLeg[]    = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialEmission_marcRightUpperLeg[]   = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialSpecular_marcRightUpperLeg[]   = { 0.0, 0, 0};
GLfloat     MaterialShininess_marcRightUpperLeg   =  10.000;
GLfloat     scalemarcRightUpperLegShadowY[]            = {1.26801, 0.0, 1.26801};
