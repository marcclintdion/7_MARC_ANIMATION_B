glGenBuffers(1, &marcHeadBack_vboID);
glBindBuffer(GL_ARRAY_BUFFER, marcHeadBack_vboID);
glBufferData(GL_ARRAY_BUFFER,       sizeof(marcHeadBack_VERT) + sizeof(marcHeadBack_NORM) + sizeof(marcHeadBack_TEX), 0, GL_STATIC_DRAW);
glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(marcHeadBack_VERT), marcHeadBack_VERT);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(marcHeadBack_VERT),  sizeof(marcHeadBack_NORM), marcHeadBack_NORM);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(marcHeadBack_VERT) + sizeof(marcHeadBack_NORM), sizeof(marcHeadBack_TEX), marcHeadBack_TEX);

    loadTexture("_MODEL_FOLDERS_/marcParts/marcHeadBack/marcHeadBack.jpg",      textureMap[200]);
    loadTexture("_MODEL_FOLDERS_/marcParts/marcHeadBack/marcHeadBack_DOT3.jpg", normalMap[200]);

    //loadTexture("_MODEL_FOLDERS_/marcHeadBack/marcHeadBack_BUMP.jpg", specularMap[200]);
