glPushMatrix();
              glTranslatef(keyboardRight_POSITION[0], keyboardRight_POSITION[1], keyboardRight_POSITION[2]);
              glRotatef(keyboardRight_ROTATION[3],keyboardRight_ROTATION[0], keyboardRight_ROTATION[1], keyboardRight_ROTATION[2]);

                   glPushMatrix();
                   glLoadIdentity();
                   //_ADDITIONAL_ROTATIONS_GO_HERE
                   glRotatef(-keyboardRight_ROTATION[3],keyboardRight_ROTATION[0], keyboardRight_ROTATION[1], keyboardRight_ROTATION[2]);

                   glRotatef(-look_LEFT_RIGHT, 0, 1, 0);
                   glTranslatef(-eyePosition[0],-eyePosition[1],-eyePosition[2]);
                   glLightfv(GL_LIGHT0,GL_POSITION,lightPos_keyboardRight);
                   glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_keyboardRight);
                    glPopMatrix();

glPopMatrix();

              glUseProgramObjectARB(keyboardRight_SHADER);


              glUniform1fARB( UNIFORM_shininess_keyboardRight, shininess_keyboardRight);

              //---------
              glUniform1fARB( UNIFORM_counter1_keyboardRight, keyboardRight_counter1);
              glUniform1fARB( UNIFORM_counter2_keyboardRight, keyboardRight_counter2);
              glUniform1fARB( UNIFORM_counter3_keyboardRight, keyboardRight_counter3);
              glUniform1fARB( UNIFORM_counter4_keyboardRight, keyboardRight_counter4);


              glBindBufferARB(GL_ARRAY_BUFFER_ARB, keyboardRight_vboID);

              glEnableClientState(GL_TEXTURE_COORD_ARRAY );
              glEnableClientState(GL_NORMAL_ARRAY);
              glEnableClientState(GL_VERTEX_ARRAY);
              glTexCoordPointer(3, GL_FLOAT, 0, (void*)(sizeof(keyboardRight_VERT) + sizeof(keyboardRight_NORM)));
              glNormalPointer(GL_FLOAT, 0, (void*)sizeof(keyboardRight_VERT));
              glVertexPointer(3, GL_FLOAT, 0, 0);

            //Texture3_textureID = glGetUniformLocationARB(keyboardRight_SHADER,"Texture3");
            //glUniform1iARB(Texture3_textureID, 2);
            //glActiveTextureARB(GL_TEXTURE2_ARB);
            //glBindTexture(GL_TEXTURE_2D,  specularMap[601]);

              DOT3_textureID     = glGetUniformLocationARB(keyboardRight_SHADER,"NormalMap");
              glUniform1iARB(DOT3_textureID, 1);
              glActiveTextureARB(GL_TEXTURE1_ARB);
              glBindTexture(GL_TEXTURE_2D,  normalMap[601]);

              textureID     = glGetUniformLocationARB(keyboardRight_SHADER,"Texture1");
              glUniform1iARB(textureID, 0);
              glActiveTextureARB(GL_TEXTURE0_ARB);
              glBindTexture(GL_TEXTURE_2D, textureMap[601]);


              glDrawArrays(GL_TRIANGLES, 0, 6);


              glDisableClientState(GL_VERTEX_ARRAY);
              glDisableClientState(GL_NORMAL_ARRAY);
              glDisableClientState(GL_TEXTURE_COORD_ARRAY);

              glUseProgramObjectARB(0);

