static float GlobalAmbient[3] = { 0.1, 0.1, 0.1 };  /* Dim */
static float LightColor[3] = { 0.95, 0.95, 0.95 };  /* White */

////////////////////________________CG_ENVIROMAPPING________________CG_ENVIROMAPPING________________CG_ENVIROMAPPING________________CG_ENVIROMAPPING
////////////////////________________CG_ENVIROMAPPING________________CG_ENVIROMAPPING________________CG_ENVIROMAPPING________________CG_ENVIROMAPPING
////////////////////________________CG_ENVIROMAPPING________________CG_ENVIROMAPPING________________CG_ENVIROMAPPING________________CG_ENVIROMAPPING
////////////////////________________CG_ENVIROMAPPING________________CG_ENVIROMAPPING________________CG_ENVIROMAPPING________________CG_ENVIROMAPPING
////////////////////________________CG_ENVIROMAPPING________________CG_ENVIROMAPPING________________CG_ENVIROMAPPING________________CG_ENVIROMAPPING


 GLfloat mudBallTimer_EmissionChannel[]  = {0.0f, 0.0f, 0.0f, 0.0f};


      


unsigned char *readShaderFile( const char *fileName )
{
    FILE *file = fopen( fileName, "r" );

    if( file == NULL )
    {
        MessageBox( NULL, "Cannot open shader file!", "ERROR",
            MB_OK | MB_ICONEXCLAMATION );
		return 0;
    }

    struct _stat fileStats;

    if( _stat( fileName, &fileStats ) != 0 )
    {
        MessageBox( NULL, "Cannot get file stats for shader file!", "ERROR",
                    MB_OK | MB_ICONEXCLAMATION );
        return 0;
    }

    unsigned char *buffer = new unsigned char[fileStats.st_size];

	int bytes = fread( buffer, 1, fileStats.st_size, file );

    buffer[bytes] = 0;

	fclose( file );

	return buffer;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////____________________SHADER_SETUP_____________SHADER_SETUP_____________SHADER_SETUP_____________SHADER_SETUP
/////////////////____________________SHADER_SETUP_____________SHADER_SETUP_____________SHADER_SETUP_____________SHADER_SETUP
/////////////////____________________SHADER_SETUP_____________SHADER_SETUP_____________SHADER_SETUP_____________SHADER_SETUP
/////////////////____________________SHADER_SETUP_____________SHADER_SETUP_____________SHADER_SETUP_____________SHADER_SETUP
/////////////////____________________SHADER_SETUP_____________SHADER_SETUP_____________SHADER_SETUP_____________SHADER_SETUP
   

     PFNGLDELETEOBJECTARBPROC         glDeleteObjectARB         = NULL;


     PFNGLSHADERSOURCEARBPROC         glShaderSourceARB         = NULL;
     PFNGLCOMPILESHADERARBPROC        glCompileShaderARB        = NULL;



     PFNGLLINKPROGRAMARBPROC          glLinkProgramARB          = NULL;
     PFNGLGETUNIFORMLOCATIONARBPROC   glGetUniformLocationARB   = NULL;
     PFNGLGETATTRIBLOCATIONARBPROC    glGetAttribLocationARB    = NULL;
   


     PFNGLUNIFORM3FARBPROC			  glUniform3fARB			= NULL;     
     PFNGLUNIFORM4FARBPROC			  glUniform4fARB			= NULL;
     PFNGLUNIFORM3FVARBPROC           glUniform3fvARB           = NULL;     
     PFNGLUNIFORM4FVARBPROC           glUniform4fvARB           = NULL;



PFNGLUNMAPBUFFERARBPROC pglUnmapBufferARB = 0;                   // unmap VBO procedure
  
          


#define glGenFramebuffersEXT                        pglGenFramebuffersEXT
#define glDeleteFramebuffersEXT                     pglDeleteFramebuffersEXT
#define glBindFramebufferEXT                        pglBindFramebufferEXT
#define glCheckFramebufferStatusEXT                 pglCheckFramebufferStatusEXT

#define glFramebufferTexture2DEXT                   pglFramebufferTexture2DEXT


#define glGenRenderbuffersEXT                       pglGenRenderbuffersEXT
#define glDeleteRenderbuffersEXT                    pglDeleteRenderbuffersEXT
#define glBindRenderbufferEXT                       pglBindRenderbufferEXT
#define glRenderbufferStorageEXT                    pglRenderbufferStorageEXT
#define glGetRenderbufferParameterivEXT             pglGetRenderbufferParameterivEXT
#define glIsRenderbufferEXT                         pglIsRenderbufferEXT

#define glMapBufferARB            pglMapBufferARB
#define glUnmapBufferARB          pglUnmapBufferARB   


void Dot3shader( void )
{
    char *ext = (char*)glGetString( GL_EXTENSIONS );

    if( strstr( ext, "GL_ARB_shading_language_100" ) == NULL )
    {
        MessageBox(NULL,"GL_ARB_shading_language_100 extension was not found",
            "ERROR",MB_OK|MB_ICONEXCLAMATION);
        return;
    }

    if( strstr( ext, "GL_ARB_shader_objects" ) == NULL )
    {
        MessageBox(NULL,"GL_ARB_shader_objects extension was not found",
            "ERROR",MB_OK|MB_ICONEXCLAMATION);
        return;
    }
    else
    {
       glCreateProgramObjectARB  = (PFNGLCREATEPROGRAMOBJECTARBPROC)wglGetProcAddress("glCreateProgramObjectARB");
       glDeleteObjectARB         = (PFNGLDELETEOBJECTARBPROC)wglGetProcAddress("glDeleteObjectARB");
       glUseProgramObjectARB     = (PFNGLUSEPROGRAMOBJECTARBPROC)wglGetProcAddress("glUseProgramObjectARB");
       glCreateShaderObjectARB   = (PFNGLCREATESHADEROBJECTARBPROC)wglGetProcAddress("glCreateShaderObjectARB");
       glShaderSourceARB         = (PFNGLSHADERSOURCEARBPROC)wglGetProcAddress("glShaderSourceARB");
       glCompileShaderARB        = (PFNGLCOMPILESHADERARBPROC)wglGetProcAddress("glCompileShaderARB");
       glGetObjectParameterivARB = (PFNGLGETOBJECTPARAMETERIVARBPROC)wglGetProcAddress("glGetObjectParameterivARB");
       glAttachObjectARB         = (PFNGLATTACHOBJECTARBPROC)wglGetProcAddress("glAttachObjectARB");
       glGetInfoLogARB           = (PFNGLGETINFOLOGARBPROC)wglGetProcAddress("glGetInfoLogARB");
       glLinkProgramARB          = (PFNGLLINKPROGRAMARBPROC)wglGetProcAddress("glLinkProgramARB");
       glGetUniformLocationARB   = (PFNGLGETUNIFORMLOCATIONARBPROC)wglGetProcAddress("glGetUniformLocationARB");
       glGetAttribLocationARB    = (PFNGLGETATTRIBLOCATIONARBPROC)wglGetProcAddress("glGetAttribLocationARB");
       glBindAttribLocationARB   = (PFNGLBINDATTRIBLOCATIONARBPROC)wglGetProcAddress("glBindAttribLocationARB");
       glUniform1iARB			 = (PFNGLUNIFORM1IARBPROC)wglGetProcAddress("glUniform1iARB");
       glUniform3fARB			 = (PFNGLUNIFORM3FARBPROC)wglGetProcAddress("glUniform3fARB");       
       glUniform4fARB			 = (PFNGLUNIFORM4FARBPROC)wglGetProcAddress("glUniform4fARB");
       glActiveTextureARB        = (PFNGLACTIVETEXTUREARBPROC)wglGetProcAddress("glActiveTextureARB");
       //glUniform1fARB            = (PFNGLUNIFORM1FARBPROC)wglGetProcAddress("glUniform1fARB");       
       glUniform3fvARB           = (PFNGLUNIFORM3FVARBPROC)wglGetProcAddress("glUniform3fvARB");       
       glUniform4fvARB           = (PFNGLUNIFORM4FVARBPROC)wglGetProcAddress("glUniform4fvARB");
       glUniformMatrix4fvARB     = (PFNGLUNIFORMMATRIX4FVARBPROC)wglGetProcAddress("glUniformMatrix4fvARB");
	   glMultiTexCoord2fARB      = (PFNGLMULTITEXCOORD2FARBPROC)wglGetProcAddress("glMultiTexCoord2fARB");
	   glMultiTexCoord3fARB      = (PFNGLMULTITEXCOORD3FARBPROC)wglGetProcAddress("glMultiTexCoord3fARB");
	   glMultiTexCoord2fvARB      = (PFNGLMULTITEXCOORD2FVARBPROC)wglGetProcAddress("glMultiTexCoord2fvARB");
	   glMultiTexCoord3fvARB      = (PFNGLMULTITEXCOORD3FVARBPROC)wglGetProcAddress("glMultiTexCoord3fvARB");                     	   
       glClientActiveTextureARB  = (PFNGLACTIVETEXTUREARBPROC)wglGetProcAddress("glClientActiveTextureARB");       
        //glMapBufferARB = (PFNGLMAPBUFFERARBPROC)wglGetProcAddress("glMapBufferARB");       
       glUnmapBufferARB          = (PFNGLUNMAPBUFFERARBPROC)wglGetProcAddress("glUnmapBufferARB");    


        if( !glCreateProgramObjectARB  || !glDeleteObjectARB       || !glUseProgramObjectARB ||
            !glCreateShaderObjectARB   || !glCreateShaderObjectARB || !glCompileShaderARB    || 
            !glGetObjectParameterivARB || !glAttachObjectARB       || !glGetInfoLogARB       || 
            !glLinkProgramARB          || !glGetUniformLocationARB || !glUniform4fARB        ||
			!glUniform1iARB            || !glMultiTexCoord2fARB    || !glClientActiveTextureARB)
        {
            MessageBox(NULL,"One or more GL_ARB_shader_objects functions were not found",
                "ERROR",MB_OK|MB_ICONEXCLAMATION);
            return;
        }
    }

/////////////////____________________SHADER_SETUP_____________SHADER_SETUP_____________SHADER_SETUP_____________SHADER_SETUP
/////////////////____________________SHADER_SETUP_____________SHADER_SETUP_____________SHADER_SETUP_____________SHADER_SETUP 
 
//------------------------------------------------------------------------------------------------------------------------
#include "_MODEL_FOLDERS_/gaussianBlur/gaussianBlurHorizontalPass/gaussianBlurHorizontalPass_shaderInit.cpp"  //vboID = 1

#include "_MODEL_FOLDERS_/gaussianBlur/gaussianBlurVerticalPass/gaussianBlurVerticalPass_shaderInit.cpp"  //vboID = 2


//------------------------------------------------------------------------------------------------------------------------ 
 
 
 
    const char *tiles_FBO_shadows_VertexStrings[1];
    const char *tiles_FBO_shadows_FragmentStrings[1];

    tiles_FBO_shadows_Vertex = glCreateShaderObjectARB( GL_VERTEX_SHADER_ARB );

	unsigned char *tiles_FBO_shadows_VertexAssembly = readShaderFile( "_MODEL_FOLDERS_/floorTiles/tiles_FBO_shadows.vert" );
    tiles_FBO_shadows_VertexStrings[0] = (char*)tiles_FBO_shadows_VertexAssembly;
    glShaderSourceARB( tiles_FBO_shadows_Vertex, 1, tiles_FBO_shadows_VertexStrings, NULL );
    glCompileShaderARB( tiles_FBO_shadows_Vertex);
    delete tiles_FBO_shadows_VertexAssembly;

    tiles_FBO_shadows_Fragment = glCreateShaderObjectARB( GL_FRAGMENT_SHADER_ARB );

    unsigned char *tiles_FBO_shadows_FragmentAssembly = readShaderFile( "_MODEL_FOLDERS_/floorTiles/tiles_FBO_shadows.frag" );
    tiles_FBO_shadows_FragmentStrings[0] = (char*)tiles_FBO_shadows_FragmentAssembly;
    glShaderSourceARB( tiles_FBO_shadows_Fragment, 1, tiles_FBO_shadows_FragmentStrings, NULL );
    glCompileShaderARB( tiles_FBO_shadows_Fragment );
    
    delete tiles_FBO_shadows_FragmentAssembly;
    
    tiles_FBO_shadows = glCreateProgramObjectARB();
    glAttachObjectARB( tiles_FBO_shadows, tiles_FBO_shadows_Vertex );
    glAttachObjectARB( tiles_FBO_shadows, tiles_FBO_shadows_Fragment );

    glLinkProgramARB( tiles_FBO_shadows );

    UNIFORM_displacement_X_tiles_1 = glGetUniformLocationARB( tiles_FBO_shadows, "textureDisplacement_X" ); 
    UNIFORM_displacement_Y_tiles_1 = glGetUniformLocationARB( tiles_FBO_shadows, "textureDisplacement_Y" );    
    UNIFORM_offset_X_tiles_1 = glGetUniformLocationARB( tiles_FBO_shadows, "offset_X" ); 
    UNIFORM_offset_Y_tiles_1 = glGetUniformLocationARB( tiles_FBO_shadows, "offset_Y" );    
    
    glUniform1f( UNIFORM_counter, tilesCounter); 
    
    UNIFORM_counter = glGetUniformLocationARB( tiles_FBO_shadows, "counter" ); 
    
    UNIFORM_lightPos_02_tiles_1 = glGetUniformLocationARB( tiles_FBO_shadows, "lightPosition_02" );
    UNIFORM_attenuation_02      = glGetUniformLocationARB( tiles_FBO_shadows, "attenuation_02" );



/////////////////____________________SHADER_SETUP_____________SHADER_SETUP_____________SHADER_SETUP_____________SHADER_SETUP          
/////////////////____________________SHADER_SETUP_____________SHADER_SETUP_____________SHADER_SETUP_____________SHADER_SETUP 






#include "_MODEL_FOLDERS_/marcParts/marcHeadBack/marcHeadBack_shaderInit.cpp" 
#include "_MODEL_FOLDERS_/marcParts/marcFace/marcFace_shaderInit.cpp"  
#include "_MODEL_FOLDERS_/marcParts/marcTorso/marcTorso_shaderInit.cpp"
#include "_MODEL_FOLDERS_/marcParts/marcHips/marcHips_shaderInit.cpp" 
#include "_MODEL_FOLDERS_/marcParts/marcRightUpperLeg/marcRightUpperLeg_shaderInit.cpp" 
#include "_MODEL_FOLDERS_/marcParts/marcRightLowerLeg/marcRightLowerLeg_shaderInit.cpp"  
#include "_MODEL_FOLDERS_/marcParts/marcRightUpperArm/marcRightUpperArm_shaderInit.cpp"  
#include "_MODEL_FOLDERS_/marcParts/marcRightForeArm/marcRightForeArm_shaderInit.cpp"
#include "_MODEL_FOLDERS_/marcParts/marcRightHand/marcRightHand_shaderInit.cpp"  
#include "_MODEL_FOLDERS_/marcParts/marcLeftUpperArm/marcLeftUpperArm_shaderInit.cpp"  
#include "_MODEL_FOLDERS_/marcParts/marcLeftForeArm/marcLeftForeArm_shaderInit.cpp" 
#include "_MODEL_FOLDERS_/marcParts/marcLeftHand/marcLeftHand_shaderInit.cpp"
#include "_MODEL_FOLDERS_/marcParts/marcRightBoot/marcRightBoot_shaderInit.cpp"  
#include "_MODEL_FOLDERS_/marcParts/marcLeftUpperLeg/marcLeftUpperLeg_shaderInit.cpp"  
#include "_MODEL_FOLDERS_/marcParts/marcLeftLowerLeg/marcLeftLowerLeg_shaderInit.cpp"  
#include "_MODEL_FOLDERS_/marcParts/marcLeftBoot/marcLeftBoot_shaderInit.cpp"  

#include "_MODEL_FOLDERS_/jetPack/jetPackVestStraps/jetPackVestStraps_shaderInit.cpp" 
#include "_MODEL_FOLDERS_/jetPack/jetPacksideHandles/jetPacksideHandles_shaderInit.cpp"  
#include "_MODEL_FOLDERS_/jetPack/jetPackBindings/jetPackBindings_shaderInit.cpp"  
#include "_MODEL_FOLDERS_/jetPack/jetPackTopCones/jetPackTopCones_shaderInit.cpp"  
#include "_MODEL_FOLDERS_/jetPack/jetPackMiddleEngines/jetPackMiddleEngines_shaderInit.cpp"  
#include "_MODEL_FOLDERS_/jetPack/jetPackNozzels/jetPackNozzels_shaderInit.cpp"  


#include "_MODEL_FOLDERS_/F1_F8/F1_F8_shaderInit.cpp"  //vboID = 573
 
//---------------------------------------------------------------------------------------------------------------------------

#include "HUD/marcDisplay_4view_shaderInit.cpp" 





/////////////////____________________SHADER_SETUP_____________SHADER_SETUP_____________SHADER_SETUP_____________SHADER_SETUP          
/////////////////____________________SHADER_SETUP_____________SHADER_SETUP_____________SHADER_SETUP_____________SHADER_SETUP

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////_______________________LOAD___BMP__TEXTURE_MAPS_______________________LOAD___BMP__TEXTURE_MAPS
/////////////////////////////////_______________________LOAD___BMP__TEXTURE_MAPS_______________________LOAD___BMP__TEXTURE_MAPS
/////////////////////////////////_______________________LOAD___BMP__TEXTURE_MAPS_______________________LOAD___BMP__TEXTURE_MAPS
/////////////////////////////////_______________________LOAD___BMP__TEXTURE_MAPS_______________________LOAD___BMP__TEXTURE_MAPS
/////////////////////////////////_______________________LOAD___BMP__TEXTURE_MAPS_______________________LOAD___BMP__TEXTURE_MAPS

/////////////////////////////////_______________________LOAD___BMP__TEXTURE_MAPS_______________________LOAD___BMP__TEXTURE_MAPS
/////////////////////////////////_______________________LOAD___BMP__TEXTURE_MAPS_______________________LOAD___BMP__TEXTURE_MAPS
/////////////////////////////////_______________________LOAD___BMP__TEXTURE_MAPS_______________________LOAD___BMP__TEXTURE_MAPS
/////////////////////////////////_______________________LOAD___BMP__TEXTURE_MAPS_______________________LOAD___BMP__TEXTURE_MAPS
/////////////////////////////////_______________________LOAD___BMP__TEXTURE_MAPS_______________________LOAD___BMP__TEXTURE_MAPS
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////_______________________LOAD___TGA__TEXTURE_MAPS_______________________LOAD___TGA__TEXTURE_MAPS
/////////////////////////////////_______________________LOAD___TGA__TEXTURE_MAPS_______________________LOAD___TGA__TEXTURE_MAPS
/////////////////////////////////_______________________LOAD___TGA__TEXTURE_MAPS_______________________LOAD___TGA__TEXTURE_MAPS
/////////////////////////////////_______________________LOAD___TGA__TEXTURE_MAPS_______________________LOAD___TGA__TEXTURE_MAPS
/////////////////////////////////_______________________LOAD___TGA__TEXTURE_MAPS_______________________LOAD___TGA__TEXTURE_MAPS

int LoadGLTextureTGA(char *textureFileName, GLuint &textureMapID)                                 
 {
    
    tgaImageFile tgaImage;
    tgaImage.load( textureFileName );
 
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glGenTextures( 1, &textureMapID );
    glEnable( GL_TEXTURE_2D );
    glBindTexture( GL_TEXTURE_2D, textureMapID );
    
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT_ARB );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT_ARB );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_NEAREST);
    gluBuild2DMipmaps(GL_TEXTURE_2D, tgaImage.m_texFormat, tgaImage.m_nImageWidth, tgaImage.m_nImageHeight, tgaImage.m_texFormat,  GL_UNSIGNED_BYTE, tgaImage.m_nImageData);

//-----------------------------------------------------------------------------
//           Name: ogl_alpha_blending_texture.cpp
//         Author: Kevin Harris
//  Last Modified: 03/25/05
return 0;
}
/////////////////////////////////_______________________LOAD___TGA__TEXTURE_MAPS_______________________LOAD___TGA__TEXTURE_MAPS
int LoadGLTextureTGA(char *textureFileName, char *normalMapFileName, GLuint &textureMapID, GLuint &normalMapID) 
{
      tgaImageFile tgaImage;
      tgaImage.load( textureFileName );
      
      glPixelStorei(GL_UNPACK_ALIGNMENT, 1);     
      glGenTextures( 1, &textureMapID );
      glEnable( GL_TEXTURE_2D );
      glBindTexture( GL_TEXTURE_2D, textureMapID );
      glPixelStorei( GL_UNPACK_ALIGNMENT, 1 );
	  glTexParameteri( GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_NEAREST );
	  glTexParameteri( GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST );
      gluBuild2DMipmaps(GL_TEXTURE_2D, tgaImage.m_texFormat, tgaImage.m_nImageWidth, 
                                       tgaImage.m_nImageHeight, tgaImage.m_texFormat, 
                                       GL_UNSIGNED_BYTE, tgaImage.m_nImageData);

      tgaImageFile tgaImage2;
      tgaImage2.load( textureFileName );
      
      glPixelStorei(GL_UNPACK_ALIGNMENT, 1);   
      glGenTextures( 1, &normalMapID );
      glEnable( GL_TEXTURE_2D );
      glBindTexture( GL_TEXTURE_2D, normalMapID );
      glPixelStorei( GL_UNPACK_ALIGNMENT, 1 );
	  glTexParameteri( GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_NEAREST );
	  glTexParameteri( GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST );
      gluBuild2DMipmaps(GL_TEXTURE_2D, tgaImage2.m_texFormat, tgaImage2.m_nImageWidth, 
                                      tgaImage2.m_nImageHeight, tgaImage2.m_texFormat, 
                                      GL_UNSIGNED_BYTE, tgaImage2.m_nImageData);    

  return 0;
                    //-----------------------------------------------------------------------------
//           Name: ogl_alpha_blending_texture.cpp
//         Author: Kevin Harris
//  Last Modified: 03/25/05
 }
/////////////////////////////////_______________________LOAD___TGA__TEXTURE_MAPS_______________________LOAD___TGA__TEXTURE_MAPS
/////////////////////////////////_______________________LOAD___TGA__TEXTURE_MAPS_______________________LOAD___TGA__TEXTURE_MAPS
/////////////////////////////////_______________________LOAD___TGA__TEXTURE_MAPS_______________________LOAD___TGA__TEXTURE_MAPS
/////////////////////////////////_______________________LOAD___TGA__TEXTURE_MAPS_______________________LOAD___TGA__TEXTURE_MAPS
/////////////////////////////////_______________________LOAD___TGA__TEXTURE_MAPS_______________________LOAD___TGA__TEXTURE_MAPS
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////__________________RUN_NMAP_SHADER__________________RUN_NMAP_SHADER__________________RUN_NMAP_SHADER__________________RUN_NMAP_SHADER
///////////__________________RUN_NMAP_SHADER__________________RUN_NMAP_SHADER__________________RUN_NMAP_SHADER__________________RUN_NMAP_SHADER
///////////__________________RUN_NMAP_SHADER__________________RUN_NMAP_SHADER__________________RUN_NMAP_SHADER__________________RUN_NMAP_SHADER
///////////__________________RUN_NMAP_SHADER__________________RUN_NMAP_SHADER__________________RUN_NMAP_SHADER__________________RUN_NMAP_SHADER
///////////__________________RUN_NMAP_SHADER__________________RUN_NMAP_SHADER__________________RUN_NMAP_SHADER__________________RUN_NMAP_SHADER
GLfloat texCoordMoveModels[] = {2,2};

void runNmapShader(int numTriangles, const GLvoid *ArrayName, GLuint texMap, GLuint normMap)
{  
    glUseProgramObjectARB(tiles_FBO_shadows);
    
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);    
    
    glActiveTextureARB(GL_TEXTURE2_ARB); 
    glMultiTexCoord2fvARB(GL_TEXTURE2_ARB, texCoordMoveModels);
    
     
    
    int DOT3_textureID;
    DOT3_textureID = glGetUniformLocationARB(tiles_FBO_shadows,"NormalMap");
    glUniform1iARB(DOT3_textureID, 1);
    glActiveTextureARB(GL_TEXTURE1_ARB);
    glBindTexture(GL_TEXTURE_2D, normMap);

    glActiveTextureARB(GL_TEXTURE0_ARB);
	glBindTexture(GL_TEXTURE_2D, texMap);

    glInterleavedArrays( GL_T2F_N3F_V3F, 0, ArrayName);
	glDrawArrays( GL_TRIANGLES, 0, numTriangles);
    glUseProgramObjectARB(0);
}

void runNmapShaderSpecular(int numTriangles, const GLvoid *ArrayName, GLuint texMap, GLuint normMap )
{  
    glUseProgramObjectARB(jetPackRockets);
    
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);    
    
    glActiveTextureARB(GL_TEXTURE2_ARB); 
    glMultiTexCoord2fvARB(GL_TEXTURE2_ARB, texCoordMoveModels);
    
    int DOT3_textureID;
    DOT3_textureID = glGetUniformLocationARB(jetPackRockets,"NormalMap");
    glUniform1iARB(DOT3_textureID, 1);
    glActiveTextureARB(GL_TEXTURE1_ARB);
    
    glBindTexture(GL_TEXTURE_2D, normMap);

    glActiveTextureARB(GL_TEXTURE0_ARB);
	glBindTexture(GL_TEXTURE_2D, texMap);

    glInterleavedArrays( GL_T2F_N3F_V3F, 0, ArrayName);
	glDrawArrays( GL_TRIANGLES, 0, numTriangles);
    glUseProgramObjectARB(0);
}
void runNmapShaderSpecularJetPackBindings(int numTriangles, const GLvoid *ArrayName, GLuint texMap, GLuint normMap)
{  
    glUseProgramObjectARB(jetPackBindingShader);
    
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);    
    
    glActiveTextureARB(GL_TEXTURE2_ARB); 

    int DOT3_textureID;
    DOT3_textureID = glGetUniformLocationARB(jetPackBindingShader,"NormalMap");
    glUniform1iARB(DOT3_textureID, 1);
    glActiveTextureARB(GL_TEXTURE1_ARB);
    
    glBindTexture(GL_TEXTURE_2D, normMap);

    glActiveTextureARB(GL_TEXTURE0_ARB);
	glBindTexture(GL_TEXTURE_2D, texMap);

    glInterleavedArrays( GL_T2F_N3F_V3F, 0, ArrayName);
	glDrawArrays( GL_TRIANGLES, 0, numTriangles);
    glUseProgramObjectARB(0);
}

void runNmapJetPackStraps(int numTriangles, const GLvoid *ArrayName, GLuint texMap, GLuint normMap, GLuint specMap )
{  
    glUseProgramObjectARB(jetPackStrapsShader);
    
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);    
    
    int SPECULAR_textureID;
    SPECULAR_textureID = glGetUniformLocationARB(jetPackStrapsShader,"SpecularMap");
    glUniform1iARB(SPECULAR_textureID, 2);
    glActiveTextureARB(GL_TEXTURE2_ARB);
    glBindTexture(GL_TEXTURE_2D, specMap);   
    
    int DOT3_textureID;
    DOT3_textureID = glGetUniformLocationARB(jetPackStrapsShader,"NormalMap");
    glUniform1iARB(DOT3_textureID, 1);
    glActiveTextureARB(GL_TEXTURE1_ARB);
    glBindTexture(GL_TEXTURE_2D, normMap);

    glActiveTextureARB(GL_TEXTURE0_ARB);
	glBindTexture(GL_TEXTURE_2D, texMap);

    glInterleavedArrays( GL_T2F_N3F_V3F, 0, ArrayName);
	glDrawArrays( GL_TRIANGLES, 0, numTriangles);
    glUseProgramObjectARB(0);
}

void runMarcFace_SHADER(int numTriangles, const GLvoid *ArrayName, GLuint texMap, GLuint normMap, GLuint specMap)
{  
    glUseProgramObjectARB(marcFace_SHADER);
    
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);    
    
    int SPECULAR_textureID;
    SPECULAR_textureID = glGetUniformLocationARB(marcFace_SHADER,"SpecularMap");
    glUniform1iARB(SPECULAR_textureID, 2);
    glActiveTextureARB(GL_TEXTURE2_ARB);
    glBindTexture(GL_TEXTURE_2D, specMap);   
    
    int DOT3_textureID;
    DOT3_textureID = glGetUniformLocationARB(marcFace_SHADER,"NormalMap");
    glUniform1iARB(DOT3_textureID, 1);
    glActiveTextureARB(GL_TEXTURE1_ARB);
    glBindTexture(GL_TEXTURE_2D, normMap);

    glActiveTextureARB(GL_TEXTURE0_ARB);
	glBindTexture(GL_TEXTURE_2D, texMap);

    glInterleavedArrays( GL_T2F_N3F_V3F, 0, ArrayName);
	glDrawArrays( GL_TRIANGLES, 0, numTriangles);
    glUseProgramObjectARB(0);
}

void runNmapShaderSideHandles(int numTriangles, const GLvoid *ArrayName, GLuint texMap, GLuint normMap)
{  
    glUseProgramObjectARB(jetPackSideHandles_SHADER);
    
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);    
    

    int DOT3_textureID;
    DOT3_textureID = glGetUniformLocationARB(jetPackSideHandles_SHADER,"NormalMap");
    glUniform1iARB(DOT3_textureID, 1);
    glActiveTextureARB(GL_TEXTURE1_ARB);
    
    glBindTexture(GL_TEXTURE_2D, normMap);

    glActiveTextureARB(GL_TEXTURE0_ARB);
	glBindTexture(GL_TEXTURE_2D, texMap);

    glInterleavedArrays( GL_T2F_N3F_V3F, 0, ArrayName);
	glDrawArrays( GL_TRIANGLES, 0, numTriangles);
    glUseProgramObjectARB(0);
}






