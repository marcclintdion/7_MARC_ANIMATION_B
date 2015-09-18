GLuint marcLeftHand_vboID   =  215 ;

GLuint marcLeftHand_SHADER;
GLuint marcLeftHand_SHADER_Vertex;
GLuint marcLeftHand_SHADER_Fragment;

#include "marcLeftHand_VERT.cpp"
#include "marcLeftHand_NORM.cpp"
#include "marcLeftHand_TEX.cpp"
GLfloat lightPos_marcLeftHand[]               =  {3.969, 82.575, 132.685};
GLfloat lightAttenuation_marcLeftHand         =   1.283;

GLfloat rotation_AXIS_marcLeftHand[]          =  {1.0, 1.0, 1.0};
GLfloat marcLeftHand_POSITION[]               =  {0.0, 0.0, 0.0};
GLfloat     marcLeftHand_counter              = 0;
GLuint      UNIFORM_counter_marcLeftHand;

GLfloat     LightAmbient_marcLeftHand[]       = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     LightDiffuse_marcLeftHand[]       = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     LightSpecular_marcLeftHand[]      = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialAmbient_marcLeftHand[]    = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialDiffuse_marcLeftHand[]    = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialEmission_marcLeftHand[]   = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialSpecular_marcLeftHand[]   = { 0.0, 0, 0};
GLfloat     MaterialShininess_marcLeftHand   =  10.000;
GLfloat     scalemarcLeftHandShadowY[]            = {1.26801, 0.0, 1.26801};
