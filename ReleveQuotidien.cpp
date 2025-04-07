#include <iostream>
#include <string>
#include <cmath>

#include "ReleveQuotidien.h"

float ReleveQuotidien::pointDeRosee(float temperature, int humidite)
{
	float a = 17.27;
	float b = 237.7;

	float alpha = (a * temperature) / (b + temperature) + std::log(humidite / 100.0);
	float pdr = (b * alpha) / (a - alpha);

	return pdr;
}

float ReleveQuotidien::getTemperature(int heure) const
{
	if (heure >= 0 && heure < 24) {
		return temperatures[heure];
	} else {
		std::cerr << "Heure incorrecte" << std::endl;
		return -99;
	}
}

int ReleveQuotidien::getHumidite(int heure) const
{
	if (heure >= 0 && heure < 24) {
		return humidites[heure];
	} else {
		std::cerr << "Heure incorrecte" << std::endl;
		return -99;
	}
}

void ReleveQuotidien::setMesure(int heure, float temperature, int humidite)
{
	if (heure >= 0 && heure < 24) {
		temperatures[heure] = temperature;
		humidites[heure] = humidite;
	} else {
		std::cerr << "Heure incorrecte" << std::endl;
	}
}

float ReleveQuotidien::getPointDeRosee(int heure) const
{
	if (heure >= 0 && heure < 24) {
		return pointDeRosee(temperatures[heure], humidites[heure]);
	} else {
		std::cerr << "Heure incorrecte" << std::endl;
		return -99;
	}
}

const std::string& ReleveQuotidien::getDate() const
{
	return date;
}

void ReleveQuotidien::setDate(const std::string& d)
{
	date = d;
}

void ReleveQuotidien::setTemperatureVeille(int heure, float temperature)
{
	// dans le tableau : case 0 <-> 18h, case 1 <-> 19h...
	if (heure >= 18 && heure < 24) {
		temperaturesVeille[heure - 18] = temperature;
	} else {
		std::cerr << "Heure incorrecte" << std::endl;
	}
}

void ReleveQuotidien::setTemperatureLendemain(int heure, float temperature)
{
	if (heure >= 0 && heure <= 6) {
		temperaturesLendemain[heure] = temperature;
	} else {
		std::cerr << "Heure incorrecte" << std::endl;
	}
}

float ReleveQuotidien::getTemperatureMinimale() const
{
	float minimum = temperaturesVeille[0];
	for (int h=0 ; h<6 ; h++) {
		if (temperaturesVeille[h] < minimum) {
			minimum = temperaturesVeille[h];
		}
	}

	for (int h=0 ; h<=18 ; h++) {
		if (temperatures[h] < minimum) {
			minimum = temperatures[h];
		}
	}

	return minimum;
}

float ReleveQuotidien::getTemperatureMaximale() const
{
	float maximum = temperatures[6];
	for (int h=6 ; h<24 ; h++) {
		if (temperatures[h] > maximum) {
			maximum = temperatures[h];
		}
	}

	for (int h=0 ; h<=6 ; h++) {
		if (temperaturesLendemain[h] > maximum) {
			maximum = temperaturesLendemain[h];
		}
	}

	return maximum;
}

std::ostream& operator<<(std::ostream& os, const ReleveQuotidien& r)
{
	os << r.getDate() << "\n\n";

	for (int h=0 ; h<24 ; h++) {
		os << h << "h" << " -- "
			 << "Température : " << r.getTemperature(h) << "°C" << " -- "
			 << "Humidité : " << r.getHumidite(h) << "%" << " -- "
			 << "Point de rosée : " << r.getPointDeRosee(h) << "°C" << "\n";
	}

	os << "\n"
		<< "Température minimale : " << r.getTemperatureMinimale() << "°C" << "\n"
		<< "Température maximale : " << r.getTemperatureMaximale() << "°C" << "\n";

	os << std::endl;

	return os;
}
