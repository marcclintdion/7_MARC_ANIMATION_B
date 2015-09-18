                             GLuint F1_F8_vboID   =  573 ;                                        

                             GLuint F1_F8_SHADER;                                                            
                             GLuint F1_F8_SHADER_Vertex;                                                     
                             GLuint F1_F8_SHADER_Fragment;                                                   

                             #include "F1_F8_VERT.cpp"                                                     
                             #include "F1_F8_NORM.cpp"                                                     
                             #include "F1_F8_TEX.cpp"                                                      
                             GLfloat     F1_F8_POSITION[]              =  {0.0, 0.0, 0.0};                   

                             GLfloat     rotation_AXIS_F1_F8[]         =  {0.0, 1.0, 0.0, 0.0};              

                             GLfloat     lightPos_F1_F8[]              =  {-1.56117, 11.9431,  10.7077};     
                             GLfloat     lightAttenuation_F1_F8        =   1.283;                            

                             GLfloat     shininess_F1_F8               = 199.733f;                           

                             GLuint      UNIFORM_shininess_F1_F8;                                            
                             //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++      

                             //----------------------------------------------------------------------------- 

                             GLfloat    F1_F8_ShadowsPosition_01[]            =  { 0.0, 0.0,0.0};            
                             GLfloat    F1_F8_ShadowsRotationUP_DOWN_01       =   36.2f;                     
                             GLfloat    F1_F8_ShadowsRotationLEFT_RIGHT_01    =   -7.00001f;                 
                             GLfloat    scale_F1_F8_Shadow_01                 =    2.0f;                     

                             //----------------------------------------------------------------------------- 

                             GLfloat    F1_F8_ShadowsPosition_00[]            =  { 0.0, 0.0,0.0};            
                             GLfloat    F1_F8_ShadowsRotationUP_DOWN_00       =   36.2f;                     
                             GLfloat    F1_F8_ShadowsRotationLEFT_RIGHT_00    =   -7.00001f;                 
                             GLfloat    scale_F1_F8_Shadow_00                 =    2.0f;                     

                             //----------------------------------------------------------------------------- 

                             GLfloat     F1_F8_counter1             =   0.0;                                  
                             GLfloat     F1_F8_counter2             =   0.0;                                  
                             GLfloat     F1_F8_counter3             =   0.0;                                  
                             GLfloat     F1_F8_counter4             =   0.0;                                  
                             GLuint      UNIFORM_counter1_F1_F8;                                              

                             GLuint      UNIFORM_counter2_F1_F8;                                              

                             GLuint      UNIFORM_counter3_F1_F8;                                              

                             GLuint      UNIFORM_counter4_F1_F8;                                              

                             GLfloat     LightAmbient_F1_F8[]        = { 1.0f, 1.0f, 1.0f, 1.0f};             
                             GLfloat     LightDiffuse_F1_F8[]        = { 1.0f, 1.0f, 1.0f, 1.0f};             
                             GLfloat     LightSpecular_F1_F8[]       = { 1.0f, 1.0f, 1.0f, 1.0f};             
                             GLfloat     MaterialAmbient_F1_F8[]     = { 1.0f, 1.0f, 1.0f, 1.0f};             
                             GLfloat     MaterialDiffuse_F1_F8[]     = { 1.0f, 1.0f, 1.0f, 1.0f};             
                             GLfloat     MaterialEmission_F1_F8[]    = { 1.0f, 1.0f, 1.0f, 1.0f};             
                             GLfloat     MaterialSpecular_F1_F8[]    = { 0.0, 0, 0};                          
                             GLfloat     scaleF1_F8ShadowY[]         = {1.26801, 0.0, 1.26801};               
