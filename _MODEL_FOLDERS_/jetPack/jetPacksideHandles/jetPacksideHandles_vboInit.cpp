glGenBuffers(1, &jetPacksideHandles_vboID);
glBindBuffer(GL_ARRAY_BUFFER, jetPacksideHandles_vboID);
glBufferData(GL_ARRAY_BUFFER,       sizeof(jetPacksideHandles_VERT) + sizeof(jetPacksideHandles_NORM) + sizeof(jetPacksideHandles_TEX), 0, GL_STATIC_DRAW);
glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(jetPacksideHandles_VERT), jetPacksideHandles_VERT);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(jetPacksideHandles_VERT),  sizeof(jetPacksideHandles_NORM), jetPacksideHandles_NORM);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(jetPacksideHandles_VERT) + sizeof(jetPacksideHandles_NORM), sizeof(jetPacksideHandles_TEX), jetPacksideHandles_TEX);

    loadTexture("_MODEL_FOLDERS_/jetPack/jetPacksideHandles/jetPacksideHandles.jpg",      textureMap[222]);
    loadTexture("_MODEL_FOLDERS_/jetPack/jetPacksideHandles/jetPacksideHandles_DOT3.jpg", normalMap[222]);

    //loadTexture("_MODEL_FOLDERS_/jetPack/jetPacksideHandles/jetPacksideHandles_BUMP.jpg", specularMap[222]);
