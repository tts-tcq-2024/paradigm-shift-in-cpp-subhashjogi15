#include "DisplayWarnings.h"
 
void displayLowTempratureWarningIfInRange(float temperature, std::string &warning) {
	if ((temperature > 0) && (temperature < 2.25)) {
		warning = "Warning: Approaching Low temperature!";
	}
}

void displayHighTempratureWarningIfInRange(float temperature, std::string &warning) {
	if ((temperature > 42.75) && (temperature < 45)) {
		warning = "Warning: Approaching High temperature!";
	}
}

void displaySOCDischargeWarningIfInRange(float soc, std::string &warning) {
	if ((soc > 20) && (soc < 24)){
		warning = warning + " and " + "Warning: Approaching discharge!";
	}
}

void displaySOCChargePeakWarningIfInRange(float soc, std::string &warning) {
	if ((soc > 76) && (soc < 80)) {
		warning = warning + " and " + "Warning: Approaching charge-peak!";
	}
}

void displayWarningsforTempratureAndSOC(float temperature, float soc, std::string &warning) {
	displayLowTempratureWarningIfInRange(temperature, warning);
	displayHighTempratureWarningIfInRange(temperature, warning);
	displaySOCDischargeWarningIfInRange(soc, warning);
	displaySOCChargePeakWarningIfInRange(soc, warning);
}
