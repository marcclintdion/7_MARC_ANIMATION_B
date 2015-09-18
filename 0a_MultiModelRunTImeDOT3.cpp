   GLfloat lightpos_pillerBush[] =  {3, 9.95999, -3.83491};
   GLfloat quadraticAttenuationPillerBush =   1.83;
   float   quadraticAttenuationPillerBushGround    = 1.83;
   
   float   light4LeavesRound[]                     =  {5.7, -9.9, -12.1};
   float   quadraticAttenuationLeavesRound         =   1.83;  
  
   float   lightPosFrontWall[]                     =  {-3.99, 4.24, -2.46988};
   float   quadraticAttenuationFrontWall           =    1.83;

  GLfloat  lightPosRearWall[]                      =  {26.9849, 33.1149, 7.82012};
  GLfloat  quadraticAttenuationRearWall            =    3.11293;               
 
  GLfloat  rightSideWallLight[]                    =  {3.83, 3.3, 8.17};
  GLfloat  quadraticAttenuationRightSideWallLight  =   1.83;

   float   frontRightCorner[]                      =  {10.8902, 9.26981, -13.1898};
   float   quadraticAttenuationFrontRightCorner    =   1.83; 
   
   float   stoneStairs_0_Light[]                   =  {2.9, 5.5, -11.15};
   float   quadraticAttenuationStoneStairs_0_Light =   1.83;

   float   tree_05_Light[]                         =  {4.8, 8.10001, -3.74997};
   float   quadraticAttenuationTree_05_Light       =   1.83;
   float   plantPot_light[]                        =  {0.75, 11.6, 0.650025};
   float   quadraticAttenuationPlantPot            =   1.83;

   float   tile_00_09_Light[]                      =  {12.929, 10, -14.947}; 
   float   quadraticAttenuationTile_00_09_Light    =   1.83;
  
   float   borderRight_light[]                     =  {-1.85, -8.70002, -12.5};
   float   quadraticAttenuationBorderRight         =   1.83;
   
   float   tree_06_Light[]                         =  {18.6, -22.8, 40.9999};
   float   quadraticAttenuationTree_06_Light       =   1.83;
                   
   GLfloat tree_06_leaves_light[]                  =  {-94.7357, -49.1549, -78.2305};
   GLfloat quadraticAttenuationTree_06_leaves      =   1.065;

void CenterPieceGround(void)
{
                                            glDisable(GL_BLEND);
    glPushMatrix();            
    glTranslatef(moveCenterModels[0],moveCenterModels[1],moveCenterModels[2]);               
               glPushMatrix();
                      glLightfv (GL_LIGHT0,GL_POSITION, lightpos_pillerBush);
                      glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, quadraticAttenuationPillerBushGround);      
               glPopMatrix();      
          runNmapShader(141, cubeBushPlusTree1, textureMap[12], normalMap[12]);
   glPopMatrix();

glDisable(GL_BLEND);   
}



void CenterPieceTreeLeaves(void)
{
   glPushMatrix();            
   glTranslatef(moveCenterModels[0],moveCenterModels[1],moveCenterModels[2]);
   //////////////////////////////////////////////////////////////////////////////////////////      
                glPushMatrix();
                     glLightfv (GL_LIGHT0,GL_POSITION, lightpos_pillerBush);
                     glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, quadraticAttenuationPillerBush);         
                glPopMatrix();
          runNmapShader(168, plusTree1, textureMap[14], normalMap[14]);
          ////////////////////////////////////////////////////////////////////////////////////////    
                         glPushMatrix();
                              glLightfv (GL_LIGHT0,GL_POSITION,light4LeavesRound);
                              glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, quadraticAttenuationPillerBush);
                         glPopMatrix();  
                    runNmapShader(147, leavesRound, textureMap[16], normalMap[16]);      
   //////////////////////////////////////////////////////////////////////////////////////////  
   glPopMatrix();
}
void CenterPieceFrontWall(void)
{
      glPushMatrix();            
          glPushMatrix();
          glLoadIdentity();
          glLightfv (GL_LIGHT0,GL_POSITION, lightPosFrontWall);
          glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, quadraticAttenuationFrontWall);            
          glPopMatrix(); 
      glTranslatef(moveCenterModels[0],moveCenterModels[1],moveCenterModels[2]);        
      runNmapShader(102, rockWallWide_00, textureMap[44], normalMap[44]);
      glPopMatrix();
    //////////////////////////////////////////////////////////////////////////////////////  
     glPushMatrix();            
          glPushMatrix();
          glLoadIdentity();
          glLightfv (GL_LIGHT0,GL_POSITION, lightPosRearWall);
          glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, quadraticAttenuationRearWall);            
          glPopMatrix(); 
      glTranslatef(moveCenterModels[0],moveCenterModels[1],moveCenterModels[2]);        
      glScalef(1, 1, -1);
      glDisable(GL_CULL_FACE);
      runNmapShader(102, rockWallWide_00, textureMap[44], normalMap[44]);
      glEnable(GL_CULL_FACE);
      glPopMatrix();

}
void CenterPieceRightSideWall(void)
{
      glPushMatrix();            
                 glPushMatrix();
                 glLoadIdentity();      
                 glLightfv (GL_LIGHT0,GL_POSITION, rightSideWallLight);
                 glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, quadraticAttenuationRightSideWallLight);          
                 glPopMatrix();
           glTranslatef(moveCenterModels[0],moveCenterModels[1],moveCenterModels[2]);    
           runNmapShader(60, rightSideWall, textureMap[25], normalMap[25]);
      glPopMatrix();    

      glPushMatrix();            
                 glPushMatrix();
                 glLoadIdentity();      
                 glLightfv (GL_LIGHT0,GL_POSITION, rightSideWallLight);
                 glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, quadraticAttenuationRightSideWallLight);          
                 glPopMatrix();
           glTranslatef(moveCenterModels[0],moveCenterModels[1],moveCenterModels[2]);    
           glScalef(-1, 1, 1);
           glDisable(GL_CULL_FACE);
           runNmapShader(60, rightSideWall, textureMap[25], normalMap[25]);
      glPopMatrix();

}
void CenterPieceCorners(void)
{
      glPushMatrix();
        glPushMatrix();
        glLoadIdentity();      
      glLightfv (GL_LIGHT0,GL_POSITION,frontRightCorner);
      glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, quadraticAttenuationFrontRightCorner);
            glPopMatrix();
     glTranslatef(moveCenterModels[0],moveCenterModels[1],moveCenterModels[2]);       
      runNmapShader(12, cornerStone_FRa, textureMap[17], normalMap[17]);
      runNmapShader(12, cornerStone_FRb, textureMap[17], normalMap[18]);
      runNmapShader(36, cornerStone_x3a, textureMap[17], normalMap[17]);
      runNmapShader(36, cornerStone_x3b, textureMap[17], normalMap[18]);
      runNmapShader(30, topStone,        textureMap[19], normalMap[19]);
      runNmapShader(66, topStone_x3,     textureMap[19], normalMap[19]);
      glPopMatrix();   
}







void RearLeftStairs(void)
{
      glPushMatrix();
        glPushMatrix();
        glLoadIdentity();      
        glLightfv (GL_LIGHT0,GL_POSITION,stoneStairs_0_Light);
        glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, quadraticAttenuationStoneStairs_0_Light);
        glPopMatrix();
       
      runNmapShader(72, bottomStair,     textureMap[21], normalMap[21]);
      runNmapShader(45, middleStair,     textureMap[24], normalMap[24]);
      runNmapShader(42, upperStair,      textureMap[23], normalMap[23]);
      runNmapShader(12, topWalkway,      textureMap[22], normalMap[22]);
      glPopMatrix();
}
void Tree_05_BottomRight(void)
{
      glPushMatrix();
        glPushMatrix();
          glLoadIdentity();      
          glLightfv (GL_LIGHT0,GL_POSITION, tree_05_Light);
          glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, quadraticAttenuationTree_05_Light);
        glPopMatrix();
       
      runNmapShader(183, tree_05, textureMap[26], normalMap[26]);
      glPopMatrix();
}

      
void FloorTiles_x100(void)
{
      glPushMatrix();
        glPushMatrix();
        glLoadIdentity();
      glLightfv (GL_LIGHT0,GL_POSITION, tile_00_09_Light);
      glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, quadraticAttenuationTile_00_09_Light);     ///////_____TILES///////_____TILES///////_____TILES///////_____TILES///////_____TILES
            glPopMatrix();
       
      LoadTileModels_00_100();
      glPopMatrix();
}
void Borders(void)
{
      glDisable(GL_CULL_FACE);
      glPushMatrix();
        glPushMatrix();
        glLoadIdentity();      
      glLightfv (GL_LIGHT0,GL_POSITION,borderRight_light);
      glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, quadraticAttenuationBorderRight);
            glPopMatrix();
              
      runNmapShader(60, borderRight, smallDetail[1], smallDetailDOT3[1]);
      runNmapShader(60, borderLeft, smallDetail[1], smallDetailDOT3[1]);
      runNmapShader(60, borderFar, smallDetail[1], smallDetailDOT3[1]);
      glPopMatrix();
      glEnable(GL_CULL_FACE);
}

GLfloat tree_06_position[] =  {-0.2, 0.04, -3.50177e-009};

void Tree_06_LeftMiddle(void)
{
      
      glPushMatrix();
      glTranslatef(-5.0, 0, 0);
      glRotatef(180, 0, 1, 0);         
          glPushMatrix();
          glLoadIdentity();      
             glLightfv (GL_LIGHT0,GL_POSITION, tree_06_Light);
             glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, quadraticAttenuationTree_06_Light);      
          glPopMatrix();
 
          runNmapShader(162, tree_06, textureMap[39], normalMap[39]);
          glPopMatrix();
}
                    void Tree_06_Leaves_LeftMiddle(void)
                    {
                         glPushMatrix();
                         glTranslatef(tree_06_position[0], tree_06_position[1], tree_06_position[2]);
                         glEnable(GL_BLEND);
                              glPushMatrix();
                              glLoadIdentity();       
                              glLightfv (GL_LIGHT0,GL_POSITION,tree_06_leaves_light);
                              glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, quadraticAttenuationTree_06_leaves);////___(GL_BLEND) = true___/////should be rendered later 
                              glPopMatrix();      
                         runNmapShader(96, tree_06_leaves, smallDetail[0], smallDetailDOT3[0]);
                         glPopMatrix();     
                    }
