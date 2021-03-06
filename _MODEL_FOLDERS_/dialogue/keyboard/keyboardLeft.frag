uniform float counter1;
uniform float counter2;
uniform float counter3;
uniform float counter4;

varying vec4 position;

float distance;  
varying float attenuation;

uniform sampler2D Texture1;
uniform sampler2D NormalMap;
//uniform sampler2D Texture3;

vec4   finalcolor;
vec3   normal;
//vec4 thirdTexture;


varying vec3 lightDir1;

float NdotL1;

uniform float shiny;

void main( void )
{
    finalcolor                =  texture2D(Texture1,gl_TexCoord[0].xy);

    vec3 NormalTex            =  texture2D(NormalMap,  gl_TexCoord[0].st).xyz;
    NormalTex                 = (NormalTex - 0.5) * 2.0;
    normal                    =  normalize(NormalTex);
    NdotL1                    =  dot(normal,lightDir1);

    //thirdTexture            =  texture2D(Texture3,  gl_TexCoord[0].st);

    float specularLight       =  pow(max(NdotL1, 0.0), shiny);
    finalcolor               +=  specularLight * finalcolor;

    finalcolor               *=  attenuation * NdotL1 * NdotL1; 

    gl_FragColor              =  finalcolor;

}
