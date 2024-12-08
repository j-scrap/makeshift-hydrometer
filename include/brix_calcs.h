#ifndef BRIX_CALCS_H
#define BRIX_CALCS_H

const int SUSPENDED_WEIGHT_WEIGHT = 2000;
const int SUSPENDED_WEIGHT_VOLUME = 257;

float current_brix(float temperature, float weight);
float desired_brix(float temperature);

#endif /* BRIX_CALCS_H */
