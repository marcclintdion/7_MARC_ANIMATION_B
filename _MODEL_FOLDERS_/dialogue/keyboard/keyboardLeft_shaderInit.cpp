    const char *keyboardLeft_SHADER_VertexStrings[1];
    const char *keyboardLeft_SHADER_FragmentStrings[1];

    keyboardLeft_SHADER_Vertex = glCreateShaderObjectARB( GL_VERTEX_SHADER_ARB );

	 unsigned char *keyboardLeft_SHADER_VertexAssembly = readShaderFile( "_MODEL_FOLDERS_/keyboardLeft/keyboardLeft.vert" );
    keyboardLeft_SHADER_VertexStrings[0] = (char*)keyboardLeft_SHADER_VertexAssembly;
    glShaderSourceARB( keyboardLeft_SHADER_Vertex, 1, keyboardLeft_SHADER_VertexStrings, NULL );
    glCompileShaderARB( keyboardLeft_SHADER_Vertex);
    delete keyboardLeft_SHADER_VertexAssembly;

    keyboardLeft_SHADER_Fragment = glCreateShaderObjectARB( GL_FRAGMENT_SHADER_ARB );

    unsigned char *keyboardLeft_SHADER_FragmentAssembly = readShaderFile( "_MODEL_FOLDERS_/keyboardLeft/keyboardLeft.frag" );
    keyboardLeft_SHADER_FragmentStrings[0] = (char*)keyboardLeft_SHADER_FragmentAssembly;
    glShaderSourceARB( keyboardLeft_SHADER_Fragment, 1, keyboardLeft_SHADER_FragmentStrings, NULL );
    glCompileShaderARB(keyboardLeft_SHADER_Fragment );

    delete keyboardLeft_SHADER_FragmentAssembly;

	 keyboardLeft_SHADER = glCreateProgramObjectARB();

    glAttachObjectARB( keyboardLeft_SHADER, keyboardLeft_SHADER_Vertex );
    glAttachObjectARB( keyboardLeft_SHADER, keyboardLeft_SHADER_Fragment );

    glLinkProgramARB(keyboardLeft_SHADER); 

    UNIFORM_shininess_keyboardLeft = glGetUniformLocationARB(  keyboardLeft_SHADER, "shiny" );   

    UNIFORM_counter1_keyboardLeft = glGetUniformLocationARB( keyboardLeft_SHADER, "counter1" );
    UNIFORM_counter2_keyboardLeft = glGetUniformLocationARB( keyboardLeft_SHADER, "counter2" );
    UNIFORM_counter3_keyboardLeft = glGetUniformLocationARB( keyboardLeft_SHADER, "counter3" );
    UNIFORM_counter4_keyboardLeft = glGetUniformLocationARB( keyboardLeft_SHADER, "counter4" );

