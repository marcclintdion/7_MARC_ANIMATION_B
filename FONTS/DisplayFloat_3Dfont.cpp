#include "FontListBasic.cpp"//______Wednesday November 11, 2009<<<___Hidious

float pushNumber      = 0.075f;

float value           = 1.23f;
float inputValue      = 0.0f;
float tempInputValue  = 0.0f;
float tempInputValueB = 0.0f;
float numberPosition  = 0.0f;
int   input_01        = 0;
int   input_02        = 0;
int   tempValueA      = 0;
int   tempValueB      = 0;
bool  inputValueIsNegative = false;

int leftOfDecimalPoint    = 0;
int twoLeftOfDecimalPoint = 0;

void printDecimalNumbers(float inputValue) 
{
    tempInputValue  = inputValue;
    inputValueIsNegative = false;
    
    if(inputValue < 10.0f)
    {
     twoLeftOfDecimalPoint = 0;
    }
    
    if(tempInputValue < 0.0f)
    {
         inputValueIsNegative = true;
         tempInputValue       = tempInputValue * -1.0f;
         inputValue           = inputValue     * -1.0f;
    }
    if(tempInputValue >= 10.0f)
    {
         twoLeftOfDecimalPoint = (int)tempInputValue;
         twoLeftOfDecimalPoint = twoLeftOfDecimalPoint / 10;             
    } 

    tempValueA      = (int)inputValue;
    leftOfDecimalPoint = tempValueA;
    if(leftOfDecimalPoint >= 10 && leftOfDecimalPoint < 20)
    {
        leftOfDecimalPoint = leftOfDecimalPoint -10;
    }
    if(leftOfDecimalPoint >= 20 && leftOfDecimalPoint < 30)
    {
        leftOfDecimalPoint = leftOfDecimalPoint -20;
    }
    if(leftOfDecimalPoint >= 30 && leftOfDecimalPoint < 40)
    {
        leftOfDecimalPoint = leftOfDecimalPoint -30;
    }
    if(leftOfDecimalPoint >= 40 && leftOfDecimalPoint < 50)
    {
        leftOfDecimalPoint = leftOfDecimalPoint -40;
    }
    if(leftOfDecimalPoint >= 50 && leftOfDecimalPoint < 60)
    {
        leftOfDecimalPoint = leftOfDecimalPoint -50;
    }
    if(leftOfDecimalPoint >= 60 && leftOfDecimalPoint < 70)
    {
        leftOfDecimalPoint = leftOfDecimalPoint -60;
    }
    if(leftOfDecimalPoint >= 70 && leftOfDecimalPoint < 80)
    {
        leftOfDecimalPoint = leftOfDecimalPoint -70;
    }
    if(leftOfDecimalPoint >= 80 && leftOfDecimalPoint < 90)
    {
        leftOfDecimalPoint = leftOfDecimalPoint -80;
    }        
    if(leftOfDecimalPoint >= 90 && leftOfDecimalPoint < 100)
    {
        leftOfDecimalPoint = leftOfDecimalPoint -90;
    }    
    tempInputValueB =  tempInputValue;        

    inputValue      = inputValue  - tempValueA;
    tempInputValueB = tempInputValueB - tempValueA;
    tempInputValueB = tempInputValueB * 10;

    inputValue      = inputValue      * 10;

    input_01        = (int)inputValue;
    
    tempInputValueB = tempInputValueB - input_01;

    tempInputValue  = tempInputValueB * 10;
    
    input_02 = (int)tempInputValue;
    
 glScalef(.3,.3,.3);   
 if(leftOfDecimalPoint == 0)
 {
             glPushMatrix();        
                  glTranslatef(-.13, 0.0f, 0.0f);
                  glInterleavedArrays( GL_V3F, 0, zero_VERT );                        
                  glDrawArrays( GL_TRIANGLES, 0, 36);
             glPopMatrix();
 }
             
 if(leftOfDecimalPoint == 1)
 {
            glPushMatrix();
                glTranslatef(-.13f, 0.0f, 0.0f);            
                glInterleavedArrays( GL_V3F, 0, one_VERT );                        
                glDrawArrays( GL_TRIANGLES, 0, 6);
            glPopMatrix();       
 }
 if(twoLeftOfDecimalPoint == 1)
 {
            glPushMatrix();
                glTranslatef(-.23f, 0.0f, 0.0f);            
                glInterleavedArrays( GL_V3F, 0, one_VERT );                        
                glDrawArrays( GL_TRIANGLES, 0, 6);
            glPopMatrix();       
 }
 if(leftOfDecimalPoint == 2)
 {
            glPushMatrix();
                glTranslatef(-.13f, 0.0f, 0.0f);            
                glInterleavedArrays( GL_V3F, 0, two_VERT );                        
                glDrawArrays( GL_TRIANGLES, 0, 27);
            glPopMatrix();       
 }
 if(twoLeftOfDecimalPoint == 2)
 {
            glPushMatrix();
                glTranslatef(-.23f, 0.0f, 0.0f);            
                glInterleavedArrays( GL_V3F, 0, two_VERT );                        
                glDrawArrays( GL_TRIANGLES, 0, 27);
            glPopMatrix();       
 }
 if(leftOfDecimalPoint == 3)
 {
            glPushMatrix();
                glTranslatef(-.13f, 0.0f, 0.0f);            
                glInterleavedArrays( GL_V3F, 0, three_VERT );                        
                glDrawArrays( GL_TRIANGLES, 0, 51);
            glPopMatrix();       
 }
 if(twoLeftOfDecimalPoint == 3)
 {
            glPushMatrix();
                glTranslatef(-.23f, 0.0f, 0.0f);            
                glInterleavedArrays( GL_V3F, 0, three_VERT );                        
                glDrawArrays( GL_TRIANGLES, 0, 51);
            glPopMatrix();       
 }
 if(leftOfDecimalPoint == 4)
 {
            glPushMatrix();
                glTranslatef(-.13f, 0.0f, 0.0f);            
                glInterleavedArrays( GL_V3F, 0, four_VERT );                        
                glDrawArrays( GL_TRIANGLES, 0, 18);
            glPopMatrix();       
 }
 if(twoLeftOfDecimalPoint == 4)
 {
            glPushMatrix();
                glTranslatef(-.23f, 0.0f, 0.0f);            
                glInterleavedArrays( GL_V3F, 0, four_VERT );                        
                glDrawArrays( GL_TRIANGLES, 0, 18);
            glPopMatrix();       
 }
 if(leftOfDecimalPoint == 5)
 {
            glPushMatrix();
                glTranslatef(-.13f, 0.0f, 0.0f);            
                glInterleavedArrays( GL_V3F, 0, five_VERT );                        
                glDrawArrays( GL_TRIANGLES, 0, 39);
            glPopMatrix();       
 }
 if(twoLeftOfDecimalPoint == 5)
 {
            glPushMatrix();
                glTranslatef(-.23f, 0.0f, 0.0f);            
                glInterleavedArrays( GL_V3F, 0, five_VERT );                        
                glDrawArrays( GL_TRIANGLES, 0, 39);
            glPopMatrix();       
 }
 if(leftOfDecimalPoint == 6)
 {
            glPushMatrix();
                glTranslatef(-.13f, 0.0f, 0.0f);            
                glInterleavedArrays( GL_V3F, 0, six_VERT );                        
                glDrawArrays( GL_TRIANGLES, 0, 69);
            glPopMatrix();       
 }
 if(twoLeftOfDecimalPoint == 6)
 {
            glPushMatrix();
                glTranslatef(-.23f, 0.0f, 0.0f);            
                glInterleavedArrays( GL_V3F, 0, six_VERT );                        
                glDrawArrays( GL_TRIANGLES, 0, 69);
            glPopMatrix();       
 }
 if(leftOfDecimalPoint == 7)
 {
            glPushMatrix();
                glTranslatef(-.13f, 0.0f, 0.0f);            
                glInterleavedArrays( GL_V3F, 0, seven_VERT );                        
                glDrawArrays( GL_TRIANGLES, 0, 15);
            glPopMatrix();       
 }
 if(twoLeftOfDecimalPoint == 7)
 {
            glPushMatrix();
                glTranslatef(-.23f, 0.0f, 0.0f);            
                glInterleavedArrays( GL_V3F, 0, seven_VERT );                        
                glDrawArrays( GL_TRIANGLES, 0, 15);
            glPopMatrix();       
 }
 if(leftOfDecimalPoint == 8)
 {
            glPushMatrix();
                glTranslatef(-.13f, 0.0f, 0.0f);            
                glInterleavedArrays( GL_V3F, 0, eight_VERT );                        
                glDrawArrays( GL_TRIANGLES, 0, 84);
            glPopMatrix();       
 }
 if(twoLeftOfDecimalPoint == 8)
 {
            glPushMatrix();
                glTranslatef(-.23f, 0.0f, 0.0f);            
                glInterleavedArrays( GL_V3F, 0, eight_VERT );                        
                glDrawArrays( GL_TRIANGLES, 0, 84);
            glPopMatrix();       
 }
 if(leftOfDecimalPoint == 9)
 {
            glPushMatrix();
                glTranslatef(-.13f, 0.0f, 0.0f);            
                glInterleavedArrays( GL_V3F, 0, nine_VERT );                        
                glDrawArrays( GL_TRIANGLES, 0, 60);
            glPopMatrix();       
 }
 if(twoLeftOfDecimalPoint == 9)
 {
            glPushMatrix();
                glTranslatef(-.23f, 0.0f, 0.0f);            
                glInterleavedArrays( GL_V3F, 0, nine_VERT );                        
                glDrawArrays( GL_TRIANGLES, 0, 60);
            glPopMatrix();       
 } 
 
        if(inputValueIsNegative)
        {
            glPushMatrix();        
                  glTranslatef(-0.33, 0.0f, 0.0f);
                  glScalef(10.0f, 3.0f, 3.0f);
                  glInterleavedArrays( GL_V3F, 0, decimalPoint_VERT );                        
                  glDrawArrays( GL_TRIANGLES, 0, 6);
             glPopMatrix();
        }             
             
        glPushMatrix();        
                  glTranslatef(-0.07, 0.0f, 0.0f);
                  glScalef(3.0f, 3.0f, 3.0f);
                  glInterleavedArrays( GL_V3F, 0, decimalPoint_VERT );                        
                  glDrawArrays( GL_TRIANGLES, 0, 6);
        glPopMatrix();
             
        if(input_01 == 0)
        {    
             glPushMatrix();        
                  glTranslatef(numberPosition, 0.0f, 0.0f);
                  glInterleavedArrays( GL_V3F, 0, zero_VERT );                        
                  glDrawArrays( GL_TRIANGLES, 0, 36);
             glPopMatrix();
        }
        if(input_02 == 0)
        {    
             glPushMatrix();        
                  glTranslatef(numberPosition + pushNumber, 0.0f, 0.0f);
                  glInterleavedArrays( GL_V3F, 0, zero_VERT );                        
                  glDrawArrays( GL_TRIANGLES, 0, 36);
             glPopMatrix();
        }
////////////////////////////////////////////////////////////////////////////////       
        if(input_01 == 1)
        {
            glPushMatrix();
                glTranslatef(numberPosition, 0.0f, 0.0f);            
                glInterleavedArrays( GL_V3F, 0, one_VERT );                        
                glDrawArrays( GL_TRIANGLES, 0, 6);
            glPopMatrix();
        }
        if(input_02 == 1)
        {
            glPushMatrix();
                glTranslatef(numberPosition + pushNumber, 0.0f, 0.0f);            
                glInterleavedArrays( GL_V3F, 0, one_VERT );                        
                glDrawArrays( GL_TRIANGLES, 0, 6);
            glPopMatrix();
        }
////////////////////////////////////////////////////////////////////////////////        
        if(input_01 == 2)
        {
            glPushMatrix();
                glTranslatef(numberPosition, 0.0f, 0.0f);            
                glInterleavedArrays( GL_V3F, 0, two_VERT );                        
                glDrawArrays( GL_TRIANGLES, 0, 27);
            glPopMatrix();
        }
        if(input_02 == 2)
        {
            glPushMatrix();
                glTranslatef(numberPosition + pushNumber, 0.0f, 0.0f);            
                glInterleavedArrays( GL_V3F, 0, two_VERT );                        
                glDrawArrays( GL_TRIANGLES, 0, 27);
            glPopMatrix();
        }        
////////////////////////////////////////////////////////////////////////////////        
        if(input_01 == 3)
        {    
            glPushMatrix();
                glTranslatef(numberPosition, 0.0f, 0.0f);           
                glInterleavedArrays( GL_V3F, 0, three_VERT );                        
                glDrawArrays( GL_TRIANGLES, 0, 51);   
            glPopMatrix();
        }
        if(input_02 == 3)
        {    
            glPushMatrix();
                glTranslatef(numberPosition + pushNumber, 0.0f, 0.0f);           
                glInterleavedArrays( GL_V3F, 0, three_VERT );                        
                glDrawArrays( GL_TRIANGLES, 0, 51);   
            glPopMatrix();
        }
////////////////////////////////////////////////////////////////////////////////        
        if(input_01 == 4)
        {    
            glPushMatrix();
                glTranslatef(numberPosition, 0.0f, 0.0f);            
                glInterleavedArrays( GL_V3F, 0, four_VERT );                        
                glDrawArrays( GL_TRIANGLES, 0, 18);
            glPopMatrix();
        }
        if(input_02 == 4)
        {    
            glPushMatrix();
                glTranslatef(numberPosition + pushNumber, 0.0f, 0.0f);            
                glInterleavedArrays( GL_V3F, 0, four_VERT );                        
                glDrawArrays( GL_TRIANGLES, 0, 18);
            glPopMatrix();
        }
////////////////////////////////////////////////////////////////////////////////        
        if(input_01 == 5)
        {    
            glPushMatrix();
                glTranslatef(numberPosition, 0.0f, 0.0f);            
                glInterleavedArrays( GL_V3F, 0, five_VERT );                        
                glDrawArrays( GL_TRIANGLES, 0, 39);
            glPopMatrix();
        }
        if(input_02 == 5)
        {    
            glPushMatrix();
                glTranslatef(numberPosition + pushNumber, 0.0f, 0.0f);            
                glInterleavedArrays( GL_V3F, 0, five_VERT );                        
                glDrawArrays( GL_TRIANGLES, 0, 39);
            glPopMatrix();
        }
////////////////////////////////////////////////////////////////////////////////        
        if(input_01 == 6)
        {    
            glPushMatrix();
                glTranslatef(numberPosition, 0.0f, 0.0f);    
                glInterleavedArrays( GL_V3F, 0, six_VERT );                        
                glDrawArrays( GL_TRIANGLES, 0, 69);
            glPopMatrix();
        }
        if(input_02 == 6)
        {    
            glPushMatrix();
                glTranslatef(numberPosition + pushNumber, 0.0f, 0.0f);    
                glInterleavedArrays( GL_V3F, 0, six_VERT );                        
                glDrawArrays( GL_TRIANGLES, 0, 69);
            glPopMatrix();
        }
////////////////////////////////////////////////////////////////////////////////        
        if(input_01 == 7)
        {    
            glPushMatrix();
                glTranslatef(numberPosition, 0.0f, 0.0f);            
                glInterleavedArrays( GL_V3F, 0, seven_VERT );                        
                glDrawArrays( GL_TRIANGLES, 0, 15);
            glPopMatrix();
        }
        if(input_02 == 7)
        {    
            glPushMatrix();
                glTranslatef(numberPosition + pushNumber, 0.0f, 0.0f);            
                glInterleavedArrays( GL_V3F, 0, seven_VERT );                        
                glDrawArrays( GL_TRIANGLES, 0, 15);
            glPopMatrix();
        }
////////////////////////////////////////////////////////////////////////////////        
        if(input_01 == 8)
        {    
            glPushMatrix();
                glTranslatef(numberPosition, 0.0f, 0.0f);            
                glInterleavedArrays( GL_V3F, 0, eight_VERT );                        
                glDrawArrays( GL_TRIANGLES, 0, 84);
            glPopMatrix();
        }
        if(input_02 == 8)
        {    
            glPushMatrix();
                glTranslatef(numberPosition + pushNumber, 0.0f, 0.0f);            
                glInterleavedArrays( GL_V3F, 0, eight_VERT );                        
                glDrawArrays( GL_TRIANGLES, 0, 84);
            glPopMatrix();
        }
////////////////////////////////////////////////////////////////////////////////        
        if(input_01 == 9)
        {    
            glPushMatrix();
                glTranslatef(numberPosition, 0.0f, 0.0f);           
                glInterleavedArrays( GL_V3F, 0, nine_VERT );                        
                glDrawArrays( GL_TRIANGLES, 0, 60);
            glPopMatrix();   
        }
        if(input_02 == 9)
        {    
            glPushMatrix();
                glTranslatef(numberPosition + pushNumber, 0.0f, 0.0f);           
                glInterleavedArrays( GL_V3F, 0, nine_VERT );                        
                glDrawArrays( GL_TRIANGLES, 0, 60);
            glPopMatrix();   
        }
}//__close-->>  printNumbers(function)
