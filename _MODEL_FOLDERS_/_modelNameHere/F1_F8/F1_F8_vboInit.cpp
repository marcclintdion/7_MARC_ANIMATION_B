glGenBuffersARB(1, &F1_F8_vboID);                                                                                                
glBindBufferARB(GL_ARRAY_BUFFER_ARB, F1_F8_vboID);                                                                               
glBufferDataARB(GL_ARRAY_BUFFER_ARB,       sizeof(F1_F8_VERT) + sizeof(F1_F8_NORM) + sizeof(F1_F8_TEX), 0, GL_STATIC_DRAW_ARB);  
glBufferSubDataARB(GL_ARRAY_BUFFER_ARB, 0, sizeof(F1_F8_VERT), F1_F8_VERT);                                                      
glBufferSubDataARB(GL_ARRAY_BUFFER_ARB,    sizeof(F1_F8_VERT),  sizeof(F1_F8_NORM), F1_F8_NORM);                                 
glBufferSubDataARB(GL_ARRAY_BUFFER_ARB,    sizeof(F1_F8_VERT) + sizeof(F1_F8_NORM), sizeof(F1_F8_TEX), F1_F8_TEX);               


    loadTexture("_MODEL_FOLDERS_/F1_F8/F1_F8.jpg",        textureMap[573]);                                
    loadTexture("_MODEL_FOLDERS_/F1_F8/F1_F8_DOT3.bmp",   normalMap[573]);                                
  //loadTexture("_MODEL_FOLDERS_/F1_F8/F1_F8_BUMP.jpg", specularMap[573]);                                  
