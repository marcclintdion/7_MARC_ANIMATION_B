glPushMatrix();
glTranslatef(rightLegDialogues[0], rightLegDialogues[1], rightLegDialogues[2]);
           
      glPushMatrix();
      glTranslatef(rightLegDialogueText[0],rightLegDialogueText[1],rightLegDialogueText[2]);
         glEnable(GL_BLEND);
         glEnable(GL_TEXTURE_2D);
         glBindTexture( GL_TEXTURE_2D, textureMap[69] );
         glInterleavedArrays( GL_T2F_N3F_V3F, 0, smallTextBlock);
         glDrawArrays( GL_TRIANGLES, 0, 6);       
         glDisable(GL_TEXTURE_2D);
         glDisable(GL_BLEND);
      glPopMatrix();         
      
      glPushMatrix();
           glTranslatef(rightLegDialogueA[0],rightLegDialogueA[1],rightLegDialogueA[2]);   

           glRotatef(-90, 1, 0,0); 
                glPushMatrix();
                  glTranslatef(0.0f, 0.0f, 0.85/3);
                  printDecimalNumbers(rightUpperLeg_ROTATE[3]);
                glPopMatrix();
                
                glPushMatrix();
                  glTranslatef(0.0f, 0.0f, 0.66/3);    
                  printDecimalNumbers(rightUpperLeg_ROTATE[0]);
                glPopMatrix();
                
                glPushMatrix();
                  glTranslatef(0.0f, 0.0f, 0.5/3);
                  printDecimalNumbers(rightUpperLeg_ROTATE[1]);
                glPopMatrix();
                
                glPushMatrix();
                   glTranslatef(0.0f, 0.0f, 0.34/3);
                   printDecimalNumbers(rightUpperLeg_ROTATE[2]);
                glPopMatrix();
       glPopMatrix();
    glPushMatrix();
         glTranslatef(rightLegDialogueB[0],rightLegDialogueB[1],rightLegDialogueB[2]); 
        
         glRotatef(-90, 1, 0,0);    
              glPushMatrix();
                glTranslatef(0.0f, 0.0f, 0.85/3);
                printDecimalNumbers(rightLowerLeg_ROTATE[3]);
              glPopMatrix();

              glPushMatrix();
                glTranslatef(0.0f, 0.0f, 0.66/3);    
                printDecimalNumbers(rightLowerLeg_ROTATE[0]);
              glPopMatrix();    

              glPushMatrix();
                glTranslatef(0.0f, 0.0f, 0.5/3);
                printDecimalNumbers(rightLowerLeg_ROTATE[1]);
              glPopMatrix();

              glPushMatrix();
                glTranslatef(0.0f, 0.0f, 0.34/3);
                printDecimalNumbers(rightLowerLeg_ROTATE[2]);
              glPopMatrix();
       glPopMatrix();
    glPushMatrix();
         glTranslatef(rightLegDialogueC[0],rightLegDialogueC[1],rightLegDialogueC[2]); 
         
         glRotatef(-90, 1, 0,0);    
              glPushMatrix();
                glTranslatef(0.0f, 0.0f, 0.85/3);
                printDecimalNumbers(rightFoot_ROTATE[3]);
              glPopMatrix();

              glPushMatrix();
                glTranslatef(0.0f, 0.0f, 0.66/3);    
                printDecimalNumbers(rightFoot_ROTATE[0]);
              glPopMatrix();    
        
              glPushMatrix();
                glTranslatef(0.0f, 0.0f, 0.5/3);
                printDecimalNumbers(rightFoot_ROTATE[1]);
              glPopMatrix();
         
              glPushMatrix();
                glTranslatef(0.0f, 0.0f, 0.34/3);
                printDecimalNumbers(rightFoot_ROTATE[2]);
              glPopMatrix();
    glPopMatrix();
glPopMatrix();
