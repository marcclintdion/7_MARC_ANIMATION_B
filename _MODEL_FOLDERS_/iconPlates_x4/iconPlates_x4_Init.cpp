      #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      iconPlates_x4_SHADER = glCreateProgram();                                                                                                  
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource =                                                                                                              
      "    #define highp                                                                                            "                       
      "    uniform highp vec4 light_POSITION_01;                                                                    "                       
      "    uniform         mat4 modelViewProjectionMatrix;                                                          "                       
      "    uniform         mat4 lightMatrix;                                                                        "                       
      "    attribute       vec4 position;                                                                           "                       
      "    attribute       vec2 texture;                                                                            "                       
      "    varying highp vec4 lightPosition_PASS;                                                                   "                       
      "    varying highp vec2 varTexcoord;                                                                          "                       
      "    void main()                                                                                              "                       
      "    {                                                                                                        "                       
      "        lightPosition_PASS = normalize(lightMatrix * light_POSITION_01);                                     "                       
      "        varTexcoord        = texture;                                                                        "                       
      "        gl_Position        = modelViewProjectionMatrix * position;                                           "                       
      "}\n";                 
      //---------------------------------------------------------------------                                                                   
      iconPlates_x4_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                            
      glShaderSource(iconPlates_x4_SHADER_VERTEX, 1, &vertexSource, NULL);                                                                       
      glCompileShader(iconPlates_x4_SHADER_VERTEX);                                                                                              
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource =                                                                                                            
      " #ifdef GL_ES                                                                                                "                       
      " #else                                                                                                       "                       
      " #define highp                                                                                               "                       
      " #endif                                                                                                      "                       
      "    uniform sampler2D  Texture1;                                                                             "                       
      "    uniform sampler2D  NormalMap;                                                                            "                       
      "    varying highp vec4  lightPosition_PASS;                                                                  "                       
      "    varying highp vec2  varTexcoord;                                                                         "                       
      "     highp float NdotL1;                                                                                     "                       
      "     highp vec3  normal;                                                                                     "                       
      "     void main()                                                                                             "                       
      "     {                                                                                                       "                       
      "         highp vec3 NormalTex   =  texture2D(NormalMap,  varTexcoord).xyz;                                   "                       
      "         NormalTex             = (NormalTex - 0.5);                                                          "                       
      "         normal                =  normalize(NormalTex);                                                      "                       
      "         normal                =  normal.rgb;                                                                "                       
      "         NdotL1                =  dot(normal, lightPosition_PASS.xyz);                                       "                       
      "         gl_FragColor          =  texture2D(Texture1, varTexcoord.st, 0.0)  * .2                             "                       
      "                               +  texture2D(Texture1, varTexcoord.st, 0.0) * NdotL1 * NdotL1* NdotL1         "                       
      "                               +  texture2D(Texture1, varTexcoord.st, 0.0) * pow(NdotL1, 80.0)*.6 ;          "                       
      "}\n";                    
      //---------------------------------------------------------------------                                                                   
      iconPlates_x4_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                        
      glShaderSource(iconPlates_x4_SHADER_FRAGMENT, 1, &fragmentSource, NULL);                                                                   
      glCompileShader(iconPlates_x4_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                        
      glAttachShader(iconPlates_x4_SHADER, iconPlates_x4_SHADER_VERTEX);                                                                          
      glAttachShader(iconPlates_x4_SHADER, iconPlates_x4_SHADER_FRAGMENT);                                                                        
      //------------------------------------------------                                                                                        
      glBindAttribLocation(iconPlates_x4_SHADER, 0, "position");                                                                               
      glBindAttribLocation(iconPlates_x4_SHADER, 1, "texture");                                                                                
      //glBindAttribLocation(iconPlates_x4 _SHADER, 2, "normal");                                                                              
      //------------------------------------------------                                                                                        
      glLinkProgram(iconPlates_x4_SHADER);                                                                                                       
      //------------------------------------------------                                                                                        
      #ifdef __APPLE__                                                                                                                          
      glDetachShader(iconPlates_x4_SHADER, iconPlates_x4_SHADER_VERTEX);                                                                          
      glDetachShader(iconPlates_x4_SHADER, iconPlates_x4_SHADER_FRAGMENT);                                                                        
      #endif                                                                                                                                    
      //------------------------------------------------                                                                                        
      glDeleteShader(iconPlates_x4_SHADER_VERTEX);                                                                                               
      glDeleteShader(iconPlates_x4_SHADER_FRAGMENT);                                                                                             
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS          
      UNIFORM_MODELVIEWPROJ                   = glGetUniformLocation(iconPlates_x4_SHADER, "modelViewProjectionMatrix");                       
      UNIFORM_LIGHT_MATRIX                    = glGetUniformLocation(iconPlates_x4_SHADER, "lightMatrix");                                     
      //UNIFORM_NORMAL_iconPlates_x4LeftUpperArm       = glGetUniformLocation(iconPlates_x4 _SHADER, "normalMatrix");                           
      UNIFORM_LIGHT_POSITION_01_iconPlates_x4          = glGetUniformLocation(iconPlates_x4_SHADER, "light_POSITION_01");                       
      UNIFORM_TEXTURE_DOT3_iconPlates_x4                    = glGetUniformLocation(iconPlates_x4_SHADER, "NormalMap");                                       
      UNIFORM_TEXTURE_iconPlates_x4                         = glGetUniformLocation(iconPlates_x4_SHADER, "Texture1");                                        
      //------------------------------------------------------------------------------------------------------------//___LOAD_TEXTURES          
      //------------------------------------------------------------------------------------------                                              
      #ifdef __APPLE__                                                                                                                          
      filePathName = [[NSBundle mainBundle] pathForResource:@"iconPlates_x4_DOT3" ofType:@"bmp"];                                            
      image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding], false);                                                   
      glGenTextures(1, &iconPlates_x4_NORMAL_TEX);                                                                                                
      glBindTexture(GL_TEXTURE_2D, iconPlates_x4_NORMAL_TEX);                                                                                     
      ConfigureAndLoadTexture(image->data,  image->width, image->height );                                                                      
      imgDestroyImage(image);                                                                                                                   
      //---------------------                                                                                                                   
      filePathName = [[NSBundle mainBundle] pathForResource:@"armsBendBackLowForward" ofType:@"png"];                                                 
      image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding], false);                                                   
      glGenTextures(1, &iconPlates_x4_TEXTURE1);                                                                                               
      glBindTexture(GL_TEXTURE_2D, iconPlates_x4_TEXTURE1);                                                                                    
      ConfigureAndLoadTexture(image->data,  image->width, image->height );                                                                      
      imgDestroyImage(image);                                                                                                                   
      #endif                                                                                                                                    
      //------------------------------------------------------------------------------------------                                              
      #ifdef _WIN32_                                                                                                                            
      loadTexture("iconPlates_x4_DOT3.bmp",          iconPlates_x4_NORMAL_TEX);                                                     
      loadTexture("iconPlates_x4.png",               iconPlates_x4_TEXTURE1);                                                    
      #endif                                                                                                                                    
      //------------------------------------------------------------------------------------------------------------//___LOAD_VBO               
      #include    "iconPlates_x4.cpp"                                                                                             
      glGenBuffers(1,              &iconPlates_x4_VBO);                                                                                          
      glBindBuffer(GL_ARRAY_BUFFER, iconPlates_x4_VBO);                                                                                          
      glBufferData(GL_ARRAY_BUFFER, sizeof(iconPlates_x4), iconPlates_x4, GL_STATIC_DRAW);                                                        
      glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                         
      //=================================================================================================================================       

