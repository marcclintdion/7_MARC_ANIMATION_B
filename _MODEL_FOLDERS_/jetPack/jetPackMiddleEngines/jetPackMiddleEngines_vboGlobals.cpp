GLuint jetPackMiddleEngines_vboID   =  224 ;

GLuint jetPackMiddleEngines_SHADER;
GLuint jetPackMiddleEngines_SHADER_Vertex;
GLuint jetPackMiddleEngines_SHADER_Fragment;

#include "jetPackMiddleEngines_VERT.cpp"
#include "jetPackMiddleEngines_NORM.cpp"
#include "jetPackMiddleEngines_TEX.cpp"
GLfloat lightPos_jetPackMiddleEngines[]               =  {3.969, 82.575, 132.685};
GLfloat lightAttenuation_jetPackMiddleEngines         =   1.283;

GLfloat rotation_AXIS_jetPackMiddleEngines[]          =  {1.0, 1.0, 1.0};
GLfloat jetPackMiddleEngines_POSITION[]               =  {0.0, 0.0, 0.0};
GLfloat     jetPackMiddleEngines_counter              = 0;
GLuint      UNIFORM_counter_jetPackMiddleEngines;

GLfloat     LightAmbient_jetPackMiddleEngines[]       = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     LightDiffuse_jetPackMiddleEngines[]       = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     LightSpecular_jetPackMiddleEngines[]      = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialAmbient_jetPackMiddleEngines[]    = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialDiffuse_jetPackMiddleEngines[]    = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialEmission_jetPackMiddleEngines[]   = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialSpecular_jetPackMiddleEngines[]   = { 0.0, 0, 0};
GLfloat     MaterialShininess_jetPackMiddleEngines   =  10.000;
GLfloat     scalejetPackMiddleEnginesShadowY[]            = {1.26801, 0.0, 1.26801};
