glGenBuffers(1, &jetPackVestStraps_vboID);
glBindBuffer(GL_ARRAY_BUFFER, jetPackVestStraps_vboID);
glBufferData(GL_ARRAY_BUFFER,       sizeof(jetPackVestStraps_VERT) + sizeof(jetPackVestStraps_NORM) + sizeof(jetPackVestStraps_TEX), 0, GL_STATIC_DRAW);
glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(jetPackVestStraps_VERT), jetPackVestStraps_VERT);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(jetPackVestStraps_VERT),  sizeof(jetPackVestStraps_NORM), jetPackVestStraps_NORM);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(jetPackVestStraps_VERT) + sizeof(jetPackVestStraps_NORM), sizeof(jetPackVestStraps_TEX), jetPackVestStraps_TEX);

    loadTexture("_MODEL_FOLDERS_/jetPack/jetPackVestStraps/jetPackVestStraps.jpg",      textureMap[220]);
    loadTexture("_MODEL_FOLDERS_/jetPack/jetPackVestStraps/jetPackVestStraps_DOT3.jpg", normalMap[220]);

    //loadTexture("_MODEL_FOLDERS_/jetPack/jetPackVestStraps/jetPackVestStraps_BUMP.jpg", specularMap[220]);
