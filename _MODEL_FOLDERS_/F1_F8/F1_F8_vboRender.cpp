

              glUseProgramObjectARB(F1_F8_SHADER);


              glUniform1fARB( UNIFORM_shininess_F1_F8, shininess_F1_F8);
              //------------------------------------------------------

              glUniform1fARB( UNIFORM_counter4_F1_F8, F1_F8_counter4);


              glBindBuffer(GL_ARRAY_BUFFER_ARB, F1_F8_vboID);

              glEnableClientState(GL_TEXTURE_COORD_ARRAY );
              glEnableClientState(GL_NORMAL_ARRAY);
              glEnableClientState(GL_VERTEX_ARRAY);
              glTexCoordPointer(3, GL_FLOAT, 0, (void*)(sizeof(F1_F8_VERT) + sizeof(F1_F8_NORM)));
              glNormalPointer(GL_FLOAT, 0, (void*)sizeof(F1_F8_VERT));
              glVertexPointer(3, GL_FLOAT, 0, 0);

              DOT3_textureID     = glGetUniformLocationARB(F1_F8_SHADER,"NormalMap");
              glUniform1iARB(DOT3_textureID, 1);
              glActiveTextureARB(GL_TEXTURE1_ARB);
              glBindTexture(GL_TEXTURE_2D,  normalMap[573]);

              textureID     = glGetUniformLocationARB(F1_F8_SHADER,"Texture1");
              glUniform1iARB(textureID, 0);
              glActiveTextureARB(GL_TEXTURE0_ARB);
              glBindTexture(GL_TEXTURE_2D, textureMap[573]);

//----------------------------------------------------------------------------------------------------------------------            
             
              glUniform1fARB( UNIFORM_counter1_F1_F8, 0.0);
              glUniform1fARB( UNIFORM_counter2_F1_F8, 0.0);
              glUniform1fARB( UNIFORM_counter3_F1_F8, F1_isSet);                             
              //----------------------------------------------------
              glPushMatrix();
                     glTranslatef(0.0, 0.0, 0.0);               
                     glDrawArrays(GL_TRIANGLES, 0, 30);
              glPopMatrix();

//----------------------------------------------------------------------------------------------------------------------
              
              glUniform1fARB( UNIFORM_counter1_F1_F8, 0.0795004);          //F1_F8_counter1  
              glUniform1fARB( UNIFORM_counter2_F1_F8, 0.0);                //F1_F8_counter2
              glUniform1fARB( UNIFORM_counter3_F1_F8, F2_isSet);              
              //----------------------------------------------------              
              glPushMatrix();
                     glTranslatef(.16, 0.0, 0.0);               
                     glDrawArrays(GL_TRIANGLES, 0, 30);
              glPopMatrix();              

//------------------------------------------------------------------------------------------------------------              
              
              glUniform1fARB( UNIFORM_counter1_F1_F8, 0.161);              //F1_F8_counter1              
              glUniform1fARB( UNIFORM_counter2_F1_F8, 0.0);                //F1_F8_counter2        
              glUniform1fARB( UNIFORM_counter3_F1_F8, F3_isSet);  
              //----------------------------------------------------                         
              glPushMatrix();
                     glTranslatef(.16*2, 0.0, 0.0);               
                     glDrawArrays(GL_TRIANGLES, 0, 30);
              glPopMatrix();                 
              
//------------------------------------------------------------------------------------------------------------          
              
              glUniform1fARB( UNIFORM_counter1_F1_F8, 0.242999);           //F1_F8_counter1              
              glUniform1fARB( UNIFORM_counter2_F1_F8, 0.0);                //F1_F8_counter2         
              glUniform1fARB( UNIFORM_counter3_F1_F8, F4_isSet);  
              //----------------------------------------------------                      
              glPushMatrix();
                     glTranslatef(.16*3, 0.0, 0.0);               
                     glDrawArrays(GL_TRIANGLES, 0, 30);
              glPopMatrix();                 
              
//------------------------------------------------------------------------------------------------------------               
              
              glUniform1fARB( UNIFORM_counter1_F1_F8,  0.0);               //F1_F8_counter1           
              glUniform1fARB( UNIFORM_counter2_F1_F8, -0.036);             //F1_F8_counter2   
              glUniform1fARB( UNIFORM_counter3_F1_F8, F5_isSet);  
              //----------------------------------------------------                       
              glPushMatrix();
                     glTranslatef(.16*4+.05, 0.0, 0.0);               
                     glDrawArrays(GL_TRIANGLES, 0, 30);
              glPopMatrix();                 
              
//------------------------------------------------------------------------------------------------------------               
              
              glUniform1fARB( UNIFORM_counter1_F1_F8,  0.0795004);         //F1_F8_counter1           
              glUniform1fARB( UNIFORM_counter2_F1_F8, -0.036);             //F1_F8_counter2   
              glUniform1fARB( UNIFORM_counter3_F1_F8, F6_isSet);  
              //----------------------------------------------------                       
              glPushMatrix();
                     glTranslatef(.16*5+.05, 0.0, 0.0);               
                     glDrawArrays(GL_TRIANGLES, 0, 30);
              glPopMatrix();                 
              
//------------------------------------------------------------------------------------------------------------                 
              
              glUniform1fARB( UNIFORM_counter1_F1_F8,  0.161);         //F1_F8_counter1           
              glUniform1fARB( UNIFORM_counter2_F1_F8, -0.036);             //F1_F8_counter2   
              glUniform1fARB( UNIFORM_counter3_F1_F8, F7_isSet);  
              //----------------------------------------------------                        
              glPushMatrix();
                     glTranslatef(.16*6+.05, 0.0, 0.0);               
                     glDrawArrays(GL_TRIANGLES, 0, 30);
              glPopMatrix();                 
              
//------------------------------------------------------------------------------------------------------------                 
              
              glUniform1fARB( UNIFORM_counter1_F1_F8,  0.243);         //F1_F8_counter1           
              glUniform1fARB( UNIFORM_counter2_F1_F8, -0.036);             //F1_F8_counter2   
              glUniform1fARB( UNIFORM_counter3_F1_F8, F8_isSet);  
              //----------------------------------------------------                        
              glPushMatrix();
                     glTranslatef(.16*7+.05, 0.0, 0.0);               
                     glDrawArrays(GL_TRIANGLES, 0, 30);
              glPopMatrix();                 
              
//------------------------------------------------------------------------------------------------------------                 
              
              
              
              
              
              
              
              
              
              
              
              glDisableClientState(GL_VERTEX_ARRAY);
              glDisableClientState(GL_NORMAL_ARRAY);
              glDisableClientState(GL_TEXTURE_COORD_ARRAY);

              glUseProgramObjectARB(0);

