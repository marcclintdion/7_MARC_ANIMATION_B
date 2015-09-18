glGenBuffers(1, &zero_vboID);
glBindBuffer(GL_ARRAY_BUFFER, zero_vboID);
glBufferData(GL_ARRAY_BUFFER,       sizeof(zero_VERT) + sizeof(zero_NORM) + sizeof(zero_TEX), 0, GL_STATIC_DRAW);
glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(zero_VERT), zero_VERT);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(zero_VERT),  sizeof(zero_NORM), zero_NORM);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(zero_VERT) + sizeof(zero_NORM), sizeof(zero_TEX), zero_TEX);


