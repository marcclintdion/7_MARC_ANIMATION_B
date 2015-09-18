glGenBuffers(1, &marcLeftLowerLeg_vboID);
glBindBuffer(GL_ARRAY_BUFFER, marcLeftLowerLeg_vboID);
glBufferData(GL_ARRAY_BUFFER,       sizeof(marcLeftLowerLeg_VERT) + sizeof(marcLeftLowerLeg_NORM) + sizeof(marcLeftLowerLeg_TEX), 0, GL_STATIC_DRAW);
glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(marcLeftLowerLeg_VERT), marcLeftLowerLeg_VERT);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(marcLeftLowerLeg_VERT),  sizeof(marcLeftLowerLeg_NORM), marcLeftLowerLeg_NORM);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(marcLeftLowerLeg_VERT) + sizeof(marcLeftLowerLeg_NORM), sizeof(marcLeftLowerLeg_TEX), marcLeftLowerLeg_TEX);

    loadTexture("_MODEL_FOLDERS_/marcParts/marcLeftLowerLeg/marcLeftLowerLeg.jpg",      textureMap[210]);
    loadTexture("_MODEL_FOLDERS_/marcParts/marcLeftLowerLeg/marcLeftLowerLeg_DOT3.jpg", normalMap[210]);

    //loadTexture("_MODEL_FOLDERS_/marcParts/marcLeftLowerLeg/marcLeftLowerLeg_BUMP.jpg", specularMap[210]);
