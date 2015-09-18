    const char *gaussianBlurVerticalPass_SHADER_VertexStrings[1];
    const char *gaussianBlurVerticalPass_SHADER_FragmentStrings[1];

    gaussianBlurVerticalPass_SHADER_Vertex = glCreateShaderObjectARB( GL_VERTEX_SHADER_ARB );

	 unsigned char *gaussianBlurVerticalPass_SHADER_VertexAssembly = readShaderFile( "_MODEL_FOLDERS_/gaussianBlur/gaussianBlurVerticalPass/gaussianBlurVerticalPass.vert" );
    gaussianBlurVerticalPass_SHADER_VertexStrings[0] = (char*)gaussianBlurVerticalPass_SHADER_VertexAssembly;
    glShaderSourceARB( gaussianBlurVerticalPass_SHADER_Vertex, 1, gaussianBlurVerticalPass_SHADER_VertexStrings, NULL );
    glCompileShaderARB( gaussianBlurVerticalPass_SHADER_Vertex);
    delete gaussianBlurVerticalPass_SHADER_VertexAssembly;

    gaussianBlurVerticalPass_SHADER_Fragment = glCreateShaderObjectARB( GL_FRAGMENT_SHADER_ARB );

    unsigned char *gaussianBlurVerticalPass_SHADER_FragmentAssembly = readShaderFile( "_MODEL_FOLDERS_/gaussianBlur/gaussianBlurVerticalPass/gaussianBlurVerticalPass.frag" );
    gaussianBlurVerticalPass_SHADER_FragmentStrings[0] = (char*)gaussianBlurVerticalPass_SHADER_FragmentAssembly;
    glShaderSourceARB( gaussianBlurVerticalPass_SHADER_Fragment, 1, gaussianBlurVerticalPass_SHADER_FragmentStrings, NULL );
    glCompileShaderARB(gaussianBlurVerticalPass_SHADER_Fragment );

    delete gaussianBlurVerticalPass_SHADER_FragmentAssembly;

	 gaussianBlurVerticalPass_SHADER = glCreateProgramObjectARB();

    glAttachObjectARB( gaussianBlurVerticalPass_SHADER, gaussianBlurVerticalPass_SHADER_Vertex );
    glAttachObjectARB( gaussianBlurVerticalPass_SHADER, gaussianBlurVerticalPass_SHADER_Fragment );

    glLinkProgramARB(gaussianBlurVerticalPass_SHADER); 

    UNIFORM_shininess_gaussianBlurVerticalPass = glGetUniformLocationARB(  gaussianBlurVerticalPass_SHADER, "shiny" );   

    UNIFORM_counter1_gaussianBlurVerticalPass = glGetUniformLocationARB( gaussianBlurVerticalPass_SHADER, "counter1" );

    UNIFORM_counter2_gaussianBlurVerticalPass = glGetUniformLocationARB( gaussianBlurVerticalPass_SHADER, "counter2" );

    UNIFORM_counter3_gaussianBlurVerticalPass = glGetUniformLocationARB( gaussianBlurVerticalPass_SHADER, "counter3" );

    UNIFORM_counter4_gaussianBlurVerticalPass = glGetUniformLocationARB( gaussianBlurVerticalPass_SHADER, "counter4" );

