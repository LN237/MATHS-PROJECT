#include "Neopopulation.hpp"
#include <iostream>


// Fonction pour générer une séquence d'ADN aléatoire
std::string Individu::genererADN(int longueur) 
{
    std::string nucleotides = "ACGT";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, nucleotides.size() - 1);

    std::string adn;
    for (int i = 0; i < longueur; ++i) {
        adn += nucleotides[dis(gen)];
    }

    return adn;
}
	
	
Individu::Individu()
{
    _taillePopulation = 50;
    _longueurADN = 8;
	genererADN(_longueurADN);
	_adn = _adn;	
}
	
void Individu::creerPopulation()
{
	// Création de la population
    for (int i = 0; i < _taillePopulation; ++i) {
        Individu humain;
        humain._adn = genererADN(_longueurADN);
        
        _population.push_back(humain._adn);
    }
}

int Individu::getTaillePopulation()
{
    return _taillePopulation;
}

int Individu::getLongueurADN()
{
    return _longueurADN;
}

std::vector<std::string> getPopulation(std::vector<std::string>&h)
{
    
    for (int i = 0; i < 40; ++i) {
        
        std::cout << "la liste des ADN individus de cette population est : "<<std::endl;
        std::cout <<"Individu "<<i<<" : "<<h._population[i]<< std::endl;
        
    }
     return h._population;
}

void Individu::afficher()
{
	// Affichage des individus de la population
    for (int i = 0; i < 40; ++i) {
        
        std::cout << "la liste des ADN individus de cette population est : "<<std::endl;
        std::cout <<"Individu "<<_population[i]<< std::endl;
         
    }
}

int main()
{
    Individu I1;
}