    const char *marcTorso_SHADER_VertexStrings[1];
    const char *marcTorso_SHADER_FragmentStrings[1];

    marcTorso_SHADER_Vertex = glCreateShaderObjectARB( GL_VERTEX_SHADER_ARB );

	 unsigned char *marcTorso_SHADER_VertexAssembly   = readShaderFile( "_MODEL_FOLDERS_/marcParts/marcTorso/marcTorso.vert" );
    marcTorso_SHADER_VertexStrings[0] = (char*)marcTorso_SHADER_VertexAssembly;
    glShaderSourceARB( marcTorso_SHADER_Vertex, 1, marcTorso_SHADER_VertexStrings, NULL );
    glCompileShaderARB( marcTorso_SHADER_Vertex);
    delete marcTorso_SHADER_VertexAssembly;

    marcTorso_SHADER_Fragment = glCreateShaderObjectARB( GL_FRAGMENT_SHADER_ARB );

    unsigned char *marcTorso_SHADER_FragmentAssembly = readShaderFile( "_MODEL_FOLDERS_/marcParts/marcTorso/marcTorso.frag" );
    marcTorso_SHADER_FragmentStrings[0] = (char*)marcTorso_SHADER_FragmentAssembly;
    glShaderSourceARB( marcTorso_SHADER_Fragment, 1, marcTorso_SHADER_FragmentStrings, NULL );
    glCompileShaderARB( marcTorso_SHADER_Fragment );

    delete marcTorso_SHADER_FragmentAssembly;

	 marcTorso_SHADER = glCreateProgramObjectARB();

    glAttachObjectARB( marcTorso_SHADER, marcTorso_SHADER_Vertex );
    glAttachObjectARB( marcTorso_SHADER, marcTorso_SHADER_Fragment );

    glLinkProgramARB(marcTorso_SHADER); 

    UNIFORM_bodyPartSelection = glGetUniformLocationARB( marcTorso_SHADER, "COLOR_CHANGE" );

    UNIFORM_counter_marcTorso = glGetUniformLocationARB( marcTorso_SHADER, "counter" );

