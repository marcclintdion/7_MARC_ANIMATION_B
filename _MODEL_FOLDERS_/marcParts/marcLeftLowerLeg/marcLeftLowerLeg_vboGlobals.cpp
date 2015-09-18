GLuint marcLeftLowerLeg_vboID   =  210 ;

GLuint marcLeftLowerLeg_SHADER;
GLuint marcLeftLowerLeg_SHADER_Vertex;
GLuint marcLeftLowerLeg_SHADER_Fragment;

#include "marcLeftLowerLeg_VERT.cpp"
#include "marcLeftLowerLeg_NORM.cpp"
#include "marcLeftLowerLeg_TEX.cpp"
GLfloat lightPos_marcLeftLowerLeg[]               =  {3.969, 82.575, 132.685};
GLfloat lightAttenuation_marcLeftLowerLeg         =   1.283;

GLfloat rotation_AXIS_marcLeftLowerLeg[]          =  {1.0, 1.0, 1.0};
GLfloat marcLeftLowerLeg_POSITION[]               =  {0.0, 0.0, 0.0};
GLfloat     marcLeftLowerLeg_counter              = 0;
GLuint      UNIFORM_counter_marcLeftLowerLeg;

GLfloat     LightAmbient_marcLeftLowerLeg[]       = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     LightDiffuse_marcLeftLowerLeg[]       = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     LightSpecular_marcLeftLowerLeg[]      = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialAmbient_marcLeftLowerLeg[]    = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialDiffuse_marcLeftLowerLeg[]    = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialEmission_marcLeftLowerLeg[]   = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialSpecular_marcLeftLowerLeg[]   = { 0.0, 0, 0};
GLfloat     MaterialShininess_marcLeftLowerLeg   =  10.000;
GLfloat     scalemarcLeftLowerLegShadowY[]            = {1.26801, 0.0, 1.26801};
