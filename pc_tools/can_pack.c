#include "can_pack.h"
#include <stdio.h>
#include <stdint.h>
#include <math.h>


void pack_u16(uint8_t *data, int offset,uint16_t value){
    uint8_t low_byte = value & 0xFF;
    uint8_t high_byte = (value >> 8) & 0xFF;
    data[offset]=low_byte;
    data[offset+1]=high_byte;
}

void pack_i16(uint8_t *data, int offset,int16_t value){
    pack_u16(data,offset,(uint16_t)value);
}

uint16_t unpack_u16(const uint8_t *data, int offset){
    uint16_t value = (data[offset+1]<<8 | data[offset]);
    return value;
}

int16_t unpack_i16(const uint8_t *data,int offset){
    return (int16_t)unpack_u16(data,offset);
}

void pack_temp(uint8_t *data,int offset,float temp_in){
    int16_t value=(int16_t)roundf(temp_in*10);
    pack_i16(data,offset,value);
}

float unpack_temp(const uint8_t *data,int offset){
    return unpack_i16(data,offset)/10.0f;
}

void pack_accel(uint8_t *data,int16_t ax, int16_t ay, int16_t az){
    pack_i16(data,0,ax);
    pack_i16(data,2,ay);
    pack_i16(data,4,az);
}

void unpack_accel(const uint8_t *data, int16_t *ax,int16_t *ay,int16_t *az){
    *ax=unpack_i16(data,0);
    *ay=unpack_i16(data,2);
    *az=unpack_i16(data,4);
}

void pack_speed(uint8_t *data,int offset,uint16_t speed_in){
    pack_u16(data,offset,speed_in);
}

uint16_t unpack_speed(const uint8_t *data,int offset){
    return unpack_u16(data,offset);
}

static void frame_init(can_frame_t *frame,uint16_t id,uint8_t dlc){
    for (int i=0;i<8;i++){
        frame->data[i]=0;
    }
    frame->id=id;
    frame->dlc=dlc;
}

void make_temp_frame(can_frame_t *frame,float temp){
    frame_init(frame,CAN_ID_TEMP,2);
    pack_temp(frame->data,0,temp);

}

void make_accel_frame(can_frame_t *frame, int16_t ax,int16_t ay,int16_t az){
    frame_init(frame,CAN_ID_ACCEL,6);
    pack_accel(frame->data,ax,ay,az);
}

void make_speed_frame(can_frame_t *frame,uint16_t speed_in){
    frame_init(frame,CAN_ID_SPEED,2);
    pack_speed(frame->data,0,speed_in);
}

void handle_frame(const can_frame_t *frame){
    switch (frame->id)
    {
    case CAN_ID_TEMP:
        if (frame->id<2){
            printf("Hibás dlc!");
            break;
        }
        float temp = unpack_temp(frame->data,0);
        printf("%.1f°C",temp);
        break;
    case CAN_ID_ACCEL:{
        if (frame->id<6){
            printf("Hibás dlc!");
            break;
        }
        int16_t rx;
        int16_t ry;
        int16_t rz;
        unpack_accel(frame->data,&rx,&ry,&rz);
        printf("%d mg",rx);
        printf("%d mg",ry);
        printf("%d mg",rz);
        break;
    }
    case CAN_ID_SPEED:
        if (frame->id<2){
            printf("Hibás dlc!");
            break;
        }
        uint16_t speed= unpack_speed(frame->data,0);
        printf("%d km/h",speed);
        break;
    default:
        printf("Ismeretlen ID!");
        break;
    }
}