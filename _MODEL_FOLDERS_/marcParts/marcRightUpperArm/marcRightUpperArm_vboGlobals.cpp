GLuint marcRightUpperArm_vboID   =  206 ;

GLuint marcRightUpperArm_SHADER;
GLuint marcRightUpperArm_SHADER_Vertex;
GLuint marcRightUpperArm_SHADER_Fragment;

#include "marcRightUpperArm_VERT.cpp"
#include "marcRightUpperArm_NORM.cpp"
#include "marcRightUpperArm_TEX.cpp"
GLfloat lightPos_marcRightUpperArm[]               =  {3.969, 82.575, 132.685};
GLfloat lightAttenuation_marcRightUpperArm         =   1.283;



GLfloat     LightAmbient_marcRightUpperArm[]       = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     LightDiffuse_marcRightUpperArm[]       = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     LightSpecular_marcRightUpperArm[]      = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialAmbient_marcRightUpperArm[]    = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialDiffuse_marcRightUpperArm[]    = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialEmission_marcRightUpperArm[]   = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialSpecular_marcRightUpperArm[]   = { 0.0, 0, 0};
GLfloat     MaterialShininess_marcRightUpperArm   =  10.000;
GLfloat     scalemarcRightUpperArmShadowY[]            = {1.26801, 0.0, 1.26801};
