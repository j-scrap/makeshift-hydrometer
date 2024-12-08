#include "brix_calcs.h"

float current_brix(float temperature, float weight) {
	float density = (SUSPENDED_WEIGHT_WEIGHT - weight) / SUSPENDED_WEIGHT_VOLUME;

	// equation from: https://beermaverick.com/brix-plato-specific-gravity-converter/
	return (((182.4601 * density -775.6821) * density +1262.7794) * density -669.5622);
}

float desired_brix(float temperature) {
	return (688.0 - temperature) / 10.0;
}
