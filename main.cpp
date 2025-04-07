#include <iostream>
#include <cmath>

#include "ReleveQuotidien.h"

float TEMPERATURES[] =
{
	// 1er janvier (de 00h à 23h UTC)
	-0.7, -1.7, -2.5, -2.7, -3.1, -2.7, -2.5, -2.8, -2.6, -1.8, -2.1, -1.7,
	0.1, 2.4, 4.3, 5.3, 5.5, 4.9, 3.5, 3.0, 1.4, 0.3, -0.5, -1.4,

	// 2 janvier
	-1.3, -1.1, -1.3, -1.4, -1.4, -1.3, -1.9, -2.5, -2.7, -3.2, -2.6,
	-2.0, 0.1, 2.6, 3.0, 4.5, 5.4, 5.4, 4.7, 4.6, 4.3, 3.1, 2.6, 1.9,

	// 3 janvier
	1.7, 1.5, 1.6, 1.4, 1.5, 0.8, 0.5, 0.4, 0.6, 0.1, -0.1, -0.5,
	0.4, 2.0, 3.6, 3.9, 4.4, 4.3, 4.4, 3.8, 4.2, 3.8, 2.5, 2.0,

	// 4 janvier
	0.5, 1.5, 0.4, 0.5, 0.0, 0.5, 1.5, 1.4, 0.7, 0.9, 1.2, 1.5,
	1.7, 2.3, 3.6, 3.9, 3.5, 3.4, 3.0, 2.7, 2.2, 2.2, 2.1, 2.3,

	// 5 janvier
	2.3, 2.3, 2.3, 2.3, 2.3, 2.5, 1.6, 1.8, 1.1, 0.7, 0.3, 0.3,
	2.7, 4.2, 4.0, 4.7, 4.7, 4.3, 4.0, 3.6, 3.5, 3.1, 2.9, 2.9,

	// 6 janvier 00h
	2.7
};

int HUMIDITES[] =
{
	// 1er janvier
	99, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97,
	95, 89, 76, 69, 68, 71, 75, 80, 87, 93, 95, 97,

	// 2 janvier
	97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97,
	99, 93, 93, 91, 90, 91, 93, 95, 88, 95, 95, 95,

	// 3 janvier
	95, 95, 95, 95, 97, 97, 97, 97, 99, 99, 99, 99,
	99, 97, 91, 89, 89, 84, 83, 84, 79, 79, 84, 87,

	// 4 janvier
	92, 91, 92, 90, 95, 92, 89, 91, 97, 97, 95, 95,
	97, 93, 87, 83, 87, 87, 86, 87, 91, 91, 93, 91,

	// 5 janvier
	91, 91, 91, 91, 89, 87, 91, 89, 91, 93, 92, 92,
	87, 80, 83, 79, 74, 75, 79, 80, 80, 83, 84, 82,

	// 6 janvier 00h
	84
};


float pointDeRosee(float temperature, int humidite)
{
	float a = 17.27;
	float b = 237.7;

	float alpha = (a * temperature) / (b + temperature) + std::log(humidite / 100.0);
	float pdr = (b * alpha) / (a - alpha);

	return pdr;
}

void temperaturesMinMax(int jour)
{
	int heureMinimale = 0;
	int heureMaximale = 5 * 24;

	std::cout << (jour + 1) << " janvier\n---------\n";

	bool minimumDispo = true;
	float minimum = TEMPERATURES[jour * 24];
	for (int heure = jour * 24 - 6 ; heure <= jour * 24 + 18 ; heure++) {
		if (heure < heureMinimale || heure > heureMaximale) {
			minimumDispo = false;
			break;
		} else if (TEMPERATURES[heure] < minimum) {
			minimum = TEMPERATURES[heure];
		}
	}
	if (minimumDispo) {
		std::cout << "min : " << minimum << "°C, ";
	} else {
		std::cout << "min : --°C, ";
	}

	bool maximumDispo = true;
	float maximum = TEMPERATURES[jour * 24];
	for (int heure = jour * 24 + 6 ; heure <= (jour + 1) * 24 + 6 ; heure++) {
		if (heure < heureMinimale || heure > heureMaximale) {
			maximumDispo = false;
			break;
		} else if (TEMPERATURES[heure] > maximum) {
			maximum = TEMPERATURES[heure];
		}
	}
	if (maximumDispo) {
		std::cout << "max : " << maximum << "°C\n";
	} else {
		std::cout << "max : --°C\n";
	}
	std::cout << std::endl;
}

int main()
{
	temperaturesMinMax(3);
	temperaturesMinMax(4);


	ReleveQuotidien releve4Janvier;

	releve4Janvier.setDate("4 janvier 2021");
	for (int h = 3 * 24 ; h < 4 * 24 ; h++) {
		releve4Janvier.setMesure(h - 3*24, TEMPERATURES[h], HUMIDITES[h]);
	}
	for (int h = 2 * 24 + 18 ; h < 3 * 24 ; h++) {
		releve4Janvier.setTemperatureVeille(h - 2*24, TEMPERATURES[h]);
	}
	for (int h = 4 * 24 ; h <= 4 * 24 + 6 ; h++) {
		releve4Janvier.setTemperatureLendemain(h - 4*24, TEMPERATURES[h]);
	}

	std::cout << releve4Janvier << std::endl;
}
