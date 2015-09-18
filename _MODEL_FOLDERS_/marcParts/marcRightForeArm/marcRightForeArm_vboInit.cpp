glGenBuffers(1, &marcRightForeArm_vboID);
glBindBuffer(GL_ARRAY_BUFFER, marcRightForeArm_vboID);
glBufferData(GL_ARRAY_BUFFER,       sizeof(marcRightForeArm_VERT) + sizeof(marcRightForeArm_NORM) + sizeof(marcRightForeArm_TEX), 0, GL_STATIC_DRAW);
glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(marcRightForeArm_VERT), marcRightForeArm_VERT);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(marcRightForeArm_VERT),  sizeof(marcRightForeArm_NORM), marcRightForeArm_NORM);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(marcRightForeArm_VERT) + sizeof(marcRightForeArm_NORM), sizeof(marcRightForeArm_TEX), marcRightForeArm_TEX);

    loadTexture("_MODEL_FOLDERS_/marcParts/marcRightForeArm/marcRightForeArm.jpg",      textureMap[207]);
    loadTexture("_MODEL_FOLDERS_/marcParts/marcRightForeArm/marcRightForeArm_DOT3.jpg", normalMap[207]);

    //loadTexture("_MODEL_FOLDERS_/marcParts/marcRightForeArm/marcRightForeArm_BUMP.jpg", specularMap[207]);
