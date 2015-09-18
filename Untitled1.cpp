 
    if(writeAnimationFile)
    {//______________________________________________________________________________________________________BEGIN_WRITE_ANIMATION
          writeAnimationFile                   = false; 
          
          ofstream out("_MODEL_FOLDERS_/marcParts/marcAnimations/animationFiles/ME_AnimationSet.cpp");    

          //-------------------------------------------------------------------------------------------------          
          out << "hips_POSITION_setSelectionLimit  = " << hips_POSITION_setSelectionLimit <<  ";\n";    
          out << "hips_POSITION_SelectionCount     = " << hips_POSITION_SelectionCount    << ";\n\n\n";           
          //-------------------------------------------------------------------------------------------------         
          out << "setSelectionLimit_HEAD              = " << setSelectionLimit_HEAD             <<  ";\n";    
          out << "SelectionCount_HEAD                 = " << SelectionCount_HEAD                << ";\n\n\n";           
          //-------------------------------------------------------------------------------------------------          
          out << "setSelectionLimit_TORSO             = " << setSelectionLimit_TORSO            <<  ";\n";    
          out << "SelectionCount_TORSO                = " << SelectionCount_TORSO               << ";\n\n\n"; 
          //-------------------------------------------------------------------------------------------------          
          out << "setSelectionLimit_HIPS              = " << setSelectionLimit_HIPS             <<  ";\n";    
          out << "SelectionCount_HIPS                 = " << SelectionCount_HIPS                << ";\n\n\n";                              
          //-------------------------------------------------------------------------------------------------         
          out << "setSelectionLimit_LEFT_ARM          = " << setSelectionLimit_LEFT_ARM         <<  ";\n";    
          out << "SelectionCount_LEFT_ARM             = " << SelectionCount_LEFT_ARM            << ";\n\n\n";                 
          //-------------------------------------------------------------------------------------------------
          out << "setSelectionLimit_RIGHT_ARM         = " << setSelectionLimit_RIGHT_ARM        <<  ";\n";    
          out << "SelectionCount_RIGHT_ARM            = " << SelectionCount_RIGHT_ARM           << ";\n\n\n";
          //-------------------------------------------------------------------------------------------------   
          out << "setSelectionLimit_LEFT_LEG          = " << setSelectionLimit_LEFT_LEG         <<  ";\n";    
          out << "SelectionCount_LEFT_LEG             = " << SelectionCount_LEFT_LEG            << ";\n\n\n";                 
          //-------------------------------------------------------------------------------------------------
          out << "setSelectionLimit_RIGHT_LEG         = " << setSelectionLimit_RIGHT_LEG        <<  ";\n";    
          out << "SelectionCount_RIGHT_LEG            = " << SelectionCount_RIGHT_LEG           << ";\n\n\n";                    
          //-------------------------------------------------------------------------------------------------  
//################################################################################################################################################  
//################################################################################################################################################  



          
          //////////////////////____MAIN__POSITION___////////////////////////////////////////////////////////////////////   
          out << "if(hips_POSITION_setSelection == 1)" <<  "\n{\n";
          
          out << "    hips_POSITION_MOVE_FRAMEA[0]     = "  <<   hips_POSITION_SET_01[0]  <<  ";\n";
          out << "    hips_POSITION_MOVE_FRAMEA[1]     = "  <<   hips_POSITION_SET_01[1]  <<  ";\n";                   
          out << "    hips_POSITION_MOVE_FRAMEA[2]     = "  <<   hips_POSITION_SET_01[2]  <<  ";\n";
                      
          out << "    hips_POSITION_MOVE_FRAMEB[0]     = "  <<   hips_POSITION_SET_02[0]  <<  ";\n";
          out << "    hips_POSITION_MOVE_FRAMEB[1]     = "  <<   hips_POSITION_SET_02[1]  <<  ";\n";                    
          out << "    hips_POSITION_MOVE_FRAMEB[2]     = "  <<   hips_POSITION_SET_02[2]  <<  ";\n}\n";           
          
          
          //////////////////////____MAIN__POSITION___////////////////////////////////////////////////////////////////////           
         
          //////////////////////////________LEFT___ARM____///////////////////////////////////////////////////////          
          out << "if(setSelection_LEFT_ARM == 1)" <<  "\n{";

                 out << "    leftUpperArm_ROTATE_FRAMEA[3]   = "  <<  leftUpperArm_SET_01[3]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[0]   = "  <<  leftUpperArm_SET_01[0]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[1]   = "  <<  leftUpperArm_SET_01[1]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[2]   = "  <<  leftUpperArm_SET_01[2]     <<  ";\n";
                 
                 out << "    leftUpperArm_ROTATE_FRAMEB[3]   = "  <<  leftUpperArm_SET_02[3]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEB[0]   = "  <<  leftUpperArm_SET_02[0]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEB[1]   = "  <<  leftUpperArm_SET_02[1]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEB[2]   = "  <<  leftUpperArm_SET_02[2]     <<  ";\n";
                 ///_<subPart>_////                 
                 out << "    leftForeArm_ROTATE_FRAMEA[3]   = "  <<  leftForeArm_SET_01[3]     <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEA[0]   = "  <<  leftForeArm_SET_01[0]     <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEA[1]   = "  <<  leftForeArm_SET_01[1]     <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEA[2]   = "  <<  leftForeArm_SET_01[2]     <<  ";\n";
                 
                 out << "    leftForeArm_ROTATE_FRAMEB[3]   = "  <<  leftForeArm_SET_02[3]     <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEB[0]   = "  <<  leftForeArm_SET_02[0]     <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEB[1]   = "  <<  leftForeArm_SET_02[1]     <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEB[2]   = "  <<  leftForeArm_SET_02[2]     <<  ";\n";                           
                 ///_<subPart>_////          
                 out << "    leftGlovedHand_ROTATE_FRAMEA[3]   = "  <<  leftGlovedHand_SET_01[3]     <<  ";\n";
                 out << "    leftGlovedHand_ROTATE_FRAMEA[0]   = "  <<  leftGlovedHand_SET_01[0]     <<  ";\n";
                 out << "    leftGlovedHand_ROTATE_FRAMEA[1]   = "  <<  leftGlovedHand_SET_01[1]     <<  ";\n";
                 out << "    leftGlovedHand_ROTATE_FRAMEA[2]   = "  <<  leftGlovedHand_SET_01[2]     <<  ";\n";
                 
                 out << "    leftGlovedHand_ROTATE_FRAMEB[3]   = "  <<  leftGlovedHand_SET_02[3]     <<  ";\n";
                 out << "    leftGlovedHand_ROTATE_FRAMEB[0]   = "  <<  leftGlovedHand_SET_02[0]     <<  ";\n";
                 out << "    leftGlovedHand_ROTATE_FRAMEB[1]   = "  <<  leftGlovedHand_SET_02[1]     <<  ";\n";
                 out << "    leftGlovedHand_ROTATE_FRAMEB[2]   = "  <<  leftGlovedHand_SET_02[2]     <<  ";\n}\n";           
          //////////////////////////________LEFT___ARM____///////////////////////////////////////////////////////      
          
          
          //////////////////////////________RIGHT____ARM____///////////////////////////////////////////////////////           
          out << "if(setSelection_RIGHT_ARM == 1)" <<  "\n{";
                 out << "    rightUpperArm_ROTATE_FRAMEA[3]   = "  <<  rightUpperArm_SET_01[3]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[0]   = "  <<  rightUpperArm_SET_01[0]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[1]   = "  <<  rightUpperArm_SET_01[1]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[2]   = "  <<  rightUpperArm_SET_01[2]     <<  ";\n";
                 
                 out << "    rightUpperArm_ROTATE_FRAMEB[3]   = "  <<  rightUpperArm_SET_02[3]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEB[0]   = "  <<  rightUpperArm_SET_02[0]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEB[1]   = "  <<  rightUpperArm_SET_02[1]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEB[2]   = "  <<  rightUpperArm_SET_02[2]     <<  ";\n";
                 ///_<subPart>_////                 
                 out << "    rightForeArm_ROTATE_FRAMEA[3]   = "  <<  rightForeArm_SET_01[3]     <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEA[0]   = "  <<  rightForeArm_SET_01[0]     <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEA[1]   = "  <<  rightForeArm_SET_01[1]     <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEA[2]   = "  <<  rightForeArm_SET_01[2]     <<  ";\n";
                 
                 out << "    rightForeArm_ROTATE_FRAMEB[3]   = "  <<  rightForeArm_SET_02[3]     <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEB[0]   = "  <<  rightForeArm_SET_02[0]     <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEB[1]   = "  <<  rightForeArm_SET_02[1]     <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEB[2]   = "  <<  rightForeArm_SET_02[2]     <<  ";\n";                           
                 ///_<subPart>_////          
                 out << "    rightGlovedHand_ROTATE_FRAMEA[3]   = "  <<  rightGlovedHand_SET_01[3]     <<  ";\n";
                 out << "    rightGlovedHand_ROTATE_FRAMEA[0]   = "  <<  rightGlovedHand_SET_01[0]     <<  ";\n";
                 out << "    rightGlovedHand_ROTATE_FRAMEA[1]   = "  <<  rightGlovedHand_SET_01[1]     <<  ";\n";
                 out << "    rightGlovedHand_ROTATE_FRAMEA[2]   = "  <<  rightGlovedHand_SET_01[2]     <<  ";\n";
                 
                 out << "    rightGlovedHand_ROTATE_FRAMEB[3]   = "  <<  rightGlovedHand_SET_02[3]     <<  ";\n";
                 out << "    rightGlovedHand_ROTATE_FRAMEB[0]   = "  <<  rightGlovedHand_SET_02[0]     <<  ";\n";
                 out << "    rightGlovedHand_ROTATE_FRAMEB[1]   = "  <<  rightGlovedHand_SET_02[1]     <<  ";\n";
                 out << "    rightGlovedHand_ROTATE_FRAMEB[2]   = "  <<  rightGlovedHand_SET_02[2]     <<  ";\n}\n";           
           //////////////////////////________RIGHT___ARM____//////////////////////////////////////////////////////// 
           
         
           //////////////////////////________LEFT___ARM____///////////////////////////////////////////////////////          
           out << "if(setSelection_LEFT_LEG == 1)" <<  "\n{";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[3]   = "  <<  leftUpperLeg_SET_01[3]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[0]   = "  <<  leftUpperLeg_SET_01[0]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[1]   = "  <<  leftUpperLeg_SET_01[1]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[2]   = "  <<  leftUpperLeg_SET_01[2]     <<  ";\n";
                 
                 out << "    leftUpperLeg_ROTATE_FRAMEB[3]   = "  <<  leftUpperLeg_SET_02[3]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[0]   = "  <<  leftUpperLeg_SET_02[0]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[1]   = "  <<  leftUpperLeg_SET_02[1]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[2]   = "  <<  leftUpperLeg_SET_02[2]     <<  ";\n";
                 
                 out << "    leftLowerLeg_ROTATE_FRAMEA[3]   = "  <<  leftLowerLeg_SET_01[3]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEA[0]   = "  <<  leftLowerLeg_SET_01[0]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEA[1]   = "  <<  leftLowerLeg_SET_01[1]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEA[2]   = "  <<  leftLowerLeg_SET_01[2]     <<  ";\n";
                 
                 out << "    leftLowerLeg_ROTATE_FRAMEB[3]   = "  <<  leftLowerLeg_SET_02[3]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[0]   = "  <<  leftLowerLeg_SET_02[0]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[1]   = "  <<  leftLowerLeg_SET_02[1]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[2]   = "  <<  leftLowerLeg_SET_02[2]     <<  ";\n";                           
          
                 out << "    leftFoot_ROTATE_FRAMEA[3]       = "  <<  leftFoot_SET_01[3]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEA[0]       = "  <<  leftFoot_SET_01[0]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEA[1]       = "  <<  leftFoot_SET_01[1]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEA[2]       = "  <<  leftFoot_SET_01[2]     <<  ";\n";
                 
                 out << "    leftFoot_ROTATE_FRAMEB[3]       = "  <<  leftFoot_SET_02[3]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[0]       = "  <<  leftFoot_SET_02[0]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[1]       = "  <<  leftFoot_SET_02[1]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[2]       = "  <<  leftFoot_SET_02[2]     <<  ";\n}\n";            
          //////////////////////////________LEFT___ARM____///////////////////////////////////////////////////////      
          
          
          //////////////////////////________RIGHT____ARM____///////////////////////////////////////////////////////           
          out << "if(setSelection_RIGHT_LEG == 1)" <<  "\n{";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[3]   = "  <<  rightUpperLeg_SET_01[3]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[0]   = "  <<  rightUpperLeg_SET_01[0]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[1]   = "  <<  rightUpperLeg_SET_01[1]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[2]   = "  <<  rightUpperLeg_SET_01[2]     <<  ";\n";
                 
                 out << "    rightUpperLeg_ROTATE_FRAMEB[3]   = "  <<  rightUpperLeg_SET_02[3]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[0]   = "  <<  rightUpperLeg_SET_02[0]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[1]   = "  <<  rightUpperLeg_SET_02[1]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[2]   = "  <<  rightUpperLeg_SET_02[2]     <<  ";\n";
                
                 out << "    rightLowerLeg_ROTATE_FRAMEA[3]   = "  <<  rightLowerLeg_SET_01[3]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEA[0]   = "  <<  rightLowerLeg_SET_01[0]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEA[1]   = "  <<  rightLowerLeg_SET_01[1]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEA[2]   = "  <<  rightLowerLeg_SET_01[2]     <<  ";\n";
                 
                 out << "    rightLowerLeg_ROTATE_FRAMEB[3]   = "  <<  rightLowerLeg_SET_02[3]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[0]   = "  <<  rightLowerLeg_SET_02[0]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[1]   = "  <<  rightLowerLeg_SET_02[1]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[2]   = "  <<  rightLowerLeg_SET_02[2]     <<  ";\n";                           
        
                 out << "    rightFoot_ROTATE_FRAMEA[3]   = "  <<  rightFoot_SET_01[3]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEA[0]   = "  <<  rightFoot_SET_01[0]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEA[1]   = "  <<  rightFoot_SET_01[1]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEA[2]   = "  <<  rightFoot_SET_01[2]     <<  ";\n";
                 
                 out << "    rightFoot_ROTATE_FRAMEB[3]   = "  <<  rightFoot_SET_02[3]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[0]   = "  <<  rightFoot_SET_02[0]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[1]   = "  <<  rightFoot_SET_02[1]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[2]   = "  <<  rightFoot_SET_02[2]     <<  ";\n}\n";           
           //////////////////////////________RIGHT___ARM____////////////////////////////////////////////////////////            
        
          
           //////////////////////____HEAD__POSITION___////////////////////////////////////////////////////////////////////   
           out << "if(setSelection_HEAD == 1)" <<  "\n{\n";
          
                 out << "    head_ROTATE_FRAMEA[3]   = "  <<  head_SET_01[3]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEA[0]   = "  <<  head_SET_01[0]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEA[1]   = "  <<  head_SET_01[1]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEA[2]   = "  <<  head_SET_01[2]     <<  ";\n";          

                 out << "    head_ROTATE_FRAMEB[3]   = "  <<  head_SET_02[3]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[0]   = "  <<  head_SET_02[0]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[1]   = "  <<  head_SET_02[1]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[2]   = "  <<  head_SET_02[2]     <<  ";\n}\n";              
          //////////////////////____HEAD__POSITION___////////////////////////////////////////////////////////////////////           
           
         
          //////////////////////____TORSO__POSITION___////////////////////////////////////////////////////////////////////   
          out << "if(setSelection_TORSO == 1)" <<  "\n{\n";
                 out << "    torso_ROTATE_FRAMEA[3]   = "  <<  torso_SET_01[3]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEA[0]   = "  <<  torso_SET_01[0]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEA[1]   = "  <<  torso_SET_01[1]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEA[2]   = "  <<  torso_SET_01[2]     <<  ";\n";          

                 out << "    torso_ROTATE_FRAMEB[3]   = "  <<  torso_SET_02[3]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[0]   = "  <<  torso_SET_02[0]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[1]   = "  <<  torso_SET_02[1]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[2]   = "  <<  torso_SET_02[2]     <<  ";\n}\n";             
          //////////////////////____TORSO__POSITION___////////////////////////////////////////////////////////////////////           
          
          //////////////////////____HIPS__POSITION___////////////////////////////////////////////////////////////////////   
          out << "if(setSelection_HIPS == 1)" <<  "\n{\n";
                 out << "    hips_ROTATE_FRAMEA[3]   = "  <<  hips_SET_01[3]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEA[0]   = "  <<  hips_SET_01[0]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEA[1]   = "  <<  hips_SET_01[1]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEA[2]   = "  <<  hips_SET_01[2]     <<  ";\n";          
          
                 out << "    hips_ROTATE_FRAMEB[3]   = "  <<  hips_SET_02[3]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[0]   = "  <<  hips_SET_02[0]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[1]   = "  <<  hips_SET_02[1]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[2]   = "  <<  hips_SET_02[2]     <<  ";\n}\n";             
          //////////////////////____HIPS__POSITION___//////////////////////////////////////////////////////////////////// 
                 
//################################################################################################################################################  
//################################################################################################################################################           

         

          
          //////////////////////____MAIN__POSITION___////////////////////////////////////////////////////////////////////      
          out << "if(hips_POSITION_setSelection == 2)" <<  "\n{\n";
              out << "    hips_POSITION_MOVE_FRAMEA[0]         = "  <<  hips_POSITION_SET_02[0]         <<  ";\n";
              out << "    hips_POSITION_MOVE_FRAMEA[1]         = "  <<  hips_POSITION_SET_02[1]         <<  ";\n";                 
              out << "    hips_POSITION_MOVE_FRAMEA[2]         = "  <<  hips_POSITION_SET_02[2]         <<  ";\n\n";
        
              out << "    hips_POSITION_MOVE_FRAMEB[0]         = "  <<   hips_POSITION_SET_03[0]  <<  ";\n";
              out << "    hips_POSITION_MOVE_FRAMEB[1]         = "  <<   hips_POSITION_SET_03[1]  <<  ";\n";                      
              out << "    hips_POSITION_MOVE_FRAMEB[2]         = "  <<   hips_POSITION_SET_03[2]  <<  ";\n}\n\n";          
          //////////////////////____MAIN__POSITION___//////////////////////////////////////////////////////////////// 
                        
                           
          //////////////////////____LEFT___ARM___////////////////////////////////////////////////////////////////////          
          out << "if(setSelection_LEFT_ARM == 2)" <<  "\n{\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[3]     = "  <<  leftUpperArm_SET_02[3]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[0]     = "  <<  leftUpperArm_SET_02[0]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[1]     = "  <<  leftUpperArm_SET_02[1]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[2]     = "  <<  leftUpperArm_SET_02[2]     <<  ";\n";
                
                 out << "    leftForeArm_ROTATE_FRAMEA[3]      = "  <<  leftForeArm_SET_02[3]      <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEA[0]      = "  <<  leftForeArm_SET_02[0]      <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEA[1]      = "  <<  leftForeArm_SET_02[1]      <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEA[2]      = "  <<  leftForeArm_SET_02[2]      <<  ";\n";                 
          
                 out << "    leftGlovedHand_ROTATE_FRAMEA[3]   = "  <<  leftGlovedHand_SET_02[3]     <<  ";\n";
                 out << "    leftGlovedHand_ROTATE_FRAMEA[0]   = "  <<  leftGlovedHand_SET_02[0]     <<  ";\n";
                 out << "    leftGlovedHand_ROTATE_FRAMEA[1]   = "  <<  leftGlovedHand_SET_02[1]     <<  ";\n";
                 out << "    leftGlovedHand_ROTATE_FRAMEA[2]   = "  <<  leftGlovedHand_SET_02[2]     <<  ";\n";          
          
         
                out << "    leftUpperArm_ROTATE_FRAMEB[3]      = "  <<  leftUpperArm_SET_03[3]     <<  ";\n";
                out << "    leftUpperArm_ROTATE_FRAMEB[0]      = "  <<  leftUpperArm_SET_03[0]     <<  ";\n";
                out << "    leftUpperArm_ROTATE_FRAMEB[1]      = "  <<  leftUpperArm_SET_03[1]     <<  ";\n";
                out << "    leftUpperArm_ROTATE_FRAMEB[2]      = "  <<  leftUpperArm_SET_03[2]     <<  ";\n";          
               
                out << "    leftForeArm_ROTATE_FRAMEB[3]       = "  <<  leftForeArm_SET_03[3]     <<  ";\n";
                out << "    leftForeArm_ROTATE_FRAMEB[0]       = "  <<  leftForeArm_SET_03[0]     <<  ";\n";
                out << "    leftForeArm_ROTATE_FRAMEB[1]       = "  <<  leftForeArm_SET_03[1]     <<  ";\n";
                out << "    leftForeArm_ROTATE_FRAMEB[2]       = "  <<  leftForeArm_SET_03[2]     <<  ";\n";                          
                         
                out << "    leftGlovedHand_ROTATE_FRAMEB[3]    = "  <<  leftGlovedHand_SET_03[3]     <<  ";\n";
                out << "    leftGlovedHand_ROTATE_FRAMEB[0]    = "  <<  leftGlovedHand_SET_03[0]     <<  ";\n";
                out << "    leftGlovedHand_ROTATE_FRAMEB[1]    = "  <<  leftGlovedHand_SET_03[1]     <<  ";\n";
                out << "    leftGlovedHand_ROTATE_FRAMEB[2]    = "  <<  leftGlovedHand_SET_03[2]     <<  ";\n}\n\n";         
          //////////////////////____LEFT___ARM___////////////////////////////////////////////////////////////////////           
          
          //////////////////////____RIGHT___ARM___////////////////////////////////////////////////////////////////////          
          out << "if(setSelection_RIGHT_ARM == 2)" <<  "\n{\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[3]   = "  <<  rightUpperArm_SET_02[3]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[0]   = "  <<  rightUpperArm_SET_02[0]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[1]   = "  <<  rightUpperArm_SET_02[1]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[2]   = "  <<  rightUpperArm_SET_02[2]     <<  ";\n";
                
                 out << "    rightForeArm_ROTATE_FRAMEA[3]    = "  <<  rightForeArm_SET_02[3]      <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEA[0]    = "  <<  rightForeArm_SET_02[0]      <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEA[1]    = "  <<  rightForeArm_SET_02[1]      <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEA[2]    = "  <<  rightForeArm_SET_02[2]      <<  ";\n";                 
          
                 out << "    rightGlovedHand_ROTATE_FRAMEA[3]   = "  <<  rightGlovedHand_SET_02[3]     <<  ";\n";
                 out << "    rightGlovedHand_ROTATE_FRAMEA[0]   = "  <<  rightGlovedHand_SET_02[0]     <<  ";\n";
                 out << "    rightGlovedHand_ROTATE_FRAMEA[1]   = "  <<  rightGlovedHand_SET_02[1]     <<  ";\n";
                 out << "    rightGlovedHand_ROTATE_FRAMEA[2]   = "  <<  rightGlovedHand_SET_02[2]     <<  ";\n";          
          
       
                out << "    rightUpperArm_ROTATE_FRAMEB[3]   = "  <<  rightUpperArm_SET_03[3]     <<  ";\n";
                out << "    rightUpperArm_ROTATE_FRAMEB[0]   = "  <<  rightUpperArm_SET_03[0]     <<  ";\n";
                out << "    rightUpperArm_ROTATE_FRAMEB[1]   = "  <<  rightUpperArm_SET_03[1]     <<  ";\n";
                out << "    rightUpperArm_ROTATE_FRAMEB[2]   = "  <<  rightUpperArm_SET_03[2]     <<  ";\n";          
               
                out << "    rightForeArm_ROTATE_FRAMEB[3]   = "  <<  rightForeArm_SET_03[3]     <<  ";\n";
                out << "    rightForeArm_ROTATE_FRAMEB[0]   = "  <<  rightForeArm_SET_03[0]     <<  ";\n";
                out << "    rightForeArm_ROTATE_FRAMEB[1]   = "  <<  rightForeArm_SET_03[1]     <<  ";\n";
                out << "    rightForeArm_ROTATE_FRAMEB[2]   = "  <<  rightForeArm_SET_03[2]     <<  ";\n";                          
                         
                out << "    rightGlovedHand_ROTATE_FRAMEB[3]   = "  <<  rightGlovedHand_SET_03[3]     <<  ";\n";
                out << "    rightGlovedHand_ROTATE_FRAMEB[0]   = "  <<  rightGlovedHand_SET_03[0]     <<  ";\n";
                out << "    rightGlovedHand_ROTATE_FRAMEB[1]   = "  <<  rightGlovedHand_SET_03[1]     <<  ";\n";
                out << "    rightGlovedHand_ROTATE_FRAMEB[2]   = "  <<  rightGlovedHand_SET_03[2]     <<  ";\n}\n\n";         
          //////////////////////____RIGHT___ARM___////////////////////////////////////////////////////////////////////           
                      
          //////////////////////____LEFT___LEG___////////////////////////////////////////////////////////////////////          
          out << "if(setSelection_LEFT_LEG == 2)" <<  "\n{\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[3]   = "  <<  leftUpperLeg_SET_02[3]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[0]   = "  <<  leftUpperLeg_SET_02[0]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[1]   = "  <<  leftUpperLeg_SET_02[1]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[2]   = "  <<  leftUpperLeg_SET_02[2]     <<  ";\n";
         
                 out << "    leftLowerLeg_ROTATE_FRAMEA[3]   = "  <<  leftLowerLeg_SET_02[3]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEA[0]   = "  <<  leftLowerLeg_SET_02[0]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEA[1]   = "  <<  leftLowerLeg_SET_02[1]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEA[2]   = "  <<  leftLowerLeg_SET_02[2]     <<  ";\n";                 
             
                 out << "    leftFoot_ROTATE_FRAMEA[3]   = "  <<  leftFoot_SET_02[3]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEA[0]   = "  <<  leftFoot_SET_02[0]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEA[1]   = "  <<  leftFoot_SET_02[1]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEA[2]   = "  <<  leftFoot_SET_02[2]     <<  ";\n";          
          
       
        
                 out << "    leftUpperLeg_ROTATE_FRAMEB[3]   = "  <<  leftUpperLeg_SET_03[3]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[0]   = "  <<  leftUpperLeg_SET_03[0]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[1]   = "  <<  leftUpperLeg_SET_03[1]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[2]   = "  <<  leftUpperLeg_SET_03[2]     <<  ";\n";          
                                                 
                 out << "    leftLowerLeg_ROTATE_FRAMEB[3]   = "  <<  leftLowerLeg_SET_03[3]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[0]   = "  <<  leftLowerLeg_SET_03[0]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[1]   = "  <<  leftLowerLeg_SET_03[1]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[2]   = "  <<  leftLowerLeg_SET_03[2]     <<  ";\n";                          
                             
                 out << "    leftFoot_ROTATE_FRAMEB[3]   = "  <<  leftFoot_SET_03[3]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[0]   = "  <<  leftFoot_SET_03[0]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[1]   = "  <<  leftFoot_SET_03[1]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[2]   = "  <<  leftFoot_SET_03[2]     <<  ";\n}\n\n";              
          //////////////////////____LEFT___LEG___////////////////////////////////////////////////////////////////////           
          
          //////////////////////____RIGHT___LEG__////////////////////////////////////////////////////////////////////          
          out << "if(setSelection_RIGHT_LEG == 2)" <<  "\n{\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[3]   = "  <<  rightUpperLeg_SET_02[3]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[0]   = "  <<  rightUpperLeg_SET_02[0]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[1]   = "  <<  rightUpperLeg_SET_02[1]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[2]   = "  <<  rightUpperLeg_SET_02[2]     <<  ";\n";
                            
                 out << "    rightLowerLeg_ROTATE_FRAMEA[3]   = "  <<  rightLowerLeg_SET_02[3]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEA[0]   = "  <<  rightLowerLeg_SET_02[0]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEA[1]   = "  <<  rightLowerLeg_SET_02[1]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEA[2]   = "  <<  rightLowerLeg_SET_02[2]     <<  ";\n";                 
           
                 out << "    rightFoot_ROTATE_FRAMEA[3]   = "  <<  rightFoot_SET_02[3]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEA[0]   = "  <<  rightFoot_SET_02[0]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEA[1]   = "  <<  rightFoot_SET_02[1]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEA[2]   = "  <<  rightFoot_SET_02[2]     <<  ";\n";        
          
       
                 out << "    rightUpperLeg_ROTATE_FRAMEB[3]   = "  <<  rightUpperLeg_SET_03[3]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[0]   = "  <<  rightUpperLeg_SET_03[0]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[1]   = "  <<  rightUpperLeg_SET_03[1]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[2]   = "  <<  rightUpperLeg_SET_03[2]     <<  ";\n";          
                                              
                 out << "    rightLowerLeg_ROTATE_FRAMEB[3]   = "  <<  rightLowerLeg_SET_03[3]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[0]   = "  <<  rightLowerLeg_SET_03[0]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[1]   = "  <<  rightLowerLeg_SET_03[1]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[2]   = "  <<  rightLowerLeg_SET_03[2]     <<  ";\n";                          
                            
                 out << "    rightFoot_ROTATE_FRAMEB[3]   = "  <<  rightFoot_SET_03[3]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[0]   = "  <<  rightFoot_SET_03[0]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[1]   = "  <<  rightFoot_SET_03[1]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[2]   = "  <<  rightFoot_SET_03[2]     <<  ";\n}\n\n";              
          //////////////////////____RIGHT___ARM___////////////////////////////////////////////////////////////////////           
         
          //////////////////////____HEAD__POSITION___////////////////////////////////////////////////////////////////////      
          out << "if(setSelection_HEAD == 2)" <<  "\n{\n";
                 out << "    head_ROTATE_FRAMEA[3]   = "  <<  head_SET_02[3]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEA[0]   = "  <<  head_SET_02[0]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEA[1]   = "  <<  head_SET_02[1]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEA[2]   = "  <<  head_SET_02[2]     <<  ";\n"; 
          
          
                 out << "    head_ROTATE_FRAMEB[3]   = "  <<  head_SET_03[3]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[0]   = "  <<  head_SET_03[0]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[1]   = "  <<  head_SET_03[1]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[2]   = "  <<  head_SET_03[2]     <<  ";\n}\n\n";        
          //////////////////////____HEAD__POSITION___////////////////////////////////////////////////////////////////          

          //////////////////////____TORSO__POSITION___////////////////////////////////////////////////////////////////////      
          out << "if(setSelection_TORSO == 2)" <<  "\n{\n";
                 out << "    torso_ROTATE_FRAMEA[3]   = "  <<  torso_SET_02[3]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEA[0]   = "  <<  torso_SET_02[0]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEA[1]   = "  <<  torso_SET_02[1]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEA[2]   = "  <<  torso_SET_02[2]     <<  ";\n"; 
          
          
                 out << "    torso_ROTATE_FRAMEB[3]   = "  <<  torso_SET_03[3]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[0]   = "  <<  torso_SET_03[0]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[1]   = "  <<  torso_SET_03[1]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[2]   = "  <<  torso_SET_03[2]     <<  ";\n}\n\n";        
          //////////////////////____TORSO__POSITION___////////////////////////////////////////////////////////////////          
        
          //////////////////////____HIPS__POSITION___////////////////////////////////////////////////////////////////////      
          out << "if(setSelection_HIPS == 2)" <<  "\n{\n";
                 out << "    hips_ROTATE_FRAMEA[3]   = "  <<  hips_SET_02[3]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEA[0]   = "  <<  hips_SET_02[0]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEA[1]   = "  <<  hips_SET_02[1]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEA[2]   = "  <<  hips_SET_02[2]     <<  ";\n"; 
          
       
                 out << "    hips_ROTATE_FRAMEB[3]   = "  <<  hips_SET_03[3]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[0]   = "  <<  hips_SET_03[0]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[1]   = "  <<  hips_SET_03[1]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[2]   = "  <<  hips_SET_03[2]     <<  ";\n}\n\n";    
          //////////////////////____HIPS__POSITION___//////////////////////////////////////////////////////////////// 
                   
//################################################################################################################################################
          
       
      //////////////////////____MAIN__POSITION___////////////////////////////////////////////////////////////////////           
          
          out << "if(hips_POSITION_setSelection == 3)" <<  "\n{\n";
                 out << "    hips_POSITION_MOVE_FRAMEA[0]      = "  <<  hips_POSITION_SET_03[0]  <<  ";\n";
                 out << "    hips_POSITION_MOVE_FRAMEA[1]      = "  <<  hips_POSITION_SET_03[1]  <<  ";\n";                     
                 out << "    hips_POSITION_MOVE_FRAMEA[2]      = "  <<  hips_POSITION_SET_03[2]  <<  ";\n\n";          

                 out << "    hips_POSITION_MOVE_FRAMEB[0]      = "  <<  hips_POSITION_SET_04[0]  <<  ";\n";
                 out << "    hips_POSITION_MOVE_FRAMEB[1]      = "  <<  hips_POSITION_SET_04[1]  <<  ";\n";                      
                 out << "    hips_POSITION_MOVE_FRAMEB[2]      = "  <<  hips_POSITION_SET_04[2]  <<  ";\n}\n\n";           
          //////////////////////____MAIN__POSITION___////////////////////////////////////////////////////////////////////          
         
          //////////////////////____LEFT___ARM___////////////////////////////////////////////////////////////////////          
          out << "if(setSelection_LEFT_ARM == 3)" <<  "\n{\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[3]   = "  <<  leftUpperArm_SET_03[3]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[0]   = "  <<  leftUpperArm_SET_03[0]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[1]   = "  <<  leftUpperArm_SET_03[1]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[2]   = "  <<  leftUpperArm_SET_03[2]     <<  ";\n";
                          
                 out << "    leftForeArm_ROTATE_FRAMEA[3]    = "  <<  leftForeArm_SET_03[3]      <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEA[0]    = "  <<  leftForeArm_SET_03[0]      <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEA[1]    = "  <<  leftForeArm_SET_03[1]      <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEA[2]    = "  <<  leftForeArm_SET_03[2]      <<  ";\n";          
                   
                 out << "    leftGlovedHand_ROTATE_FRAMEA[3] = "  <<  leftGlovedHand_SET_03[3]   <<  ";\n";
                 out << "    leftGlovedHand_ROTATE_FRAMEA[0] = "  <<  leftGlovedHand_SET_03[0]   <<  ";\n";
                 out << "    leftGlovedHand_ROTATE_FRAMEA[1] = "  <<  leftGlovedHand_SET_03[1]   <<  ";\n";
                 out << "    leftGlovedHand_ROTATE_FRAMEA[2] = "  <<  leftGlovedHand_SET_03[2]   <<  ";\n\n";         

                 out << "    leftUpperArm_ROTATE_FRAMEB[3]   = "  <<  leftUpperArm_SET_04[3]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEB[0]   = "  <<  leftUpperArm_SET_04[0]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEB[1]   = "  <<  leftUpperArm_SET_04[1]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEB[2]   = "  <<  leftUpperArm_SET_04[2]     <<  ";\n";          
           
                 out << "    leftForeArm_ROTATE_FRAMEB[3]   = "  <<  leftForeArm_SET_04[3]     <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEB[0]   = "  <<  leftForeArm_SET_04[0]     <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEB[1]   = "  <<  leftForeArm_SET_04[1]     <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEB[2]   = "  <<  leftForeArm_SET_04[2]     <<  ";\n";          
            
                 out << "    leftGlovedHand_ROTATE_FRAMEB[3]   = "  <<  leftGlovedHand_SET_04[3]     <<  ";\n";
                 out << "    leftGlovedHand_ROTATE_FRAMEB[0]   = "  <<  leftGlovedHand_SET_04[0]     <<  ";\n";
                 out << "    leftGlovedHand_ROTATE_FRAMEB[1]   = "  <<  leftGlovedHand_SET_04[1]     <<  ";\n";
                 out << "    leftGlovedHand_ROTATE_FRAMEB[2]   = "  <<  leftGlovedHand_SET_04[2]     <<  ";\n}\n\n";
          //////////////////////____LEFT___ARM___////////////////////////////////////////////////////////////////////          
          
          //////////////////////____RIGHT___ARM___////////////////////////////////////////////////////////////////////          
          out << "if(setSelection_RIGHT_ARM == 3)" <<  "\n{\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[3]   = "  <<  rightUpperArm_SET_03[3]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[0]   = "  <<  rightUpperArm_SET_03[0]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[1]   = "  <<  rightUpperArm_SET_03[1]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[2]   = "  <<  rightUpperArm_SET_03[2]     <<  ";\n";
                          
                 out << "    rightForeArm_ROTATE_FRAMEA[3]    = "  <<  rightForeArm_SET_03[3]      <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEA[0]    = "  <<  rightForeArm_SET_03[0]      <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEA[1]    = "  <<  rightForeArm_SET_03[1]      <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEA[2]    = "  <<  rightForeArm_SET_03[2]      <<  ";\n";          
                   
                 out << "    rightGlovedHand_ROTATE_FRAMEA[3] = "  <<  rightGlovedHand_SET_03[3]   <<  ";\n";
                 out << "    rightGlovedHand_ROTATE_FRAMEA[0] = "  <<  rightGlovedHand_SET_03[0]   <<  ";\n";
                 out << "    rightGlovedHand_ROTATE_FRAMEA[1] = "  <<  rightGlovedHand_SET_03[1]   <<  ";\n";
                 out << "    rightGlovedHand_ROTATE_FRAMEA[2] = "  <<  rightGlovedHand_SET_03[2]   <<  ";\n\n";         

                 out << "    rightUpperArm_ROTATE_FRAMEB[3]   = "  <<  rightUpperArm_SET_04[3]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEB[0]   = "  <<  rightUpperArm_SET_04[0]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEB[1]   = "  <<  rightUpperArm_SET_04[1]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEB[2]   = "  <<  rightUpperArm_SET_04[2]     <<  ";\n";          
           
                 out << "    rightForeArm_ROTATE_FRAMEB[3]   = "  <<  rightForeArm_SET_04[3]     <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEB[0]   = "  <<  rightForeArm_SET_04[0]     <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEB[1]   = "  <<  rightForeArm_SET_04[1]     <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEB[2]   = "  <<  rightForeArm_SET_04[2]     <<  ";\n";          
            
                 out << "    rightGlovedHand_ROTATE_FRAMEB[3]   = "  <<  rightGlovedHand_SET_04[3]     <<  ";\n";
                 out << "    rightGlovedHand_ROTATE_FRAMEB[0]   = "  <<  rightGlovedHand_SET_04[0]     <<  ";\n";
                 out << "    rightGlovedHand_ROTATE_FRAMEB[1]   = "  <<  rightGlovedHand_SET_04[1]     <<  ";\n";
                 out << "    rightGlovedHand_ROTATE_FRAMEB[2]   = "  <<  rightGlovedHand_SET_04[2]     <<  ";\n}\n\n";
          //////////////////////____RIGHT___ARM___////////////////////////////////////////////////////////////////////          

          //////////////////////____LEFT___LEG___////////////////////////////////////////////////////////////////////          
          out << "if(setSelection_LEFT_LEG == 3)" <<  "\n{\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[3]   = "  <<  leftUpperLeg_SET_03[3]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[0]   = "  <<  leftUpperLeg_SET_03[0]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[1]   = "  <<  leftUpperLeg_SET_03[1]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[2]   = "  <<  leftUpperLeg_SET_03[2]     <<  ";\n";
                  
                 out << "    leftLowerLeg_ROTATE_FRAMEA[3]   = "  <<  leftLowerLeg_SET_03[3]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEA[0]   = "  <<  leftLowerLeg_SET_03[0]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEA[1]   = "  <<  leftLowerLeg_SET_03[1]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEA[2]   = "  <<  leftLowerLeg_SET_03[2]     <<  ";\n";          
           
                 out << "    leftFoot_ROTATE_FRAMEA[3]   = "  <<  leftFoot_SET_03[3]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEA[0]   = "  <<  leftFoot_SET_03[0]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEA[1]   = "  <<  leftFoot_SET_03[1]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEA[2]   = "  <<  leftFoot_SET_03[2]     <<  ";\n";         

                 out << "    leftUpperLeg_ROTATE_FRAMEB[3]   = "  <<  leftUpperLeg_SET_04[3]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[0]   = "  <<  leftUpperLeg_SET_04[0]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[1]   = "  <<  leftUpperLeg_SET_04[1]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[2]   = "  <<  leftUpperLeg_SET_04[2]     <<  ";\n";          
            
                 out << "    leftLowerLeg_ROTATE_FRAMEB[3]   = "  <<  leftLowerLeg_SET_04[3]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[0]   = "  <<  leftLowerLeg_SET_04[0]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[1]   = "  <<  leftLowerLeg_SET_04[1]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[2]   = "  <<  leftLowerLeg_SET_04[2]     <<  ";\n";          
           
                 out << "    leftFoot_ROTATE_FRAMEB[3]   = "  <<  leftFoot_SET_04[3]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[0]   = "  <<  leftFoot_SET_04[0]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[1]   = "  <<  leftFoot_SET_04[1]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[2]   = "  <<  leftFoot_SET_04[2]     <<  ";\n}\n\n";
          //////////////////////____LEFT___LEG___////////////////////////////////////////////////////////////////////          
          
          //////////////////////____RIGHT___LEG___////////////////////////////////////////////////////////////////////          
          out << "if(setSelection_RIGHT_LEG == 3)" <<  "\n{\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[3]   = "  <<  rightUpperLeg_SET_03[3]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[0]   = "  <<  rightUpperLeg_SET_03[0]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[1]   = "  <<  rightUpperLeg_SET_03[1]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[2]   = "  <<  rightUpperLeg_SET_03[2]     <<  ";\n";
                 
                 out << "    rightLowerLeg_ROTATE_FRAMEA[3]   = "  <<  rightLowerLeg_SET_03[3]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEA[0]   = "  <<  rightLowerLeg_SET_03[0]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEA[1]   = "  <<  rightLowerLeg_SET_03[1]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEA[2]   = "  <<  rightLowerLeg_SET_03[2]     <<  ";\n";          
           
                 out << "    rightFoot_ROTATE_FRAMEA[3]   = "  <<  rightFoot_SET_03[3]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEA[0]   = "  <<  rightFoot_SET_03[0]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEA[1]   = "  <<  rightFoot_SET_03[1]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEA[2]   = "  <<  rightFoot_SET_03[2]     <<  ";\n";          

                 out << "    rightUpperLeg_ROTATE_FRAMEB[3]   = "  <<  rightUpperLeg_SET_04[3]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[0]   = "  <<  rightUpperLeg_SET_04[0]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[1]   = "  <<  rightUpperLeg_SET_04[1]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[2]   = "  <<  rightUpperLeg_SET_04[2]     <<  ";\n";          
         
                 out << "    rightLowerLeg_ROTATE_FRAMEB[3]   = "  <<  rightLowerLeg_SET_04[3]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[0]   = "  <<  rightLowerLeg_SET_04[0]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[1]   = "  <<  rightLowerLeg_SET_04[1]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[2]   = "  <<  rightLowerLeg_SET_04[2]     <<  ";\n";          
            
                 out << "    rightFoot_ROTATE_FRAMEB[3]   = "  <<  rightFoot_SET_04[3]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[0]   = "  <<  rightFoot_SET_04[0]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[1]   = "  <<  rightFoot_SET_04[1]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[2]   = "  <<  rightFoot_SET_04[2]     <<  ";\n\n}\n";
          //////////////////////____RIGHT___LEG___////////////////////////////////////////////////////////////////////  
      
          //////////////////////____HEAD__POSITION___////////////////////////////////////////////////////////////////////           
          out << "if(setSelection_HEAD == 3)" <<  "\n{\n";
                 out << "    head_ROTATE_FRAMEA[3]   = "  <<  head_SET_03[3]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEA[0]   = "  <<  head_SET_03[0]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEA[1]   = "  <<  head_SET_03[1]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEA[2]   = "  <<  head_SET_03[2]     <<  ";\n";         

                 out << "    head_ROTATE_FRAMEB[3]   = "  <<  head_SET_04[3]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[0]   = "  <<  head_SET_04[0]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[1]   = "  <<  head_SET_04[1]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[2]   = "  <<  head_SET_04[2]     <<  ";\n}\n\n";       
          //////////////////////____HEAD__POSITION___////////////////////////////////////////////////////////////////////          
           
           //////////////////////____TORSO__POSITION___////////////////////////////////////////////////////////////////////           
          out << "if(setSelection_TORSO == 3)" <<  "\n{\n";
                 out << "    torso_ROTATE_FRAMEA[3]   = "  <<  torso_SET_03[3]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEA[0]   = "  <<  torso_SET_03[0]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEA[1]   = "  <<  torso_SET_03[1]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEA[2]   = "  <<  torso_SET_03[2]     <<  ";\n";       

                 out << "    torso_ROTATE_FRAMEB[3]   = "  <<  torso_SET_04[3]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[0]   = "  <<  torso_SET_04[0]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[1]   = "  <<  torso_SET_04[1]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[2]   = "  <<  torso_SET_04[2]     <<  ";\n}\n\n";    
          //////////////////////____TORSO__POSITION___////////////////////////////////////////////////////////////////////          

          //////////////////////____HIPS__POSITION___////////////////////////////////////////////////////////////////////           
          out << "if(setSelection_HIPS == 3)" <<  "\n{\n";
                 out << "    hips_ROTATE_FRAMEA[3]   = "  <<  hips_SET_03[3]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEA[0]   = "  <<  hips_SET_03[0]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEA[1]   = "  <<  hips_SET_03[1]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEA[2]   = "  <<  hips_SET_03[2]     <<  ";\n";    

                 out << "    hips_ROTATE_FRAMEB[3]   = "  <<  hips_SET_04[3]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[0]   = "  <<  hips_SET_04[0]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[1]   = "  <<  hips_SET_04[1]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[2]   = "  <<  hips_SET_04[2]    <<  ";\n}\n\n";  
          //////////////////////____HIPS__POSITION___////////////////////////////////////////////////////////////////////  
          
//################################################################################################################################################           





          //////////////////////____MAIN__POSITION___////////////////////////////////////////////////////////////////////      
          out << "if(hips_POSITION_setSelection == 4)" <<  "\n{\n";
              out << "    hips_POSITION_MOVE_FRAMEA[0]         = "  <<  hips_POSITION_SET_04[0]         <<  ";\n";
              out << "    hips_POSITION_MOVE_FRAMEA[1]         = "  <<  hips_POSITION_SET_04[1]         <<  ";\n";                 
              out << "    hips_POSITION_MOVE_FRAMEA[2]         = "  <<  hips_POSITION_SET_04[2]         <<  ";\n\n";
        
              out << "    hips_POSITION_MOVE_FRAMEB[0]         = "  <<   hips_POSITION_SET_05[0]  <<  ";\n";
              out << "    hips_POSITION_MOVE_FRAMEB[1]         = "  <<   hips_POSITION_SET_05[1]  <<  ";\n";                      
              out << "    hips_POSITION_MOVE_FRAMEB[2]         = "  <<   hips_POSITION_SET_05[2]  <<  ";\n}\n\n";          
          //////////////////////____MAIN__POSITION___//////////////////////////////////////////////////////////////// 
                        
          //////////////////////____LEFT___ARM___////////////////////////////////////////////////////////////////////          
          out << "if(setSelection_LEFT_ARM == 4)" <<  "\n{\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[3]     = "  <<  leftUpperArm_SET_04[3]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[0]     = "  <<  leftUpperArm_SET_04[0]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[1]     = "  <<  leftUpperArm_SET_04[1]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[2]     = "  <<  leftUpperArm_SET_04[2]     <<  ";\n";
                
                 out << "    leftForeArm_ROTATE_FRAMEA[3]      = "  <<  leftForeArm_SET_04[3]      <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEA[0]      = "  <<  leftForeArm_SET_04[0]      <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEA[1]      = "  <<  leftForeArm_SET_04[1]      <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEA[2]      = "  <<  leftForeArm_SET_04[2]      <<  ";\n";                 
          
                 out << "    leftGlovedHand_ROTATE_FRAMEA[3]   = "  <<  leftGlovedHand_SET_04[3]     <<  ";\n";
                 out << "    leftGlovedHand_ROTATE_FRAMEA[0]   = "  <<  leftGlovedHand_SET_04[0]     <<  ";\n";
                 out << "    leftGlovedHand_ROTATE_FRAMEA[1]   = "  <<  leftGlovedHand_SET_04[1]     <<  ";\n";
                 out << "    leftGlovedHand_ROTATE_FRAMEA[2]   = "  <<  leftGlovedHand_SET_04[2]     <<  ";\n";          
          
        
                out << "    leftUpperArm_ROTATE_FRAMEB[3]      = "  <<  leftUpperArm_SET_05[3]     <<  ";\n";
                out << "    leftUpperArm_ROTATE_FRAMEB[0]      = "  <<  leftUpperArm_SET_05[0]     <<  ";\n";
                out << "    leftUpperArm_ROTATE_FRAMEB[1]      = "  <<  leftUpperArm_SET_05[1]     <<  ";\n";
                out << "    leftUpperArm_ROTATE_FRAMEB[2]      = "  <<  leftUpperArm_SET_05[2]     <<  ";\n";          
               
                out << "    leftForeArm_ROTATE_FRAMEB[3]       = "  <<  leftForeArm_SET_05[3]     <<  ";\n";
                out << "    leftForeArm_ROTATE_FRAMEB[0]       = "  <<  leftForeArm_SET_05[0]     <<  ";\n";
                out << "    leftForeArm_ROTATE_FRAMEB[1]       = "  <<  leftForeArm_SET_05[1]     <<  ";\n";
                out << "    leftForeArm_ROTATE_FRAMEB[2]       = "  <<  leftForeArm_SET_05[2]     <<  ";\n";                          
                         
                out << "    leftGlovedHand_ROTATE_FRAMEB[3]    = "  <<  leftGlovedHand_SET_05[3]     <<  ";\n";
                out << "    leftGlovedHand_ROTATE_FRAMEB[0]    = "  <<  leftGlovedHand_SET_05[0]     <<  ";\n";
                out << "    leftGlovedHand_ROTATE_FRAMEB[1]    = "  <<  leftGlovedHand_SET_05[1]     <<  ";\n";
                out << "    leftGlovedHand_ROTATE_FRAMEB[2]    = "  <<  leftGlovedHand_SET_05[2]     <<  ";\n}\n\n";         
          //////////////////////____LEFT___ARM___////////////////////////////////////////////////////////////////////           
          
          //////////////////////____RIGHT___ARM___////////////////////////////////////////////////////////////////////          
          out << "if(setSelection_RIGHT_ARM == 4)" <<  "\n{\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[3]   = "  <<  rightUpperArm_SET_04[3]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[0]   = "  <<  rightUpperArm_SET_04[0]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[1]   = "  <<  rightUpperArm_SET_04[1]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[2]   = "  <<  rightUpperArm_SET_04[2]     <<  ";\n";
                
                 out << "    rightForeArm_ROTATE_FRAMEA[3]    = "  <<  rightForeArm_SET_04[3]      <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEA[0]    = "  <<  rightForeArm_SET_04[0]      <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEA[1]    = "  <<  rightForeArm_SET_04[1]      <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEA[2]    = "  <<  rightForeArm_SET_04[2]      <<  ";\n";                 
          
                 out << "    rightGlovedHand_ROTATE_FRAMEA[3]   = "  <<  rightGlovedHand_SET_04[3]     <<  ";\n";
                 out << "    rightGlovedHand_ROTATE_FRAMEA[0]   = "  <<  rightGlovedHand_SET_04[0]     <<  ";\n";
                 out << "    rightGlovedHand_ROTATE_FRAMEA[1]   = "  <<  rightGlovedHand_SET_04[1]     <<  ";\n";
                 out << "    rightGlovedHand_ROTATE_FRAMEA[2]   = "  <<  rightGlovedHand_SET_04[2]     <<  ";\n";          
          
       
                out << "    rightUpperArm_ROTATE_FRAMEB[3]   = "  <<  rightUpperArm_SET_05[3]     <<  ";\n";
                out << "    rightUpperArm_ROTATE_FRAMEB[0]   = "  <<  rightUpperArm_SET_05[0]     <<  ";\n";
                out << "    rightUpperArm_ROTATE_FRAMEB[1]   = "  <<  rightUpperArm_SET_05[1]     <<  ";\n";
                out << "    rightUpperArm_ROTATE_FRAMEB[2]   = "  <<  rightUpperArm_SET_05[2]     <<  ";\n";          
               
                out << "    rightForeArm_ROTATE_FRAMEB[3]   = "  <<  rightForeArm_SET_05[3]     <<  ";\n";
                out << "    rightForeArm_ROTATE_FRAMEB[0]   = "  <<  rightForeArm_SET_05[0]     <<  ";\n";
                out << "    rightForeArm_ROTATE_FRAMEB[1]   = "  <<  rightForeArm_SET_05[1]     <<  ";\n";
                out << "    rightForeArm_ROTATE_FRAMEB[2]   = "  <<  rightForeArm_SET_05[2]     <<  ";\n";                          
                         
                out << "    rightGlovedHand_ROTATE_FRAMEB[3]   = "  <<  rightGlovedHand_SET_05[3]     <<  ";\n";
                out << "    rightGlovedHand_ROTATE_FRAMEB[0]   = "  <<  rightGlovedHand_SET_05[0]     <<  ";\n";
                out << "    rightGlovedHand_ROTATE_FRAMEB[1]   = "  <<  rightGlovedHand_SET_05[1]     <<  ";\n";
                out << "    rightGlovedHand_ROTATE_FRAMEB[2]   = "  <<  rightGlovedHand_SET_05[2]     <<  ";\n}\n\n";         
          //////////////////////____RIGHT___ARM___////////////////////////////////////////////////////////////////////           
                      
          //////////////////////____LEFT___LEG___////////////////////////////////////////////////////////////////////          
          out << "if(setSelection_LEFT_LEG == 4)" <<  "\n{\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[3]   = "  <<  leftUpperLeg_SET_04[3]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[0]   = "  <<  leftUpperLeg_SET_04[0]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[1]   = "  <<  leftUpperLeg_SET_04[1]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[2]   = "  <<  leftUpperLeg_SET_04[2]     <<  ";\n";
         
                 out << "    leftLowerLeg_ROTATE_FRAMEA[3]   = "  <<  leftLowerLeg_SET_04[3]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEA[0]   = "  <<  leftLowerLeg_SET_04[0]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEA[1]   = "  <<  leftLowerLeg_SET_04[1]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEA[2]   = "  <<  leftLowerLeg_SET_04[2]     <<  ";\n";                 
             
                 out << "    leftFoot_ROTATE_FRAMEA[3]   = "  <<  leftFoot_SET_04[3]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEA[0]   = "  <<  leftFoot_SET_04[0]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEA[1]   = "  <<  leftFoot_SET_04[1]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEA[2]   = "  <<  leftFoot_SET_04[2]     <<  ";\n";          
          
          
        
                 out << "    leftUpperLeg_ROTATE_FRAMEB[3]   = "  <<  leftUpperLeg_SET_05[3]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[0]   = "  <<  leftUpperLeg_SET_05[0]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[1]   = "  <<  leftUpperLeg_SET_05[1]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[2]   = "  <<  leftUpperLeg_SET_05[2]     <<  ";\n";          
                                                 
                 out << "    leftLowerLeg_ROTATE_FRAMEB[3]   = "  <<  leftLowerLeg_SET_05[3]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[0]   = "  <<  leftLowerLeg_SET_05[0]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[1]   = "  <<  leftLowerLeg_SET_05[1]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[2]   = "  <<  leftLowerLeg_SET_05[2]     <<  ";\n";                          
                             
                 out << "    leftFoot_ROTATE_FRAMEB[3]   = "  <<  leftFoot_SET_05[3]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[0]   = "  <<  leftFoot_SET_05[0]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[1]   = "  <<  leftFoot_SET_05[1]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[2]   = "  <<  leftFoot_SET_05[2]     <<  ";\n}\n\n";              
          //////////////////////____LEFT___LEG___////////////////////////////////////////////////////////////////////           
          
          //////////////////////____RIGHT___LEG__////////////////////////////////////////////////////////////////////          
          out << "if(setSelection_RIGHT_LEG == 4)" <<  "\n{\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[3]   = "  <<  rightUpperLeg_SET_04[3]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[0]   = "  <<  rightUpperLeg_SET_04[0]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[1]   = "  <<  rightUpperLeg_SET_04[1]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[2]   = "  <<  rightUpperLeg_SET_04[2]     <<  ";\n";
                            
                 out << "    rightLowerLeg_ROTATE_FRAMEA[3]   = "  <<  rightLowerLeg_SET_04[3]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEA[0]   = "  <<  rightLowerLeg_SET_04[0]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEA[1]   = "  <<  rightLowerLeg_SET_04[1]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEA[2]   = "  <<  rightLowerLeg_SET_04[2]     <<  ";\n";                 
           
                 out << "    rightFoot_ROTATE_FRAMEA[3]   = "  <<  rightFoot_SET_04[3]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEA[0]   = "  <<  rightFoot_SET_04[0]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEA[1]   = "  <<  rightFoot_SET_04[1]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEA[2]   = "  <<  rightFoot_SET_04[2]     <<  ";\n";        
          
          
                 out << "    rightUpperLeg_ROTATE_FRAMEB[3]   = "  <<  rightUpperLeg_SET_05[3]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[0]   = "  <<  rightUpperLeg_SET_05[0]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[1]   = "  <<  rightUpperLeg_SET_05[1]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[2]   = "  <<  rightUpperLeg_SET_05[2]     <<  ";\n";          
                                              
                 out << "    rightLowerLeg_ROTATE_FRAMEB[3]   = "  <<  rightLowerLeg_SET_05[3]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[0]   = "  <<  rightLowerLeg_SET_05[0]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[1]   = "  <<  rightLowerLeg_SET_05[1]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[2]   = "  <<  rightLowerLeg_SET_05[2]     <<  ";\n";                          
                            
                 out << "    rightFoot_ROTATE_FRAMEB[3]   = "  <<  rightFoot_SET_05[3]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[0]   = "  <<  rightFoot_SET_05[0]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[1]   = "  <<  rightFoot_SET_05[1]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[2]   = "  <<  rightFoot_SET_05[2]     <<  ";\n}\n\n";              
          //////////////////////____RIGHT___ARM___////////////////////////////////////////////////////////////////////           
         
          //////////////////////____HEAD__POSITION___////////////////////////////////////////////////////////////////////      
          out << "if(setSelection_HEAD == 4)" <<  "\n{\n";
                 out << "    head_ROTATE_FRAMEA[3]   = "  <<  head_SET_04[3]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEA[0]   = "  <<  head_SET_04[0]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEA[1]   = "  <<  head_SET_04[1]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEA[2]   = "  <<  head_SET_04[2]     <<  ";\n"; 
          
       
                 out << "    head_ROTATE_FRAMEB[3]   = "  <<  head_SET_05[3]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[0]   = "  <<  head_SET_05[0]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[1]   = "  <<  head_SET_05[1]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[2]   = "  <<  head_SET_05[2]     <<  ";\n}\n\n";        
          //////////////////////____HEAD__POSITION___////////////////////////////////////////////////////////////////          

        
          //////////////////////____TORSO__POSITION___////////////////////////////////////////////////////////////////////      
          out << "if(setSelection_TORSO == 4)" <<  "\n{\n";
                 out << "    torso_ROTATE_FRAMEA[3]   = "  <<  torso_SET_04[3]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEA[0]   = "  <<  torso_SET_04[0]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEA[1]   = "  <<  torso_SET_04[1]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEA[2]   = "  <<  torso_SET_04[2]     <<  ";\n"; 
          
        
                 out << "    torso_ROTATE_FRAMEB[3]   = "  <<  torso_SET_05[3]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[0]   = "  <<  torso_SET_05[0]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[1]   = "  <<  torso_SET_05[1]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[2]   = "  <<  torso_SET_05[2]     <<  ";\n}\n\n";        
          //////////////////////____TORSO__POSITION___////////////////////////////////////////////////////////////////          
        
          //////////////////////____HIPS__POSITION___////////////////////////////////////////////////////////////////////      
          out << "if(setSelection_HIPS == 4)" <<  "\n{\n";
                 out << "    hips_ROTATE_FRAMEA[3]   = "  <<  hips_SET_04[3]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEA[0]   = "  <<  hips_SET_04[0]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEA[1]   = "  <<  hips_SET_04[1]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEA[2]   = "  <<  hips_SET_04[2]     <<  ";\n"; 
          
         
                 out << "    hips_ROTATE_FRAMEB[3]   = "  <<  hips_SET_05[3]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[0]   = "  <<  hips_SET_05[0]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[1]   = "  <<  hips_SET_05[1]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[2]   = "  <<  hips_SET_05[2]     <<  ";\n}\n\n";    
          //////////////////////____HIPS__POSITION___//////////////////////////////////////////////////////////////// 
                   
//################################################################################################################################################
//################################################################################################################################################           

        
          
    
        
          //////////////////////____MAIN__POSITION___////////////////////////////////////////////////////////////////////      
          out << "if(hips_POSITION_setSelection == 5)" <<  "\n{\n";
              out << "    hips_POSITION_MOVE_FRAMEA[0]         = "  <<  hips_POSITION_SET_05[0]         <<  ";\n";
              out << "    hips_POSITION_MOVE_FRAMEA[1]         = "  <<  hips_POSITION_SET_05[1]         <<  ";\n";                 
              out << "    hips_POSITION_MOVE_FRAMEA[2]         = "  <<  hips_POSITION_SET_05[2]         <<  ";\n\n";
       
              out << "    hips_POSITION_MOVE_FRAMEB[0]         = "  <<   hips_POSITION_SET_06[0]  <<  ";\n";
              out << "    hips_POSITION_MOVE_FRAMEB[1]         = "  <<   hips_POSITION_SET_06[1]  <<  ";\n";                      
              out << "    hips_POSITION_MOVE_FRAMEB[2]         = "  <<   hips_POSITION_SET_06[2]  <<  ";\n}\n\n";          
          //////////////////////____MAIN__POSITION___//////////////////////////////////////////////////////////////// 
                        
                           
          //////////////////////____LEFT___ARM___////////////////////////////////////////////////////////////////////          
          out << "if(setSelection_LEFT_ARM == 5)" <<  "\n{\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[3]     = "  <<  leftUpperArm_SET_05[3]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[0]     = "  <<  leftUpperArm_SET_05[0]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[1]     = "  <<  leftUpperArm_SET_05[1]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[2]     = "  <<  leftUpperArm_SET_05[2]     <<  ";\n";
                
                 out << "    leftForeArm_ROTATE_FRAMEA[3]      = "  <<  leftForeArm_SET_05[3]      <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEA[0]      = "  <<  leftForeArm_SET_05[0]      <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEA[1]      = "  <<  leftForeArm_SET_05[1]      <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEA[2]      = "  <<  leftForeArm_SET_05[2]      <<  ";\n";                 
          
                 out << "    leftGlovedHand_ROTATE_FRAMEA[3]   = "  <<  leftGlovedHand_SET_05[3]     <<  ";\n";
                 out << "    leftGlovedHand_ROTATE_FRAMEA[0]   = "  <<  leftGlovedHand_SET_05[0]     <<  ";\n";
                 out << "    leftGlovedHand_ROTATE_FRAMEA[1]   = "  <<  leftGlovedHand_SET_05[1]     <<  ";\n";
                 out << "    leftGlovedHand_ROTATE_FRAMEA[2]   = "  <<  leftGlovedHand_SET_05[2]     <<  ";\n";          
          
          
                out << "    leftUpperArm_ROTATE_FRAMEB[3]      = "  <<  leftUpperArm_SET_06[3]     <<  ";\n";
                out << "    leftUpperArm_ROTATE_FRAMEB[0]      = "  <<  leftUpperArm_SET_06[0]     <<  ";\n";
                out << "    leftUpperArm_ROTATE_FRAMEB[1]      = "  <<  leftUpperArm_SET_06[1]     <<  ";\n";
                out << "    leftUpperArm_ROTATE_FRAMEB[2]      = "  <<  leftUpperArm_SET_06[2]     <<  ";\n";          
               
                out << "    leftForeArm_ROTATE_FRAMEB[3]       = "  <<  leftForeArm_SET_06[3]     <<  ";\n";
                out << "    leftForeArm_ROTATE_FRAMEB[0]       = "  <<  leftForeArm_SET_06[0]     <<  ";\n";
                out << "    leftForeArm_ROTATE_FRAMEB[1]       = "  <<  leftForeArm_SET_06[1]     <<  ";\n";
                out << "    leftForeArm_ROTATE_FRAMEB[2]       = "  <<  leftForeArm_SET_06[2]     <<  ";\n";                          
                         
                out << "    leftGlovedHand_ROTATE_FRAMEB[3]    = "  <<  leftGlovedHand_SET_06[3]     <<  ";\n";
                out << "    leftGlovedHand_ROTATE_FRAMEB[0]    = "  <<  leftGlovedHand_SET_06[0]     <<  ";\n";
                out << "    leftGlovedHand_ROTATE_FRAMEB[1]    = "  <<  leftGlovedHand_SET_06[1]     <<  ";\n";
                out << "    leftGlovedHand_ROTATE_FRAMEB[2]    = "  <<  leftGlovedHand_SET_06[2]     <<  ";\n}\n\n";         
          //////////////////////____LEFT___ARM___////////////////////////////////////////////////////////////////////           
          
          //////////////////////____RIGHT___ARM___////////////////////////////////////////////////////////////////////          
          out << "if(setSelection_RIGHT_ARM == 5)" <<  "\n{\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[3]   = "  <<  rightUpperArm_SET_05[3]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[0]   = "  <<  rightUpperArm_SET_05[0]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[1]   = "  <<  rightUpperArm_SET_05[1]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[2]   = "  <<  rightUpperArm_SET_05[2]     <<  ";\n";
                
                 out << "    rightForeArm_ROTATE_FRAMEA[3]    = "  <<  rightForeArm_SET_05[3]      <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEA[0]    = "  <<  rightForeArm_SET_05[0]      <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEA[1]    = "  <<  rightForeArm_SET_05[1]      <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEA[2]    = "  <<  rightForeArm_SET_05[2]      <<  ";\n";                 
          
                 out << "    rightGlovedHand_ROTATE_FRAMEA[3]   = "  <<  rightGlovedHand_SET_05[3]     <<  ";\n";
                 out << "    rightGlovedHand_ROTATE_FRAMEA[0]   = "  <<  rightGlovedHand_SET_05[0]     <<  ";\n";
                 out << "    rightGlovedHand_ROTATE_FRAMEA[1]   = "  <<  rightGlovedHand_SET_05[1]     <<  ";\n";
                 out << "    rightGlovedHand_ROTATE_FRAMEA[2]   = "  <<  rightGlovedHand_SET_05[2]     <<  ";\n";          
          
     
                out << "    rightUpperArm_ROTATE_FRAMEB[3]   = "  <<  rightUpperArm_SET_06[3]     <<  ";\n";
                out << "    rightUpperArm_ROTATE_FRAMEB[0]   = "  <<  rightUpperArm_SET_06[0]     <<  ";\n";
                out << "    rightUpperArm_ROTATE_FRAMEB[1]   = "  <<  rightUpperArm_SET_06[1]     <<  ";\n";
                out << "    rightUpperArm_ROTATE_FRAMEB[2]   = "  <<  rightUpperArm_SET_06[2]     <<  ";\n";          
               
                out << "    rightForeArm_ROTATE_FRAMEB[3]   = "  <<  rightForeArm_SET_06[3]     <<  ";\n";
                out << "    rightForeArm_ROTATE_FRAMEB[0]   = "  <<  rightForeArm_SET_06[0]     <<  ";\n";
                out << "    rightForeArm_ROTATE_FRAMEB[1]   = "  <<  rightForeArm_SET_06[1]     <<  ";\n";
                out << "    rightForeArm_ROTATE_FRAMEB[2]   = "  <<  rightForeArm_SET_06[2]     <<  ";\n";                          
                         
                out << "    rightGlovedHand_ROTATE_FRAMEB[3]   = "  <<  rightGlovedHand_SET_06[3]     <<  ";\n";
                out << "    rightGlovedHand_ROTATE_FRAMEB[0]   = "  <<  rightGlovedHand_SET_06[0]     <<  ";\n";
                out << "    rightGlovedHand_ROTATE_FRAMEB[1]   = "  <<  rightGlovedHand_SET_06[1]     <<  ";\n";
                out << "    rightGlovedHand_ROTATE_FRAMEB[2]   = "  <<  rightGlovedHand_SET_06[2]     <<  ";\n}\n\n";         
          //////////////////////____RIGHT___ARM___////////////////////////////////////////////////////////////////////           
                      
          //////////////////////____LEFT___LEG___////////////////////////////////////////////////////////////////////          
          out << "if(setSelection_LEFT_LEG == 5)" <<  "\n{\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[3]   = "  <<  leftUpperLeg_SET_05[3]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[0]   = "  <<  leftUpperLeg_SET_05[0]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[1]   = "  <<  leftUpperLeg_SET_05[1]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[2]   = "  <<  leftUpperLeg_SET_05[2]     <<  ";\n";
         
                 out << "    leftLowerLeg_ROTATE_FRAMEA[3]   = "  <<  leftLowerLeg_SET_05[3]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEA[0]   = "  <<  leftLowerLeg_SET_05[0]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEA[1]   = "  <<  leftLowerLeg_SET_05[1]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEA[2]   = "  <<  leftLowerLeg_SET_05[2]     <<  ";\n";                 
             
                 out << "    leftFoot_ROTATE_FRAMEA[3]   = "  <<  leftFoot_SET_05[3]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEA[0]   = "  <<  leftFoot_SET_05[0]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEA[1]   = "  <<  leftFoot_SET_05[1]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEA[2]   = "  <<  leftFoot_SET_05[2]     <<  ";\n";          
          
          
        
                 out << "    leftUpperLeg_ROTATE_FRAMEB[3]   = "  <<  leftUpperLeg_SET_06[3]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[0]   = "  <<  leftUpperLeg_SET_06[0]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[1]   = "  <<  leftUpperLeg_SET_06[1]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[2]   = "  <<  leftUpperLeg_SET_06[2]     <<  ";\n";          
                                                 
                 out << "    leftLowerLeg_ROTATE_FRAMEB[3]   = "  <<  leftLowerLeg_SET_06[3]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[0]   = "  <<  leftLowerLeg_SET_06[0]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[1]   = "  <<  leftLowerLeg_SET_06[1]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[2]   = "  <<  leftLowerLeg_SET_06[2]     <<  ";\n";                          
                             
                 out << "    leftFoot_ROTATE_FRAMEB[3]   = "  <<  leftFoot_SET_06[3]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[0]   = "  <<  leftFoot_SET_06[0]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[1]   = "  <<  leftFoot_SET_06[1]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[2]   = "  <<  leftFoot_SET_06[2]     <<  ";\n}\n\n";              
          //////////////////////____LEFT___LEG___////////////////////////////////////////////////////////////////////           
          
          //////////////////////____RIGHT___LEG__////////////////////////////////////////////////////////////////////          
          out << "if(setSelection_RIGHT_LEG == 5)" <<  "\n{\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[3]   = "  <<  rightUpperLeg_SET_05[3]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[0]   = "  <<  rightUpperLeg_SET_05[0]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[1]   = "  <<  rightUpperLeg_SET_05[1]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[2]   = "  <<  rightUpperLeg_SET_05[2]     <<  ";\n";
                            
                 out << "    rightLowerLeg_ROTATE_FRAMEA[3]   = "  <<  rightLowerLeg_SET_05[3]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEA[0]   = "  <<  rightLowerLeg_SET_05[0]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEA[1]   = "  <<  rightLowerLeg_SET_05[1]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEA[2]   = "  <<  rightLowerLeg_SET_05[2]     <<  ";\n";                 
           
                 out << "    rightFoot_ROTATE_FRAMEA[3]   = "  <<  rightFoot_SET_05[3]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEA[0]   = "  <<  rightFoot_SET_05[0]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEA[1]   = "  <<  rightFoot_SET_05[1]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEA[2]   = "  <<  rightFoot_SET_05[2]     <<  ";\n";        
      
                 out << "    rightUpperLeg_ROTATE_FRAMEB[3]   = "  <<  rightUpperLeg_SET_06[3]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[0]   = "  <<  rightUpperLeg_SET_06[0]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[1]   = "  <<  rightUpperLeg_SET_06[1]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[2]   = "  <<  rightUpperLeg_SET_06[2]     <<  ";\n";          
                                              
                 out << "    rightLowerLeg_ROTATE_FRAMEB[3]   = "  <<  rightLowerLeg_SET_06[3]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[0]   = "  <<  rightLowerLeg_SET_06[0]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[1]   = "  <<  rightLowerLeg_SET_06[1]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[2]   = "  <<  rightLowerLeg_SET_06[2]     <<  ";\n";                          
                            
                 out << "    rightFoot_ROTATE_FRAMEB[3]   = "  <<  rightFoot_SET_06[3]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[0]   = "  <<  rightFoot_SET_06[0]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[1]   = "  <<  rightFoot_SET_06[1]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[2]   = "  <<  rightFoot_SET_06[2]     <<  ";\n\n}\n";              
          //////////////////////____RIGHT___ARM___////////////////////////////////////////////////////////////////////           
         
          //////////////////////____HEAD__POSITION___////////////////////////////////////////////////////////////////////      
          out << "if(setSelection_HEAD == 5)" <<  "\n{\n";
                 out << "    head_ROTATE_FRAMEA[3]   = "  <<  head_SET_05[3]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEA[0]   = "  <<  head_SET_05[0]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEA[1]   = "  <<  head_SET_05[1]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEA[2]   = "  <<  head_SET_05[2]     <<  ";\n"; 
          
         
                 out << "    head_ROTATE_FRAMEB[3]   = "  <<  head_SET_06[3]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[0]   = "  <<  head_SET_06[0]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[1]   = "  <<  head_SET_06[1]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[2]   = "  <<  head_SET_06[2]     <<  ";\n}\n\n";        
          //////////////////////____HEAD__POSITION___////////////////////////////////////////////////////////////////          

        
          //////////////////////____TORSO__POSITION___////////////////////////////////////////////////////////////////////      
          out << "if(setSelection_TORSO == 5)" <<  "\n{\n";
                 out << "    torso_ROTATE_FRAMEA[3]   = "  <<  torso_SET_05[3]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEA[0]   = "  <<  torso_SET_05[0]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEA[1]   = "  <<  torso_SET_05[1]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEA[2]   = "  <<  torso_SET_05[2]     <<  ";\n"; 
          
           
                 out << "    torso_ROTATE_FRAMEB[3]   = "  <<  torso_SET_06[3]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[0]   = "  <<  torso_SET_06[0]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[1]   = "  <<  torso_SET_06[1]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[2]   = "  <<  torso_SET_06[2]     <<  ";\n}\n\n";        
          //////////////////////____TORSO__POSITION___////////////////////////////////////////////////////////////////          
        
          //////////////////////____HIPS__POSITION___////////////////////////////////////////////////////////////////////      
          out << "if(setSelection_HIPS == 5)" <<  "\n{\n";
                 out << "    hips_ROTATE_FRAMEA[3]   = "  <<  hips_SET_05[3]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEA[0]   = "  <<  hips_SET_05[0]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEA[1]   = "  <<  hips_SET_05[1]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEA[2]   = "  <<  hips_SET_05[2]     <<  ";\n"; 
          
       
                 out << "    hips_ROTATE_FRAMEB[3]   = "  <<  hips_SET_06[3]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[0]   = "  <<  hips_SET_06[0]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[1]   = "  <<  hips_SET_06[1]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[2]   = "  <<  hips_SET_06[2]     <<  ";\n}\n\n";    
          //////////////////////____HIPS__POSITION___//////////////////////////////////////////////////////////////// 
                   
//################################################################################################################################################  
//################################################################################################################################################  

//################################################################################################################################################
//################################################################################################################################################           

        
          
    
        
          //////////////////////____MAIN__POSITION___////////////////////////////////////////////////////////////////////      
          out << "if(hips_POSITION_setSelection == 6)" <<  "\n{\n";
              out << "    hips_POSITION_MOVE_FRAMEA[0]         = "  <<  hips_POSITION_SET_06[0]         <<  ";\n";
              out << "    hips_POSITION_MOVE_FRAMEA[1]         = "  <<  hips_POSITION_SET_06[1]         <<  ";\n";                 
              out << "    hips_POSITION_MOVE_FRAMEA[2]         = "  <<  hips_POSITION_SET_06[2]         <<  ";\n\n";
        
              out << "    hips_POSITION_MOVE_FRAMEB[0]         = "  <<   hips_POSITION_SET_07[0]  <<  ";\n";
              out << "    hips_POSITION_MOVE_FRAMEB[1]         = "  <<   hips_POSITION_SET_07[1]  <<  ";\n";                      
              out << "    hips_POSITION_MOVE_FRAMEB[2]         = "  <<   hips_POSITION_SET_07[2]  <<  ";\n}\n\n";          
          //////////////////////____MAIN__POSITION___//////////////////////////////////////////////////////////////// 
                        
                           
          //////////////////////____LEFT___ARM___////////////////////////////////////////////////////////////////////          
          out << "if(setSelection_LEFT_ARM == 6)" <<  "\n{\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[3]     = "  <<  leftUpperArm_SET_06[3]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[0]     = "  <<  leftUpperArm_SET_06[0]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[1]     = "  <<  leftUpperArm_SET_06[1]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[2]     = "  <<  leftUpperArm_SET_06[2]     <<  ";\n";
                
                 out << "    leftForeArm_ROTATE_FRAMEA[3]      = "  <<  leftForeArm_SET_06[3]      <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEA[0]      = "  <<  leftForeArm_SET_06[0]      <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEA[1]      = "  <<  leftForeArm_SET_06[1]      <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEA[2]      = "  <<  leftForeArm_SET_06[2]      <<  ";\n";                 
          
                 out << "    leftGlovedHand_ROTATE_FRAMEA[3]   = "  <<  leftGlovedHand_SET_06[3]     <<  ";\n";
                 out << "    leftGlovedHand_ROTATE_FRAMEA[0]   = "  <<  leftGlovedHand_SET_06[0]     <<  ";\n";
                 out << "    leftGlovedHand_ROTATE_FRAMEA[1]   = "  <<  leftGlovedHand_SET_06[1]     <<  ";\n";
                 out << "    leftGlovedHand_ROTATE_FRAMEA[2]   = "  <<  leftGlovedHand_SET_06[2]     <<  ";\n";          
          
          
                out << "    leftUpperArm_ROTATE_FRAMEB[3]      = "  <<  leftUpperArm_SET_07[3]     <<  ";\n";
                out << "    leftUpperArm_ROTATE_FRAMEB[0]      = "  <<  leftUpperArm_SET_07[0]     <<  ";\n";
                out << "    leftUpperArm_ROTATE_FRAMEB[1]      = "  <<  leftUpperArm_SET_07[1]     <<  ";\n";
                out << "    leftUpperArm_ROTATE_FRAMEB[2]      = "  <<  leftUpperArm_SET_07[2]     <<  ";\n";          
               
                out << "    leftForeArm_ROTATE_FRAMEB[3]       = "  <<  leftForeArm_SET_07[3]     <<  ";\n";
                out << "    leftForeArm_ROTATE_FRAMEB[0]       = "  <<  leftForeArm_SET_07[0]     <<  ";\n";
                out << "    leftForeArm_ROTATE_FRAMEB[1]       = "  <<  leftForeArm_SET_07[1]     <<  ";\n";
                out << "    leftForeArm_ROTATE_FRAMEB[2]       = "  <<  leftForeArm_SET_07[2]     <<  ";\n";                          
                         
                out << "    leftGlovedHand_ROTATE_FRAMEB[3]    = "  <<  leftGlovedHand_SET_07[3]     <<  ";\n";
                out << "    leftGlovedHand_ROTATE_FRAMEB[0]    = "  <<  leftGlovedHand_SET_07[0]     <<  ";\n";
                out << "    leftGlovedHand_ROTATE_FRAMEB[1]    = "  <<  leftGlovedHand_SET_07[1]     <<  ";\n";
                out << "    leftGlovedHand_ROTATE_FRAMEB[2]    = "  <<  leftGlovedHand_SET_07[2]     <<  ";\n}\n\n";         
          //////////////////////____LEFT___ARM___////////////////////////////////////////////////////////////////////           
          
          //////////////////////____RIGHT___ARM___////////////////////////////////////////////////////////////////////          
          out << "if(setSelection_RIGHT_ARM == 6)" <<  "\n{\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[3]   = "  <<  rightUpperArm_SET_06[3]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[0]   = "  <<  rightUpperArm_SET_06[0]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[1]   = "  <<  rightUpperArm_SET_06[1]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[2]   = "  <<  rightUpperArm_SET_06[2]     <<  ";\n";
                
                 out << "    rightForeArm_ROTATE_FRAMEA[3]    = "  <<  rightForeArm_SET_06[3]      <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEA[0]    = "  <<  rightForeArm_SET_06[0]      <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEA[1]    = "  <<  rightForeArm_SET_06[1]      <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEA[2]    = "  <<  rightForeArm_SET_06[2]      <<  ";\n";                 
          
                 out << "    rightGlovedHand_ROTATE_FRAMEA[3]   = "  <<  rightGlovedHand_SET_06[3]     <<  ";\n";
                 out << "    rightGlovedHand_ROTATE_FRAMEA[0]   = "  <<  rightGlovedHand_SET_06[0]     <<  ";\n";
                 out << "    rightGlovedHand_ROTATE_FRAMEA[1]   = "  <<  rightGlovedHand_SET_06[1]     <<  ";\n";
                 out << "    rightGlovedHand_ROTATE_FRAMEA[2]   = "  <<  rightGlovedHand_SET_06[2]     <<  ";\n";          
          
         
                out << "    rightUpperArm_ROTATE_FRAMEB[3]   = "  <<  rightUpperArm_SET_07[3]     <<  ";\n";
                out << "    rightUpperArm_ROTATE_FRAMEB[0]   = "  <<  rightUpperArm_SET_07[0]     <<  ";\n";
                out << "    rightUpperArm_ROTATE_FRAMEB[1]   = "  <<  rightUpperArm_SET_07[1]     <<  ";\n";
                out << "    rightUpperArm_ROTATE_FRAMEB[2]   = "  <<  rightUpperArm_SET_07[2]     <<  ";\n";          
               
                out << "    rightForeArm_ROTATE_FRAMEB[3]   = "  <<  rightForeArm_SET_07[3]     <<  ";\n";
                out << "    rightForeArm_ROTATE_FRAMEB[0]   = "  <<  rightForeArm_SET_07[0]     <<  ";\n";
                out << "    rightForeArm_ROTATE_FRAMEB[1]   = "  <<  rightForeArm_SET_07[1]     <<  ";\n";
                out << "    rightForeArm_ROTATE_FRAMEB[2]   = "  <<  rightForeArm_SET_07[2]     <<  ";\n";                          
                         
                out << "    rightGlovedHand_ROTATE_FRAMEB[3]   = "  <<  rightGlovedHand_SET_07[3]     <<  ";\n";
                out << "    rightGlovedHand_ROTATE_FRAMEB[0]   = "  <<  rightGlovedHand_SET_07[0]     <<  ";\n";
                out << "    rightGlovedHand_ROTATE_FRAMEB[1]   = "  <<  rightGlovedHand_SET_07[1]     <<  ";\n";
                out << "    rightGlovedHand_ROTATE_FRAMEB[2]   = "  <<  rightGlovedHand_SET_07[2]     <<  ";\n\n}\n";         
          //////////////////////____RIGHT___ARM___////////////////////////////////////////////////////////////////////           
                      
          //////////////////////____LEFT___LEG___////////////////////////////////////////////////////////////////////          
          out << "if(setSelection_LEFT_LEG == 6)" <<  "\n{\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[3]   = "  <<  leftUpperLeg_SET_06[3]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[0]   = "  <<  leftUpperLeg_SET_06[0]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[1]   = "  <<  leftUpperLeg_SET_06[1]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[2]   = "  <<  leftUpperLeg_SET_06[2]     <<  ";\n";
         
                 out << "    leftLowerLeg_ROTATE_FRAMEA[3]   = "  <<  leftLowerLeg_SET_06[3]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEA[0]   = "  <<  leftLowerLeg_SET_06[0]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEA[1]   = "  <<  leftLowerLeg_SET_06[1]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEA[2]   = "  <<  leftLowerLeg_SET_06[2]     <<  ";\n";                 
             
                 out << "    leftFoot_ROTATE_FRAMEA[3]   = "  <<  leftFoot_SET_06[3]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEA[0]   = "  <<  leftFoot_SET_06[0]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEA[1]   = "  <<  leftFoot_SET_06[1]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEA[2]   = "  <<  leftFoot_SET_06[2]     <<  ";\n";          
          
         
        
                 out << "    leftUpperLeg_ROTATE_FRAMEB[3]   = "  <<  leftUpperLeg_SET_07[3]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[0]   = "  <<  leftUpperLeg_SET_07[0]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[1]   = "  <<  leftUpperLeg_SET_07[1]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[2]   = "  <<  leftUpperLeg_SET_07[2]     <<  ";\n";          
                                                 
                 out << "    leftLowerLeg_ROTATE_FRAMEB[3]   = "  <<  leftLowerLeg_SET_07[3]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[0]   = "  <<  leftLowerLeg_SET_07[0]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[1]   = "  <<  leftLowerLeg_SET_07[1]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[2]   = "  <<  leftLowerLeg_SET_07[2]     <<  ";\n";                          
                             
                 out << "    leftFoot_ROTATE_FRAMEB[3]   = "  <<  leftFoot_SET_07[3]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[0]   = "  <<  leftFoot_SET_07[0]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[1]   = "  <<  leftFoot_SET_07[1]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[2]   = "  <<  leftFoot_SET_07[2]     <<  ";\n}\n\n";              
          //////////////////////____LEFT___LEG___////////////////////////////////////////////////////////////////////           
          
          //////////////////////____RIGHT___LEG__////////////////////////////////////////////////////////////////////          
          out << "if(setSelection_RIGHT_LEG == 6)" <<  "\n{\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[3]   = "  <<  rightUpperLeg_SET_06[3]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[0]   = "  <<  rightUpperLeg_SET_06[0]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[1]   = "  <<  rightUpperLeg_SET_06[1]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[2]   = "  <<  rightUpperLeg_SET_06[2]     <<  ";\n";
                            
                 out << "    rightLowerLeg_ROTATE_FRAMEA[3]   = "  <<  rightLowerLeg_SET_06[3]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEA[0]   = "  <<  rightLowerLeg_SET_06[0]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEA[1]   = "  <<  rightLowerLeg_SET_06[1]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEA[2]   = "  <<  rightLowerLeg_SET_06[2]     <<  ";\n";                 
           
                 out << "    rightFoot_ROTATE_FRAMEA[3]   = "  <<  rightFoot_SET_06[3]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEA[0]   = "  <<  rightFoot_SET_06[0]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEA[1]   = "  <<  rightFoot_SET_06[1]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEA[2]   = "  <<  rightFoot_SET_06[2]     <<  ";\n";        
          
       
                 out << "    rightUpperLeg_ROTATE_FRAMEB[3]   = "  <<  rightUpperLeg_SET_07[3]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[0]   = "  <<  rightUpperLeg_SET_07[0]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[1]   = "  <<  rightUpperLeg_SET_07[1]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[2]   = "  <<  rightUpperLeg_SET_07[2]     <<  ";\n";          
                                              
                 out << "    rightLowerLeg_ROTATE_FRAMEB[3]   = "  <<  rightLowerLeg_SET_07[3]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[0]   = "  <<  rightLowerLeg_SET_07[0]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[1]   = "  <<  rightLowerLeg_SET_07[1]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[2]   = "  <<  rightLowerLeg_SET_07[2]     <<  ";\n";                          
                            
                 out << "    rightFoot_ROTATE_FRAMEB[3]   = "  <<  rightFoot_SET_07[3]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[0]   = "  <<  rightFoot_SET_07[0]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[1]   = "  <<  rightFoot_SET_07[1]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[2]   = "  <<  rightFoot_SET_07[2]     <<  ";\n}\n\n";              
          //////////////////////____RIGHT___ARM___////////////////////////////////////////////////////////////////////           
         
          //////////////////////____HEAD__POSITION___////////////////////////////////////////////////////////////////////      
          out << "if(setSelection_HEAD == 6)" <<  "\n{\n";
                 out << "    head_ROTATE_FRAMEA[3]   = "  <<  head_SET_06[3]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEA[0]   = "  <<  head_SET_06[0]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEA[1]   = "  <<  head_SET_06[1]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEA[2]   = "  <<  head_SET_06[2]     <<  ";\n"; 
          
          
                 out << "    head_ROTATE_FRAMEB[3]   = "  <<  head_SET_07[3]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[0]   = "  <<  head_SET_07[0]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[1]   = "  <<  head_SET_07[1]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[2]   = "  <<  head_SET_07[2]     <<  ";\n}\n\n";        
          //////////////////////____HEAD__POSITION___////////////////////////////////////////////////////////////////          

        
          //////////////////////____TORSO__POSITION___////////////////////////////////////////////////////////////////////      
          out << "if(setSelection_TORSO == 6)" <<  "\n{\n";
                 out << "    torso_ROTATE_FRAMEA[3]   = "  <<  torso_SET_06[3]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEA[0]   = "  <<  torso_SET_06[0]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEA[1]   = "  <<  torso_SET_06[1]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEA[2]   = "  <<  torso_SET_06[2]     <<  ";\n"; 
          
        
                 out << "    torso_ROTATE_FRAMEB[3]   = "  <<  torso_SET_07[3]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[0]   = "  <<  torso_SET_07[0]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[1]   = "  <<  torso_SET_07[1]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[2]   = "  <<  torso_SET_07[2]     <<  ";\n}\n\n";        
          //////////////////////____TORSO__POSITION___////////////////////////////////////////////////////////////////          
        
          //////////////////////____HIPS__POSITION___////////////////////////////////////////////////////////////////////      
          out << "if(setSelection_HIPS == 6)" <<  "\n{\n";
                 out << "    hips_ROTATE_FRAMEA[3]   = "  <<  hips_SET_06[3]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEA[0]   = "  <<  hips_SET_06[0]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEA[1]   = "  <<  hips_SET_06[1]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEA[2]   = "  <<  hips_SET_06[2]     <<  ";\n"; 
          
        
                 out << "    hips_ROTATE_FRAMEB[3]   = "  <<  hips_SET_07[3]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[0]   = "  <<  hips_SET_07[0]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[1]   = "  <<  hips_SET_07[1]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[2]   = "  <<  hips_SET_07[2]     <<  ";\n}\n\n";    
          //////////////////////____HIPS__POSITION___//////////////////////////////////////////////////////////////// 
//################################################################################################################################################  
//################################################################################################################################################  

      
          //////////////////////____MAIN__POSITION___////////////////////////////////////////////////////////////////////   
          out << "if(hips_POSITION_setSelection == 7)" <<  "\n{\n";
          
          out << "    hips_POSITION_MOVE_FRAMEA[0]     = "  <<   hips_POSITION_SET_07[0]  <<  ";\n";
          out << "    hips_POSITION_MOVE_FRAMEA[1]     = "  <<   hips_POSITION_SET_07[1]  <<  ";\n";                   
          out << "    hips_POSITION_MOVE_FRAMEA[2]     = "  <<   hips_POSITION_SET_07[2]  <<  ";\n}";
          
          //////////////////////____MAIN__POSITION___////////////////////////////////////////////////////////////////////           
         
          //////////////////////////________LEFT___ARM____///////////////////////////////////////////////////////          
          out << "if(setSelection_LEFT_ARM == 7)" <<  "\n{";

                   
                 out << "    leftUpperArm_ROTATE_FRAMEA[3]   = "  <<  leftUpperArm_SET_07[3]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[0]   = "  <<  leftUpperArm_SET_07[0]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[1]   = "  <<  leftUpperArm_SET_07[1]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[2]   = "  <<  leftUpperArm_SET_07[2]     <<  ";\n";
                 

                 ///_<subPart>_////                 
                 out << "    leftForeArm_ROTATE_FRAMEA[3]   = "  <<  leftForeArm_SET_07[3]     <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEA[0]   = "  <<  leftForeArm_SET_07[0]     <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEA[1]   = "  <<  leftForeArm_SET_07[1]     <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEA[2]   = "  <<  leftForeArm_SET_07[2]     <<  ";\n";
                 
                       
                 ///_<subPart>_////          
                 out << "    leftGlovedHand_ROTATE_FRAMEA[3]   = "  <<  leftGlovedHand_SET_07[3]     <<  ";\n";
                 out << "    leftGlovedHand_ROTATE_FRAMEA[0]   = "  <<  leftGlovedHand_SET_07[0]     <<  ";\n";
                 out << "    leftGlovedHand_ROTATE_FRAMEA[1]   = "  <<  leftGlovedHand_SET_07[1]     <<  ";\n";
                 out << "    leftGlovedHand_ROTATE_FRAMEA[2]   = "  <<  leftGlovedHand_SET_07[2]     <<  ";\n}";
                 
          
          //////////////////////////________LEFT___ARM____///////////////////////////////////////////////////////      
          
          
          //////////////////////////________RIGHT____ARM____///////////////////////////////////////////////////////           
          out << "if(setSelection_RIGHT_ARM == 7)" <<  "\n{";
                 out << "    rightUpperArm_ROTATE_FRAMEA[3]   = "  <<  rightUpperArm_SET_07[3]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[0]   = "  <<  rightUpperArm_SET_07[0]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[1]   = "  <<  rightUpperArm_SET_07[1]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[2]   = "  <<  rightUpperArm_SET_07[2]     <<  ";\n";
                 

                 ///_<subPart>_////                 
                 out << "    rightForeArm_ROTATE_FRAMEA[3]   = "  <<  rightForeArm_SET_07[3]     <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEA[0]   = "  <<  rightForeArm_SET_07[0]     <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEA[1]   = "  <<  rightForeArm_SET_07[1]     <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEA[2]   = "  <<  rightForeArm_SET_07[2]     <<  ";\n";
                          
                 ///_<subPart>_////          
                 out << "    rightGlovedHand_ROTATE_FRAMEA[3]   = "  <<  rightGlovedHand_SET_07[3]     <<  ";\n";
                 out << "    rightGlovedHand_ROTATE_FRAMEA[0]   = "  <<  rightGlovedHand_SET_07[0]     <<  ";\n";
                 out << "    rightGlovedHand_ROTATE_FRAMEA[1]   = "  <<  rightGlovedHand_SET_07[1]     <<  ";\n";
                 out << "    rightGlovedHand_ROTATE_FRAMEA[2]   = "  <<  rightGlovedHand_SET_07[2]     <<  ";\n}";
                 
         
           //////////////////////////________RIGHT___ARM____//////////////////////////////////////////////////////// 
           
           //////////////////////////________LEFT___ARM____///////////////////////////////////////////////////////          
           out << "if(setSelection_LEFT_LEG == 7)" <<  "\n{";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[3]   = "  <<  leftUpperLeg_SET_07[3]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[0]   = "  <<  leftUpperLeg_SET_07[0]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[1]   = "  <<  leftUpperLeg_SET_07[1]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[2]   = "  <<  leftUpperLeg_SET_07[2]     <<  ";\n";
                 

                 
                 out << "    leftLowerLeg_ROTATE_FRAMEA[3]   = "  <<  leftLowerLeg_SET_07[3]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEA[0]   = "  <<  leftLowerLeg_SET_07[0]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEA[1]   = "  <<  leftLowerLeg_SET_07[1]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEA[2]   = "  <<  leftLowerLeg_SET_07[2]     <<  ";\n";
                 
                        
          
                 out << "    leftFoot_ROTATE_FRAMEA[3]       = "  <<  leftFoot_SET_07[3]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEA[0]       = "  <<  leftFoot_SET_07[0]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEA[1]       = "  <<  leftFoot_SET_07[1]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEA[2]       = "  <<  leftFoot_SET_07[2]     <<  ";\n}";
                 
            
          //////////////////////////________LEFT___ARM____///////////////////////////////////////////////////////      
          
          //////////////////////////________RIGHT____ARM____///////////////////////////////////////////////////////           
          out << "if(setSelection_RIGHT_LEG == 7)" <<  "\n{";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[3]   = "  <<  rightUpperLeg_SET_07[3]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[0]   = "  <<  rightUpperLeg_SET_07[0]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[1]   = "  <<  rightUpperLeg_SET_07[1]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[2]   = "  <<  rightUpperLeg_SET_07[2]     <<  ";\n";
                 

                
                 out << "    rightLowerLeg_ROTATE_FRAMEA[3]   = "  <<  rightLowerLeg_SET_07[3]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEA[0]   = "  <<  rightLowerLeg_SET_07[0]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEA[1]   = "  <<  rightLowerLeg_SET_07[1]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEA[2]   = "  <<  rightLowerLeg_SET_07[2]     <<  ";\n";
                 
                      
        
                 out << "    rightFoot_ROTATE_FRAMEA[3]   = "  <<  rightFoot_SET_07[3]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEA[0]   = "  <<  rightFoot_SET_07[0]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEA[1]   = "  <<  rightFoot_SET_07[1]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEA[2]   = "  <<  rightFoot_SET_07[2]     <<  ";\n}";
                 
           
           //////////////////////////________RIGHT___ARM____////////////////////////////////////////////////////////            
        
           //////////////////////____HEAD__POSITION___////////////////////////////////////////////////////////////////////   
           out << "if(setSelection_HEAD == 7)" <<  "\n{\n";
          
                 out << "    head_ROTATE_FRAMEA[3]   = "  <<  head_SET_07[3]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEA[0]   = "  <<  head_SET_07[0]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEA[1]   = "  <<  head_SET_07[1]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEA[2]   = "  <<  head_SET_07[2]     <<  ";\n}";          

           
           //////////////////////____HEAD__POSITION___////////////////////////////////////////////////////////////////////           
           
           //////////////////////____TORSO__POSITION___////////////////////////////////////////////////////////////////////   
           out << "if(setSelection_TORSO == 7)" <<  "\n{\n";
                 out << "    torso_ROTATE_FRAMEA[3]   = "  <<  torso_SET_07[3]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEA[0]   = "  <<  torso_SET_07[0]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEA[1]   = "  <<  torso_SET_07[1]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEA[2]   = "  <<  torso_SET_07[2]     <<  ";\n}";          
           
          //////////////////////____TORSO__POSITION___////////////////////////////////////////////////////////////////////           
          
          //////////////////////____HIPS__POSITION___////////////////////////////////////////////////////////////////////   
          out << "if(setSelection_HIPS == 7)" <<  "\n{\n";
                 out << "    hips_ROTATE_FRAMEA[3]   = "  <<  hips_SET_07[3]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEA[0]   = "  <<  hips_SET_07[0]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEA[1]   = "  <<  hips_SET_07[1]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEA[2]   = "  <<  hips_SET_07[2]     <<  ";\n}\n";          
           
          //////////////////////____HIPS__POSITION___//////////////////////////////////////////////////////////////////// 
      
    
    }////______________________________________________________________________________________________________BEGIN_WRITE_ANIMATION
