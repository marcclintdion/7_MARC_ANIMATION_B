


float attenuation;

vec4 finalcolor;


vec3 normal;
vec3 lightDir1;


uniform sampler2D Texture1;			    // Our Texture no.1
uniform sampler2D NormalMap;			// Our Normal Map

void main( void )
{


    finalcolor         = texture2D(Texture1,gl_TexCoord[0].xy);     


	attenuation        = (gl_LightSource[0].quadraticAttenuation);

	
    finalcolor        *= attenuation; 

    
    gl_FragColor       = finalcolor; 
}

