#include <iostream>
#include <string>

class PieceJointe
{
protected:
	std::string fichier;

public:
	PieceJointe(const std::string& fichier);
	~PieceJointe();
};
