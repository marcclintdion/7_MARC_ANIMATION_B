              //glTranslatef(jetPackMiddleEngines_POSITION[0], jetPackMiddleEngines_POSITION[1], jetPackMiddleEngines_POSITION[2]);
              //glRotatef(180, 0, 1, 0);//ROTATE_MODEL_TO_ALIGN_Z_AXIS_LIGHTING_WITH_MODEL_TRANSFORMATION_MATRIX
              //glRotatef(spinFloat,rotation_AXIS_jetPackMiddleEngines[0], rotation_AXIS_jetPackMiddleEngines[1], rotation_AXIS_jetPackMiddleEngines[2]);

              //glPushMatrix();
              //       glLoadIdentity();
              //       glRotatef(-spinFloat,-rotation_AXIS_jetPackMiddleEngines[0], -rotation_AXIS_jetPackMiddleEngines[1], rotation_AXIS_jetPackMiddleEngines[2]);
              //       glLightfv(GL_LIGHT0,GL_POSITION,lightPos_jetPackMiddleEngines);
              //       glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_jetPackMiddleEngines);
              //glPopMatrix();

              glUseProgramObjectARB(jetPackMiddleEngines_SHADER);

              glBindBuffer(GL_ARRAY_BUFFER, jetPackMiddleEngines_vboID);
              glLightfv(GL_LIGHT0, GL_AMBIENT,     LightAmbient_jetPackMiddleEngines);
              glLightfv(GL_LIGHT0, GL_DIFFUSE,     LightDiffuse_jetPackMiddleEngines);
              glLightfv(GL_LIGHT0, GL_SPECULAR,    LightSpecular_jetPackMiddleEngines);
              glMaterialfv(GL_FRONT, GL_AMBIENT,   MaterialAmbient_jetPackMiddleEngines);
              glMaterialfv(GL_FRONT, GL_DIFFUSE,   MaterialDiffuse_jetPackMiddleEngines);
              glMaterialfv(GL_FRONT, GL_EMISSION,  MaterialEmission_jetPackMiddleEngines);
              glMaterialfv(GL_FRONT, GL_SPECULAR,  MaterialSpecular_jetPackMiddleEngines);
              glMaterialf(GL_FRONT, GL_SHININESS,  MaterialShininess_jetPackMiddleEngines);

              glUniform1fARB( UNIFORM_counter_jetPackMiddleEngines, jetPackMiddleEngines_counter);

              glEnableClientState(GL_TEXTURE_COORD_ARRAY );
              glEnableClientState(GL_NORMAL_ARRAY);
              glEnableClientState(GL_VERTEX_ARRAY);
              glTexCoordPointer(3, GL_FLOAT, 0, (void*)(sizeof(jetPackMiddleEngines_VERT) + sizeof(jetPackMiddleEngines_NORM)));
              glNormalPointer(GL_FLOAT, 0, (void*)sizeof(jetPackMiddleEngines_VERT));
              glVertexPointer(3, GL_FLOAT, 0, 0);

              //SPECULAR_textureID;
              //SPECULAR_textureID = glGetUniformLocationARB(jetPackMiddleEngines_SHADER,"SpecularMap");
              //glUniform1iARB(SPECULAR_textureID, 2);
              //glActiveTextureARB(GL_TEXTURE2_ARB);
              //glBindTexture(GL_TEXTURE_2D,  specularMap[224]);

              DOT3_textureID;
              DOT3_textureID     = glGetUniformLocationARB(jetPackMiddleEngines_SHADER,"NormalMap");
              glUniform1iARB(DOT3_textureID, 1);
              glActiveTextureARB(GL_TEXTURE1_ARB);
              glBindTexture(GL_TEXTURE_2D,  normalMap[224]);

              textureID;
              textureID     = glGetUniformLocationARB(jetPackMiddleEngines_SHADER,"Texture1");
              glUniform1iARB(textureID, 0);
              glActiveTextureARB(GL_TEXTURE0_ARB);
              glBindTexture(GL_TEXTURE_2D, textureMap[224]);

              //glLightfv(GL_LIGHT0,GL_POSITION,lightPos_jetPackMiddleEngines);
              //glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_jetPackMiddleEngines);

              glDrawArrays(GL_TRIANGLES, 0, 651);

              glDisableClientState(GL_VERTEX_ARRAY);
              glDisableClientState(GL_NORMAL_ARRAY);
              glDisableClientState(GL_TEXTURE_COORD_ARRAY);

              glUseProgramObjectARB(0);

