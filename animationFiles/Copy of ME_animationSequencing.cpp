void ME_animationSequencing(void)
{
     if(mainBodyPosition_animationBlendFactor_JUMP >= 0.0f && mainBodyPosition_animationBlendFactor_JUMP <= 1.0f)
     {
         mainBodyPosition[0]           = mainBodyPosition_MOVE_FRAMEA[0]     * (1 - mainBodyPosition_animationBlendFactor_JUMP) 
                                   + mainBodyPosition_MOVE_FRAMEB[0] * mainBodyPosition_animationBlendFactor_JUMP;        
        
         mainBodyPosition[1]           = mainBodyPosition_MOVE_FRAMEA[1]     * (1 - mainBodyPosition_animationBlendFactor_JUMP) 
                                   + mainBodyPosition_MOVE_FRAMEB[1] * mainBodyPosition_animationBlendFactor_JUMP; 
        
         mainBodyPosition[2]           = mainBodyPosition_MOVE_FRAMEA[2]     * (1 - mainBodyPosition_animationBlendFactor_JUMP) 
                                   + mainBodyPosition_MOVE_FRAMEB[2] * mainBodyPosition_animationBlendFactor_JUMP;
     }
     if(mainBodyPosition_animationBlendFactor_JUMP >= 1.0f)
     {
        mainBodyPosition_setSelection_JUMP ++;
        mainBodyPosition_animationBlendFactor_JUMP = 0.0f;
     }
     if(mainBodyPosition_setSelection_JUMP == mainBodyPosition_setSelection_JUMPLimit+1)
     {
        mainBodyPosition_setSelection_JUMP = 1;
     }   
     mainBodyPosition_animationBlendFactor_JUMP += mainBodyPosition_FRAME_TIME_01;
     
          
     
       if(animationBlendFactor_JUMP_LEFT_ARM >= 0.0f && animationBlendFactor_JUMP_LEFT_ARM <= 1.0f)
       {    
             leftUpperArm_ROTATE[3]    = leftUpperArm_ROTATE_FRAMEA[3]    * (1 - animationBlendFactor_JUMP_LEFT_ARM) 
                                       + leftUpperArm_ROTATE_FRAMEB[3]    *      animationBlendFactor_JUMP_LEFT_ARM;        
        
             leftUpperArm_ROTATE[0]    = leftUpperArm_ROTATE_FRAMEA[0]    * (1 - animationBlendFactor_JUMP_LEFT_ARM) 
                                       + leftUpperArm_ROTATE_FRAMEB[0]    *      animationBlendFactor_JUMP_LEFT_ARM; 
        
             leftUpperArm_ROTATE[1]    = leftUpperArm_ROTATE_FRAMEA[1]    * (1 - animationBlendFactor_JUMP_LEFT_ARM) 
                                       + leftUpperArm_ROTATE_FRAMEB[1]    *      animationBlendFactor_JUMP_LEFT_ARM;
        
             leftUpperArm_ROTATE[2]    = leftUpperArm_ROTATE_FRAMEA[2]    * (1 - animationBlendFactor_JUMP_LEFT_ARM) 
                                       + leftUpperArm_ROTATE_FRAMEB[2]    *      animationBlendFactor_JUMP_LEFT_ARM;
             ///////                               
          
             leftForeArm_ROTATE[3]     = leftForeArm_ROTATE_FRAMEA[3]     * (1 - animationBlendFactor_JUMP_LEFT_ARM) 
                                       + leftForeArm_ROTATE_FRAMEB[3]     *      animationBlendFactor_JUMP_LEFT_ARM;        
        
             leftForeArm_ROTATE[0]     = leftForeArm_ROTATE_FRAMEA[0]     * (1 - animationBlendFactor_JUMP_LEFT_ARM) 
                                       + leftForeArm_ROTATE_FRAMEB[0]     *      animationBlendFactor_JUMP_LEFT_ARM; 
        
             leftForeArm_ROTATE[1]     = leftForeArm_ROTATE_FRAMEA[1]     * (1 - animationBlendFactor_JUMP_LEFT_ARM) 
                                       + leftForeArm_ROTATE_FRAMEB[1]     *      animationBlendFactor_JUMP_LEFT_ARM;
        
             leftForeArm_ROTATE[2]     = leftForeArm_ROTATE_FRAMEA[2]     * (1 - animationBlendFactor_JUMP_LEFT_ARM) 
                                       + leftForeArm_ROTATE_FRAMEB[2]     *      animationBlendFactor_JUMP_LEFT_ARM;                                          
             ///////                              
        
             leftGlovedHand_ROTATE[3]  = leftGlovedHand_ROTATE_FRAMEA[3]  * (1 - animationBlendFactor_JUMP_LEFT_ARM) 
                                       + leftGlovedHand_ROTATE_FRAMEB[3]  *      animationBlendFactor_JUMP_LEFT_ARM;        
        
             leftGlovedHand_ROTATE[0]  = leftGlovedHand_ROTATE_FRAMEA[0]  * (1 - animationBlendFactor_JUMP_LEFT_ARM) 
                                       + leftGlovedHand_ROTATE_FRAMEB[0]  *      animationBlendFactor_JUMP_LEFT_ARM; 
        
             leftGlovedHand_ROTATE[1]  = leftGlovedHand_ROTATE_FRAMEA[1]  * (1 - animationBlendFactor_JUMP_LEFT_ARM) 
                                       + leftGlovedHand_ROTATE_FRAMEB[1]  *      animationBlendFactor_JUMP_LEFT_ARM;
        
             leftGlovedHand_ROTATE[2]  = leftGlovedHand_ROTATE_FRAMEA[2]  * (1 - animationBlendFactor_JUMP_LEFT_ARM) 
                                       + leftGlovedHand_ROTATE_FRAMEB[2]  *      animationBlendFactor_JUMP_LEFT_ARM;      
        }    
        /////////////////////////////////////////////////////////////        
        if(animationBlendFactor_JUMP_LEFT_ARM >= 1.0f)
        {
             setSelection_JUMP_LEFT_ARM ++;
             animationBlendFactor_JUMP_LEFT_ARM = 0.0f;
        }
        if(setSelection_JUMP_LEFT_ARM == setSelection_JUMPLimit_LEFT_ARM + 1)
        {
             setSelection_JUMP_LEFT_ARM = 1;
        }
        animationBlendFactor_JUMP_LEFT_ARM  += LEFT_ARM_FRAME_TIME_01; 
        
             
     
                            if(animationBlendFactor_JUMP_HEAD >= 0.0f && animationBlendFactor_JUMP_HEAD <= 1.0f)
                            {                          
                                  head_ROTATE[3]            = head_ROTATE_FRAMEA[3]            * (1 - animationBlendFactor_JUMP_HEAD) 
                                                            + head_ROTATE_FRAMEB[3]            * animationBlendFactor_JUMP_HEAD;        
        
                                  head_ROTATE[0]            = head_ROTATE_FRAMEA[0]            * (1 - animationBlendFactor_JUMP_HEAD) 
                                                            + head_ROTATE_FRAMEB[0]            * animationBlendFactor_JUMP_HEAD; 
        
                                  head_ROTATE[1]            = head_ROTATE_FRAMEA[1]            * (1 - animationBlendFactor_JUMP_HEAD) 
                                                            + head_ROTATE_FRAMEB[1]            * animationBlendFactor_JUMP_HEAD;
        
                                  head_ROTATE[2]            = head_ROTATE_FRAMEA[2]            * (1 - animationBlendFactor_JUMP_HEAD) 
                                                            + head_ROTATE_FRAMEB[2]            * animationBlendFactor_JUMP_HEAD; 
                            }
    
                            if(animationBlendFactor_JUMP_HEAD >= 1.0f)
                            {
                                 setSelection_JUMP_HEAD ++;
                                 animationBlendFactor_JUMP_HEAD = 0.0f;
                            }
    
                            if(setSelection_JUMP_HEAD == setSelection_JUMPLimit_HEAD+1)
                            {
                                 setSelection_JUMP_HEAD = 1;
                            }
    
                            animationBlendFactor_JUMP_HEAD       += HEAD_FRAME_TIME_01;   
    
    
       
        if(animationBlendFactor_JUMP_TORSO >= 0.0f && animationBlendFactor_JUMP_TORSO <= 1.0f)
        {    
              torso_ROTATE[3]           = torso_ROTATE_FRAMEA[3]           * (1 - animationBlendFactor_JUMP_TORSO) 
                                        + torso_ROTATE_FRAMEB[3]           * animationBlendFactor_JUMP_TORSO;        
        
              torso_ROTATE[0]           = torso_ROTATE_FRAMEA[0]           * (1 - animationBlendFactor_JUMP_TORSO) 
                                        + torso_ROTATE_FRAMEB[0]           * animationBlendFactor_JUMP_TORSO; 
        
              torso_ROTATE[1]           = torso_ROTATE_FRAMEA[1]           * (1 - animationBlendFactor_JUMP_TORSO) 
                                        + torso_ROTATE_FRAMEB[1]           * animationBlendFactor_JUMP_TORSO;
        
              torso_ROTATE[2]           = torso_ROTATE_FRAMEA[2]           * (1 - animationBlendFactor_JUMP_TORSO) 
                                        + torso_ROTATE_FRAMEB[2]           * animationBlendFactor_JUMP_TORSO;     
        }    
        if(animationBlendFactor_JUMP_TORSO >= 1.0f)
        {
             setSelection_JUMP_TORSO ++;
             animationBlendFactor_JUMP_TORSO = 0.0f;
        }
    
        if(setSelection_JUMP_TORSO == setSelection_JUMPLimit_TORSO+1)
        {
             setSelection_JUMP_TORSO = 1;
        }
    
        animationBlendFactor_JUMP_TORSO       += TORSO_FRAME_TIME_01;    
    
    
    
                              if(animationBlendFactor_JUMP_HIPS >= 0.0f && animationBlendFactor_JUMP_HIPS <= 1.0f)
                              {     
                                         hips_ROTATE[3]            = hips_ROTATE_FRAMEA[3]            * (1 - animationBlendFactor_JUMP_HIPS) 
                                                                   + hips_ROTATE_FRAMEB[3]            * animationBlendFactor_JUMP_HIPS;        
        
                                         hips_ROTATE[0]            = hips_ROTATE_FRAMEA[0]            * (1 - animationBlendFactor_JUMP_HIPS) 
                                                                   + hips_ROTATE_FRAMEB[0]            * animationBlendFactor_JUMP_HIPS; 
        
                                         hips_ROTATE[1]            = hips_ROTATE_FRAMEA[1]            * (1 - animationBlendFactor_JUMP_HIPS) 
                                                                   + hips_ROTATE_FRAMEB[1]            * animationBlendFactor_JUMP_HIPS;
        
                                         hips_ROTATE[2]            = hips_ROTATE_FRAMEA[2]            * (1 - animationBlendFactor_JUMP_HIPS) 
                                                                   + hips_ROTATE_FRAMEB[2]            * animationBlendFactor_JUMP_HIPS;    
                             }
                             if(animationBlendFactor_JUMP_HIPS >= 1.0f)
                             {
                                  setSelection_JUMP_HIPS ++;
                                  animationBlendFactor_JUMP_HIPS = 0.0f;
                             }
    
                             if(setSelection_JUMP_HIPS == setSelection_JUMPLimit_HIPS+1)
                             {
                                  setSelection_JUMP_HIPS = 1;
                             }
                             
                             animationBlendFactor_JUMP_HIPS       += HIPS_FRAME_TIME_01;   
  
   

                            if(animationBlendFactor_JUMP_RIGHT_ARM >= 0.0f && animationBlendFactor_JUMP_RIGHT_ARM <= 1.0f)
                              {     
                                  rightUpperArm_ROTATE[3]   = rightUpperArm_ROTATE_FRAMEA[3]   * (1 - animationBlendFactor_JUMP_RIGHT_ARM) 
                                                            + rightUpperArm_ROTATE_FRAMEB[3]   * animationBlendFactor_JUMP_RIGHT_ARM;        
        
                                  rightUpperArm_ROTATE[0]   = rightUpperArm_ROTATE_FRAMEA[0]   * (1 - animationBlendFactor_JUMP_RIGHT_ARM) 
                                                            + rightUpperArm_ROTATE_FRAMEB[0]   * animationBlendFactor_JUMP_RIGHT_ARM; 
        
                                  rightUpperArm_ROTATE[1]   = rightUpperArm_ROTATE_FRAMEA[1]   * (1 - animationBlendFactor_JUMP_RIGHT_ARM) 
                                                            + rightUpperArm_ROTATE_FRAMEB[1]   * animationBlendFactor_JUMP_RIGHT_ARM;
        
                                  rightUpperArm_ROTATE[2]   = rightUpperArm_ROTATE_FRAMEA[2]   * (1 - animationBlendFactor_JUMP_RIGHT_ARM) 
                                                            + rightUpperArm_ROTATE_FRAMEB[2]   * animationBlendFactor_JUMP_RIGHT_ARM;
                                  ////////                                
        
                                  rightForeArm_ROTATE[3]    = rightForeArm_ROTATE_FRAMEA[3]    * (1 - animationBlendFactor_JUMP_RIGHT_ARM) 
                                                            + rightForeArm_ROTATE_FRAMEB[3]    * animationBlendFactor_JUMP_RIGHT_ARM;        
        
                                  rightForeArm_ROTATE[0]    = rightForeArm_ROTATE_FRAMEA[0]    * (1 - animationBlendFactor_JUMP_RIGHT_ARM) 
                                                            + rightForeArm_ROTATE_FRAMEB[0]    * animationBlendFactor_JUMP_RIGHT_ARM; 
        
                                  rightForeArm_ROTATE[1]    = rightForeArm_ROTATE_FRAMEA[1]    * (1 - animationBlendFactor_JUMP_RIGHT_ARM) 
                                                            + rightForeArm_ROTATE_FRAMEB[1]    * animationBlendFactor_JUMP_RIGHT_ARM;
        
                                  rightForeArm_ROTATE[2]    = rightForeArm_ROTATE_FRAMEA[2]    * (1 - animationBlendFactor_JUMP_RIGHT_ARM) 
                                                            + rightForeArm_ROTATE_FRAMEB[2]    * animationBlendFactor_JUMP_RIGHT_ARM;                                          
                                  ////////                              
        
                                  rightGlovedHand_ROTATE[3] = rightGlovedHand_ROTATE_FRAMEA[3] * (1 - animationBlendFactor_JUMP_RIGHT_ARM) 
                                                            + rightGlovedHand_ROTATE_FRAMEB[3] * animationBlendFactor_JUMP_RIGHT_ARM;        
        
                                  rightGlovedHand_ROTATE[0] = rightGlovedHand_ROTATE_FRAMEA[0] * (1 - animationBlendFactor_JUMP_RIGHT_ARM) 
                                                            + rightGlovedHand_ROTATE_FRAMEB[0] * animationBlendFactor_JUMP_RIGHT_ARM; 
        
                                  rightGlovedHand_ROTATE[1] = rightGlovedHand_ROTATE_FRAMEA[1] * (1 - animationBlendFactor_JUMP_RIGHT_ARM) 
                                                            + rightGlovedHand_ROTATE_FRAMEB[1] * animationBlendFactor_JUMP_RIGHT_ARM;
        
                                  rightGlovedHand_ROTATE[2] = rightGlovedHand_ROTATE_FRAMEA[2] * (1 - animationBlendFactor_JUMP_RIGHT_ARM) 
                                                            + rightGlovedHand_ROTATE_FRAMEB[2] * animationBlendFactor_JUMP_RIGHT_ARM;    
                             }
                             
                             if(animationBlendFactor_JUMP_RIGHT_ARM >= 1.0f)
                             {
                                  setSelection_JUMP_RIGHT_ARM ++;
                                  animationBlendFactor_JUMP_RIGHT_ARM = 0.0f;
                             }
    
                             if(setSelection_JUMP_RIGHT_ARM == setSelection_JUMPLimit_RIGHT_ARM + 1)
                             {
                                  setSelection_JUMP_RIGHT_ARM = 1;
                             }
                             
                             animationBlendFactor_JUMP_RIGHT_ARM       += RIGHT_ARM_FRAME_TIME_01;  



        if(animationBlendFactor_JUMP_LEFT_LEG >= 0.0f && animationBlendFactor_JUMP_LEFT_LEG <= 1.0f)
        {    

             leftUpperLeg_ROTATE[3]    = leftUpperLeg_ROTATE_FRAMEA[3]    * (1 - animationBlendFactor_JUMP_LEFT_LEG) 
                                       + leftUpperLeg_ROTATE_FRAMEB[3]    * animationBlendFactor_JUMP_LEFT_LEG;        
        
             leftUpperLeg_ROTATE[0]    = leftUpperLeg_ROTATE_FRAMEA[0]    * (1 - animationBlendFactor_JUMP_LEFT_LEG) 
                                       + leftUpperLeg_ROTATE_FRAMEB[0]    * animationBlendFactor_JUMP_LEFT_LEG; 
        
             leftUpperLeg_ROTATE[1]    = leftUpperLeg_ROTATE_FRAMEA[1]    * (1 - animationBlendFactor_JUMP_LEFT_LEG) 
                                       + leftUpperLeg_ROTATE_FRAMEB[1]    * animationBlendFactor_JUMP_LEFT_LEG;
        
             leftUpperLeg_ROTATE[2]    = leftUpperLeg_ROTATE_FRAMEA[2]    * (1 - animationBlendFactor_JUMP_LEFT_LEG) 
                                       + leftUpperLeg_ROTATE_FRAMEB[2]    * animationBlendFactor_JUMP_LEFT_LEG;
             ///////                                
        
             leftLowerLeg_ROTATE[3]    = leftLowerLeg_ROTATE_FRAMEA[3]    * (1 - animationBlendFactor_JUMP_LEFT_LEG) 
                                       + leftLowerLeg_ROTATE_FRAMEB[3]    * animationBlendFactor_JUMP_LEFT_LEG;        
        
             leftLowerLeg_ROTATE[0]    = leftLowerLeg_ROTATE_FRAMEA[0]    * (1 - animationBlendFactor_JUMP_LEFT_LEG) 
                                       + leftLowerLeg_ROTATE_FRAMEB[0]    * animationBlendFactor_JUMP_LEFT_LEG; 
        
             leftLowerLeg_ROTATE[1]    = leftLowerLeg_ROTATE_FRAMEA[1]    * (1 - animationBlendFactor_JUMP_LEFT_LEG) 
                                       + leftLowerLeg_ROTATE_FRAMEB[1]    * animationBlendFactor_JUMP_LEFT_LEG;
        
             leftLowerLeg_ROTATE[2]    = leftLowerLeg_ROTATE_FRAMEA[2]    * (1 - animationBlendFactor_JUMP_LEFT_LEG) 
                                       + leftLowerLeg_ROTATE_FRAMEB[2]    * animationBlendFactor_JUMP_LEFT_LEG;                                          
             ///////                            
        
             leftFoot_ROTATE[3]        = leftFoot_ROTATE_FRAMEA[3]        * (1 - animationBlendFactor_JUMP_LEFT_LEG) 
                                       + leftFoot_ROTATE_FRAMEB[3]        * animationBlendFactor_JUMP_LEFT_LEG;        
        
             leftFoot_ROTATE[0]        = leftFoot_ROTATE_FRAMEA[0]        * (1 - animationBlendFactor_JUMP_LEFT_LEG) 
                                       + leftFoot_ROTATE_FRAMEB[0]        * animationBlendFactor_JUMP_LEFT_LEG; 
        
             leftFoot_ROTATE[1]        = leftFoot_ROTATE_FRAMEA[1]        * (1 - animationBlendFactor_JUMP_LEFT_LEG) 
                                       + leftFoot_ROTATE_FRAMEB[1]        * animationBlendFactor_JUMP_LEFT_LEG;
        
             leftFoot_ROTATE[2]        = leftFoot_ROTATE_FRAMEA[2]        * (1 - animationBlendFactor_JUMP_LEFT_LEG) 
                                       + leftFoot_ROTATE_FRAMEB[2]        * animationBlendFactor_JUMP_LEFT_LEG;     
        }    
        
 
        if(animationBlendFactor_JUMP_LEFT_LEG >= 1.0f)
        {
             setSelection_JUMP_LEFT_LEG ++;
             animationBlendFactor_JUMP_LEFT_LEG = 0.0f;
        }
    
        if(setSelection_JUMP_LEFT_LEG == setSelection_JUMPLimit_LEFT_LEG+1)
        {
             setSelection_JUMP_LEFT_LEG = 1;
        }
    
        animationBlendFactor_JUMP_LEFT_LEG     += LEFT_LEG_FRAME_TIME_01; 
        
        

        
        

                              if(animationBlendFactor_JUMP_RIGHT_LEG >= 0.0f && animationBlendFactor_JUMP_RIGHT_LEG <= 1.0f)
                              {     
                                  rightUpperLeg_ROTATE[3]   = rightUpperLeg_ROTATE_FRAMEA[3]   * (1 - animationBlendFactor_JUMP_RIGHT_LEG) 
                                                            + rightUpperLeg_ROTATE_FRAMEB[3]   * animationBlendFactor_JUMP_RIGHT_LEG;        
        
                                  rightUpperLeg_ROTATE[0]   = rightUpperLeg_ROTATE_FRAMEA[0]   * (1 - animationBlendFactor_JUMP_RIGHT_LEG) 
                                                            + rightUpperLeg_ROTATE_FRAMEB[0]   * animationBlendFactor_JUMP_RIGHT_LEG; 
        
                                  rightUpperLeg_ROTATE[1]   = rightUpperLeg_ROTATE_FRAMEA[1]   * (1 - animationBlendFactor_JUMP_RIGHT_LEG) 
                                                            + rightUpperLeg_ROTATE_FRAMEB[1]   * animationBlendFactor_JUMP_RIGHT_LEG;
        
                                  rightUpperLeg_ROTATE[2]   = rightUpperLeg_ROTATE_FRAMEA[2]   * (1 - animationBlendFactor_JUMP_RIGHT_LEG) 
                                                            + rightUpperLeg_ROTATE_FRAMEB[2]   * animationBlendFactor_JUMP_RIGHT_LEG;
                                  ///////                                
        
                                  rightLowerLeg_ROTATE[3]   = rightLowerLeg_ROTATE_FRAMEA[3]   * (1 - animationBlendFactor_JUMP_RIGHT_LEG) 
                                                            + rightLowerLeg_ROTATE_FRAMEB[3]   * animationBlendFactor_JUMP_RIGHT_LEG;        
        
                                  rightLowerLeg_ROTATE[0]   = rightLowerLeg_ROTATE_FRAMEA[0]   * (1 - animationBlendFactor_JUMP_RIGHT_LEG) 
                                                            + rightLowerLeg_ROTATE_FRAMEB[0]   * animationBlendFactor_JUMP_RIGHT_LEG; 
        
                                  rightLowerLeg_ROTATE[1]   = rightLowerLeg_ROTATE_FRAMEA[1]   * (1 - animationBlendFactor_JUMP_RIGHT_LEG) 
                                                            + rightLowerLeg_ROTATE_FRAMEB[1]   * animationBlendFactor_JUMP_RIGHT_LEG;
        
                                  rightLowerLeg_ROTATE[2]   = rightLowerLeg_ROTATE_FRAMEA[2]   * (1 - animationBlendFactor_JUMP_RIGHT_LEG) 
                                                            + rightLowerLeg_ROTATE_FRAMEB[2]   * animationBlendFactor_JUMP_RIGHT_LEG;                                          
                                  ///////                            
        
                                  rightFoot_ROTATE[3]       = rightFoot_ROTATE_FRAMEA[3]       * (1 - animationBlendFactor_JUMP_RIGHT_LEG) 
                                                            + rightFoot_ROTATE_FRAMEB[3]       * animationBlendFactor_JUMP_RIGHT_LEG;        
        
                                  rightFoot_ROTATE[0]       = rightFoot_ROTATE_FRAMEA[0]       * (1 - animationBlendFactor_JUMP_RIGHT_LEG) 
                                                            + rightFoot_ROTATE_FRAMEB[0]       * animationBlendFactor_JUMP_RIGHT_LEG; 
        
                                  rightFoot_ROTATE[1]       = rightFoot_ROTATE_FRAMEA[1]       * (1 - animationBlendFactor_JUMP_RIGHT_LEG) 
                                                            + rightFoot_ROTATE_FRAMEB[1]       * animationBlendFactor_JUMP_RIGHT_LEG;
        
                                  rightFoot_ROTATE[2]       = rightFoot_ROTATE_FRAMEA[2]       * (1 - animationBlendFactor_JUMP_RIGHT_LEG) 
                                                            + rightFoot_ROTATE_FRAMEB[2]       * animationBlendFactor_JUMP_RIGHT_LEG; 
                             }
                             
                             if(animationBlendFactor_JUMP_RIGHT_LEG >= 1.0f)
                             {
                                  setSelection_JUMP_RIGHT_LEG ++;
                                  animationBlendFactor_JUMP_RIGHT_LEG = 0.0f;
                             }
    
                             if(setSelection_JUMP_RIGHT_LEG == setSelection_JUMPLimit_RIGHT_LEG + 1)
                             {
                                  setSelection_JUMP_RIGHT_LEG = 1;
                             }
                             
                             animationBlendFactor_JUMP_RIGHT_LEG       += RIGHT_LEG_FRAME_TIME_01;    
   
    
      //#include "runTimeAnimation.cpp"
    
      #include "ME_AnimationSet_00.cpp"
}










