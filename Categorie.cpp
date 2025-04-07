#include <string>
#include <vector>

#include "Categorie.h"

Categorie::Categorie(const std::string& n) :
	m_nom{n},
	m_parente{nullptr}
{}

const Categorie* getCategorieParente()
{
	return m_parente;
}

void Categorie::ajouterNote(const Note* note)
{
	m_notes.push_back(note);
}

std::string Categorie::getNom() const
{
	return m_nom;
}

void Categorie::setNom(const std::string& n)
{
	m_nom = n;
}
