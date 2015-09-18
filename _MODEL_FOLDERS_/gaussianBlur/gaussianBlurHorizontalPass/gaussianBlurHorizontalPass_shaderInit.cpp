    const char *gaussianBlurHorizontalPass_SHADER_VertexStrings[1];
    const char *gaussianBlurHorizontalPass_SHADER_FragmentStrings[1];

    gaussianBlurHorizontalPass_SHADER_Vertex = glCreateShaderObjectARB( GL_VERTEX_SHADER_ARB );

	 unsigned char *gaussianBlurHorizontalPass_SHADER_VertexAssembly = readShaderFile( "_MODEL_FOLDERS_/gaussianBlur/gaussianBlurHorizontalPass/gaussianBlurHorizontalPass.vert" );
    gaussianBlurHorizontalPass_SHADER_VertexStrings[0] = (char*)gaussianBlurHorizontalPass_SHADER_VertexAssembly;
    glShaderSourceARB( gaussianBlurHorizontalPass_SHADER_Vertex, 1, gaussianBlurHorizontalPass_SHADER_VertexStrings, NULL );
    glCompileShaderARB( gaussianBlurHorizontalPass_SHADER_Vertex);
    delete gaussianBlurHorizontalPass_SHADER_VertexAssembly;

    gaussianBlurHorizontalPass_SHADER_Fragment = glCreateShaderObjectARB( GL_FRAGMENT_SHADER_ARB );

    unsigned char *gaussianBlurHorizontalPass_SHADER_FragmentAssembly = readShaderFile( "_MODEL_FOLDERS_/gaussianBlur/gaussianBlurHorizontalPass/gaussianBlurHorizontalPass.frag" );
    gaussianBlurHorizontalPass_SHADER_FragmentStrings[0] = (char*)gaussianBlurHorizontalPass_SHADER_FragmentAssembly;
    glShaderSourceARB( gaussianBlurHorizontalPass_SHADER_Fragment, 1, gaussianBlurHorizontalPass_SHADER_FragmentStrings, NULL );
    glCompileShaderARB(gaussianBlurHorizontalPass_SHADER_Fragment );

    delete gaussianBlurHorizontalPass_SHADER_FragmentAssembly;

	 gaussianBlurHorizontalPass_SHADER = glCreateProgramObjectARB();

    glAttachObjectARB( gaussianBlurHorizontalPass_SHADER, gaussianBlurHorizontalPass_SHADER_Vertex );
    glAttachObjectARB( gaussianBlurHorizontalPass_SHADER, gaussianBlurHorizontalPass_SHADER_Fragment );

    glLinkProgramARB(gaussianBlurHorizontalPass_SHADER); 

    UNIFORM_shininess_gaussianBlurHorizontalPass = glGetUniformLocationARB(  gaussianBlurHorizontalPass_SHADER, "shiny" );   

    UNIFORM_counter1_gaussianBlurHorizontalPass = glGetUniformLocationARB( gaussianBlurHorizontalPass_SHADER, "counter1" );

    UNIFORM_counter2_gaussianBlurHorizontalPass = glGetUniformLocationARB( gaussianBlurHorizontalPass_SHADER, "counter2" );

    UNIFORM_counter3_gaussianBlurHorizontalPass = glGetUniformLocationARB( gaussianBlurHorizontalPass_SHADER, "counter3" );

    UNIFORM_counter4_gaussianBlurHorizontalPass = glGetUniformLocationARB( gaussianBlurHorizontalPass_SHADER, "counter4" );

