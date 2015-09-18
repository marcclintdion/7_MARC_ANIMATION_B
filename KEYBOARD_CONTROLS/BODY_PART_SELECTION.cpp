        
       
if(BODY_PART_SELECTION == 1)////___LEFT_ARM
{    
/////////////////////////////////////////////_________LEFT___ARM_________0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
/////////////////////////////////////////////_________LEFT___ARM_________0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
/////////////////////////////////////////////_________LEFT___ARM_________0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
/////////////////////////////////////////////_________LEFT___ARM_________0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
/////////////////////////////////////////////_________LEFT___ARM_________0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
/////////////////////////////////////////////_________LEFT___ARM_________0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
if(keys['8'])
    leftArmSelection = 8;
if(keys['9'])
    leftArmSelection = 9;
if(keys['0'])
    leftArmSelection = 0;

//////____________________________________________________________________________________________________________________________ 
if(leftArmSelection == 8)    
{
    if (keys[VK_PRIOR])
    {
          leftUpperArm_ROTATE[3]   += 1.0f;                
    }    
    if (keys[VK_NEXT])
    {
          leftUpperArm_ROTATE[3]   -= 1.0f;                
    } 
    if (keys[VK_NUMPAD0]) 
    {
          leftUpperArm_ROTATE[3]    = 0.0f;           
    }         
            
//////_______________________________________   
    if (keys[VK_NUMPAD9]) 
	{
           if(leftUpperArm_ROTATE[0] <= 1.0f)           
              leftUpperArm_ROTATE[0] += 0.01f;//_____FORWARD            
    }
    if (keys[VK_NUMPAD8]) 
    {
           if(leftUpperArm_ROTATE[0] >= 0.0f)          
              leftUpperArm_ROTATE[0] -= 0.01f;//_____REVERSE             
    }
    if (keys[VK_NUMPAD7]) 
    {
          leftUpperArm_ROTATE[0] = 0.000001f;//______RESET 
    } 
//////_______________________________________    
    if (keys[VK_NUMPAD6]) 
	{
         if(leftUpperArm_ROTATE[1] <= 1.0f)          
            leftUpperArm_ROTATE[1] += 0.01f;//_______FORWARD            
    }
    if (keys[VK_NUMPAD5]) 
    {
         if(leftUpperArm_ROTATE[1] >= 0.0f)
            leftUpperArm_ROTATE[1] -= 0.01f;//_______REVERSE             

    }     
    if (keys[VK_NUMPAD4]) 
    {
            leftUpperArm_ROTATE[1] = 0.000001f;//____RESET           
    }    
//////_______________________________________    
    if (keys[VK_NUMPAD3]) 
	{
          if(leftUpperArm_ROTATE[2] <= 1.0f)           
             leftUpperArm_ROTATE[2] += 0.01f;//______FORWARD            
    }
    if (keys[VK_NUMPAD2]) 
    {
          if(leftUpperArm_ROTATE[2] >= 0.0f)          
             leftUpperArm_ROTATE[2] -= 0.01f;//______REVERSE             
    } 
    if (keys[VK_NUMPAD1]) 
    {
             leftUpperArm_ROTATE[2] = 0.000001f;//___RESET          
    }    
}
//////____________________________________________________________________________________________________________________________ 
if(leftArmSelection == 9)    
{
    if (keys[VK_PRIOR])
    {
          leftForeArm_ROTATE[3]   += 1.0f;                
    }    
    if (keys[VK_NEXT])
    {
          leftForeArm_ROTATE[3]   -= 1.0f;                
    } 
    if (keys[VK_NUMPAD0]) 
    {
          leftForeArm_ROTATE[3]    = 0.0f;           
    }         
            
//////_______________________________________    
    if (keys[VK_NUMPAD9]) 
	{
          if(leftForeArm_ROTATE[0] <= 1.0f)           
             leftForeArm_ROTATE[0] += 0.01f;//____FORWARD            
    }
    if (keys[VK_NUMPAD8]) 
    {
          if(leftForeArm_ROTATE[0] >= 0.0f)          
             leftForeArm_ROTATE[0] -= 0.01f;//____REVERSE            
    }
    if (keys[VK_NUMPAD7]) 
    {
          leftForeArm_ROTATE[0] = 0.000001f;//____RESET  
    } 
//////_______________________________________      
    if (keys[VK_NUMPAD6]) 
	{
         if(leftForeArm_ROTATE[1] <= 1.0f)          
            leftForeArm_ROTATE[1] += 0.01f;//_____FORWARD            
    }
    if (keys[VK_NUMPAD5]) 
    {
         if(leftForeArm_ROTATE[1] >= 0.0f)
            leftForeArm_ROTATE[1] -= 0.01f;//_____REVERSE            
    }     

    if (keys[VK_NUMPAD4]) 
    {
           leftForeArm_ROTATE[1] = 0.000001f;//___RESET            
    }    
//////_______________________________________     
    if (keys[VK_NUMPAD3]) 
	{
        if(leftForeArm_ROTATE[2] <= 1.0f)           
           leftForeArm_ROTATE[2] += 0.01f;//______FORWARD            
    }
    if (keys[VK_NUMPAD2]) 
    {
        if(leftForeArm_ROTATE[2] >= 0.0f)          
           leftForeArm_ROTATE[2] -= 0.01f;//______REVERSE            
    } 
    if (keys[VK_NUMPAD1]) 
    {
           leftForeArm_ROTATE[2] = 0.000001f;//___RESET           
    }    
}

//////____________________________________________________________________________________________________________________________ 
if(leftArmSelection == 0)    
{
    if (keys[VK_PRIOR])
    {
          leftGlovedHand_ROTATE[3]   += 1.0f;                
    }    
    if (keys[VK_NEXT])
    {
          leftGlovedHand_ROTATE[3]   -= 1.0f;                
    } 
    if (keys[VK_NUMPAD0]) 
    {
          leftGlovedHand_ROTATE[3]    = 0.0f;           
    }         
            
//////_______________________________________    
    if (keys[VK_NUMPAD9]) 
	{
         if(leftGlovedHand_ROTATE[0] <= 1.0f)           
            leftGlovedHand_ROTATE[0] += 0.01f;//_____FORWARD            
    }
    if (keys[VK_NUMPAD8]) 
    {
         if(leftGlovedHand_ROTATE[0] >= -0.0f)          
            leftGlovedHand_ROTATE[0] -= 0.01f;//_____REVERSE            
    }
    if (keys[VK_NUMPAD7]) 
    {
            leftGlovedHand_ROTATE[0] = 0.000001f;//__RESET 
    } 
//////_______________________________________     
    if (keys[VK_NUMPAD6]) 
	{
         if(leftGlovedHand_ROTATE[1] <= 1.0f)          
            leftGlovedHand_ROTATE[1] += 0.01f;//_____FORWARD            
    }
    if (keys[VK_NUMPAD5]) 
    {
        if(leftGlovedHand_ROTATE[1] >= -0.0f)
           leftGlovedHand_ROTATE[1] -= 0.01f;//______REVERSE            

    }     
    if (keys[VK_NUMPAD4]) 
    {
           leftGlovedHand_ROTATE[1] = 0.000001f;//___RESET            
    }    
//////_______________________________________      
    if (keys[VK_NUMPAD3]) 
	{
        if(leftGlovedHand_ROTATE[2] <= 1.0f)           
           leftGlovedHand_ROTATE[2] += 0.01f;//______FORWARD             
    }
    if (keys[VK_NUMPAD2]) 
    {
       if(leftGlovedHand_ROTATE[2] >= -0.0f)          
          leftGlovedHand_ROTATE[2] -= 0.01f;//_______REVERSE            
    } 
    if (keys[VK_NUMPAD1]) 
    {
          leftGlovedHand_ROTATE[2] = 0.000001f;//____RESET           
    }    
}

}
/////////////////////////////////////////////_________LEFT___ARM_________0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
/////////////////////////////////////////////_________LEFT___ARM_________0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
/////////////////////////////////////////////_________LEFT___ARM_________0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
/////////////////////////////////////////////_________LEFT___ARM_________0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
/////////////////////////////////////////////_________LEFT___ARM_________0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
/////////////////////////////////////////////_________LEFT___ARM_________0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000

////////////////////////////////////// 

/////////////////////////////////////////////_________RIGHT__ARM_________%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
/////////////////////////////////////////////_________RIGHT__ARM_________%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
/////////////////////////////////////////////_________RIGHT__ARM_________%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                      
/////////////////////////////////////////////_________RIGHT__ARM_________%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
/////////////////////////////////////////////_________RIGHT__ARM_________%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
/////////////////////////////////////////////_________RIGHT__ARM_________%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
if(BODY_PART_SELECTION == 2)////___RIGHT_ARM
{

if(keys['8'])
    rightArmSelection = 8;
if(keys['9'])
    rightArmSelection = 9;
if(keys['0'])
    rightArmSelection = 0;

//////____________________________________________________________________________________________________________________________ 
if(rightArmSelection == 8)    
{
    if (keys[VK_PRIOR])
    {
          rightArmUpper_ROTATE[3]   += 1.0f;                
    }    
    if (keys[VK_NEXT])
    {
          rightArmUpper_ROTATE[3]   -= 1.0f;                
    } 
    if (keys[VK_NUMPAD0]) 
    {
          rightArmUpper_ROTATE[3]    = 0.0f;           
    }         
            
//////_______________________________________   
    if (keys[VK_NUMPAD9]) 
	{
           if(rightArmUpper_ROTATE[0] <= 1.0f)           
              rightArmUpper_ROTATE[0] += 0.01f;//_____FORWARD            
    }
    if (keys[VK_NUMPAD8]) 
    {
           if(rightArmUpper_ROTATE[0] >= 0.0f)          
              rightArmUpper_ROTATE[0] -= 0.01f;//_____REVERSE             
    }
    if (keys[VK_NUMPAD7]) 
    {
          rightArmUpper_ROTATE[0] = 0.000001f;//______RESET 
    } 
//////_______________________________________    
    if (keys[VK_NUMPAD6]) 
	{
         if(rightArmUpper_ROTATE[1] <= 1.0f)          
            rightArmUpper_ROTATE[1] += 0.01f;//_______FORWARD            
    }
    if (keys[VK_NUMPAD5]) 
    {
         if(rightArmUpper_ROTATE[1] >= 0.0f)
            rightArmUpper_ROTATE[1] -= 0.01f;//_______REVERSE             

    }     
    if (keys[VK_NUMPAD4]) 
    {
            rightArmUpper_ROTATE[1] = 0.000001f;//____RESET           
    }    
//////_______________________________________    
    if (keys[VK_NUMPAD3]) 
	{
          if(rightArmUpper_ROTATE[2] <= 1.0f)           
             rightArmUpper_ROTATE[2] += 0.01f;//______FORWARD            
    }
    if (keys[VK_NUMPAD2]) 
    {
          if(rightArmUpper_ROTATE[2] >= 0.0f)          
             rightArmUpper_ROTATE[2] -= 0.01f;//______REVERSE             
    } 
    if (keys[VK_NUMPAD1]) 
    {
             rightArmUpper_ROTATE[2] = 0.000001f;//___RESET          
    }    
}
//////____________________________________________________________________________________________________________________________ 
if(rightArmSelection == 9)    
{
    if (keys[VK_PRIOR])
    {
          rightForeArm_ROTATE[3]   += 1.0f;                
    }    
    if (keys[VK_NEXT])
    {
          rightForeArm_ROTATE[3]   -= 1.0f;                
    } 
    if (keys[VK_NUMPAD0]) 
    {
          rightForeArm_ROTATE[3]    = 0.0f;           
    }         
            
//////_______________________________________    
    if (keys[VK_NUMPAD9]) 
	{
          if(rightForeArm_ROTATE[0] <= 1.0f)           
             rightForeArm_ROTATE[0] += 0.01f;//____FORWARD            
    }
    if (keys[VK_NUMPAD8]) 
    {
          if(rightForeArm_ROTATE[0] >= 0.0f)          
             rightForeArm_ROTATE[0] -= 0.01f;//____REVERSE            
    }
    if (keys[VK_NUMPAD7]) 
    {
          rightForeArm_ROTATE[0] = 0.000001f;//____RESET  
    } 
//////_______________________________________      
    if (keys[VK_NUMPAD6]) 
	{
         if(rightForeArm_ROTATE[1] <= 1.0f)          
            rightForeArm_ROTATE[1] += 0.01f;//_____FORWARD            
    }
    if (keys[VK_NUMPAD5]) 
    {
         if(rightForeArm_ROTATE[1] >= 0.0f)
            rightForeArm_ROTATE[1] -= 0.01f;//_____REVERSE            
    }     

    if (keys[VK_NUMPAD4]) 
    {
           rightForeArm_ROTATE[1] = 0.000001f;//___RESET            
    }    
//////_______________________________________     
    if (keys[VK_NUMPAD3]) 
	{
        if(rightForeArm_ROTATE[2] <= 1.0f)           
           rightForeArm_ROTATE[2] += 0.01f;//______FORWARD            
    }
    if (keys[VK_NUMPAD2]) 
    {
        if(rightForeArm_ROTATE[2] >= 0.0f)          
           rightForeArm_ROTATE[2] -= 0.01f;//______REVERSE            
    } 
    if (keys[VK_NUMPAD1]) 
    {
           rightForeArm_ROTATE[2] = 0.000001f;//___RESET           
    }    
}

//////____________________________________________________________________________________________________________________________ 
if(rightArmSelection == 0)    
{
    if (keys[VK_PRIOR])
    {
          rightGlovedHand_ROTATE[3]   += 1.0f;                
    }    
    if (keys[VK_NEXT])
    {
          rightGlovedHand_ROTATE[3]   -= 1.0f;                
    } 
    if (keys[VK_NUMPAD0]) 
    {
          rightGlovedHand_ROTATE[3]    = 0.0f;           
    }         
            
//////_______________________________________    
    if (keys[VK_NUMPAD9]) 
	{
         if(rightGlovedHand_ROTATE[0] <= 1.0f)           
            rightGlovedHand_ROTATE[0] += 0.01f;//_____FORWARD            
    }
    if (keys[VK_NUMPAD8]) 
    {
         if(rightGlovedHand_ROTATE[0] >= -0.0f)          
            rightGlovedHand_ROTATE[0] -= 0.01f;//_____REVERSE            
    }
    if (keys[VK_NUMPAD7]) 
    {
            rightGlovedHand_ROTATE[0] = 0.000001f;//__RESET 
    } 
//////_______________________________________     
    if (keys[VK_NUMPAD6]) 
	{
         if(rightGlovedHand_ROTATE[1] <= 1.0f)          
            rightGlovedHand_ROTATE[1] += 0.01f;//_____FORWARD            
    }
    if (keys[VK_NUMPAD5]) 
    {
        if(rightGlovedHand_ROTATE[1] >= -0.0f)
           rightGlovedHand_ROTATE[1] -= 0.01f;//______REVERSE            

    }     
    if (keys[VK_NUMPAD4]) 
    {
           rightGlovedHand_ROTATE[1] = 0.000001f;//___RESET            
    }    
//////_______________________________________      
    if (keys[VK_NUMPAD3]) 
	{
        if(rightGlovedHand_ROTATE[2] <= 1.0f)           
           rightGlovedHand_ROTATE[2] += 0.01f;//______FORWARD             
    }
    if (keys[VK_NUMPAD2]) 
    {
       if(rightGlovedHand_ROTATE[2] >= -0.0f)          
          rightGlovedHand_ROTATE[2] -= 0.01f;//_______REVERSE            
    } 
    if (keys[VK_NUMPAD1]) 
    {
          rightGlovedHand_ROTATE[2] = 0.000001f;//____RESET           
    }    
}

}
/////////////////////////////////////////////_________RIGHT__ARM_________%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
/////////////////////////////////////////////_________RIGHT__ARM_________%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
/////////////////////////////////////////////_________RIGHT__ARM_________%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

/////////////////////////////////////////////_________LEFT__LEG__________+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/////////////////////////////////////////////_________LEFT__LEG__________+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/////////////////////////////////////////////_________LEFT__LEG__________+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/////////////////////////////////////////////_________LEFT__LEG__________+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/////////////////////////////////////////////_________LEFT__LEG__________+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
if(BODY_PART_SELECTION == 3)////___LEFT_LEG
{
                              
if(keys['8'])
    leftLegSelection = 8;
if(keys['9'])
    leftLegSelection = 9;
if(keys['0'])
    leftLegSelection = 0;

//////____________________________________________________________________________________________________________________________ 
if(leftLegSelection == 8)    
{
    if (keys[VK_PRIOR])
    {
          leftUpperLeg_ROTATE[3]   += 1.0f;                
    }    
    if (keys[VK_NEXT])
    {
          leftUpperLeg_ROTATE[3]   -= 1.0f;                
    } 
    if (keys[VK_NUMPAD0]) 
    {
          leftUpperLeg_ROTATE[3]    = 0.0f;           
    }         
            
//////_______________________________________   
    if (keys[VK_NUMPAD9]) 
	{
           if(leftUpperLeg_ROTATE[0] <= 1.0f)           
              leftUpperLeg_ROTATE[0] += 0.01f;//_____FORWARD            
    }
    if (keys[VK_NUMPAD8]) 
    {
           if(leftUpperLeg_ROTATE[0] >= 0.0f)          
              leftUpperLeg_ROTATE[0] -= 0.01f;//_____REVERSE             
    }
    if (keys[VK_NUMPAD7]) 
    {
          leftUpperLeg_ROTATE[0] = 0.000001f;//______RESET 
    } 
//////_______________________________________    
    if (keys[VK_NUMPAD6]) 
	{
         if(leftUpperLeg_ROTATE[1] <= 1.0f)          
            leftUpperLeg_ROTATE[1] += 0.01f;//_______FORWARD            
    }
    if (keys[VK_NUMPAD5]) 
    {
         if(leftUpperLeg_ROTATE[1] >= 0.0f)
            leftUpperLeg_ROTATE[1] -= 0.01f;//_______REVERSE             

    }     
    if (keys[VK_NUMPAD4]) 
    {
            leftUpperLeg_ROTATE[1] = 0.000001f;//____RESET           
    }    
//////_______________________________________    
    if (keys[VK_NUMPAD3]) 
	{
          if(leftUpperLeg_ROTATE[2] <= 1.0f)           
             leftUpperLeg_ROTATE[2] += 0.01f;//______FORWARD            
    }
    if (keys[VK_NUMPAD2]) 
    {
          if(leftUpperLeg_ROTATE[2] >= 0.0f)          
             leftUpperLeg_ROTATE[2] -= 0.01f;//______REVERSE             
    } 
    if (keys[VK_NUMPAD1]) 
    {
             leftUpperLeg_ROTATE[2] = 0.000001f;//___RESET          
    }    
}
//////____________________________________________________________________________________________________________________________ 
if(leftLegSelection == 9)    
{
    if (keys[VK_PRIOR])
    {
          leftLowerLeg_ROTATE[3]   += 1.0f;                
    }    
    if (keys[VK_NEXT])
    {
          leftLowerLeg_ROTATE[3]   -= 1.0f;                
    } 
    if (keys[VK_NUMPAD0]) 
    {
          leftLowerLeg_ROTATE[3]    = 0.0f;           
    }         
            
//////_______________________________________    
    if (keys[VK_NUMPAD9]) 
	{
          if(leftLowerLeg_ROTATE[0] <= 1.0f)           
             leftLowerLeg_ROTATE[0] += 0.01f;//____FORWARD            
    }
    if (keys[VK_NUMPAD8]) 
    {
          if(leftLowerLeg_ROTATE[0] >= 0.0f)          
             leftLowerLeg_ROTATE[0] -= 0.01f;//____REVERSE            
    }
    if (keys[VK_NUMPAD7]) 
    {
          leftLowerLeg_ROTATE[0] = 0.000001f;//____RESET  
    } 
//////_______________________________________      
    if (keys[VK_NUMPAD6]) 
	{
         if(leftLowerLeg_ROTATE[1] <= 1.0f)          
            leftLowerLeg_ROTATE[1] += 0.01f;//_____FORWARD            
    }
    if (keys[VK_NUMPAD5]) 
    {
         if(leftLowerLeg_ROTATE[1] >= 0.0f)
            leftLowerLeg_ROTATE[1] -= 0.01f;//_____REVERSE            
    }     

    if (keys[VK_NUMPAD4]) 
    {
           leftLowerLeg_ROTATE[1] = 0.000001f;//___RESET            
    }    
//////_______________________________________     
    if (keys[VK_NUMPAD3]) 
	{
        if(leftLowerLeg_ROTATE[2] <= 1.0f)           
           leftLowerLeg_ROTATE[2] += 0.01f;//______FORWARD            
    }
    if (keys[VK_NUMPAD2]) 
    {
        if(leftLowerLeg_ROTATE[2] >= 0.0f)          
           leftLowerLeg_ROTATE[2] -= 0.01f;//______REVERSE            
    } 
    if (keys[VK_NUMPAD1]) 
    {
           leftLowerLeg_ROTATE[2] = 0.000001f;//___RESET           
    }    
}

//////____________________________________________________________________________________________________________________________ 
if(leftLegSelection == 0)    
{
    if (keys[VK_PRIOR])
    {
          leftFoot_ROTATE[3]   += 1.0f;                
    }    
    if (keys[VK_NEXT])
    {
          leftFoot_ROTATE[3]   -= 1.0f;                
    } 
    if (keys[VK_NUMPAD0]) 
    {
          leftFoot_ROTATE[3]    = 0.0f;           
    }         
            
//////_______________________________________    
    if (keys[VK_NUMPAD9]) 
	{
         if(leftFoot_ROTATE[0] <= 1.0f)           
            leftFoot_ROTATE[0] += 0.01f;//_____FORWARD            
    }
    if (keys[VK_NUMPAD8]) 
    {
         if(leftFoot_ROTATE[0] >= -0.0f)          
            leftFoot_ROTATE[0] -= 0.01f;//_____REVERSE            
    }
    if (keys[VK_NUMPAD7]) 
    {
            leftFoot_ROTATE[0] = 0.000001f;//__RESET 
    } 
//////_______________________________________     
    if (keys[VK_NUMPAD6]) 
	{
         if(leftFoot_ROTATE[1] <= 1.0f)          
            leftFoot_ROTATE[1] += 0.01f;//_____FORWARD            
    }
    if (keys[VK_NUMPAD5]) 
    {
        if(leftFoot_ROTATE[1] >= -0.0f)
           leftFoot_ROTATE[1] -= 0.01f;//______REVERSE            

    }     
    if (keys[VK_NUMPAD4]) 
    {
           leftFoot_ROTATE[1] = 0.000001f;//___RESET            
    }    
//////_______________________________________      
    if (keys[VK_NUMPAD3]) 
	{
        if(leftFoot_ROTATE[2] <= 1.0f)           
           leftFoot_ROTATE[2] += 0.01f;//______FORWARD             
    }
    if (keys[VK_NUMPAD2]) 
    {
       if(leftFoot_ROTATE[2] >= -0.0f)          
          leftFoot_ROTATE[2] -= 0.01f;//_______REVERSE            
    } 
    if (keys[VK_NUMPAD1]) 
    {
          leftFoot_ROTATE[2] = 0.000001f;//____RESET           
    }    
}

}
/////////////////////////////////////////////_________LEFT__LEG__________+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/////////////////////////////////////////////_________LEFT__LEG__________+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/////////////////////////////////////////////_________LEFT__LEG__________+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/////////////////////////////////////////////_________LEFT__LEG__________+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/////////////////////////////////////////////_________LEFT__LEG__________+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

////////////////////////////////////////////__________RIGHT_LEG__________^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
////////////////////////////////////////////__________RIGHT_LEG__________^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
////////////////////////////////////////////__________RIGHT_LEG__________^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
////////////////////////////////////////////__________RIGHT_LEG__________^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
////////////////////////////////////////////__________RIGHT_LEG__________^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
if(BODY_PART_SELECTION == 4)////___RIGHT_LEG
{
if(keys['8'])
    rightLegSelection = 8;
if(keys['9'])
    rightLegSelection = 9;
if(keys['0'])
    rightLegSelection = 0;

//////____________________________________________________________________________________________________________________________ 
if(rightLegSelection == 8)    
{
    if (keys[VK_PRIOR])
    {
          rightUpperLeg_ROTATE[3]   += 1.0f;                
    }    
    if (keys[VK_NEXT])
    {
          rightUpperLeg_ROTATE[3]   -= 1.0f;                
    } 
    if (keys[VK_NUMPAD0]) 
    {
          rightUpperLeg_ROTATE[3]    = 0.0f;           
    }         
            
//////_______________________________________   
    if (keys[VK_NUMPAD9]) 
	{
           if(rightUpperLeg_ROTATE[0] <= 1.0f)           
              rightUpperLeg_ROTATE[0] += 0.01f;//_____FORWARD            
    }
    if (keys[VK_NUMPAD8]) 
    {
           if(rightUpperLeg_ROTATE[0] >= 0.0f)          
              rightUpperLeg_ROTATE[0] -= 0.01f;//_____REVERSE             
    }
    if (keys[VK_NUMPAD7]) 
    {
          rightUpperLeg_ROTATE[0] = 0.000001f;//______RESET 
    } 
//////_______________________________________    
    if (keys[VK_NUMPAD6]) 
	{
         if(rightUpperLeg_ROTATE[1] <= 1.0f)          
            rightUpperLeg_ROTATE[1] += 0.01f;//_______FORWARD            
    }
    if (keys[VK_NUMPAD5]) 
    {
         if(rightUpperLeg_ROTATE[1] >= 0.0f)
            rightUpperLeg_ROTATE[1] -= 0.01f;//_______REVERSE             

    }     
    if (keys[VK_NUMPAD4]) 
    {
            rightUpperLeg_ROTATE[1] = 0.000001f;//____RESET           
    }    
//////_______________________________________    
    if (keys[VK_NUMPAD3]) 
	{
          if(rightUpperLeg_ROTATE[2] <= 1.0f)           
             rightUpperLeg_ROTATE[2] += 0.01f;//______FORWARD            
    }
    if (keys[VK_NUMPAD2]) 
    {
          if(rightUpperLeg_ROTATE[2] >= 0.0f)          
             rightUpperLeg_ROTATE[2] -= 0.01f;//______REVERSE             
    } 
    if (keys[VK_NUMPAD1]) 
    {
             rightUpperLeg_ROTATE[2] = 0.000001f;//___RESET          
    }    
}
//////____________________________________________________________________________________________________________________________ 
if(rightLegSelection == 9)    
{
    if (keys[VK_PRIOR])
    {
          rightLowerLeg_ROTATE[3]   += 1.0f;                
    }    
    if (keys[VK_NEXT])
    {
          rightLowerLeg_ROTATE[3]   -= 1.0f;                
    } 
    if (keys[VK_NUMPAD0]) 
    {
          rightLowerLeg_ROTATE[3]    = 0.0f;           
    }         
            
//////_______________________________________    
    if (keys[VK_NUMPAD9]) 
	{
          if(rightLowerLeg_ROTATE[0] <= 1.0f)           
             rightLowerLeg_ROTATE[0] += 0.01f;//____FORWARD            
    }
    if (keys[VK_NUMPAD8]) 
    {
          if(rightLowerLeg_ROTATE[0] >= 0.0f)          
             rightLowerLeg_ROTATE[0] -= 0.01f;//____REVERSE            
    }
    if (keys[VK_NUMPAD7]) 
    {
          rightLowerLeg_ROTATE[0] = 0.000001f;//____RESET  
    } 
//////_______________________________________      
    if (keys[VK_NUMPAD6]) 
	{
         if(rightLowerLeg_ROTATE[1] <= 1.0f)          
            rightLowerLeg_ROTATE[1] += 0.01f;//_____FORWARD            
    }
    if (keys[VK_NUMPAD5]) 
    {
         if(rightLowerLeg_ROTATE[1] >= 0.0f)
            rightLowerLeg_ROTATE[1] -= 0.01f;//_____REVERSE            
    }     

    if (keys[VK_NUMPAD4]) 
    {
           rightLowerLeg_ROTATE[1] = 0.000001f;//___RESET            
    }    
//////_______________________________________     
    if (keys[VK_NUMPAD3]) 
	{
        if(rightLowerLeg_ROTATE[2] <= 1.0f)           
           rightLowerLeg_ROTATE[2] += 0.01f;//______FORWARD            
    }
    if (keys[VK_NUMPAD2]) 
    {
        if(rightLowerLeg_ROTATE[2] >= 0.0f)          
           rightLowerLeg_ROTATE[2] -= 0.01f;//______REVERSE            
    } 
    if (keys[VK_NUMPAD1]) 
    {
           rightLowerLeg_ROTATE[2] = 0.000001f;//___RESET           
    }    
}

//////____________________________________________________________________________________________________________________________ 
if(rightLegSelection == 0)    
{
    if (keys[VK_PRIOR])
    {
          rightFoot_ROTATE[3]   += 1.0f;                
    }    
    if (keys[VK_NEXT])
    {
          rightFoot_ROTATE[3]   -= 1.0f;                
    } 
    if (keys[VK_NUMPAD0]) 
    {
          rightFoot_ROTATE[3]    = 0.0f;           
    }         
            
//////_______________________________________    
    if (keys[VK_NUMPAD9]) 
	{
         if(rightFoot_ROTATE[0] <= 1.0f)           
            rightFoot_ROTATE[0] += 0.01f;//_____FORWARD            
    }
    if (keys[VK_NUMPAD8]) 
    {
         if(rightFoot_ROTATE[0] >= -0.0f)          
            rightFoot_ROTATE[0] -= 0.01f;//_____REVERSE            
    }
    if (keys[VK_NUMPAD7]) 
    {
            rightFoot_ROTATE[0] = 0.000001f;//__RESET 
    } 
//////_______________________________________     
    if (keys[VK_NUMPAD6]) 
	{
         if(rightFoot_ROTATE[1] <= 1.0f)          
            rightFoot_ROTATE[1] += 0.01f;//_____FORWARD            
    }
    if (keys[VK_NUMPAD5]) 
    {
        if(rightFoot_ROTATE[1] >= -0.0f)
           rightFoot_ROTATE[1] -= 0.01f;//______REVERSE            

    }     
    if (keys[VK_NUMPAD4]) 
    {
           rightFoot_ROTATE[1] = 0.000001f;//___RESET            
    }    
//////_______________________________________      
    if (keys[VK_NUMPAD3]) 
	{
        if(rightFoot_ROTATE[2] <= 1.0f)           
           rightFoot_ROTATE[2] += 0.01f;//______FORWARD             
    }
    if (keys[VK_NUMPAD2]) 
    {
       if(rightFoot_ROTATE[2] >= -0.0f)          
          rightFoot_ROTATE[2] -= 0.01f;//_______REVERSE            
    } 
    if (keys[VK_NUMPAD1]) 
    {
          rightFoot_ROTATE[2] = 0.000001f;//____RESET           
    }    
}
}
////////////////////////////////////////////__________RIGHT_LEG__________^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
////////////////////////////////////////////__________RIGHT_LEG__________^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
////////////////////////////////////////////__________RIGHT_LEG__________^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
////////////////////////////////////////////__________RIGHT_LEG__________^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
////////////////////////////////////////////__________RIGHT_LEG__________^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

////////////////////////////////////////////______HIPS__TORSO__HEAD______^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
////////////////////////////////////////////______HIPS__TORSO__HEAD______^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
////////////////////////////////////////////______HIPS__TORSO__HEAD______^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
////////////////////////////////////////////______HIPS__TORSO__HEAD______^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
////////////////////////////////////////////______HIPS__TORSO__HEAD______^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
if(BODY_PART_SELECTION == 5)////___HIPS
{ 
    if (keys[VK_PRIOR])
    {
          hips_ROTATE[3]   += 1.0f;                
    }    
    if (keys[VK_NEXT])
    {
          hips_ROTATE[3]   -= 1.0f;                
    } 
    if (keys[VK_NUMPAD0]) 
    {
          hips_ROTATE[3]    = 0.0f;           
    }         
            
//////_______________________________________   
    if (keys[VK_NUMPAD9]) 
	{
           if(hips_ROTATE[0] <= 1.0f)           
              hips_ROTATE[0] += 0.01f;//_____FORWARD            
    }
    if (keys[VK_NUMPAD8]) 
    {
           if(hips_ROTATE[0] >= 0.0f)          
              hips_ROTATE[0] -= 0.01f;//_____REVERSE             
    }
    if (keys[VK_NUMPAD7]) 
    {
          hips_ROTATE[0] = 0.000001f;//______RESET 
    } 
//////_______________________________________    
    if (keys[VK_NUMPAD6]) 
	{
         if(hips_ROTATE[1] <= 1.0f)          
            hips_ROTATE[1] += 0.01f;//_______FORWARD            
    }
    if (keys[VK_NUMPAD5]) 
    {
         if(hips_ROTATE[1] >= 0.0f)
            hips_ROTATE[1] -= 0.01f;//_______REVERSE             

    }     
    if (keys[VK_NUMPAD4]) 
    {
            hips_ROTATE[1] = 0.000001f;//____RESET           
    }    
//////_______________________________________    
    if (keys[VK_NUMPAD3]) 
	{
          if(hips_ROTATE[2] <= 1.0f)           
             hips_ROTATE[2] += 0.01f;//______FORWARD            
    }
    if (keys[VK_NUMPAD2]) 
    {
          if(hips_ROTATE[2] >= 0.0f)          
             hips_ROTATE[2] -= 0.01f;//______REVERSE             
    } 
    if (keys[VK_NUMPAD1]) 
    {
             hips_ROTATE[2] = 0.000001f;//___RESET          
    }    
}
//////____________________________________________________________________________________________________________________________ 
if(BODY_PART_SELECTION == 6)////___TORSO
{  

    if (keys[VK_PRIOR])
    {
          torso_ROTATE[3]   += 1.0f;                
    }    
    if (keys[VK_NEXT])
    {
          torso_ROTATE[3]   -= 1.0f;                
    } 
    if (keys[VK_NUMPAD0]) 
    {
          torso_ROTATE[3]    = 0.0f;           
    }         
            
//////_______________________________________    
    if (keys[VK_NUMPAD9]) 
	{
          if(torso_ROTATE[0] <= 1.0f)           
             torso_ROTATE[0] += 0.01f;//____FORWARD            
    }
    if (keys[VK_NUMPAD8]) 
    {
          if(torso_ROTATE[0] >= 0.0f)          
             torso_ROTATE[0] -= 0.01f;//____REVERSE            
    }
    if (keys[VK_NUMPAD7]) 
    {
          torso_ROTATE[0] = 0.000001f;//____RESET  
    } 
//////_______________________________________      
    if (keys[VK_NUMPAD6]) 
	{
         if(torso_ROTATE[1] <= 1.0f)          
            torso_ROTATE[1] += 0.01f;//_____FORWARD            
    }
    if (keys[VK_NUMPAD5]) 
    {
         if(torso_ROTATE[1] >= 0.0f)
            torso_ROTATE[1] -= 0.01f;//_____REVERSE            
    }     

    if (keys[VK_NUMPAD4]) 
    {
           torso_ROTATE[1] = 0.000001f;//___RESET            
    }    
//////_______________________________________     
    if (keys[VK_NUMPAD3]) 
	{
        if(torso_ROTATE[2] <= 1.0f)           
           torso_ROTATE[2] += 0.01f;//______FORWARD            
    }
    if (keys[VK_NUMPAD2]) 
    {
        if(torso_ROTATE[2] >= 0.0f)          
           torso_ROTATE[2] -= 0.01f;//______REVERSE            
    } 
    if (keys[VK_NUMPAD1]) 
    {
           torso_ROTATE[2] = 0.000001f;//___RESET           
    }    
}

//////____________________________________________________________________________________________________________________________ 

if(BODY_PART_SELECTION == 7)////___HEAD
{


    if (keys[VK_PRIOR])
    {
          head_ROTATE[3]   += 1.0f;                
    }    
    if (keys[VK_NEXT])
    {
          head_ROTATE[3]   -= 1.0f;                
    } 
    if (keys[VK_NUMPAD0]) 
    {
          head_ROTATE[3]    = 0.0f;           
    }         
            
//////_______________________________________    
    if (keys[VK_NUMPAD9]) 
	{
         if(head_ROTATE[0] <= 1.0f)           
            head_ROTATE[0] += 0.01f;//_____FORWARD            
    }
    if (keys[VK_NUMPAD8]) 
    {
         if(head_ROTATE[0] >= -0.0f)          
            head_ROTATE[0] -= 0.01f;//_____REVERSE            
    }
    if (keys[VK_NUMPAD7]) 
    {
            head_ROTATE[0] = 0.000001f;//__RESET 
    } 
//////_______________________________________     
    if (keys[VK_NUMPAD6]) 
	{
         if(head_ROTATE[1] <= 1.0f)          
            head_ROTATE[1] += 0.01f;//_____FORWARD            
    }
    if (keys[VK_NUMPAD5]) 
    {
        if(head_ROTATE[1] >= -0.0f)
           head_ROTATE[1] -= 0.01f;//______REVERSE            

    }     
    if (keys[VK_NUMPAD4]) 
    {
           head_ROTATE[1] = 0.000001f;//___RESET            
    }    
//////_______________________________________      
    if (keys[VK_NUMPAD3]) 
	{
        if(head_ROTATE[2] <= 1.0f)           
           head_ROTATE[2] += 0.01f;//______FORWARD             
    }
    if (keys[VK_NUMPAD2]) 
    {
       if(head_ROTATE[2] >= -0.0f)          
          head_ROTATE[2] -= 0.01f;//_______REVERSE            
    } 
    if (keys[VK_NUMPAD1]) 
    {
          head_ROTATE[2] = 0.000001f;//____RESET           
    }    
}
////////////////////////////////////////////______HIPS__TORSO__HEAD______^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
////////////////////////////////////////////______HIPS__TORSO__HEAD______^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
////////////////////////////////////////////______HIPS__TORSO__HEAD______^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
////////////////////////////////////////////______HIPS__TORSO__HEAD______^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
////////////////////////////////////////////______HIPS__TORSO__HEAD______^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
