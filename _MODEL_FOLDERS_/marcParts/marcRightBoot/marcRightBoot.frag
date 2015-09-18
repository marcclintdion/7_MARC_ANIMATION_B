varying vec4 pos;

uniform vec3  nMapLightPosition;
uniform float nMapLightAttenuation;

float distance;  // Distance between light position and fragment
float NdotL1;     // Dot product of normal and lightDir
float NdotL2; 
float attenuation;

vec4 finalcolor;
vec4 diffuse = vec4(2.0,2.0,2.0,1.0);

vec3 normal;
vec3 lightDir1;
vec3 lightDir2;

uniform sampler2D Texture1;			    // Our Texture no.1
uniform sampler2D NormalMap;			// Our Normal Map

void main( void )
{


	vec3 NormalTex     = texture2D(NormalMap, gl_TexCoord[0].st).xyz;
    NormalTex          = (NormalTex - 0.5) * 2.0;
    normal             = normalize(NormalTex);
    
    finalcolor         = texture2D(Texture1,gl_TexCoord[0].xy);     

	lightDir1          = normalize(vec3(gl_LightSource[0].position-pos));
    NdotL1             = max(dot(normal,lightDir1),0.0);
    
    distance           = length(vec3(gl_LightSource[0].position-pos));
	attenuation        = 1.00 / (gl_LightSource[0].quadraticAttenuation * distance * distance);

	
    finalcolor        *= attenuation * (diffuse * NdotL1); 

    if(NdotL1 >= 0)
    {
         finalcolor +=   pow(max(NdotL1, 0.0), 100.0)*.2;
    }	
    
    gl_FragColor       = finalcolor; 
}
