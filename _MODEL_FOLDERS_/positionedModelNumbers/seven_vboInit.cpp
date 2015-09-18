glGenBuffers(1, &seven_vboID);
glBindBuffer(GL_ARRAY_BUFFER, seven_vboID);
glBufferData(GL_ARRAY_BUFFER,       sizeof(seven_VERT) + sizeof(seven_NORM) + sizeof(seven_TEX), 0, GL_STATIC_DRAW);
glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(seven_VERT), seven_VERT);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(seven_VERT),  sizeof(seven_NORM), seven_NORM);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(seven_VERT) + sizeof(seven_NORM), sizeof(seven_TEX), seven_TEX);
