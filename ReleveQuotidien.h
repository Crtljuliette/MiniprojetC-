#include <iostream>
#include <string>

class ReleveQuotidien
{
private:
	float temperatures[24];
	int humidites[24];
	float temperaturesVeille[6];
	float temperaturesLendemain[7];
	std::string date;

public:
	static float pointDeRosee(float temperature, int humidite);

	float getTemperature(int heure) const;
	int getHumidite(int heure) const;
	void setMesure(int heure, float temperature, int humidite);
	float getPointDeRosee(int heure) const;

	const std::string& getDate() const;
	void setDate(const std::string& date);

	void setTemperatureVeille(int heure, float temperature);
	void setTemperatureLendemain(int heure, float temperature);

	float getTemperatureMinimale() const;
	float getTemperatureMaximale() const;
};

std::ostream& operator<<(std::ostream& os, const ReleveQuotidien& r);
