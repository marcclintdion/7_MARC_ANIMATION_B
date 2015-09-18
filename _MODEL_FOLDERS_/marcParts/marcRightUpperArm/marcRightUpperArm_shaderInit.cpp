    const char *marcRightUpperArm_SHADER_VertexStrings[1];
    const char *marcRightUpperArm_SHADER_FragmentStrings[1];

    marcRightUpperArm_SHADER_Vertex = glCreateShaderObjectARB( GL_VERTEX_SHADER_ARB );

	 unsigned char *marcRightUpperArm_SHADER_VertexAssembly   = readShaderFile( "_MODEL_FOLDERS_/marcParts/marcTorso/marcTorso.vert" );
    marcRightUpperArm_SHADER_VertexStrings[0] = (char*)marcRightUpperArm_SHADER_VertexAssembly;
    glShaderSourceARB( marcRightUpperArm_SHADER_Vertex, 1, marcRightUpperArm_SHADER_VertexStrings, NULL );
    glCompileShaderARB( marcRightUpperArm_SHADER_Vertex);
    delete marcRightUpperArm_SHADER_VertexAssembly;

    marcRightUpperArm_SHADER_Fragment = glCreateShaderObjectARB( GL_FRAGMENT_SHADER_ARB );

    unsigned char *marcRightUpperArm_SHADER_FragmentAssembly = readShaderFile( "_MODEL_FOLDERS_/marcParts/marcTorso/marcTorso.frag" );
    marcRightUpperArm_SHADER_FragmentStrings[0] = (char*)marcRightUpperArm_SHADER_FragmentAssembly;
    glShaderSourceARB( marcRightUpperArm_SHADER_Fragment, 1, marcRightUpperArm_SHADER_FragmentStrings, NULL );
    glCompileShaderARB( marcRightUpperArm_SHADER_Fragment );

    delete marcRightUpperArm_SHADER_FragmentAssembly;

	 marcRightUpperArm_SHADER = glCreateProgramObjectARB();

    glAttachObjectARB( marcRightUpperArm_SHADER, marcRightUpperArm_SHADER_Vertex );
    glAttachObjectARB( marcRightUpperArm_SHADER, marcRightUpperArm_SHADER_Fragment );

    glLinkProgramARB(marcRightUpperArm_SHADER); 

