#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "can_pack.h"
#include "sensor_logic.h"
#include <assert.h>


int main(void){
    // uint8_t data[8] = {0};
    // pack_temp(23.4,data);
    // printf("0x%02X\n",data[0]);
    // printf("0x%02X\n",data[1]);

    // uint8_t data[8] = {0};
    // float test[]= {23.4f, 3500.0f, 105.7f, -12.5f};
    // for (int i=0;i<sizeof(test)/sizeof(test[0]);i++){
    //     pack_temp(test[i],data);
    //     printf("%.1f ",test[i]);
    //     printf("%02X ",data[0]);
    //     printf("%02X ",data[1]);
    //     printf("%.1f\n",unpack_temp(data));
    // }
    // float temp=23.4;

    // uint16_t speed=52.3;

    // int16_t ax=120;
    // int16_t ay= -30;
    // int16_t az= 1000;

    // can_frame_t frame_temp;
    // can_frame_t frame_accel;
    // can_frame_t frame_speed;

    // make_temp_frame(&frame_temp,temp);
    // make_accel_frame(&frame_accel,ax,ay,az);
    // make_speed_frame(&frame_speed,speed);

    // handle_frame(&frame_temp);
    // handle_frame(&frame_accel);
    // handle_frame(&frame_speed);

    // // printf("%02X %02X ",frame_temp.data[0],frame_temp.data[1]);
    // // printf("%02X %02X ",frame_accel.data[0],frame_accel.data[1]);
    // // printf("%02X %02X ",frame_speed.data[0],frame_speed.data[1]);
    // printf("\n");

    // imu_raw_to_mg teszt
    // int16_t in[]       = {16384, -16384, 0, 8192, 27, -27, 32767, -32768};
    // int16_t expected[] = { 1000,  -1000, 0,  500,  2,  -2,  2000,  -2000};

    // for (size_t i = 0; i < sizeof(in) / sizeof(in[0]); i++) {
    //     int16_t result = imu_raw_to_mg(in[i]);
    //     printf("raw: %6d  mg: %5d  várt: %5d\n", in[i], result, expected[i]);
    //     assert(result == expected[i]);
    // }   
    // printf("imu_raw_to_mg: minden teszt rendben\n");
    filter_t filter;
    filter_init(&filter,0.05);
    float tomb[]={0,0,0,1000,1000,1000,1000,1000,1000};
    for (size_t i=0;i<(sizeof(tomb)/sizeof(tomb[i]));i++){
        printf("%.1f\n",filter_update(&filter,tomb[i]));
    }
    return 0;
}


