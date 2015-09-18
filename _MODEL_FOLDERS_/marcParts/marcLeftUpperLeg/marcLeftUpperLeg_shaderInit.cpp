    const char *marcLeftUpperLeg_SHADER_VertexStrings[1];
    const char *marcLeftUpperLeg_SHADER_FragmentStrings[1];

    marcLeftUpperLeg_SHADER_Vertex = glCreateShaderObjectARB( GL_VERTEX_SHADER_ARB );

	 unsigned char *marcLeftUpperLeg_SHADER_VertexAssembly   = readShaderFile( "_MODEL_FOLDERS_/marcParts/marcTorso/marcTorso.vert" );
    marcLeftUpperLeg_SHADER_VertexStrings[0] = (char*)marcLeftUpperLeg_SHADER_VertexAssembly;
    glShaderSourceARB( marcLeftUpperLeg_SHADER_Vertex, 1, marcLeftUpperLeg_SHADER_VertexStrings, NULL );
    glCompileShaderARB( marcLeftUpperLeg_SHADER_Vertex);
    delete marcLeftUpperLeg_SHADER_VertexAssembly;

    marcLeftUpperLeg_SHADER_Fragment = glCreateShaderObjectARB( GL_FRAGMENT_SHADER_ARB );

    unsigned char *marcLeftUpperLeg_SHADER_FragmentAssembly = readShaderFile( "_MODEL_FOLDERS_/marcParts/marcTorso/marcTorso.frag" );
    marcLeftUpperLeg_SHADER_FragmentStrings[0] = (char*)marcLeftUpperLeg_SHADER_FragmentAssembly;
    glShaderSourceARB( marcLeftUpperLeg_SHADER_Fragment, 1, marcLeftUpperLeg_SHADER_FragmentStrings, NULL );
    glCompileShaderARB( marcLeftUpperLeg_SHADER_Fragment );

    delete marcLeftUpperLeg_SHADER_FragmentAssembly;

	 marcLeftUpperLeg_SHADER = glCreateProgramObjectARB();

    glAttachObjectARB( marcLeftUpperLeg_SHADER, marcLeftUpperLeg_SHADER_Vertex );
    glAttachObjectARB( marcLeftUpperLeg_SHADER, marcLeftUpperLeg_SHADER_Fragment );

    glLinkProgramARB(marcLeftUpperLeg_SHADER); 

    UNIFORM_counter_marcLeftUpperLeg = glGetUniformLocationARB( marcLeftUpperLeg_SHADER, "counter" );

