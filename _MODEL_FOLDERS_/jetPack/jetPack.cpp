
                             GLfloat jetPackPosition[]                                   =   {0.0,       0.0,      0.0};
                            
                             GLuint      jetPackTextures[10];
                             GLuint      jetPackNormals[10];
                             GLuint      jetPackSpecular[10];

                             GLhandleARB jetPackRockets;
                             GLhandleARB jetPackRockets_Vertex;
                             GLhandleARB jetPackRockets_Fragment;

                             GLhandleARB jetPackBindingShader;
                             GLhandleARB jetPackBindings_Vertex;
                             GLhandleARB jetPackBindings_Fragment;

                             GLhandleARB jetPackStrapsShader;
                             GLhandleARB jetPackStrapsShader_Vertex;
                             GLhandleARB jetPackStrapsShader_Fragment;

                             GLhandleARB JetPack_ExhaustPlumes_SHADER;
                             GLhandleARB JetPack_ExhaustPlumes_SHADERVertex;
                             GLhandleARB JetPack_ExhaustPlumes_SHADERFragment;  
                             GLhandleARB JetPack_ExhaustPlumes_outer_SHADER;
                             GLhandleARB JetPack_ExhaustPlumes_outer_SHADERVertex;
                             GLhandleARB JetPack_ExhaustPlumes_outer_SHADERFragment; 
            
                             GLhandleARB jetPackSideHandles_SHADER;
                             GLhandleARB jetPackSideHandles_SHADER_Vertex;
                             GLhandleARB jetPackSideHandles_SHADER_Fragment;                              
                            
                             #include "jetPackVestStraps/jetPackVestStraps_vboGlobals.cpp" 
                             #include "jetPacksideHandles/jetPacksideHandles_vboGlobals.cpp" 
                             #include "jetPackBindings/jetPackBindings_vboGlobals.cpp" 
                             #include "jetPackTopCones/jetPackTopCones_vboGlobals.cpp" 
                             #include "jetPackMiddleEngines/jetPackMiddleEngines_vboGlobals.cpp" 
                             #include "jetPackNozzels/jetPackNozzels_vboGlobals.cpp" 
