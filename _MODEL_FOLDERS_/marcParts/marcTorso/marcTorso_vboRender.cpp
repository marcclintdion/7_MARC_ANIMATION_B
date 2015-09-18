glDisable(GL_BLEND);
              glUseProgramObjectARB(marcTorso_SHADER);
              glUniform1f( UNIFORM_bodyPartSelection, BODY_PART_SELECTION_COLOR_CHANGE);  
              glBindBuffer(GL_ARRAY_BUFFER, marcTorso_vboID);
              glLightfv(GL_LIGHT0, GL_AMBIENT,     LightAmbient_marcTorso);
              glLightfv(GL_LIGHT0, GL_DIFFUSE,     LightDiffuse_marcTorso);
              glLightfv(GL_LIGHT0, GL_SPECULAR,    LightSpecular_marcTorso);
              glMaterialfv(GL_FRONT, GL_AMBIENT,   MaterialAmbient_marcTorso);
              glMaterialfv(GL_FRONT, GL_DIFFUSE,   MaterialDiffuse_marcTorso);
              glMaterialfv(GL_FRONT, GL_EMISSION,  MaterialEmission_marcTorso);
              glMaterialfv(GL_FRONT, GL_SPECULAR,  MaterialSpecular_marcTorso);
              glMaterialf(GL_FRONT, GL_SHININESS,  MaterialShininess_marcTorso);

              glUniform1f( UNIFORM_counter_marcTorso, marcTorso_counter);

              glEnableClientState(GL_TEXTURE_COORD_ARRAY );
              glEnableClientState(GL_NORMAL_ARRAY);
              glEnableClientState(GL_VERTEX_ARRAY);
              glTexCoordPointer(3, GL_FLOAT, 0, (void*)(sizeof(marcTorso_VERT) + sizeof(marcTorso_NORM)));
              glNormalPointer(GL_FLOAT, 0, (void*)sizeof(marcTorso_VERT));
              glVertexPointer(3, GL_FLOAT, 0, 0);

              //SPECULAR_textureID;
              //SPECULAR_textureID = glGetUniformLocationARB(marcTorso_SHADER,"SpecularMap");
              //glUniform1iARB(SPECULAR_textureID, 2);
              //glActiveTextureARB(GL_TEXTURE2_ARB);
              //glBindTexture(GL_TEXTURE_2D,  specularMap[202]);

              DOT3_textureID;
              DOT3_textureID     = glGetUniformLocationARB(marcTorso_SHADER,"NormalMap");
              glUniform1iARB(DOT3_textureID, 1);
              glActiveTextureARB(GL_TEXTURE1_ARB);
              glBindTexture(GL_TEXTURE_2D,  normalMap[202]);

              textureID;
              textureID     = glGetUniformLocationARB(marcTorso_SHADER,"Texture1");
              glUniform1iARB(textureID, 0);
              glActiveTextureARB(GL_TEXTURE0_ARB);
              glBindTexture(GL_TEXTURE_2D, textureMap[202]);

              //glLightfv(GL_LIGHT0,GL_POSITION,lightPos_marcTorso);
              //glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_marcTorso);

              glDrawArrays(GL_TRIANGLES, 0, 972);

              glDisableClientState(GL_VERTEX_ARRAY);
              glDisableClientState(GL_NORMAL_ARRAY);
              glDisableClientState(GL_TEXTURE_COORD_ARRAY);

              glUseProgramObjectARB(0);

