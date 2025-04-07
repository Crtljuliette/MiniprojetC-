// Q1.
/*
int modulo(int dividende, int diviseur)
{
	std::cout << "dividende : " << dividende << ", "
		        << "diviseur : "  << diviseur  << std::endl;
	return dividende;
}
*/

// Q2.
/*
int main()
{
	modulo(5, 2);
}
//*/

// Q3.
/*
int modulo(int dividende, int diviseur)
{
	if (dividende < diviseur) {
		std::swap(dividende, diviseur);
	}
	std::cout << "dividende : " << dividende << ", "
		        << "diviseur : "  << diviseur  << std::endl;
	return dividende;
}

int main()
{
	modulo(5, 2);
	modulo(2, 5);
}
//*/

// Q4.
/*
int modulo(int dividende, int diviseur)
{
	if (dividende < diviseur) {
		std::swap(dividende, diviseur);
	}
	std::cout << "dividende : " << dividende << ", "
		        << "diviseur : "  << diviseur  << std::endl;
	while (dividende > diviseur) {
		dividende -= diviseur;

	return dividende;
}

int main()
{
	if (modulo(5, 2) == 5 % 2)
		std::cout << "Test 1 réussi !" << std::endl;
	else
		std::cout << "Test 1 raté !" << std::endl;

	if (modulo(2, 5) == 5 % 2)
		std::cout << "Test 2 réussi !" << std::endl;
	else
		std::cout << "Test 2 raté !" << std::endl;
}
//*/

// Q5.
int modulo(int dividende, int diviseur)
{
	if (dividende < 0)
		dividende = -dividende;
	if (diviseur < 0)
		diviseur = -diviseur;
	if (diviseur == 0)
		return 0;
	if (dividende < diviseur) {
		std::swap(dividende, diviseur);
	}
	std::cout << "dividende : " << dividende << ", "
		        << "diviseur : "  << diviseur  << std::endl;
	while (dividende > diviseur) {
		dividende -= diviseur;

	return dividende;
}

int main()
{
	if (modulo(5, 2) == 5 % 2)
		std::cout << "Test 1 réussi !" << std::endl;
	else
		std::cout << "Test 1 raté !" << std::endl;

	if (modulo(2, 5) == 5 % 2)
		std::cout << "Test 2 réussi !" << std::endl;
	else
		std::cout << "Test 2 raté !" << std::endl;

	if (modulo(-2, 5) == 5 % 2)
		std::cout << "Test 3 réussi !" << std::endl;
	else
		std::cout << "Test 3 raté !" << std::endl;

	if (modulo(-2, -5) == 5 % 2)
		std::cout << "Test 4 réussi !" << std::endl;
	else
		std::cout << "Test 4 raté !" << std::endl;

	if (modulo(5, 0) == 0)
		std::cout << "Test 5 réussi !" << std::endl;
	else
		std::cout << "Test 5 raté !" << std::endl;
}
