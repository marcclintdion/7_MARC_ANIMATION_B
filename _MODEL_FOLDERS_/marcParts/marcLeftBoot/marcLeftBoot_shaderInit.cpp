    const char *marcLeftBoot_SHADER_VertexStrings[1];
    const char *marcLeftBoot_SHADER_FragmentStrings[1];

    marcLeftBoot_SHADER_Vertex = glCreateShaderObjectARB( GL_VERTEX_SHADER_ARB );

	 unsigned char *marcLeftBoot_SHADER_VertexAssembly   = readShaderFile( "_MODEL_FOLDERS_/marcParts/marcTorso/marcTorso.vert" );
    marcLeftBoot_SHADER_VertexStrings[0] = (char*)marcLeftBoot_SHADER_VertexAssembly;
    glShaderSourceARB( marcLeftBoot_SHADER_Vertex, 1, marcLeftBoot_SHADER_VertexStrings, NULL );
    glCompileShaderARB( marcLeftBoot_SHADER_Vertex);
    delete marcLeftBoot_SHADER_VertexAssembly;

    marcLeftBoot_SHADER_Fragment = glCreateShaderObjectARB( GL_FRAGMENT_SHADER_ARB );

    unsigned char *marcLeftBoot_SHADER_FragmentAssembly = readShaderFile( "_MODEL_FOLDERS_/marcParts/marcTorso/marcTorso.frag" );
    marcLeftBoot_SHADER_FragmentStrings[0] = (char*)marcLeftBoot_SHADER_FragmentAssembly;
    glShaderSourceARB( marcLeftBoot_SHADER_Fragment, 1, marcLeftBoot_SHADER_FragmentStrings, NULL );
    glCompileShaderARB( marcLeftBoot_SHADER_Fragment );

    delete marcLeftBoot_SHADER_FragmentAssembly;

	 marcLeftBoot_SHADER = glCreateProgramObjectARB();

    glAttachObjectARB( marcLeftBoot_SHADER, marcLeftBoot_SHADER_Vertex );
    glAttachObjectARB( marcLeftBoot_SHADER, marcLeftBoot_SHADER_Fragment );

    glLinkProgramARB(marcLeftBoot_SHADER); 

    UNIFORM_counter_marcLeftBoot = glGetUniformLocationARB( marcLeftBoot_SHADER, "counter" );

