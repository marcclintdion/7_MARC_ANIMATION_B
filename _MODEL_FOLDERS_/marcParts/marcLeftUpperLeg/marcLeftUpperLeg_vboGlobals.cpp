GLuint marcLeftUpperLeg_vboID   =  209 ;

GLuint marcLeftUpperLeg_SHADER;
GLuint marcLeftUpperLeg_SHADER_Vertex;
GLuint marcLeftUpperLeg_SHADER_Fragment;

#include "marcLeftUpperLeg_VERT.cpp"
#include "marcLeftUpperLeg_NORM.cpp"
#include "marcLeftUpperLeg_TEX.cpp"
GLfloat lightPos_marcLeftUpperLeg[]               =  {3.969, 82.575, 132.685};
GLfloat lightAttenuation_marcLeftUpperLeg         =   1.283;

GLfloat rotation_AXIS_marcLeftUpperLeg[]          =  {1.0, 1.0, 1.0};
GLfloat marcLeftUpperLeg_POSITION[]               =  {0.0, 0.0, 0.0};
GLfloat     marcLeftUpperLeg_counter              = 0;
GLuint      UNIFORM_counter_marcLeftUpperLeg;

GLfloat     LightAmbient_marcLeftUpperLeg[]       = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     LightDiffuse_marcLeftUpperLeg[]       = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     LightSpecular_marcLeftUpperLeg[]      = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialAmbient_marcLeftUpperLeg[]    = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialDiffuse_marcLeftUpperLeg[]    = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialEmission_marcLeftUpperLeg[]   = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialSpecular_marcLeftUpperLeg[]   = { 0.0, 0, 0};
GLfloat     MaterialShininess_marcLeftUpperLeg   =  10.000;
GLfloat     scalemarcLeftUpperLegShadowY[]            = {1.26801, 0.0, 1.26801};
