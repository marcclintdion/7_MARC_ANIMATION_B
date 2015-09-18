/*        glColor4f(0.4, 0.4, 0.4, 1.0);                                                                                                      

/*       glPushMatrix();                                                                                                                      

             glTranslatef(moveSet[0], -moveSet[2], 0.0f);                                                                                     
             glTranslatef(F1_F8_ShadowsPosition_00[0]+F1_F8_POSITION[0], F1_F8_ShadowsPosition_00[1]+F1_F8_POSITION[1], F1_F8_ShadowsPosition_00[2]+F1_F8_POSITION[2]); 
             glRotatef(rotation_AXIS_F1_F8[3],rotation_AXIS_F1_F8[0], rotation_AXIS_F1_F8[1], rotation_AXIS_F1_F8[2]);                        
             glRotatef(F1_F8_ShadowsRotationUP_DOWN_00, 1, 0, 0);                                                                             
             glRotatef(F1_F8_ShadowsRotationLEFT_RIGHT_00, 0, 0, 1);                                                                          
             glScalef(scale_F1_F8_Shadow_00, 0.0, scale_F1_F8_Shadow_00);                                                                     
         glPopMatrix();*/                                                                                                                     

             glBindBufferARB(GL_ARRAY_BUFFER_ARB, F1_F8_vboID);                                                                               

             glEnableClientState(GL_TEXTURE_COORD_ARRAY );                                                                                    
             glEnableClientState(GL_NORMAL_ARRAY);                                                                                            
             glEnableClientState(GL_VERTEX_ARRAY);                                                                                            
             glTexCoordPointer(3, GL_FLOAT, 0, (void*)(sizeof(F1_F8_VERT) + sizeof(F1_F8_NORM)));                                             
             glNormalPointer(GL_FLOAT, 0, (void*)sizeof(F1_F8_VERT));                                                                         
             glVertexPointer(3, GL_FLOAT, 0, 0);                                                                                              

             glDrawArrays(GL_TRIANGLES, 0, 30);                                                                  

             glDisableClientState(GL_VERTEX_ARRAY);                                                                                           
             glDisableClientState(GL_NORMAL_ARRAY);                                                                                           
             glDisableClientState(GL_TEXTURE_COORD_ARRAY);                                                                                    

