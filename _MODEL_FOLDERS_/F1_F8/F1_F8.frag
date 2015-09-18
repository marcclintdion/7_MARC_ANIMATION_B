uniform float counter1;
uniform float counter2;
uniform float counter3;
uniform float counter4;

varying vec4 position;

float distance;  
varying float attenuation;

uniform sampler2D Texture1;
uniform sampler2D NormalMap;

vec4   finalcolor;
vec3   normal;

varying vec3 lightDir1;

float NdotL1;

uniform float shiny;

void main( void )
{
    finalcolor                =  texture2D(Texture1,gl_TexCoord[0].xy);

    vec3 NormalTex            =  texture2D(NormalMap,  gl_TexCoord[1].st).xyz;
    NormalTex                 = (NormalTex - 0.5) * 2.0;
    normal                    =  normalize(NormalTex);
    NdotL1                    =  dot(normal,lightDir1);

    
    float specularLight       =  pow(max(NdotL1, 0.0), shiny);
    finalcolor               +=  specularLight;

    finalcolor.r             += counter3*.3;
    finalcolor.g             += counter3*.2;    
    
    
    finalcolor               *=  attenuation * NdotL1; 

    gl_FragColor              =  finalcolor;

}
