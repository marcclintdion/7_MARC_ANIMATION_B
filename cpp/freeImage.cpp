		
		//FreeImage_Save(FIF_JPEG, dib, "mybitmap.jpg", JPEG_QUALITYSUPERB);
		


void loadTexture(char *textureFileName, GLuint &textureMapID)	
{
	FREE_IMAGE_FORMAT fifmt = FreeImage_GetFileType(textureFileName, 0);

	FIBITMAP *dib = FreeImage_Load(fifmt, textureFileName,0);

	FIBITMAP *temp = dib;
    dib = FreeImage_ConvertTo32Bits(temp);
    FreeImage_Unload(temp);	 
	
    if( dib != NULL )
	{
        glGenTextures( 1, &textureMapID );
		glBindTexture( GL_TEXTURE_2D, textureMapID );
        
         
        BYTE *pixels = (BYTE*)FreeImage_GetBits(dib);
        
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT_ARB);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT_ARB);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
       	glTexParameteri( GL_TEXTURE_2D, GL_GENERATE_MIPMAP_SGIS, GL_TRUE );
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, FreeImage_GetWidth(dib), FreeImage_GetHeight(dib), 0, GL_BGRA, GL_UNSIGNED_BYTE, pixels);		
      
        
        free(pixels);
        FreeImage_Unload(dib);
	}

}






