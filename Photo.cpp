#include <iostream>
#include <string>

#include "Photo.h"

Photo::Photo(const std::string& l) :
	legende{l}
{
}

Photo::~Photo()
{
	std::cout << "Appel au destructeur de Photo" << std::endl;
}

const std::string& Photo::getTitre() const
{
	return legende;
}
