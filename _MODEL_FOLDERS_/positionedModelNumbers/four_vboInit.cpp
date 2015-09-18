glGenBuffers(1, &four_vboID);
glBindBuffer(GL_ARRAY_BUFFER, four_vboID);
glBufferData(GL_ARRAY_BUFFER,       sizeof(four_VERT) + sizeof(four_NORM) + sizeof(four_TEX), 0, GL_STATIC_DRAW);
glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(four_VERT), four_VERT);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(four_VERT),  sizeof(four_NORM), four_NORM);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(four_VERT) + sizeof(four_NORM), sizeof(four_TEX), four_TEX);
