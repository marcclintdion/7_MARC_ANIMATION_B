varying vec4 position;
varying vec3 lightDir1;
varying float attenuation;
uniform float counter;

float distance;  



vec3 normal;
varying vec3 vertexShaderNormal;

float NdotL1;

uniform sampler2D Texture1;
uniform sampler2D NormalMap;
uniform sampler2D SpecularMap;
		

vec4 finalcolor;	
vec3 NormalTex;
vec4 shadow;



void main( void )
{
    shadow           =  texture2D(SpecularMap,  gl_TexCoord[1].st);
    
    finalcolor       =  texture2D(Texture1,     gl_TexCoord[0].xy);	

    gl_FragColor     = (finalcolor * shadow);
}

