#include <iostream>
#include <string>

#include "Email.h"

Email::Email(
		const std::string& titre,
		const std::string& destinataire,
		const std::string& texte
	) :
	sujet{titre},
	destinataire{destinataire},
	texte{texte}
{
}

Email::~Email()
{
	std::cout << "Appel au destructeur d'email" << std::endl;
}

const std::string& Email::getTitre() const
{
	return sujet;
}

const std::string& Email::getDestinataire() const
{
	return destinataire;
}

const std::string& Email::getTexte() const
{
	return texte;
}
