#ifndef CATEGORIE_H
#define CATEGORIE_H

#include <string>

#include "Note.h"

class Categorie
{
private:
	std::string nom;
	Categorie* parente;
	static const int MAX_NOTES = 10;
	Note* notes[MAX_NOTES];

public:
	Categorie(const std::string& n, Categorie* p = nullptr);
	const std::string& getNom() const;
	void setNom(const std::string& s);
	Categorie* getParente() const;
	bool ajouterNote(Note* n);

friend std::ostream& operator<<(std::ostream& os, const Categorie& cat);
};

std::ostream& operator<<(std::ostream& os, const Categorie& cat);

#endif
