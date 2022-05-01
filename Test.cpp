#include "doctest.h"
#include <string>
#include <stdexcept>
#include <iostream>
#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Game.hpp"
using namespace std;
using namespace coup;

TEST_CASE("RUN GAME")
{
	
	Game game_1{}; // init the game 

	CHECK_THROWS(game_1.turn()); // no players in the game

	/* This player drew the "Duke" card, his name is Moshe*/
	Duke duke{game_1, "Moshe"};
	/* This player drew the "Assassin" card, his name is Yossi*/
	Assassin assassin{game_1, "Yossi"};
	/* This player drew the "Ambassador" card, his name is Meirav*/
	Ambassador ambassador{game_1, "Meirav"};
	/* This player drew the "Captain" card, his name is Reut*/
	Captain captain{game_1, "Reut"};
	/* This player drew the "Contessa" card, his name is Gilad*/
	Contessa contessa{game_1, "Gilad"};

	vector<string> players = game_1.players();


	// check that all of players has 0 coins 
	CHECK_EQ(duke.coins(), 0);
	CHECK_EQ(assassin.coins(), 0);
	CHECK_EQ(ambassador.coins(), 0);
	CHECK_EQ(captain.coins(), 0);
	CHECK_EQ(contessa.coins(), 0);
	CHECK_EQ(game_1.players(), players);

	// check moshe turn , because he is first player
	CHECK_EQ(game_1.turn(), "Moshe");


	// try to start with other players 
	CHECK_THROWS(assassin.income());
	CHECK_THROWS(ambassador.income());
	CHECK_THROWS(captain.income());
	CHECK_THROWS(contessa.income());

	// lets start with just coin throw 
	CHECK_NOTHROW(duke.income());
	// lets try again to call assasin  , need to throw because its is not his turn 
	CHECK_THROWS(duke.income());
	CHECK_NOTHROW(assassin.income());
	CHECK_NOTHROW(ambassador.income());
	CHECK_NOTHROW(captain.income());
	CHECK_NOTHROW(contessa.income());
	
	CHECK_NOTHROW(duke.income());
	CHECK_NOTHROW(assassin.foreign_aid());

	// throws exception, the last operation duke performed
	// is income, which cannot be blocked by any role
	CHECK_THROWS(captain.block(duke));

	CHECK_EQ(duke.coins(), 2); // prints 2
	CHECK_EQ(assassin.coins(), 3); // prints 3

	// throws exception, the last operation duke performed
	// is foreign aid, which cannot be blocked by contessa
	CHECK_THROWS(contessa.block(assassin));

	CHECK_NOTHROW(duke.block(assassin));
	CHECK_EQ(assassin.coins(), 1); // prints 1

	//transfers 1 coin from duke to assassin
	CHECK_NOTHROW(ambassador.transfer(duke, assassin));
	CHECK_NOTHROW(captain.foreign_aid());
	CHECK_NOTHROW(contessa.foreign_aid());

	CHECK_NOTHROW(duke.tax());
	CHECK_NOTHROW(assassin.income());
	CHECK_NOTHROW(ambassador.foreign_aid());
	CHECK_NOTHROW(captain.steal(contessa));
	CHECK_NOTHROW(contessa.foreign_aid());

	CHECK_NOTHROW(duke.tax());
	// no exception, assassin can coup with only 3 coins
	CHECK_NOTHROW(assassin.coup(duke));
	players = {"Yossi", "Meirav", "Reut", "Gilad"};
	CHECK_EQ(game_1.players(), players);
	CHECK_NOTHROW(contessa.block(assassin));
	players = {"Moshe", "Yossi", "Meirav", "Reut", "Gilad"};
	CHECK_EQ(game_1.players(), players);
}