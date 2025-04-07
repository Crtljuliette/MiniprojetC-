#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <string>

#include "Note.h"

Note::Note(const std::string& t, const std::string& c) :
	titre{t},
	contenu{c},
	horodatage{std::chrono::system_clock::now()}
{
	for (int i=0 ; i<MAX_PIECES_JOINTES ; i++) {
		piecesJointes[i] = nullptr;
	}
	std::cout << "Constructeur normal de note" << std::endl;
}

Note::Note(const Note& note) :
	titre{note.titre},
	contenu{note.contenu},
	horodatage{note.horodatage}
{
	// Attention, ce constructeur ne marche plus ici ! Les pièces-jointes
	// sont censées être responsables de leurs pièces-jointes donc ici, il
	// faudrait les dupliquer pour que chaque Note ait sa propre copie des
	// pièces-jointes, sinon on risque la double désallocation.
	/*for (int i=0 ; i<MAX_PIECES_JOINTES ; i++) {
		piecesJointes[i] = note.piecesJointes[i];
	}*/
	std::cout << "Constructeur par recopie de note" << std::endl;
}

Note::Note(Note&& note) :
	titre{std::move(note.titre)},
	contenu{std::move(note.contenu)},
	horodatage{std::move(note.horodatage)}
{
	for (int i=0 ; i<MAX_PIECES_JOINTES ; i++) {
		piecesJointes[i] = note.piecesJointes[i];
		// Paradoxalement, la construction par déplacement peut parfois
		// donner du travail que la recopie ne donne pas
		note.piecesJointes[i] = nullptr;
	}
	std::cout << "Constructeur par déplacement de note" << std::endl;
}

Note::~Note()
{
	for (int i=0 ; i<MAX_PIECES_JOINTES ; i++) {
		// On peut faire delete sur un pointeur null, ce n'est pas une
		// erreur (mais ça ne fait rien). Par contre faire un delete
		// sur un pointeur invalide, qui n'a pas été alloué
		// dynamiquement ou qui a déjà été désalloué est une erreur. Il
		// faut donc remettre les cases du tableau à nullptr après
		// désallocation pour éviter des double désallocations.
		delete piecesJointes[i];
		piecesJointes[i] = nullptr;
	}
	std::cout << "Destruction de la note \"" << titre << "\"" << std::endl;
}


void Note::operator=(const Note& n)
{
	// Bien sûr les attributs "titre", "contenu", etc. sont privés mais ici
	// nous sommes dans une méthode de la même classe ! Donc, nous y avons
	// accès, même dans d'autres objets Note que dans l'objet courant.
	titre = n.titre;
	contenu = n.contenu;
	horodatage = n.horodatage;
	/* Même problème que le constructeur par recopie, ici, la recopie des
	 * pièces-jointes pose problème. */
	std::cout << "Affectation par recopie de note" << std::endl;
}

void Note::operator=(Note&& n)
{
	titre = std::move(n.titre);
	contenu = std::move(n.contenu);
	horodatage = std::move(n.horodatage);
	for (int i=0 ; i<MAX_PIECES_JOINTES ; i++) {
		piecesJointes[i] = n.piecesJointes[i];
		n.piecesJointes[i] = nullptr;
	}
	std::cout << "Affectation par recopie de note" << std::endl;
}

const std::string& Note::getTitre() const
{
	return titre;
}

const std::string& Note::getContenu() const
{
	return contenu;
}

const std::chrono::system_clock::time_point Note::getHorodatage() const
{
	return horodatage;
}

void Note::setTitre(const std::string& t)
{
	titre = t;
}

void Note::ajouterContenu(const std::string& c)
{
	contenu += c;
}

void Note::viderContenu()
{
	contenu.clear();
}

auto Note::affichageHorodatage() const
{
	std::time_t t = std::chrono::system_clock::to_time_t(horodatage);
	return std::put_time(std::localtime(&t), "%F %T");
}

bool Note::ajouterPieceJointe(PieceJointe* p)
{
	bool ret = false;
	for (int i=0 ; i<MAX_PIECES_JOINTES ; i++) {
		if (piecesJointes[i] == nullptr) {
			ret = true;
			piecesJointes[i] = p;
			break;
		}
	}
	return ret;
}

int Note::getNbPiecesJointes() const
{
	// On parcourt le tableau depuis la fin pour trouver la première case
	// vide. Son indice est le nombre de pièces-jointes (tant qu'on le
	// remplit dans l'ordre)
	int ret = 0;
	for (int i=MAX_PIECES_JOINTES-1 ; i>=0 ; i--) {
		if (piecesJointes[i] != nullptr) {
			ret = i + 1;
			break;
		}
	}
	return ret;
}

PieceJointe* Note::getPieceJointe(int i) const
{
	if (i >= getNbPiecesJointes())
		return nullptr;
	return piecesJointes[i];
}

std::ostream& operator<<(std::ostream& os, const Note& n)
{
	os << n.getTitre() << " (" << n.affichageHorodatage() << ")\n"
	   << n.getContenu() << "\n";

	os << "Pièces jointes (" << n.getNbPiecesJointes() << ") :\n";
	for (int i=0 ; i<n.getNbPiecesJointes() ; i++) {
		os << "\t- " << n.getPieceJointe(i)->getTitre() << "\n";
	}
	return os;
}
