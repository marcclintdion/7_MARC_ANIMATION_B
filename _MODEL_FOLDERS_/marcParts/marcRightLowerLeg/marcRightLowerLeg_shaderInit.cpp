    const char *marcRightLowerLeg_SHADER_VertexStrings[1];
    const char *marcRightLowerLeg_SHADER_FragmentStrings[1];

    marcRightLowerLeg_SHADER_Vertex = glCreateShaderObjectARB( GL_VERTEX_SHADER_ARB );

	 unsigned char *marcRightLowerLeg_SHADER_VertexAssembly   = readShaderFile( "_MODEL_FOLDERS_/marcParts/marcTorso/marcTorso.vert" );
    marcRightLowerLeg_SHADER_VertexStrings[0] = (char*)marcRightLowerLeg_SHADER_VertexAssembly;
    glShaderSourceARB( marcRightLowerLeg_SHADER_Vertex, 1, marcRightLowerLeg_SHADER_VertexStrings, NULL );
    glCompileShaderARB( marcRightLowerLeg_SHADER_Vertex);
    delete marcRightLowerLeg_SHADER_VertexAssembly;

    marcRightLowerLeg_SHADER_Fragment = glCreateShaderObjectARB( GL_FRAGMENT_SHADER_ARB );

    unsigned char *marcRightLowerLeg_SHADER_FragmentAssembly = readShaderFile( "_MODEL_FOLDERS_/marcParts/marcTorso/marcTorso.frag" );
    marcRightLowerLeg_SHADER_FragmentStrings[0] = (char*)marcRightLowerLeg_SHADER_FragmentAssembly;
    glShaderSourceARB( marcRightLowerLeg_SHADER_Fragment, 1, marcRightLowerLeg_SHADER_FragmentStrings, NULL );
    glCompileShaderARB( marcRightLowerLeg_SHADER_Fragment );

    delete marcRightLowerLeg_SHADER_FragmentAssembly;

	 marcRightLowerLeg_SHADER = glCreateProgramObjectARB();

    glAttachObjectARB( marcRightLowerLeg_SHADER, marcRightLowerLeg_SHADER_Vertex );
    glAttachObjectARB( marcRightLowerLeg_SHADER, marcRightLowerLeg_SHADER_Fragment );

    glLinkProgramARB(marcRightLowerLeg_SHADER); 

    UNIFORM_counter_marcRightLowerLeg = glGetUniformLocationARB( marcRightLowerLeg_SHADER, "counter" );

