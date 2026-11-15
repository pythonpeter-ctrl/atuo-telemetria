#ifndef CAN_PACK_H
#define CAN_PACK_H
#include <stdint.h>

void pack_i16(uint8_t *data, int offset,int16_t value);

int16_t unpack_i16(const uint8_t *data,int offset);

void pack_temp(float temp_in,uint8_t *data,int offset);

float unpack_temp(const uint8_t *data,int offset);

void pack_accel(int16_t ax, int16_t ay, int16_t az, uint8_t *data);

void unpack_accel(const uint8_t *data, int16_t *ax,int16_t *ay,int16_t *az);

#endif