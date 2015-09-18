glGenBuffers(1, &jetPackTopCones_vboID);
glBindBuffer(GL_ARRAY_BUFFER, jetPackTopCones_vboID);
glBufferData(GL_ARRAY_BUFFER,       sizeof(jetPackTopCones_VERT) + sizeof(jetPackTopCones_NORM) + sizeof(jetPackTopCones_TEX), 0, GL_STATIC_DRAW);
glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(jetPackTopCones_VERT), jetPackTopCones_VERT);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(jetPackTopCones_VERT),  sizeof(jetPackTopCones_NORM), jetPackTopCones_NORM);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(jetPackTopCones_VERT) + sizeof(jetPackTopCones_NORM), sizeof(jetPackTopCones_TEX), jetPackTopCones_TEX);

    loadTexture("_MODEL_FOLDERS_/jetPack/jetPackTopCones/jetPackTopCones.jpg",      textureMap[225]);
    loadTexture("_MODEL_FOLDERS_/jetPack/jetPackTopCones/jetPackTopCones_DOT3.jpg", normalMap[225]);

    //loadTexture("_MODEL_FOLDERS_/jetPack/jetPackTopCones/jetPackTopCones_BUMP.jpg", specularMap[225]);
