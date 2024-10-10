#include "Checker.h"

bool isTemperatureWithinRange(float temperature, std::string &message) {
    if (temperature < 0) {
        message = "Temperature too low!";
        return false;
    } else if (temperature > 45) {
        message = "Temperature too high!";
        return false;
    }
    return true;
}
 
bool isSOCWithinRange(float soc, std::string &message) {
    if (soc < 20) {
        message = "State of Charge too low!";
        return false;
    } else if (soc > 80) {
        message = "State of Charge too high!";
        return false;
    }
    return true;
}
 
bool isChargeRateOK(float chargeRate, std::string &message) {
    if (chargeRate > 0.8) {
        message = "Charge Rate too high!";
        return false;
    }
    return true;
}

bool isTemperatureAndSOCWithinRange(float temperature, float soc, std::string &message) {
	if(isTemperatureWithinRange(temperature, message) && isSOCWithinRange(soc, message)) {
		return true;
	}
	else {
		return false;
	}

}
 
bool performCheck(float temperature, float soc, float chargeRate, std::string &message) {
    if(isTemperatureAndSOCWithinRange(temperature, soc, message) && isChargeRateOK(chargeRate, message)) {
		return true;
	}
	else {
		return false;
	}
}

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

void displayWarningIfWithinRange(float temperature, float soc, std::string &warning) {
	displayLowTempratureWarningIfInRange(temperature, warning);
	displayHighTempratureWarningIfInRange(temperature, warning);
	displaySOCDischargeWarningIfInRange(soc, warning);
	displaySOCChargePeakWarningIfInRange(soc, warning);
}
 
bool isBatteryOk(float temperature, float soc, float chargeRate, std::string &message, std::string &warning) {
    bool allChecksOk = performCheck(temperature, soc, chargeRate, message);
 
    if (allChecksOk) {
        message = "Battery is OK.";
	    displayWarningIfWithinRange(temperature, soc, chargeRate, warning);
		return true;
    }
	else {
		return false;
	}
}
