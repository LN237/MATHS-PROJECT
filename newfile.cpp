#include <iostream>
#include <vector>
#include <random>

// Structure pour représenter un individu
struct Individu {
    std::string adn;
    // Ajoutez ici d'autres attributs selon vos besoins
};

// Fonction pour générer une séquence d'ADN aléatoire
std::string genererADN(int longueur) {
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

int rouletteSelection;

int main() {
    // Paramètres de la population
    int taillePopulation = 100;
    int longueurADN = 10;

    // Création de la population
    std::vector<Individu> population;
    for (int i = 0; i < taillePopulation; ++i) {
        Individu individu;
        individu.adn = genererADN(longueurADN);
        // Ajoutez ici l'initialisation des autres attributs de l'individu
        population.push_back(individu);
    }

    // Affichage des individus de la population
    for (const auto& individu : population) {
        std::cout << "ADN : " << individu.adn << std::endl;
        // Ajoutez ici l'affichage des autres attributs de l'individu
    }

    return 0;

}

