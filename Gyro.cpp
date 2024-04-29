#include "Gyro.h"
#include "Display.h"
#include "Ball.h"
#include<Wire.h> //for GY-521 (Gyro-Sensor)

#define THRESHOLD 1800
#define L 0
#define R 1
#define U 2
#define D 3
#define LU 4
#define LD 5
#define RU 6
#define RD 7

const int MPU=0x68; 
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
int16_t GyX_0,GyY_0,GyZ_0;

char tmp_str[7]; // temporary variable used in convert function

char* convert_int16_to_str(int16_t i) { // converts int16 to string. Moreover, resulting strings will have the same length in the debug monitor.
  sprintf(tmp_str, "%6d", i);
  return tmp_str;
}

void Gyro::initialize(){  
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);  
  Wire.write(0);    
  Wire.endTransmission(true);
}

void Gyro::getStartPositions() {
  getPos();
  GyX_0 = GyX;
  GyY_0 = GyY;
  GyZ_0 = GyZ;
}

void Gyro::getPos() {
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);  
  Wire.endTransmission(false);
  Wire.requestFrom(MPU,12,true);

  GyX=Wire.read()<<8|Wire.read();  
  GyY=Wire.read()<<8|Wire.read();  
  GyZ=Wire.read()<<8|Wire.read(); 
  AcX=Wire.read()<<8|Wire.read();    
  AcY=Wire.read()<<8|Wire.read();  
  AcZ=Wire.read()<<8|Wire.read();

  //Display::printText(280, 5, "X: " + String(convert_int16_to_str(GyX)) + ", Y: " + String(convert_int16_to_str(GyY)) + ", Z: " + String(convert_int16_to_str(GyZ)));
  delay(200);
}

void Gyro::checkMovement() {
  getPos();

  if(GyX < GyX_0-THRESHOLD) {
    if(GyY < GyY_0-THRESHOLD) {
      // ... left up ... 
      Ball::moveBall(LU);
    } else if(GyY > GyY_0+THRESHOLD) {
      // ... left down ... 
      Ball::moveBall(LD);
    } else {
      // ... left ... 
      Ball::moveBall(L);
    }
  }
  
  if(GyX > GyX_0+THRESHOLD) { 
    if(GyY < GyY_0-THRESHOLD) {
      // ... right up ... 
      Ball::moveBall(RU);
    } else if(GyY > GyY_0+THRESHOLD) {
      // ... right down ... 
      Ball::moveBall(RD);
    } else {
      // ... right ... 
      Ball::moveBall(R);
    }
  }

  if(GyY < GyY_0-THRESHOLD) {
    // ... up ... 
    Ball::moveBall(U);
  }
  
  if(GyY > GyY_0+THRESHOLD) { 
    // ... down ...
    Ball::moveBall(D);
  }
}
