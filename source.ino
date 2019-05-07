#include <NewPing.h>

#define Mkanan_Dir 12
#define Mkanan_Vel 10
#define Mkiri_Dir 13
#define Mkiri_Vel 11

#define fullspeed 255
#define nospeed 0

#define FLAME_SENSOR 3 //connect FLAME_SENSOR to digital pin3
#define KIPAS 2
#define BUZZER 4

int tengah, kiri, kanan;

#define TENGAH 5
#define KIRI 6
#define KANAN 7
#define MAX 100
#define CLOSE 20

NewPing front(TENGAH, TENGAH, MAX);
NewPing right(KANAN, KANAN, MAX);
NewPing left(KIRI, KIRI, MAX);

void maju(){
  digitalWrite(Mkanan_Dir,HIGH);
  analogWrite(Mkanan_Vel,fullspeed);
  digitalWrite(Mkiri_Dir,HIGH);
  analogWrite(Mkiri_Vel,fullspeed);
}

void mundur(){
  digitalWrite(Mkanan_Dir,LOW);
  analogWrite(Mkanan_Vel,fullspeed);
  digitalWrite(Mkiri_Dir,LOW);
  analogWrite(Mkiri_Vel,fullspeed);
}

void berhenti(){
  digitalWrite(Mkanan_Dir,LOW);
  analogWrite(Mkanan_Vel,nospeed);
  digitalWrite(Mkiri_Dir,LOW);
  analogWrite(Mkiri_Vel,nospeed);
}

void belokkanan(){
  digitalWrite(Mkanan_Dir,LOW);
  analogWrite(Mkanan_Vel,fullspeed);
  digitalWrite(Mkiri_Dir,HIGH);
  analogWrite(Mkiri_Vel,fullspeed);
  delay(200);
}

void belokkiri(){
  digitalWrite(Mkanan_Dir,HIGH);
  analogWrite(Mkanan_Vel,fullspeed);
  digitalWrite(Mkiri_Dir,LOW);
  analogWrite(Mkiri_Vel,fullspeed);
  delay(200);
}

boolean isFlameDetected()
{
	if(digitalRead(FLAME_SENSOR))
		return false;
	else return true;
}

void Beep() {
  delay(100);
  digitalWrite(BUZZER,HIGH);
}

void setup(){
  pinMode(12,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(11,OUTPUT);
  Serial.begin(9600);
  
  pinMode(FLAME_SENSOR, INPUT);
   pinMode(KIPAS,OUTPUT);
   pinMode(BUZZER,OUTPUT);
   digitalWrite(KIPAS,HIGH);
   digitalWrite(BUZZER,LOW);
}

void loop(){
  delay(100);
  Beep();
  tengah = front.ping_cm();
  kanan = right.ping_cm();
  kiri = left.ping_cm();
  
  Serial.print(" Hasil pengukuran ");
  Serial.print("kanan :");
  Serial.print(kanan);
  Serial.print(" cm ");
  Serial.print("kiri :");
  Serial.print(kiri);
  Serial.print(" cm ");
  Serial.print("tengah :");
  Serial.print(tengah);
  Serial.print(" cm ");
  
  if(isFlameDetected()){
    berhenti();
    digitalWrite(KIPAS,LOW);
    digitalWrite(BUZZER,HIGH);
    delay(3500);
    Serial.print("Ada API COOOYYY!!");
    Serial.println("");
  }else{
       digitalWrite(KIPAS,HIGH);
       digitalWrite(BUZZER,LOW);
      
       Serial.print("Ga");
       Serial.println(""); 
      if(tengah!=0 && tengah>CLOSE){
        if(isFlameDetected()){ 
        berhenti(); 
        digitalWrite(KIPAS,LOW); 
        digitalWrite(BUZZER,HIGH); 
        delay(3500); 
        Serial.print("Ada API COOOYYY!!"); 
        Serial.println(""); 
    }else{ 
    digitalWrite(KIPAS,HIGH); 
    digitalWrite(BUZZER,LOW); 
     
    Serial.print("Ga"); 
    Serial.println(""); 

      maju();
      }
}

if(tengah!=0 && tengah<CLOSE && kiri!=0 && kiri<CLOSE && kanan!=0 && kanan>CLOSE){
if(isFlameDetected()){ 
        berhenti(); 
        digitalWrite(KIPAS,LOW); 
        digitalWrite(BUZZER,HIGH); 
        delay(3500); 
        Serial.print("Ada API COOOYYY!!"); 
        Serial.println(""); 
    }else{ 
    digitalWrite(KIPAS,HIGH); 
    digitalWrite(BUZZER,LOW); 
     
    Serial.print("Ga"); 
    Serial.println(""); 
      
      if (tengah<10 && kanan<10 && kiri<10){
 if(isFlameDetected()){ 
        berhenti(); 
        digitalWrite(KIPAS,LOW); 
        digitalWrite(BUZZER,HIGH); 
        delay(3500); 
        Serial.print("Ada API COOOYYY!!"); 
        Serial.println(""); 
    }else{ 
    digitalWrite(KIPAS,HIGH); 
    digitalWrite(BUZZER,LOW); 
     
    Serial.print("Ga"); 
    Serial.println(""); 
    
    if (kanan>CLOSE && kanan>kiri){
    belokkanan();
    }
    else if (kiri>CLOSE && kiri>kanan){
    belokkiri();
    }      
  }} 
  else {
      mundur();}
      
      mundur();
      belokkanan();
      mundur();
      belokkanan();
      }}
      
if(tengah!=0 && tengah<CLOSE && kanan!=0 && kanan<CLOSE && kiri!=0 && kiri>CLOSE){
if(isFlameDetected()){ 
        berhenti(); 
        digitalWrite(KIPAS,LOW); 
        digitalWrite(BUZZER,HIGH); 
        delay(3500); 
        Serial.print("Ada API COOOYYY!!"); 
        Serial.println(""); 
    }else{ 
    digitalWrite(KIPAS,HIGH); 
    digitalWrite(BUZZER,LOW); 
     
    Serial.print("Ga"); 
    Serial.println(""); 
      
      if (tengah<10 && kanan<10 && kiri<10){
 if(isFlameDetected()){ 
        berhenti(); 
        digitalWrite(KIPAS,LOW); 
        digitalWrite(BUZZER,HIGH); 
        delay(3500); 
        Serial.print("Ada API COOOYYY!!"); 
        Serial.println(""); 
    }else{ 
    digitalWrite(KIPAS,HIGH); 
    digitalWrite(BUZZER,LOW); 
     
    Serial.print("Ga"); 
    Serial.println(""); 
    
    if (kanan>CLOSE && kanan>kiri){
    belokkanan();
    }
    else if (kiri>CLOSE && kiri>kanan){
    belokkiri();
    }      
  }} 
  else {
      mundur();}
      
      mundur();
      belokkiri();
      mundur();
      belokkiri();
      }}
      
if(tengah!=0 && tengah<CLOSE && kanan!=0 && kanan>CLOSE && kiri!=0 && kiri>CLOSE){
if(isFlameDetected()){ 
        berhenti(); 
        digitalWrite(KIPAS,LOW); 
        digitalWrite(BUZZER,HIGH); 
        delay(3500); 
        Serial.print("Ada API COOOYYY!!"); 
        Serial.println(""); 
    }else{ 
    digitalWrite(KIPAS,HIGH); 
    digitalWrite(BUZZER,LOW); 
     
    Serial.print("Ga"); 
    Serial.println(""); 
    
    if (tengah<10 && kanan<10 && kiri<10){
 if(isFlameDetected()){ 
        berhenti(); 
        digitalWrite(KIPAS,LOW); 
        digitalWrite(BUZZER,HIGH); 
        delay(3500); 
        Serial.print("Ada API COOOYYY!!"); 
        Serial.println(""); 
    }else{ 
    digitalWrite(KIPAS,HIGH); 
    digitalWrite(BUZZER,LOW); 
     
    Serial.print("Ga"); 
    Serial.println(""); 
    
    if (kanan>CLOSE && kanan>kiri){
    belokkanan();
    }
    else if (kiri>CLOSE && kiri>kanan){
    belokkiri();
    }      
  }} 
  else {
      mundur();}
    
      mundur();
      belokkiri();
      mundur();
      belokkiri();
      }}
    
if(kiri!=0 && kiri<5){
if(isFlameDetected()){ 
        berhenti(); 
        digitalWrite(KIPAS,LOW); 
        digitalWrite(BUZZER,HIGH); 
        delay(3500); 
        Serial.print("Ada API COOOYYY!!"); 
        Serial.println(""); 
    }else{ 
    digitalWrite(KIPAS,HIGH); 
    digitalWrite(BUZZER,LOW); 
     
    Serial.print("Ga"); 
    Serial.println(""); 
      
      if (tengah<10 && kanan<10 && kiri<10){
 if(isFlameDetected()){ 
        berhenti(); 
        digitalWrite(KIPAS,LOW); 
        digitalWrite(BUZZER,HIGH); 
        delay(3500); 
        Serial.print("Ada API COOOYYY!!"); 
        Serial.println(""); 
    }else{ 
    digitalWrite(KIPAS,HIGH); 
    digitalWrite(BUZZER,LOW); 
     
    Serial.print("Ga"); 
    Serial.println(""); 
    
    if (kanan>CLOSE && kanan>kiri){
    belokkanan();
    }
    else if (kiri>CLOSE && kiri>kanan){
    belokkiri();
    }      
  }} 
  else {
      mundur();}
      
      belokkanan();
      }} 
 
if(kanan!=0 && kanan<5){
if(isFlameDetected()){ 
        berhenti(); 
        digitalWrite(KIPAS,LOW); 
        digitalWrite(BUZZER,HIGH); 
        delay(3500); 
        Serial.print("Ada API COOOYYY!!"); 
        Serial.println(""); 
    }else{ 
    digitalWrite(KIPAS,HIGH); 
    digitalWrite(BUZZER,LOW); 
     
    Serial.print("Ga"); 
    Serial.println(""); 
    
    if (tengah<10 && kanan<10 && kiri<10){
 if(isFlameDetected()){ 
        berhenti(); 
        digitalWrite(KIPAS,LOW); 
        digitalWrite(BUZZER,HIGH); 
        delay(3500); 
        Serial.print("Ada API COOOYYY!!"); 
        Serial.println(""); 
    }else{ 
    digitalWrite(KIPAS,HIGH); 
    digitalWrite(BUZZER,LOW); 
     
    Serial.print("Ga"); 
    Serial.println(""); 
    
    if (kanan>CLOSE && kanan>kiri){
    belokkanan();
    }
    else if (kiri>CLOSE && kiri>kanan){
    belokkiri();
    }      
  }} 
  else {
      mundur();}
    
      belokkiri();
      }}  
      
    }
}
