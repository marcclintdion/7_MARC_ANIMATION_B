              //glTranslatef(jetPackNozzels_POSITION[0], jetPackNozzels_POSITION[1], jetPackNozzels_POSITION[2]);
              //glRotatef(180, 0, 1, 0);//ROTATE_MODEL_TO_ALIGN_Z_AXIS_LIGHTING_WITH_MODEL_TRANSFORMATION_MATRIX
              //glRotatef(spinFloat,rotation_AXIS_jetPackNozzels[0], rotation_AXIS_jetPackNozzels[1], rotation_AXIS_jetPackNozzels[2]);

              //glPushMatrix();
              //       glLoadIdentity();
              //       glRotatef(-spinFloat,-rotation_AXIS_jetPackNozzels[0], -rotation_AXIS_jetPackNozzels[1], rotation_AXIS_jetPackNozzels[2]);
              //       glLightfv(GL_LIGHT0,GL_POSITION,lightPos_jetPackNozzels);
              //       glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_jetPackNozzels);
              //glPopMatrix();

              glUseProgramObjectARB(jetPackNozzels_SHADER);

              glBindBuffer(GL_ARRAY_BUFFER, jetPackNozzels_vboID);
              glLightfv(GL_LIGHT0, GL_AMBIENT,     LightAmbient_jetPackNozzels);
              glLightfv(GL_LIGHT0, GL_DIFFUSE,     LightDiffuse_jetPackNozzels);
              glLightfv(GL_LIGHT0, GL_SPECULAR,    LightSpecular_jetPackNozzels);
              glMaterialfv(GL_FRONT, GL_AMBIENT,   MaterialAmbient_jetPackNozzels);
              glMaterialfv(GL_FRONT, GL_DIFFUSE,   MaterialDiffuse_jetPackNozzels);
              glMaterialfv(GL_FRONT, GL_EMISSION,  MaterialEmission_jetPackNozzels);
              glMaterialfv(GL_FRONT, GL_SPECULAR,  MaterialSpecular_jetPackNozzels);
              glMaterialf(GL_FRONT, GL_SHININESS,  MaterialShininess_jetPackNozzels);

              glUniform1fARB( UNIFORM_counter_jetPackNozzels, jetPackNozzels_counter);

              glEnableClientState(GL_TEXTURE_COORD_ARRAY );
              glEnableClientState(GL_NORMAL_ARRAY);
              glEnableClientState(GL_VERTEX_ARRAY);
              glTexCoordPointer(3, GL_FLOAT, 0, (void*)(sizeof(jetPackNozzels_VERT) + sizeof(jetPackNozzels_NORM)));
              glNormalPointer(GL_FLOAT, 0, (void*)sizeof(jetPackNozzels_VERT));
              glVertexPointer(3, GL_FLOAT, 0, 0);

              //SPECULAR_textureID;
              //SPECULAR_textureID = glGetUniformLocationARB(jetPackNozzels_SHADER,"SpecularMap");
              //glUniform1iARB(SPECULAR_textureID, 2);
              //glActiveTextureARB(GL_TEXTURE2_ARB);
              //glBindTexture(GL_TEXTURE_2D,  specularMap[223]);

              DOT3_textureID;
              DOT3_textureID     = glGetUniformLocationARB(jetPackNozzels_SHADER,"NormalMap");
              glUniform1iARB(DOT3_textureID, 1);
              glActiveTextureARB(GL_TEXTURE1_ARB);
              glBindTexture(GL_TEXTURE_2D,  normalMap[223]);

              textureID;
              textureID     = glGetUniformLocationARB(jetPackNozzels_SHADER,"Texture1");
              glUniform1iARB(textureID, 0);
              glActiveTextureARB(GL_TEXTURE0_ARB);
              glBindTexture(GL_TEXTURE_2D, textureMap[223]);

              //glLightfv(GL_LIGHT0,GL_POSITION,lightPos_jetPackNozzels);
              //glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_jetPackNozzels);

              glDrawArrays(GL_TRIANGLES, 0, 420);

              glDisableClientState(GL_VERTEX_ARRAY);
              glDisableClientState(GL_NORMAL_ARRAY);
              glDisableClientState(GL_TEXTURE_COORD_ARRAY);

              glUseProgramObjectARB(0);

