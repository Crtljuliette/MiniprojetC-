#ifndef NOTE_H
#define NOTE_H

#include <iostream>
#include <string>
#include <chrono>
#include <vector>

class Categorie;
class PieceJointe;

class Note
{
private:
	// Attributs :
	std::string m_titre;
	std::string m_contenu;
	std::chrono::system_clock::time_point m_dateCreation;
	std::vector<const PieceJointe*> m_piecesJointes;
	Categorie m_categorie;

public:
	// Méthodes :
	Note(const Categorie& categorie, const std::string& titre, const std::string& contenu  = std::string{});
	std::string getTitre() const;
	void setTitre(const std::string&);
	std::string getContenu() const;
	void setContenu(const std::string&);
	const std::chrono::system_clock::time_point getDate() const;
	void ajouterPieceJointe(const PieceJointe* pieceJointe);

friend std::ostream& operator<<(std::ostream& os, const Note& note);
};

std::ostream& operator<<(std::ostream& os, const Note& note);


// Les méthodes publiques et la surcharge de l'opérateur d'affichage constituent
// l'interface de la classe.

#endif
