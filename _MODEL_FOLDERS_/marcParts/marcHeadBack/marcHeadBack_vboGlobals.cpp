GLuint marcHeadBack_vboID   =  200 ;

GLuint marcHeadBack_SHADER;
GLuint marcHeadBack_SHADER_Vertex;
GLuint marcHeadBack_SHADER_Fragment;

#include "marcHeadBack_VERT.cpp"
#include "marcHeadBack_NORM.cpp"
#include "marcHeadBack_TEX.cpp"
GLfloat     lightPos_marcHeadBack[]               = {12.913, 100, -149.049};
GLfloat     lightAttenuation_marcHeadBack         =   4.0005e-005;


GLfloat     marcHeadBack_counter              =   0;
GLuint      UNIFORM_counter_marcHeadBack;

GLfloat     LightAmbient_marcHeadBack[]       = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     LightDiffuse_marcHeadBack[]       = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     LightSpecular_marcHeadBack[]      = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialAmbient_marcHeadBack[]    = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialDiffuse_marcHeadBack[]    = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialEmission_marcHeadBack[]   = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialSpecular_marcHeadBack[]   = { 0.0, 0, 0};
GLfloat     MaterialShininess_marcHeadBack   =  10.000;
GLfloat     scalemarcHeadBackShadowY[]            = {1.26801, 0.0, 1.26801};
