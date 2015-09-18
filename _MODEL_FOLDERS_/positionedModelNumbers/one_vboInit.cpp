glGenBuffers(1, &one_vboID);
glBindBuffer(GL_ARRAY_BUFFER, one_vboID);
glBufferData(GL_ARRAY_BUFFER,       sizeof(one_VERT) + sizeof(one_NORM) + sizeof(one_TEX), 0, GL_STATIC_DRAW);
glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(one_VERT), one_VERT);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(one_VERT),  sizeof(one_NORM), one_NORM);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(one_VERT) + sizeof(one_NORM), sizeof(one_TEX), one_TEX);

