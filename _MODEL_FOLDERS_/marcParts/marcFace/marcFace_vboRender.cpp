
              glUseProgramObjectARB(marcFace_SHADER);
              glUniform1f( UNIFORM_bodyPartSelection, BODY_PART_SELECTION_COLOR_CHANGE);  
              glBindBuffer(GL_ARRAY_BUFFER, marcFace_vboID);
              glLightfv(GL_LIGHT0, GL_AMBIENT,     LightAmbient_marcFace);
              glLightfv(GL_LIGHT0, GL_DIFFUSE,     LightDiffuse_marcFace);
              glLightfv(GL_LIGHT0, GL_SPECULAR,    LightSpecular_marcFace);
              glMaterialfv(GL_FRONT, GL_AMBIENT,   MaterialAmbient_marcFace);
              glMaterialfv(GL_FRONT, GL_DIFFUSE,   MaterialDiffuse_marcFace);
              glMaterialfv(GL_FRONT, GL_EMISSION,  MaterialEmission_marcFace);
              glMaterialfv(GL_FRONT, GL_SPECULAR,  MaterialSpecular_marcFace);
              glMaterialf(GL_FRONT, GL_SHININESS,  MaterialShininess_marcFace);

              glUniform1f( UNIFORM_counter_marcFace, marcFace_counter);

              glEnableClientState(GL_TEXTURE_COORD_ARRAY );
              glEnableClientState(GL_NORMAL_ARRAY);
              glEnableClientState(GL_VERTEX_ARRAY);
              glTexCoordPointer(3, GL_FLOAT, 0, (void*)(sizeof(marcFace_VERT) + sizeof(marcFace_NORM)));
              glNormalPointer(GL_FLOAT, 0, (void*)sizeof(marcFace_VERT));
              glVertexPointer(3, GL_FLOAT, 0, 0);

              //SPECULAR_textureID;
              //SPECULAR_textureID = glGetUniformLocationARB(marcFace_SHADER,"SpecularMap");
              //glUniform1iARB(SPECULAR_textureID, 2);
              //glActiveTextureARB(GL_TEXTURE2_ARB);
              //glBindTexture(GL_TEXTURE_2D,  specularMap[201]);

              DOT3_textureID;
              DOT3_textureID     = glGetUniformLocationARB(marcFace_SHADER,"NormalMap");
              glUniform1iARB(DOT3_textureID, 1);
              glActiveTextureARB(GL_TEXTURE1_ARB);
              glBindTexture(GL_TEXTURE_2D,  normalMap[201]);

              textureID;
              textureID     = glGetUniformLocationARB(marcFace_SHADER,"Texture1");
              glUniform1iARB(textureID, 0);
              glActiveTextureARB(GL_TEXTURE0_ARB);
              glBindTexture(GL_TEXTURE_2D, textureMap[201]);

              //glLightfv(GL_LIGHT0,GL_POSITION,lightPos_marcFace);
              //glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_marcFace);

              glDrawArrays(GL_TRIANGLES, 0, 1761);

              glDisableClientState(GL_VERTEX_ARRAY);
              glDisableClientState(GL_NORMAL_ARRAY);
              glDisableClientState(GL_TEXTURE_COORD_ARRAY);

              glUseProgramObjectARB(0);

