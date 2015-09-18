    const char *jetPackVestStraps_SHADER_VertexStrings[1];
    const char *jetPackVestStraps_SHADER_FragmentStrings[1];

    jetPackVestStraps_SHADER_Vertex = glCreateShaderObjectARB( GL_VERTEX_SHADER_ARB );

	 unsigned char *jetPackVestStraps_SHADER_VertexAssembly   = readShaderFile( "_MODEL_FOLDERS_/jetPack/jetPackVestStraps/jetPackVestStraps.vert" );
    jetPackVestStraps_SHADER_VertexStrings[0] = (char*)jetPackVestStraps_SHADER_VertexAssembly;
    glShaderSourceARB( jetPackVestStraps_SHADER_Vertex, 1, jetPackVestStraps_SHADER_VertexStrings, NULL );
    glCompileShaderARB( jetPackVestStraps_SHADER_Vertex);
    delete jetPackVestStraps_SHADER_VertexAssembly;

    jetPackVestStraps_SHADER_Fragment = glCreateShaderObjectARB( GL_FRAGMENT_SHADER_ARB );

    unsigned char *jetPackVestStraps_SHADER_FragmentAssembly = readShaderFile( "_MODEL_FOLDERS_/jetPack/jetPackVestStraps/jetPackVestStraps.frag" );
    jetPackVestStraps_SHADER_FragmentStrings[0] = (char*)jetPackVestStraps_SHADER_FragmentAssembly;
    glShaderSourceARB( jetPackVestStraps_SHADER_Fragment, 1, jetPackVestStraps_SHADER_FragmentStrings, NULL );
    glCompileShaderARB( jetPackVestStraps_SHADER_Fragment );

    delete jetPackVestStraps_SHADER_FragmentAssembly;

	 jetPackVestStraps_SHADER = glCreateProgramObjectARB();

    glAttachObjectARB( jetPackVestStraps_SHADER, jetPackVestStraps_SHADER_Vertex );
    glAttachObjectARB( jetPackVestStraps_SHADER, jetPackVestStraps_SHADER_Fragment );

    glLinkProgramARB(jetPackVestStraps_SHADER); 

    UNIFORM_counter_jetPackVestStraps = glGetUniformLocationARB( jetPackVestStraps_SHADER, "counter" );

