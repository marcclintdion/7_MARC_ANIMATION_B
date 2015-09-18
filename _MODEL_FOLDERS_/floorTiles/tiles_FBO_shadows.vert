varying vec4 position;
varying vec3 lightDir1;
varying float attenuation;

uniform float counter;

uniform float textureDisplacement_X;
uniform float textureDisplacement_Y;
uniform float offset_X;
uniform float offset_Y;



void main( void )
{
    gl_TexCoord[0]    = gl_MultiTexCoord0;
    gl_TexCoord[1]    = gl_MultiTexCoord0;

//////////////----------------------------    
    gl_TexCoord[1].x *= 0.1;
    gl_TexCoord[1].y *= 0.1;
    
    gl_TexCoord[1].x -= offset_X;
    gl_TexCoord[1].y -= offset_Y;    
  
//////////////----------------------------    
     

    position          = gl_ModelViewProjectionMatrix * gl_Vertex;
    gl_Position       = position;

}



