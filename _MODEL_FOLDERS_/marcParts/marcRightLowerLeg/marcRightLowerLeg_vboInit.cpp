glGenBuffers(1, &marcRightLowerLeg_vboID);
glBindBuffer(GL_ARRAY_BUFFER, marcRightLowerLeg_vboID);
glBufferData(GL_ARRAY_BUFFER,       sizeof(marcRightLowerLeg_VERT) + sizeof(marcRightLowerLeg_NORM) + sizeof(marcRightLowerLeg_TEX), 0, GL_STATIC_DRAW);
glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(marcRightLowerLeg_VERT), marcRightLowerLeg_VERT);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(marcRightLowerLeg_VERT),  sizeof(marcRightLowerLeg_NORM), marcRightLowerLeg_NORM);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(marcRightLowerLeg_VERT) + sizeof(marcRightLowerLeg_NORM), sizeof(marcRightLowerLeg_TEX), marcRightLowerLeg_TEX);

    loadTexture("_MODEL_FOLDERS_/marcParts/marcRightLowerLeg/marcRightLowerLeg.jpg",      textureMap[205]);
    loadTexture("_MODEL_FOLDERS_/marcParts/marcRightLowerLeg/marcRightLowerLeg_DOT3.jpg", normalMap[205]);

    //loadTexture("_MODEL_FOLDERS_/marcParts/marcRightLowerLeg/marcRightLowerLeg_BUMP.jpg", specularMap[205]);
