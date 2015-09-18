glGenBuffers(1, &keyboardRight_vboID);
glBindBuffer(GL_ARRAY_BUFFER, keyboardRight_vboID);
glBufferData(GL_ARRAY_BUFFER,       sizeof(keyboardRight_VERT) + sizeof(keyboardRight_NORM) + sizeof(keyboardRight_TEX), 0, GL_STATIC_DRAW);
glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(keyboardRight_VERT), keyboardRight_VERT);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(keyboardRight_VERT),  sizeof(keyboardRight_NORM), keyboardRight_NORM);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(keyboardRight_VERT) + sizeof(keyboardRight_NORM), sizeof(keyboardRight_TEX), keyboardRight_TEX);


    loadTexture("_MODEL_FOLDERS_/dialogue/keyboard/keyboard_Right.jpg",        textureMap[601]);
