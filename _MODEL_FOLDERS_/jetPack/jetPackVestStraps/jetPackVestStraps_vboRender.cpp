              //glTranslatef(jetPackVestStraps_POSITION[0], jetPackVestStraps_POSITION[1], jetPackVestStraps_POSITION[2]);
              //glRotatef(180, 0, 1, 0);//ROTATE_MODEL_TO_ALIGN_Z_AXIS_LIGHTING_WITH_MODEL_TRANSFORMATION_MATRIX
              //glRotatef(spinFloat,rotation_AXIS_jetPackVestStraps[0], rotation_AXIS_jetPackVestStraps[1], rotation_AXIS_jetPackVestStraps[2]);

              //glPushMatrix();
              //       glLoadIdentity();
              //       glRotatef(-spinFloat,-rotation_AXIS_jetPackVestStraps[0], -rotation_AXIS_jetPackVestStraps[1], rotation_AXIS_jetPackVestStraps[2]);
              //       glLightfv(GL_LIGHT0,GL_POSITION,lightPos_jetPackVestStraps);
              //       glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_jetPackVestStraps);
              //glPopMatrix();

              glUseProgramObjectARB(jetPackVestStraps_SHADER);

              glBindBuffer(GL_ARRAY_BUFFER, jetPackVestStraps_vboID);
              glLightfv(GL_LIGHT0, GL_AMBIENT,     LightAmbient_jetPackVestStraps);
              glLightfv(GL_LIGHT0, GL_DIFFUSE,     LightDiffuse_jetPackVestStraps);
              glLightfv(GL_LIGHT0, GL_SPECULAR,    LightSpecular_jetPackVestStraps);
              glMaterialfv(GL_FRONT, GL_AMBIENT,   MaterialAmbient_jetPackVestStraps);
              glMaterialfv(GL_FRONT, GL_DIFFUSE,   MaterialDiffuse_jetPackVestStraps);
              glMaterialfv(GL_FRONT, GL_EMISSION,  MaterialEmission_jetPackVestStraps);
              glMaterialfv(GL_FRONT, GL_SPECULAR,  MaterialSpecular_jetPackVestStraps);
              glMaterialf(GL_FRONT, GL_SHININESS,  MaterialShininess_jetPackVestStraps);

              glUniform1fARB( UNIFORM_counter_jetPackVestStraps, jetPackVestStraps_counter);

              glEnableClientState(GL_TEXTURE_COORD_ARRAY );
              glEnableClientState(GL_NORMAL_ARRAY);
              glEnableClientState(GL_VERTEX_ARRAY);
              glTexCoordPointer(3, GL_FLOAT, 0, (void*)(sizeof(jetPackVestStraps_VERT) + sizeof(jetPackVestStraps_NORM)));
              glNormalPointer(GL_FLOAT, 0, (void*)sizeof(jetPackVestStraps_VERT));
              glVertexPointer(3, GL_FLOAT, 0, 0);

              //SPECULAR_textureID;
              //SPECULAR_textureID = glGetUniformLocationARB(jetPackVestStraps_SHADER,"SpecularMap");
              //glUniform1iARB(SPECULAR_textureID, 2);
              //glActiveTextureARB(GL_TEXTURE2_ARB);
              //glBindTexture(GL_TEXTURE_2D,  specularMap[220]);

              DOT3_textureID;
              DOT3_textureID     = glGetUniformLocationARB(jetPackVestStraps_SHADER,"NormalMap");
              glUniform1iARB(DOT3_textureID, 1);
              glActiveTextureARB(GL_TEXTURE1_ARB);
              glBindTexture(GL_TEXTURE_2D,  normalMap[220]);

              textureID;
              textureID     = glGetUniformLocationARB(jetPackVestStraps_SHADER,"Texture1");
              glUniform1iARB(textureID, 0);
              glActiveTextureARB(GL_TEXTURE0_ARB);
              glBindTexture(GL_TEXTURE_2D, textureMap[220]);

              //glLightfv(GL_LIGHT0,GL_POSITION,lightPos_jetPackVestStraps);
              //glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_jetPackVestStraps);

              glDrawArrays(GL_TRIANGLES, 0, 879);

              glDisableClientState(GL_VERTEX_ARRAY);
              glDisableClientState(GL_NORMAL_ARRAY);
              glDisableClientState(GL_TEXTURE_COORD_ARRAY);

              glUseProgramObjectARB(0);

