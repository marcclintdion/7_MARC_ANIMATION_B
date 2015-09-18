glGenBuffers(1, &marcLeftBoot_vboID);
glBindBuffer(GL_ARRAY_BUFFER, marcLeftBoot_vboID);
glBufferData(GL_ARRAY_BUFFER,       sizeof(marcLeftBoot_VERT) + sizeof(marcLeftBoot_NORM) + sizeof(marcLeftBoot_TEX), 0, GL_STATIC_DRAW);
glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(marcLeftBoot_VERT), marcLeftBoot_VERT);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(marcLeftBoot_VERT),  sizeof(marcLeftBoot_NORM), marcLeftBoot_NORM);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(marcLeftBoot_VERT) + sizeof(marcLeftBoot_NORM), sizeof(marcLeftBoot_TEX), marcLeftBoot_TEX);

    loadTexture("_MODEL_FOLDERS_/marcParts/marcLeftBoot/marcLeftBoot.jpg",      textureMap[211]);
    loadTexture("_MODEL_FOLDERS_/marcParts/marcLeftBoot/marcLeftBoot_DOT3.jpg", normalMap[211]);

    //loadTexture("_MODEL_FOLDERS_/marcParts/marcLeftBoot/marcLeftBoot_BUMP.jpg", specularMap[211]);
