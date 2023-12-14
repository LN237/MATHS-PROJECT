#include <random>
#include "Population.hpp"

Population::newIndividu(){
 struct BinaryIndividual {
    std::vector<int> genes; 
     BinaryIndividual(int geneCount) {
        for (int i = 0; i < geneCount; ++i) {
            genes.push_back(generateRandomBinary());
        }
    }
 };
 std::string generateRandomAllele() {
    const std::vector<std::string> alleles = {"00", "11", "01", "10"};
    return alleles[randomIndex(alleles.size())];
}

}

Population::Population(std::string _individu, std::vector<std::string> _ListeDIndividu)
{
// Fonction pour générer un nombre aléatoire binaire
int generateRandomBinary() {
    std::random_device rd;  // Utilisé pour obtenir une seed vraiment aléatoire
    std::mt19937 gen(rd()); // Mersenne Twister 19937 comme générateur

    std::uniform_int_distribution<> distribution(0, 1);
    return distribution(gen);
}



   
}


Population::~Population()
{
}
