
void PrintIntegerNumbers(int inputValue)
{
     const int startValue = inputValue;
     
     int tempValue        = 0;
     int displayValue     = startValue;
     int displayValue_x10 = startValue/10;


       if(displayValue == 0)
       {
            glPushMatrix();        
                glTranslatef(0.75f, 0.0f, 0.0f);
                glInterleavedArrays( GL_V3F, 0, zero_VERT );                        
                glDrawArrays( GL_TRIANGLES, 0, 36);
            glPopMatrix();
       }
       if(displayValue == 1)
       {
            glPushMatrix();
                glTranslatef(0.75f, 0.0f, 0.0f);  
                glInterleavedArrays( GL_V3F, 0, one_VERT );                        
                glDrawArrays( GL_TRIANGLES, 0, 6);
            glPopMatrix();       
       }
       if(displayValue == 2)
       {
            glPushMatrix();
                glTranslatef(0.75f, 0.0f, 0.0f);          
                glInterleavedArrays( GL_V3F, 0, two_VERT );                        
                glDrawArrays( GL_TRIANGLES, 0, 27);
            glPopMatrix();       
       }
       if(displayValue == 3)
       {
            glPushMatrix();
                glTranslatef(0.75f, 0.0f, 0.0f);          
                glInterleavedArrays( GL_V3F, 0, three_VERT );                        
                glDrawArrays( GL_TRIANGLES, 0, 51);
            glPopMatrix();       
       }
       if(displayValue == 4)
       {
            glPushMatrix();
                glTranslatef(0.75f, 0.0f, 0.0f);           
                glInterleavedArrays( GL_V3F, 0, four_VERT );                        
                glDrawArrays( GL_TRIANGLES, 0, 18);
            glPopMatrix();       
       }
       if(displayValue == 5)
       {
            glPushMatrix();
                glTranslatef(0.75f, 0.0f, 0.0f);           
                glInterleavedArrays( GL_V3F, 0, five_VERT );                        
                glDrawArrays( GL_TRIANGLES, 0, 39);
            glPopMatrix();       
       }
       if(displayValue == 6)
       {
            glPushMatrix();
                glTranslatef(0.75f, 0.0f, 0.0f);           
                glInterleavedArrays( GL_V3F, 0, six_VERT );                        
                glDrawArrays( GL_TRIANGLES, 0, 69);
            glPopMatrix();       
       }
 
       if(displayValue == 7)
       {
            glPushMatrix();
                glTranslatef(0.75f, 0.0f, 0.0f);            
                glInterleavedArrays( GL_V3F, 0, seven_VERT );                        
                glDrawArrays( GL_TRIANGLES, 0, 15);
            glPopMatrix();       
       } 
 
       if(displayValue == 8)
       {
            glPushMatrix();
                glTranslatef(0.75f, 0.0f, 0.0f);            
                glInterleavedArrays( GL_V3F, 0, eight_VERT );                        
                glDrawArrays( GL_TRIANGLES, 0, 84);
            glPopMatrix();       
       } 
       if(displayValue == 9)
       {
            glPushMatrix();
                glTranslatef(0.75f, 0.0f, 0.0f);          
                glInterleavedArrays( GL_V3F, 0, nine_VERT );                        
                glDrawArrays( GL_TRIANGLES, 0, 60);
            glPopMatrix();       
       }

 
 

 
 
 
 
 
 
 
 




}     
