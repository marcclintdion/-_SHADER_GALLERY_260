                                                                                                                                             
    glBindBuffer(GL_ARRAY_BUFFER, diamond_VBO);   
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, diamond_INDEX_VBO);                                                                                                                               
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__MODEL             
/*                                                                     
    MultiplyMatrix(mvpMatrix, projection, modelView);                                                                                                                         
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__LIGHT             
    LoadIdentity(lightMatrix1);                                                                                                                                                
    InvertMatrix(lightMatrix1, modelView);                                                                                                                                     
    //Translate(lightMatrix1, 1.0, -10.0, 2.0);                                                                                                                                
    Rotate(lightMatrix1,0.0, 1.0, 0.0,  look_LEFT_RIGHT);                                                                                                                         
    Rotate(lightMatrix1,1.0, 0.0, 0.0,  -look_UP_DOWN);                                                                                                                      
*/    //======================================================================================================                                                                  
    SelectShader(shaderNumber);                                                                                                                                
    //======================================================================================================                                                                  
    glActiveTexture ( GL_TEXTURE1 );                                                                                                                                          
    glBindTexture(GL_TEXTURE_2D, diamond_NORMALMAP);                                                                                                                          
    //---                                                                                                                                                                     
    glActiveTexture (GL_TEXTURE0);                                                                                                                                            
    glBindTexture(GL_TEXTURE_2D, diamond_TEXTUREMAP);                                                                                                                            
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__DRAW              
    glDrawElements(GL_TRIANGLES, 384, GL_UNSIGNED_INT, 0);
