glGenBuffers(1, &marcRightHand_vboID);
glBindBuffer(GL_ARRAY_BUFFER, marcRightHand_vboID);
glBufferData(GL_ARRAY_BUFFER,       sizeof(marcRightHand_VERT) + sizeof(marcRightHand_NORM) + sizeof(marcRightHand_TEX), 0, GL_STATIC_DRAW);
glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(marcRightHand_VERT), marcRightHand_VERT);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(marcRightHand_VERT),  sizeof(marcRightHand_NORM), marcRightHand_NORM);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(marcRightHand_VERT) + sizeof(marcRightHand_NORM), sizeof(marcRightHand_TEX), marcRightHand_TEX);

    loadTexture("_MODEL_FOLDERS_/marcParts/marcRightHand/marcRightHand.jpg",      textureMap[212]);
    loadTexture("_MODEL_FOLDERS_/marcParts/marcRightHand/marcRightHand_DOT3.jpg", normalMap[212]);

    //loadTexture("_MODEL_FOLDERS_/marcParts/marcRightHand/marcRightHand_BUMP.jpg", specularMap[212]);
