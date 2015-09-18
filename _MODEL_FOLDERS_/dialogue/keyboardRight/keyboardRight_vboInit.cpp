glGenBuffersARB(1, &keyboardRight_vboID);
glBindBufferARB(GL_ARRAY_BUFFER_ARB, keyboardRight_vboID);
glBufferDataARB(GL_ARRAY_BUFFER_ARB,       sizeof(keyboardRight_VERT) + sizeof(keyboardRight_NORM) + sizeof(keyboardRight_TEX), 0, GL_STATIC_DRAW_ARB);
glBufferSubDataARB(GL_ARRAY_BUFFER_ARB, 0, sizeof(keyboardRight_VERT), keyboardRight_VERT);
glBufferSubDataARB(GL_ARRAY_BUFFER_ARB,    sizeof(keyboardRight_VERT),  sizeof(keyboardRight_NORM), keyboardRight_NORM);
glBufferSubDataARB(GL_ARRAY_BUFFER_ARB,    sizeof(keyboardRight_VERT) + sizeof(keyboardRight_NORM), sizeof(keyboardRight_TEX), keyboardRight_TEX);


    loadTexture("_MODEL_FOLDERS_/keyboardRight/keyboardRight.jpg",        textureMap[601]);
    loadTexture("_MODEL_FOLDERS_/keyboardRight/keyboardRight_DOT3.bmp",   normalMap[601]);
  //loadTexture("_MODEL_FOLDERS_/keyboardRight/keyboardRight_BUMP.jpg", specularMap[601]);
