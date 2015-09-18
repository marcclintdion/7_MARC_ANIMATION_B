glGenBuffers(1, &three_vboID);
glBindBuffer(GL_ARRAY_BUFFER, three_vboID);
glBufferData(GL_ARRAY_BUFFER,       sizeof(three_VERT) + sizeof(three_NORM) + sizeof(three_TEX), 0, GL_STATIC_DRAW);
glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(three_VERT), three_VERT);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(three_VERT),  sizeof(three_NORM), three_NORM);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(three_VERT) + sizeof(three_NORM), sizeof(three_TEX), three_TEX);
