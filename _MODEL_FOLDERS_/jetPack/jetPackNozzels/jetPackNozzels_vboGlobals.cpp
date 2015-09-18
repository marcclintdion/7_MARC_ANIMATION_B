GLuint jetPackNozzels_vboID   =  223 ;

GLuint jetPackNozzels_SHADER;
GLuint jetPackNozzels_SHADER_Vertex;
GLuint jetPackNozzels_SHADER_Fragment;

#include "jetPackNozzels_VERT.cpp"
#include "jetPackNozzels_NORM.cpp"
#include "jetPackNozzels_TEX.cpp"
GLfloat lightPos_jetPackNozzels[]               =  {3.969, 82.575, 132.685};
GLfloat lightAttenuation_jetPackNozzels         =   1.283;

GLfloat rotation_AXIS_jetPackNozzels[]          =  {1.0, 1.0, 1.0};
GLfloat jetPackNozzels_POSITION[]               =  {0.0, 0.0, 0.0};
GLfloat     jetPackNozzels_counter              = 0;
GLuint      UNIFORM_counter_jetPackNozzels;

GLfloat     LightAmbient_jetPackNozzels[]       = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     LightDiffuse_jetPackNozzels[]       = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     LightSpecular_jetPackNozzels[]      = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialAmbient_jetPackNozzels[]    = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialDiffuse_jetPackNozzels[]    = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialEmission_jetPackNozzels[]   = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialSpecular_jetPackNozzels[]   = { 0.0, 0, 0};
GLfloat     MaterialShininess_jetPackNozzels   =  10.000;
GLfloat     scalejetPackNozzelsShadowY[]            = {1.26801, 0.0, 1.26801};
