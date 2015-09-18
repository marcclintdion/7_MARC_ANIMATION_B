glPushMatrix();  
   glTranslatef(marcModelPosition[0], marcModelPosition[1], marcModelPosition[2]);
   glRotatef(marcRotation, 0.0, 1.0, 0.0);            
  
        glTranslatef(hips_POSITION[0],     hips_POSITION[1],     hips_POSITION[2]);
        glRotatef(   hips_ROTATE[3], hips_ROTATE[0], hips_ROTATE[1], hips_ROTATE[2]);   

                         
                            glPushMatrix();
                                 glLoadIdentity();
                                 glRotatef(-hips_ROTATE[3], -hips_ROTATE[0], -hips_ROTATE[1], hips_ROTATE[2]);                                  
                                 glRotatef(marcRotation, 0.0, 1.0, 0.0); 
                                 glRotatef(-look_LEFT_RIGHT, 0.0, -1.0, 0.0);
                                 glTranslatef(-eyePosition[0],-eyePosition[1],-eyePosition[2]);
                                 glLightfv(GL_LIGHT0,GL_POSITION,lightPos_marcTorso);
                                 glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_marcTorso);
                            glPopMatrix();
                            //-------------------------------------------------------------------------------------------
                            if(BODY_PART_SELECTION == 5)
                            { 
                                   MaterialDiffuse_marcTorso[0] =1.0;
                                   rotationInfoTransparency     = 1.0;
                            }
                            else                 
                            {
                                   MaterialDiffuse_marcTorso[0] = 1.0;
                                   rotationInfoTransparency     = 0.2;
                            
                            }                
                            //-------------------------------------------------------------------------------------------
                            
                            
                            #include "_MODEL_FOLDERS_/marcParts/marcHips/marcHips_vboRender.cpp" //_________________________________ALL_WOOD_SHADERS_ARE_LINKED_TO_THE_TORSO_SHADER 
                        
                                              /////--------------------------------___HUD_START___-----------------------------------                       
                                        if(hideSetPlusDialoque == 0.0)   
                                        {//------------------------------------------BEGIN_HIDE_SET_DIALOGUE-------                                              
                                              glPushMatrix(); 
                                                        glTranslatef(hipsRotationDisplayValues[0], hipsRotationDisplayValues[1], hipsRotationDisplayValues[2]); 
                                                        glRotatef(180, 0.0, 1.0, 0.0);
                                                        glDisable(GL_TEXTURE_2D);
                                                        glDisable(GL_CULL_FACE);
                                                        glColor4f(1.0f,1.0f,1.0f,rotationInfoTransparency);
                                                        glScalef(.4,.4,.4);
                                                        glEnable(GL_BLEND);
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, 0.097, 0);
                                                             printDecimalNumbers(hips_ROTATE[3]);
                                                        glPopMatrix(); 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.071+.05, 0);
                                                             printDecimalNumbers(hips_ROTATE[0]);
                                                        glPopMatrix();                                 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.238+.10, 0);
                                                             printDecimalNumbers(hips_ROTATE[1]);
                                                        glPopMatrix();
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.410998+.15, 0);
                                                             printDecimalNumbers(hips_ROTATE[2]);
                                                        glPopMatrix();
                                                        glDisable(GL_BLEND);
                                                        glEnable(GL_CULL_FACE);
                                                        glEnable(GL_TEXTURE_2D);
                                               glPopMatrix();
                                         }//------------------------------------------END_HIDE_SET_DIALOGUE-------      
                                              /////--------------------------------___HUD_START___-----------------------------------     

                 /////////////+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++  
                 /////////////+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++  
                 /////////////+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++  
                 /////////////+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++                           
                             glPushMatrix(); 
                                       glTranslatef(torso_04[0], torso_04[1], torso_04[2]);
                                       glRotatef(torso_ROTATE[3], torso_ROTATE[0], torso_ROTATE[1], torso_ROTATE[2]);  
                            
                                          glPushMatrix();
                                              glLoadIdentity();
                                              //
                                              glRotatef(-torso_ROTATE[3], -torso_ROTATE[0], -torso_ROTATE[1], torso_ROTATE[2]);                                                
                                              glRotatef(-hips_ROTATE[3],  -hips_ROTATE[0],  -hips_ROTATE[1],  hips_ROTATE[2]);                                 
                                              glRotatef( marcRotation, 0, 1, 0); 
                                              glRotatef(-look_LEFT_RIGHT, 0, -1, 0);
                                              glTranslatef(-eyePosition[0],-eyePosition[1],-eyePosition[2]);
                                              glLightfv(GL_LIGHT0,GL_POSITION,lightPos_marcTorso);
                                              glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_marcTorso);
                                         glPopMatrix();          
                                         //-----------------------------------------------------------------------------------
                                               if(BODY_PART_SELECTION == 6)
                                               { 
                                                    MaterialDiffuse_marcTorso[0] =1.0;
                                                    rotationInfoTransparency     = 1.0;
                                               }
                                               else                 
                                               {
                                                    MaterialDiffuse_marcTorso[0] = 1.0;
                                                    rotationInfoTransparency     = 0.2;
                                               }      
                                               #include "_MODEL_FOLDERS_/marcParts/marcTorso/marcTorso_vboRender.cpp"  //_________________________________ALL_WOOD_SHADERS_ARE_LINKED_TO_THE_TORSO_SHADER
                                              /////--------------------------------___HUD_START___-----------------------------------                       
                                              /////--------------------------------___HUD_START___-----------------------------------                       
                                              if(hideSetPlusDialoque == 0.0)   
                                              {//______________________________________________BEGIN_HIDE_SET_DIALOGUE____                                              
                                                   glPushMatrix(); 
                                                        glTranslatef(torsoRotationDisplayValues[0], torsoRotationDisplayValues[1], torsoRotationDisplayValues[2]); 
                                                        glRotatef(180, 0.0, 1.0, 0.0);
                                                        glDisable(GL_TEXTURE_2D);
                                                        glDisable(GL_CULL_FACE);
                                                        glColor4f(1.0f,1.0f,1.0f,rotationInfoTransparency);
                                                        glScalef(.4,.4,.4);
                                                        glEnable(GL_BLEND);
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, 0.097, 0);
                                                             printDecimalNumbers(torso_ROTATE[3]);
                                                        glPopMatrix(); 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.071+.05, 0);
                                                             printDecimalNumbers(torso_ROTATE[0]);
                                                        glPopMatrix();                                 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.238+.10, 0);
                                                             printDecimalNumbers(torso_ROTATE[1]);
                                                        glPopMatrix();
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.410998+.15, 0);
                                                             printDecimalNumbers(torso_ROTATE[2]);
                                                        glPopMatrix();
                                                        glEnable(GL_CULL_FACE);
                                                        glDisable(GL_BLEND);
                                                        glEnable(GL_TEXTURE_2D);
                                                   glPopMatrix();
                                              }
                       /////--------------------------------___HUD_FINISH___-----------------------------------                    
                 
                 /////////////+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++                                              
                 /////////////+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++  
                 /////////////+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++  
                 /////////////+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++                                              
                                            
                                            glPushMatrix();
                                                   glTranslatef(faceMarc_04[0], faceMarc_04[1], faceMarc_04[2]);
                                                   glRotatef(head_ROTATE[3], head_ROTATE[0], head_ROTATE[1], head_ROTATE[2]);         
                                                   glDisable(GL_BLEND);
                                                      
                                                      glPushMatrix();
                                                           glLoadIdentity();
                                                           //
                                                           glRotatef(-head_ROTATE[3],  -head_ROTATE[0],   -head_ROTATE[1],  head_ROTATE[2]);                                                            
                                                           glRotatef(-torso_ROTATE[3], -torso_ROTATE[0],  -torso_ROTATE[1], torso_ROTATE[2]);                                                           
                                                           glRotatef(-hips_ROTATE[3],  -hips_ROTATE[0],   -hips_ROTATE[1],  hips_ROTATE[2]);                                                           
                                                           glRotatef(marcRotation, 0, 1, 0); 
                                                           glRotatef(-look_LEFT_RIGHT, 0, -1, 0);
                                                           glTranslatef(-eyePosition[0],-eyePosition[1],-eyePosition[2]);                                                   
                                                           glLightfv (GL_LIGHT0,GL_POSITION, face_Marc_DOT3_light);
                                                           glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, quadraticAttenuationFace_Marc_DOT3);
                                                      glPopMatrix();                        
                                              
                                                     #include "_MODEL_FOLDERS_/marcParts/marcFace/marcFace_vboRender.cpp"  
                                                                                
                                                       glPushMatrix();
                                                            glLoadIdentity();
                                                            //
                                                            glRotatef(-head_ROTATE[3],  -head_ROTATE[0],  -head_ROTATE[1],  head_ROTATE[2]);                                                             
                                                            glRotatef(-torso_ROTATE[3], -torso_ROTATE[0], -torso_ROTATE[1], torso_ROTATE[2]);                                                            
                                                            glRotatef(-hips_ROTATE[3],  -hips_ROTATE[0],  -hips_ROTATE[1],  hips_ROTATE[2]);                                                            
                                                            glRotatef(marcRotation, 0, 1, 0); 
                                                            glRotatef(-look_LEFT_RIGHT, 0, -1, 0);
                                                            glTranslatef(-eyePosition[0],-eyePosition[1],-eyePosition[2]);                                              
                                                            glLightfv(GL_LIGHT0,GL_POSITION,lightPos_marcTorso);
                                                            glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_marcTorso);
                                                       glPopMatrix();                          
                                               if(BODY_PART_SELECTION == 7)
                                               { 
                                                    MaterialDiffuse_marcTorso[0] =1.0;
                                                    rotationInfoTransparency     = 1.0;
                                               }
                                               else                 
                                               {
                                                    MaterialDiffuse_marcTorso[0] = 1.0;
                                                    rotationInfoTransparency     = 0.2;
                                               }    
                                              /////--------------------------------___HUD_START___-----------------------------------                       
                                              /////--------------------------------___HUD_START___-----------------------------------                       
                                              if(hideSetPlusDialoque == 0.0)   
                                              {//______________________________________________BEGIN_HIDE_SET_DIALOGUE____                                              
                                                    glPushMatrix(); 
                                                        glTranslatef(headRotationDisplayValues[0], headRotationDisplayValues[1], headRotationDisplayValues[2]); 
                                                        glRotatef(180, 0.0, 1.0, 0.0);
                                                        glDisable(GL_TEXTURE_2D);
                                                        glDisable(GL_CULL_FACE);
                                                        glColor4f(1.0f,1.0f,1.0f,rotationInfoTransparency);
                                                        glScalef(.4,.4,.4);
                                                        glEnable(GL_BLEND);
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, 0.097, 0);
                                                             printDecimalNumbers(head_ROTATE[3]);
                                                        glPopMatrix(); 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.071+.05, 0);
                                                             printDecimalNumbers(head_ROTATE[0]);
                                                        glPopMatrix();                                 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.238+.10, 0);
                                                             printDecimalNumbers(head_ROTATE[1]);
                                                        glPopMatrix();
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.410998+.15, 0);
                                                             printDecimalNumbers(head_ROTATE[2]);
                                                        glPopMatrix();
                                                        glEnable(GL_CULL_FACE);
                                                        glDisable(GL_BLEND);
                                                        glEnable(GL_TEXTURE_2D);
                                                    glPopMatrix();
                                               }//______________________________________________END_HIDE_SET_DIALOGUE____  
                                              /////--------------------------------___HUD_FINISH___-----------------------------------                                                        
                                                     #include "_MODEL_FOLDERS_/marcParts/marcHeadBack/marcHeadBack_vboRender.cpp" //_________________________________ALL_WOOD_SHADERS_ARE_LINKED_TO_THE_TORSO_SHADER
                                            
                                            glPopMatrix();
                              glPopMatrix();        
                            
                              
                              
////////////_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO
////////////_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO
////////////_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO_____TORSO
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM
////////////_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM
////////////_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM
glPushMatrix();
      
    glTranslatef(torso_04[0], torso_04[1], torso_04[2]);
    glRotatef(torso_ROTATE[3], torso_ROTATE[0], torso_ROTATE[1], torso_ROTATE[2]);   
        
        glPushMatrix(); 
            glTranslatef(leftUpperArm_POSITION[0], leftUpperArm_POSITION[1], leftUpperArm_POSITION[2]);           
            glRotatef(leftUpperArm_ROTATE[3], leftUpperArm_ROTATE[0], leftUpperArm_ROTATE[1], leftUpperArm_ROTATE[2]);        
                            
                            glPushMatrix();
                                 glLoadIdentity();
                                 glRotatef(-leftUpperArm_ROTATE[3],  -leftUpperArm_ROTATE[0], -leftUpperArm_ROTATE[1], leftUpperArm_ROTATE[2]);                                 
                                 glRotatef(-torso_ROTATE[3],         -torso_ROTATE[0],        -torso_ROTATE[1],        torso_ROTATE[2]);                                 
                                 glRotatef(-hips_ROTATE[3],          -hips_ROTATE[0],         -hips_ROTATE[1],         hips_ROTATE[2]);                                 
                                 glRotatef(marcRotation, 0, 1, 0); 
                                 glRotatef(-look_LEFT_RIGHT, 0, -1, 0);
                                 glTranslatef(-eyePosition[0],-eyePosition[1],-eyePosition[2]); 
                                 glLightfv(GL_LIGHT0,GL_POSITION,lightPos_marcTorso);
                                 glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_marcTorso);            
                            glPopMatrix();    

                                               if(BODY_PART_SELECTION == 1 && leftArmSelection == 8)
                                               { 
                                                    MaterialDiffuse_marcTorso[0] =1.0;
                                                    rotationInfoTransparency     = 1.0;
                                               }
                                               else                 
                                               {
                                                    MaterialDiffuse_marcTorso[0] = 1.0;
                                                    rotationInfoTransparency     = 0.2;
                                               }                 
                    
                                     /////--------------------------------___HUD_START___-----------------------------------                       
                                              /////--------------------------------___HUD_START___-----------------------------------                       
                                              if(hideSetPlusDialoque == 0.0)   
                                              {//______________________________________________BEGIN_HIDE_SET_DIALOGUE____                                             
                                                   glPushMatrix(); 
                                                        glTranslatef(leftUpperArmRotationDisplayValues[0], leftUpperArmRotationDisplayValues[1], leftUpperArmRotationDisplayValues[2]); 
                                                        glRotatef(180, 0.0, 1.0, 0.0);
                                                        //glDisable(GL_DEPTH_TEST);
                                                        //glDisable(GL_CULL_FACE);
                                                        glDisable(GL_TEXTURE_2D);
                                                        glDisable(GL_CULL_FACE);
                                                        glColor4f(1.0f,1.0f,1.0f,rotationInfoTransparency);
                                                        glScalef(.4,.4,.4);
                                                        glEnable(GL_BLEND);
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, 0.097, 0);
                                                             printDecimalNumbers(leftUpperArm_ROTATE[3]);
                                                        glPopMatrix(); 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.071+.05, 0);
                                                             printDecimalNumbers(leftUpperArm_ROTATE[0]);
                                                        glPopMatrix();                                 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.238+.10, 0);
                                                             printDecimalNumbers(leftUpperArm_ROTATE[1]);
                                                        glPopMatrix();
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.410998+.15, 0);
                                                             printDecimalNumbers(leftUpperArm_ROTATE[2]);
                                                        glPopMatrix();
                                                        glEnable(GL_CULL_FACE);
                                                        glDisable(GL_BLEND);
                                                        glEnable(GL_TEXTURE_2D);
                                                        //glEnable(GL_CULL_FACE);
                                                        //glEnable(GL_DEPTH_TEST);                
                                                  glPopMatrix();
                                              }//______________________________________________END_HIDE_SET_DIALOGUE____ 
                                    /////--------------------------------___HUD_FINISH___-----------------------------------                     
                    //------------------------------------------------------------------------------------------------------------------------------                    
                    #include "_MODEL_FOLDERS_/marcParts/marcLeftUpperArm/marcLeftUpperArm_vboRender.cpp"  //_ALL_WOOD_SHADERS_ARE_LINKED_TO_THE_TORSO_SHADER
  
 
                       glPushMatrix(); 
                            glTranslatef(leftForeArm_POSITION[0], leftForeArm_POSITION[1], leftForeArm_POSITION[2]);             
                            glRotatef(leftForeArm_ROTATE[3], leftForeArm_ROTATE[0], leftForeArm_ROTATE[1], leftForeArm_ROTATE[2]);       
                            
                            glPushMatrix();
                                 glLoadIdentity();
                                 //
                            
                                 glRotatef(-leftForeArm_ROTATE[3],  -leftForeArm_ROTATE[0],  -leftForeArm_ROTATE[1],  leftForeArm_ROTATE[2]);                                 
                                 glRotatef(-leftUpperArm_ROTATE[3], -leftUpperArm_ROTATE[0], -leftUpperArm_ROTATE[1], leftUpperArm_ROTATE[2]);                                  
                                 glRotatef(-torso_ROTATE[3],        -torso_ROTATE[0],        -torso_ROTATE[1],        torso_ROTATE[2]); 
                                 glRotatef(-hips_ROTATE[3],         -hips_ROTATE[0],         -hips_ROTATE[1],         hips_ROTATE[2]);                                 
                                 glRotatef(marcRotation, 0, 1, 0); 
                                 glRotatef(-look_LEFT_RIGHT, 0, -1, 0);
                                 glTranslatef(-eyePosition[0],-eyePosition[1],-eyePosition[2]); 
                                 glLightfv(GL_LIGHT0,GL_POSITION,lightPos_marcTorso);
                                 glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_marcTorso);
                            glPopMatrix();                                 
                            //------------------------------------------------------
                                               if(BODY_PART_SELECTION == 1 && leftArmSelection == 9)
                                               { 
                                                    MaterialDiffuse_marcTorso[0] =1.0;
                                                    rotationInfoTransparency     = 1.0;
                                               }
                                               else                 
                                               {
                                                    MaterialDiffuse_marcTorso[0] = 1.0;
                                                    rotationInfoTransparency     = 0.2;
                                               }                          
                            /////--------------------------------___HUD_START___-----------------------------------                       
                                              if(hideSetPlusDialoque == 0.0)   
                                              {//______________________________________________BEGIN_HIDE_SET_DIALOGUE____                                                                                                  
                                                   glPushMatrix(); 
                                                        glTranslatef(leftLowerArmRotationDisplayValues[0], leftLowerArmRotationDisplayValues[1], leftLowerArmRotationDisplayValues[2]); 
                                                        glRotatef(180, 0.0, 1.0, 0.0);
                                                        //glDisable(GL_DEPTH_TEST);
                                                        //glDisable(GL_CULL_FACE);
                                                        glDisable(GL_TEXTURE_2D);
                                                        glDisable(GL_CULL_FACE);
                                                        glColor4f(1.0f,1.0f,1.0f,rotationInfoTransparency);
                                                        glScalef(.4,.4,.4);
                                                        glEnable(GL_BLEND);
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, 0.097, 0);
                                                             printDecimalNumbers(leftForeArm_ROTATE[3]);
                                                        glPopMatrix(); 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.071+.05, 0);
                                                             printDecimalNumbers(leftForeArm_ROTATE[0]);
                                                        glPopMatrix();                                 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.238+.10, 0);
                                                             printDecimalNumbers(leftForeArm_ROTATE[1]);
                                                        glPopMatrix();
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.410998+.15, 0);
                                                             printDecimalNumbers(leftForeArm_ROTATE[2]);
                                                        glPopMatrix();
                                                        glEnable(GL_CULL_FACE);
                                                        glDisable(GL_BLEND);
                                                        glEnable(GL_TEXTURE_2D);
                                                        //glEnable(GL_CULL_FACE);
                                                        //glEnable(GL_DEPTH_TEST);                
                                                    glPopMatrix();
                                               }//______________________________________________END_HIDE_SET_DIALOGUE____ 
                                /////--------------------------------___HUD_FINISH___-----------------------------------                                
                            #include "_MODEL_FOLDERS_/marcParts/marcLeftForeArm/marcLeftForeArm_vboRender.cpp"  //_________________________________ALL_WOOD_SHADERS_ARE_LINKED_TO_THE_TORSO_SHADER
                                          glTranslatef(leftHand_04[0], leftHand_04[1], leftHand_04[2]);             
                                          glRotatef(leftHand_ROTATE[3], leftHand_ROTATE[0], leftHand_ROTATE[1], leftHand_ROTATE[2]);         
                                                      
                                          glPushMatrix();
                                               glLoadIdentity();
                                               //
                                               glRotatef(-leftHand_ROTATE[3], -leftHand_ROTATE[0], -leftHand_ROTATE[1], leftHand_ROTATE[2]);                                               
                                               glRotatef(-leftForeArm_ROTATE[3],    -leftForeArm_ROTATE[0],    -leftForeArm_ROTATE[1],    leftForeArm_ROTATE[2]);                                               
                                               glRotatef(-leftUpperArm_ROTATE[3],   -leftUpperArm_ROTATE[0],   -leftUpperArm_ROTATE[1],   leftUpperArm_ROTATE[2]);                                                
                                               glRotatef(-torso_ROTATE[3],          -torso_ROTATE[0],          -torso_ROTATE[1],          torso_ROTATE[2]);                                               
                                               glRotatef(-hips_ROTATE[3],           -hips_ROTATE[0],           -hips_ROTATE[1],           hips_ROTATE[2]);                                               
                                               glRotatef(marcRotation, 0, 1, 0); 
                                               glRotatef(-look_LEFT_RIGHT, 0, -1, 0);
                                               glTranslatef(-eyePosition[0],-eyePosition[1],-eyePosition[2]); 
                                               glLightfv(GL_LIGHT0,GL_POSITION,lightPos_marcTorso);
                                               glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_marcTorso);   
                                          glPopMatrix();     
                                          //------------------------------------------------------
                                               if(BODY_PART_SELECTION == 1 && leftArmSelection == 0)
                                               { 
                                                    MaterialDiffuse_marcTorso[0] =1.0;
                                                    rotationInfoTransparency     = 1.0;
                                               }
                                               else                 
                                               {
                                                    MaterialDiffuse_marcTorso[0] = 1.0;
                                                    rotationInfoTransparency     = 0.2;
                                               }                          
                                               /////--------------------------------___HUD_START___-----------------------------------                                                
                                              if(hideSetPlusDialoque == 0.0)   
                                              {//______________________________________________BEGIN_HIDE_SET_DIALOGUE____                                                     
                                                    glPushMatrix(); 
                                                        glTranslatef(leftHandRotationDisplayValues[0], leftHandRotationDisplayValues[1], leftHandRotationDisplayValues[2]); 
                                                        glRotatef(180, 0.0, 1.0, 0.0);
                                                        //glDisable(GL_DEPTH_TEST);
                                                        //glDisable(GL_CULL_FACE);
                                                        glDisable(GL_TEXTURE_2D);
                                                        glDisable(GL_CULL_FACE);
                                                        glColor4f(1.0f,1.0f,1.0f,rotationInfoTransparency);
                                                        glScalef(.4,.4,.4);
                                                        glEnable(GL_BLEND);
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, 0.097, 0);
                                                             printDecimalNumbers(leftHand_ROTATE[3]);
                                                        glPopMatrix(); 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.071+.05, 0);
                                                             printDecimalNumbers(leftHand_ROTATE[0]);
                                                        glPopMatrix();                                 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.238+.1, 0);
                                                             printDecimalNumbers(leftHand_ROTATE[1]);
                                                        glPopMatrix();
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.410998+.15, 0);
                                                             printDecimalNumbers(leftHand_ROTATE[2]);
                                                        glPopMatrix();
                                                        glEnable(GL_CULL_FACE);
                                                        glDisable(GL_BLEND);
                                                        glEnable(GL_TEXTURE_2D);
                                                        //glEnable(GL_CULL_FACE);
                                                        //glEnable(GL_DEPTH_TEST);                
                                                    glPopMatrix();
                                               }
                                /////--------------------------------___HUD_FINISH___-----------------------------------   
                                               if(BODY_PART_SELECTION == 1 && leftArmSelection == 0)
                                               { 
                                                    MaterialDiffuse_marcTorso[0] =1.0;
                                                    rotationInfoTransparency     = 1.0;
                                               }
                                               else                 
                                               {
                                                    MaterialDiffuse_marcTorso[0] = 1.0;
                                                    rotationInfoTransparency     = 0.2;
                                               }  
                                          #include "_MODEL_FOLDERS_/marcParts/marcLeftHand/marcLeftHand_vboRender.cpp" //_________________________________ALL_WOOD_SHADERS_ARE_LINKED_TO_THE_TORSO_SHADER 

                                          

    glPopMatrix();              
  glPopMatrix();
glPopMatrix();
////////////_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM
////////////_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM
////////////_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM_____LEFT_ARM            
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                    
////////////_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM
////////////_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM
////////////_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM
glPushMatrix();
    
    glTranslatef(torso_04[0], torso_04[1], torso_04[2]);
   
    glRotatef(torso_ROTATE[3], torso_ROTATE[0], torso_ROTATE[1], torso_ROTATE[2]); 
       
       glPushMatrix(); 
           glTranslatef(rightUpperArm_04[0], rightUpperArm_04[1], rightUpperArm_04[2]);             
           glRotatef(rightUpperArm_ROTATE[3], rightUpperArm_ROTATE[0], rightUpperArm_ROTATE[1], rightUpperArm_ROTATE[2]);   
                           
                           
                            glPushMatrix();
                                 glLoadIdentity();
                                 glRotatef(-rightUpperArm_ROTATE[3],     -rightUpperArm_ROTATE[0], -rightUpperArm_ROTATE[1], rightUpperArm_ROTATE[2]);                                 
                                 glRotatef(-torso_ROTATE[3],             -torso_ROTATE[0],         -torso_ROTATE[1],         torso_ROTATE[2]);                                 
                                 glRotatef(-hips_ROTATE[3],              -hips_ROTATE[0],          -hips_ROTATE[1],          hips_ROTATE[2]);                                 
                                 glRotatef(marcRotation, 0, 1, 0); 
                                 glRotatef(-look_LEFT_RIGHT, 0, -1, 0);
                                 glTranslatef(-eyePosition[0],-eyePosition[1],-eyePosition[2]);                  
                                 glLightfv(GL_LIGHT0,GL_POSITION,lightPos_marcTorso);
                                 glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_marcTorso);
                            glPopMatrix();
                 
                                               if(BODY_PART_SELECTION == 2 && rightArmSelection == 8)
                                               { 
                                                    MaterialDiffuse_marcTorso[0] =1.0;
                                                    rotationInfoTransparency     = 1.0;
                                               }
                                               else                 
                                               {
                                                    MaterialDiffuse_marcTorso[0] = 1.0;
                                                    rotationInfoTransparency     = 0.2;
                                               }   
                                                      /////--------------------------------___HUD_START___-----------------------------------                       
                                              if(hideSetPlusDialoque == 0.0)   
                                              {//______________________________________________BEGIN_HIDE_SET_DIALOGUE____                                                   
                                                    glPushMatrix(); 
                                                        glTranslatef(rightUpperArmRotationDisplayValues[0], rightUpperArmRotationDisplayValues[1], rightUpperArmRotationDisplayValues[2]); 
                                                        glRotatef(180, 0.0, 1.0, 0.0);
                                                        //glDisable(GL_DEPTH_TEST);
                                                        //glDisable(GL_CULL_FACE);
                                                        glDisable(GL_TEXTURE_2D);
                                                        glDisable(GL_CULL_FACE);
                                                        glColor4f(1.0f,1.0f,1.0f,rotationInfoTransparency);
                                                        glScalef(.4,.4,.4);
                                                        glEnable(GL_BLEND);
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, 0.097, 0);
                                                             printDecimalNumbers(rightUpperArm_ROTATE[3]);
                                                        glPopMatrix(); 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.071+.05, 0);
                                                             printDecimalNumbers(rightUpperArm_ROTATE[0]);
                                                        glPopMatrix();                                 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.238+.10, 0);
                                                             printDecimalNumbers(rightUpperArm_ROTATE[1]);
                                                        glPopMatrix();
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.410998+.15, 0);
                                                             printDecimalNumbers(rightUpperArm_ROTATE[2]);
                                                        glPopMatrix();
                                                        glEnable(GL_CULL_FACE);
                                                        glDisable(GL_BLEND);
                                                        glEnable(GL_TEXTURE_2D);
                                                        //glEnable(GL_CULL_FACE);
                                                        //glEnable(GL_DEPTH_TEST);                
                                                    glPopMatrix();
                                               }//______________________________________________END_HIDE_SET_DIALOGUE____ 
                                    /////--------------------------------___HUD_FINISH___-----------------------------------   
                     #include "_MODEL_FOLDERS_/marcParts/marcRightUpperArm/marcRightUpperArm_vboRender.cpp"  //_________________________________ALL_WOOD_SHADERS_ARE_LINKED_TO_THE_TORSO_SHADER


                    
                     glPushMatrix(); 
                              glTranslatef(rightForeArm_04[0], rightForeArm_04[1], rightForeArm_04[2]);             
                              glRotatef(rightForeArm_ROTATE[3], rightForeArm_ROTATE[0], rightForeArm_ROTATE[1], rightForeArm_ROTATE[2]);    
                            
                            glPushMatrix();
                                 glLoadIdentity();
                                 //
                                 
                                 glRotatef(-rightForeArm_ROTATE[3],     -rightForeArm_ROTATE[0],  -rightForeArm_ROTATE[1],    rightForeArm_ROTATE[2]);                                  
                                 glRotatef(-rightUpperArm_ROTATE[3],    -rightUpperArm_ROTATE[0], -rightUpperArm_ROTATE[1],   rightUpperArm_ROTATE[2]);                                
                                 glRotatef(-torso_ROTATE[3],            -torso_ROTATE[0],         -torso_ROTATE[1],           torso_ROTATE[2]);                                 
                                 glRotatef(-hips_ROTATE[3],             -hips_ROTATE[0],          -hips_ROTATE[1],            hips_ROTATE[2]);                                 
                                 glRotatef(marcRotation, 0, 1, 0); 
                                 glRotatef(-look_LEFT_RIGHT, 0, -1, 0);
                                 glTranslatef(-eyePosition[0],-eyePosition[1],-eyePosition[2]);                                               
                                glLightfv(GL_LIGHT0,GL_POSITION,lightPos_marcTorso);
                                glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_marcTorso);
                            glPopMatrix();                                

                                               if(BODY_PART_SELECTION == 2 && rightArmSelection == 9)
                                               { 
                                                    MaterialDiffuse_marcTorso[0] =1.0;
                                                    rotationInfoTransparency     = 1.0;
                                               }
                                               else                 
                                               {
                                                    MaterialDiffuse_marcTorso[0] = 1.0;
                                                    rotationInfoTransparency     = 0.2;
                                               }                          
                            /////--------------------------------___HUD_START___-----------------------------------                       
                                              if(hideSetPlusDialoque == 0.0)   
                                              {//______________________________________________BEGIN_HIDE_SET_DIALOGUE____                                                    
                                                   glPushMatrix(); 
                                                        glTranslatef(rightLowerArmRotationDisplayValues[0], rightLowerArmRotationDisplayValues[1], rightLowerArmRotationDisplayValues[2]); 
                                                        glRotatef(180, 0.0, 1.0, 0.0);
                                                        //glDisable(GL_DEPTH_TEST);
                                                        //glDisable(GL_CULL_FACE);
                                                        glDisable(GL_TEXTURE_2D);
                                                        glDisable(GL_CULL_FACE);
                                                        glColor4f(1.0f,1.0f,1.0f,rotationInfoTransparency);
                                                        glScalef(.4,.4,.4);
                                                        glEnable(GL_BLEND);
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, 0.097, 0);
                                                             printDecimalNumbers(rightForeArm_ROTATE[3]);
                                                        glPopMatrix(); 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.071+.05, 0);
                                                             printDecimalNumbers(rightForeArm_ROTATE[0]);
                                                        glPopMatrix();                                 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.238+.10, 0);
                                                             printDecimalNumbers(rightForeArm_ROTATE[1]);
                                                        glPopMatrix();
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.410998+.15, 0);
                                                             printDecimalNumbers(rightForeArm_ROTATE[2]);
                                                        glPopMatrix();
                                                        glEnable(GL_CULL_FACE);
                                                        glDisable(GL_BLEND);
                                                        glEnable(GL_TEXTURE_2D);
                                                        //glEnable(GL_CULL_FACE);
                                                        //glEnable(GL_DEPTH_TEST);                
                                                    glPopMatrix();
                                               }//______________________________________________END_HIDE_SET_DIALOGUE____ 
                                /////--------------------------------___HUD_FINISH___-----------------------------------             
                                #include "_MODEL_FOLDERS_/marcParts/marcRightForeArm/marcRightForeArm_vboRender.cpp"  //_________________________________ALL_WOOD_SHADERS_ARE_LINKED_TO_THE_TORSO_SHADER

                 
                                         glTranslatef(rightHand_04[0],  rightHand_04[1],     rightHand_04[2]);             
                                         glRotatef(rightHand_ROTATE[3], rightHand_ROTATE[0], rightHand_ROTATE[1], rightHand_ROTATE[2]);   
                                          
                                          glPushMatrix();
                                               glLoadIdentity();
                                               //
                                               glRotatef(-rightHand_ROTATE[3], -rightHand_ROTATE[0], -rightHand_ROTATE[1], rightHand_ROTATE[2]);    
                                               glRotatef(-rightForeArm_ROTATE[3],    -rightForeArm_ROTATE[0],    -rightForeArm_ROTATE[1],    rightForeArm_ROTATE[2]);
                                               glRotatef(-rightUpperArm_ROTATE[3],   -rightUpperArm_ROTATE[0],   -rightUpperArm_ROTATE[1],   rightUpperArm_ROTATE[2]);                                            
                                               glRotatef(-torso_ROTATE[3],           -torso_ROTATE[0],           -torso_ROTATE[1],           torso_ROTATE[2]);                                               
                                               glRotatef(-hips_ROTATE[3],            -hips_ROTATE[0],            -hips_ROTATE[1],            hips_ROTATE[2]);                                              
                                               glRotatef(marcRotation, 0, 1, 0); 
                                               glRotatef(-look_LEFT_RIGHT, 0, -1, 0);
                                               glTranslatef(-eyePosition[0],-eyePosition[1],-eyePosition[2]);                                          
                                               glLightfv(GL_LIGHT0,GL_POSITION,lightPos_marcTorso);
                                               glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_marcTorso);  
                                          glPopMatrix();                                         
            
                                               if(BODY_PART_SELECTION == 2 && rightArmSelection == 0)
                                               { 
                                                    MaterialDiffuse_marcTorso[0] =1.0;
                                                    rotationInfoTransparency     = 1.0;
                                               }
                                               else                 
                                               {
                                                    MaterialDiffuse_marcTorso[0] = 1.0;
                                                    rotationInfoTransparency     = 0.2;
                                               } 
                                          /////--------------------------------___HUD_START___-----------------------------------                       
                                              if(hideSetPlusDialoque == 0.0)   
                                              {//______________________________________________BEGIN_HIDE_SET_DIALOGUE____                                                    
                                                   glPushMatrix(); 
                                                        glTranslatef(rightHandRotationDisplayValues[0], rightHandRotationDisplayValues[1], rightHandRotationDisplayValues[2]); 
                                                        glRotatef(180, 0.0, 1.0, 0.0);
                                                        //glDisable(GL_DEPTH_TEST);
                                                        //glDisable(GL_CULL_FACE);
                                                        glDisable(GL_TEXTURE_2D);
                                                        glDisable(GL_CULL_FACE);
                                                        glColor4f(1.0f,1.0f,1.0f,rotationInfoTransparency);
                                                        glScalef(.4,.4,.4);
                                                        glEnable(GL_BLEND);
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, 0.097, 0);
                                                             printDecimalNumbers(rightHand_ROTATE[3]);
                                                        glPopMatrix(); 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.071+.05, 0);
                                                             printDecimalNumbers(rightHand_ROTATE[0]);
                                                        glPopMatrix();                                 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.238+.1, 0);
                                                             printDecimalNumbers(rightHand_ROTATE[1]);
                                                        glPopMatrix();
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.410998+.15, 0);
                                                             printDecimalNumbers(rightHand_ROTATE[2]);
                                                        glPopMatrix();
                                                        glEnable(GL_CULL_FACE);
                                                        glDisable(GL_BLEND);
                                                        glEnable(GL_TEXTURE_2D);
                                                        //glEnable(GL_CULL_FACE);
                                                        //glEnable(GL_DEPTH_TEST);                
                                                    glPopMatrix();
                                               }//______________________________________________END_HIDE_SET_DIALOGUE____     
                                /////--------------------------------___HUD_FINISH___-----------------------------------                                          
                                         #include "_MODEL_FOLDERS_/marcParts/marcRightHand/marcRightHand_vboRender.cpp"  //_________________________________ALL_WOOD_SHADERS_ARE_LINKED_TO_THE_TORSO_SHADER
       glPopMatrix();
   glPopMatrix();
glPopMatrix();            
////////////_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM
////////////_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM
////////////_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM_____RIGHT_ARM
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////            
////////////_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG
////////////_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG
////////////_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG
glPushMatrix(); 
    
    glPushMatrix(); 
         glTranslatef(leftUpperLeg_04[0], leftUpperLeg_04[1], leftUpperLeg_04[2]);             
         glRotatef(leftUpperLeg_ROTATE[3], leftUpperLeg_ROTATE[0], leftUpperLeg_ROTATE[1], leftUpperLeg_ROTATE[2]); 

                            glPushMatrix();
                                 glLoadIdentity();
                                 glRotatef(-leftUpperLeg_ROTATE[3], -leftUpperLeg_ROTATE[0], -leftUpperLeg_ROTATE[1], leftUpperLeg_ROTATE[2]);                                 
                                 glRotatef(-hips_ROTATE[3],         -hips_ROTATE[0],         -hips_ROTATE[1],         hips_ROTATE[2]);                                 
                                 glRotatef(marcRotation, 0, 1, 0); 
                                 glRotatef(-look_LEFT_RIGHT, 0, -1, 0);
                                 glTranslatef(-eyePosition[0],-eyePosition[1],-eyePosition[2]);             
                                 glLightfv(GL_LIGHT0,GL_POSITION,lightPos_marcTorso);
                                 glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_marcTorso);
                            glPopMatrix();                 

                                               if(BODY_PART_SELECTION == 3 && leftLegSelection == 8)
                                               { 
                                                    MaterialDiffuse_marcTorso[0] =1.0;
                                                    rotationInfoTransparency     = 1.0;
                                               }
                                               else                 
                                               {
                                                    MaterialDiffuse_marcTorso[0] = 1.0;
                                                    rotationInfoTransparency     = 0.2;
                                               }   
                                     /////--------------------------------___HUD_START___-----------------------------------                       
                                              if(hideSetPlusDialoque == 0.0)   
                                              {//______________________________________________BEGIN_HIDE_SET_DIALOGUE____                                                    
                                                   glPushMatrix(); 
                                                        glTranslatef(leftUpperLegRotationDisplayValues[0], leftUpperLegRotationDisplayValues[1], leftUpperLegRotationDisplayValues[2]); 
                                                        glRotatef(180, 0.0, 1.0, 0.0);
                                                        //glDisable(GL_DEPTH_TEST);
                                                        //glDisable(GL_CULL_FACE);
                                                        glDisable(GL_TEXTURE_2D);
                                                        glDisable(GL_CULL_FACE);
                                                        glColor4f(1.0f,1.0f,1.0f,rotationInfoTransparency);
                                                        glScalef(.4,.4,.4);
                                                        glEnable(GL_BLEND);
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, 0.097, 0);
                                                             printDecimalNumbers(leftUpperLeg_ROTATE[3]);
                                                        glPopMatrix(); 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.071+.05, 0);
                                                             printDecimalNumbers(leftUpperLeg_ROTATE[0]);
                                                        glPopMatrix();                                 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.238+.10, 0);
                                                             printDecimalNumbers(leftUpperLeg_ROTATE[1]);
                                                        glPopMatrix();
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.410998+.15, 0);
                                                             printDecimalNumbers(leftUpperLeg_ROTATE[2]);
                                                        glPopMatrix();
                                                        glEnable(GL_CULL_FACE);
                                                        glDisable(GL_BLEND);
                                                        glEnable(GL_TEXTURE_2D);
                                                        //glEnable(GL_CULL_FACE);
                                                        //glEnable(GL_DEPTH_TEST);                
                                                    glPopMatrix();
                                               }//______________________________________________END_HIDE_SET_DIALOGUE____
                                    /////--------------------------------___HUD_FINISH___-----------------------------------                             
                             
                             #include "_MODEL_FOLDERS_/marcParts/marcLeftUpperLeg/marcLeftUpperLeg_vboRender.cpp"  //_________________________________ALL_WOOD_SHADERS_ARE_LINKED_TO_THE_TORSO_SHADER



                    glPushMatrix(); 
                               glTranslatef(leftLowerLeg_04[0], leftLowerLeg_04[1], leftLowerLeg_04[2]);             
                               glRotatef(leftLowerLeg_ROTATE[3], leftLowerLeg_ROTATE[0], leftLowerLeg_ROTATE[1], leftLowerLeg_ROTATE[2]);   
                            
                            glPushMatrix();
                                 glLoadIdentity();
                                 //
                                 
                                 glRotatef(-leftLowerLeg_ROTATE[3], -leftLowerLeg_ROTATE[0], -leftLowerLeg_ROTATE[1], leftLowerLeg_ROTATE[2]);                                 
                                 glRotatef(-leftUpperLeg_ROTATE[3], -leftUpperLeg_ROTATE[0], -leftUpperLeg_ROTATE[1], leftUpperLeg_ROTATE[2]);                                  
                                 glRotatef(-hips_ROTATE[3],         -hips_ROTATE[0],         -hips_ROTATE[1],         hips_ROTATE[2]);                                 
                                 glRotatef(marcRotation, 0, 1, 0); 
                                 glRotatef(-look_LEFT_RIGHT, 0, -1, 0);
                                 glTranslatef(-eyePosition[0],-eyePosition[1],-eyePosition[2]);                               
                                 glLightfv(GL_LIGHT0,GL_POSITION,lightPos_marcTorso);
                                 glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_marcTorso);   
                            glPopMatrix();                               

                                               if(BODY_PART_SELECTION == 3 && leftLegSelection == 9)
                                               { 
                                                    MaterialDiffuse_marcTorso[0] =1.0;
                                                    rotationInfoTransparency     = 1.0;
                                               }
                                               else                 
                                               {
                                                    MaterialDiffuse_marcTorso[0] = 1.0;
                                                    rotationInfoTransparency     = 0.2;
                                               }                         
                                     /////--------------------------------___HUD_START___-----------------------------------                       
                                              if(hideSetPlusDialoque == 0.0)   
                                              {//______________________________________________BEGIN_HIDE_SET_DIALOGUE____                                                    
                                                   glPushMatrix(); 
                                                        glTranslatef(leftLowerLegRotationDisplayValues[0], leftLowerLegRotationDisplayValues[1], leftLowerLegRotationDisplayValues[2]); 
                                                        glRotatef(180, 0.0, 1.0, 0.0);
                                                        //glDisable(GL_DEPTH_TEST);
                                                        //glDisable(GL_CULL_FACE);
                                                        glDisable(GL_TEXTURE_2D);
                                                        glDisable(GL_CULL_FACE);
                                                        glColor4f(1.0f,1.0f,1.0f,rotationInfoTransparency);
                                                        glScalef(.4,.4,.4);
                                                        glEnable(GL_BLEND);
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, 0.097, 0);
                                                             printDecimalNumbers(leftLowerLeg_ROTATE[3]);
                                                        glPopMatrix(); 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.071+.05, 0);
                                                             printDecimalNumbers(leftLowerLeg_ROTATE[0]);
                                                        glPopMatrix();                                 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.238+.10, 0);
                                                             printDecimalNumbers(leftLowerLeg_ROTATE[1]);
                                                        glPopMatrix();
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.410998+.15, 0);
                                                             printDecimalNumbers(leftLowerLeg_ROTATE[2]);
                                                        glPopMatrix();
                                                        glEnable(GL_CULL_FACE);
                                                        glDisable(GL_BLEND);
                                                        glEnable(GL_TEXTURE_2D);
                                                        //glEnable(GL_CULL_FACE);
                                                        //glEnable(GL_DEPTH_TEST);                
                                                    glPopMatrix();
                                               }//______________________________________________END_HIDE_SET_DIALOGUE____  
                                    /////--------------------------------___HUD_FINISH___-----------------------------------                             
                                                          
                             #include "_MODEL_FOLDERS_/marcParts/marcLeftLowerLeg/marcLeftLowerLeg_vboRender.cpp"  //_________________________________ALL_WOOD_SHADERS_ARE_LINKED_TO_THE_TORSO_SHADER

       
                                                  glTranslatef(leftFoot_04[0], leftFoot_04[1], leftFoot_04[2]);             
                                                  glRotatef(leftFoot_ROTATE[3], leftFoot_ROTATE[0], leftFoot_ROTATE[1], leftFoot_ROTATE[2]); 
                                                 
                                                 glPushMatrix();
                                                      glLoadIdentity();
                                                      //
                                                      glRotatef(-leftFoot_ROTATE[3], -leftFoot_ROTATE[0], -leftFoot_ROTATE[1], leftFoot_ROTATE[2]);                                                       
                                                      glRotatef(-leftLowerLeg_ROTATE[3], -leftLowerLeg_ROTATE[0], -leftLowerLeg_ROTATE[1], leftLowerLeg_ROTATE[2]);                                                       
                                                      glRotatef(-leftUpperLeg_ROTATE[3], -leftUpperLeg_ROTATE[0], -leftUpperLeg_ROTATE[1], leftUpperLeg_ROTATE[2]);                                                       
                                                      glRotatef(-hips_ROTATE[3],         -hips_ROTATE[0],         -hips_ROTATE[1],         hips_ROTATE[2]);                                                     
                                                      glRotatef(marcRotation, 0, 1, 0); 
                                                      glRotatef(-look_LEFT_RIGHT, 0, -1, 0);
                                                      glTranslatef(-eyePosition[0],-eyePosition[1],-eyePosition[2]);                                                  
                                                      glLightfv(GL_LIGHT0,GL_POSITION,lightPos_marcTorso);
                                                      glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_marcTorso);     
                                                 glPopMatrix();                                                  

                                               if(BODY_PART_SELECTION == 3 && leftLegSelection == 0)
                                               { 
                                                    MaterialDiffuse_marcTorso[0] =1.0;
                                                    rotationInfoTransparency     = 1.0;
                                               }
                                               else                 
                                               {
                                                    MaterialDiffuse_marcTorso[0] = 1.0;
                                                    rotationInfoTransparency     = 0.2;
                                               }                                                 
                                     /////--------------------------------___HUD_START___-----------------------------------                       
                                              if(hideSetPlusDialoque == 0.0)   
                                              {//______________________________________________BEGIN_HIDE_SET_DIALOGUE____                                                    
                                                   glPushMatrix(); 
                                                        glTranslatef(leftFootRotationDisplayValues[0], leftFootRotationDisplayValues[1], leftFootRotationDisplayValues[2]); 
                                                        glRotatef(180, 0.0, 1.0, 0.0);
                                                        //glDisable(GL_DEPTH_TEST);
                                                        //glDisable(GL_CULL_FACE);
                                                        glDisable(GL_TEXTURE_2D);
                                                        glDisable(GL_CULL_FACE);
                                                        glColor4f(1.0f,1.0f,1.0f,rotationInfoTransparency);
                                                        glScalef(.4,.4,.4);
                                                        glEnable(GL_BLEND);
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, 0.097, 0);
                                                             printDecimalNumbers(leftFoot_ROTATE[3]);
                                                        glPopMatrix(); 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.071+.05, 0);
                                                             printDecimalNumbers(leftFoot_ROTATE[0]);
                                                        glPopMatrix();                                 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.238+.10, 0);
                                                             printDecimalNumbers(leftFoot_ROTATE[1]);
                                                        glPopMatrix();
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.410998+.15, 0);
                                                             printDecimalNumbers(leftFoot_ROTATE[2]);
                                                        glPopMatrix();
                                                        glEnable(GL_CULL_FACE);
                                                        glDisable(GL_BLEND);
                                                        glEnable(GL_TEXTURE_2D);
                                                        //glEnable(GL_CULL_FACE);
                                                        //glEnable(GL_DEPTH_TEST);                
                                                    glPopMatrix();
                                               }//______________________________________________BEGIN_HIDE_SET_DIALOGUE____
                                    /////--------------------------------___HUD_FINISH___-----------------------------------                                                     
                                                 #include "_MODEL_FOLDERS_/marcParts/marcLeftBoot/marcLeftBoot_vboRender.cpp"  //_________________________________ALL_WOOD_SHADERS_ARE_LINKED_TO_THE_TORSO_SHADER

 

      glPopMatrix();
   glPopMatrix();
glPopMatrix(); 
////////////_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG
////////////_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG
////////////_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG_____LEFT_LEG
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG
////////////_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG
////////////_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG
glPushMatrix();
           glPushMatrix(); 
                  glTranslatef(rightUpperLeg_04[0], rightUpperLeg_04[1], rightUpperLeg_04[2]);             
                  glRotatef(rightUpperLeg_ROTATE[3], rightUpperLeg_ROTATE[0], rightUpperLeg_ROTATE[1], rightUpperLeg_ROTATE[2]);      
           
                            glPushMatrix();
                                 glLoadIdentity();
                                 glRotatef(-rightUpperLeg_ROTATE[3], -rightUpperLeg_ROTATE[0], -rightUpperLeg_ROTATE[1], rightUpperLeg_ROTATE[2]);                                 
                                 glRotatef(-hips_ROTATE[3],          -hips_ROTATE[0],          -hips_ROTATE[1],          hips_ROTATE[2]);                                 
                                 glRotatef(marcRotation, 0, 1, 0); 
                                 glRotatef(-look_LEFT_RIGHT, 0, -1, 0);
                                 glTranslatef(-eyePosition[0],-eyePosition[1],-eyePosition[2]);                          
                                 glLightfv(GL_LIGHT0,GL_POSITION,lightPos_marcTorso);
                                 glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_marcTorso);
                            glPopMatrix();
                            
                                               if(BODY_PART_SELECTION == 4 && rightLegSelection == 8)
                                               { 
                                                    MaterialDiffuse_marcTorso[0] =1.0;
                                                    rotationInfoTransparency     = 1.0;
                                               }
                                               else                 
                                               {
                                                    MaterialDiffuse_marcTorso[0] = 1.0;
                                                    rotationInfoTransparency     = 0.2;
                                               }   
                                     /////--------------------------------___HUD_START___-----------------------------------                       
                                              if(hideSetPlusDialoque == 0.0)   
                                              {//______________________________________________BEGIN_HIDE_SET_DIALOGUE____                                                    
                                                    glPushMatrix(); 
                                                        glTranslatef(rightUpperLegRotationDisplayValues[0], rightUpperLegRotationDisplayValues[1], rightUpperLegRotationDisplayValues[2]); 
                                                        glRotatef(180, 0.0, 1.0, 0.0);
                                                        //glDisable(GL_DEPTH_TEST);
                                                        //glDisable(GL_CULL_FACE);
                                                        glDisable(GL_TEXTURE_2D);
                                                        glColor4f(1.0f,1.0f,1.0f,rotationInfoTransparency);
                                                        glScalef(.4,.4,.4);
                                                        glEnable(GL_BLEND);
                                                        glDisable(GL_CULL_FACE);
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, 0.097, 0);
                                                             printDecimalNumbers(rightUpperLeg_ROTATE[3]);
                                                        glPopMatrix(); 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.071+.05, 0);
                                                             printDecimalNumbers(rightUpperLeg_ROTATE[0]);
                                                        glPopMatrix();                                 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.238+.10, 0);
                                                             printDecimalNumbers(rightUpperLeg_ROTATE[1]);
                                                        glPopMatrix();
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.410998+.15, 0);
                                                             printDecimalNumbers(rightUpperLeg_ROTATE[2]);
                                                        glPopMatrix();
                                                        glEnable(GL_CULL_FACE);
                                                        glDisable(GL_BLEND);
                                                        glEnable(GL_TEXTURE_2D);
                                                        //glEnable(GL_CULL_FACE);
                                                        //glEnable(GL_DEPTH_TEST);                
                                                    glPopMatrix();
                                               }//______________________________________________END_HIDE_SET_DIALOGUE____  
                                    /////--------------------------------___HUD_FINISH___-----------------------------------                                
                             
                             #include "_MODEL_FOLDERS_/marcParts/marcRightUpperLeg/marcRightUpperLeg_vboRender.cpp"      //_________________________________ALL_WOOD_SHADERS_ARE_LINKED_TO_THE_TORSO_SHADER    
                                            
                                    glPushMatrix(); 
                                            glTranslatef(rightLowerLeg_04[0], rightLowerLeg_04[1], rightLowerLeg_04[2]);             
                                            glRotatef(rightLowerLeg_ROTATE[3], rightLowerLeg_ROTATE[0], rightLowerLeg_ROTATE[1], rightLowerLeg_ROTATE[2]);     
                            glPushMatrix();
                                 glLoadIdentity();
                                 //
                                 glRotatef(-rightLowerLeg_ROTATE[3], -rightLowerLeg_ROTATE[0], -rightLowerLeg_ROTATE[1], rightLowerLeg_ROTATE[2]);                                 
                                 glRotatef(-rightUpperLeg_ROTATE[3], -rightUpperLeg_ROTATE[0], -rightUpperLeg_ROTATE[1], rightUpperLeg_ROTATE[2]);                                 
                                 glRotatef(-hips_ROTATE[3],          -hips_ROTATE[0],          -hips_ROTATE[1],          hips_ROTATE[2]);                                 
                                 glRotatef(marcRotation, 0, 1, 0); 
                                 glRotatef(-look_LEFT_RIGHT, 0, -1, 0);
                                 glTranslatef(-eyePosition[0],-eyePosition[1],-eyePosition[2]);                                            
                                 glLightfv(GL_LIGHT0,GL_POSITION,lightPos_marcTorso);
                                 glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_marcTorso);                                            
                            glPopMatrix();                

                                               if(BODY_PART_SELECTION == 4 && rightLegSelection == 9)
                                               { 
                                                    MaterialDiffuse_marcTorso[0] =1.0;
                                                    rotationInfoTransparency     = 1.0;
                                               }
                                               else                 
                                               {
                                                    MaterialDiffuse_marcTorso[0] = 1.0;
                                                    rotationInfoTransparency     = 0.2;
                                               }                       
                                     /////--------------------------------___HUD_START___-----------------------------------                       
                                              if(hideSetPlusDialoque == 0.0)   
                                              {//______________________________________________BEGIN_HIDE_SET_DIALOGUE____                                                    
                                                    glPushMatrix(); 
                                                        glTranslatef(rightLowerLegRotationDisplayValues[0], rightLowerLegRotationDisplayValues[1], rightLowerLegRotationDisplayValues[2]); 
                                                        glRotatef(180, 0.0, 1.0, 0.0);
                                                        //glDisable(GL_DEPTH_TEST);
                                                        //glDisable(GL_CULL_FACE);
                                                        glDisable(GL_TEXTURE_2D);
                                                        glDisable(GL_CULL_FACE);
                                                        glColor4f(1.0f,1.0f,1.0f,rotationInfoTransparency);
                                                        glScalef(.4,.4,.4);
                                                        glEnable(GL_BLEND);
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, 0.097, 0);
                                                             printDecimalNumbers(rightLowerLeg_ROTATE[3]);
                                                        glPopMatrix(); 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.071+.05, 0);
                                                             printDecimalNumbers(rightLowerLeg_ROTATE[0]);
                                                        glPopMatrix();                                 
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.238+.10, 0);
                                                             printDecimalNumbers(rightLowerLeg_ROTATE[1]);
                                                        glPopMatrix();
                                                        glPushMatrix(); 
                                                             glTranslatef(0.0f, -0.410998+.15, 0);
                                                             printDecimalNumbers(rightLowerLeg_ROTATE[2]);
                                                        glPopMatrix();
                                                        glDisable(GL_BLEND);
                                                        glEnable(GL_CULL_FACE);
                                                        glEnable(GL_TEXTURE_2D);
                                                        //glEnable(GL_CULL_FACE);
                                                        //glEnable(GL_DEPTH_TEST);                
                                                   glPopMatrix();
                                               }//______________________________________________END_HIDE_SET_DIALOGUE____ 
                                    /////--------------------------------___HUD_FINISH___-----------------------------------                             
                             #include "_MODEL_FOLDERS_/marcParts/marcRightLowerLeg/marcRightLowerLeg_vboRender.cpp" //_________________________________ALL_WOOD_SHADERS_ARE_LINKED_TO_THE_TORSO_SHADER
                          
   
                      
                                                            glTranslatef(rightFoot_04[0], rightFoot_04[1], rightFoot_04[2]);             
                                                            glRotatef(rightFoot_ROTATE[3], rightFoot_ROTATE[0], rightFoot_ROTATE[1], rightFoot_ROTATE[2]);       
                           
                                                              glPushMatrix();
                                                                   glLoadIdentity();
                                                                   //
                                                                   glRotatef(-rightFoot_ROTATE[3], -rightFoot_ROTATE[0], -rightFoot_ROTATE[1], rightFoot_ROTATE[2]);                                                                    
                                                                   glRotatef(-rightLowerLeg_ROTATE[3], -rightLowerLeg_ROTATE[0], -rightLowerLeg_ROTATE[1], rightLowerLeg_ROTATE[2]);                                                                   
                                                                   glRotatef(-rightUpperLeg_ROTATE[3], -rightUpperLeg_ROTATE[0], -rightUpperLeg_ROTATE[1], rightUpperLeg_ROTATE[2]);                                                                   
                                                                   glRotatef(-hips_ROTATE[3],          -hips_ROTATE[0],          -hips_ROTATE[1],          hips_ROTATE[2]);                                                                   
                                                                   glRotatef(marcRotation, 0, 1, 0); 
                                                                   glRotatef(-look_LEFT_RIGHT, 0, -1, 0);
                                                                   glTranslatef(-eyePosition[0],-eyePosition[1],-eyePosition[2]);                                                            
                                                                   glLightfv(GL_LIGHT0,GL_POSITION,lightPos_marcTorso);
                                                                   glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_marcTorso);   
                                                              glPopMatrix();                           

                                                              if(BODY_PART_SELECTION == 4 && rightLegSelection == 0)
                                                              { 
                                                                    MaterialDiffuse_marcTorso[0] =1.0;
                                                                    rotationInfoTransparency     = 1.0;
                                                              }
                                                              else                 
                                                              {
                                                                    MaterialDiffuse_marcTorso[0] = 1.0;
                                                                    rotationInfoTransparency     = 0.2;
                                                              }                                    
                                                              /////--------------------------------___HUD_START___-----------------------------------                       
                                                              if(hideSetPlusDialoque == 0.0)   
                                                              {//______________________________________________BEGIN_HIDE_SET_DIALOGUE____                                                                            
                                                                       glPushMatrix(); 
                                                                                 glTranslatef(rightFootRotationDisplayValues[0], rightFootRotationDisplayValues[1], rightFootRotationDisplayValues[2]); 
                                                                                 glRotatef(180, 0.0, 1.0, 0.0);
                                                                                 //glDisable(GL_DEPTH_TEST);
                                                                                 //glDisable(GL_CULL_FACE);
                                                                                 glDisable(GL_TEXTURE_2D);
                                                                                 glDisable(GL_CULL_FACE);                      
                                                                                 glColor4f(1.0f,1.0f,1.0f,rotationInfoTransparency);
                                                                                 glScalef(.4,.4,.4);
                                                                                 glEnable(GL_BLEND);
                                                                                 glPushMatrix(); 
                                                                                      glTranslatef(0.0f, 0.097, 0);
                                                                                      printDecimalNumbers(rightFoot_ROTATE[3]);
                                                                                 glPopMatrix(); 
                                                                                 glPushMatrix(); 
                                                                                     glTranslatef(0.0f, -0.071+.05, 0);
                                                                                      printDecimalNumbers(rightFoot_ROTATE[0]);
                                                                                 glPopMatrix();                                 
                                                                                 glPushMatrix(); 
                                                                                      glTranslatef(0.0f, -0.238+.10, 0);
                                                                                      printDecimalNumbers(rightFoot_ROTATE[1]);
                                                                                 glPopMatrix();
                                                                                 glPushMatrix(); 
                                                                                      glTranslatef(0.0f, -0.410998+.15, 0);
                                                                                      printDecimalNumbers(rightFoot_ROTATE[2]);
                                                                                 glPopMatrix();
                                                                                 glDisable(GL_BLEND);
                                                                                 glEnable(GL_CULL_FACE);
                                                                                 glEnable(GL_TEXTURE_2D);
                                                                                 //glEnable(GL_CULL_FACE);
                                                                                 //glEnable(GL_DEPTH_TEST);                
                                                                        glPopMatrix();
                                                                }//______________________________________________END_HIDE_SET_DIALOGUE____   
                                                              /////--------------------------------___HUD_FINISH___-----------------------------------                                                                 
                                                              #include "_MODEL_FOLDERS_/marcParts/marcRightBoot/marcRightBoot_vboRender.cpp" //_________________________________ALL_WOOD_SHADERS_ARE_LINKED_TO_THE_TORSO_SHADER 

                        
     
       
                                    glPopMatrix(); 
             glPopMatrix();
       glPopMatrix();


////////////_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG
////////////_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG
////////////_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG_____RIGHT_LEG      
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   glTranslatef(torso_04[0],  torso_04[1], torso_04[2]);
   glRotatef(torso_ROTATE[3], torso_ROTATE[0], torso_ROTATE[1], torso_ROTATE[2]); 

                                                      
                                                        glTranslatef(jetPackPosition[0], jetPackPosition[1], jetPackPosition[2]);     
                                                                    
                                                                    glPushMatrix();
                                                                          glLoadIdentity();
                                                                          //
                                                                          glRotatef(-torso_ROTATE[3], -torso_ROTATE[0], -torso_ROTATE[1], torso_ROTATE[2]);                                                                          
                                                                          glRotatef(-hips_ROTATE[3],  -hips_ROTATE[0],  -hips_ROTATE[1],  hips_ROTATE[2]);                                                                          
                                                                          glRotatef(marcRotation, 0, 1, 0); 
                                                                          glRotatef(-look_LEFT_RIGHT, 0, -1, 0);
                                                                          glTranslatef(-eyePosition[0],-eyePosition[1],-eyePosition[2]);                                                                      
                                                                          glLightfv (GL_LIGHT0,GL_POSITION, lightPos_marcTorso);
                                                                          glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, quadraticAttenuation_jetPackEngines);
                                                                    glPopMatrix();     

                                                                    #include "_MODEL_FOLDERS_/jetPack/jetPackTopCones/jetPackTopCones_vboRender.cpp" 
                                                             ////////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

                                                                    #include "_MODEL_FOLDERS_/jetPack/jetPackMiddleEngines/jetPackMiddleEngines_vboRender.cpp"                         
                                                             ////////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    

                                                                    #include "_MODEL_FOLDERS_/jetPack/jetPackNozzels/jetPackNozzels_vboRender.cpp"  
                                                             ////////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
     

                                                                    #include "_MODEL_FOLDERS_/jetPack/jetPackBindings/jetPackBindings_vboRender.cpp"  
                                                             ////////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                                                                

                                                                    
                                                                    #include "_MODEL_FOLDERS_/jetPack/jetPacksideHandles/jetPacksideHandles_vboRender.cpp"  
                                                     
                                                             ////////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 

                                                                    #include "_MODEL_FOLDERS_/jetPack/jetPackVestStraps/jetPackVestStraps_vboRender.cpp"  
                                                    
                                                   
glPopMatrix(); 
