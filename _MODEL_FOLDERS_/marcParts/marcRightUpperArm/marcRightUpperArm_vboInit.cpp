glGenBuffers(1, &marcRightUpperArm_vboID);
glBindBuffer(GL_ARRAY_BUFFER, marcRightUpperArm_vboID);
glBufferData(GL_ARRAY_BUFFER,       sizeof(marcRightUpperArm_VERT) + sizeof(marcRightUpperArm_NORM) + sizeof(marcRightUpperArm_TEX), 0, GL_STATIC_DRAW);
glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(marcRightUpperArm_VERT), marcRightUpperArm_VERT);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(marcRightUpperArm_VERT),  sizeof(marcRightUpperArm_NORM), marcRightUpperArm_NORM);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(marcRightUpperArm_VERT) + sizeof(marcRightUpperArm_NORM), sizeof(marcRightUpperArm_TEX), marcRightUpperArm_TEX);

    loadTexture("_MODEL_FOLDERS_/marcParts/marcRightUpperArm/marcRightUpperArm.jpg",      textureMap[206]);
    loadTexture("_MODEL_FOLDERS_/marcParts/marcRightUpperArm/marcRightUpperArm_DOT3.jpg", normalMap[206]);

    //loadTexture("_MODEL_FOLDERS_/marcParts/marcRightUpperArm/marcRightUpperArm_BUMP.jpg", specularMap[206]);
