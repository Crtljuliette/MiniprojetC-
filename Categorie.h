#ifndef CATEGORIE_H
#define CATEGORIE_H

#include <string>
#include <vector>

class Note;

class Categorie
{
private:
	std::string m_nom;
	const Categorie* m_parente;
	void setParente(const Categorie* parente);
	std::vector<const Note*> m_notes;

public:
	Categorie(const std::string& nom);
	const Categorie* getCategorieParente();
	void ajouterNote(const Note* note);
	std::string getNom() const;
	void setNom(const std::string& nom);
};

#endif
