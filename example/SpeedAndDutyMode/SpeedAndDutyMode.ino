#include "RMRC_BreakoutV2.h"

RMRC_BreakoutV2 m1(M1M2_ADDR, MOTOR_1), m2(M1M2_ADDR, MOTOR_2);
// m3(M3M4_ADDR, MOTOR_3), m4(M3M4_ADDR, MOTOR_4);

#define MAXIMUM_SHAFT_RPM 294.0f
#define GEAR_RATIO        34.0f

void setup() {
  delay(400);
  Serial.begin(115200);

  m1.begin();
  m2.begin();
  // m3.begin();
  // m4.begin();

  m1.setMotorMode(SPEED_AND_DUTY);
  m2.setMotorMode(SPEED_AND_DUTY);
  // m3.setMotorMode(SPEED_AND_DUTY);
  // m4.setMotorMode(SPEED_AND_DUTY);

  m1.setDuty(0);
  m2.setDuty(0);
  // m3.setDuty(0);
  // m4.setDuty(0);

  m1.setEncoderResolution(11.0f);
  m2.setEncoderResolution(11.0f);
  // m3.setEncoderResolution(11.0f);
  // m4.setEncoderResolution(11.0f);

  m1.setMaximumRPM(MAXIMUM_SHAFT_RPM * GEAR_RATIO);
  m2.setMaximumRPM(MAXIMUM_SHAFT_RPM * GEAR_RATIO);
  // m3.setMaximumRPM(MAXIMUM_SHAFT_RPM * GEAR_RATIO);
  // m4.setMaximumRPM(MAXIMUM_SHAFT_RPM * GEAR_RATIO);

  // if you want to using default value of kp, ki and kd just delete or comment function under this line.
  //  m1.setKp(0.0f);
  //  m1.setKi(0.0f);
  //  m1.setKd(0.0f);
  //
  //  m2.setKp(0.0f);
  //  m2.setKi(0.0f);
  //  m2.setKd(0.0f);

  // m3.setKp(0.0f);
  // m3.setKi(0.0f);
  // m3.setKd(0.0f);

  // m4.setKp(0.0f);
  // m4.setKi(0.0f);
  // m4.setKd(0.0f);
}

void loop() {
  // setDuty: range -16999 to 16999.
  // m1.setDuty(0);
  // m2.setDuty(0);
  // m3.setDuty(0);
  // m4.setDuty(0);

  //setRPM: range -maximum_rpm to maximum_rpm
  m1.setRPM(0.0f);
  m2.setRPM(0.0f);
  // m3.setRPM(0.0f);
  // m4.setRPM(0.0f);

  Serial.print("m1->RPM = "); Serial.println(m1.rpm);
  Serial.print("m2->RPM = "); Serial.println(m2.rpm);
  // Serial.print("m3->RPM = "); Serial.println(m3.rpm);
  // Serial.print("m4->RPM = "); Serial.println(m4.rpm);
}
