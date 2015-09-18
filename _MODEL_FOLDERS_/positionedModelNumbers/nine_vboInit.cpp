glGenBuffers(1, &nine_vboID);
glBindBuffer(GL_ARRAY_BUFFER, nine_vboID);
glBufferData(GL_ARRAY_BUFFER,       sizeof(nine_VERT) + sizeof(nine_NORM) + sizeof(nine_TEX), 0, GL_STATIC_DRAW);
glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(nine_VERT), nine_VERT);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(nine_VERT),  sizeof(nine_NORM), nine_NORM);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(nine_VERT) + sizeof(nine_NORM), sizeof(nine_TEX), nine_TEX);
