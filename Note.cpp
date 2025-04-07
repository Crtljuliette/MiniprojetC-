#include <iostream>
#include <string>
#include <chrono>
#include <vector>

#include "Note.h"
#include "Categorie.h"

Note::Note(const Categorie& categorie, const std::string& titre, const std::string& contenu) :
	m_titre{titre},
	m_contenu{contenu},
	m_dateCreation{std::chrono::system_clock::now()},
	m_categorie{categorie}
{
}

std::string Note::getTitre() const {
	return m_titre;
}

void Note::setTitre(const std::string& titre) {
	m_titre = titre;
}

std::string Note::getContenu() const {
	return m_contenu;
}

void Note::setContenu(const std::string& contenu) {
	m_contenu = contenu;
}

const std::chrono::system_clock::time_point Note::getDate() const
{
	return m_dateCreation;
}

void Note::ajouterPieceJointe(const PieceJointe* pieceJointe)
{
	m_piecesJointes.push_back(pieceJointe);
}

std::ostream& operator<<(std::ostream& os, const Note& note)
{
	os << note.m_titre << "\n"
	   << std::chrono::system_clock::to_time_t(note.m_dateCreation) << "\n"
	   << note.m_contenu << "\n";
	return os;
}
