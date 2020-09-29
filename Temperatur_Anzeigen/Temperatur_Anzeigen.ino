#define Zeit 50

int sensorPin = A0;
int DataEiner[4] =  {6,7,8,9}; 
int DataZweier[4] = {10,11,12,13};
int DataDreier[4] = {2,3,4,5};

void setup(){

             for(int index = 0; index <= 3; index++){                                                             
                 pinMode(DataEiner[index],OUTPUT);                          
                 } 
             for(int index1 = 0; index1 <= 3; index1++){                                                             
                 pinMode(DataZweier[index1],OUTPUT);                          
                 }  
             for(int index2 = 0; index2 <= 3; index2++){                                                             
                 pinMode(DataDreier[index2],OUTPUT);                          
                 }  
                 
Serial.begin(9600);

}

void loop(){
  
  int sensorVal = analogRead(sensorPin);
  float voltage = (sensorVal/1024.0)*5;
 
Serial.print("Temperatur: ");

 float temperature = (voltage - .5)*100;

// Berechnungen

 int Einer = temperature / 10;
 int Zweier1 = temperature;
 int Zweier = Zweier1 %10;
 int Dreier1 = temperature*10;
 int Dreier = Dreier1 %10;

Serial.print(temperature,1);
Serial.print(", Einer: ");
Serial.print(Einer);
Serial.print(", Zweier: ");
Serial.print(Zweier);
Serial.print(", Dreier: ");
Serial.println(Dreier);

  
  switch (Einer){          
                 case 0:                                          
                        digitalWrite(DataEiner[0],LOW);              
                        digitalWrite(DataEiner[1],LOW);                
                        digitalWrite(DataEiner[2],LOW);                
                        digitalWrite(DataEiner[3],LOW); 
                        break;   
                        
                 case 1:                                         
                        digitalWrite(DataEiner[0],HIGH);              
                        digitalWrite(DataEiner[1],LOW);                
                        digitalWrite(DataEiner[2],LOW);                
                        digitalWrite(DataEiner[3],LOW); 
                        break;                                    
                                                                           
                 case 2:                                         
                        digitalWrite(DataEiner[0],LOW);              
                        digitalWrite(DataEiner[1],HIGH);             
                        digitalWrite(DataEiner[2],LOW);              
                        digitalWrite(DataEiner[3],LOW);                
                        break;                                  
                                                                           
                 case 3:                                        
                        digitalWrite(DataEiner[0],HIGH);             
                        digitalWrite(DataEiner[1],HIGH);             
                        digitalWrite(DataEiner[2],LOW);              
                        digitalWrite(DataEiner[3],LOW);              
                        break;                                  
                                                                           
                 case 4:                                       
                        digitalWrite(DataEiner[0],LOW);              
                        digitalWrite(DataEiner[1],LOW);              
                        digitalWrite(DataEiner[2],HIGH);             
                        digitalWrite(DataEiner[3],LOW);                
                        break;                                 
               }    

switch (Zweier){        
                 case 0:                                         
                        digitalWrite(DataZweier[0],LOW);              
                        digitalWrite(DataZweier[1],LOW);              
                        digitalWrite(DataZweier[2],LOW);               
                        digitalWrite(DataZweier[3],LOW); 
                        break; 
                        
                 case 1:                                         
                        digitalWrite(DataZweier[0],HIGH);              
                        digitalWrite(DataZweier[1],LOW);               
                        digitalWrite(DataZweier[2],LOW);               
                        digitalWrite(DataZweier[3],LOW);                
                        break;                                   
                                                                           
                 case 2:                                         
                        digitalWrite(DataZweier[0],LOW);              
                        digitalWrite(DataZweier[1],HIGH);             
                        digitalWrite(DataZweier[2],LOW);              
                        digitalWrite(DataZweier[3],LOW);                 
                        break;                                 
                                                                           
                 case 3:                                        
                        digitalWrite(DataZweier[0],HIGH);             
                        digitalWrite(DataZweier[1],HIGH);             
                        digitalWrite(DataZweier[2],LOW);              
                        digitalWrite(DataZweier[3],LOW);               
                        break;                                 
                                                                           
                 case 4:                                       
                        digitalWrite(DataZweier[0],LOW);              
                        digitalWrite(DataZweier[1],LOW);              
                        digitalWrite(DataZweier[2],HIGH);             
                        digitalWrite(DataZweier[3],LOW);                
                        break;   
                                                       
                 case 5:                                       
                        digitalWrite(DataZweier[0],HIGH);             
                        digitalWrite(DataZweier[1],LOW);              
                        digitalWrite(DataZweier[2],HIGH);              
                        digitalWrite(DataZweier[3],LOW);               
                        break;    
                                                                  
                 case 6:                                      
                        digitalWrite(DataZweier[0],LOW);              
                        digitalWrite(DataZweier[1],HIGH);              
                        digitalWrite(DataZweier[2],HIGH);             
                        digitalWrite(DataZweier[3],LOW);                 
                        break; 
                              
                 case 7:                                       
                        digitalWrite(DataZweier[0],HIGH);              
                        digitalWrite(DataZweier[1],HIGH);              
                        digitalWrite(DataZweier[2],HIGH);             
                        digitalWrite(DataZweier[3],LOW);                
                        break; 

                 case 8:                                        
                        digitalWrite(DataZweier[0],LOW);              
                        digitalWrite(DataZweier[1],LOW);               
                        digitalWrite(DataZweier[2],LOW);             
                        digitalWrite(DataZweier[3],HIGH);                
                        break;
                                   
                 case 9:        
                        digitalWrite(DataZweier[0],HIGH);              
                        digitalWrite(DataZweier[1],LOW);              
                        digitalWrite(DataZweier[2],LOW);             
                        digitalWrite(DataZweier[3],HIGH);              
                        break;  

               }
               
switch (Dreier){        
                 case 0:                                         
                        digitalWrite(DataDreier[0],LOW);              
                        digitalWrite(DataDreier[1],LOW);              
                        digitalWrite(DataDreier[2],LOW);               
                        digitalWrite(DataDreier[3],LOW); 
                        break; 
                        
                 case 1:                                         
                        digitalWrite(DataDreier[0],HIGH);              
                        digitalWrite(DataDreier[1],LOW);               
                        digitalWrite(DataDreier[2],LOW);               
                        digitalWrite(DataDreier[3],LOW);                
                        break;                                   
                                                                           
                 case 2:                                         
                        digitalWrite(DataDreier[0],LOW);              
                        digitalWrite(DataDreier[1],HIGH);             
                        digitalWrite(DataDreier[2],LOW);              
                        digitalWrite(DataDreier[3],LOW);                 
                        break;                                 
                                                                           
                 case 3:                                        
                        digitalWrite(DataDreier[0],HIGH);             
                        digitalWrite(DataDreier[1],HIGH);             
                        digitalWrite(DataDreier[2],LOW);              
                        digitalWrite(DataDreier[3],LOW);               
                        break;                                 
                                                                           
                 case 4:                                       
                        digitalWrite(DataDreier[0],LOW);              
                        digitalWrite(DataDreier[1],LOW);              
                        digitalWrite(DataDreier[2],HIGH);             
                        digitalWrite(DataDreier[3],LOW);                
                        break;   
                                                       
                 case 5:                                       
                        digitalWrite(DataDreier[0],HIGH);             
                        digitalWrite(DataDreier[1],LOW);              
                        digitalWrite(DataDreier[2],HIGH);              
                        digitalWrite(DataDreier[3],LOW);               
                        break;    
                                                                  
                 case 6:                                      
                        digitalWrite(DataDreier[0],LOW);              
                        digitalWrite(DataDreier[1],HIGH);              
                        digitalWrite(DataDreier[2],HIGH);             
                        digitalWrite(DataDreier[3],LOW);                 
                        break; 
                              
                 case 7:                                       
                        digitalWrite(DataDreier[0],HIGH);              
                        digitalWrite(DataDreier[1],HIGH);              
                        digitalWrite(DataDreier[2],HIGH);             
                        digitalWrite(DataDreier[3],LOW);                
                        break; 

                 case 8:                                        
                        digitalWrite(DataDreier[0],LOW);              
                        digitalWrite(DataDreier[1],LOW);               
                        digitalWrite(DataDreier[2],LOW);             
                        digitalWrite(DataDreier[3],HIGH);                
                        break;
                                   
                 case 9:        
                        digitalWrite(DataDreier[0],HIGH);              
                        digitalWrite(DataDreier[1],LOW);              
                        digitalWrite(DataDreier[2],LOW);             
                        digitalWrite(DataDreier[3],HIGH);              
                        break;  

               }
}



