glGenBuffers(1, &marcLeftHand_vboID);
glBindBuffer(GL_ARRAY_BUFFER, marcLeftHand_vboID);
glBufferData(GL_ARRAY_BUFFER,       sizeof(marcLeftHand_VERT) + sizeof(marcLeftHand_NORM) + sizeof(marcLeftHand_TEX), 0, GL_STATIC_DRAW);
glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(marcLeftHand_VERT), marcLeftHand_VERT);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(marcLeftHand_VERT),  sizeof(marcLeftHand_NORM), marcLeftHand_NORM);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(marcLeftHand_VERT) + sizeof(marcLeftHand_NORM), sizeof(marcLeftHand_TEX), marcLeftHand_TEX);

    loadTexture("_MODEL_FOLDERS_/marcParts/marcLeftHand/marcLeftHand.jpg",      textureMap[215]);
    loadTexture("_MODEL_FOLDERS_/marcParts/marcLeftHand/marcLeftHand_DOT3.jpg", normalMap[215]);

    //loadTexture("_MODEL_FOLDERS_/marcParts/marcLeftHand/marcLeftHand_BUMP.jpg", specularMap[215]);
