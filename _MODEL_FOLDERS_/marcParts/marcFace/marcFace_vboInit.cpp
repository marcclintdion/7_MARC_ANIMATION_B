glGenBuffers(1, &marcFace_vboID);
glBindBuffer(GL_ARRAY_BUFFER, marcFace_vboID);
glBufferData(GL_ARRAY_BUFFER,       sizeof(marcFace_VERT) + sizeof(marcFace_NORM) + sizeof(marcFace_TEX), 0, GL_STATIC_DRAW);
glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(marcFace_VERT), marcFace_VERT);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(marcFace_VERT),  sizeof(marcFace_NORM), marcFace_NORM);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(marcFace_VERT) + sizeof(marcFace_NORM), sizeof(marcFace_TEX), marcFace_TEX);

    loadTexture("_MODEL_FOLDERS_/marcParts/marcFace/marcFace.jpg",      textureMap[201]);
    loadTexture("_MODEL_FOLDERS_/marcParts/marcFace/marcFace_DOT3.jpg", normalMap[201]);

    //loadTexture("_MODEL_FOLDERS_/marcFace/marcFace_BUMP.jpg", specularMap[201]);
