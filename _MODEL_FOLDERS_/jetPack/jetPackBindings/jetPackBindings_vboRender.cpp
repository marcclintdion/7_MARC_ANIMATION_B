              //glTranslatef(jetPackBindings_POSITION[0], jetPackBindings_POSITION[1], jetPackBindings_POSITION[2]);
              //glRotatef(180, 0, 1, 0);//ROTATE_MODEL_TO_ALIGN_Z_AXIS_LIGHTING_WITH_MODEL_TRANSFORMATION_MATRIX
              //glRotatef(spinFloat,rotation_AXIS_jetPackBindings[0], rotation_AXIS_jetPackBindings[1], rotation_AXIS_jetPackBindings[2]);

              //glPushMatrix();
              //       glLoadIdentity();
              //       glRotatef(-spinFloat,-rotation_AXIS_jetPackBindings[0], -rotation_AXIS_jetPackBindings[1], rotation_AXIS_jetPackBindings[2]);
              //       glLightfv(GL_LIGHT0,GL_POSITION,lightPos_jetPackBindings);
              //       glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_jetPackBindings);
              //glPopMatrix();

              glUseProgramObjectARB(jetPackBindings_SHADER);

              glBindBuffer(GL_ARRAY_BUFFER, jetPackBindings_vboID);
              glLightfv(GL_LIGHT0, GL_AMBIENT,     LightAmbient_jetPackBindings);
              glLightfv(GL_LIGHT0, GL_DIFFUSE,     LightDiffuse_jetPackBindings);
              glLightfv(GL_LIGHT0, GL_SPECULAR,    LightSpecular_jetPackBindings);
              glMaterialfv(GL_FRONT, GL_AMBIENT,   MaterialAmbient_jetPackBindings);
              glMaterialfv(GL_FRONT, GL_DIFFUSE,   MaterialDiffuse_jetPackBindings);
              glMaterialfv(GL_FRONT, GL_EMISSION,  MaterialEmission_jetPackBindings);
              glMaterialfv(GL_FRONT, GL_SPECULAR,  MaterialSpecular_jetPackBindings);
              glMaterialf(GL_FRONT, GL_SHININESS,  MaterialShininess_jetPackBindings);

              glUniform1fARB( UNIFORM_counter_jetPackBindings, jetPackBindings_counter);

              glEnableClientState(GL_TEXTURE_COORD_ARRAY );
              glEnableClientState(GL_NORMAL_ARRAY);
              glEnableClientState(GL_VERTEX_ARRAY);
              glTexCoordPointer(3, GL_FLOAT, 0, (void*)(sizeof(jetPackBindings_VERT) + sizeof(jetPackBindings_NORM)));
              glNormalPointer(GL_FLOAT, 0, (void*)sizeof(jetPackBindings_VERT));
              glVertexPointer(3, GL_FLOAT, 0, 0);

              //SPECULAR_textureID;
              //SPECULAR_textureID = glGetUniformLocationARB(jetPackBindings_SHADER,"SpecularMap");
              //glUniform1iARB(SPECULAR_textureID, 2);
              //glActiveTextureARB(GL_TEXTURE2_ARB);
              //glBindTexture(GL_TEXTURE_2D,  specularMap[221]);

              DOT3_textureID;
              DOT3_textureID     = glGetUniformLocationARB(jetPackBindings_SHADER,"NormalMap");
              glUniform1iARB(DOT3_textureID, 1);
              glActiveTextureARB(GL_TEXTURE1_ARB);
              glBindTexture(GL_TEXTURE_2D,  normalMap[221]);

              textureID;
              textureID     = glGetUniformLocationARB(jetPackBindings_SHADER,"Texture1");
              glUniform1iARB(textureID, 0);
              glActiveTextureARB(GL_TEXTURE0_ARB);
              glBindTexture(GL_TEXTURE_2D, textureMap[221]);

              //glLightfv(GL_LIGHT0,GL_POSITION,lightPos_jetPackBindings);
              //glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_jetPackBindings);

              glDrawArrays(GL_TRIANGLES, 0, 384);

              glDisableClientState(GL_VERTEX_ARRAY);
              glDisableClientState(GL_NORMAL_ARRAY);
              glDisableClientState(GL_TEXTURE_COORD_ARRAY);

              glUseProgramObjectARB(0);

