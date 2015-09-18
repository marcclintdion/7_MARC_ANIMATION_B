glGenBuffers(1, &marcRightUpperLeg_vboID);
glBindBuffer(GL_ARRAY_BUFFER, marcRightUpperLeg_vboID);
glBufferData(GL_ARRAY_BUFFER,       sizeof(marcRightUpperLeg_VERT) + sizeof(marcRightUpperLeg_NORM) + sizeof(marcRightUpperLeg_TEX), 0, GL_STATIC_DRAW);
glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(marcRightUpperLeg_VERT), marcRightUpperLeg_VERT);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(marcRightUpperLeg_VERT),  sizeof(marcRightUpperLeg_NORM), marcRightUpperLeg_NORM);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(marcRightUpperLeg_VERT) + sizeof(marcRightUpperLeg_NORM), sizeof(marcRightUpperLeg_TEX), marcRightUpperLeg_TEX);

    loadTexture("_MODEL_FOLDERS_/marcParts/marcRightUpperLeg/marcRightUpperLeg.jpg",      textureMap[204]);
    loadTexture("_MODEL_FOLDERS_/marcParts/marcRightUpperLeg/marcRightUpperLeg_DOT3.jpg", normalMap[204]);

    //loadTexture("_MODEL_FOLDERS_/marcParts/marcRightUpperLeg/marcRightUpperLeg_BUMP.jpg", specularMap[204]);
