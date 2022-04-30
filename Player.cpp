#include "Player.hpp"

namespace coup { 
        Player::Player(Game & game, string name_init){
        this->name = name_init; 
        this->game = &game; 
        this->amountCoins = 0 ; 

        //game.addPlayer(name_init); 

        }
        void Player::income(){
            this->amountCoins++;  

        }
        void Player::foreign_aid(){
            this->amountCoins+=2; 

        }
        void Player::coup(Player &player){
            cout << "coup" << endl ; 

        }
        void Player::role(){
            cout << "roles" << endl ; 
        }
        int Player::coins(){
            return (int)this->amountCoins; 
        }
        Player::~Player(){

        }





}