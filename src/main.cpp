#include <Arduino.h>
// #include <EEPROM.h>
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <multiCameraIrControl.h>
#include <AccelStepper.h>

/**
 * The PITCH stepper utilizes the Y stepper driver on the RAMPS 1.4 board.
 */
#define PITCH_DIR 61
#define PITCH_ENABLE 56
#define PITCH_STEP 60

/**
 * The YAW stepper utilizes the Z stepper driver on the RAMPS 1.4 board.
 */
#define YAW_DIR 48
#define YAW_ENABLE 62
#define YAW_STEP 46

void setup()
{
  pinMode(PITCH_DIR, OUTPUT);
  pinMode(PITCH_STEP, OUTPUT);
  pinMode(PITCH_ENABLE, OUTPUT);

  pinMode(YAW_DIR, OUTPUT);
  pinMode(YAW_STEP, OUTPUT);
  pinMode(YAW_ENABLE, OUTPUT);

  digitalWrite(YAW_ENABLE, HIGH);
  digitalWrite(PITCH_ENABLE, HIGH);

  Serial.begin(9600);
}

const int stepsPerRevolution = 200;

void loop()
{
  digitalWrite(PITCH_DIR, HIGH);
  digitalWrite(YAW_DIR, HIGH);

  for (int x = 0; x < stepsPerRevolution; x++)
  {
    digitalWrite(YAW_STEP, HIGH);
    digitalWrite(PITCH_STEP, HIGH);

    delayMicroseconds(2000);

    digitalWrite(YAW_STEP, LOW);
    digitalWrite(PITCH_STEP, LOW);

    delayMicroseconds(2000);
  }

  delay(1000);
}