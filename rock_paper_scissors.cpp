#include <iostream>

enum class move {
	Tas,
	Kagit,
	Makas
};

class Players {
public:
	virtual move make_move() = 0;
	static std::string move_to_str(move move)
	{
		switch (move) {
		case move::Tas:
			return std::string{ "Tas" };
		case move::Kagit:
			return std::string{ "Kagit" };
		case move::Makas:
			return std::string{ "Makas" };
		}
	}

};

class Computer : public Players {
public:
	move computer_move;
	move make_move()override
	{
		std::cout << "Computer is making his move..\n";
		computer_move = static_cast<move>(rand() % 3);

		std::cout << "Computer's move :" << move_to_str(computer_move) << "\n";
		return computer_move;
	}
};

class Player : public Players {
public:
	move player_move;
	move make_move()override
	{
		int player_input{};
		do{
		std::cout << "It's your turn. Make your move (Tas=0,Kagit=1, Makas=2) : ";
		std::cin >> player_input;
		} while (player_input < 0 || player_input > 2);
		player_move = static_cast<move>(player_input);
		std::cout << "Your move is " << move_to_str(player_move) << "\n";

		return player_move;
	}
};
class Game {
private:
	Player player;
	Computer computer;
	int game_count;

public:
	int player_score = 0;
	int computer_score = 0;

	void start_game()
	{
		srand(time(0));
		std::cout << "How many turns you want to play? : ";
		std::cin >> game_count;

		while (game_count) {
			move player_move = player.make_move();
			move computer_move = computer.make_move();
			std::cout << who_wins(this, computer_move, player_move) << "\n";
			//std::cout << who_wins(player.make_move(), computer.make_move()); // Ambiguity: It depends on the compiler which argument is called first.
			std::cout << "Stats = Computer(" << computer_score << ")" << " Player(" << player_score << ")";
			std::cout <<",  " << --game_count << " games left!\n\n";
		}

		std::cout << "TOTAL RESULTS  :  ";
		if (player_score > computer_score)
			std::cout << "Player Won!\n";
		else if (player_score < computer_score)
			std::cout << "Computer Won!\n";
		else if (player_score == computer_score)
			std::cout << "The game ended in a draw.\n";


	}
	friend std::string who_wins(Game* game_obj,move computer, move player);
	
};


std::string who_wins(Game* game_obj, move computer, move player)
{
	std::string player_wins{ "Player won!\n" };
	std::string computer_wins{ "Computer won\n" };

	if (computer == player)
		return std::string{ "No one wins\n" };

	switch (computer) {
	case move::Tas:
		if (player == move::Kagit) {
			game_obj->player_score++;
			return player_wins;
		}
		else if (player == move::Makas) {
			game_obj->computer_score++;
			return computer_wins;
		}
		break;
	case move::Kagit:
		if (player == move::Tas) {
			game_obj->computer_score++;
			return computer_wins;
		}
		else if (player == move::Makas) {
			game_obj->player_score++;
			return player_wins;
		}
		break;
	case move::Makas:
		if (player == move::Kagit) {
			game_obj->computer_score++;
			return computer_wins;
		}
		else if (player == move::Tas) {
			game_obj->player_score++;
			return player_wins;
		}
		break;
	}
}



int main()
{
	Game game;
	game.start_game();
}
