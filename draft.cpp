
//################################################################################################################################################
//################################################################################################################################################           

        
          
    
        
          //////////////////////____MAIN__POSITION___////////////////////////////////////////////////////////////////////      
          out << "if(moveSet_setSelection == 6)" <<  "\n{\n";
              out << "    moveSet_MOVE_FRAMEA[0]         = "  <<  moveSet_SET_06[0]         <<  ";\n";
              out << "    moveSet_MOVE_FRAMEA[1]         = "  <<  moveSet_SET_06[1]         <<  ";\n";                 
              out << "    moveSet_MOVE_FRAMEA[2]         = "  <<  moveSet_SET_06[2]         <<  ";\n\n";
          out << "   if(moveSet_SelectionCount == 6)" <<  "\n{\n";          
              out << "   moveSet_MOVE_FRAMEB[0]          = "  <<   moveSet_SET_01[0]  <<  ";\n";
              out << "   moveSet_MOVE_FRAMEB[1]          = "  <<   moveSet_SET_01[1]  <<  ";\n";                   
              out << "   moveSet_MOVE_FRAMEB[2]          = "  <<   moveSet_SET_01[2]  <<  ";\n}\n";
          out << "     else " <<  "\n    {\n";          
              out << "    moveSet_MOVE_FRAMEB[0]         = "  <<   moveSet_SET_07[0]  <<  ";\n";
              out << "    moveSet_MOVE_FRAMEB[1]         = "  <<   moveSet_SET_07[1]  <<  ";\n";                      
              out << "    moveSet_MOVE_FRAMEB[2]         = "  <<   moveSet_SET_07[2]  <<  ";\n}\n}\n";          
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
          
          out << "     if(SelectionCount_LEFT_ARM == 6)" <<  "\n    {\n";          
                 out << "    leftUpperArm_ROTATE_FRAMEB[3]     = "  <<  leftUpperArm_SET_01[3]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEB[0]     = "  <<  leftUpperArm_SET_01[0]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEB[1]     = "  <<  leftUpperArm_SET_01[1]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEB[2]     = "  <<  leftUpperArm_SET_01[2]     <<  ";\n";           
                 
                 out << "    leftForeArm_ROTATE_FRAMEB[3]      = "  <<  leftForeArm_SET_01[3]     <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEB[0]      = "  <<  leftForeArm_SET_01[0]     <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEB[1]      = "  <<  leftForeArm_SET_01[1]     <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEB[2]      = "  <<  leftForeArm_SET_01[2]     <<  ";\n";         
                
                out << "    leftGlovedHand_ROTATE_FRAMEB[3]    = "  <<  leftGlovedHand_SET_01[3]     <<  ";\n";
                out << "    leftGlovedHand_ROTATE_FRAMEB[0]    = "  <<  leftGlovedHand_SET_01[0]     <<  ";\n";
                out << "    leftGlovedHand_ROTATE_FRAMEB[1]    = "  <<  leftGlovedHand_SET_01[1]     <<  ";\n";
                out << "    leftGlovedHand_ROTATE_FRAMEB[2]    = "  <<  leftGlovedHand_SET_01[2]     <<  ";\n}\n";           
          out << "     else " <<  "\n    {\n";          
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
                out << "    leftGlovedHand_ROTATE_FRAMEB[2]    = "  <<  leftGlovedHand_SET_07[2]     <<  ";\n}\n}\n";         
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
          
          out << "     if(SelectionCount_RIGHT_ARM == 6)" <<  "\n    {\n";          
                 out << "    rightUpperArm_ROTATE_FRAMEB[3]   = "  <<  rightUpperArm_SET_01[3]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEB[0]   = "  <<  rightUpperArm_SET_01[0]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEB[1]   = "  <<  rightUpperArm_SET_01[1]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEB[2]   = "  <<  rightUpperArm_SET_01[2]     <<  ";\n";           
                 
                 out << "    rightForeArm_ROTATE_FRAMEB[3]   = "  <<  rightForeArm_SET_01[3]     <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEB[0]   = "  <<  rightForeArm_SET_01[0]     <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEB[1]   = "  <<  rightForeArm_SET_01[1]     <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEB[2]   = "  <<  rightForeArm_SET_01[2]     <<  ";\n";         
                
                out << "    rightGlovedHand_ROTATE_FRAMEB[3]   = "  <<  rightGlovedHand_SET_01[3]     <<  ";\n";
                out << "    rightGlovedHand_ROTATE_FRAMEB[0]   = "  <<  rightGlovedHand_SET_01[0]     <<  ";\n";
                out << "    rightGlovedHand_ROTATE_FRAMEB[1]   = "  <<  rightGlovedHand_SET_01[1]     <<  ";\n";
                out << "    rightGlovedHand_ROTATE_FRAMEB[2]   = "  <<  rightGlovedHand_SET_01[2]     <<  ";\n}\n";           
          out << "     else " <<  "\n    {\n";          
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
                out << "    rightGlovedHand_ROTATE_FRAMEB[2]   = "  <<  rightGlovedHand_SET_07[2]     <<  ";\n}\n}\n";         
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
          
          out << "     if(SelectionCount_LEFT_LEG == 6)" <<  "\n    {\n";          
                 out << "    leftUpperLeg_ROTATE_FRAMEB[3]   = "  <<  leftUpperLeg_SET_01[3]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[0]   = "  <<  leftUpperLeg_SET_01[0]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[1]   = "  <<  leftUpperLeg_SET_01[1]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[2]   = "  <<  leftUpperLeg_SET_01[2]     <<  ";\n";           
                    
                 out << "    leftLowerLeg_ROTATE_FRAMEB[3]   = "  <<  leftLowerLeg_SET_01[3]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[0]   = "  <<  leftLowerLeg_SET_01[0]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[1]   = "  <<  leftLowerLeg_SET_01[1]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[2]   = "  <<  leftLowerLeg_SET_01[2]     <<  ";\n";         
                      
                 out << "    leftFoot_ROTATE_FRAMEB[3]   = "  <<  leftFoot_SET_01[3]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[0]   = "  <<  leftFoot_SET_01[0]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[1]   = "  <<  leftFoot_SET_01[1]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[2]   = "  <<  leftFoot_SET_01[2]      <<  ";\n}\n";             
          out << "     else " <<  "\n    {\n";          
        
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
                 out << "    leftFoot_ROTATE_FRAMEB[2]   = "  <<  leftFoot_SET_07[2]     <<  ";\n}\n}\n";              
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
          
          out << "     if(SelectionCount_RIGHT_LEG == 6)" <<  "\n    {\n";          
                 out << "    rightUpperLeg_ROTATE_FRAMEB[3]   = "  <<  rightUpperLeg_SET_01[3]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[0]   = "  <<  rightUpperLeg_SET_01[0]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[1]   = "  <<  rightUpperLeg_SET_01[1]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[2]   = "  <<  rightUpperLeg_SET_01[2]     <<  ";\n";           
                      
                 out << "    rightLowerLeg_ROTATE_FRAMEB[3]   = "  <<  rightLowerLeg_SET_01[3]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[0]   = "  <<  rightLowerLeg_SET_01[0]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[1]   = "  <<  rightLowerLeg_SET_01[1]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[2]   = "  <<  rightLowerLeg_SET_01[2]     <<  ";\n";         
                     
                 out << "    rightFoot_ROTATE_FRAMEB[3]   = "  <<  rightFoot_SET_01[3]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[0]   = "  <<  rightFoot_SET_01[0]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[1]   = "  <<  rightFoot_SET_01[1]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[2]   = "  <<  rightFoot_SET_01[2]      <<  ";\n}\n";          
          out << "     else " <<  "\n    {\n";          
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
                 out << "    rightFoot_ROTATE_FRAMEB[2]   = "  <<  rightFoot_SET_07[2]     <<  ";\n}\n}\n";              
          //////////////////////____RIGHT___ARM___////////////////////////////////////////////////////////////////////           
         
          //////////////////////____HEAD__POSITION___////////////////////////////////////////////////////////////////////      
          out << "if(setSelection_HEAD == 6)" <<  "\n{\n";
                 out << "    head_ROTATE_FRAMEA[3]   = "  <<  head_SET_06[3]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEA[0]   = "  <<  head_SET_06[0]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEA[1]   = "  <<  head_SET_06[1]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEA[2]   = "  <<  head_SET_06[2]     <<  ";\n"; 
          
          out << "   if(SelectionCount_HEAD == 6)" <<  "\n{\n";          
                 out << "    head_ROTATE_FRAMEB[3]   = "  <<  head_SET_01[3]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[0]   = "  <<  head_SET_01[0]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[1]   = "  <<  head_SET_01[1]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[2]   = "  <<  head_SET_01[2]     <<  ";\n}\n";   
          
          out << "     else " <<  "\n    {\n";          
                 out << "    head_ROTATE_FRAMEB[3]   = "  <<  head_SET_07[3]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[0]   = "  <<  head_SET_07[0]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[1]   = "  <<  head_SET_07[1]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[2]   = "  <<  head_SET_07[2]     <<  ";\n}\n}\n";        
          //////////////////////____HEAD__POSITION___////////////////////////////////////////////////////////////////          

        
          //////////////////////____TORSO__POSITION___////////////////////////////////////////////////////////////////////      
          out << "if(setSelection_TORSO == 6)" <<  "\n{\n";
                 out << "    torso_ROTATE_FRAMEA[3]   = "  <<  torso_SET_06[3]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEA[0]   = "  <<  torso_SET_06[0]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEA[1]   = "  <<  torso_SET_06[1]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEA[2]   = "  <<  torso_SET_06[2]     <<  ";\n"; 
          
          out << "   if(SelectionCount_TORSO == 6)" <<  "\n{\n";          
                 out << "    torso_ROTATE_FRAMEB[3]   = "  <<  torso_SET_01[3]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[0]   = "  <<  torso_SET_01[0]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[1]   = "  <<  torso_SET_01[1]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[2]   = "  <<  torso_SET_01[2]     <<  ";\n}\n";  
          
          out << "     else " <<  "\n    {\n";          
                 out << "    torso_ROTATE_FRAMEB[3]   = "  <<  torso_SET_07[3]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[0]   = "  <<  torso_SET_07[0]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[1]   = "  <<  torso_SET_07[1]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[2]   = "  <<  torso_SET_07[2]     <<  ";\n}\n}\n";        
          //////////////////////____TORSO__POSITION___////////////////////////////////////////////////////////////////          
        
          //////////////////////____HIPS__POSITION___////////////////////////////////////////////////////////////////////      
          out << "if(setSelection_HIPS == 6)" <<  "\n{\n";
                 out << "    hips_ROTATE_FRAMEA[3]   = "  <<  hips_SET_06[3]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEA[0]   = "  <<  hips_SET_06[0]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEA[1]   = "  <<  hips_SET_06[1]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEA[2]   = "  <<  hips_SET_06[2]     <<  ";\n"; 
          
          out << "   if(SelectionCount_HIPS == 6)" <<  "\n{\n";          
                 out << "    hips_ROTATE_FRAMEB[3]   = "  <<  hips_SET_01[3]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[0]   = "  <<  hips_SET_01[0]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[1]   = "  <<  hips_SET_01[1]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[2]   = "  <<  hips_SET_01[2]     <<  ";\n}\n";  
          
          out << "     else " <<  "\n    {\n";          
                 out << "    hips_ROTATE_FRAMEB[3]   = "  <<  hips_SET_07[3]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[0]   = "  <<  hips_SET_07[0]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[1]   = "  <<  hips_SET_07[1]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[2]   = "  <<  hips_SET_07[2]     <<  ";\n}\n}\n";    
          //////////////////////____HIPS__POSITION___//////////////////////////////////////////////////////////////// 
//################################################################################################################################################  
//################################################################################################################################################  

      
          //////////////////////____MAIN__POSITION___////////////////////////////////////////////////////////////////////   
          out << "if(moveSet_setSelection == 7)" <<  "\n{\n";
          
          out << "    moveSet_MOVE_FRAMEA[0]     = "  <<   moveSet_SET_07[0]  <<  ";\n";
          out << "    moveSet_MOVE_FRAMEA[1]     = "  <<   moveSet_SET_07[1]  <<  ";\n";                   
          out << "    moveSet_MOVE_FRAMEA[2]     = "  <<   moveSet_SET_07[2]  <<  ";\n";
                      
          out << "    moveSet_MOVE_FRAMEB[0]     = "  <<   moveSet_SET_01[0]  <<  ";\n";
          out << "    moveSet_MOVE_FRAMEB[1]     = "  <<   moveSet_SET_01[1]  <<  ";\n";                    
          out << "    moveSet_MOVE_FRAMEB[2]     = "  <<   moveSet_SET_01[2]  <<  ";\n}\n";           
          //////////////////////____MAIN__POSITION___////////////////////////////////////////////////////////////////////           
         
          //////////////////////////________LEFT___ARM____///////////////////////////////////////////////////////          
          out << "if(setSelection_LEFT_ARM == 7)" <<  "\n{";

                   
                 out << "    leftUpperArm_ROTATE_FRAMEA[3]   = "  <<  leftUpperArm_SET_07[3]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[0]   = "  <<  leftUpperArm_SET_07[0]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[1]   = "  <<  leftUpperArm_SET_07[1]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEA[2]   = "  <<  leftUpperArm_SET_07[2]     <<  ";\n";
                 
                 out << "    leftUpperArm_ROTATE_FRAMEB[3]   = "  <<  leftUpperArm_SET_01[3]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEB[0]   = "  <<  leftUpperArm_SET_01[0]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEB[1]   = "  <<  leftUpperArm_SET_01[1]     <<  ";\n";
                 out << "    leftUpperArm_ROTATE_FRAMEB[2]   = "  <<  leftUpperArm_SET_01[2]     <<  ";\n";
                 ///_<subPart>_////                 
                 out << "    leftForeArm_ROTATE_FRAMEA[3]   = "  <<  leftForeArm_SET_07[3]     <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEA[0]   = "  <<  leftForeArm_SET_07[0]     <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEA[1]   = "  <<  leftForeArm_SET_07[1]     <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEA[2]   = "  <<  leftForeArm_SET_07[2]     <<  ";\n";
                 
                 out << "    leftForeArm_ROTATE_FRAMEB[3]   = "  <<  leftForeArm_SET_01[3]     <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEB[0]   = "  <<  leftForeArm_SET_01[0]     <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEB[1]   = "  <<  leftForeArm_SET_01[1]     <<  ";\n";
                 out << "    leftForeArm_ROTATE_FRAMEB[2]   = "  <<  leftForeArm_SET_01[2]     <<  ";\n";                           
                 ///_<subPart>_////          
                 out << "    leftGlovedHand_ROTATE_FRAMEA[3]   = "  <<  leftGlovedHand_SET_07[3]     <<  ";\n";
                 out << "    leftGlovedHand_ROTATE_FRAMEA[0]   = "  <<  leftGlovedHand_SET_07[0]     <<  ";\n";
                 out << "    leftGlovedHand_ROTATE_FRAMEA[1]   = "  <<  leftGlovedHand_SET_07[1]     <<  ";\n";
                 out << "    leftGlovedHand_ROTATE_FRAMEA[2]   = "  <<  leftGlovedHand_SET_07[2]     <<  ";\n";
                 
                 out << "    leftGlovedHand_ROTATE_FRAMEB[3]   = "  <<  leftGlovedHand_SET_01[3]     <<  ";\n";
                 out << "    leftGlovedHand_ROTATE_FRAMEB[0]   = "  <<  leftGlovedHand_SET_01[0]     <<  ";\n";
                 out << "    leftGlovedHand_ROTATE_FRAMEB[1]   = "  <<  leftGlovedHand_SET_01[1]     <<  ";\n";
                 out << "    leftGlovedHand_ROTATE_FRAMEB[2]   = "  <<  leftGlovedHand_SET_01[2]     <<  ";\n}\n";           
          //////////////////////////________LEFT___ARM____///////////////////////////////////////////////////////      
          
          
          //////////////////////////________RIGHT____ARM____///////////////////////////////////////////////////////           
          out << "if(setSelection_RIGHT_ARM == 7)" <<  "\n{";
                 out << "    rightUpperArm_ROTATE_FRAMEA[3]   = "  <<  rightUpperArm_SET_07[3]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[0]   = "  <<  rightUpperArm_SET_07[0]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[1]   = "  <<  rightUpperArm_SET_07[1]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEA[2]   = "  <<  rightUpperArm_SET_07[2]     <<  ";\n";
                 
                 out << "    rightUpperArm_ROTATE_FRAMEB[3]   = "  <<  rightUpperArm_SET_01[3]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEB[0]   = "  <<  rightUpperArm_SET_01[0]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEB[1]   = "  <<  rightUpperArm_SET_01[1]     <<  ";\n";
                 out << "    rightUpperArm_ROTATE_FRAMEB[2]   = "  <<  rightUpperArm_SET_01[2]     <<  ";\n";
                 ///_<subPart>_////                 
                 out << "    rightForeArm_ROTATE_FRAMEA[3]   = "  <<  rightForeArm_SET_07[3]     <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEA[0]   = "  <<  rightForeArm_SET_07[0]     <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEA[1]   = "  <<  rightForeArm_SET_07[1]     <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEA[2]   = "  <<  rightForeArm_SET_07[2]     <<  ";\n";
                 
                 out << "    rightForeArm_ROTATE_FRAMEB[3]   = "  <<  rightForeArm_SET_01[3]     <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEB[0]   = "  <<  rightForeArm_SET_01[0]     <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEB[1]   = "  <<  rightForeArm_SET_01[1]     <<  ";\n";
                 out << "    rightForeArm_ROTATE_FRAMEB[2]   = "  <<  rightForeArm_SET_01[2]     <<  ";\n";                           
                 ///_<subPart>_////          
                 out << "    rightGlovedHand_ROTATE_FRAMEA[3]   = "  <<  rightGlovedHand_SET_07[3]     <<  ";\n";
                 out << "    rightGlovedHand_ROTATE_FRAMEA[0]   = "  <<  rightGlovedHand_SET_07[0]     <<  ";\n";
                 out << "    rightGlovedHand_ROTATE_FRAMEA[1]   = "  <<  rightGlovedHand_SET_07[1]     <<  ";\n";
                 out << "    rightGlovedHand_ROTATE_FRAMEA[2]   = "  <<  rightGlovedHand_SET_07[2]     <<  ";\n";
                 
                 out << "    rightGlovedHand_ROTATE_FRAMEB[3]   = "  <<  rightGlovedHand_SET_01[3]     <<  ";\n";
                 out << "    rightGlovedHand_ROTATE_FRAMEB[0]   = "  <<  rightGlovedHand_SET_01[0]     <<  ";\n";
                 out << "    rightGlovedHand_ROTATE_FRAMEB[1]   = "  <<  rightGlovedHand_SET_01[1]     <<  ";\n";
                 out << "    rightGlovedHand_ROTATE_FRAMEB[2]   = "  <<  rightGlovedHand_SET_01[2]     <<  ";\n}\n";           
           //////////////////////////________RIGHT___ARM____//////////////////////////////////////////////////////// 
           
           //////////////////////////________LEFT___ARM____///////////////////////////////////////////////////////          
           out << "if(setSelection_LEFT_LEG == 7)" <<  "\n{";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[3]   = "  <<  leftUpperLeg_SET_07[3]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[0]   = "  <<  leftUpperLeg_SET_07[0]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[1]   = "  <<  leftUpperLeg_SET_07[1]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEA[2]   = "  <<  leftUpperLeg_SET_07[2]     <<  ";\n";
                 
                 out << "    leftUpperLeg_ROTATE_FRAMEB[3]   = "  <<  leftUpperLeg_SET_01[3]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[0]   = "  <<  leftUpperLeg_SET_01[0]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[1]   = "  <<  leftUpperLeg_SET_01[1]     <<  ";\n";
                 out << "    leftUpperLeg_ROTATE_FRAMEB[2]   = "  <<  leftUpperLeg_SET_01[2]     <<  ";\n";
                 
                 out << "    leftLowerLeg_ROTATE_FRAMEA[3]   = "  <<  leftLowerLeg_SET_07[3]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEA[0]   = "  <<  leftLowerLeg_SET_07[0]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEA[1]   = "  <<  leftLowerLeg_SET_07[1]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEA[2]   = "  <<  leftLowerLeg_SET_07[2]     <<  ";\n";
                 
                 out << "    leftLowerLeg_ROTATE_FRAMEB[3]   = "  <<  leftLowerLeg_SET_01[3]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[0]   = "  <<  leftLowerLeg_SET_01[0]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[1]   = "  <<  leftLowerLeg_SET_01[1]     <<  ";\n";
                 out << "    leftLowerLeg_ROTATE_FRAMEB[2]   = "  <<  leftLowerLeg_SET_01[2]     <<  ";\n";                           
          
                 out << "    leftFoot_ROTATE_FRAMEA[3]       = "  <<  leftFoot_SET_07[3]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEA[0]       = "  <<  leftFoot_SET_07[0]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEA[1]       = "  <<  leftFoot_SET_07[1]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEA[2]       = "  <<  leftFoot_SET_07[2]     <<  ";\n";
                 
                 out << "    leftFoot_ROTATE_FRAMEB[3]       = "  <<  leftFoot_SET_01[3]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[0]       = "  <<  leftFoot_SET_01[0]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[1]       = "  <<  leftFoot_SET_01[1]     <<  ";\n";
                 out << "    leftFoot_ROTATE_FRAMEB[2]       = "  <<  leftFoot_SET_01[2]     <<  ";\n}\n";            
          //////////////////////////________LEFT___ARM____///////////////////////////////////////////////////////      
          
          //////////////////////////________RIGHT____ARM____///////////////////////////////////////////////////////           
          out << "if(setSelection_RIGHT_LEG == 7)" <<  "\n{";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[3]   = "  <<  rightUpperLeg_SET_07[3]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[0]   = "  <<  rightUpperLeg_SET_07[0]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[1]   = "  <<  rightUpperLeg_SET_07[1]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEA[2]   = "  <<  rightUpperLeg_SET_07[2]     <<  ";\n";
                 
                 out << "    rightUpperLeg_ROTATE_FRAMEB[3]   = "  <<  rightUpperLeg_SET_01[3]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[0]   = "  <<  rightUpperLeg_SET_01[0]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[1]   = "  <<  rightUpperLeg_SET_01[1]     <<  ";\n";
                 out << "    rightUpperLeg_ROTATE_FRAMEB[2]   = "  <<  rightUpperLeg_SET_01[2]     <<  ";\n";
                
                 out << "    rightLowerLeg_ROTATE_FRAMEA[3]   = "  <<  rightLowerLeg_SET_07[3]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEA[0]   = "  <<  rightLowerLeg_SET_07[0]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEA[1]   = "  <<  rightLowerLeg_SET_07[1]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEA[2]   = "  <<  rightLowerLeg_SET_07[2]     <<  ";\n";
                 
                 out << "    rightLowerLeg_ROTATE_FRAMEB[3]   = "  <<  rightLowerLeg_SET_01[3]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[0]   = "  <<  rightLowerLeg_SET_01[0]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[1]   = "  <<  rightLowerLeg_SET_01[1]     <<  ";\n";
                 out << "    rightLowerLeg_ROTATE_FRAMEB[2]   = "  <<  rightLowerLeg_SET_01[2]     <<  ";\n";                           
        
                 out << "    rightFoot_ROTATE_FRAMEA[3]   = "  <<  rightFoot_SET_07[3]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEA[0]   = "  <<  rightFoot_SET_07[0]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEA[1]   = "  <<  rightFoot_SET_07[1]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEA[2]   = "  <<  rightFoot_SET_07[2]     <<  ";\n";
                 
                 out << "    rightFoot_ROTATE_FRAMEB[3]   = "  <<  rightFoot_SET_01[3]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[0]   = "  <<  rightFoot_SET_01[0]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[1]   = "  <<  rightFoot_SET_01[1]     <<  ";\n";
                 out << "    rightFoot_ROTATE_FRAMEB[2]   = "  <<  rightFoot_SET_01[2]     <<  ";\n}\n";           
           //////////////////////////________RIGHT___ARM____////////////////////////////////////////////////////////            
        
           //////////////////////____HEAD__POSITION___////////////////////////////////////////////////////////////////////   
           out << "if(setSelection_HEAD == 7)" <<  "\n{\n";
          
                 out << "    head_ROTATE_FRAMEA[3]   = "  <<  head_SET_07[3]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEA[0]   = "  <<  head_SET_07[0]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEA[1]   = "  <<  head_SET_07[1]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEA[2]   = "  <<  head_SET_07[2]     <<  ";\n";          

                 out << "    head_ROTATE_FRAMEB[3]   = "  <<  head_SET_01[3]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[0]   = "  <<  head_SET_01[0]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[1]   = "  <<  head_SET_01[1]     <<  ";\n";
                 out << "    head_ROTATE_FRAMEB[2]   = "  <<  head_SET_01[2]     <<  ";\n}\n";              
           //////////////////////____HEAD__POSITION___////////////////////////////////////////////////////////////////////           
           
           //////////////////////____TORSO__POSITION___////////////////////////////////////////////////////////////////////   
           out << "if(setSelection_TORSO == 7)" <<  "\n{\n";
                 out << "    torso_ROTATE_FRAMEA[3]   = "  <<  torso_SET_07[3]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEA[0]   = "  <<  torso_SET_07[0]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEA[1]   = "  <<  torso_SET_07[1]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEA[2]   = "  <<  torso_SET_07[2]     <<  ";\n";          

                 out << "    torso_ROTATE_FRAMEB[3]   = "  <<  torso_SET_01[3]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[0]   = "  <<  torso_SET_01[0]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[1]   = "  <<  torso_SET_01[1]     <<  ";\n";
                 out << "    torso_ROTATE_FRAMEB[2]   = "  <<  torso_SET_01[2]     <<  ";\n}\n";             
          //////////////////////____TORSO__POSITION___////////////////////////////////////////////////////////////////////           
          
          //////////////////////____HIPS__POSITION___////////////////////////////////////////////////////////////////////   
          out << "if(setSelection_HIPS == 7)" <<  "\n{\n";
                 out << "    hips_ROTATE_FRAMEA[3]   = "  <<  hips_SET_07[3]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEA[0]   = "  <<  hips_SET_07[0]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEA[1]   = "  <<  hips_SET_07[1]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEA[2]   = "  <<  hips_SET_07[2]     <<  ";\n";          
          
                 out << "    hips_ROTATE_FRAMEB[3]   = "  <<  hips_SET_01[3]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[0]   = "  <<  hips_SET_01[0]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[1]   = "  <<  hips_SET_01[1]     <<  ";\n";
                 out << "    hips_ROTATE_FRAMEB[2]   = "  <<  hips_SET_01[2]     <<  ";\n}\n";             
          //////////////////////____HIPS__POSITION___//////////////////////////////////////////////////////////////////// 
