GLuint marcRightBoot_vboID   =  208;

GLuint marcRightBoot_SHADER;
GLuint marcRightBoot_SHADER_Vertex;
GLuint marcRightBoot_SHADER_Fragment;

#include "marcRightBoot_VERT.cpp"
#include "marcRightBoot_NORM.cpp"
#include "marcRightBoot_TEX.cpp"
GLfloat lightPos_marcRightBoot[]               =  {3.969, 82.575, 132.685};
GLfloat lightAttenuation_marcRightBoot         =   1.283;

GLfloat rotation_AXIS_marcRightBoot[]          =  {1.0, 1.0, 1.0};
GLfloat marcRightBoot_POSITION[]               =  {0.0, 0.0, 0.0};
GLfloat     marcRightBoot_counter              = 0;
GLuint      UNIFORM_counter_marcRightBoot;

GLfloat     LightAmbient_marcRightBoot[]       = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     LightDiffuse_marcRightBoot[]       = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     LightSpecular_marcRightBoot[]      = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialAmbient_marcRightBoot[]    = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialDiffuse_marcRightBoot[]    = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialEmission_marcRightBoot[]   = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialSpecular_marcRightBoot[]   = { 0.0, 0, 0};
GLfloat     MaterialShininess_marcRightBoot   =  10.000;
GLfloat     scalemarcRightBootShadowY[]            = {1.26801, 0.0, 1.26801};
