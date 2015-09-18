GLuint marcLeftBoot_vboID   =  211 ;

GLuint marcLeftBoot_SHADER;
GLuint marcLeftBoot_SHADER_Vertex;
GLuint marcLeftBoot_SHADER_Fragment;

#include "marcLeftBoot_VERT.cpp"
#include "marcLeftBoot_NORM.cpp"
#include "marcLeftBoot_TEX.cpp"
GLfloat lightPos_marcLeftBoot[]               =  {3.969, 82.575, 132.685};
GLfloat lightAttenuation_marcLeftBoot         =   1.283;

GLfloat rotation_AXIS_marcLeftBoot[]          =  {1.0, 1.0, 1.0};
GLfloat marcLeftBoot_POSITION[]               =  {0.0, 0.0, 0.0};
GLfloat     marcLeftBoot_counter              = 0;
GLuint      UNIFORM_counter_marcLeftBoot;

GLfloat     LightAmbient_marcLeftBoot[]       = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     LightDiffuse_marcLeftBoot[]       = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     LightSpecular_marcLeftBoot[]      = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialAmbient_marcLeftBoot[]    = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialDiffuse_marcLeftBoot[]    = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialEmission_marcLeftBoot[]   = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialSpecular_marcLeftBoot[]   = { 0.0, 0, 0};
GLfloat     MaterialShininess_marcLeftBoot   =  10.000;
GLfloat     scalemarcLeftBootShadowY[]            = {1.26801, 0.0, 1.26801};
