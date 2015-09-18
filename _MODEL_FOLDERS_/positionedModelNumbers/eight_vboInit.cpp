glGenBuffers(1, &eight_vboID);
glBindBuffer(GL_ARRAY_BUFFER, eight_vboID);
glBufferData(GL_ARRAY_BUFFER,       sizeof(eight_VERT) + sizeof(eight_NORM) + sizeof(eight_TEX), 0, GL_STATIC_DRAW);
glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(eight_VERT), eight_VERT);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(eight_VERT),  sizeof(eight_NORM), eight_NORM);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(eight_VERT) + sizeof(eight_NORM), sizeof(eight_TEX), eight_TEX);
