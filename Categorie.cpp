#include <string>

#include "Categorie.h"

const int Categorie::MAX_NOTES;

Categorie::Categorie(const std::string& n, Categorie* p) :
	nom{n},
	parente{p}
{
	for (int i=0 ; i<MAX_NOTES ; i++) {
		notes[i] = nullptr;
	}
}

const std::string& Categorie::getNom() const
{
	return nom;
}

void Categorie::setNom(const std::string& n)
{
	nom = n;
}

Categorie* Categorie::getParente() const
{
	return parente;
}

bool Categorie::ajouterNote(Note* n)
{
	// on parcourt le tableau jusqu'à trouver une case vide, s'il n'y en a
	// pas, on renvoie false
	bool ret = false;
	for (int i=0 ; i<Categorie::MAX_NOTES ; i++) {
		if (notes[i] == nullptr) {
			ret = true;
			notes[i] = n;
			break;
		}
	}
	return ret;
}

std::ostream& operator<<(std::ostream& os, const Categorie& cat)
{
	os << cat.nom << "\n";
	for (int i=0 ; i<Categorie::MAX_NOTES ; i++) {
		// Attention, on ne doit jamais déréférencer un pointeur nul !
		if (cat.notes[i] != nullptr) {
			os << (*cat.notes[i]) << "\n";
		}
	}
	return os;
}
