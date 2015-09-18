    const char *marcHeadBack_SHADER_VertexStrings[1];
    const char *marcHeadBack_SHADER_FragmentStrings[1];

    marcHeadBack_SHADER_Vertex = glCreateShaderObjectARB( GL_VERTEX_SHADER_ARB );

	 unsigned char *marcHeadBack_SHADER_VertexAssembly   = readShaderFile( "_MODEL_FOLDERS_/marcParts/marcTorso/marcTorso.vert" );
    marcHeadBack_SHADER_VertexStrings[0] = (char*)marcHeadBack_SHADER_VertexAssembly;
    glShaderSourceARB( marcHeadBack_SHADER_Vertex, 1, marcHeadBack_SHADER_VertexStrings, NULL );
    glCompileShaderARB( marcHeadBack_SHADER_Vertex);
    delete marcHeadBack_SHADER_VertexAssembly;

    marcHeadBack_SHADER_Fragment = glCreateShaderObjectARB( GL_FRAGMENT_SHADER_ARB );

    unsigned char *marcHeadBack_SHADER_FragmentAssembly = readShaderFile( "_MODEL_FOLDERS_/marcParts/marcTorso/marcTorso.frag" );
    marcHeadBack_SHADER_FragmentStrings[0] = (char*)marcHeadBack_SHADER_FragmentAssembly;
    glShaderSourceARB( marcHeadBack_SHADER_Fragment, 1, marcHeadBack_SHADER_FragmentStrings, NULL );
    glCompileShaderARB( marcHeadBack_SHADER_Fragment );

    delete marcHeadBack_SHADER_FragmentAssembly;

	 marcHeadBack_SHADER = glCreateProgramObjectARB();

    glAttachObjectARB( marcHeadBack_SHADER, marcHeadBack_SHADER_Vertex );
    glAttachObjectARB( marcHeadBack_SHADER, marcHeadBack_SHADER_Fragment );

    glLinkProgramARB(marcHeadBack_SHADER); 

    UNIFORM_counter_marcHeadBack = glGetUniformLocationARB( marcHeadBack_SHADER, "counter" );

