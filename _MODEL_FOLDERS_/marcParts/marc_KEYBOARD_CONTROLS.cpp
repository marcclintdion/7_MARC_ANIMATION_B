
    

//----------------------------------------------------------------------------------------    
//----------------------------------------------------------------------------------------    
if (keys['L'] &! keys['I'] &! keys['K'])
{
     if(marcRotation >= 360.0)
     {
          marcRotation -= 360.0;
     }
     if(marcRotation < 0.0)
     {
          marcRotation += 360.0;
     }            

     if(marcRotation > 90.0 && marcRotation <= 270.0)
     {
         marcRotation -= 4.0 * frameRateAdjustment;
     }
     if(marcRotation < 90.0 && marcRotation >= 0.0 || marcRotation > 270.0 && marcRotation < 360.0)
     {
         marcRotation += 4.0 * frameRateAdjustment;
     }
//------------------------------------------------------------------
           CollisionCheck_RIGHT(boundingBox_MAIN_CHARACTER_left_edge, 
                                boundingBox_MAIN_CHARACTER_right_edge,
                                boundingBox_MAIN_CHARACTER_lower_edge,
                                boundingBox_MAIN_CHARACTER_upper_edge,
                                boundingBox_MAIN_CHARACTER_near_edge, 
                                boundingBox_MAIN_CHARACTER_far_edge);          
     if(RIGHT == true)         
     {
          marcWalking                    = true;  
          moveSet[0]                    -= .01965*frameRateAdjustment;
          shadows_TextureDisplacement_X += .00975*frameRateAdjustment;
     }
}
//----------------------------------------------------------------------------------------    
//----------------------------------------------------------------------------------------     
if (keys['J'] &! keys['I'] &! keys['K'])
{
     if(marcRotation >= 360.0)
     {
          marcRotation -= 360.0;
     }
     if(marcRotation <= 0.0)
     {
          marcRotation += 360.0;
     }          
     
     if(marcRotation == 0.0)
     {
          marcRotation += 360.0;
     }
     if(marcRotation >= 270.0 && marcRotation <= 360.0 || marcRotation >= 0.0 && marcRotation <= 90.0)
     {
          marcRotation -= 4.0* frameRateAdjustment;
     }
     if(marcRotation < 270.0  && marcRotation  >= 90.0)
     {
          marcRotation += 4.0* frameRateAdjustment;
     }     
          
//------------------------------------------------------------------    
           CollisionCheck_LEFT(boundingBox_MAIN_CHARACTER_left_edge,  
                               boundingBox_MAIN_CHARACTER_right_edge,    
                               boundingBox_MAIN_CHARACTER_lower_edge,
                               boundingBox_MAIN_CHARACTER_upper_edge,
                               boundingBox_MAIN_CHARACTER_near_edge,  
                               boundingBox_MAIN_CHARACTER_far_edge); 
     if(LEFT == true)        
     {       
          marcWalking                     = true;              
          moveSet[0]                     += .01965*frameRateAdjustment;
          shadows_TextureDisplacement_X  -= .00975*frameRateAdjustment;
     }
}
//----------------------------------------------------------------------------------------    
//----------------------------------------------------------------------------------------     
if (keys['I'] &! keys['J'] &! keys['L'])
{
     if(marcRotation >= 360)
     {
         marcRotation -= 360;
     }
     if(marcRotation < 0)
     {
         marcRotation += 360;
     }      
     if(marcRotation >= 180 && marcRotation < 360)
     {
           marcRotation -= 4* frameRateAdjustment;
     }
     if(marcRotation < 180 && marcRotation >= 0.0)
     {
           marcRotation += 4* frameRateAdjustment;
     }
//------------------------------------------------------------------   
            CollisionCheck_UP(boundingBox_MAIN_CHARACTER_left_edge,  
                              boundingBox_MAIN_CHARACTER_right_edge,    
                              boundingBox_MAIN_CHARACTER_lower_edge, 
                              boundingBox_MAIN_CHARACTER_upper_edge,
                              boundingBox_MAIN_CHARACTER_near_edge,  
                              boundingBox_MAIN_CHARACTER_far_edge);  
     if(UP == true)      
     { 
           marcWalking                    = true;               
           moveSet[2]                    += .01965*frameRateAdjustment;
           shadows_TextureDisplacement_Y += .00975*frameRateAdjustment;     
     }
}	
//----------------------------------------------------------------------------------------    
//----------------------------------------------------------------------------------------     
if (keys['K'] &! keys['J'] &! keys['L'])
{
     if(marcRotation >= 360)
     {
          marcRotation -= 360;
     }
     if(marcRotation < 0)
     {
          marcRotation += 360;
     } 
     
     if(marcRotation <= 3)
     {
          marcRotation = 0;
     }
     if(marcRotation >= 357)
     {
          marcRotation = 0;
     }      
     
     if(marcRotation < 360 && marcRotation > 180.0)
     {
          marcRotation += 4* frameRateAdjustment;
     }     
     if(marcRotation > 0.0 && marcRotation <= 180.0)
     {
          marcRotation -= 4* frameRateAdjustment;
     }
//------------------------------------------------------------------    
            CollisionCheck_DOWN(boundingBox_MAIN_CHARACTER_left_edge,  
                                boundingBox_MAIN_CHARACTER_right_edge,   
                                boundingBox_MAIN_CHARACTER_lower_edge, 
                                boundingBox_MAIN_CHARACTER_upper_edge,
                                boundingBox_MAIN_CHARACTER_near_edge,  
                                boundingBox_MAIN_CHARACTER_far_edge); 
     if(DOWN == true)        
     {        
          marcWalking                     =  true;              
          moveSet[2]                     -= 0.01965 * frameRateAdjustment;
          shadows_TextureDisplacement_Y  -= 0.00975 * frameRateAdjustment;    
     }
}      
//----------------------------------------------------------------------------------------    
//----------------------------------------------------------------------------------------  
if (keys['K'] && keys['L'])
{
    if(marcRotation >= 360)
    {
         marcRotation -= 360;
    }
    if(marcRotation < 0)
    {
         marcRotation += 360;
    } 
     
    if(marcRotation > 45 && marcRotation <= 225)
    {
         marcRotation -= 4* frameRateAdjustment;
    }
    if(marcRotation < 45 && marcRotation >= 0.0 || marcRotation >= 225 && marcRotation <= 360)
    {
         marcRotation += 4* frameRateAdjustment;
    }
//------------------------------------------------------------------ 
            CollisionCheck_DOWN(boundingBox_MAIN_CHARACTER_left_edge,  
                                boundingBox_MAIN_CHARACTER_right_edge,   
                                boundingBox_MAIN_CHARACTER_lower_edge, 
                                boundingBox_MAIN_CHARACTER_upper_edge,
                                boundingBox_MAIN_CHARACTER_near_edge,  
                                boundingBox_MAIN_CHARACTER_far_edge);
            
            CollisionCheck_RIGHT(boundingBox_MAIN_CHARACTER_left_edge,   
                                 boundingBox_MAIN_CHARACTER_right_edge,
                                 boundingBox_MAIN_CHARACTER_lower_edge,  
                                 boundingBox_MAIN_CHARACTER_upper_edge,
                                 boundingBox_MAIN_CHARACTER_near_edge,   
                                 boundingBox_MAIN_CHARACTER_far_edge);             
            
    if(DOWN == true  && RIGHT == true )        
    {        
         marcWalking                    = true;              
         moveSet[0]                    -= .015*frameRateAdjustment;
         moveSet[2]                    -= .015*frameRateAdjustment;
         shadows_TextureDisplacement_X += .0075*frameRateAdjustment;
         shadows_TextureDisplacement_Y -= .0075*frameRateAdjustment;      
    }
}      
//----------------------------------------------------------------------------------------    
//----------------------------------------------------------------------------------------  
if (keys['I'] && keys['L'])
{
    if(marcRotation >= 360)
    {
        marcRotation -= 360;
    }
    if(marcRotation < 0)
    {
        marcRotation += 360;
    } 
    if(marcRotation > 135 && marcRotation <= 315)
    {
        marcRotation -= 4* frameRateAdjustment;
    }
    if(marcRotation < 135 && marcRotation >= 0.0 || marcRotation >= 315 && marcRotation <= 360)
    {
        marcRotation += 4* frameRateAdjustment;
    }
//------------------------------------------------------------------  
            CollisionCheck_UP(boundingBox_MAIN_CHARACTER_left_edge,   
                              boundingBox_MAIN_CHARACTER_right_edge,  
                              boundingBox_MAIN_CHARACTER_lower_edge,  
                              boundingBox_MAIN_CHARACTER_upper_edge,
                              boundingBox_MAIN_CHARACTER_near_edge,   
                              boundingBox_MAIN_CHARACTER_far_edge); 
            
            CollisionCheck_RIGHT(boundingBox_MAIN_CHARACTER_left_edge,   
                                 boundingBox_MAIN_CHARACTER_right_edge,
                                 boundingBox_MAIN_CHARACTER_lower_edge,  
                                 boundingBox_MAIN_CHARACTER_upper_edge,
                                 boundingBox_MAIN_CHARACTER_near_edge,   
                                 boundingBox_MAIN_CHARACTER_far_edge);            
            
    if(UP == true && RIGHT == true )      
    {      
         marcWalking = true;              
         moveSet[0]  -= .015*frameRateAdjustment;
         moveSet[2]  += .015*frameRateAdjustment;
         shadows_TextureDisplacement_X   += .0075*frameRateAdjustment;
         shadows_TextureDisplacement_Y   += .0075*frameRateAdjustment;     
    }
}    
//----------------------------------------------------------------------------------------    
//----------------------------------------------------------------------------------------    
if (keys['I'] && keys['J'])
{
    if(marcRotation >= 360)
    {
        marcRotation -= 360;
    }
    if(marcRotation < 0)
    {
        marcRotation += 360;
    } 
    if(marcRotation > 225 && marcRotation <= 360 || marcRotation <= 45 && marcRotation >= 0)
    {
        marcRotation -= 4* frameRateAdjustment;
    }
    if(marcRotation < 225 && marcRotation >= 45)
    {
        marcRotation += 4* frameRateAdjustment;
    }
//------------------------------------------------------------------    
            CollisionCheck_UP(boundingBox_MAIN_CHARACTER_left_edge,  
                              boundingBox_MAIN_CHARACTER_right_edge,
                              boundingBox_MAIN_CHARACTER_lower_edge, 
                              boundingBox_MAIN_CHARACTER_upper_edge, 
                              boundingBox_MAIN_CHARACTER_near_edge,  
                              boundingBox_MAIN_CHARACTER_far_edge);
            
            CollisionCheck_LEFT(boundingBox_MAIN_CHARACTER_left_edge,  
                                boundingBox_MAIN_CHARACTER_right_edge,    
                                boundingBox_MAIN_CHARACTER_lower_edge, 
                                boundingBox_MAIN_CHARACTER_upper_edge,
                                boundingBox_MAIN_CHARACTER_near_edge,  
                                boundingBox_MAIN_CHARACTER_far_edge); 
               
     if(UP == true && LEFT == true)      
     {      
         marcWalking = true;              
         moveSet[0]  += .015*frameRateAdjustment;
         moveSet[2]  += .015*frameRateAdjustment;
         shadows_TextureDisplacement_X   -= .0075*frameRateAdjustment;
         shadows_TextureDisplacement_Y   += .0075*frameRateAdjustment;     
     }
}      
//----------------------------------------------------------------------------------------    
//----------------------------------------------------------------------------------------     
if (keys['J'] && keys['K'])
{
    if(marcRotation >= 360)
    {
        marcRotation -= 360;
    }
    if(marcRotation < 0)
    {
        marcRotation += 360;
    } 
    if(marcRotation > 315 && marcRotation <= 360 || marcRotation <= 135 && marcRotation >= 0)
    {
        marcRotation -= 4* frameRateAdjustment;
    }
    if(marcRotation < 315 && marcRotation >= 135)
    {
        marcRotation += 4* frameRateAdjustment;
    }
//------------------------------------------------------------------
            CollisionCheck_LEFT(boundingBox_MAIN_CHARACTER_left_edge,  
                                boundingBox_MAIN_CHARACTER_right_edge,
                                boundingBox_MAIN_CHARACTER_lower_edge, 
                                boundingBox_MAIN_CHARACTER_upper_edge,
                                boundingBox_MAIN_CHARACTER_near_edge,  
                                boundingBox_MAIN_CHARACTER_far_edge);
            
            CollisionCheck_DOWN(boundingBox_MAIN_CHARACTER_left_edge,  
                                boundingBox_MAIN_CHARACTER_right_edge,   
                                boundingBox_MAIN_CHARACTER_lower_edge, 
                                boundingBox_MAIN_CHARACTER_upper_edge,
                                boundingBox_MAIN_CHARACTER_near_edge,  
                                boundingBox_MAIN_CHARACTER_far_edge);            
    if(LEFT == true && DOWN == true)        
    {       
         marcWalking  = true;              
         moveSet[0]  += .015*frameRateAdjustment;
         moveSet[2]  -= .015*frameRateAdjustment;
         shadows_TextureDisplacement_X   -= .0075*frameRateAdjustment;
         shadows_TextureDisplacement_Y   -= .0075*frameRateAdjustment;      
    }
}     
//------------------------------------------------------------------------------
    if (!keys['L'] && !keys['J'] && !keys['I'] && !keys['K'])
	{
          marcWalking = false;  
    }        
