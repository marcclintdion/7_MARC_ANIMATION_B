glPushMatrix();

glTranslatef(leftArmDialogues[0],leftArmDialogues[1],leftArmDialogues[2]);

      glPushMatrix();
      glTranslatef(leftArmDialogueText[0],leftArmDialogueText[1],leftArmDialogueText[2]);
         glEnable(GL_BLEND);
         glEnable(GL_TEXTURE_2D);
         glBindTexture( GL_TEXTURE_2D, textureMap[67] );
         glInterleavedArrays( GL_T2F_N3F_V3F, 0, smallTextBlock);
         glDrawArrays( GL_TRIANGLES, 0, 6);       
         glDisable(GL_BLEND);
         glDisable(GL_TEXTURE_2D);      
      glPopMatrix();

           glPushMatrix();
                glTranslatef(leftArmDialogueA[0],leftArmDialogueA[1],leftArmDialogueA[2]);   
                glRotatef(-90, 1, 0,0); 
                glPushMatrix();
                  glTranslatef(0.0f, 0.0f, 0.85/3);
                  printDecimalNumbers(leftUpperArm_ROTATE[3]);
                glPopMatrix();
                
                glPushMatrix();
                  glTranslatef(0.0f, 0.0f, 0.66/3);    
                  printDecimalNumbers(leftUpperArm_ROTATE[0]);
                glPopMatrix();
                
                glPushMatrix();
                  glTranslatef(0.0f, 0.0f, 0.5/3);
                  printDecimalNumbers(leftUpperArm_ROTATE[1]);
                glPopMatrix();
                
                glPushMatrix();
                   glTranslatef(0.0f, 0.0f, 0.34/3);
                   printDecimalNumbers(leftUpperArm_ROTATE[2]);
                glPopMatrix();
          glPopMatrix();
    
          glPushMatrix();
              glTranslatef(leftArmDialogueB[0],leftArmDialogueB[1],leftArmDialogueB[2]); 
              glRotatef(-90, 1, 0,0);    
              glPushMatrix();
                glTranslatef(0.0f, 0.0f, 0.85/3);
                printDecimalNumbers(leftForeArm_ROTATE[3]);
              glPopMatrix();

              glPushMatrix();
                glTranslatef(0.0f, 0.0f, 0.66/3);    
                printDecimalNumbers(leftForeArm_ROTATE[0]);
              glPopMatrix();    

              glPushMatrix();
                glTranslatef(0.0f, 0.0f, 0.5/3);
                printDecimalNumbers(leftForeArm_ROTATE[1]);
              glPopMatrix();

              glPushMatrix();
                glTranslatef(0.0f, 0.0f, 0.34/3);
                printDecimalNumbers(leftForeArm_ROTATE[2]);
              glPopMatrix();
         glPopMatrix();
    
         glPushMatrix();
              glTranslatef(leftArmDialogueC[0],leftArmDialogueC[1],leftArmDialogueC[2]); 
              glRotatef(-90, 1, 0,0);    
              glPushMatrix();
                glTranslatef(0.0f, 0.0f, 0.85/3);
                printDecimalNumbers(leftGlovedHand_ROTATE[3]);
              glPopMatrix();

              glPushMatrix();
                glTranslatef(0.0f, 0.0f, 0.66/3);    
                printDecimalNumbers(leftGlovedHand_ROTATE[0]);
              glPopMatrix();    
        
              glPushMatrix();
                glTranslatef(0.0f, 0.0f, 0.5/3);
                printDecimalNumbers(leftGlovedHand_ROTATE[1]);
              glPopMatrix();
         
              glPushMatrix();
                glTranslatef(0.0f, 0.0f, 0.34/3);
                printDecimalNumbers(leftGlovedHand_ROTATE[2]);
              glPopMatrix();
         glPopMatrix();
         
glPopMatrix();





