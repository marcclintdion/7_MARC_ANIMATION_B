glGenBuffers(1, &F1_F8_vboID);
glBindBuffer(GL_ARRAY_BUFFER, F1_F8_vboID);
glBufferData(GL_ARRAY_BUFFER,       sizeof(F1_F8_VERT) + sizeof(F1_F8_NORM) + sizeof(F1_F8_TEX), 0, GL_STATIC_DRAW);
glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(F1_F8_VERT), F1_F8_VERT);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(F1_F8_VERT),  sizeof(F1_F8_NORM), F1_F8_NORM);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(F1_F8_VERT) + sizeof(F1_F8_NORM), sizeof(F1_F8_TEX), F1_F8_TEX);


    loadTexture("_MODEL_FOLDERS_/F1_F8/keyboard_A.jpg",        textureMap[573]);
    loadTexture("_MODEL_FOLDERS_/F1_F8/keyboard_A_DOT3.bmp",   normalMap[573]);
  //loadTexture("_MODEL_FOLDERS_/F1_F8/F1_F8_BUMP.jpg", specularMap[573]);
