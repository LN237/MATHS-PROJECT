#include <iostream>
#include "Population.hpp"

int main(){
srand(static_cast<unsigned>(time(0)));

    // Paramètres de l'algorithme génétique
    const int populationSize = 10;
    const int sequenceLength = 8;
    const std::string targetSequence = "ATGC";

    const double mutationRate = 0.1;

    // Initialisation de la population
    std::vector<DNAIndividual> population;
    for (int i = 0; i < populationSize; ++i) {
        population.push_back(DNAIndividual(sequenceLength));
    }

    // Boucle principale de l'algorithme génétique
    for (int generation = 0; generation < 1000; ++generation) {
        // Évaluation de la fitness de chaque individu
        for (DNAIndividual& individual : population) {
            individual.fitness = calculateFitness(individual.sequence, targetSequence);
        }

        // Sélection des parents et création de la nouvelle génération
        std::vector<DNAIndividual> newGeneration;
        for (int i = 0; i < populationSize; ++i) {
            size_t parentIndex1 = rouletteSelection(population);
            size_t parentIndex2 = rouletteSelection(population);

            DNAIndividual child = crossover(population[parentIndex1], population[parentIndex2]);
            mutate(child, mutationRate);

            newGeneration.push_back(child);
        }

        // Remplacement de l'ancienne génération par la nouvelle
        population = newGeneration;
    }

    // Trouver le meilleur individu dans la population finale
    DNAIndividual bestIndividual = population[0];
    for (const DNAIndividual& individual : population) {
        if (individual.fitness > bestIndividual.fitness) {
            bestIndividual = individual;
        }
    }

    // Afficher la meilleure séquence trouvée
    std::cout << "Meilleure séquence : " << bestIndividual.sequence << ", Fitness : " << bestIndividual.fitness << std::endl;

    return 0;
}