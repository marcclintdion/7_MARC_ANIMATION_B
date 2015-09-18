GLuint marcTorso_vboID   =  202 ;

GLuint marcTorso_SHADER;
GLuint marcTorso_SHADER_Vertex;
GLuint marcTorso_SHADER_Fragment;

#include "marcTorso_VERT.cpp"
#include "marcTorso_NORM.cpp"
#include "marcTorso_TEX.cpp"



GLfloat     marcTorso_counter              = 0;

GLuint      UNIFORM_counter_marcTorso;
GLuint      UNIFORM_bodyPartSelection;




GLfloat     scalemarcTorsoShadowY[]            = {1.26801, 0.0, 1.26801};
