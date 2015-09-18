glGenBuffers(1, &marcLeftUpperLeg_vboID);
glBindBuffer(GL_ARRAY_BUFFER, marcLeftUpperLeg_vboID);
glBufferData(GL_ARRAY_BUFFER,       sizeof(marcLeftUpperLeg_VERT) + sizeof(marcLeftUpperLeg_NORM) + sizeof(marcLeftUpperLeg_TEX), 0, GL_STATIC_DRAW);
glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(marcLeftUpperLeg_VERT), marcLeftUpperLeg_VERT);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(marcLeftUpperLeg_VERT),  sizeof(marcLeftUpperLeg_NORM), marcLeftUpperLeg_NORM);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(marcLeftUpperLeg_VERT) + sizeof(marcLeftUpperLeg_NORM), sizeof(marcLeftUpperLeg_TEX), marcLeftUpperLeg_TEX);

    loadTexture("_MODEL_FOLDERS_/marcParts/marcLeftUpperLeg/marcLeftUpperLeg.jpg",      textureMap[209]);
    loadTexture("_MODEL_FOLDERS_/marcParts/marcLeftUpperLeg/marcLeftUpperLeg_DOT3.jpg", normalMap[209]);

    //loadTexture("_MODEL_FOLDERS_/marcParts/marcLeftUpperLeg/marcLeftUpperLeg_BUMP.jpg", specularMap[209]);
