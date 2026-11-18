#ifndef SENSOR_LOGIC_H
#define SENSOR_LOGIC_H
#include <stdint.h>

typedef struct{
    float alpha;
    float y;
    int initialized;
}filter_t;

int16_t imu_raw_to_mg(int16_t raw);

void filter_init(filter_t *filter,float alpha);

float filter_update(filter_t *filter,float x);

#endif