glGenBuffers(1, &marcTorso_vboID);
glBindBuffer(GL_ARRAY_BUFFER, marcTorso_vboID);
glBufferData(GL_ARRAY_BUFFER,       sizeof(marcTorso_VERT) + sizeof(marcTorso_NORM) + sizeof(marcTorso_TEX), 0, GL_STATIC_DRAW);
glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(marcTorso_VERT), marcTorso_VERT);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(marcTorso_VERT),  sizeof(marcTorso_NORM), marcTorso_NORM);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(marcTorso_VERT) + sizeof(marcTorso_NORM), sizeof(marcTorso_TEX), marcTorso_TEX);

    loadTexture("_MODEL_FOLDERS_/marcParts/marcTorso/marcTorso.jpg",      textureMap[202]);
    loadTexture("_MODEL_FOLDERS_/marcParts/marcTorso/marcTorso_DOT3.jpg", normalMap[202]);

    //loadTexture("_MODEL_FOLDERS_/marcParts/marcTorso/marcTorso_BUMP.jpg", specularMap[202]);
