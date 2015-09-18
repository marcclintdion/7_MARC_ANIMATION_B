GLuint marcRightForeArm_vboID   =  207 ;

GLuint marcRightForeArm_SHADER;
GLuint marcRightForeArm_SHADER_Vertex;
GLuint marcRightForeArm_SHADER_Fragment;

#include "marcRightForeArm_VERT.cpp"
#include "marcRightForeArm_NORM.cpp"
#include "marcRightForeArm_TEX.cpp"
GLfloat lightPos_marcRightForeArm[]               =  {3.969, 82.575, 132.685};
GLfloat lightAttenuation_marcRightForeArm         =   1.283;

GLfloat rotation_AXIS_marcRightForeArm[]          =  {1.0, 1.0, 1.0};
GLfloat marcRightForeArm_POSITION[]               =  {0.0, 0.0, 0.0};
GLfloat     marcRightForeArm_counter              = 0;
GLuint      UNIFORM_counter_marcRightForeArm;

GLfloat     LightAmbient_marcRightForeArm[]       = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     LightDiffuse_marcRightForeArm[]       = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     LightSpecular_marcRightForeArm[]      = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialAmbient_marcRightForeArm[]    = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialDiffuse_marcRightForeArm[]    = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialEmission_marcRightForeArm[]   = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialSpecular_marcRightForeArm[]   = { 0.0, 0, 0};
GLfloat     MaterialShininess_marcRightForeArm   =  10.000;
GLfloat     scalemarcRightForeArmShadowY[]            = {1.26801, 0.0, 1.26801};
