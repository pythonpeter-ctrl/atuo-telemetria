#ifndef CAN_PACK_H
#define CAN_PACK_H
#include <stdint.h>
#include <math.h>

#define CAN_ID_TEMP 0x100
#define CAN_ID_ACCEL 0x110
#define CAN_ID_SPEED 0x120

typedef struct{
    uint16_t id;
    uint16_t dlc;
    uint8_t data[8];
}can_frame_t;


void pack_u16(uint8_t *data, int offset,uint16_t value);

void pack_i16(uint8_t *data, int offset,int16_t value);

uint16_t unpack_u16(const uint8_t *data, int offset);

int16_t unpack_i16(const uint8_t *data,int offset);

void pack_temp(uint8_t *data,int offset,float temp_in);

float unpack_temp(const uint8_t *data,int offset);

void pack_accel( uint8_t *data,int16_t ax, int16_t ay, int16_t az);

void unpack_accel(const uint8_t *data, int16_t *ax,int16_t *ay,int16_t *az);

void pack_speed(uint8_t *data,int offset,uint16_t speed_in);

uint16_t unpack_speed(const uint8_t *data,int offset);

void make_temp_frame(can_frame_t *frame,float temp);

void make_accel_frame(can_frame_t *frame, int16_t ax,int16_t ay,int16_t az);

void make_speed_frame(can_frame_t *frame,uint16_t speed_in);

#endif