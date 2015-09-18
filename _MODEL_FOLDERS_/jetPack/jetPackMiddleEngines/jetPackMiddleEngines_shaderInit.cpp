    const char *jetPackMiddleEngines_SHADER_VertexStrings[1];
    const char *jetPackMiddleEngines_SHADER_FragmentStrings[1];

    jetPackMiddleEngines_SHADER_Vertex = glCreateShaderObjectARB( GL_VERTEX_SHADER_ARB );

	 unsigned char *jetPackMiddleEngines_SHADER_VertexAssembly   = readShaderFile( "_MODEL_FOLDERS_/jetPack/jetPackMiddleEngines/jetPackMiddleEngines.vert" );
    jetPackMiddleEngines_SHADER_VertexStrings[0] = (char*)jetPackMiddleEngines_SHADER_VertexAssembly;
    glShaderSourceARB( jetPackMiddleEngines_SHADER_Vertex, 1, jetPackMiddleEngines_SHADER_VertexStrings, NULL );
    glCompileShaderARB( jetPackMiddleEngines_SHADER_Vertex);
    delete jetPackMiddleEngines_SHADER_VertexAssembly;

    jetPackMiddleEngines_SHADER_Fragment = glCreateShaderObjectARB( GL_FRAGMENT_SHADER_ARB );

    unsigned char *jetPackMiddleEngines_SHADER_FragmentAssembly = readShaderFile( "_MODEL_FOLDERS_/jetPack/jetPackMiddleEngines/jetPackMiddleEngines.frag" );
    jetPackMiddleEngines_SHADER_FragmentStrings[0] = (char*)jetPackMiddleEngines_SHADER_FragmentAssembly;
    glShaderSourceARB( jetPackMiddleEngines_SHADER_Fragment, 1, jetPackMiddleEngines_SHADER_FragmentStrings, NULL );
    glCompileShaderARB( jetPackMiddleEngines_SHADER_Fragment );

    delete jetPackMiddleEngines_SHADER_FragmentAssembly;

	 jetPackMiddleEngines_SHADER = glCreateProgramObjectARB();

    glAttachObjectARB( jetPackMiddleEngines_SHADER, jetPackMiddleEngines_SHADER_Vertex );
    glAttachObjectARB( jetPackMiddleEngines_SHADER, jetPackMiddleEngines_SHADER_Fragment );

    glLinkProgramARB(jetPackMiddleEngines_SHADER); 

    UNIFORM_counter_jetPackMiddleEngines = glGetUniformLocationARB( jetPackMiddleEngines_SHADER, "counter" );

