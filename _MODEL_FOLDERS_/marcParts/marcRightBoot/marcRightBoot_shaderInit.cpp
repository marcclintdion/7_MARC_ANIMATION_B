    const char *marcRightBoot_SHADER_VertexStrings[1];
    const char *marcRightBoot_SHADER_FragmentStrings[1];

    marcRightBoot_SHADER_Vertex = glCreateShaderObjectARB( GL_VERTEX_SHADER_ARB );

	 unsigned char *marcRightBoot_SHADER_VertexAssembly   = readShaderFile( "_MODEL_FOLDERS_/marcParts/marcTorso/marcTorso.vert" );
    marcRightBoot_SHADER_VertexStrings[0] = (char*)marcRightBoot_SHADER_VertexAssembly;
    glShaderSourceARB( marcRightBoot_SHADER_Vertex, 1, marcRightBoot_SHADER_VertexStrings, NULL );
    glCompileShaderARB( marcRightBoot_SHADER_Vertex);
    delete marcRightBoot_SHADER_VertexAssembly;

    marcRightBoot_SHADER_Fragment = glCreateShaderObjectARB( GL_FRAGMENT_SHADER_ARB );

    unsigned char *marcRightBoot_SHADER_FragmentAssembly = readShaderFile( "_MODEL_FOLDERS_/marcParts/marcTorso/marcTorso.frag" );
    marcRightBoot_SHADER_FragmentStrings[0] = (char*)marcRightBoot_SHADER_FragmentAssembly;
    glShaderSourceARB( marcRightBoot_SHADER_Fragment, 1, marcRightBoot_SHADER_FragmentStrings, NULL );
    glCompileShaderARB( marcRightBoot_SHADER_Fragment );

    delete marcRightBoot_SHADER_FragmentAssembly;

	 marcRightBoot_SHADER = glCreateProgramObjectARB();

    glAttachObjectARB( marcRightBoot_SHADER, marcRightBoot_SHADER_Vertex );
    glAttachObjectARB( marcRightBoot_SHADER, marcRightBoot_SHADER_Fragment );

    glLinkProgramARB(marcRightBoot_SHADER); 

    UNIFORM_counter_marcRightBoot = glGetUniformLocationARB( marcRightBoot_SHADER, "counter" );

