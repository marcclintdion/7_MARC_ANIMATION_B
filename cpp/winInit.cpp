


int WINAPI WinMain(	HINSTANCE hInstance,
					HINSTANCE hPrevInstance,
					LPSTR     lpCmdLine,
					int       nCmdShow )
{
	WNDCLASSEX winClass;
	MSG        uMsg;

    memset(&uMsg,0,sizeof(uMsg));

	winClass.lpszClassName = "MY_WINDOWS_CLASS";
	winClass.cbSize        = sizeof(WNDCLASSEX);
	winClass.style         = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	winClass.lpfnWndProc   = WindowProc;
	winClass.hInstance     = hInstance;
    winClass.hIcon	       = LoadIcon(NULL, IDI_APPLICATION);
    winClass.hIconSm	   = LoadIcon(NULL, IDI_APPLICATION);
	winClass.hCursor       = LoadCursor(NULL, IDC_ARROW);
	winClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	winClass.lpszMenuName  = NULL;
	winClass.cbClsExtra    = 0;
	winClass.cbWndExtra    = 0;
	
	if( !RegisterClassEx(&winClass) )
		return E_FAIL;

	hWnd = CreateWindowEx( 0,"MY_WINDOWS_CLASS",
						    "D1_C3",
							WS_OVERLAPPEDWINDOW,
					 	    0, 000, (DWORD)screenWidth, (DWORD)screenHeight/1, 0, 0, hInstance, 0 );

	if( hWnd == NULL )
		return E_FAIL;

    ShowWindow( hWnd, nCmdShow );
    UpdateWindow( hWnd );


	

Init();
Dot3shader();


	while( uMsg.message != WM_QUIT )
	{
		if( PeekMessage( &uMsg, NULL, 0, 0, PM_REMOVE ) )
		{ 
			TranslateMessage( &uMsg );
			DispatchMessage( &uMsg );
		}
    
        else
        {   
            ProcessKeyboard();
            render();
        	       
        }
	}
	
	
    //out << "Average frameRate = " << (frameNumber/(GetTickCount() - inTheBeginning))*1000 << endl;
	shutDown();

    UnregisterClass( "MY_WINDOWS_CLASS", hInstance );

	return uMsg.wParam;
	
}


LRESULT CALLBACK WindowProc( HWND   hWnd, 
							 UINT   msg, 
							 WPARAM wParam, 
							 LPARAM lParam )
{
    static POINT ptLastMousePosit;
	static POINT ptCurrentMousePosit;
	
    switch( msg )
	{
        case WM_KEYDOWN:
		{
			keys[wParam] = TRUE;					// If So, Mark It As TRUE
            return 0;								// Jump Back
		}
        break;

        case WM_KEYUP:								// Has A Key Been Released?
		{
			keys[wParam] = FALSE;					// If So, Mark It As FALSE
			return 0;								// Jump Back
		}
		break;

        case WM_RBUTTONDOWN:
		{
			ptLastMousePosit.x = ptCurrentMousePosit.x = LOWORD (lParam);
            ptLastMousePosit.y = ptCurrentMousePosit.y = HIWORD (lParam);
			rightMouseActivated = true;

        }break;		
        //-----------------------------------------------------------------------------------------------------------------        
        case WM_LBUTTONDOWN:
		{
			ptLastMousePosit.x = ptCurrentMousePosit.x = LOWORD (lParam);
            ptLastMousePosit.y = ptCurrentMousePosit.y = HIWORD (lParam);
			leftMouseActivated = true;
            
            if(ptCurrentMousePosit.x >= 0 && ptCurrentMousePosit.x <= 200 && ptCurrentMousePosit.y >= 0 && ptCurrentMousePosit.y <= 200)
            {
                    leftUpperArm_ROTATE[3]               = -152;
                    leftUpperArm_ROTATE[0]               = 1;
                    leftUpperArm_ROTATE[1]               = 0;
                    leftUpperArm_ROTATE[2]               = -0.48;
                    //-----------------------------------------
                    rightUpperArm_ROTATE[3]              = -152;
                    rightUpperArm_ROTATE[0]              = 1;
                    rightUpperArm_ROTATE[1]              = 0;
                    rightUpperArm_ROTATE[2]              = 0.56;
            }			
            if(ptCurrentMousePosit.x >= 200 && ptCurrentMousePosit.x <= 400 && ptCurrentMousePosit.y >= 0 && ptCurrentMousePosit.y <= 200)
            {
                    leftUpperArm_ROTATE[3]               = 78;
                    leftUpperArm_ROTATE[0]               = 1;
                    leftUpperArm_ROTATE[1]               = 0.24;
                    leftUpperArm_ROTATE[2]               = 0;
                    //-----------------------------------------
                    rightUpperArm_ROTATE[3]              = 78;
                    rightUpperArm_ROTATE[0]              = 1.05;
                    rightUpperArm_ROTATE[1]              = -0.2;
                    rightUpperArm_ROTATE[2]              = 0;
            }	
            if(ptCurrentMousePosit.x >= 400 && ptCurrentMousePosit.x <= 600 && ptCurrentMousePosit.y >= 0 && ptCurrentMousePosit.y <= 200)
            {        
                    leftUpperArm_ROTATE[3]               = -148;
                    leftUpperArm_ROTATE[0]               = 1;
                    leftUpperArm_ROTATE[1]               = -0.02;
                    leftUpperArm_ROTATE[2]               = -0.999999;
                    //-----------------------------------------
                    rightUpperArm_ROTATE[3]              = -146;
                    rightUpperArm_ROTATE[0]              = 1.05;
                    rightUpperArm_ROTATE[1]              = 0.03;
                    rightUpperArm_ROTATE[2]              = 1.27;       
            }
            if(ptCurrentMousePosit.x >= 600 && ptCurrentMousePosit.x <= 800 && ptCurrentMousePosit.y >= 0 && ptCurrentMousePosit.y <= 200)
            {        
                    leftUpperArm_ROTATE[3]               = -118.114;
                    leftUpperArm_ROTATE[0]               = 0.556001;
                    leftUpperArm_ROTATE[1]               = -0.754832;
                    leftUpperArm_ROTATE[2]               = -0.834031;
                    //-----------------------------------------
                    rightUpperArm_ROTATE[3]              = -122.67;
                    rightUpperArm_ROTATE[0]              = 1.03128;
                    rightUpperArm_ROTATE[1]              = 1.47925;
                    rightUpperArm_ROTATE[2]              = 1.40834;
            }        
            if(ptCurrentMousePosit.x >= 800 && ptCurrentMousePosit.x <= 1000 && ptCurrentMousePosit.y >= 0 && ptCurrentMousePosit.y <= 200)
            {        
                    leftUpperArm_ROTATE[3]               = 93;
                    leftUpperArm_ROTATE[0]               = 1;
                    leftUpperArm_ROTATE[1]               = 0.24;
                    leftUpperArm_ROTATE[2]               = 2.47;
                    //-----------------------------------------
                    rightUpperArm_ROTATE[3]              = 91;
                    rightUpperArm_ROTATE[0]              = 1.05;
                    rightUpperArm_ROTATE[1]              = -0.2;
                    rightUpperArm_ROTATE[2]              = -2.44;          
            }          
            //----------------------------------------------------------------------------------------------------------        
            
            if(ptCurrentMousePosit.x >= 1080 && ptCurrentMousePosit.x <= 1180 && ptCurrentMousePosit.y >= 0 && ptCurrentMousePosit.y <= 100)
            {        
                    BODY_PART_SELECTION = 7;
            }            
            if(ptCurrentMousePosit.x >= 1180 && ptCurrentMousePosit.x <= 1280 && ptCurrentMousePosit.y >= 0 && ptCurrentMousePosit.y <= 100)
            {        
                    BODY_PART_SELECTION = 5;
            }            
            //----------------------------------------------------------------------------------------------------------        
            if(ptCurrentMousePosit.x >= 1180 && ptCurrentMousePosit.x <= 1280 && ptCurrentMousePosit.y >= 100 && ptCurrentMousePosit.y <= 200)
            {        
                    BODY_PART_SELECTION = 6;
            }         
            //----------------------------------------------------------------------------------------------------------        
            if(ptCurrentMousePosit.x >= 1180 && ptCurrentMousePosit.x <= 1280 && ptCurrentMousePosit.y >= 200 && ptCurrentMousePosit.y <= 300)
            {        
                    BODY_PART_SELECTION = 1;
                    leftArmSelection = 8;
            }        
            if(ptCurrentMousePosit.x >= 1180 && ptCurrentMousePosit.x <= 1280 && ptCurrentMousePosit.y >= 300 && ptCurrentMousePosit.y <= 400)
            {        
                    BODY_PART_SELECTION = 1;
                    leftArmSelection = 9;
            }         
            if(ptCurrentMousePosit.x >= 1180 && ptCurrentMousePosit.x <= 1280 && ptCurrentMousePosit.y >= 400 && ptCurrentMousePosit.y <= 500)
            {        
                    BODY_PART_SELECTION = 1;
                    leftArmSelection = 0;
            }          
            //----------------------------------------------------------------------------------------------------------        
            if(ptCurrentMousePosit.x >= 1080 && ptCurrentMousePosit.x <= 1180 && ptCurrentMousePosit.y >= 200 && ptCurrentMousePosit.y <= 300)
            {        
                    BODY_PART_SELECTION = 2;
                    rightArmSelection = 8;
            }        
            if(ptCurrentMousePosit.x >= 1080 && ptCurrentMousePosit.x <= 1180 && ptCurrentMousePosit.y >= 300 && ptCurrentMousePosit.y <= 400)
            {        
                    BODY_PART_SELECTION = 2;
                    rightArmSelection = 9;
            }         
            if(ptCurrentMousePosit.x >= 1080 && ptCurrentMousePosit.x <= 1180 && ptCurrentMousePosit.y >= 400 && ptCurrentMousePosit.y <= 500)
            {        
                    BODY_PART_SELECTION = 2;
                    rightArmSelection = 0;
            }         
            //----------------------------------------------------------------------------------------------------------        
            if(ptCurrentMousePosit.x >= 980 && ptCurrentMousePosit.x <= 1080 && ptCurrentMousePosit.y >= 200 && ptCurrentMousePosit.y <= 300)
            {        
                    BODY_PART_SELECTION = 3;
                    leftLegSelection = 8;
            }        
            if(ptCurrentMousePosit.x >= 980 && ptCurrentMousePosit.x <= 1080 && ptCurrentMousePosit.y >= 300 && ptCurrentMousePosit.y <= 400)
            {        
                    BODY_PART_SELECTION = 3;
                    leftLegSelection = 9;
            }         
            if(ptCurrentMousePosit.x >= 980 && ptCurrentMousePosit.x <= 1080 && ptCurrentMousePosit.y >= 400 && ptCurrentMousePosit.y <= 500)
            {        
                    BODY_PART_SELECTION = 3;
                    leftLegSelection = 0;
            }               
            //----------------------------------------------------------------------------------------------------------        
            if(ptCurrentMousePosit.x >= 880 && ptCurrentMousePosit.x <= 980 && ptCurrentMousePosit.y >= 200 && ptCurrentMousePosit.y <= 300)
            {        
                    BODY_PART_SELECTION = 4;
                    rightLegSelection = 8;
            }        
            if(ptCurrentMousePosit.x >= 880 && ptCurrentMousePosit.x <= 980 && ptCurrentMousePosit.y >= 300 && ptCurrentMousePosit.y <= 400)
            {        
                    BODY_PART_SELECTION = 4;
                    rightLegSelection = 9;
            }         
            if(ptCurrentMousePosit.x >= 880 && ptCurrentMousePosit.x <= 980 && ptCurrentMousePosit.y >= 400 && ptCurrentMousePosit.y <= 500)
            {        
                    BODY_PART_SELECTION = 4;
                    rightLegSelection = 0;
            }             
            //----------------------------------------------------------------------------------------------------------        
 
                    
            //----------------------------------------------------------------------------------------------------------            
        }break; 
		    
        case WM_LBUTTONUP:
		{
			leftMouseActivated = false;
		}break;
        case WM_RBUTTONUP:
		{
			rightMouseActivated = false;
		}break;        

        
        case WM_MOUSEMOVE:
		{
			ptCurrentMousePosit.x = LOWORD (lParam);
			ptCurrentMousePosit.y = HIWORD (lParam);
			
            mousePositionX = ptCurrentMousePosit.x;
			mousePositionY = ptCurrentMousePosit.y;

      
            if( leftMouseActivated )
			{
			   
               if(BODY_PART_SELECTION == 1) 
               {     
                     
                    
                     
                     
                     if(leftArmSelection == 8)
                     {
                            leftUpperArm_ROTATE[3] +=  ((ptCurrentMousePosit.y - ptLastMousePosit.y));
                         
                         if(leftUpperArm_ROTATE_X)
                            leftUpperArm_ROTATE[0] +=  ((ptCurrentMousePosit.x - ptLastMousePosit.x))*.01; 
                         if(leftUpperArm_ROTATE_Y)
                            leftUpperArm_ROTATE[1] +=  ((ptCurrentMousePosit.x - ptLastMousePosit.x))*.01;                     
                         if(leftUpperArm_ROTATE_Z)
                            leftUpperArm_ROTATE[2] +=  ((ptCurrentMousePosit.x - ptLastMousePosit.x))*.01;                     
                     
                     }
                     if(leftArmSelection == 9)
                     {
                            leftForeArm_ROTATE[3] +=  ((ptCurrentMousePosit.y - ptLastMousePosit.y));
                         
                         if(leftForeArm_ROTATE_X)
                            leftForeArm_ROTATE[0] +=  ((ptCurrentMousePosit.x - ptLastMousePosit.x))*.01; 
                         if(leftForeArm_ROTATE_Y)
                            leftForeArm_ROTATE[1] +=  ((ptCurrentMousePosit.x - ptLastMousePosit.x))*.01;                     
                         if(leftForeArm_ROTATE_Z)
                            leftForeArm_ROTATE[2] +=  ((ptCurrentMousePosit.x - ptLastMousePosit.x))*.01; 
                     }               
                     
                     if(leftArmSelection == 0)
                     {
                            leftHand_ROTATE[3] +=  ((ptCurrentMousePosit.y - ptLastMousePosit.y));
                         
                         if(leftHand_ROTATE_X)
                            leftHand_ROTATE[0] +=  ((ptCurrentMousePosit.x - ptLastMousePosit.x))*.01; 
                         if(leftHand_ROTATE_Y)
                            leftHand_ROTATE[1] +=  ((ptCurrentMousePosit.x - ptLastMousePosit.x))*.01;                     
                         if(leftHand_ROTATE_Z)
                            leftHand_ROTATE[2] +=  ((ptCurrentMousePosit.x - ptLastMousePosit.x))*.01;
                     }               
               }
               
               if(BODY_PART_SELECTION == 2) 
               {     
                     if(rightArmSelection == 8)
                     {
                             rightUpperArm_ROTATE[3] +=  ((ptCurrentMousePosit.y - ptLastMousePosit.y));
                         
                         if( rightUpperArm_ROTATE_X)
                             rightUpperArm_ROTATE[0] +=  ((ptCurrentMousePosit.x - ptLastMousePosit.x))*.01; 
                         if( rightUpperArm_ROTATE_Y)
                             rightUpperArm_ROTATE[1] +=  ((ptCurrentMousePosit.x - ptLastMousePosit.x))*.01;                     
                         if( rightUpperArm_ROTATE_Z)
                             rightUpperArm_ROTATE[2] +=  ((ptCurrentMousePosit.x - ptLastMousePosit.x))*.01;                     
                     
                     }
                     if(rightArmSelection == 9)
                     {
                            rightForeArm_ROTATE[3] +=  ((ptCurrentMousePosit.y - ptLastMousePosit.y));
                         
                         if(rightForeArm_ROTATE_X)
                            rightForeArm_ROTATE[0] +=  ((ptCurrentMousePosit.x - ptLastMousePosit.x))*.01; 
                         if(rightForeArm_ROTATE_Y)
                            rightForeArm_ROTATE[1] +=  ((ptCurrentMousePosit.x - ptLastMousePosit.x))*.01;                     
                         if(rightForeArm_ROTATE_Z)
                            rightForeArm_ROTATE[2] +=  ((ptCurrentMousePosit.x - ptLastMousePosit.x))*.01; 
                     }               
                     
                     if(rightArmSelection == 0)
                     {
                            rightHand_ROTATE[3] +=  ((ptCurrentMousePosit.y - ptLastMousePosit.y));
                         
                         if(rightHand_ROTATE_X)
                            rightHand_ROTATE[0] +=  ((ptCurrentMousePosit.x - ptLastMousePosit.x))*.01; 
                         if(rightHand_ROTATE_Y)
                            rightHand_ROTATE[1] +=  ((ptCurrentMousePosit.x - ptLastMousePosit.x))*.01;                     
                         if(rightHand_ROTATE_Z)
                            rightHand_ROTATE[2] +=  ((ptCurrentMousePosit.x - ptLastMousePosit.x))*.01;
                     } 
                  
               }               
                
               if(BODY_PART_SELECTION == 3) 
               {     
                     if(leftLegSelection == 8)
                     {
                             leftUpperLeg_ROTATE[3] +=  ((ptCurrentMousePosit.y - ptLastMousePosit.y));
                         
                         if( leftUpperLeg_ROTATE_X)
                             leftUpperLeg_ROTATE[0] +=  ((ptCurrentMousePosit.x - ptLastMousePosit.x))*.01; 
                         if( leftUpperLeg_ROTATE_Y)
                             leftUpperLeg_ROTATE[1] +=  ((ptCurrentMousePosit.x - ptLastMousePosit.x))*.01;                     
                         if( leftUpperLeg_ROTATE_Z)
                             leftUpperLeg_ROTATE[2] +=  ((ptCurrentMousePosit.x - ptLastMousePosit.x))*.01;                     
                     
                     }
                     if(leftLegSelection == 9)
                     {
                            leftLowerLeg_ROTATE[3] +=  ((ptCurrentMousePosit.y - ptLastMousePosit.y));
                         
                         if(leftLowerLeg_ROTATE_X)
                            leftLowerLeg_ROTATE[0] +=  ((ptCurrentMousePosit.x - ptLastMousePosit.x))*.01; 
                         if(leftLowerLeg_ROTATE_Y)
                            leftLowerLeg_ROTATE[1] +=  ((ptCurrentMousePosit.x - ptLastMousePosit.x))*.01;                     
                         if(leftLowerLeg_ROTATE_Z)
                            leftLowerLeg_ROTATE[2] +=  ((ptCurrentMousePosit.x - ptLastMousePosit.x))*.01; 
                     }               
                     
                     if(leftLegSelection == 0)
                     {
                            leftFoot_ROTATE[3] +=  ((ptCurrentMousePosit.y - ptLastMousePosit.y));
                         
                         if(leftFoot_ROTATE_X)
                            leftFoot_ROTATE[0] +=  ((ptCurrentMousePosit.x - ptLastMousePosit.x))*.01; 
                         if(leftFoot_ROTATE_Y)
                            leftFoot_ROTATE[1] +=  ((ptCurrentMousePosit.x - ptLastMousePosit.x))*.01;                     
                         if(leftFoot_ROTATE_Z)
                            leftFoot_ROTATE[2] +=  ((ptCurrentMousePosit.x - ptLastMousePosit.x))*.01;
                     } 
                  
               } 
               if(BODY_PART_SELECTION == 4) 
               {     
                     if(rightLegSelection == 8)
                     {
                             rightUpperLeg_ROTATE[3] +=  ((ptCurrentMousePosit.y - ptLastMousePosit.y));
                         
                         if( rightUpperLeg_ROTATE_X)
                             rightUpperLeg_ROTATE[0] +=  ((ptCurrentMousePosit.x - ptLastMousePosit.x))*.01; 
                         if( rightUpperLeg_ROTATE_Y)
                             rightUpperLeg_ROTATE[1] +=  ((ptCurrentMousePosit.x - ptLastMousePosit.x))*.01;                     
                         if( rightUpperLeg_ROTATE_Z)
                             rightUpperLeg_ROTATE[2] +=  ((ptCurrentMousePosit.x - ptLastMousePosit.x))*.01;                     
                     
                     }
                     if(rightLegSelection == 9)
                     {
                            rightLowerLeg_ROTATE[3] +=  ((ptCurrentMousePosit.y - ptLastMousePosit.y));
                         
                         if(rightLowerLeg_ROTATE_X)
                            rightLowerLeg_ROTATE[0] +=  ((ptCurrentMousePosit.x - ptLastMousePosit.x))*.01; 
                         if(rightLowerLeg_ROTATE_Y)
                            rightLowerLeg_ROTATE[1] +=  ((ptCurrentMousePosit.x - ptLastMousePosit.x))*.01;                     
                         if(rightLowerLeg_ROTATE_Z)
                            rightLowerLeg_ROTATE[2] +=  ((ptCurrentMousePosit.x - ptLastMousePosit.x))*.01; 
                     }               
                     
                     if(rightLegSelection == 0)
                     {
                            rightFoot_ROTATE[3] +=  ((ptCurrentMousePosit.y - ptLastMousePosit.y));
                         
                         if(rightFoot_ROTATE_X)
                            rightFoot_ROTATE[0] +=  ((ptCurrentMousePosit.x - ptLastMousePosit.x))*.01; 
                         if(rightFoot_ROTATE_Y)
                            rightFoot_ROTATE[1] +=  ((ptCurrentMousePosit.x - ptLastMousePosit.x))*.01;                     
                         if(rightFoot_ROTATE_Z)
                            rightFoot_ROTATE[2] +=  ((ptCurrentMousePosit.x - ptLastMousePosit.x))*.01;
                     } 
                  
               }			
               
               if(BODY_PART_SELECTION == 5) 
               {     
                             hips_ROTATE[3] +=  ((ptCurrentMousePosit.y - ptLastMousePosit.y));
                         
                         if( hips_ROTATE_X)
                             hips_ROTATE[0] +=  ((ptCurrentMousePosit.x - ptLastMousePosit.x))*.01; 
                         if( hips_ROTATE_Y)
                             hips_ROTATE[1] +=  ((ptCurrentMousePosit.x - ptLastMousePosit.x))*.01;                     
                         if( hips_ROTATE_Z)
                             hips_ROTATE[2] +=  ((ptCurrentMousePosit.x - ptLastMousePosit.x))*.01;                     
               }            
               
               if(BODY_PART_SELECTION == 6) 
               {     
                             torso_ROTATE[3] +=  ((ptCurrentMousePosit.y - ptLastMousePosit.y));
                         
                         if( torso_ROTATE_X)
                             torso_ROTATE[0] +=  ((ptCurrentMousePosit.x - ptLastMousePosit.x))*.01; 
                         if( torso_ROTATE_Y)
                             torso_ROTATE[1] +=  ((ptCurrentMousePosit.x - ptLastMousePosit.x))*.01;                     
                         if( torso_ROTATE_Z)
                             torso_ROTATE[2] +=  ((ptCurrentMousePosit.x - ptLastMousePosit.x))*.01;                     
               }            
               
               if(BODY_PART_SELECTION == 7) 
               {     
                             head_ROTATE[3] +=  ((ptCurrentMousePosit.y - ptLastMousePosit.y));
                         
                         if( head_ROTATE_X)
                             head_ROTATE[0] +=  ((ptCurrentMousePosit.x - ptLastMousePosit.x))*.01; 
                         if( head_ROTATE_Y)
                             head_ROTATE[1] +=  ((ptCurrentMousePosit.x - ptLastMousePosit.x))*.01;                     
                         if( head_ROTATE_Z)
                             head_ROTATE[2] +=  ((ptCurrentMousePosit.x - ptLastMousePosit.x))*.01;                     
               }            
            
            
            
            }//_END__if(leftMouseActivated)
			
			
            if(rightMouseActivated)
			{
			     
                       look_LEFT_RIGHT  +=  ((ptCurrentMousePosit.x - ptLastMousePosit.x));
                       look_UP_DOWN     +=  ((ptCurrentMousePosit.y - ptLastMousePosit.y));
                  
            }//_END__if(rightMouseActivated)  
            
            ptLastMousePosit.x = ptCurrentMousePosit.x;
            ptLastMousePosit.y = ptCurrentMousePosit.y;
		}
		break;
		
		case WM_SIZE:
		{
			int nWidth  = LOWORD(lParam); 
			int nHeight = HIWORD(lParam);
			glViewport(0, 0, nWidth, nHeight);

                  glMatrixMode( GL_PROJECTION );
                  glLoadIdentity();
                  gluPerspective( 45.24, (GLdouble)nWidth / (GLdouble)nHeight, 0.1, 1000);

        screenWidth  = nWidth;
        screenHeight = nHeight;
        
        }
		break;

		case WM_CLOSE:
		{
			PostQuitMessage(0);	
		}

        case WM_DESTROY:
		{
            PostQuitMessage(0);
		}
        break;
		
		default:
		{
			return DefWindowProc( hWnd, msg, wParam, lParam );
		}
		break;
	}

	return 0;
}




