#include "can_pack.h"
#include <stdint.h>
#include <math.h>

void pack_i16(uint8_t *data, int offset,int16_t value){
    uint8_t low_byte = (uint16_t)value & 0xFF;
    uint8_t high_byte = ((uint16_t)value >> 8) & 0xFF;
    data[offset]=low_byte;
    data[offset+1]=high_byte;
}

int16_t unpack_i16(const uint8_t *data,int offset){
    int16_t value = (data[offset+1]<<8 | data[offset]);
    return value;
}

void pack_temp(float temp_in,uint8_t *data,int offset){
    int16_t value=(int16_t)roundf(temp_in*10);
    pack_i16(data,offset,value);
}

float unpack_temp(const uint8_t *data,int offset){
    return unpack_i16(data,offset)/10.0f;
}

void pack_accel(int16_t ax, int16_t ay, int16_t az, uint8_t *data){
    pack_i16(data,0,ax);
    pack_i16(data,2,ay);
    pack_i16(data,4,az);
}

void unpack_accel(const uint8_t *data, int16_t *ax,int16_t *ay,int16_t *az){
    *ax=unpack_i16(data,0);
    *ay=unpack_i16(data,2);
    *az=unpack_i16(data,4);
}