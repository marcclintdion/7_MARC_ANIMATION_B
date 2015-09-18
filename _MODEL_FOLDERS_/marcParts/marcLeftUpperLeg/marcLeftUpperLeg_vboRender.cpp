/*              glTranslatef(marcLeftUpperLeg_POSITION[0], marcLeftUpperLeg_POSITION[1], marcLeftUpperLeg_POSITION[2]);
              glRotatef(180, 0, 1, 0);//ROTATE_MODEL_TO_ALIGN_Z_AXIS_LIGHTING_WITH_MODEL_TRANSFORMATION_MATRIX
              glRotatef(spinFloat,rotation_AXIS_marcLeftUpperLeg[0], rotation_AXIS_marcLeftUpperLeg[1], rotation_AXIS_marcLeftUpperLeg[2]);

              glPushMatrix();
                     glLoadIdentity();
                     glRotatef(-spinFloat,-rotation_AXIS_marcLeftUpperLeg[0], -rotation_AXIS_marcLeftUpperLeg[1], rotation_AXIS_marcLeftUpperLeg[2]);
                     glLightfv(GL_LIGHT0,GL_POSITION,lightPos_marcLeftUpperLeg);
                     glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_marcLeftUpperLeg);
              glPopMatrix();              
*/
              glUseProgramObjectARB(marcTorso_SHADER);
              glUniform1fARB( UNIFORM_bodyPartSelection, BODY_PART_SELECTION_COLOR_CHANGE);  
              glBindBuffer(GL_ARRAY_BUFFER, marcLeftUpperLeg_vboID);
              glLightfv(GL_LIGHT0, GL_AMBIENT,     LightAmbient_marcTorso);
              glLightfv(GL_LIGHT0, GL_DIFFUSE,     LightDiffuse_marcTorso);
              glLightfv(GL_LIGHT0, GL_SPECULAR,    LightSpecular_marcTorso);
              glMaterialfv(GL_FRONT, GL_AMBIENT,   MaterialAmbient_marcTorso);
              glMaterialfv(GL_FRONT, GL_DIFFUSE,   MaterialDiffuse_marcTorso);
              glMaterialfv(GL_FRONT, GL_EMISSION,  MaterialEmission_marcTorso);
              glMaterialfv(GL_FRONT, GL_SPECULAR,  MaterialSpecular_marcTorso);
              glMaterialf(GL_FRONT, GL_SHININESS,  MaterialShininess_marcTorso);

              glUniform1fARB( UNIFORM_counter_marcTorso, marcTorso_counter);

              glEnableClientState(GL_TEXTURE_COORD_ARRAY );
              glEnableClientState(GL_NORMAL_ARRAY);
              glEnableClientState(GL_VERTEX_ARRAY);
              glTexCoordPointer(3, GL_FLOAT, 0, (void*)(sizeof(marcLeftUpperLeg_VERT) + sizeof(marcLeftUpperLeg_NORM)));
              glNormalPointer(GL_FLOAT, 0, (void*)sizeof(marcLeftUpperLeg_VERT));
              glVertexPointer(3, GL_FLOAT, 0, 0);

              //SPECULAR_textureID;
              //SPECULAR_textureID = glGetUniformLocationARB(marcLeftUpperLeg_SHADER,"SpecularMap");
              //glUniform1iARB(SPECULAR_textureID, 2);
              //glActiveTextureARB(GL_TEXTURE2_ARB);
              //glBindTexture(GL_TEXTURE_2D,  specularMap[209]);

              DOT3_textureID;
              DOT3_textureID     = glGetUniformLocationARB(marcLeftUpperLeg_SHADER,"NormalMap");
              glUniform1iARB(DOT3_textureID, 1);
              glActiveTextureARB(GL_TEXTURE1_ARB);
              glBindTexture(GL_TEXTURE_2D,  normalMap[209]);

              textureID;
              textureID     = glGetUniformLocationARB(marcLeftUpperLeg_SHADER,"Texture1");
              glUniform1iARB(textureID, 0);
              glActiveTextureARB(GL_TEXTURE0_ARB);
              glBindTexture(GL_TEXTURE_2D, textureMap[209]);

              //glLightfv(GL_LIGHT0,GL_POSITION,lightPos_marcLeftUpperLeg);
              //glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_marcLeftUpperLeg);

              glDrawArrays(GL_TRIANGLES, 0, 282);

              glDisableClientState(GL_VERTEX_ARRAY);
              glDisableClientState(GL_NORMAL_ARRAY);
              glDisableClientState(GL_TEXTURE_COORD_ARRAY);

              glUseProgramObjectARB(0);
