#include <TimerOne.h> //libreria para manejar interrupciones temporales

int segA = 49;
int segB = 48;
int segC = 47;
int segD = 46;
int segE = 45;
int segF = 44;
int segG = 43;
int tuni = 24;         
int tdec = 23; 
int cont,dec,uni;
long pulsos = 0;  // variable para contar los pulsos
int resolucion = 72;  // resolución del encoder número de pulsos por revolución
double rpm; // variable para almacenar el calculo de la velocidad rpm


void setup()
{
  pinMode(segA, OUTPUT);        
  pinMode(segB, OUTPUT);       
  pinMode(segC, OUTPUT);       
  pinMode(segD, OUTPUT);       
  pinMode(segE, OUTPUT);      
  pinMode(segF, OUTPUT);      
  pinMode(segG, OUTPUT); 
  pinMode(tuni, OUTPUT);      
  pinMode(tdec, OUTPUT);  
  Serial.begin(9600);
  Timer1.initialize(2000000);  // cada 1 segundo se ejecuta la interrupción     
  Timer1.attachInterrupt(segundo);//se establece función de interrupción
  attachInterrupt(0,conteo,RISING);
  cont=0;
  pulsos=0;
  }

void deteccion(){  // función que se ejecuta cuando hay interrupción externa
  pulsos++; // se incrementa la variable pulso en uno.
}

void segundo () {  // función que se ejecuta cuando se cumple el tiempo de interrupcíón temporal
  
 rpm=((double)pulsos/resolucion)*60; // calculo de velocidad rpm
 pulsos=0; // pulsos
}

void conteo()
{
  cont++;
}

void reset () {  // función que se ejecuta cuando se cumple el tiempo de interrupcíón temporal
  
 pulsos=cont; // pulsos
 cont=0;
}

void int2bcd(int num)  //Funcion que toma un numero entero y lo convierte a BCD
{
  switch (num)
  {
    case 0:
      digitalWrite(segA, HIGH);
      digitalWrite(segB, HIGH);
      digitalWrite(segC, HIGH);
      digitalWrite(segD, HIGH);
      digitalWrite(segE, HIGH);
      digitalWrite(segF, HIGH);
      digitalWrite(segG, LOW);

      break;

    case 1:
      digitalWrite(segA, LOW);
      digitalWrite(segB, HIGH);
      digitalWrite(segC, HIGH);
      digitalWrite(segD, LOW);
      digitalWrite(segE, LOW);
      digitalWrite(segF, LOW);
      digitalWrite(segG, LOW);
      break;

    case 2:
      digitalWrite(segA, HIGH);
      digitalWrite(segB, HIGH);
      digitalWrite(segC, LOW);
      digitalWrite(segD, HIGH);
      digitalWrite(segE, HIGH);
      digitalWrite(segF, LOW);
      digitalWrite(segG, HIGH);
      break;

    case 3:
      digitalWrite(segA, HIGH);
      digitalWrite(segB, HIGH);
      digitalWrite(segC, HIGH);
      digitalWrite(segD, HIGH);
      digitalWrite(segE, LOW);
      digitalWrite(segF, LOW);
      digitalWrite(segG, HIGH);
      break;

    case 4:
      digitalWrite(segA, LOW);
      digitalWrite(segB, HIGH);
      digitalWrite(segC, HIGH);
      digitalWrite(segD, LOW);
      digitalWrite(segE, LOW);
      digitalWrite(segF, HIGH);
      digitalWrite(segG, HIGH);
      break;

    case 5:
      digitalWrite(segA, HIGH);
      digitalWrite(segB, LOW);
      digitalWrite(segC, HIGH);
      digitalWrite(segD, HIGH);
      digitalWrite(segE, LOW);
      digitalWrite(segF, HIGH);
      digitalWrite(segG, HIGH);
      break;

    case 6:
      digitalWrite(segA, LOW);
      digitalWrite(segB, LOW);
      digitalWrite(segC, HIGH);
      digitalWrite(segD, HIGH);
      digitalWrite(segE, HIGH);
      digitalWrite(segF, HIGH);
      digitalWrite(segG, HIGH);
      break;

    case 7:
      digitalWrite(segA, HIGH);
      digitalWrite(segB, HIGH);
      digitalWrite(segC, HIGH);
      digitalWrite(segD, LOW);
      digitalWrite(segE, LOW);
      digitalWrite(segF, LOW);
      digitalWrite(segG, LOW);
      break;

    case 8:
      digitalWrite(segA, HIGH);
      digitalWrite(segB, HIGH);
      digitalWrite(segC, HIGH);
      digitalWrite(segD, HIGH);
      digitalWrite(segE, HIGH);
      digitalWrite(segF, HIGH);
      digitalWrite(segG, HIGH);
      break;

    case 9:
      digitalWrite(segA, HIGH);
      digitalWrite(segB, HIGH);
      digitalWrite(segC, HIGH);
      digitalWrite(segD, LOW);
      digitalWrite(segE, LOW);
      digitalWrite(segF, HIGH);
      digitalWrite(segG, HIGH);
      break;
    
  }
}

void mostrar(int cont)
{
      dec = cont / 10;
      uni = cont % 10;
      int2bcd(uni);
      digitalWrite(tuni, HIGH);   
      digitalWrite(tdec, LOW);   
      delay(1);
      digitalWrite(tuni, LOW); 
      delay(1);
      int2bcd(dec);
      digitalWrite(tuni, LOW);  
      digitalWrite(tdec, HIGH);   
    delay(1); 
      digitalWrite(tdec, LOW); 
    
} 


void loop()
{
  
  mostrar(rpm);
 
} 
