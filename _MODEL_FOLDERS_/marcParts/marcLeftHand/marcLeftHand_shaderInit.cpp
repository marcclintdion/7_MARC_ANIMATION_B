    const char *marcLeftHand_SHADER_VertexStrings[1];
    const char *marcLeftHand_SHADER_FragmentStrings[1];

    marcLeftHand_SHADER_Vertex = glCreateShaderObjectARB( GL_VERTEX_SHADER_ARB );

	 unsigned char *marcLeftHand_SHADER_VertexAssembly   = readShaderFile( "_MODEL_FOLDERS_/marcParts/marcTorso/marcTorso.vert" );
    marcLeftHand_SHADER_VertexStrings[0] = (char*)marcLeftHand_SHADER_VertexAssembly;
    glShaderSourceARB( marcLeftHand_SHADER_Vertex, 1, marcLeftHand_SHADER_VertexStrings, NULL );
    glCompileShaderARB( marcLeftHand_SHADER_Vertex);
    delete marcLeftHand_SHADER_VertexAssembly;

    marcLeftHand_SHADER_Fragment = glCreateShaderObjectARB( GL_FRAGMENT_SHADER_ARB );

    unsigned char *marcLeftHand_SHADER_FragmentAssembly = readShaderFile( "_MODEL_FOLDERS_/marcParts/marcTorso/marcTorso.frag" );
    marcLeftHand_SHADER_FragmentStrings[0] = (char*)marcLeftHand_SHADER_FragmentAssembly;
    glShaderSourceARB( marcLeftHand_SHADER_Fragment, 1, marcLeftHand_SHADER_FragmentStrings, NULL );
    glCompileShaderARB( marcLeftHand_SHADER_Fragment );

    delete marcLeftHand_SHADER_FragmentAssembly;

	 marcLeftHand_SHADER = glCreateProgramObjectARB();

    glAttachObjectARB( marcLeftHand_SHADER, marcLeftHand_SHADER_Vertex );
    glAttachObjectARB( marcLeftHand_SHADER, marcLeftHand_SHADER_Fragment );

    glLinkProgramARB(marcLeftHand_SHADER); 

    UNIFORM_counter_marcLeftHand = glGetUniformLocationARB( marcLeftHand_SHADER, "counter" );

