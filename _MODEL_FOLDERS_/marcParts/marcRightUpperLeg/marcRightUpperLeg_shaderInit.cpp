    const char *marcRightUpperLeg_SHADER_VertexStrings[1];
    const char *marcRightUpperLeg_SHADER_FragmentStrings[1];

    marcRightUpperLeg_SHADER_Vertex = glCreateShaderObjectARB( GL_VERTEX_SHADER_ARB );

	 unsigned char *marcRightUpperLeg_SHADER_VertexAssembly   = readShaderFile( "_MODEL_FOLDERS_/marcParts/marcTorso/marcTorso.vert" );
    marcRightUpperLeg_SHADER_VertexStrings[0] = (char*)marcRightUpperLeg_SHADER_VertexAssembly;
    glShaderSourceARB( marcRightUpperLeg_SHADER_Vertex, 1, marcRightUpperLeg_SHADER_VertexStrings, NULL );
    glCompileShaderARB( marcRightUpperLeg_SHADER_Vertex);
    delete marcRightUpperLeg_SHADER_VertexAssembly;

    marcRightUpperLeg_SHADER_Fragment = glCreateShaderObjectARB( GL_FRAGMENT_SHADER_ARB );

    unsigned char *marcRightUpperLeg_SHADER_FragmentAssembly = readShaderFile( "_MODEL_FOLDERS_/marcParts/marcTorso/marcTorso.frag" );
    marcRightUpperLeg_SHADER_FragmentStrings[0] = (char*)marcRightUpperLeg_SHADER_FragmentAssembly;
    glShaderSourceARB( marcRightUpperLeg_SHADER_Fragment, 1, marcRightUpperLeg_SHADER_FragmentStrings, NULL );
    glCompileShaderARB( marcRightUpperLeg_SHADER_Fragment );

    delete marcRightUpperLeg_SHADER_FragmentAssembly;

	 marcRightUpperLeg_SHADER = glCreateProgramObjectARB();

    glAttachObjectARB( marcRightUpperLeg_SHADER, marcRightUpperLeg_SHADER_Vertex );
    glAttachObjectARB( marcRightUpperLeg_SHADER, marcRightUpperLeg_SHADER_Fragment );

    glLinkProgramARB(marcRightUpperLeg_SHADER); 

    UNIFORM_counter_marcRightUpperLeg = glGetUniformLocationARB( marcRightUpperLeg_SHADER, "counter" );

