    const char *marcRightForeArm_SHADER_VertexStrings[1];
    const char *marcRightForeArm_SHADER_FragmentStrings[1];

    marcRightForeArm_SHADER_Vertex = glCreateShaderObjectARB( GL_VERTEX_SHADER_ARB );

	 unsigned char *marcRightForeArm_SHADER_VertexAssembly   = readShaderFile( "_MODEL_FOLDERS_/marcParts/marcTorso/marcTorso.vert" );
    marcRightForeArm_SHADER_VertexStrings[0] = (char*)marcRightForeArm_SHADER_VertexAssembly;
    glShaderSourceARB( marcRightForeArm_SHADER_Vertex, 1, marcRightForeArm_SHADER_VertexStrings, NULL );
    glCompileShaderARB( marcRightForeArm_SHADER_Vertex);
    delete marcRightForeArm_SHADER_VertexAssembly;

    marcRightForeArm_SHADER_Fragment = glCreateShaderObjectARB( GL_FRAGMENT_SHADER_ARB );

    unsigned char *marcRightForeArm_SHADER_FragmentAssembly = readShaderFile( "_MODEL_FOLDERS_/marcParts/marcTorso/marcTorso.frag" );
    marcRightForeArm_SHADER_FragmentStrings[0] = (char*)marcRightForeArm_SHADER_FragmentAssembly;
    glShaderSourceARB( marcRightForeArm_SHADER_Fragment, 1, marcRightForeArm_SHADER_FragmentStrings, NULL );
    glCompileShaderARB( marcRightForeArm_SHADER_Fragment );

    delete marcRightForeArm_SHADER_FragmentAssembly;

	 marcRightForeArm_SHADER = glCreateProgramObjectARB();

    glAttachObjectARB( marcRightForeArm_SHADER, marcRightForeArm_SHADER_Vertex );
    glAttachObjectARB( marcRightForeArm_SHADER, marcRightForeArm_SHADER_Fragment );

    glLinkProgramARB(marcRightForeArm_SHADER); 

    UNIFORM_counter_marcRightForeArm = glGetUniformLocationARB( marcRightForeArm_SHADER, "counter" );

