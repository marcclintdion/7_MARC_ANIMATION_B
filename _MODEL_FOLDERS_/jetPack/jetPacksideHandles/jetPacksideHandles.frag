uniform float counter;

varying vec4 position;

float distance;  


vec4 finalcolor;


vec3 normal;
vec3 lightDir1;

float NdotL1;

uniform sampler2D Texture1;
uniform sampler2D NormalMap;


vec3 lightPosMinusPos;

void main( void )
{


    finalcolor       =  texture2D(Texture1,gl_TexCoord[0].xy);
    finalcolor       =  finalcolor;

    vec3 NormalTex   =  texture2D(NormalMap,  gl_TexCoord[0].st).xyz;
    NormalTex        = (NormalTex - 0.5) * 2.0;
	normal           =  normalize(NormalTex);
    
    lightDir1        =  normalize(gl_LightSource[0].position.xyz - position.xyz);
    NdotL1           =  dot(normal,lightDir1);

    finalcolor      *=  0.156 * NdotL1 * NdotL1 * 2.2; 

    if(NdotL1 > 0.0)
    {
         float specularLight  = pow(max(NdotL1, 0.0), gl_FrontMaterial.shininess);  
         finalcolor          += specularLight;
    }    

    gl_FragColor              =  finalcolor;

}
