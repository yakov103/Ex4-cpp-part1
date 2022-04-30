#include "Game.hpp"
namespace coup { 
        // constract  the game with 0 player 
        Game::Game(){
        this->i = 0 ; 
        }

        // return list of players 
        vector<string> Game::players(){
                return this->playerList; 
        }
        string Game::turn(){
        unsigned int amountOfPlayers = this->playerList.size(); 
        if ( amountOfPlayers == 0 ){ 
                throw runtime_error("no players in the game"); 
        }
        //to show that there are no cycles . 
        this->i = this->i % amountOfPlayers ; 
        return this->playerList[this->i];
        }
        string Game::winner(){ 
        unsigned int amountOfPlayers = this->playerList.size(); 
        if (amountOfPlayers == 0 ){ 
                throw runtime_error("no players in the game"); 
        }
        if (amountOfPlayers != 1 ){ 
                throw runtime_error("the game still running !"); 
        }
        this->i = this->i % amountOfPlayers ; 
        return this->playerList[this->i];


        }
        
        Game::~Game(){

        }




}