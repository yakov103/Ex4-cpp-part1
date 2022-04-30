#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
using namespace std;


namespace coup{
    class Game {
    private: 
        vector<string> playerList; 
        unsigned int i ; 
    public:
        Game(); 
        vector<string> players();
        string turn(); 
        string winner(); 
        void addPlayer(string &p);
        ~Game();
    };
}