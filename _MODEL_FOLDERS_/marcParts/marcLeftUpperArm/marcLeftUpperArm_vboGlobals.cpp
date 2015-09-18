GLuint marcLeftUpperArm_vboID   =  213 ;

GLuint marcLeftUpperArm_SHADER;
GLuint marcLeftUpperArm_SHADER_Vertex;
GLuint marcLeftUpperArm_SHADER_Fragment;

#include "marcLeftUpperArm_VERT.cpp"
#include "marcLeftUpperArm_NORM.cpp"
#include "marcLeftUpperArm_TEX.cpp"
GLfloat lightPos_marcLeftUpperArm[]               =  {3.969, 82.575, 132.685};
GLfloat lightAttenuation_marcLeftUpperArm         =   1.283;

GLfloat rotation_AXIS_marcLeftUpperArm[]          =  {1.0, 1.0, 1.0};
GLfloat marcLeftUpperArm_POSITION[]               =  {0.0, 0.0, 0.0};
GLfloat     marcLeftUpperArm_counter              = 0;
GLuint      UNIFORM_counter_marcLeftUpperArm;

GLfloat     LightAmbient_marcLeftUpperArm[]       = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     LightDiffuse_marcLeftUpperArm[]       = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     LightSpecular_marcLeftUpperArm[]      = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialAmbient_marcLeftUpperArm[]    = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialDiffuse_marcLeftUpperArm[]    = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialEmission_marcLeftUpperArm[]   = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialSpecular_marcLeftUpperArm[]   = { 0.0, 0, 0};
GLfloat     MaterialShininess_marcLeftUpperArm   =  10.000;
GLfloat     scalemarcLeftUpperArmShadowY[]            = {1.26801, 0.0, 1.26801};
