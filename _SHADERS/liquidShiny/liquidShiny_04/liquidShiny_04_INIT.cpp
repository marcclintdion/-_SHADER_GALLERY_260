    #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      liquidShiny_04_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_liquidShiny_04 =                                                                                                        

      "    #define highp                                                                                       \n"                           
      
      "    uniform highp vec4   light_POSITION_01;                                                             \n"                           
      "    uniform       mat4   mvpMatrix;                                                                     \n"                           
      "    uniform       mat4   lightMatrix;                                                                   \n"                           

      "    attribute     vec4   position;                                                                      \n"                           
      "    attribute     vec2   texture;                                                                       \n"                           

      "    varying highp vec4   lightPosition_PASS;                                                            \n"                           
      "    varying highp vec2   varTexcoord;                                                                   \n" 



      "    void main()                                                                                         \n"                           
      "    {                                                                                                   \n"                           

                         
      "        lightPosition_PASS    = normalize(lightMatrix * light_POSITION_01);                             \n"                           
      "        varTexcoord           = texture;                                                                \n"                           
      "        gl_Position           = mvpMatrix * position;                                                   \n" 
     
     "    }\n";                                                                                                                             
      //---------------------------------------------------------------------                                                                   
      liquidShiny_04_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(liquidShiny_04_SHADER_VERTEX, 1, &vertexSource_liquidShiny_04, NULL);                                                                        
      glCompileShader(liquidShiny_04_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_liquidShiny_04 =                                                                                                            

     
      " #ifdef GL_ES                                                                                                     \n"                       
      " #else                                                                                                            \n"                       
      " #define highp                                                                                                    \n"                       
      " #endif                                                                                                           \n"                     
     
      "    uniform sampler2D     Texture1;                                                                               \n"                       
      "    uniform sampler2D     NormalMap;                                                                              \n"                       
      "    uniform highp float   shininess;                                                                              \n"                       
      "    uniform highp float   attenuation;                                                                            \n"                       

      "    varying highp vec4    lightPosition_PASS;                                                                     \n"                       
      "    varying highp vec2    varTexcoord;                                                                            \n"                       

      "            highp float   NdotL1;                                                                                 \n"                       
      "            highp vec3    normal;                                                                                 \n"                       
      "            highp vec3    NormalTex;                                                                              \n"  
      
      "            highp float   shiny;                                                                                  \n"  
      "            highp vec4    ka      = highp vec4(0.9, 0.6, 0.7, 1.0);                                               \n"  
      "            highp vec4    color;                                                                                  \n"  
      
      
      "     void main()                                                                                                  \n"                       
      "     {                                                                                                            \n"                       
      "         NormalTex             =  texture2D(NormalMap,  varTexcoord).xyz;                                         \n"                       
      "         NormalTex             = (NormalTex - 0.5);                                                               \n"                       
      "         normal                =  normalize(NormalTex) / texture2D(Texture1, varTexcoord.st).w;                                                           \n"                       
      "         NdotL1                =  dot(normal, lightPosition_PASS.xyz);                                            \n"              

      "         shiny                 = pow(NdotL1, shininess * 0.01)*.3;                                   \n" 
      "         shiny                += pow(NdotL1, shininess * 0.1) * 1.0;                            \n" 
      "         shiny                += pow(NdotL1, shininess * 4.1) * 15.0 ;                            \n"            
      "         color                 = ka * shiny;                                                                      \n" 
            
      "         gl_FragColor          = (texture2D(Texture1, varTexcoord.st) * (color * NdotL1) + (ka * NdotL1 * .1))* attenuation;                                           \n" 

      "}\n";                                                                                                                                   

      //---------------------------------------------------------------------                                                                         
      liquidShiny_04_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(liquidShiny_04_SHADER_FRAGMENT, 1, &fragmentSource_liquidShiny_04, NULL);                                                                          
      glCompileShader(liquidShiny_04_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(liquidShiny_04_SHADER, liquidShiny_04_SHADER_VERTEX);                                                                                              
      glAttachShader(liquidShiny_04_SHADER, liquidShiny_04_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(liquidShiny_04_SHADER,    0, "position");                                                                                            
      glBindAttribLocation(liquidShiny_04_SHADER,    1, "normal");       
      glBindAttribLocation(liquidShiny_04_SHADER,    2, "texture");                                                                                            
      //------------------------------------------------                                                                                              
      glLinkProgram(liquidShiny_04_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(liquidShiny_04_SHADER, liquidShiny_04_SHADER_VERTEX);                                                                                              
      glDetachShader(liquidShiny_04_SHADER, liquidShiny_04_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(liquidShiny_04_SHADER_VERTEX);                                                                                                            
      glDeleteShader(liquidShiny_04_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      UNIFORM_MODELVIEWPROJ_liquidShiny_04                   = glGetUniformLocation(liquidShiny_04_SHADER,   "mvpMatrix");                                              
      UNIFORM_LIGHT_MATRIX_liquidShiny_04                    = glGetUniformLocation(liquidShiny_04_SHADER,   "lightMatrix");                                            
      UNIFORM_LIGHT_POSITION_01_liquidShiny_04               = glGetUniformLocation(liquidShiny_04_SHADER,   "light_POSITION_01");                                      
      UNIFORM_SHININESS_liquidShiny_04                       = glGetUniformLocation(liquidShiny_04_SHADER,   "shininess");                                              
      UNIFORM_ATTENUATION_liquidShiny_04                     = glGetUniformLocation(liquidShiny_04_SHADER,   "attenuation");                                              
      UNIFORM_TEXTURE_DOT3_liquidShiny_04                    = glGetUniformLocation(liquidShiny_04_SHADER,   "NormalMap");                                              
      UNIFORM_TEXTURE_liquidShiny_04                         = glGetUniformLocation(liquidShiny_04_SHADER,   "Texture1");                                   
