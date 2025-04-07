#include <iostream>
#include <fstream>

#include "Biscuit.h"
#include "BiscuitFourre.h"

Biscuit* pointer()
{
	std::cout << "Instanciation du Biscuit fourré b3 framboise/pistache, diamètre 1cm" << std::endl;
	Biscuit* b3 = new BiscuitFourre{"framboise", "pistache", 1};

	// Déjà fait !
	// std::cout << "Création du pointeur sur le biscuit fourré b3" << std::endl;

	return b3;
}

int main()
{
	std::cout << "Affichage : Biscuit pointer sur b3" << std::endl;
	Biscuit* ptr = pointer();
	std::cout << ptr->donnerDescriptionNonVirtual() << "\n"
		  << ptr->donnerDescriptionVirtual() << "\n"
		  << std::endl;
	delete ptr;
}
