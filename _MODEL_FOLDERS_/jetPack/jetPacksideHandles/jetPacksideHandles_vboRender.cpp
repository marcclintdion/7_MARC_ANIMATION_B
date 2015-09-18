              //glTranslatef(jetPacksideHandles_POSITION[0], jetPacksideHandles_POSITION[1], jetPacksideHandles_POSITION[2]);
              //glRotatef(180, 0, 1, 0);//ROTATE_MODEL_TO_ALIGN_Z_AXIS_LIGHTING_WITH_MODEL_TRANSFORMATION_MATRIX
              //glRotatef(spinFloat,rotation_AXIS_jetPacksideHandles[0], rotation_AXIS_jetPacksideHandles[1], rotation_AXIS_jetPacksideHandles[2]);

              //glPushMatrix();
              //       glLoadIdentity();
              //       glRotatef(-spinFloat,-rotation_AXIS_jetPacksideHandles[0], -rotation_AXIS_jetPacksideHandles[1], rotation_AXIS_jetPacksideHandles[2]);
              //       glLightfv(GL_LIGHT0,GL_POSITION,lightPos_jetPacksideHandles);
              //       glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_jetPacksideHandles);
              //glPopMatrix();

              glUseProgramObjectARB(jetPacksideHandles_SHADER);

              glBindBuffer(GL_ARRAY_BUFFER, jetPacksideHandles_vboID);
              glLightfv(GL_LIGHT0, GL_AMBIENT,     LightAmbient_jetPacksideHandles);
              glLightfv(GL_LIGHT0, GL_DIFFUSE,     LightDiffuse_jetPacksideHandles);
              glLightfv(GL_LIGHT0, GL_SPECULAR,    LightSpecular_jetPacksideHandles);
              glMaterialfv(GL_FRONT, GL_AMBIENT,   MaterialAmbient_jetPacksideHandles);
              glMaterialfv(GL_FRONT, GL_DIFFUSE,   MaterialDiffuse_jetPacksideHandles);
              glMaterialfv(GL_FRONT, GL_EMISSION,  MaterialEmission_jetPacksideHandles);
              glMaterialfv(GL_FRONT, GL_SPECULAR,  MaterialSpecular_jetPacksideHandles);
              glMaterialf(GL_FRONT, GL_SHININESS,  MaterialShininess_jetPacksideHandles);

              glUniform1fARB( UNIFORM_counter_jetPacksideHandles, jetPacksideHandles_counter);

              glEnableClientState(GL_TEXTURE_COORD_ARRAY );
              glEnableClientState(GL_NORMAL_ARRAY);
              glEnableClientState(GL_VERTEX_ARRAY);
              glTexCoordPointer(3, GL_FLOAT, 0, (void*)(sizeof(jetPacksideHandles_VERT) + sizeof(jetPacksideHandles_NORM)));
              glNormalPointer(GL_FLOAT, 0, (void*)sizeof(jetPacksideHandles_VERT));
              glVertexPointer(3, GL_FLOAT, 0, 0);

              //SPECULAR_textureID;
              //SPECULAR_textureID = glGetUniformLocationARB(jetPacksideHandles_SHADER,"SpecularMap");
              //glUniform1iARB(SPECULAR_textureID, 2);
              //glActiveTextureARB(GL_TEXTURE2_ARB);
              //glBindTexture(GL_TEXTURE_2D,  specularMap[222]);

              DOT3_textureID;
              DOT3_textureID     = glGetUniformLocationARB(jetPacksideHandles_SHADER,"NormalMap");
              glUniform1iARB(DOT3_textureID, 1);
              glActiveTextureARB(GL_TEXTURE1_ARB);
              glBindTexture(GL_TEXTURE_2D,  normalMap[222]);

              textureID;
              textureID     = glGetUniformLocationARB(jetPacksideHandles_SHADER,"Texture1");
              glUniform1iARB(textureID, 0);
              glActiveTextureARB(GL_TEXTURE0_ARB);
              glBindTexture(GL_TEXTURE_2D, textureMap[222]);

              //glLightfv(GL_LIGHT0,GL_POSITION,lightPos_jetPacksideHandles);
              //glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_jetPacksideHandles);

              glDrawArrays(GL_TRIANGLES, 0, 300);

              glDisableClientState(GL_VERTEX_ARRAY);
              glDisableClientState(GL_NORMAL_ARRAY);
              glDisableClientState(GL_TEXTURE_COORD_ARRAY);

              glUseProgramObjectARB(0);

