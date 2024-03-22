// This library creating by "iRAP Robot" from "KMUTNB" for use in RMRC competition.

#ifndef RMRC_BREAKOUT_V2_h
#define RMRC_BREAKOUT_V2_h

#include <Arduino.h>
#include <Wire.h>
#include <MadgwickAHRS.h>

#if defined(ARDUINO_SAMD_NANO_33_IOT)
#include <Arduino_LSM6DS3.h>
#elif defined(ARDUINO_ARCH_NRF52840)
#include <Arduino_LSM9DS1.h>
#else 
#error "This code is intended for the Arduino Nano 33 IoT or Nano 33 BLE only."
#endif

#define MAXIMUM_DUTY (int16_t)(16999) 
#define M1M2_ADDR    (uint8_t)(0x12)
#define M3M4_ADDR (uint8_t)(0x13)
#define IMU_FEEDBACK_RATE (float)(104.0f) // Hz

typedef enum {
  NANO_IMU,
  MOTOR_1,
  MOTOR_2,
  MOTOR_3, 
  MOTOR_4
} MOTOR_ID;

typedef enum {
  SPEED_AND_DUTY = 1,
  POSITION_AND_DUTY
} MOTOR_MODE;

typedef enum {
  SET_DUTY = 0,
  SET_RPM,
  SET_KP,
  SET_KI,
  SET_KD,
  SET_OFFSET,
  SET_MIN_K_VALUE,
  SET_MAX_K_VALUE,
  GET_OFFSET,
  GET_K_ANGLE,
  SET_MOTOR_MODE,
  SET_ENCODER_RESOLUTION
} CONTROL_MODE;

typedef struct {
  uint8_t buf[9];
  uint8_t buf_count = 0;
  uint32_t asUint32_t = 0;
  uint16_t asUint16_t = 0;
  float *asFloatPtr = nullptr;
} I2C_message_t;

class RMRC_BreakoutV2 {
  public:
    RMRC_BreakoutV2(uint8_t _addr, MOTOR_ID _id);

    void setMotorMode(MOTOR_MODE _mode);
    void setEncoderResolution(uint16_t _resolution);
    void setMaximumRPM(float _max_rpm);

    void setDuty(int16_t _duty);
    void setRPM(float _rpm);

    void setKp(float _kp);
    void setKi(float _ki);
    void setKd(float _kd);

    void begin(void);

    uint8_t motor_addr = 0;
    uint8_t motor_id = 0;
    uint8_t motor_mode = 0;
    uint16_t encoder_resolution = 0;

    float maximum_rpm = 0.0f;
    float rpm = 0.0f;
    float position = 0.0f;

    struct PID_PARAM{
      float kp;
      float ki;
      float kd;
    }speed;

    void setOffset(int16_t _offset, int16_t _k_min, int16_t _k_max);

    int16_t getOffset(void);
    int16_t getKAngle(void);

  private:
    static bool initialized;
};

class RMRC_IMU : public RMRC_BreakoutV2 {
  public:
    RMRC_IMU(uint8_t _addr = 0x00, MOTOR_ID _id = NANO_IMU);

    void begin(void);

    float ax = 0.0f;
    float ay = 0.0f;
    float az = 0.0f;

    float gx = 0.0f;
    float gy = 0.0f;
    float gz = 0.0f;

    float yaw = 0.0f;
    float pitch = 0.0f;
    float roll = 0.0f;

    void update(void);
  private:
    Madgwick filter_imu;
    static bool initialized_imu;
};

#endif