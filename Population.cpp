#include <iostream>
#include <random>
#include <string>
#include "Population.hpp"

Population::Population(std::string individu, std::vector<std::string> ListeDindividu)
{

//alternative du prof concernant les lettres

    for(int i = 0; i < ; ++i)

    std::string Individu(
    "ACGT");
    std::random_device rng;
    std::uniform_int_distribution<> index_dist(0, Individu.size() - 1);
    
    std::string nucleotide;
 
    for(int i = 0; i < 8; ++i) {
     //   std::string nucleotide = Individu[index_dist(rng)].substr(3,2);
     ;
      //std::cout<<Individu[index_dist(rng)];
      
      nucleotide[i] = Individu[index_dist(rng)];
      std::cout<<nucleotide[i];
        
    }

    // il ny a plus qua faire des pushback dans population
   std::cout<<std::endl;

    for(int i = 0; i < 8 ; ++i)
    {
     std::cout<<nucleotide[i];
    }
    v.reserve(MAX_OBJ);
 
for(int i=0; i<MAX_OBJ;i++)
{
       push_back(new Obj());
}

}

Population::~Population()
{
}
