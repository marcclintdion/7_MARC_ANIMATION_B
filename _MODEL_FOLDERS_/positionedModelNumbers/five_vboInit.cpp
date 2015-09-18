glGenBuffers(1, &five_vboID);
glBindBuffer(GL_ARRAY_BUFFER, five_vboID);
glBufferData(GL_ARRAY_BUFFER,       sizeof(five_VERT) + sizeof(five_NORM) + sizeof(five_TEX), 0, GL_STATIC_DRAW);
glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(five_VERT), five_VERT);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(five_VERT),  sizeof(five_NORM), five_NORM);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(five_VERT) + sizeof(five_NORM), sizeof(five_TEX), five_TEX);

