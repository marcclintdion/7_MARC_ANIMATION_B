glGenBuffers(1, &marcLeftUpperArm_vboID);
glBindBuffer(GL_ARRAY_BUFFER, marcLeftUpperArm_vboID);
glBufferData(GL_ARRAY_BUFFER,       sizeof(marcLeftUpperArm_VERT) + sizeof(marcLeftUpperArm_NORM) + sizeof(marcLeftUpperArm_TEX), 0, GL_STATIC_DRAW);
glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(marcLeftUpperArm_VERT), marcLeftUpperArm_VERT);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(marcLeftUpperArm_VERT),  sizeof(marcLeftUpperArm_NORM), marcLeftUpperArm_NORM);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(marcLeftUpperArm_VERT) + sizeof(marcLeftUpperArm_NORM), sizeof(marcLeftUpperArm_TEX), marcLeftUpperArm_TEX);

    loadTexture("_MODEL_FOLDERS_/marcParts/marcLeftUpperArm/marcLeftUpperArm.jpg",      textureMap[213]);
    loadTexture("_MODEL_FOLDERS_/marcParts/marcLeftUpperArm/marcLeftUpperArm_DOT3.jpg", normalMap[213]);

    //loadTexture("_MODEL_FOLDERS_/marcLeftUpperArm/marcLeftUpperArm_BUMP.jpg", specularMap[213]);
