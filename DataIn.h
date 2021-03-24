#pragma once

struct Joystick {
    uint8_t left;
    uint8_t right;
    uint8_t down;
    uint8_t up;  

    uint8_t reserved_1;
    uint8_t reserved_2;
    uint8_t reserved_3;
};

struct Mpu6050 {
    uint8_t left;
    uint8_t right;
    uint8_t down;
    uint8_t up;  
    int8_t temp;
};

struct DataIn {
    Joystick j1;
    Joystick j2;
    Mpu6050 mpu;
    uint8_t command_code;  
};
