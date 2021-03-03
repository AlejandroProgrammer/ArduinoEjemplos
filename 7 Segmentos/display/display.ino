#define a 2
#define b 3
#define z 4 // He utilizado la z en vez de la c. La c da error.
#define d 5
#define e 6
#define f 7
#define g 8
int tiempo=1000;

// En el setup establecemos los parámetros iniciales.
void setup() {
  
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(z, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
}

void loop() {
  
  uno();
  delay(tiempo);
  dos();
  delay(tiempo);
  tres();
  delay(tiempo);
  cuatro();
  delay(tiempo);
  cinco();
  delay(tiempo);
  seis();
  delay(tiempo);
  siete();
  delay(tiempo);
  ocho();
  delay(tiempo);
  nueve();
  delay(tiempo);
  cero();
  delay(tiempo);
}

void borrado(){
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(z,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
}

void uno(){
  borrado();
  digitalWrite(b,LOW);
  digitalWrite(z,LOW);
}

void dos(){
  borrado();  
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(g,LOW);
  digitalWrite(e,LOW);
  digitalWrite(d,LOW);
}

void tres(){
  borrado();
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(g,LOW);
  digitalWrite(z,LOW);
  digitalWrite(d,LOW);
}

void cuatro(){
  borrado();
  digitalWrite(b,LOW);
  digitalWrite(z,LOW);
  digitalWrite(g,LOW);
  digitalWrite(f,LOW);
}

void cinco(){
  borrado();
  digitalWrite(a,LOW);
  digitalWrite(z,LOW);
  digitalWrite(d,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
}

void seis(){
  borrado();
  digitalWrite(a,LOW);
  digitalWrite(z,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
}

void siete(){
  borrado();
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(z,LOW);
}

void ocho(){
  borrado();
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(z,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
}

void nueve(){
  borrado();
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(z,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
}

void cero(){
  borrado();
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(z,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
}