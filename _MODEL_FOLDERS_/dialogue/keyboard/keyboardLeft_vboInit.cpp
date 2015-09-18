glGenBuffers(1, &keyboardLeft_vboID);
glBindBuffer(GL_ARRAY_BUFFER, keyboardLeft_vboID);
glBufferData(GL_ARRAY_BUFFER,       sizeof(keyboardLeft_VERT) + sizeof(keyboardLeft_NORM) + sizeof(keyboardLeft_TEX), 0, GL_STATIC_DRAW);
glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(keyboardLeft_VERT), keyboardLeft_VERT);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(keyboardLeft_VERT),  sizeof(keyboardLeft_NORM), keyboardLeft_NORM);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(keyboardLeft_VERT) + sizeof(keyboardLeft_NORM), sizeof(keyboardLeft_TEX), keyboardLeft_TEX);


    loadTexture("_MODEL_FOLDERS_/dialogue/keyboard/keyboard_Left.jpg",        textureMap[600]);
