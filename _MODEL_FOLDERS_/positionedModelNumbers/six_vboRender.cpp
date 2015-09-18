


              glBindBuffer(GL_ARRAY_BUFFER, six_vboID);


              glEnableClientState(GL_TEXTURE_COORD_ARRAY );
              glEnableClientState(GL_NORMAL_ARRAY);
              glEnableClientState(GL_VERTEX_ARRAY);
              glTexCoordPointer(3, GL_FLOAT, 0, (void*)(sizeof(six_VERT) + sizeof(six_NORM)));
              glNormalPointer(GL_FLOAT, 0, (void*)sizeof(six_VERT));
              glVertexPointer(3, GL_FLOAT, 0, 0);

              glDrawArrays(GL_TRIANGLES, 0, 69);

              glDisableClientState(GL_VERTEX_ARRAY);
              glDisableClientState(GL_NORMAL_ARRAY);
              glDisableClientState(GL_TEXTURE_COORD_ARRAY);
