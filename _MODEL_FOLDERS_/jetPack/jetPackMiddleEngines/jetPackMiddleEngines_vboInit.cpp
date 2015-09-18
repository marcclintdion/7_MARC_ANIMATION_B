glGenBuffers(1, &jetPackMiddleEngines_vboID);
glBindBuffer(GL_ARRAY_BUFFER, jetPackMiddleEngines_vboID);
glBufferData(GL_ARRAY_BUFFER,       sizeof(jetPackMiddleEngines_VERT) + sizeof(jetPackMiddleEngines_NORM) + sizeof(jetPackMiddleEngines_TEX), 0, GL_STATIC_DRAW);
glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(jetPackMiddleEngines_VERT), jetPackMiddleEngines_VERT);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(jetPackMiddleEngines_VERT),  sizeof(jetPackMiddleEngines_NORM), jetPackMiddleEngines_NORM);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(jetPackMiddleEngines_VERT) + sizeof(jetPackMiddleEngines_NORM), sizeof(jetPackMiddleEngines_TEX), jetPackMiddleEngines_TEX);

    loadTexture("_MODEL_FOLDERS_/jetPack/jetPackMiddleEngines/jetPackMiddleEngines.jpg",      textureMap[224]);
    loadTexture("_MODEL_FOLDERS_/jetPack/jetPackMiddleEngines/jetPackMiddleEngines_DOT3.jpg", normalMap[224]);

    //loadTexture("_MODEL_FOLDERS_/jetPack/jetPackMiddleEngines/jetPackMiddleEngines_BUMP.jpg", specularMap[224]);
