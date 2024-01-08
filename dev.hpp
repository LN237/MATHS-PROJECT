#include <iostream>
#include <vector>
#include <random>

// creation de la classe Individu
class Individu {
    private :
    
    std::string _adn;
    int _taillePopulation;
    int _longueurADN;
    std::vector<Individu> _population;
    
    //Nous  Ajouterons ici d'autres attributs selon si besoin
    
    public:
    Individu(int taillePopulation, int longueurADN);
    Individu();
  std::string genererADN(int longueurADN);  int getTaillePopulation();

  int getLongueurADN();
  std::vecror<Individu> getPopulation();
  void creerPopulation();
  void afficher();
};

void 