    const char *marcLeftUpperArm_SHADER_VertexStrings[1];
    const char *marcLeftUpperArm_SHADER_FragmentStrings[1];

    marcLeftUpperArm_SHADER_Vertex = glCreateShaderObjectARB( GL_VERTEX_SHADER_ARB );

	 unsigned char *marcLeftUpperArm_SHADER_VertexAssembly   = readShaderFile( "_MODEL_FOLDERS_/marcParts/marcTorso/marcTorso.vert" );
    marcLeftUpperArm_SHADER_VertexStrings[0] = (char*)marcLeftUpperArm_SHADER_VertexAssembly;
    glShaderSourceARB( marcLeftUpperArm_SHADER_Vertex, 1, marcLeftUpperArm_SHADER_VertexStrings, NULL );
    glCompileShaderARB( marcLeftUpperArm_SHADER_Vertex);
    delete marcLeftUpperArm_SHADER_VertexAssembly;

    marcLeftUpperArm_SHADER_Fragment = glCreateShaderObjectARB( GL_FRAGMENT_SHADER_ARB );

    unsigned char *marcLeftUpperArm_SHADER_FragmentAssembly = readShaderFile( "_MODEL_FOLDERS_/marcParts/marcTorso/marcTorso.frag" );
    marcLeftUpperArm_SHADER_FragmentStrings[0] = (char*)marcLeftUpperArm_SHADER_FragmentAssembly;
    glShaderSourceARB( marcLeftUpperArm_SHADER_Fragment, 1, marcLeftUpperArm_SHADER_FragmentStrings, NULL );
    glCompileShaderARB( marcLeftUpperArm_SHADER_Fragment );

    delete marcLeftUpperArm_SHADER_FragmentAssembly;

	 marcLeftUpperArm_SHADER = glCreateProgramObjectARB();

    glAttachObjectARB( marcLeftUpperArm_SHADER, marcLeftUpperArm_SHADER_Vertex );
    glAttachObjectARB( marcLeftUpperArm_SHADER, marcLeftUpperArm_SHADER_Fragment );

    glLinkProgramARB(marcLeftUpperArm_SHADER); 

    UNIFORM_counter_marcLeftUpperArm = glGetUniformLocationARB( marcLeftUpperArm_SHADER, "counter" );

