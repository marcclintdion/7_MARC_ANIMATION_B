glGenBuffers(1, &six_vboID);
glBindBuffer(GL_ARRAY_BUFFER, six_vboID);
glBufferData(GL_ARRAY_BUFFER,       sizeof(six_VERT) + sizeof(six_NORM) + sizeof(six_TEX), 0, GL_STATIC_DRAW);
glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(six_VERT), six_VERT);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(six_VERT),  sizeof(six_NORM), six_NORM);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(six_VERT) + sizeof(six_NORM), sizeof(six_TEX), six_TEX);
