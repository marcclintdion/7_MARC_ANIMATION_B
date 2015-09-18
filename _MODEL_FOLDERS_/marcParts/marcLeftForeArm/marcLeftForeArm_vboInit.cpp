glGenBuffers(1, &marcLeftForeArm_vboID);
glBindBuffer(GL_ARRAY_BUFFER, marcLeftForeArm_vboID);
glBufferData(GL_ARRAY_BUFFER,       sizeof(marcLeftForeArm_VERT) + sizeof(marcLeftForeArm_NORM) + sizeof(marcLeftForeArm_TEX), 0, GL_STATIC_DRAW);
glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(marcLeftForeArm_VERT), marcLeftForeArm_VERT);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(marcLeftForeArm_VERT),  sizeof(marcLeftForeArm_NORM), marcLeftForeArm_NORM);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(marcLeftForeArm_VERT) + sizeof(marcLeftForeArm_NORM), sizeof(marcLeftForeArm_TEX), marcLeftForeArm_TEX);

    loadTexture("_MODEL_FOLDERS_/marcParts/marcLeftForeArm/marcLeftForeArm.jpg",      textureMap[214]);
    loadTexture("_MODEL_FOLDERS_/marcParts/marcLeftForeArm/marcLeftForeArm_DOT3.jpg", normalMap[214]);

    //loadTexture("_MODEL_FOLDERS_/marcParts/marcLeftForeArm/marcLeftForeArm_BUMP.jpg", specularMap[214]);
