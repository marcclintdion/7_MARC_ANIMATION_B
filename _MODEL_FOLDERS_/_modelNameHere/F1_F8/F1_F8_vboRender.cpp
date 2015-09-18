//glPushMatrix();
              glTranslatef(moveSet[0], moveSet[1], moveSet[2]);                                                
              glTranslatef(F1_F8_POSITION[0], F1_F8_POSITION[1], F1_F8_POSITION[2]);
              glRotatef(rotation_AXIS_F1_F8[3],rotation_AXIS_F1_F8[0], rotation_AXIS_F1_F8[1], rotation_AXIS_F1_F8[2]);

              glPushMatrix();
                   glLoadIdentity();
                //_ADDITIONAL_ROTATIONS_GO_HERE
                   glRotatef(-rotation_AXIS_F1_F8[3],rotation_AXIS_F1_F8[0], rotation_AXIS_F1_F8[1], rotation_AXIS_F1_F8[2]);

                   glRotatef(-look_LEFT_RIGHT, 0, -1, 0);
                   glTranslatef(-eyePosition[0],-eyePosition[1],-eyePosition[2]);
                   glLightfv(GL_LIGHT0,GL_POSITION,lightPos_F1_F8);
                   glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_F1_F8);
              glPopMatrix();

//glPopMatrix();

              glUseProgramObjectARB(F1_F8_SHADER);


              glUniform1fARB( UNIFORM_shininess_F1_F8, shininess_F1_F8);
              glUniform1fARB( UNIFORM_counter1_F1_F8, F1_F8_counter1);
              glUniform1fARB( UNIFORM_counter2_F1_F8, F1_F8_counter2);
              glUniform1fARB( UNIFORM_counter3_F1_F8, F1_F8_counter3);
              glUniform1fARB( UNIFORM_counter4_F1_F8, F1_F8_counter4);


              glBindBufferARB(GL_ARRAY_BUFFER_ARB, F1_F8_vboID);

              glEnableClientState(GL_TEXTURE_COORD_ARRAY );
              glEnableClientState(GL_NORMAL_ARRAY);
              glEnableClientState(GL_VERTEX_ARRAY);
              glTexCoordPointer(3, GL_FLOAT, 0, (void*)(sizeof(F1_F8_VERT) + sizeof(F1_F8_NORM)));
              glNormalPointer(GL_FLOAT, 0, (void*)sizeof(F1_F8_VERT));
              glVertexPointer(3, GL_FLOAT, 0, 0);

            //Texture3_textureID = glGetUniformLocationARB(F1_F8_SHADER,"Texture3");
            //glUniform1iARB(Texture3_textureID, 2);
            //glActiveTextureARB(GL_TEXTURE2_ARB);
            //glBindTexture(GL_TEXTURE_2D,  specularMap[573]);

              DOT3_textureID     = glGetUniformLocationARB(F1_F8_SHADER,"NormalMap");
              glUniform1iARB(DOT3_textureID, 1);
              glActiveTextureARB(GL_TEXTURE1_ARB);
              glBindTexture(GL_TEXTURE_2D,  normalMap[573]);

              textureID     = glGetUniformLocationARB(F1_F8_SHADER,"Texture1");
              glUniform1iARB(textureID, 0);
              glActiveTextureARB(GL_TEXTURE0_ARB);
              glBindTexture(GL_TEXTURE_2D, textureMap[573]);


              glDrawArrays(GL_TRIANGLES, 0, 30);


              glDisableClientState(GL_VERTEX_ARRAY);
              glDisableClientState(GL_NORMAL_ARRAY);
              glDisableClientState(GL_TEXTURE_COORD_ARRAY);

              glUseProgramObjectARB(0);

