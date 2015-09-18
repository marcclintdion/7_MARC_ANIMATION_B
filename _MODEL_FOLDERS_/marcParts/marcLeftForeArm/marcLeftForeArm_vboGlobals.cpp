GLuint marcLeftForeArm_vboID   =  214 ;

GLuint marcLeftForeArm_SHADER;
GLuint marcLeftForeArm_SHADER_Vertex;
GLuint marcLeftForeArm_SHADER_Fragment;

#include "marcLeftForeArm_VERT.cpp"
#include "marcLeftForeArm_NORM.cpp"
#include "marcLeftForeArm_TEX.cpp"
GLfloat lightPos_marcLeftForeArm[]               =  {3.969, 82.575, 132.685};
GLfloat lightAttenuation_marcLeftForeArm         =   1.283;

GLfloat rotation_AXIS_marcLeftForeArm[]          =  {1.0, 1.0, 1.0};
GLfloat marcLeftForeArm_POSITION[]               =  {0.0, 0.0, 0.0};
GLfloat     marcLeftForeArm_counter              = 0;
GLuint      UNIFORM_counter_marcLeftForeArm;

GLfloat     LightAmbient_marcLeftForeArm[]       = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     LightDiffuse_marcLeftForeArm[]       = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     LightSpecular_marcLeftForeArm[]      = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialAmbient_marcLeftForeArm[]    = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialDiffuse_marcLeftForeArm[]    = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialEmission_marcLeftForeArm[]   = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialSpecular_marcLeftForeArm[]   = { 0.0, 0, 0};
GLfloat     MaterialShininess_marcLeftForeArm   =  10.000;
GLfloat     scalemarcLeftForeArmShadowY[]            = {1.26801, 0.0, 1.26801};
