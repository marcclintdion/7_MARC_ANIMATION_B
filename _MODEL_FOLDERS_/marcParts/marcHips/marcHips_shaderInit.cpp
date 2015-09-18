    const char *marcHips_SHADER_VertexStrings[1];
    const char *marcHips_SHADER_FragmentStrings[1];

    marcHips_SHADER_Vertex = glCreateShaderObjectARB( GL_VERTEX_SHADER_ARB );

	 unsigned char *marcHips_SHADER_VertexAssembly   = readShaderFile( "_MODEL_FOLDERS_/marcParts/marcTorso/marcTorso.vert" );
    marcHips_SHADER_VertexStrings[0] = (char*)marcHips_SHADER_VertexAssembly;
    glShaderSourceARB( marcHips_SHADER_Vertex, 1, marcHips_SHADER_VertexStrings, NULL );
    glCompileShaderARB( marcHips_SHADER_Vertex);
    delete marcHips_SHADER_VertexAssembly;

    marcHips_SHADER_Fragment = glCreateShaderObjectARB( GL_FRAGMENT_SHADER_ARB );

    unsigned char *marcHips_SHADER_FragmentAssembly = readShaderFile( "_MODEL_FOLDERS_/marcParts/marcTorso/marcTorso.frag" );
    marcHips_SHADER_FragmentStrings[0] = (char*)marcHips_SHADER_FragmentAssembly;
    glShaderSourceARB( marcHips_SHADER_Fragment, 1, marcHips_SHADER_FragmentStrings, NULL );
    glCompileShaderARB( marcHips_SHADER_Fragment );

    delete marcHips_SHADER_FragmentAssembly;

	 marcHips_SHADER = glCreateProgramObjectARB();

    glAttachObjectARB( marcHips_SHADER, marcHips_SHADER_Vertex );
    glAttachObjectARB( marcHips_SHADER, marcHips_SHADER_Fragment );

    glLinkProgramARB(marcHips_SHADER); 

    UNIFORM_counter_marcHips = glGetUniformLocationARB( marcHips_SHADER, "counter" );

