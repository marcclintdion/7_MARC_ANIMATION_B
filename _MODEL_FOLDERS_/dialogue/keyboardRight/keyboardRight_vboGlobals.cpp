                             GLuint keyboardRight_vboID   =  601 ;

                             GLuint keyboardRight_SHADER;
                             GLuint keyboardRight_SHADER_Vertex;
                             GLuint keyboardRight_SHADER_Fragment;
                             #include "keyboardRight_VERT.cpp"
                             #include "keyboardRight_NORM.cpp"
                             #include "keyboardRight_TEX.cpp"
                             GLfloat     keyboardRight_POSITION[]              =  {0.0, 0.0, 0.0};
                             GLfloat     keyboardRight_ROTATION[]         =  {0.0, 1.0, 0.0, 0.0};
                             GLfloat     lightPos_keyboardRight[]              =  {-1.56117, 11.9431,  10.7077};
                             GLfloat     lightAttenuation_keyboardRight        =   1.283;
                             GLfloat     shininess_keyboardRight               = 199.733f;
                             GLuint      UNIFORM_shininess_keyboardRight;
                             //---------
                             GLfloat    keyboardRight_ShadowsPosition_01[]            =  {-0.475997, -0.632993, -7.48398};
                             GLfloat    keyboardRight_ShadowsRotationUP_DOWN_01       =   36.2;
                             GLfloat    keyboardRight_ShadowsRotationLEFT_RIGHT_01    =   40.94;
                             GLfloat    scale_keyboardRight_Shadow_01                 =    0.45;   
                             //---------
                             GLfloat    keyboardRight_ShadowsPosition_00[]            =  {-0.182f, -0.453992f, -6.58204f};
                             GLfloat    keyboardRight_ShadowsRotationUP_DOWN_00       =   36.2;
                             GLfloat    keyboardRight_ShadowsRotationLEFT_RIGHT_00    =   -7.00001;
                             GLfloat    scale_keyboardRight_Shadow_00                 =    0.416;   
                             //--------------------------------------------------------------------------------------
                             GLfloat     keyboardRight_counter1             =   0.0;
                             GLfloat     keyboardRight_counter2             =   0.0;
                             GLfloat     keyboardRight_counter3             =   0.0;
                             GLfloat     keyboardRight_counter4             =   0.0;
                             GLuint      UNIFORM_counter1_keyboardRight;

                             GLuint      UNIFORM_counter2_keyboardRight;

                             GLuint      UNIFORM_counter3_keyboardRight;

                             GLuint      UNIFORM_counter4_keyboardRight;

                             GLfloat     LightAmbient_keyboardRight[]        = { 1.0f, 1.0f, 1.0f, 1.0f};
                             GLfloat     LightDiffuse_keyboardRight[]        = { 1.0f, 1.0f, 1.0f, 1.0f};
                             GLfloat     LightSpecular_keyboardRight[]       = { 1.0f, 1.0f, 1.0f, 1.0f};
                             GLfloat     MaterialAmbient_keyboardRight[]     = { 1.0f, 1.0f, 1.0f, 1.0f};
                             GLfloat     MaterialDiffuse_keyboardRight[]     = { 1.0f, 1.0f, 1.0f, 1.0f};
                             GLfloat     MaterialEmission_keyboardRight[]    = { 1.0f, 1.0f, 1.0f, 1.0f};
                             GLfloat     MaterialSpecular_keyboardRight[]    = { 0.0, 0, 0};
                             GLfloat     scalekeyboardRightShadowY[]         = {1.26801, 0.0, 1.26801};
