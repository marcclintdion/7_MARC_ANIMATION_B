    const char *jetPacksideHandles_SHADER_VertexStrings[1];
    const char *jetPacksideHandles_SHADER_FragmentStrings[1];

    jetPacksideHandles_SHADER_Vertex = glCreateShaderObjectARB( GL_VERTEX_SHADER_ARB );

	 unsigned char *jetPacksideHandles_SHADER_VertexAssembly   = readShaderFile( "_MODEL_FOLDERS_/jetPack/jetPacksideHandles/jetPacksideHandles.vert" );
    jetPacksideHandles_SHADER_VertexStrings[0] = (char*)jetPacksideHandles_SHADER_VertexAssembly;
    glShaderSourceARB( jetPacksideHandles_SHADER_Vertex, 1, jetPacksideHandles_SHADER_VertexStrings, NULL );
    glCompileShaderARB( jetPacksideHandles_SHADER_Vertex);
    delete jetPacksideHandles_SHADER_VertexAssembly;

    jetPacksideHandles_SHADER_Fragment = glCreateShaderObjectARB( GL_FRAGMENT_SHADER_ARB );

    unsigned char *jetPacksideHandles_SHADER_FragmentAssembly = readShaderFile( "_MODEL_FOLDERS_/jetPack/jetPacksideHandles/jetPacksideHandles.frag" );
    jetPacksideHandles_SHADER_FragmentStrings[0] = (char*)jetPacksideHandles_SHADER_FragmentAssembly;
    glShaderSourceARB( jetPacksideHandles_SHADER_Fragment, 1, jetPacksideHandles_SHADER_FragmentStrings, NULL );
    glCompileShaderARB( jetPacksideHandles_SHADER_Fragment );

    delete jetPacksideHandles_SHADER_FragmentAssembly;

	 jetPacksideHandles_SHADER = glCreateProgramObjectARB();

    glAttachObjectARB( jetPacksideHandles_SHADER, jetPacksideHandles_SHADER_Vertex );
    glAttachObjectARB( jetPacksideHandles_SHADER, jetPacksideHandles_SHADER_Fragment );

    glLinkProgramARB(jetPacksideHandles_SHADER); 

    UNIFORM_counter_jetPacksideHandles = glGetUniformLocationARB( jetPacksideHandles_SHADER, "counter" );

