    const char *jetPackNozzels_SHADER_VertexStrings[1];
    const char *jetPackNozzels_SHADER_FragmentStrings[1];

    jetPackNozzels_SHADER_Vertex = glCreateShaderObjectARB( GL_VERTEX_SHADER_ARB );

	 unsigned char *jetPackNozzels_SHADER_VertexAssembly   = readShaderFile( "_MODEL_FOLDERS_/jetPack/jetPackNozzels/jetPackNozzels.vert" );
    jetPackNozzels_SHADER_VertexStrings[0] = (char*)jetPackNozzels_SHADER_VertexAssembly;
    glShaderSourceARB( jetPackNozzels_SHADER_Vertex, 1, jetPackNozzels_SHADER_VertexStrings, NULL );
    glCompileShaderARB( jetPackNozzels_SHADER_Vertex);
    delete jetPackNozzels_SHADER_VertexAssembly;

    jetPackNozzels_SHADER_Fragment = glCreateShaderObjectARB( GL_FRAGMENT_SHADER_ARB );

    unsigned char *jetPackNozzels_SHADER_FragmentAssembly = readShaderFile( "_MODEL_FOLDERS_/jetPack/jetPackNozzels/jetPackNozzels.frag" );
    jetPackNozzels_SHADER_FragmentStrings[0] = (char*)jetPackNozzels_SHADER_FragmentAssembly;
    glShaderSourceARB( jetPackNozzels_SHADER_Fragment, 1, jetPackNozzels_SHADER_FragmentStrings, NULL );
    glCompileShaderARB( jetPackNozzels_SHADER_Fragment );

    delete jetPackNozzels_SHADER_FragmentAssembly;

	 jetPackNozzels_SHADER = glCreateProgramObjectARB();

    glAttachObjectARB( jetPackNozzels_SHADER, jetPackNozzels_SHADER_Vertex );
    glAttachObjectARB( jetPackNozzels_SHADER, jetPackNozzels_SHADER_Fragment );

    glLinkProgramARB(jetPackNozzels_SHADER); 

    UNIFORM_counter_jetPackNozzels = glGetUniformLocationARB( jetPackNozzels_SHADER, "counter" );

