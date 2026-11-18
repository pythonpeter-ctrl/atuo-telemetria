#include "sensor_logic.h"
#include <stdint.h>

int16_t imu_raw_to_mg(int16_t raw){
    int32_t value=0;
    if (raw>0){
        value=((int32_t)raw*1000+8192)/16384;
    }else if(raw<0){
        value=((int32_t)raw*1000-8192)/16384;
    }
    return (int16_t)value;
}

void filter_init(filter_t *filter,float alpha){
    filter->alpha=alpha;
    filter->y=0.0f;
    filter->initialized=0;
}

float filter_update(filter_t *filter,float x){
    if (!filter->initialized){
        filter->y=x;
        filter->initialized=1;
    }else{
        filter->y=filter->y+filter->alpha*(x-filter->y);
    }
    return filter->y;
}