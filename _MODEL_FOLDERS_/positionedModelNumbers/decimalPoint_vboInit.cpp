glGenBuffers(1, &decimalPoint_vboID);
glBindBuffer(GL_ARRAY_BUFFER, decimalPoint_vboID);
glBufferData(GL_ARRAY_BUFFER,       sizeof(decimalPoint_VERT) + sizeof(decimalPoint_NORM) + sizeof(decimalPoint_TEX), 0, GL_STATIC_DRAW);
glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(decimalPoint_VERT), decimalPoint_VERT);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(decimalPoint_VERT),  sizeof(decimalPoint_NORM), decimalPoint_NORM);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(decimalPoint_VERT) + sizeof(decimalPoint_NORM), sizeof(decimalPoint_TEX), decimalPoint_TEX);
