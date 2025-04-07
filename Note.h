#ifndef NOTE_H
#define NOTE_H

#include <iostream>
#include <string>
#include <chrono>

#include "PieceJointe.h"

class Note
{
private:
	std::string titre;
	std::string contenu;
	std::chrono::system_clock::time_point horodatage;
	static const int MAX_PIECES_JOINTES = 10;
	PieceJointe* piecesJointes[MAX_PIECES_JOINTES];

public:
	Note(const std::string& t = "", const std::string& c = "");
	Note(const Note& note);
	Note(Note&& note);
	~Note();
	void operator=(const Note& n);
	void operator=(Note&& n);
	const std::string& getTitre() const;
	const std::string& getContenu() const;
	const std::chrono::system_clock::time_point getHorodatage() const;
	auto affichageHorodatage() const;
	void setTitre(const std::string& t);
	void ajouterContenu(const std::string& c);
	void viderContenu();
	bool ajouterPieceJointe(PieceJointe* p);
	int getNbPiecesJointes() const;
	PieceJointe* getPieceJointe(int i) const;
};

std::ostream& operator<<(std::ostream& os, const Note& n);

#endif /* NOTE_H */
