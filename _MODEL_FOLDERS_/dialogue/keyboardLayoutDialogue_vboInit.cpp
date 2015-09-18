glGenBuffers(1, &keyboardLayoutDialogue_vboID);
glBindBuffer(GL_ARRAY_BUFFER, keyboardLayoutDialogue_vboID);
glBufferData(GL_ARRAY_BUFFER,       sizeof(keyboardLayoutDialogue_VERT) + sizeof(keyboardLayoutDialogue_NORM) + sizeof(keyboardLayoutDialogue_TEX), 0, GL_STATIC_DRAW);
glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(keyboardLayoutDialogue_VERT), keyboardLayoutDialogue_VERT);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(keyboardLayoutDialogue_VERT),  sizeof(keyboardLayoutDialogue_NORM), keyboardLayoutDialogue_NORM);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(keyboardLayoutDialogue_VERT) + sizeof(keyboardLayoutDialogue_NORM), sizeof(keyboardLayoutDialogue_TEX), keyboardLayoutDialogue_TEX);


    loadTexture("_MODEL_FOLDERS_/dialogue/keyboardLayoutDialogue.jpg",        textureMap[540]); 
    loadTexture("_MODEL_FOLDERS_/dialogue/hideSet.jpg",                       textureMap[580]);    
    loadTexture("_MODEL_FOLDERS_/dialogue/keyboardSet_01_INFO.jpg",           textureMap[581]);    
    //---------------------------------------------------------------------------------

    
    
