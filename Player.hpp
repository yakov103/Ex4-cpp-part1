#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include "Game.hpp"
#pragma once
using namespace std;
namespace coup{
    class Player { 
        private : 
 
        public : 
        string name;
        unsigned int amountCoins; 
        Game *game; 
        Player(Game & game, string name_init); 
        void income();
        void foreign_aid();
        void coup(Player &player);
        void role();
        int coins();
        ~Player();

    };


}