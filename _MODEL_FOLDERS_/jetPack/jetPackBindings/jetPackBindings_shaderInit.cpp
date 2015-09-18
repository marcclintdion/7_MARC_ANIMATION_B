    const char *jetPackBindings_SHADER_VertexStrings[1];
    const char *jetPackBindings_SHADER_FragmentStrings[1];

    jetPackBindings_SHADER_Vertex = glCreateShaderObjectARB( GL_VERTEX_SHADER_ARB );

	 unsigned char *jetPackBindings_SHADER_VertexAssembly   = readShaderFile( "_MODEL_FOLDERS_/jetPack/jetPackBindings/jetPackBindings.vert" );
    jetPackBindings_SHADER_VertexStrings[0] = (char*)jetPackBindings_SHADER_VertexAssembly;
    glShaderSourceARB( jetPackBindings_SHADER_Vertex, 1, jetPackBindings_SHADER_VertexStrings, NULL );
    glCompileShaderARB( jetPackBindings_SHADER_Vertex);
    delete jetPackBindings_SHADER_VertexAssembly;

    jetPackBindings_SHADER_Fragment = glCreateShaderObjectARB( GL_FRAGMENT_SHADER_ARB );

    unsigned char *jetPackBindings_SHADER_FragmentAssembly = readShaderFile( "_MODEL_FOLDERS_/jetPack/jetPackBindings/jetPackBindings.frag" );
    jetPackBindings_SHADER_FragmentStrings[0] = (char*)jetPackBindings_SHADER_FragmentAssembly;
    glShaderSourceARB( jetPackBindings_SHADER_Fragment, 1, jetPackBindings_SHADER_FragmentStrings, NULL );
    glCompileShaderARB( jetPackBindings_SHADER_Fragment );

    delete jetPackBindings_SHADER_FragmentAssembly;

	 jetPackBindings_SHADER = glCreateProgramObjectARB();

    glAttachObjectARB( jetPackBindings_SHADER, jetPackBindings_SHADER_Vertex );
    glAttachObjectARB( jetPackBindings_SHADER, jetPackBindings_SHADER_Fragment );

    glLinkProgramARB(jetPackBindings_SHADER); 

    UNIFORM_counter_jetPackBindings = glGetUniformLocationARB( jetPackBindings_SHADER, "counter" );

