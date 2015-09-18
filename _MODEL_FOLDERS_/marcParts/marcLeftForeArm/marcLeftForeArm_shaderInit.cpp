    const char *marcLeftForeArm_SHADER_VertexStrings[1];
    const char *marcLeftForeArm_SHADER_FragmentStrings[1];

    marcLeftForeArm_SHADER_Vertex = glCreateShaderObjectARB( GL_VERTEX_SHADER_ARB );

	 unsigned char *marcLeftForeArm_SHADER_VertexAssembly   = readShaderFile( "_MODEL_FOLDERS_/marcParts/marcTorso/marcTorso.vert" );
    marcLeftForeArm_SHADER_VertexStrings[0] = (char*)marcLeftForeArm_SHADER_VertexAssembly;
    glShaderSourceARB( marcLeftForeArm_SHADER_Vertex, 1, marcLeftForeArm_SHADER_VertexStrings, NULL );
    glCompileShaderARB( marcLeftForeArm_SHADER_Vertex);
    delete marcLeftForeArm_SHADER_VertexAssembly;

    marcLeftForeArm_SHADER_Fragment = glCreateShaderObjectARB( GL_FRAGMENT_SHADER_ARB );

    unsigned char *marcLeftForeArm_SHADER_FragmentAssembly = readShaderFile( "_MODEL_FOLDERS_/marcParts/marcTorso/marcTorso.frag" );
    marcLeftForeArm_SHADER_FragmentStrings[0] = (char*)marcLeftForeArm_SHADER_FragmentAssembly;
    glShaderSourceARB( marcLeftForeArm_SHADER_Fragment, 1, marcLeftForeArm_SHADER_FragmentStrings, NULL );
    glCompileShaderARB( marcLeftForeArm_SHADER_Fragment );

    delete marcLeftForeArm_SHADER_FragmentAssembly;

	 marcLeftForeArm_SHADER = glCreateProgramObjectARB();

    glAttachObjectARB( marcLeftForeArm_SHADER, marcLeftForeArm_SHADER_Vertex );
    glAttachObjectARB( marcLeftForeArm_SHADER, marcLeftForeArm_SHADER_Fragment );

    glLinkProgramARB(marcLeftForeArm_SHADER); 

    UNIFORM_counter_marcLeftForeArm = glGetUniformLocationARB( marcLeftForeArm_SHADER, "counter" );

