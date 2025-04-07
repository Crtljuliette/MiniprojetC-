#include <random>
#include <iostream>
#include <string>

// On prend une liste de mots. Dans un vrai programme, on prendrait soin de
// séparer le code des données et on lirait cette liste depuis un fichier ou
// une ressource en ligne.
const std::vector<std::string> LISTE = {
	"programme",
	"informatique",
	"langage",
	"computationnelle",
	"binaire",
	"flottant",
	"caractère",
	"fichier",
	"compilateur",
	"interpréteur"
};

const std::string& motAuHasard()
{
	// On demande au système d'exploitation une graine
	std::random_device rd;
	// pour initialiser un générateur de nombres pseudo-aléatoires,
	std::default_random_engine gen{rd()};
	// puis on transforme la sortie de ce générateur pour obtenir une distribution
	// uniforme couvrant tous les éléments de la liste de mots.
	std::uniform_int_distribution<> distrib(1, LISTE.size());

	// On prend un nombre au hasard, on soustrait 1 car les éléments de listes
	// sont numérotés à partir de 0 et on retourne l'élément de liste
	// correspondant.
	return LISTE[distrib(gen) - 1];
}

std::string demanderEntreeUtilisateur()
{
	std::string saisie;
	std::cout << "	> ";
	std::cin >> saisie;
	return saisie;
}

int deroulementJeu(int vies)
{
	const std::string& mot = motAuHasard();
	std::string cache(mot.size(), '_');
	std::cout << "J'ai choisi un mot !" << std::endl;

	while (vies > 0 && cache != mot) {
		std::cout << "Le mot à deviner est " << cache << ". "
			  << "Il vous reste " << vies << " vies."
			  << std::endl;


		std::string saisie = demanderEntreeUtilisateur();
		if (saisie.size() > 1) {
			// l'utilisateur a saisi un mot et pas une seule lettre
			cache = saisie;
			break;
		} else {
			char car = saisie[0];
			bool presente = false;
			for (int i=0 ; i<mot.size() ; i++) {
				if (mot[i] == car) {
					presente = true;
					cache[i] = car;
				}
			}
			if (!presente)
				vies--;
		}
	}

	if (cache == mot) {
		std::cout << "Vous avez gagné ! Le mot à trouver était bien " << mot << ". "
			  << "Vous marquez " << vies << " points." << std::endl;
		return vies;
	} else {
		std::cout << "Vous avez perdu ! Le mot à trouver était " << mot << ". "
			  << "Vous marquez 0 point." << std::endl;
		return 0;
	}
}

int main()
{
	deroulementJeu(10);
}
