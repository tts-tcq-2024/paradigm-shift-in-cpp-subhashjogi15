#ifndef CHECKER_H
#define CHECKER_H

#include <iostream>
#include <string>

bool isBatteryOk(float temperature, float soc, float chargeRate, std::string &message, std::string &warning);
#endif
