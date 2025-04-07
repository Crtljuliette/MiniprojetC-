#ifndef PIECE_JOINTE_H
#define PIECE_JOINTE_H

#include <string>

class PieceJointe
{
public:
	virtual const std::string& getTitre() const = 0;
	virtual ~PieceJointe();
};

#endif
