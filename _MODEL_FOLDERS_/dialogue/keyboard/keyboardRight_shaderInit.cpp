    const char *keyboardRight_SHADER_VertexStrings[1];
    const char *keyboardRight_SHADER_FragmentStrings[1];

    keyboardRight_SHADER_Vertex = glCreateShaderObjectARB( GL_VERTEX_SHADER_ARB );

	 unsigned char *keyboardRight_SHADER_VertexAssembly = readShaderFile( "_MODEL_FOLDERS_/keyboardRight/keyboardRight.vert" );
    keyboardRight_SHADER_VertexStrings[0] = (char*)keyboardRight_SHADER_VertexAssembly;
    glShaderSourceARB( keyboardRight_SHADER_Vertex, 1, keyboardRight_SHADER_VertexStrings, NULL );
    glCompileShaderARB( keyboardRight_SHADER_Vertex);
    delete keyboardRight_SHADER_VertexAssembly;

    keyboardRight_SHADER_Fragment = glCreateShaderObjectARB( GL_FRAGMENT_SHADER_ARB );

    unsigned char *keyboardRight_SHADER_FragmentAssembly = readShaderFile( "_MODEL_FOLDERS_/keyboardRight/keyboardRight.frag" );
    keyboardRight_SHADER_FragmentStrings[0] = (char*)keyboardRight_SHADER_FragmentAssembly;
    glShaderSourceARB( keyboardRight_SHADER_Fragment, 1, keyboardRight_SHADER_FragmentStrings, NULL );
    glCompileShaderARB(keyboardRight_SHADER_Fragment );

    delete keyboardRight_SHADER_FragmentAssembly;

	 keyboardRight_SHADER = glCreateProgramObjectARB();

    glAttachObjectARB( keyboardRight_SHADER, keyboardRight_SHADER_Vertex );
    glAttachObjectARB( keyboardRight_SHADER, keyboardRight_SHADER_Fragment );

    glLinkProgramARB(keyboardRight_SHADER); 

    UNIFORM_shininess_keyboardRight = glGetUniformLocationARB(  keyboardRight_SHADER, "shiny" );   

    UNIFORM_counter1_keyboardRight = glGetUniformLocationARB( keyboardRight_SHADER, "counter1" );
    UNIFORM_counter2_keyboardRight = glGetUniformLocationARB( keyboardRight_SHADER, "counter2" );
    UNIFORM_counter3_keyboardRight = glGetUniformLocationARB( keyboardRight_SHADER, "counter3" );
    UNIFORM_counter4_keyboardRight = glGetUniformLocationARB( keyboardRight_SHADER, "counter4" );

