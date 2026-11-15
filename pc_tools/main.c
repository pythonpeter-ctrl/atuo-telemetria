#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "can_pack.h"


int main(void){
    // uint8_t data[8] = {0};
    // pack_temp(23.4,data);
    // printf("0x%02X\n",data[0]);
    // printf("0x%02X\n",data[1]);

    uint8_t data[8] = {0};
    // float test[]= {23.4f, 3500.0f, 105.7f, -12.5f};
    // for (int i=0;i<sizeof(test)/sizeof(test[0]);i++){
    //     pack_temp(test[i],data);
    //     printf("%.1f ",test[i]);
    //     printf("%02X ",data[0]);
    //     printf("%02X ",data[1]);
    //     printf("%.1f\n",unpack_temp(data));
    // }

    int16_t ax=-32768;
    int16_t ay= 32767;
    int16_t az= -1;

    int16_t rx;
    int16_t ry;
    int16_t rz;

    pack_accel(ax,ay,az,data);
    for (int i=0;i<6;i++){
        printf("%02X ",data[i]);
    }
    printf("\n");
    unpack_accel(data,&rx,&ry,&rz);
    printf("%d ",rx);
    printf("%d ",ry);
    printf("%d ",rz);
    printf("\n");
    return 0;
}
