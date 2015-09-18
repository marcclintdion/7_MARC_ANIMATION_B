/*glPushMatrix();

   glTranslatef(moveSet[0], -moveSet[2], 0.0f);  
   glTranslatef(keyboardRight_ShadowsPosition_01[0], keyboardRight_ShadowsPosition_01[1], keyboardRight_ShadowsPosition_01[2]); 
   glRotatef(keyboardRight_ShadowsRotationUP_DOWN_01, 1, 0, 0); 
   glRotatef(keyboardRight_ShadowsRotationLEFT_RIGHT_01, 0, 0, 1);     
   glRotatef(keyboardRight_ROTATION[3], keyboardRight_ROTATION[0], keyboardRight_ROTATION[1], keyboardRight_ROTATION[2]);
   glScalef(scale_keyboardRight_Shadow_01, 1.0, scale_keyboardRight_Shadow_01); 
glPopMatrix();*/

   glBindBufferARB(GL_ARRAY_BUFFER_ARB, keyboardRight_vboID);

   glEnableClientState(GL_TEXTURE_COORD_ARRAY );
   glEnableClientState(GL_NORMAL_ARRAY);
   glEnableClientState(GL_VERTEX_ARRAY);
   glTexCoordPointer(3, GL_FLOAT, 0, (void*)(sizeof(keyboardRight_VERT) + sizeof(keyboardRight_NORM)));
   glNormalPointer(GL_FLOAT, 0, (void*)sizeof(keyboardRight_VERT));
   glVertexPointer(3, GL_FLOAT, 0, 0);

   glDrawArrays(GL_TRIANGLES, 0, 6);
   glDisableClientState(GL_VERTEX_ARRAY);
   glDisableClientState(GL_NORMAL_ARRAY);
   glDisableClientState(GL_TEXTURE_COORD_ARRAY);

