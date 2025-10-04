//Librería para el control del Servomotor
#include <Servo.h>

//Sensor ultrasónico
const int trigPin = 12;
const int echoPin = 13;
long duracion; 
int distancia;


//Servomotor
Servo servo;
const int servoPin = 3;

//Driver de motores - arduino
const int ENA = 6; //control de velocidad motor 1
const int ENB = 5; // control de velocidad motor 2 
const int IN1 = 11;
const int IN2 = 10;
const int IN3 = 9;
const int IN4 = 8;

//velocidad de los motores
int speedA = 200;
int speedB = 200;


//inicialización
void setup(){

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  servo.attach(servoPin); 
  servo.write(90); // posicion inicial del servo
  delay(300);
  Serial.begin(9600);
}


//Ejecución constante
void loop(){

  distancia = readUltrasonic();
  Serial.print("La distancia frontal es: ");
  Serial.println(distancia);

  if(distancia > 20){
    avanzar();
    servo.write(90);

  } else if(distancia <= 20 && distancia > 10){
    parar();
    buscarMejorDireccion();

  } else if(distancia <= 10){
    retroceder();
    delay(500);
    parar();
    buscarMejorDireccion();
  }

  delay(100);
}


//Funciones del robot ultrasónico
int readUltrasonic(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duracion = pulseIn(echoPin, HIGH);
  int dist = duracion * 0.034 / 2; 
  return dist; 
}


void avanzar(){
  //Motor A
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, speedA);

  //Motor B
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, speedB);
}


void retroceder(){
  //Motor A
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, speedA);

  //Motor B
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, speedB);
}


void parar(){
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}


void girarIzquierda(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, speedA);
  analogWrite(ENB, speedB);
  delay(600);
  parar();
}


void girarDerecha(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, speedA);
  analogWrite(ENB, speedB);
  delay(600);
  parar();
}


//Análisis de dirección
void buscarMejorDireccion(){
  servo.write(45);
  delay(500);
  int distIzq = readUltrasonic();
  Serial.print("La distancia izquierda es: ");
  Serial.println(distIzq);

  servo.write(135);
  delay(500);
  int distDer = readUltrasonic();
  Serial.print("La distancia derecha es: ");
  Serial.println(distDer);

  if(distIzq > distDer){
    girarIzquierda();
  } else {
    girarDerecha();
  }

  servo.write(90);
  delay(300);
}
