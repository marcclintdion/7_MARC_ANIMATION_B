GLuint marcHips_vboID   =  203 ;

GLuint marcHips_SHADER;
GLuint marcHips_SHADER_Vertex;
GLuint marcHips_SHADER_Fragment;

#include "marcHips_VERT.cpp"
#include "marcHips_NORM.cpp"
#include "marcHips_TEX.cpp"
GLfloat lightPos_marcHips[]               =  {3.969, 82.575, 132.685};
GLfloat lightAttenuation_marcHips         =   1.283;


GLfloat     marcHips_counter              = 0;
GLuint      UNIFORM_counter_marcHips;

GLfloat     LightAmbient_marcHips[]       = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     LightDiffuse_marcHips[]       = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     LightSpecular_marcHips[]      = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialAmbient_marcHips[]    = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialDiffuse_marcHips[]    = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialEmission_marcHips[]   = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialSpecular_marcHips[]   = { 0.0, 0, 0};
GLfloat     MaterialShininess_marcHips   =  10.000;
GLfloat     scalemarcHipsShadowY[]            = {1.26801, 0.0, 1.26801};
