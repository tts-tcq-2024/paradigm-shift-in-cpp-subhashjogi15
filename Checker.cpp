#include "Checker.h"
#include "DisplayWarnings.h"

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

 bool isBatteryOk(float temperature, float soc, float chargeRate, std::string &message, std::string &warning) {
    bool allChecksOk = performCheck(temperature, soc, chargeRate, message);
 
    if (allChecksOk) {
        message = "Battery is OK.";
	    displayWarningsforTempratureAndSOC(temperature, soc, warning);
		return true;
    }
	else {
		return false;
	}
}
