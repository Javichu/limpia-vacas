// Motor
const int stepPin = 7; 
const int dirPin = 6;

// Sensores
const int sensorAgua = 5;
const int sensorJabon = 3;
const int sensorRodillo = 4;
const int sensorAire = 2;

// Leds Agua
const int ledAgua01 = 22;
const int ledAgua02 = 23;
const int ledAgua03 = 24;
const int ledAgua04 = 25;
const int ledAgua05 = 26;
const int ledAgua06 = 27;

// Leds Jabon
const int ledJabon01 = 40;
const int ledJabon02 = 41;
const int ledJabon03 = 42;
const int ledJabon04 = 43;
const int ledJabon05 = 44;
const int ledJabon06 = 45;

// Leds Rodillo
const int ledRodillo01 = 32;
const int ledRodillo02 = 33;
const int ledRodillo03 = 34;
const int ledRodillo04 = 35;
const int ledRodillo05 = 36;
const int ledRodillo06 = 37;

// Leds Aire
const int ledAire01 = 48;
const int ledAire02 = 49;
const int ledAire03 = 50;
const int ledAire04 = 51;
const int ledAire05 = 52;
const int ledAire06 = 53;

// Estados
int estadoGeneral = 0;
int estadoAgua = 0;
int estadoJabon = 0;
int estadoRodillo = 0;
int estadoAire = 0;
int estadoMotor = 1;

// Delays calculados por cantidad de loops
// para no romper ciclos de comportamiento
const int delayMotorTotal = 20000;
int delayMotorActual = delayMotorTotal;
const int pasosAMover = 100;
int pasosPorMover = pasosAMover;
bool moverMotor = false;
int tiempoEntreMedioPaso = 2500;

const int delayAguaTotal = 1500;
int delayAguaActual = delayAguaTotal;

const int delayJabonTotal = 6000;
int delayJabonActual = delayJabonTotal;

const int delayRodilloTotal = 2000;
int delayRodilloActual = delayRodilloTotal;

const int delayAireTotal = 3000;
int delayAireActual = delayAireTotal;

void apagarTodosLosLeds();

void setup() {
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  
  pinMode(sensorAgua,INPUT);
  pinMode(sensorJabon,INPUT);
  pinMode(sensorRodillo,INPUT);
  pinMode(sensorAire,INPUT);

  pinMode(ledAgua01,OUTPUT);
  pinMode(ledAgua02,OUTPUT);
  pinMode(ledAgua03,OUTPUT);
  pinMode(ledAgua04,OUTPUT);
  pinMode(ledAgua05,OUTPUT);
  pinMode(ledAgua06,OUTPUT);

  pinMode(ledJabon01,OUTPUT);
  pinMode(ledJabon02,OUTPUT);
  pinMode(ledJabon03,OUTPUT);
  pinMode(ledJabon04,OUTPUT);
  pinMode(ledJabon05,OUTPUT);
  pinMode(ledJabon06,OUTPUT);

  pinMode(ledRodillo01,OUTPUT);
  pinMode(ledRodillo02,OUTPUT);
  pinMode(ledRodillo03,OUTPUT);
  pinMode(ledRodillo04,OUTPUT);
  pinMode(ledRodillo05,OUTPUT);
  pinMode(ledRodillo06,OUTPUT);

  pinMode(ledAire01,OUTPUT);
  pinMode(ledAire02,OUTPUT);
  pinMode(ledAire03,OUTPUT);
  pinMode(ledAire04,OUTPUT);
  pinMode(ledAire05,OUTPUT);
  pinMode(ledAire06,OUTPUT);
}

void loop() {
  if(!moverMotor){
    if(digitalRead(sensorAire)==LOW && estadoGeneral != 4){
      moverMotor = true;
      estadoGeneral = 4;
      estadoAgua = 0;
      estadoJabon = 0;
      estadoRodillo = 0;
      estadoAire = 1;
      apagarTodosLosLeds();
    }else if(digitalRead(sensorRodillo)==LOW && estadoGeneral != 3){
      moverMotor = true;
      estadoGeneral = 3;
      estadoAgua = 0;
      estadoJabon = 0;
      estadoRodillo = 1;
      estadoAire = 0;
      apagarTodosLosLeds();
    }else if(digitalRead(sensorJabon)==LOW && estadoGeneral != 2){
      moverMotor = true;
      estadoGeneral = 2;
      estadoAgua = 0;
      estadoJabon = 1;
      estadoRodillo = 0;
      estadoAire = 0;
      apagarTodosLosLeds();
    }else if(digitalRead(sensorAgua)==LOW && estadoGeneral != 1){
      moverMotor = true;
      estadoGeneral = 1;
      estadoAgua = 1;
      estadoJabon = 0;
      estadoRodillo = 0;
      estadoAire = 0;
      apagarTodosLosLeds();
    }
  }

  switch(estadoGeneral){
    case 0:
      apagarTodosLosLeds();
    break;
    case 1:
      switch(estadoAgua){
        case 1: // CICLO DEL AGUA
          delayAguaActual--;
          digitalWrite(ledAgua01,HIGH);
          digitalWrite(ledAgua02,LOW);
          digitalWrite(ledAgua03,LOW);
          digitalWrite(ledAgua04,LOW);
          digitalWrite(ledAgua05,LOW);
          digitalWrite(ledAgua06,LOW);
          if(delayAguaActual<=0){
            delayAguaActual = delayAguaTotal;
            while(estadoAgua == 1){
              estadoAgua = random(1,7);
            }
          }
        break;
        case 2:
          delayAguaActual--;
          digitalWrite(ledAgua01,LOW);
          digitalWrite(ledAgua02,HIGH);
          digitalWrite(ledAgua03,LOW);
          digitalWrite(ledAgua04,LOW);
          digitalWrite(ledAgua05,LOW);
          digitalWrite(ledAgua06,LOW);
          if(delayAguaActual<=0){
            delayAguaActual = delayAguaTotal;
            while(estadoAgua == 2){
              estadoAgua = random(1,7);
            }
          }
        break;
        case 3:
          delayAguaActual--;
          digitalWrite(ledAgua01,LOW);
          digitalWrite(ledAgua02,LOW);
          digitalWrite(ledAgua03,HIGH);
          digitalWrite(ledAgua04,LOW);
          digitalWrite(ledAgua05,LOW);
          digitalWrite(ledAgua06,LOW);
          if(delayAguaActual<=0){
            delayAguaActual = delayAguaTotal;
            while(estadoAgua == 3){
              estadoAgua = random(1,7);
            }
          }
        break;
        case 4:
          delayAguaActual--;
          digitalWrite(ledAgua01,LOW);
          digitalWrite(ledAgua02,LOW);
          digitalWrite(ledAgua03,LOW);
          digitalWrite(ledAgua04,HIGH);
          digitalWrite(ledAgua05,LOW);
          digitalWrite(ledAgua06,LOW);
          if(delayAguaActual<=0){
            delayAguaActual = delayAguaTotal;
            while(estadoAgua == 4){
              estadoAgua = random(1,7);
            }
          }
        break;
        case 5:
          delayAguaActual--;
          digitalWrite(ledAgua01,LOW);
          digitalWrite(ledAgua02,LOW);
          digitalWrite(ledAgua03,LOW);
          digitalWrite(ledAgua04,LOW);
          digitalWrite(ledAgua05,HIGH);
          digitalWrite(ledAgua06,LOW);
          if(delayAguaActual<=0){
            delayAguaActual = delayAguaTotal;
            while(estadoAgua == 5){
              estadoAgua = random(1,7);
            }
          }
        break;
        case 6:
          delayAguaActual--;
          digitalWrite(ledAgua01,LOW);
          digitalWrite(ledAgua02,LOW);
          digitalWrite(ledAgua03,LOW);
          digitalWrite(ledAgua04,LOW);
          digitalWrite(ledAgua05,LOW);
          digitalWrite(ledAgua06,HIGH);
          if(delayAguaActual<=0){
            delayAguaActual = delayAguaTotal;
            while(estadoAgua == 6){
              estadoAgua = random(1,7);
            }
          }
        break;
      }
    break;
    case 2: // CICLO DEL JABON
      switch(estadoJabon){
        case 1:
          delayJabonActual--;
          digitalWrite(ledJabon01,HIGH);
          digitalWrite(ledJabon02,LOW);
          digitalWrite(ledJabon03,LOW);
          digitalWrite(ledJabon04,LOW);
          digitalWrite(ledJabon05,LOW);
          digitalWrite(ledJabon06,LOW);
          if(delayJabonActual<=0){
            delayJabonActual = delayJabonTotal;
            estadoJabon = 2;
          }
        break;
        case 2:
          delayJabonActual--;
          digitalWrite(ledJabon01,HIGH);
          digitalWrite(ledJabon02,HIGH);
          digitalWrite(ledJabon03,HIGH);
          digitalWrite(ledJabon04,LOW);
          digitalWrite(ledJabon05,LOW);
          digitalWrite(ledJabon06,LOW);
          if(delayJabonActual<=0){
            delayJabonActual = delayJabonTotal;
            estadoJabon = 3;
          }
        break;
        case 3:
          delayJabonActual--;
          digitalWrite(ledJabon01,HIGH);
          digitalWrite(ledJabon02,HIGH);
          digitalWrite(ledJabon03,HIGH);
          digitalWrite(ledJabon04,HIGH);
          digitalWrite(ledJabon05,HIGH);
          digitalWrite(ledJabon06,HIGH);
          if(delayJabonActual<=0){
            delayJabonActual = delayJabonTotal;
            estadoJabon = 4;
          }
        break;
        case 4:
          delayJabonActual--;
          digitalWrite(ledJabon01,HIGH);
          digitalWrite(ledJabon02,HIGH);
          digitalWrite(ledJabon03,HIGH);
          digitalWrite(ledJabon04,LOW);
          digitalWrite(ledJabon05,LOW);
          digitalWrite(ledJabon06,LOW);
          if(delayJabonActual<=0){
            delayJabonActual = delayJabonTotal;
            estadoJabon = 5;
          }
        break;
        case 5:
          delayJabonActual--;
          digitalWrite(ledJabon01,HIGH);
          digitalWrite(ledJabon02,LOW);
          digitalWrite(ledJabon03,LOW);
          digitalWrite(ledJabon04,LOW);
          digitalWrite(ledJabon05,LOW);
          digitalWrite(ledJabon06,LOW);
          if(delayJabonActual<=0){
            delayJabonActual = delayJabonTotal;
            estadoJabon = 6;
          }
        break;
        case 6:
          delayJabonActual--;
          digitalWrite(ledJabon01,LOW);
          digitalWrite(ledJabon02,LOW);
          digitalWrite(ledJabon03,LOW);
          digitalWrite(ledJabon04,LOW);
          digitalWrite(ledJabon05,LOW);
          digitalWrite(ledJabon06,LOW);
          if(delayJabonActual<=0){
            delayJabonActual = delayJabonTotal;
            estadoJabon = 1;
          }
        break;
      }
    break;
    case 3: // CICLO DEL RODILLO
      switch(estadoRodillo){
        case 1:
          delayRodilloActual--;
          digitalWrite(ledRodillo01,HIGH);
          digitalWrite(ledRodillo02,HIGH);
          digitalWrite(ledRodillo03,LOW);
          digitalWrite(ledRodillo04,LOW);
          digitalWrite(ledRodillo05,LOW);
          digitalWrite(ledRodillo06,LOW);
          if(delayRodilloActual<=0){
            delayRodilloActual = delayRodilloTotal;
            estadoRodillo = 2;
          }
        break;
        case 2:
          delayRodilloActual--;
          digitalWrite(ledRodillo01,LOW);
          digitalWrite(ledRodillo02,LOW);
          digitalWrite(ledRodillo03,HIGH);
          digitalWrite(ledRodillo04,HIGH);
          digitalWrite(ledRodillo05,LOW);
          digitalWrite(ledRodillo06,LOW);
          if(delayRodilloActual<=0){
            delayRodilloActual = delayRodilloTotal;
            estadoRodillo = 3;
          }
        break;
        case 3:
          delayRodilloActual--;
          digitalWrite(ledRodillo01,LOW);
          digitalWrite(ledRodillo02,LOW);
          digitalWrite(ledRodillo03,LOW);
          digitalWrite(ledRodillo04,LOW);
          digitalWrite(ledRodillo05,HIGH);
          digitalWrite(ledRodillo06,HIGH);
          if(delayRodilloActual<=0){
            delayRodilloActual = delayRodilloTotal;
            estadoRodillo = 1;
          }
        break;
      }
    break;
    case 4:
      switch(estadoAire){
        case 1:
          delayAireActual--;
          digitalWrite(ledAire01,HIGH);
          digitalWrite(ledAire02,LOW);
          digitalWrite(ledAire03,LOW);
          digitalWrite(ledAire04,LOW);
          digitalWrite(ledAire05,LOW);
          digitalWrite(ledAire06,LOW);
          if(delayAireActual<=0){
            delayAireActual = delayAireTotal;
            estadoAire = 2;
          }
        break;
        case 2:
          delayAireActual--;
          digitalWrite(ledAire01,HIGH);
          digitalWrite(ledAire02,HIGH);
          digitalWrite(ledAire03,HIGH);
          digitalWrite(ledAire04,LOW);
          digitalWrite(ledAire05,LOW);
          digitalWrite(ledAire06,LOW);
          if(delayAireActual<=0){
            delayAireActual = delayAireTotal;
            estadoAire = 3;
          }
        break;
        case 3:
          delayAireActual--;
          digitalWrite(ledAire01,HIGH);
          digitalWrite(ledAire02,HIGH);
          digitalWrite(ledAire03,HIGH);
          digitalWrite(ledAire04,HIGH);
          digitalWrite(ledAire05,HIGH);
          digitalWrite(ledAire06,HIGH);
          if(delayAireActual<=0){
            delayAireActual = delayAireTotal;
            estadoAire = 4;
          }
        break;
        case 4:
          delayAireActual--;
          digitalWrite(ledAire01,LOW);
          digitalWrite(ledAire02,HIGH);
          digitalWrite(ledAire03,HIGH);
          digitalWrite(ledAire04,HIGH);
          digitalWrite(ledAire05,HIGH);
          digitalWrite(ledAire06,HIGH);
          if(delayAireActual<=0){
            delayAireActual = delayAireTotal;
            estadoAire = 5;
          }
        break;
        case 5:
          delayAireActual--;
          digitalWrite(ledAire01,LOW);
          digitalWrite(ledAire02,LOW);
          digitalWrite(ledAire03,LOW);
          digitalWrite(ledAire04,HIGH);
          digitalWrite(ledAire05,HIGH);
          digitalWrite(ledAire06,HIGH);
          if(delayAireActual<=0){
            delayAireActual = delayAireTotal*5; // Hacemos que la pausa apagada sea mas larga
            estadoAire = 6;
          }
        break;
        case 6:
          delayAireActual--;
          digitalWrite(ledAire01,LOW);
          digitalWrite(ledAire02,LOW);
          digitalWrite(ledAire03,LOW);
          digitalWrite(ledAire04,LOW);
          digitalWrite(ledAire05,LOW);
          digitalWrite(ledAire06,LOW);
          if(delayAireActual<=0){
            delayAireActual = delayAireTotal;
            estadoAire = 1;
          }
        break;
      }
    break;
  }
  
  // Aqui gestionamos el motor
  if(moverMotor){
    switch(estadoMotor){
      case 1: // Damos la vuelta al bote de mugir
        digitalWrite(dirPin,HIGH);
        pasosPorMover--;
        if(pasosPorMover>0){
          digitalWrite(stepPin,HIGH);
          delayMicroseconds(tiempoEntreMedioPaso);
          digitalWrite(stepPin,LOW);
          delayMicroseconds(tiempoEntreMedioPaso);
        }
        if(pasosPorMover<=0){
            pasosPorMover = pasosAMover;
            estadoMotor = 2;
        }
        break;
      case 2: // Volvemos al vertical
        digitalWrite(dirPin,LOW);
        delayMotorActual--;
        if(delayMotorActual<=0){
          pasosPorMover--;
          if(pasosPorMover>0){
            digitalWrite(stepPin,HIGH);
            delayMicroseconds(tiempoEntreMedioPaso);
            digitalWrite(stepPin,LOW);
            delayMicroseconds(tiempoEntreMedioPaso);
          }
        }
        if(pasosPorMover<=0){
          delayMotorActual--;
          if(delayMotorActual<=0){
            pasosPorMover = pasosAMover;
            delayMotorActual = delayMotorTotal;
            estadoMotor = 1;
            moverMotor = false;
          }
        }
        break;
    }
  }
}

void apagarTodosLosLeds(){
  digitalWrite(ledAgua01,LOW);
  digitalWrite(ledAgua02,LOW);
  digitalWrite(ledAgua03,LOW);
  digitalWrite(ledAgua04,LOW);
  digitalWrite(ledAgua05,LOW);
  digitalWrite(ledAgua06,LOW);

  digitalWrite(ledJabon01,LOW);
  digitalWrite(ledJabon02,LOW);
  digitalWrite(ledJabon03,LOW);
  digitalWrite(ledJabon04,LOW);
  digitalWrite(ledJabon05,LOW);
  digitalWrite(ledJabon06,LOW);

  digitalWrite(ledRodillo01,LOW);
  digitalWrite(ledRodillo02,LOW);
  digitalWrite(ledRodillo03,LOW);
  digitalWrite(ledRodillo04,LOW);
  digitalWrite(ledRodillo05,LOW);
  digitalWrite(ledRodillo06,LOW);

  digitalWrite(ledAire01,LOW);
  digitalWrite(ledAire02,LOW);
  digitalWrite(ledAire03,LOW);
  digitalWrite(ledAire04,LOW);
  digitalWrite(ledAire05,LOW);
  digitalWrite(ledAire06,LOW);
}
