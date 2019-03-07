#include "SPI.h"
#include "Wire.h"
#include "BalanceCar.h"
#include "KalmanFilter.h"
#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"

//Hardware SPI-1 Set...
#define OLED_DC    PB0
#define OLED_CS    PB1
#define OLED_RESET PA10
Adafruit_SSD1306 display(OLED_DC, OLED_RESET, OLED_CS);
/*
 * OLED_DIN = MOSI1 = PA7
 * OLED_CLK = SCK1  = PA5
 * 
 */

int but1 = PA0;
int but2 = PA1;

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

int Gyro_X, Gyro_Y, Gyro_Z;

void setup()
{
  Serial.begin(115200);                     //USB Serial Debug Monitor
  //Wire.setClock(4000000);
  //Wire.begin();
  delay(250);

  
  pinMode(but1,INPUT_PULLUP);
  pinMode(but2,INPUT_PULLUP);

  attachInterrupt(but1, kesme1, CHANGE);
  attachInterrupt(but2, kesme2, CHANGE);

  pinMode(PA8,OUTPUT);
  pinMode(PA9,OUTPUT);

  analogWrite(PA8, 50);
  analogWrite(PA9, 150);

  /*Wire.beginTransmission(0x68);
  Wire.write(0x6B);
  Wire.write(0x00);
  Wire.endTransmission();*/
    
  display.begin(SSD1306_SWITCHCAPVCC);      //128x64 spi oled display init - splashscreen yükle.   
  display.clearDisplay();                   // Ekranı Sil
  display.display();                        //Göster

  intro();
}

void kesme1(void)
{
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(30,0);
  display.clearDisplay();
  display.println("KESME1");
  display.display(); 
}

void kesme2(void)
{
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(30,0);
  display.clearDisplay();
  display.println("KESME2");
  display.display(); 
}

void intro(void)
{
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(30,0);
  display.clearDisplay();
  display.println("WALL-E");
  display.display();
 
  //display.drawLine(x0, y0, x1, y1, WHITE);
  display.drawLine(10, 30, 32, 20, WHITE);
  display.drawLine(11, 30, 31, 20, WHITE);
  display.drawLine(12, 30, 30, 20, WHITE);
  display.drawLine(13, 30, 29, 20, WHITE);
  display.drawLine(14, 30, 28, 20, WHITE);

  
  display.drawLine(54, 30, 32, 20, WHITE);
  display.drawLine(53, 30, 33, 20, WHITE);
  display.drawLine(52, 30, 34, 20, WHITE);
  display.drawLine(51, 30, 35, 20, WHITE);
  display.drawLine(50, 30, 36, 20, WHITE);

  //--------------------------------------------

  display.drawLine(74, 30, 96, 20, WHITE);
  display.drawLine(75, 30, 95, 20, WHITE);
  display.drawLine(76, 30, 94, 20, WHITE);
  display.drawLine(77, 30, 93, 20, WHITE);
  display.drawLine(78, 30, 92, 20, WHITE);

  
  display.drawLine(118, 30, 96, 20, WHITE);
  display.drawLine(117, 30, 97, 20, WHITE);
  display.drawLine(116, 30, 98, 20, WHITE);
  display.drawLine(115, 30, 99, 20, WHITE);
  display.drawLine(114, 30, 100, 20, WHITE);
  
  display.display();


  for (int16_t i=10; i<15; i+=1)
  {
     display.drawCircle(32, 45, i, WHITE);
     display.drawCircle(96, 45, i, WHITE);
     display.display();
  }
}

void loop()
{
  /*Wire.beginTransmission(0x68);
  Wire.write(0x43);
  Wire.endTransmission();
  Wire.requestFrom(0x68,6);

  Gyro_X = Wire.read()<<8 | Wire.read();
  Gyro_Y = Wire.read()<<8 | Wire.read();
  Gyro_Z = Wire.read()<<8 | Wire.read();

  Serial.print("X = ");
  Serial.print(Gyro_X);

  Serial.print(" Y = ");
  Serial.print(Gyro_Y);

  Serial.print(" Z = ");
  Serial.println(Gyro_Z);

  delay(50);*/
  
}



















  
