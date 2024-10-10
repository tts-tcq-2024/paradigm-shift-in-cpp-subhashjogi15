#include "Soundex.h"
#include <cassert>
using namespace std;

void testisBatteryOk() {
    std::string message;
	std::string warning;
 
    // Test case where battery is OK and display warning of Low Temprature
    assert(isBatteryOk(2.2, 70, 0.7, message, warning) == true);
    assert(message == "Battery is OK.");
	assert(warning == "Warning: Approaching Low temperature!");

	// Test case where battery is OK and display warning of high Temprature
    assert(isBatteryOk(43, 70, 0.7, message, warning) == true);
    assert(message == "Battery is OK.");
	assert(warning == "Warning: Approaching High temperature!");
		
	// Test case where battery is OK and display warning of Low Temprature and Approaching SOC discharge
    assert(isBatteryOk(2.2, 22, 0.7, message, warning) == true);
    assert(message == "Battery is OK.");
	assert(warning == "Warning: Approaching Low temperature! and Warning: Approaching discharge!");

	// Test case where battery is OK and display warning of High Temprature and Approaching SOC peak charge
    assert(isBatteryOk(43, 78, 0.7, message, warning) == true);
    assert(message == "Battery is OK.");
	assert(warning == "Warning: Approaching High temperature! and Warning: Approaching charge-peak!");

    // Test case where temperature is too low
    assert(isBatteryOk(-1, 70, 0.7, message, warning) == false);
    assert(message == "Temperature too low!");
 
    // Test case where temperature is too high
    assert(isBatteryOk(50, 70, 0.7, message, warning) == false);
    assert(message == "Temperature too high!");
 
    // Test case where SOC is too low
    assert(isBatteryOk(25, 10, 0.7, message, warning) == false);
    assert(message == "State of Charge too low!");
 
    // Test case where SOC is too high
    assert(isBatteryOk(25, 100, 0.7, message, warning) == false);
    assert(message == "State of Charge too high!");
 
    // Test case where charge rate is too high
    assert(isBatteryOk(25, 70, 0.9, message, warning) == false);
    assert(message == "Charge Rate too high!");
}
 
int main() {
    testisBatteryOk();
    cout << "All tests passed.\n";
    return 0;
}
