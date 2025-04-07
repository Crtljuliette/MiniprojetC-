#ifndef PHOTO_H
#define PHOTO_H

#include <string>

#include "PieceJointe.h"

class Photo : public PieceJointe
{
private:
	std::string legende;

public:
	Photo(const std::string& legende);
	~Photo();
	const std::string& getTitre() const;
};

#endif
