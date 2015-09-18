varying vec2 vTexCoord;
 

void main(void)
{
   gl_Position = ftransform();
  
   
   vec2 Pos;
   Pos = gl_Vertex.xy;
 
   gl_Position = vec4(Pos, 0.0, 1.0);
   
   vTexCoord = Pos * 0.5 + 0.5;
}
