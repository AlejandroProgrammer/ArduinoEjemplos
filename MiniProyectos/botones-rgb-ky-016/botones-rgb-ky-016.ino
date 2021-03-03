int rled = 11;
int gled = 10;
int bled = 9;

int r = 000;
int g = 000;
int b = 000;

int botonBlanco = 5;
int botonVerde = 6;
int botonRojo = 7;
int botonAzul = 8;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(rled, OUTPUT);
  pinMode(gled, OUTPUT);
  pinMode(bled, OUTPUT);
  pinMode(botonBlanco, INPUT);
}

void loop() {

  if(digitalRead(botonBlanco) == HIGH){
    r = 255;
    g = 255;
    b = 255;
    analogWrite(rled, r);
    analogWrite(gled, g);
    analogWrite(bled, b);
  }else if(digitalRead(botonVerde) == HIGH){
    r = 000;
    g = 255;
    b = 000;
    analogWrite(rled, r);
    analogWrite(gled, g);
    analogWrite(bled, b);
  }else if(digitalRead(botonRojo) == HIGH){
    r = 255;
    g = 000;
    b = 000;
    analogWrite(rled, r);
    analogWrite(gled, g);
    analogWrite(bled, b);
  }else if(digitalRead(botonAzul) == HIGH){
    r = 000;
    g = 000;
    b = 255;
    analogWrite(rled, r);
    analogWrite(gled, g);
    analogWrite(bled, b);
  }
  
  delay(20);

}
