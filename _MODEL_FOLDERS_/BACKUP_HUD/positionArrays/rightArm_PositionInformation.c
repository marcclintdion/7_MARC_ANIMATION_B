glPushMatrix();

glTranslatef(rightArmDialogues[0],rightArmDialogues[1],rightArmDialogues[2]);
           
      glPushMatrix();
      glTranslatef(rightArmDialogueText[0],rightArmDialogueText[1],rightArmDialogueText[2]);
         glEnable(GL_BLEND);
         glEnable(GL_TEXTURE_2D);
         glBindTexture( GL_TEXTURE_2D, textureMap[67] );
         glInterleavedArrays( GL_T2F_N3F_V3F, 0, smallTextBlock);
         glDrawArrays( GL_TRIANGLES, 0, 6);       
         glDisable(GL_BLEND);
         glDisable(GL_TEXTURE_2D);      
      glPopMatrix();
         
      glPushMatrix();
           glTranslatef(rightArmDialogueA[0],rightArmDialogueA[1],rightArmDialogueA[2]);   

           glRotatef(-90, 1, 0,0); 
                glPushMatrix();
                  glTranslatef(0.0f, 0.0f, 0.85/3);
                  printDecimalNumbers(rightUpperArm_ROTATE[3]);
                glPopMatrix();
                
                glPushMatrix();
                  glTranslatef(0.0f, 0.0f, 0.66/3);    
                  printDecimalNumbers(rightUpperArm_ROTATE[0]);
                glPopMatrix();
                
                glPushMatrix();
                  glTranslatef(0.0f, 0.0f, 0.5/3);
                  printDecimalNumbers(rightUpperArm_ROTATE[1]);
                glPopMatrix();
                
                glPushMatrix();
                   glTranslatef(0.0f, 0.0f, 0.34/3);
                   printDecimalNumbers(rightUpperArm_ROTATE[2]);
                glPopMatrix();
       glPopMatrix();
    glPushMatrix();
         glTranslatef(rightArmDialogueB[0],rightArmDialogueB[1],rightArmDialogueB[2]); 
        
         glRotatef(-90, 1, 0,0);    
              glPushMatrix();
                glTranslatef(0.0f, 0.0f, 0.85/3);
                printDecimalNumbers(rightForeArm_ROTATE[3]);
              glPopMatrix();

              glPushMatrix();
                glTranslatef(0.0f, 0.0f, 0.66/3);    
                printDecimalNumbers(rightForeArm_ROTATE[0]);
              glPopMatrix();    

              glPushMatrix();
                glTranslatef(0.0f, 0.0f, 0.5/3);
                printDecimalNumbers(rightForeArm_ROTATE[1]);
              glPopMatrix();

              glPushMatrix();
                glTranslatef(0.0f, 0.0f, 0.34/3);
                printDecimalNumbers(rightForeArm_ROTATE[2]);
              glPopMatrix();
       glPopMatrix();
    glPushMatrix();
         glTranslatef(rightArmDialogueC[0],rightArmDialogueC[1],rightArmDialogueC[2]); 
         
         glRotatef(-90, 1, 0,0);    
              glPushMatrix();
                glTranslatef(0.0f, 0.0f, 0.85/3);
                printDecimalNumbers(rightGlovedHand_ROTATE[3]);
              glPopMatrix();

              glPushMatrix();
                glTranslatef(0.0f, 0.0f, 0.66/3);    
                printDecimalNumbers(rightGlovedHand_ROTATE[0]);
              glPopMatrix();    
        
              glPushMatrix();
                glTranslatef(0.0f, 0.0f, 0.5/3);
                printDecimalNumbers(rightGlovedHand_ROTATE[1]);
              glPopMatrix();
         
              glPushMatrix();
                glTranslatef(0.0f, 0.0f, 0.34/3);
                printDecimalNumbers(rightGlovedHand_ROTATE[2]);
              glPopMatrix();
    glPopMatrix();
glPopMatrix();
