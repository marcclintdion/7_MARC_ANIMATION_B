    const char *marcLeftLowerLeg_SHADER_VertexStrings[1];
    const char *marcLeftLowerLeg_SHADER_FragmentStrings[1];

    marcLeftLowerLeg_SHADER_Vertex = glCreateShaderObjectARB( GL_VERTEX_SHADER_ARB );

	 unsigned char *marcLeftLowerLeg_SHADER_VertexAssembly   = readShaderFile( "_MODEL_FOLDERS_/marcParts/marcTorso/marcTorso.vert" );
    marcLeftLowerLeg_SHADER_VertexStrings[0] = (char*)marcLeftLowerLeg_SHADER_VertexAssembly;
    glShaderSourceARB( marcLeftLowerLeg_SHADER_Vertex, 1, marcLeftLowerLeg_SHADER_VertexStrings, NULL );
    glCompileShaderARB( marcLeftLowerLeg_SHADER_Vertex);
    delete marcLeftLowerLeg_SHADER_VertexAssembly;

    marcLeftLowerLeg_SHADER_Fragment = glCreateShaderObjectARB( GL_FRAGMENT_SHADER_ARB );

    unsigned char *marcLeftLowerLeg_SHADER_FragmentAssembly = readShaderFile( "_MODEL_FOLDERS_/marcParts/marcTorso/marcTorso.frag" );
    marcLeftLowerLeg_SHADER_FragmentStrings[0] = (char*)marcLeftLowerLeg_SHADER_FragmentAssembly;
    glShaderSourceARB( marcLeftLowerLeg_SHADER_Fragment, 1, marcLeftLowerLeg_SHADER_FragmentStrings, NULL );
    glCompileShaderARB( marcLeftLowerLeg_SHADER_Fragment );

    delete marcLeftLowerLeg_SHADER_FragmentAssembly;

	 marcLeftLowerLeg_SHADER = glCreateProgramObjectARB();

    glAttachObjectARB( marcLeftLowerLeg_SHADER, marcLeftLowerLeg_SHADER_Vertex );
    glAttachObjectARB( marcLeftLowerLeg_SHADER, marcLeftLowerLeg_SHADER_Fragment );

    glLinkProgramARB(marcLeftLowerLeg_SHADER); 

    UNIFORM_counter_marcLeftLowerLeg = glGetUniformLocationARB( marcLeftLowerLeg_SHADER, "counter" );

