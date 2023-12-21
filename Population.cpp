#include <iostream>
#include <random>
#include <string>
#include "Population.hpp"

Population::Population(std::string individu, std::vector<std::string> ListeDindividu)
{

//alternative du prof concernant les lettres


    std::string Individu("ACGT");
    std::random_device rng;
    std::uniform_int_distribution<> index_dist(0, Individu.size() - 1);
    
    std::string nucleotide;
 
    for(int i = 0; i < 8; ++i) {
     //   std::string nucleotide = Individu[index_dist(rng)].substr(3,2);
        
      //std::cout<<Individu[index_dist(rng)];
      
      nucleotide[i] = Individu[index_dist(rng)];
      std::cout<<nucleotide[i];
        
    }

    // il n'y a plus qua faire des pushback dans population
   std::cout<<std::endl;

    for(int i = 0; i < 8 ; ++i)
    {
        
            
        std::cout<<nucleotide[i];
        ListeDindividu.push_back(new std::string nucleotide[i]);
    }
    
    //ListeDindividu.reserve(MAX_OBJ);

}

Population::~Population()
{
}
