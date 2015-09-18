           mainBodyPosition_setSelectionLimit         = mainBodyPosition_setSelectionLimit;   
           mainBodyPosition_SelectionCount            = mainBodyPosition_SelectionCount;          
//ERASE_ALL_OF_THESE                 
           setSelectionLimit_HEAD       = setSelectionLimit_HEAD;
           SelectionCount_HEAD          = SelectionCount_HEAD;     
//ERASE_ALL_OF_THESE       
           setSelectionLimit_TORSO      = setSelectionLimit_TORSO;
           SelectionCount_TORSO         = SelectionCount_TORSO;
//ERASE_ALL_OF_THESE            
           setSelectionLimit_HIPS       = setSelectionLimit_HIPS;
           SelectionCount_HIPS          = SelectionCount_HIPS;           
//BOTH_SIDES_ARE_EQUAL
           setSelectionLimit_LEFT_ARM   = setSelectionLimit_LEFT_ARM;
           SelectionCount_LEFT_ARM      = SelectionCount_LEFT_ARM;
//BOTH_SIDES_ARE_EQUAL           
           setSelectionLimit_RIGHT_ARM  = setSelectionLimit_RIGHT_ARM;
           SelectionCount_RIGHT_ARM     = SelectionCount_RIGHT_ARM;         
//BOTH_SIDES_ARE_EQUAL         
           setSelectionLimit_LEFT_LEG   = setSelectionLimit_LEFT_LEG;
           SelectionCount_LEFT_LEG      = SelectionCount_LEFT_LEG;
//BOTH_SIDES_ARE_EQUAL           
           setSelectionLimit_RIGHT_LEG  = setSelectionLimit_RIGHT_LEG;
           SelectionCount_RIGHT_LEG     = SelectionCount_RIGHT_LEG;          
         
         #include "HEAD/HEAD_frame_1.cpp"
         #include "LEFT_LEG/LEFT_LEG_frame_1.cpp"         
         #include "TORSO/TORSO_frame_1.cpp"
         #include "HIPS/HIPS_frame_1.cpp"         
         #include "LEFT_ARM/LEFT_ARM_frame_1.cpp"          
         #include "RIGHT_ARM/RIGHT_ARM_frame_1.cpp"
          
         #include "RIGHT_LEG/RIGHT_LEG_frame_1.cpp"         
         
                  
        if(mainBodyPosition_setSelection == 1)
        {          
                      mainBodyPosition_MOVE_FRAMEA[0]      =  mainBodyPosition_SET_01[0];
                      mainBodyPosition_MOVE_FRAMEA[1]      =  mainBodyPosition_SET_01[1];                     
                      mainBodyPosition_MOVE_FRAMEA[2]      =  mainBodyPosition_SET_01[2];
                      
                      mainBodyPosition_MOVE_FRAMEB[0]      =  mainBodyPosition_SET_02[0];
                      mainBodyPosition_MOVE_FRAMEB[1]      =  mainBodyPosition_SET_02[1];                      
                      mainBodyPosition_MOVE_FRAMEB[2]      =  mainBodyPosition_SET_02[2];                    
        }
     
      
         #include "HEAD/HEAD_frame_2.cpp"           
         #include "TORSO/TORSO_frame_2.cpp"
         #include "HIPS/HIPS_frame_2.cpp" 
         #include "LEFT_ARM/LEFT_ARM_frame_2.cpp" 
         #include "RIGHT_ARM/RIGHT_ARM_frame_2.cpp"
         #include "LEFT_LEG/LEFT_LEG_frame_2.cpp" 
         #include "RIGHT_LEG/RIGHT_LEG_frame_2.cpp"         
                               
         if(mainBodyPosition_setSelection == 2)
         {
                mainBodyPosition_MOVE_FRAMEA[0]      =  mainBodyPosition_SET_02[0];
                mainBodyPosition_MOVE_FRAMEA[1]      =  mainBodyPosition_SET_02[1];                     
                mainBodyPosition_MOVE_FRAMEA[2]      =  mainBodyPosition_SET_02[2];

                if(mainBodyPosition_SelectionCount == 2)
                {         
                      mainBodyPosition_MOVE_FRAMEB[0]      =  mainBodyPosition_SET_01[0];
                      mainBodyPosition_MOVE_FRAMEB[1]      =  mainBodyPosition_SET_01[1];                      
                      mainBodyPosition_MOVE_FRAMEB[2]      =  mainBodyPosition_SET_01[2];                                     
                }
                else
                {         
                      mainBodyPosition_MOVE_FRAMEB[0]      =  mainBodyPosition_SET_03[0];
                      mainBodyPosition_MOVE_FRAMEB[1]      =  mainBodyPosition_SET_03[1];                      
                      mainBodyPosition_MOVE_FRAMEB[2]      =  mainBodyPosition_SET_03[2];                                       
                }
          }    
           
           
         #include "HEAD/HEAD_frame_3.cpp"
         #include "TORSO/TORSO_frame_3.cpp"                      
         #include "HIPS/HIPS_frame_3.cpp" 
         #include "LEFT_ARM/LEFT_ARM_frame_3.cpp" 
         #include "RIGHT_ARM/RIGHT_ARM_frame_3.cpp"         
         #include "LEFT_LEG/LEFT_LEG_frame_3.cpp" 
         #include "RIGHT_LEG/RIGHT_LEG_frame_3.cpp"
         
                    
           if(mainBodyPosition_setSelection == 3)
           {
                 mainBodyPosition_MOVE_FRAMEA[0]      =  mainBodyPosition_SET_03[0];
                 mainBodyPosition_MOVE_FRAMEA[1]      =  mainBodyPosition_SET_03[1];                     
                 mainBodyPosition_MOVE_FRAMEA[2]      =  mainBodyPosition_SET_03[2];
         
                 if(mainBodyPosition_SelectionCount == 3)
                 {          

                      mainBodyPosition_MOVE_FRAMEB[0]      =  mainBodyPosition_SET_01[0];
                      mainBodyPosition_MOVE_FRAMEB[1]      =  mainBodyPosition_SET_01[1];                      
                      mainBodyPosition_MOVE_FRAMEB[2]      =  mainBodyPosition_SET_01[2];   
                 }
                 else
                 {
                      mainBodyPosition_MOVE_FRAMEB[0]      =  mainBodyPosition_SET_04[0];
                      mainBodyPosition_MOVE_FRAMEB[1]      =  mainBodyPosition_SET_04[1];                      
                      mainBodyPosition_MOVE_FRAMEB[2]      =  mainBodyPosition_SET_04[2];                                     
                 } 
            }    
           
         #include "HEAD/HEAD_frame_4.cpp" 
         #include "TORSO/TORSO_frame_4.cpp"
         #include "HIPS/HIPS_frame_4.cpp"            
         #include "LEFT_ARM/LEFT_ARM_frame_4.cpp" 
         #include "RIGHT_ARM/RIGHT_ARM_frame_4.cpp"         
         #include "LEFT_LEG/LEFT_LEG_frame_4.cpp" 
         #include "RIGHT_LEG/RIGHT_LEG_frame_4.cpp"         
                   
           if(mainBodyPosition_setSelection == 4)
           {
                      mainBodyPosition_MOVE_FRAMEA[0]      =  mainBodyPosition_SET_04[0];
                      mainBodyPosition_MOVE_FRAMEA[1]      =  mainBodyPosition_SET_04[1];                     
                      mainBodyPosition_MOVE_FRAMEA[2]      =  mainBodyPosition_SET_04[2];
           
                      if(mainBodyPosition_SelectionCount == 4)
                      {          
                          mainBodyPosition_MOVE_FRAMEB[0]      =  mainBodyPosition_SET_01[0];
                          mainBodyPosition_MOVE_FRAMEB[1]      =  mainBodyPosition_SET_01[1];                      
                          mainBodyPosition_MOVE_FRAMEB[2]      =  mainBodyPosition_SET_01[2];                                
                      }

           }
