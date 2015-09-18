    //############################################################################################################################################################            
    glUseProgram(iconPlates_x4_SHADER);                                                                                                                                                
    glBindBuffer(GL_ARRAY_BUFFER, iconPlates_x4_VBO);                                                                                                                                  
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__MODEL             
    LoadIdentity(modelView);                                                                                                                                                  
    Translate(modelView, iconPlates_x4_POSITION[0], iconPlates_x4_POSITION[1], iconPlates_x4_POSITION[2]);                                                                                   
    Rotate(modelView, iconPlates_x4_ROTATE[0], iconPlates_x4_ROTATE[1], iconPlates_x4_ROTATE[2], iconPlates_x4_ROTATE[3]);//--MODEL                                                                               
    MultiplyMatrix(mvpMatrix, projection, modelView);                                                                                                                         
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__LIGHT             
    LoadIdentity(lightMatrix);                                                                                                                                                
    InvertMatrix(lightMatrix, modelView);                                                                                                                                     
  //Translate(lightMatrix, 1.0, -10.0, 2.0);                                                                                                                                  
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__ATTRIBUTES        
    glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(0));                                                                                                  
    glEnableVertexAttribArray(0);	                                                                                                                                          
    glVertexAttribPointer(1,   2, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(12));                                                                                                 
    glEnableVertexAttribArray(1);                                                                                                                                             
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__UNIFORMS          
    glUniform4f(UNIFORM_LIGHT_POSITION_01_iconPlates_x4, iconPlates_x4_LIGHT_POSITION[0], iconPlates_x4_LIGHT_POSITION[1], iconPlates_x4_LIGHT_POSITION[2], iconPlates_x4_LIGHT_POSITION[3]);                  
    glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ,   1,0,  mvpMatrix);                                                                                                             
    glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX,    1,0,  lightMatrix);                                                                                                           
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__TEXTURES          
    glActiveTextureARB ( GL_TEXTURE1 );                                                                                                                                          
    glBindTexture(GL_TEXTURE_2D, iconPlates_x4_NORMAL_TEX);                                                                                                                               
    glUniform1i (UNIFORM_TEXTURE_DOT3_iconPlates_x4, 1);                                                                                                                                    
    //---                                                                                                                                                                     
    glActiveTextureARB (GL_TEXTURE0);                                                                                                                                            
    glBindTexture(GL_TEXTURE_2D, iconPlates_x4_TEXTURE1);                                                                                                                              
    glUniform1i (UNIFORM_TEXTURE_iconPlates_x4, 0 );                                                                                                                                        
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__DRAW              
    glDrawArrays(GL_TRIANGLES, 0,  6);                                                                                                                                       
    //############################################################################################################################################################            
    glDisableVertexAttribArray(0);	                                                                                                                                          
    glDisableVertexAttribArray(1); 
