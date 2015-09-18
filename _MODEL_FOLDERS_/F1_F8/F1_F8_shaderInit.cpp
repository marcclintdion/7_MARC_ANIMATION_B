    const char *F1_F8_SHADER_VertexStrings[1];
    const char *F1_F8_SHADER_FragmentStrings[1];

    F1_F8_SHADER_Vertex = glCreateShaderObjectARB( GL_VERTEX_SHADER_ARB );

	 unsigned char *F1_F8_SHADER_VertexAssembly = readShaderFile( "_MODEL_FOLDERS_/F1_F8/F1_F8.vert" );
    F1_F8_SHADER_VertexStrings[0] = (char*)F1_F8_SHADER_VertexAssembly;
    glShaderSourceARB( F1_F8_SHADER_Vertex, 1, F1_F8_SHADER_VertexStrings, NULL );
    glCompileShaderARB( F1_F8_SHADER_Vertex);
    delete F1_F8_SHADER_VertexAssembly;

    F1_F8_SHADER_Fragment = glCreateShaderObjectARB( GL_FRAGMENT_SHADER_ARB );

    unsigned char *F1_F8_SHADER_FragmentAssembly = readShaderFile( "_MODEL_FOLDERS_/F1_F8/F1_F8.frag" );
    F1_F8_SHADER_FragmentStrings[0] = (char*)F1_F8_SHADER_FragmentAssembly;
    glShaderSourceARB( F1_F8_SHADER_Fragment, 1, F1_F8_SHADER_FragmentStrings, NULL );
    glCompileShaderARB(F1_F8_SHADER_Fragment );

    delete F1_F8_SHADER_FragmentAssembly;

	 F1_F8_SHADER = glCreateProgramObjectARB();

    glAttachObjectARB( F1_F8_SHADER, F1_F8_SHADER_Vertex );
    glAttachObjectARB( F1_F8_SHADER, F1_F8_SHADER_Fragment );

    glLinkProgramARB(F1_F8_SHADER); 

    UNIFORM_shininess_F1_F8 = glGetUniformLocationARB(  F1_F8_SHADER, "shiny" );   

    UNIFORM_counter1_F1_F8 = glGetUniformLocationARB( F1_F8_SHADER, "counter1" );

    UNIFORM_counter2_F1_F8 = glGetUniformLocationARB( F1_F8_SHADER, "counter2" );

    UNIFORM_counter3_F1_F8 = glGetUniformLocationARB( F1_F8_SHADER, "counter3" );

    UNIFORM_counter4_F1_F8 = glGetUniformLocationARB( F1_F8_SHADER, "counter4" );

