glGenBuffers(1, &marcHips_vboID);
glBindBuffer(GL_ARRAY_BUFFER, marcHips_vboID);
glBufferData(GL_ARRAY_BUFFER,       sizeof(marcHips_VERT) + sizeof(marcHips_NORM) + sizeof(marcHips_TEX), 0, GL_STATIC_DRAW);
glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(marcHips_VERT), marcHips_VERT);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(marcHips_VERT),  sizeof(marcHips_NORM), marcHips_NORM);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(marcHips_VERT) + sizeof(marcHips_NORM), sizeof(marcHips_TEX), marcHips_TEX);

    loadTexture("_MODEL_FOLDERS_/marcParts/marcHips/marcHips.jpg",      textureMap[203]);
    loadTexture("_MODEL_FOLDERS_/marcParts/marcHips/marcHips_DOT3.jpg", normalMap[203]);

    //loadTexture("_MODEL_FOLDERS_/marcHips/marcHips_BUMP.jpg", specularMap[203]);
