#include <string>
#include <ctime>
#include <vector>

/* A=00
C=01
G=10
T=11 */

class Population
{
private:
    std::string _individu;
    std::vector<std::string> _ListeDIndividu;
    newIndividu();

public:
    Population(std::string individu, std::vector<std::string> ListeDIndividu);

    ~Population();
};
