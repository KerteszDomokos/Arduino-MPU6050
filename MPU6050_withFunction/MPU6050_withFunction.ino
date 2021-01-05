/*
    MPU6050 Triple Axis Gyroscope & Accelerometer. Motion detection.
    Read more: http://www.jarzebski.pl/arduino/czujniki-i-sensory/3-osiowy-zyroskop-i-akcelerometr-mpu6050.html
    GIT: https://github.com/jarzebski/Arduino-MPU6050
    Web: http://www.jarzebski.pl
    (c) 2014 by Korneliusz Jarzebski
    Edited by Kertesz Domokos 2020
*/

#include <Wire.h>
#include <MPU6050.h>


int16_t ax, ay, az;
int16_t gx, gy, gz;
unsigned long timer;
float timeStep;

double gyrodat[6]={0.00,0.00,0.00,0.00,0.00,0.00};

void setup(){
while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G))
  {
    Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
    delay(500);
  }
  mpu.calibrateGyro();
  mpu.setThreshold(3);
}

void loop(){
//write here your private code

//invite the getMPU() function, minimum 10/sec
//use the gyrodat array value. 0-pitch 1-roll, 2-yaw, 3-accelX 4-accelY 5-accelZ(gravity)
getMPU()


}

void getMPU(){
  timeStep=millis()-timer;
  timer = millis();
  //gyro
  Vector norm = mpu.readNormalizeGyro();
  pitch = pitch + norm.YAxis * timeStep/1000;
  roll = roll + norm.XAxis * timeStep/1000;
  yaw = yaw + norm.ZAxis * timeStep/1000;  
  gyrodat[0]=pitch;
  gyrodat[1]=roll;
  gyrodat[2]=yaw;
  
  //accel
  Vector norma=mpu.readNormalizeAccel();
  gyrodat[3]=norma.XAxis;
  gyrodat[4]=norma.YAxis;
  gyrodat[5]=norma.ZAxis;

}
