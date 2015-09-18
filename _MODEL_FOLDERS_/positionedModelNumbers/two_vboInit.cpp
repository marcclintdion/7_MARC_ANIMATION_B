glGenBuffers(1, &two_vboID);
glBindBuffer(GL_ARRAY_BUFFER, two_vboID);
glBufferData(GL_ARRAY_BUFFER,       sizeof(two_VERT) + sizeof(two_NORM) + sizeof(two_TEX), 0, GL_STATIC_DRAW);
glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(two_VERT), two_VERT);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(two_VERT),  sizeof(two_NORM), two_NORM);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(two_VERT) + sizeof(two_NORM), sizeof(two_TEX), two_TEX);
