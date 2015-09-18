glPushMatrix();

glTranslatef(leftLegDialogues[0], leftLegDialogues[1], leftLegDialogues[2]);
            
      glPushMatrix();
      glTranslatef(leftLegDialogueText[0],leftLegDialogueText[1],leftLegDialogueText[2]);
         glEnable(GL_BLEND);
         glEnable(GL_TEXTURE_2D);         
         glBindTexture( GL_TEXTURE_2D, textureMap[68] );
         glInterleavedArrays( GL_T2F_N3F_V3F, 0, smallTextBlock);
         glDrawArrays( GL_TRIANGLES, 0, 6);       
         glDisable(GL_TEXTURE_2D);          
         glDisable(GL_BLEND);      
      glPopMatrix();
      glPushMatrix();
           glTranslatef(leftLegDialogueA[0],leftLegDialogueA[1],leftLegDialogueA[2]);   

           glRotatef(-90, 1, 0,0); 
                glPushMatrix();
                  glTranslatef(0.0f, 0.0f, 0.85/3);
                  printDecimalNumbers(leftUpperLeg_ROTATE[3]);
                glPopMatrix();
                
                glPushMatrix();
                  glTranslatef(0.0f, 0.0f, 0.66/3);    
                  printDecimalNumbers(leftUpperLeg_ROTATE[0]);
                glPopMatrix();
                
                glPushMatrix();
                  glTranslatef(0.0f, 0.0f, 0.5/3);
                  printDecimalNumbers(leftUpperLeg_ROTATE[1]);
                glPopMatrix();
                
                glPushMatrix();
                   glTranslatef(0.0f, 0.0f, 0.34/3);
                   printDecimalNumbers(leftUpperLeg_ROTATE[2]);
                glPopMatrix();
       glPopMatrix();
    glPushMatrix();
         glTranslatef(leftLegDialogueB[0],leftLegDialogueB[1],leftLegDialogueB[2]); 
        
         glRotatef(-90, 1, 0,0);    
              glPushMatrix();
                glTranslatef(0.0f, 0.0f, 0.85/3);
                printDecimalNumbers(leftLowerLeg_ROTATE[3]);
              glPopMatrix();

              glPushMatrix();
                glTranslatef(0.0f, 0.0f, 0.66/3);    
                printDecimalNumbers(leftLowerLeg_ROTATE[0]);
              glPopMatrix();    

              glPushMatrix();
                glTranslatef(0.0f, 0.0f, 0.5/3);
                printDecimalNumbers(leftLowerLeg_ROTATE[1]);
              glPopMatrix();

              glPushMatrix();
                glTranslatef(0.0f, 0.0f, 0.34/3);
                printDecimalNumbers(leftLowerLeg_ROTATE[2]);
              glPopMatrix();
       glPopMatrix();
    glPushMatrix();
         glTranslatef(leftLegDialogueC[0],leftLegDialogueC[1],leftLegDialogueC[2]); 
         
         glRotatef(-90, 1, 0,0);    
              glPushMatrix();
                glTranslatef(0.0f, 0.0f, 0.85/3);
                printDecimalNumbers(leftFoot_ROTATE[3]);
              glPopMatrix();

              glPushMatrix();
                glTranslatef(0.0f, 0.0f, 0.66/3);    
                printDecimalNumbers(leftFoot_ROTATE[0]);
              glPopMatrix();    
        
              glPushMatrix();
                glTranslatef(0.0f, 0.0f, 0.5/3);
                printDecimalNumbers(leftFoot_ROTATE[1]);
              glPopMatrix();
         
              glPushMatrix();
                glTranslatef(0.0f, 0.0f, 0.34/3);
                printDecimalNumbers(leftFoot_ROTATE[2]);
              glPopMatrix();
    glPopMatrix();
glPopMatrix();
