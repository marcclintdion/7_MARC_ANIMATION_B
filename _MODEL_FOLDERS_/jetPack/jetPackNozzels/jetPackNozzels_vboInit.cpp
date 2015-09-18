glGenBuffers(1, &jetPackNozzels_vboID);
glBindBuffer(GL_ARRAY_BUFFER, jetPackNozzels_vboID);
glBufferData(GL_ARRAY_BUFFER,       sizeof(jetPackNozzels_VERT) + sizeof(jetPackNozzels_NORM) + sizeof(jetPackNozzels_TEX), 0, GL_STATIC_DRAW);
glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(jetPackNozzels_VERT), jetPackNozzels_VERT);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(jetPackNozzels_VERT),  sizeof(jetPackNozzels_NORM), jetPackNozzels_NORM);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(jetPackNozzels_VERT) + sizeof(jetPackNozzels_NORM), sizeof(jetPackNozzels_TEX), jetPackNozzels_TEX);

    loadTexture("_MODEL_FOLDERS_/jetPack/jetPackNozzels/jetPackNozzels.jpg",      textureMap[223]);
    loadTexture("_MODEL_FOLDERS_/jetPack/jetPackNozzels/jetPackNozzels_DOT3.jpg", normalMap[223]);

    //loadTexture("_MODEL_FOLDERS_/jetPack/jetPackNozzels/jetPackNozzels_BUMP.jpg", specularMap[223]);
