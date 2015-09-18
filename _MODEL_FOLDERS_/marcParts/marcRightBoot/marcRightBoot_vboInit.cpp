glGenBuffers(1, &marcRightBoot_vboID);
glBindBuffer(GL_ARRAY_BUFFER, marcRightBoot_vboID);
glBufferData(GL_ARRAY_BUFFER,       sizeof(marcRightBoot_VERT) + sizeof(marcRightBoot_NORM) + sizeof(marcRightBoot_TEX), 0, GL_STATIC_DRAW);
glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(marcRightBoot_VERT), marcRightBoot_VERT);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(marcRightBoot_VERT),  sizeof(marcRightBoot_NORM), marcRightBoot_NORM);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(marcRightBoot_VERT) + sizeof(marcRightBoot_NORM), sizeof(marcRightBoot_TEX), marcRightBoot_TEX);

    loadTexture("_MODEL_FOLDERS_/marcParts/marcRightBoot/marcRightBoot.jpg",      textureMap[208]);
    loadTexture("_MODEL_FOLDERS_/marcParts/marcRightBoot/marcRightBoot_DOT3.jpg", normalMap[208]);

    //loadTexture("_MODEL_FOLDERS_/marcParts/marcRightBoot/marcRightBoot_BUMP.jpg", specularMap[208]);
