

              glBindBuffer(GL_ARRAY_BUFFER, one_vboID);



              glEnableClientState(GL_TEXTURE_COORD_ARRAY );
              glEnableClientState(GL_NORMAL_ARRAY);
              glEnableClientState(GL_VERTEX_ARRAY);
              glTexCoordPointer(3, GL_FLOAT, 0, (void*)(sizeof(one_VERT) + sizeof(one_NORM)));
              glNormalPointer(GL_FLOAT, 0, (void*)sizeof(one_VERT));
              glVertexPointer(3, GL_FLOAT, 0, 0);



              glDrawArrays(GL_TRIANGLES, 0, 6);

              glDisableClientState(GL_VERTEX_ARRAY);
              glDisableClientState(GL_NORMAL_ARRAY);
              glDisableClientState(GL_TEXTURE_COORD_ARRAY);
