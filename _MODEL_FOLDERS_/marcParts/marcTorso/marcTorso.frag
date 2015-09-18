varying vec4 position;
float distance;  
float attenuation;


vec3 normal;
vec3 lightDir1;

float NdotL1;

uniform sampler2D   Texture1;			    
uniform sampler2D   NormalMap;


vec3 lightPosMinusPos;


float diffuse;
float specular;

vec3 NormalTex;
vec4 textureTex;

void main( void )
{
    NormalTex        = texture2D(NormalMap,  gl_TexCoord[0].st).xyz;
    NormalTex        = (NormalTex - 0.5) * 2.0;
	normal           = normalize(NormalTex);
	
    lightPosMinusPos = gl_LightSource[0].position.xyz - position.xyz;
    lightDir1        = normalize(lightPosMinusPos);

	NdotL1           = dot(normal,lightDir1);
    attenuation      = 1.00 / (gl_LightSource[0].quadraticAttenuation);

    specular        += pow(NdotL1, 5.96 * 3.0) * 0.7; 

    textureTex       =  texture2D(Texture1, gl_TexCoord[0].xy);
    
    vec4 final       = NdotL1 * NdotL1 * attenuation * textureTex * 3.0;        
    gl_FragColor     = final + specular;
    

    
}


