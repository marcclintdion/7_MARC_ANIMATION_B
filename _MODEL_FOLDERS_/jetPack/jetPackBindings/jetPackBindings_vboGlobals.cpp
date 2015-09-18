GLuint jetPackBindings_vboID   =  221 ;

GLuint jetPackBindings_SHADER;
GLuint jetPackBindings_SHADER_Vertex;
GLuint jetPackBindings_SHADER_Fragment;

#include "jetPackBindings_VERT.cpp"
#include "jetPackBindings_NORM.cpp"
#include "jetPackBindings_TEX.cpp"
GLfloat lightPos_jetPackBindings[]               =  {3.969, 82.575, 132.685};
GLfloat lightAttenuation_jetPackBindings         =   1.283;

GLfloat rotation_AXIS_jetPackBindings[]          =  {1.0, 1.0, 1.0};
GLfloat jetPackBindings_POSITION[]               =  {0.0, 0.0, 0.0};
GLfloat     jetPackBindings_counter              = 0;
GLuint      UNIFORM_counter_jetPackBindings;

GLfloat     LightAmbient_jetPackBindings[]       = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     LightDiffuse_jetPackBindings[]       = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     LightSpecular_jetPackBindings[]      = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialAmbient_jetPackBindings[]    = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialDiffuse_jetPackBindings[]    = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialEmission_jetPackBindings[]   = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialSpecular_jetPackBindings[]   = { 0.0, 0, 0};
GLfloat     MaterialShininess_jetPackBindings   =  10.000;
GLfloat     scalejetPackBindingsShadowY[]            = {1.26801, 0.0, 1.26801};
