/*
 0--> avanti
 1--> indietro
 2--> destra
 3-->sinistra
 */

//costanti per l'inizzializzazione dei pin per controllare i motori
const int rotOraria_M1 = 8; 
const int rotAntioraria_M1 = 13;
const int pinEnable_M1 = 10; 
const int rotOraria_M2 = 2; 
const int rotAntioraria_M2 = 3;
const int pinEnable_M2 = 9; 
const int rotOraria_M3 = 4; 
const int rotAntioraria_M3 = 5;
const int pinEnable_M3 = 11; 
const int rotOraria_M4 = 6; 
const int rotAntioraria_M4 = 7;
const int pinEnable_M4 = 12; 

//costranti
char c;
int velocita=40;
 
void setup()  //inizializzazioni
{
  Serial.begin(9600);  
  //inizializzazione motore 1
  pinMode(rotOraria_M1, OUTPUT);  
  pinMode(rotAntioraria_M1, OUTPUT);
  pinMode(pinEnable_M1, OUTPUT); 
  //inizializzaione motore 2
  pinMode(rotOraria_M2, OUTPUT);  
  pinMode(rotAntioraria_M2, OUTPUT);
  pinMode(pinEnable_M2, OUTPUT); 
  //inizializzazione motore 3
  pinMode(rotOraria_M3, OUTPUT);  
  pinMode(rotAntioraria_M3, OUTPUT);
  pinMode(pinEnable_M3, OUTPUT); 
  //inizializzazione motore 4
  pinMode(rotOraria_M4, OUTPUT);  
  pinMode(rotAntioraria_M4, OUTPUT);
  pinMode(pinEnable_M4, OUTPUT); 
    
}


void loop(){

  
  if(Serial.available()) {
  
    c = Serial.read();
    Serial.print(c);
    switch(c){
      case '0':
        Serial.println("avanti");
        avantiMotore1();
        avantiMotore2();
        avantiMotore3();
        avantiMotore4();
      break;
      case '1':
        Serial.println("indietro");
        indietroMotore1();
        indietroMotore2();
        indietroMotore3();
        indietroMotore4();
      break;
      case '2':
        Serial.println("destra");
        indietroMotore1();
        avantiMotore2();
        avantiMotore3();
        indietroMotore4();
      break;
      case '3':
        Serial.println("sinistra");
        avantiMotore1();
        indietroMotore2();
        indietroMotore3();
        avantiMotore4();
      break;
      case 'A':
        Serial.println("velocita bassa");
        velocita=30;
      break;
      case 'B':
        Serial.println("velocita media");
        velocita=60;
      break;
      case 'C':
        Serial.println("velocita alta");
        velocita=90;
      break;
    }
  }
}

 
//fare giare avanti motore 1
void avantiMotore1(){
  digitalWrite(rotOraria_M1, HIGH);
  digitalWrite(rotAntioraria_M1, LOW);
  analogWrite(pinEnable_M1, (255 * velocita)/100);
}

//fare girare avanti motore 2
void avantiMotore2(){
  digitalWrite(rotOraria_M2, HIGH);
  digitalWrite(rotAntioraria_M2, LOW);
  analogWrite(pinEnable_M2, (255 * velocita)/100);
}

//fare girare avanti motore 3
void avantiMotore3(){
  digitalWrite(rotOraria_M3, HIGH);
  digitalWrite(rotAntioraria_M3, LOW);
  analogWrite(pinEnable_M3, (255 * velocita)/100);
}

//fare girare avanti motore 4
void avantiMotore4(){
  digitalWrite(rotOraria_M4, HIGH);
  digitalWrite(rotAntioraria_M4, LOW);
  analogWrite(pinEnable_M4, (255 * velocita)/100);
}

//fare girare indietro motore 1
void indietroMotore1(){
  digitalWrite(rotOraria_M1, LOW);
  digitalWrite(rotAntioraria_M1, HIGH);
  analogWrite(pinEnable_M1, (255 * velocita)/100);
}

//fare girare indietro motore 2
void indietroMotore2(){
  digitalWrite(rotOraria_M2, LOW);
  digitalWrite(rotAntioraria_M2, HIGH);
  analogWrite(pinEnable_M2, (255 * velocita)/100);
}

//fare girare indietro motore 3
void indietroMotore3(){
  digitalWrite(rotOraria_M3, LOW);
  digitalWrite(rotAntioraria_M3, HIGH);
  analogWrite(pinEnable_M3, (255 * velocita)/100);
}

//fare girare indietro motore 4
void indietroMotore4(){
  digitalWrite(rotOraria_M4, LOW);
  digitalWrite(rotAntioraria_M4, HIGH);
  analogWrite(pinEnable_M4, (255 * velocita)/100);
}

//fermare tutti i motori
void stopMotor(){
  digitalWrite(pinEnable_M1, LOW);
  digitalWrite(pinEnable_M2, LOW);
  digitalWrite(pinEnable_M3, LOW);
  digitalWrite(pinEnable_M4, LOW);
}
