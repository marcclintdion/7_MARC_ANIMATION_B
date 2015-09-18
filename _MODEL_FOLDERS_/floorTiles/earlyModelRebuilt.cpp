
glPushMatrix(); 
       
       glBindBufferARB(GL_ARRAY_BUFFER_ARB, tiles_1_vboID);
                   
       glEnableClientState(GL_TEXTURE_COORD_ARRAY );                 
       glEnableClientState(GL_NORMAL_ARRAY);
       glEnableClientState(GL_VERTEX_ARRAY);
            
          
       glTexCoordPointer(3, GL_FLOAT, 0, (void*)(sizeof(tiles_1_VERT) + sizeof(tiles_1_NORM)));              
       glNormalPointer(GL_FLOAT, 0, (void*)sizeof(tiles_1_VERT));
       glVertexPointer(3, GL_FLOAT, 0, 0);

                              glUseProgramObjectARB(tiles_FBO_shadows);
                      
                                      
                                      
                                      shadows_offset_X = - .4 + shadows_TextureDisplacement_X*.1;
                                      shadows_offset_Y = - .4 + shadows_TextureDisplacement_Y*.1;                                     
                                      
                                      glUniform1fARB( UNIFORM_offset_X_tiles_1, shadows_offset_X); 
                                      glUniform1fARB( UNIFORM_offset_Y_tiles_1, shadows_offset_Y);
                                      glUniform1fARB( UNIFORM_counter, tilesCounter);                                                                            
                                      
                                      SPECULAR_textureID;
                                      SPECULAR_textureID = glGetUniformLocationARB(tiles_FBO_shadows,"SpecularMap");
                                      glUniform1iARB(SPECULAR_textureID, 2);
                                      glActiveTextureARB(GL_TEXTURE2_ARB);
                                      glBindTexture(GL_TEXTURE_2D,  textureMap[2]);
                                      
                                      DOT3_textureID;
                                      DOT3_textureID = glGetUniformLocationARB(tiles_FBO_shadows,"NormalMap");
                                      glUniform1iARB(DOT3_textureID,1);
                                      glActiveTextureARB(GL_TEXTURE1_ARB);
                                      glBindTexture(GL_TEXTURE_2D, normalMap[180]);
                                      
                                      glActiveTextureARB(GL_TEXTURE0_ARB);
	                                  
                                      glBindTexture(GL_TEXTURE_2D, textureMap[180]);//____shaderParameters-->>>___RGB_tex   
                                      glPushMatrix();
                                         glLoadIdentity();
                                         glRotatef(-look_LEFT_RIGHT, 0, -1, 0);
                                         glTranslatef(-eyePosition[0],-eyePosition[1],-eyePosition[2]);
                                         glLightfv (GL_LIGHT0,GL_POSITION,lightPos_tiles_1);
                                         glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION,  quadraticAttenuation_tiles_1);  
                                      glPopMatrix();
                                      
                                      glDrawArrays(GL_TRIANGLES, 0, 30);
      
glPopMatrix();            

glPushMatrix();       
      
                   


                              glTranslatef(2,0,0);
                              
                                    
                                      
                                      shadows_offset_X = -.5 + shadows_TextureDisplacement_X*.1;
                                      shadows_offset_Y = -.4 + shadows_TextureDisplacement_Y*.1;                                       
                                      glUniform1fARB( UNIFORM_offset_X_tiles_1, shadows_offset_X); 
                                      glUniform1fARB( UNIFORM_offset_Y_tiles_1, shadows_offset_Y);
                                     
                                      
                                         
                                      DOT3_textureID;//______________________shaderParameters-->>>___DOT3_tex
                                      DOT3_textureID = glGetUniformLocationARB(tiles_FBO_shadows,"NormalMap");//DOT3_tex
                                      
                                      glUniform1iARB(DOT3_textureID,1);//________shaderParameters-->>>___DOT3_tex
                                      glActiveTextureARB(GL_TEXTURE1_ARB);//_____shaderParameters-->>>___DOT3_tex
                                      glBindTexture(GL_TEXTURE_2D, normalMap[180]);//___shaderParameters-->>>___DOT3_tex
                                      glEnableClientState(GL_TEXTURE_COORD_ARRAY);
                                      
                                      glActiveTextureARB(GL_TEXTURE0_ARB);//_____shaderParameters-->>>___RGB_tex
	                                  
                                      glBindTexture(GL_TEXTURE_2D, textureMap[181]);//____shaderParameters-->>>___RGB_tex   
                                      
                                      glDrawArrays(GL_TRIANGLES, 0, 30);
                            
          
      
glPopMatrix();            

glPushMatrix();        
    
                   


                              glTranslatef(-2,0,0);
                                  
                                      
                                      
                                      shadows_offset_X = - .3 + shadows_TextureDisplacement_X*.1;
                                      shadows_offset_Y = - .4 + shadows_TextureDisplacement_Y*.1;                                       
                                      glUniform1fARB( UNIFORM_offset_X_tiles_1, shadows_offset_X); 
                                      glUniform1fARB( UNIFORM_offset_Y_tiles_1, shadows_offset_Y);
  
                                      
                                      DOT3_textureID;//______________________shaderParameters-->>>___DOT3_tex
                                      DOT3_textureID = glGetUniformLocationARB(tiles_FBO_shadows,"NormalMap");//DOT3_tex
                                      
                                      glUniform1iARB(DOT3_textureID,1);//________shaderParameters-->>>___DOT3_tex
                                      glActiveTextureARB(GL_TEXTURE1_ARB);//_____shaderParameters-->>>___DOT3_tex
                                      glBindTexture(GL_TEXTURE_2D, normalMap[180]);//___shaderParameters-->>>___DOT3_tex
                                      glEnableClientState(GL_TEXTURE_COORD_ARRAY);
                                      
                                      glActiveTextureARB(GL_TEXTURE0_ARB);//_____shaderParameters-->>>___RGB_tex
	                                  
                                      glBindTexture(GL_TEXTURE_2D, textureMap[182]);//____shaderParameters-->>>___RGB_tex   
                                      
                                      glDrawArrays(GL_TRIANGLES, 0, 30);
      
glPopMatrix();            

glPushMatrix();        


                              glTranslatef(2,0,2);
                              
                                       
                                      
                                      shadows_offset_X = -0.5 + shadows_TextureDisplacement_X*.1;
                                      shadows_offset_Y = -0.3 + shadows_TextureDisplacement_Y*.1;                                       
                                      glUniform1fARB( UNIFORM_offset_X_tiles_1, shadows_offset_X); 
                                      glUniform1fARB( UNIFORM_offset_Y_tiles_1, shadows_offset_Y);
                                                                            
                                      DOT3_textureID;//______________________shaderParameters-->>>___DOT3_tex
                                      DOT3_textureID = glGetUniformLocationARB(tiles_FBO_shadows,"NormalMap");//DOT3_tex
                                      
                                      glUniform1iARB(DOT3_textureID,1);//________shaderParameters-->>>___DOT3_tex
                                      glActiveTextureARB(GL_TEXTURE1_ARB);//_____shaderParameters-->>>___DOT3_tex
                                      glBindTexture(GL_TEXTURE_2D, normalMap[180]);//___shaderParameters-->>>___DOT3_tex
                                      glEnableClientState(GL_TEXTURE_COORD_ARRAY);
                                      
                                      glActiveTextureARB(GL_TEXTURE0_ARB);//_____shaderParameters-->>>___RGB_tex
	                                  
                                      glBindTexture(GL_TEXTURE_2D, textureMap[183]);//____shaderParameters-->>>___RGB_tex   
                                      
                                      glDrawArrays(GL_TRIANGLES, 0, 30);
      
glPopMatrix();            

glPushMatrix();        


                              glTranslatef(-2,0,2);
                                     
                                      
                                      shadows_offset_X = -0.3 + shadows_TextureDisplacement_X*.1;
                                      shadows_offset_Y = -0.3 + shadows_TextureDisplacement_Y*.1;                                      
                                      glUniform1fARB( UNIFORM_offset_X_tiles_1, shadows_offset_X); 
                                      glUniform1fARB( UNIFORM_offset_Y_tiles_1, shadows_offset_Y);                                      
                                      
                                      DOT3_textureID;//______________________shaderParameters-->>>___DOT3_tex
                                      DOT3_textureID = glGetUniformLocationARB(tiles_FBO_shadows,"NormalMap");//DOT3_tex
                                      
                                      glUniform1iARB(DOT3_textureID,1);//________shaderParameters-->>>___DOT3_tex
                                      glActiveTextureARB(GL_TEXTURE1_ARB);//_____shaderParameters-->>>___DOT3_tex
                                      glBindTexture(GL_TEXTURE_2D, normalMap[180]);//___shaderParameters-->>>___DOT3_tex
                                      glEnableClientState(GL_TEXTURE_COORD_ARRAY);
                                      
                                      glActiveTextureARB(GL_TEXTURE0_ARB);//_____shaderParameters-->>>___RGB_tex
	                                  
                                      glBindTexture(GL_TEXTURE_2D, textureMap[184]);//____shaderParameters-->>>___RGB_tex   
                                      
                                      glDrawArrays(GL_TRIANGLES, 0, 30);
      
glPopMatrix();            

glPushMatrix();        

                          
                              glTranslatef(0,0,2);
                                 
                                      
                                      
                                      shadows_offset_X = -0.4 + shadows_TextureDisplacement_X*.1;
                                      shadows_offset_Y = -0.3 + shadows_TextureDisplacement_Y*.1;                                      
                                      glUniform1fARB( UNIFORM_offset_X_tiles_1, shadows_offset_X); 
                                      glUniform1fARB( UNIFORM_offset_Y_tiles_1, shadows_offset_Y);                                      
                                      
                                      DOT3_textureID;//______________________shaderParameters-->>>___DOT3_tex
                                      DOT3_textureID = glGetUniformLocationARB(tiles_FBO_shadows,"NormalMap");//DOT3_tex
                                      
                                      glUniform1iARB(DOT3_textureID,1);//________shaderParameters-->>>___DOT3_tex
                                      glActiveTextureARB(GL_TEXTURE1_ARB);//_____shaderParameters-->>>___DOT3_tex
                                      glBindTexture(GL_TEXTURE_2D, normalMap[180]);//___shaderParameters-->>>___DOT3_tex
                                      glEnableClientState(GL_TEXTURE_COORD_ARRAY);
                                      
                                      glActiveTextureARB(GL_TEXTURE0_ARB);//_____shaderParameters-->>>___RGB_tex
	                                  
                                      glBindTexture(GL_TEXTURE_2D, textureMap[185]);//____shaderParameters-->>>___RGB_tex   
                                      
                                      glDrawArrays(GL_TRIANGLES, 0, 30);
       
glPopMatrix();            

