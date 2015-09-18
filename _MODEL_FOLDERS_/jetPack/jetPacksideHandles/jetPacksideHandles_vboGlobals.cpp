GLuint jetPacksideHandles_vboID   =  222 ;

GLuint jetPacksideHandles_SHADER;
GLuint jetPacksideHandles_SHADER_Vertex;
GLuint jetPacksideHandles_SHADER_Fragment;

#include "jetPacksideHandles_VERT.cpp"
#include "jetPacksideHandles_NORM.cpp"
#include "jetPacksideHandles_TEX.cpp"
GLfloat lightPos_jetPacksideHandles[]               =  {3.969, 82.575, 132.685};
GLfloat lightAttenuation_jetPacksideHandles         =   1.283;

GLfloat rotation_AXIS_jetPacksideHandles[]          =  {1.0, 1.0, 1.0};
GLfloat jetPacksideHandles_POSITION[]               =  {0.0, 0.0, 0.0};
GLfloat     jetPacksideHandles_counter              = 0;
GLuint      UNIFORM_counter_jetPacksideHandles;

GLfloat     LightAmbient_jetPacksideHandles[]       = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     LightDiffuse_jetPacksideHandles[]       = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     LightSpecular_jetPacksideHandles[]      = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialAmbient_jetPacksideHandles[]    = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialDiffuse_jetPacksideHandles[]    = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialEmission_jetPacksideHandles[]   = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialSpecular_jetPacksideHandles[]   = { 0.0, 0, 0};
GLfloat     MaterialShininess_jetPacksideHandles   =  10.000;
GLfloat     scalejetPacksideHandlesShadowY[]            = {1.26801, 0.0, 1.26801};
