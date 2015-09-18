uniform float counter;

varying vec4 position;

void main( void )
{
    gl_TexCoord[0]   = gl_MultiTexCoord0;

    position         = gl_ModelViewProjectionMatrix * gl_Vertex;
    gl_Position      = position;
}
