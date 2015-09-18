glGenBuffers(1, &jetPackBindings_vboID);
glBindBuffer(GL_ARRAY_BUFFER, jetPackBindings_vboID);
glBufferData(GL_ARRAY_BUFFER,       sizeof(jetPackBindings_VERT) + sizeof(jetPackBindings_NORM) + sizeof(jetPackBindings_TEX), 0, GL_STATIC_DRAW);
glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(jetPackBindings_VERT), jetPackBindings_VERT);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(jetPackBindings_VERT),  sizeof(jetPackBindings_NORM), jetPackBindings_NORM);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(jetPackBindings_VERT) + sizeof(jetPackBindings_NORM), sizeof(jetPackBindings_TEX), jetPackBindings_TEX);

    loadTexture("_MODEL_FOLDERS_/jetPack/jetPackBindings/jetPackBindings.jpg",      textureMap[221]);
    loadTexture("_MODEL_FOLDERS_/jetPack/jetPackBindings/jetPackBindings_DOT3.jpg", normalMap[221]);

    //loadTexture("_MODEL_FOLDERS_/jetPack/jetPackBindings/jetPackBindings_BUMP.jpg", specularMap[221]);
