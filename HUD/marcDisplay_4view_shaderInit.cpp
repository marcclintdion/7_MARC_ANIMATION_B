    const char *marcDisplay_4view_VertexStrings[1];
    const char *marcDisplay_4view_FragmentStrings[1];

    marcDisplay_4view_Vertex = glCreateShaderObjectARB( GL_VERTEX_SHADER_ARB );

	 unsigned char *marcDisplay_4view_VertexAssembly   = readShaderFile( "HUD/marcDisplay_4view.vert" );
    marcDisplay_4view_VertexStrings[0] = (char*)marcDisplay_4view_VertexAssembly;
    glShaderSourceARB( marcDisplay_4view_Vertex, 1, marcDisplay_4view_VertexStrings, NULL );
    glCompileShaderARB( marcDisplay_4view_Vertex);
    delete marcDisplay_4view_VertexAssembly;

    marcDisplay_4view_Fragment = glCreateShaderObjectARB( GL_FRAGMENT_SHADER_ARB );

    unsigned char *marcDisplay_4view_FragmentAssembly = readShaderFile( "HUD/marcDisplay_4view.frag" );
    marcDisplay_4view_FragmentStrings[0] = (char*)marcDisplay_4view_FragmentAssembly;
    glShaderSourceARB( marcDisplay_4view_Fragment, 1, marcDisplay_4view_FragmentStrings, NULL );
    glCompileShaderARB( marcDisplay_4view_Fragment );

    delete marcDisplay_4view_FragmentAssembly;

	 marcDisplay_4view_SHADER = glCreateProgramObjectARB();

    glAttachObjectARB( marcDisplay_4view_SHADER, marcDisplay_4view_Vertex );
    glAttachObjectARB( marcDisplay_4view_SHADER, marcDisplay_4view_Fragment );

    glLinkProgramARB(marcDisplay_4view_SHADER); 

    UNIFORM_counter_marcDisplay_4view = glGetUniformLocationARB( marcDisplay_4view_SHADER, "counter" );

