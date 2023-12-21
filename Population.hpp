/* A = 00 , C = 01 , G = 10 , T = 11 */

#include <iostream>
#include <string>
#include <ctime>

class Population 
{
  private:
    std::string _individu;
    std::vector<std::string> _ListeDindividu;
    int a;

  public:
    Population(std::string _individu, std::vector<std::string> _ListeDindividu);
    ~Population();
    NewIndividu();
    AddIndividu();
    MeilleureIndividu();
    newPopulation();

}

