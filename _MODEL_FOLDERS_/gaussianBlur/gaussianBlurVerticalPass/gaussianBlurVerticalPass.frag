uniform sampler2D Texture1;
varying vec2 vTexCoord;
 

uniform float counter1;  
 
void main(void)
{
   vec4 sum = vec4(0.0);
 
   

   sum += texture2D(Texture1, vec2(vTexCoord.x, vTexCoord.y - 2.0 * counter1)) * 0.10;
   sum += texture2D(Texture1, vec2(vTexCoord.x, vTexCoord.y -       counter1)) * 0.25;
   sum += texture2D(Texture1, vec2(vTexCoord.x, vTexCoord.y))                  * 0.30;
   sum += texture2D(Texture1, vec2(vTexCoord.x, vTexCoord.y +       counter1)) * 0.25;
   sum += texture2D(Texture1, vec2(vTexCoord.x, vTexCoord.y + 2.0 * counter1)) * 0.10;

 
   gl_FragColor = sum;
}



