GLuint jetPackVestStraps_vboID   =  220 ;

GLuint jetPackVestStraps_SHADER;
GLuint jetPackVestStraps_SHADER_Vertex;
GLuint jetPackVestStraps_SHADER_Fragment;

#include "jetPackVestStraps_VERT.cpp"
#include "jetPackVestStraps_NORM.cpp"
#include "jetPackVestStraps_TEX.cpp"
GLfloat lightPos_jetPackVestStraps[]               =  {3.969, 82.575, 132.685};
GLfloat lightAttenuation_jetPackVestStraps         =   1.283;

GLfloat rotation_AXIS_jetPackVestStraps[]          =  {1.0, 1.0, 1.0};
GLfloat jetPackVestStraps_POSITION[]               =  {0.0, 0.0, 0.0};
GLfloat     jetPackVestStraps_counter              = 0;
GLuint      UNIFORM_counter_jetPackVestStraps;

GLfloat     LightAmbient_jetPackVestStraps[]       = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     LightDiffuse_jetPackVestStraps[]       = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     LightSpecular_jetPackVestStraps[]      = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialAmbient_jetPackVestStraps[]    = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialDiffuse_jetPackVestStraps[]    = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialEmission_jetPackVestStraps[]   = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialSpecular_jetPackVestStraps[]   = { 0.0, 0, 0};
GLfloat     MaterialShininess_jetPackVestStraps   =  10.000;
GLfloat     scalejetPackVestStrapsShadowY[]            = {1.26801, 0.0, 1.26801};
