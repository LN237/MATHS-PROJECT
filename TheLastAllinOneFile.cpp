#include <iostream>
#include <string>
#include <vector>
#include <random>

class Individu {
private:
    int _taillePopulation;
    int _longueurADN;
    std::vector<std::string> _population;
    std::string _adn;

public:
    Individu(int taillePopulation = 50, int longueurADN = 8);
    std::string genererADN(int longueur);
    void creerPopulation();
   std::string genererADNavecDesA(int longueur);
    void afficher();
    double calculerTauxMutation(double ParamEntre);
    void evoluerPopulation(double ParamEntre);

    // Getters
    int getTaillePopulation() const;
    int getLongueurADN() const;
    std::vector<std::string> getPopulation() const;
    std::string getADN() const;

    // Setters
    void setTaillePopulation(int taillePopulation);
    void setLongueurADN(int longueurADN);
    void setPopulation(const std::vector<std::string>& population);
    void setADN(const std::string& adn);
};

// Fonction pour générer une séquence d'ADN aléatoire
std::string Individu::genererADN(int longueur) {
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

std::string Individu::genererADNavecDesA(int longueur) {
    std::string nucleotides = "A";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, nucleotides.size() - 1);

    std::string adn;
    for (int i = 0; i < longueur; ++i) {
        adn += nucleotides[dis(gen)];
    }

    return adn;
}


// Constructeur de la classe Individu
Individu::Individu(int taillePopulation, int longueurADN)
    : _taillePopulation(taillePopulation), _longueurADN(longueurADN) {
    _adn = genererADN(_longueurADN);
}

// Fonction pour créer une population d'individus
void Individu::creerPopulation() {
    // Création de la population
    Individu human;
        human.setADN(genererADNavecDesA(_longueurADN));
     _population.push_back(human.getADN());
    for (int i = 0; i <= _taillePopulation; ++i) {
        Individu humain;
        humain.setADN(genererADN(_longueurADN));
      
        _population.push_back(humain.getADN());
    }
}

// Fonction pour afficher la population
void Individu::afficher() {
    // Affichage des individus de la population
    std::cout << "La liste des ADN individus de cette population est :" << std::endl;
    for (int i = 0; i <=_taillePopulation; ++i) {
        std::cout << "Individu " << i + 1 << " : " << _population[i] << std::endl;
    }
}

// Calculer le taux de mutation en fonction du nombre de nucléotides A présents dans la chaîne des individus de la population ; choisir le taux maximum
double Individu::calculerTauxMutation(double ParamEntre) {
    double tauxMutation = 0.0;
    int occurencesMin = _longueurADN;
    std::vector<int> TabOccurences;
    for (int i = 0; i <= _taillePopulation; i++) {
        int occurences = 0;

        for (int j = 0; j < _longueurADN; j++) {
            if (_population[i][j] != 'A') {
                occurences++;
            }
        }

        TabOccurences.push_back(occurences);
    }

    for (int i = 0; i < TabOccurences.size(); i++) {
        if (TabOccurences[i] <= occurencesMin) {
            occurencesMin = TabOccurences[i];
        }
      
    }
std::cout<<occurencesMin<<std::endl;

    if (occurencesMin == 0) {
        tauxMutation = ParamEntre / _longueurADN;
    } else {
        tauxMutation = static_cast<double> (1 / _longueurADN);
    }
    
    

    return tauxMutation;
}


// Fonction pour faire évoluer la population avec des mutations
void Individu::evoluerPopulation(double ParamEntre) {
    double tauxMutation = calculerTauxMutation(ParamEntre);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    for (int i = 0; i <= _taillePopulation; ++i) {
        // Effectuer une mutation avec une certaine probabilité (ligne S_AC)
        if ( tauxMutation == 1/_longueurADN) {
            // Effectuer la mutation en remplaçant un nucléotide aléatoire
            std::uniform_int_distribution<> disNucleotide(0, _longueurADN - 1);
            int positionMutation = disNucleotide(gen);
            std::string nouvelADN = _population[i];
            nouvelADN[positionMutation] = genererADN(1)[0];  // Remplacer un nucléotide par un autre aléatoire
            _population[i] = nouvelADN;}}
            
            else if (tauxMutation > 1/_longueurADN){            	  
           int occurencesMin = _longueurADN;
    std::vector<int> TabOccurences;
    for (int i = 0; i <= _taillePopulation; i++) {
        int occurences = 0;

        for (int j = 0; j < _longueurADN; j++) {
            if (_population[i][j] != 'A') {
                occurences++;
            }
        }

        TabOccurences.push_back(occurences);
    }
	int position = 5;
    for (int i = 0; i < TabOccurences.size(); i++) {
        if(TabOccurences[i] == occurencesMin){
      	 position = i;}
    }
    for (int i = 0; i <= _taillePopulation; ++i) {
        // Effectuer une mutation avec une certaine probabilité (ligne S_AC)
        if ( tauxMutation > 1/_longueurADN) {
            // Effectuer la mutation en remplaçant un nucléotide aléatoire
            std::uniform_int_distribution<> disNucleotide(0, _longueurADN - 1);
            int positionMutation = disNucleotide(gen);
            std::string nouvelADN = _population[position];
            nouvelADN[positionMutation] = genererADN(1)[0];  // Remplacer un nucléotide par un autre aléatoire
            _population[position] = nouvelADN;
            
            	}
        }
     }
}
// Getters
int Individu::getTaillePopulation() const {
    return _taillePopulation;
}

int Individu::getLongueurADN() const {
    return _longueurADN;
}

std::vector<std::string> Individu::getPopulation() const {
    return _population;
}

std::string Individu::getADN() const {
    return _adn;
}

// Setters
void Individu::setTaillePopulation(int taillePopulation) {
    _taillePopulation = taillePopulation;
}

void Individu::setLongueurADN(int longueurADN) {
    _longueurADN = longueurADN;
}

void Individu::setPopulation(const std::vector<std::string>& population) {
    _population = population;
}

void Individu::setADN(const std::string& adn) {
    _adn = adn;
}

int main()
{
	Individu I1(5, 7);
	I1.creerPopulation();
	I1.afficher();
	I1.afficher();
	std::cout << I1.calculerTauxMutation(5.0);	
	for (int i = 0 ; i < 1000 ; i++){
	I1.evoluerPopulation(5.0);
	std::cout<<"evolution"<<i+1<<std::endl;
	I1.afficher(); }
	I1.afficher();
	
	return 0;
}
