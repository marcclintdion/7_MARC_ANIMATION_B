                             GLhandleARB marcWood;
                             GLhandleARB marcWood_Vertex;
                             GLhandleARB marcWood_Fragment;
                                                            
                           
                                                            
                             GLuint      marcTextures[100];
                             GLuint      marcNormals[100];

                   GLfloat face_Marc_DOT3_light[] =  {-13.5501, 100, 704.795};
                   GLfloat quadraticAttenuationFace_Marc_DOT3 =   2.60903;
                   
                   
   float torso_light[] = {12.913, 100, -149.049};
   float quadraticAttenuationtorso =  4.0005e-005;

   float hips_light[] = {12.913, 100, -149.049};
   GLfloat quadraticAttenuationhips =   1.17003;
   
   GLint   uniformLightPosition;   
   GLint   uniformLightAttenuation;
   GLfloat nMapLightPosition[]     = {12.913, 100, -149.049};
   GLfloat nMapLightAttenuation  = 3.5005e-005;

   

   float leftUpperArm_light[] = {12.913, 100, -149.049};
   float quadraticAttenuationleftUpperArm = 4.0005e-005;

         float leftForeArm_light[] = {12.913, 100, -149.049};
         float quadraticAttenuationleftForeArm  = 4.0005e-005;

               float leftHand_light[] = {12.913, 100, -149.049};
               float quadraticAttenuationleftHand = 4.0005e-005;

   
   float rightUpperArm_light[] = {12.913, 100, -149.049};
   float quadraticAttenuationrightUpperArm = 4.0005e-005;

         float rightForeArm_light[] = {12.913, 100, -149.049};
         float quadraticAttenuationrightForeArm = 4.0005e-005;

               float rightHand_light[]= {12.913, 100, -149.049};
               float quadraticAttenuationrightHand = 4.0005e-005; 
   
   float leftUpperLeg_light[] = {12.913, 100, -149.049};
   float quadraticAttenuationleftUpperLeg = 4.0005e-005;

         float leftForeLeg_light[] = {12.913, 100, -149.049};
         float quadraticAttenuationleftLowerLeg = 4.0005e-005;

               float leftBoot_light[] = {12.913, 100, -149.049};
               float quadraticAttenuationleftBoot = 4.0005e-005;
               

   float rightUpperLeg_light[] = {12.913, 100, -149.049};
   float quadraticAttenuationrightUpperLeg = 4.0005e-005;

         float rightForeLeg_light[] = {12.913, 100, -149.049};
         float quadraticAttenuationrightLowerLeg = 4.0005e-005;

               float rightBoot_light[] = {12.913, 100, -149.049};
               float quadraticAttenuationrightBoot = 4.0005e-005;

                                                            
                             //---------------------------------------------------------                             
                             
                             GLfloat lightPos_marcTorso[]               = {12.913, 100, -149.049};
                             GLfloat lightAttenuation_marcTorso         = 1.17004;                             
                             
                             #include "marcHeadBack/marcHeadBack_vboGlobals.cpp"        
                             #include "marcFace/marcFace_vboGlobals.cpp"        
                             #include "marcTorso/marcTorso_vboGlobals.cpp"        
                             #include "marcHips/marcHips_vboGlobals.cpp"        
                             #include "marcRightUpperLeg/marcRightUpperLeg_vboGlobals.cpp"        
                             #include "marcRightLowerLeg/marcRightLowerLeg_vboGlobals.cpp"        
                             #include "marcRightUpperArm/marcRightUpperArm_vboGlobals.cpp"        
                             #include "marcRightForeArm/marcRightForeArm_vboGlobals.cpp"        
                             #include "marcRightHand/marcRightHand_vboGlobals.cpp"        
                             #include "marcLeftUpperArm/marcLeftUpperArm_vboGlobals.cpp"                              
                             #include "marcLeftForeArm/marcLeftForeArm_vboGlobals.cpp"                              
                             #include "marcLeftHand/marcLeftHand_vboGlobals.cpp"                              
                             #include "marcRightBoot/marcRightBoot_vboGlobals.cpp" 
                             #include "marcLeftUpperLeg/marcLeftUpperLeg_vboGlobals.cpp" 
                             #include "marcLeftLowerLeg/marcLeftLowerLeg_vboGlobals.cpp" 
                             #include "marcLeftBoot/marcLeftBoot_vboGlobals.cpp" 
