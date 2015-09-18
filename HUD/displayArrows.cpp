 glPushMatrix();
                           glTranslatef(arrows[0],arrows[1],arrows[2]);
                           glScalef(arrowScaleFactor,arrowScaleFactor,arrowScaleFactor);     
                           glDisable(GL_BLEND);
                               if(arrowSelection == 1)
                               {             
                                       glPushMatrix();
                                       glRotatef(90, 1.0, 0.0, 0.0); 
                                             glColor3f(1.0f, 0.0f, 1.0f);                                              
                                              glInterleavedArrays( GL_T2F_N3F_V3F, 0, headArrow);
                                              glDrawArrays( GL_TRIANGLES, 0, 12);  
                                       glPopMatrix();
                               }
                               if(arrowSelection == 2)
                               {             
                                       glPushMatrix();
                                       glRotatef(90, 1.0, 0.0, 0.0); 
                                             glColor3f(1.0f, 0.0f, 1.0f); 
                                             glInterleavedArrays( GL_T2F_N3F_V3F, 0, hipsArrow);
                                             glDrawArrays( GL_TRIANGLES, 0, 24);  
                                       glPopMatrix();
                               }                               
                               if(arrowSelection == 3)
                               {             
                                       glPushMatrix();
                                       glRotatef(90, 1.0, 0.0, 0.0);                                             
                                             glColor3f(1.0f, 0.0f, 1.0f);                                             
                                             glInterleavedArrays( GL_T2F_N3F_V3F, 0, torsoArrow);
                                             glDrawArrays( GL_TRIANGLES, 0, 24);  
                                       glPopMatrix();
                               } 
                               if(arrowSelection == 12)
                               {             
                                       glPushMatrix();
                                       glRotatef(90, 1.0, 0.0, 0.0);                                             
                                             glColor3f(1.0f, 0.0f, 1.0f);                                                                                    
                                             glInterleavedArrays( GL_T2F_N3F_V3F, 0, leftAnkleArrow);
                                             glDrawArrays( GL_TRIANGLES, 0, 12);   
                                       glPopMatrix();
                               } 
                               if(arrowSelection == 11)
                               {             
                                       glPushMatrix();
                                       glRotatef(90, 1.0, 0.0, 0.0);                                             
                                             glColor3f(1.0f, 0.0f, 1.0f);                                                                                    
                                             glInterleavedArrays( GL_T2F_N3F_V3F, 0, leftLowerLegArrow);
                                             glDrawArrays( GL_TRIANGLES, 0, 12);  
                                       glPopMatrix();
                               }
                               if(arrowSelection == 10)
                               {             
                                       glPushMatrix();
                                       glRotatef(90, 1.0, 0.0, 0.0);                                             
                                             glColor3f(1.0f, 0.0f, 1.0f);                                                                                    
                                             glInterleavedArrays( GL_T2F_N3F_V3F, 0, leftUpperLegArrow);
                                             glDrawArrays( GL_TRIANGLES, 0, 12);  
                                       glPopMatrix();
                               }
                               if(arrowSelection == 9)
                               {             
                                       glPushMatrix();
                                       glRotatef(90, 1.0, 0.0, 0.0);                                             
                                             glColor3f(1.0f, 0.0f, 1.0f);                                                                                   
                                             glInterleavedArrays( GL_T2F_N3F_V3F, 0, rightWristArrow);
                                             glDrawArrays( GL_TRIANGLES, 0, 12); 
                                       glPopMatrix(); 
                               }
                               if(arrowSelection == 8)
                               {             
                                       glPushMatrix();
                                       glRotatef(90, 1.0, 0.0, 0.0);                                            
                                             glColor3f(1.0f, 0.0f, 1.0f);                                                                                     
                                             glInterleavedArrays( GL_T2F_N3F_V3F, 0, rightElbowArrow);
                                             glDrawArrays( GL_TRIANGLES, 0, 12);
                                       glPopMatrix();  
                               } 
                               if(arrowSelection == 7)
                               {             
                                       glPushMatrix();
                                       glRotatef(90, 1.0, 0.0, 0.0);                                             
                                             glColor3f(1.0f, 0.0f, 1.0f);                                                                                    
                                             glInterleavedArrays( GL_T2F_N3F_V3F, 0, rightShoulderArrow);
                                             glDrawArrays( GL_TRIANGLES, 0, 12);  
                                       glPopMatrix();
                               }                    
                               if(arrowSelection == 6)
                               {             
                                       glPushMatrix();
                                       glRotatef(90, 1.0, 0.0, 0.0);                                             
                                             glColor3f(1.0f, 0.0f, 1.0f);                                                                                    
                                             glInterleavedArrays( GL_T2F_N3F_V3F, 0, leftWristArrow);
                                             glDrawArrays( GL_TRIANGLES, 0, 12);
                                       glPopMatrix();   
                               }                               
                               if(arrowSelection == 5)
                               {             
                                       glPushMatrix();
                                       glRotatef(90, 1.0, 0.0, 0.0);                                             
                                             glColor3f(1.0f, 0.0f, 1.0f);                                                                                   
                                             glInterleavedArrays( GL_T2F_N3F_V3F, 0, leftElbowArrow);
                                             glDrawArrays( GL_TRIANGLES, 0, 12);
                                       glPopMatrix();  
                               }
                              
                               if(arrowSelection == 4)
                               {             
                                       glPushMatrix();
                                       glRotatef(90, 1.0, 0.0, 0.0);                                              
                                             glColor3f(1.0f, 0.0f, 1.0f);                                                                                    
                                             glInterleavedArrays( GL_T2F_N3F_V3F, 0, leftShoulderArrow);
                                             glDrawArrays( GL_TRIANGLES, 0, 12);
                                       glPopMatrix();  
                               }
                               if(arrowSelection == 15)
                               {             
                                       glPushMatrix();
                                       glRotatef(90, 1.0, 0.0, 0.0);                                             
                                              glColor3f(1.0f, 0.0f, 1.0f);                                                                                   
                                             glInterleavedArrays( GL_T2F_N3F_V3F, 0, rightAnkleArrow);
                                             glDrawArrays( GL_TRIANGLES, 0, 12);   
                                       glPopMatrix();
                               }
                               if(arrowSelection == 14)
                               {             
                                       glPushMatrix();
                                       glRotatef(90, 1.0, 0.0, 0.0);                                              
                                             glColor3f(1.0f, 0.0f, 1.0f);                                                                                    
                                             glInterleavedArrays( GL_T2F_N3F_V3F, 0, rightLowerLegArrow);
                                             glDrawArrays( GL_TRIANGLES, 0, 9); 
                                       glPopMatrix(); 
                               }
                               if(arrowSelection == 13)
                               {             
                                       glPushMatrix();
                                       glRotatef(90, 1.0, 0.0, 0.0);                                              
                                             glColor3f(1.0f, 0.0f, 1.0f);                                                                                 
                                             glInterleavedArrays( GL_T2F_N3F_V3F, 0, rightUpperLegArrow);
                                             glDrawArrays( GL_TRIANGLES, 0, 12);
                                       glPopMatrix();  
                               }
                              glColor3f(1.0f,1.0f,1.0f);                              
                              glPopMatrix();
