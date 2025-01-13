#include <iostream>

enum class moves {
	Tas,
	Kagit,
	Makas
};

class Players {
protected:
	virtual moves make_move() = 0;
	static std::string move_to_str(moves move)
	{
		switch (move) {
		case moves::Tas:
			return std::string{ "Tas" };
		case moves::Kagit:
			return std::string{ "Kagit" };
		case moves::Makas:
			return std::string{ "Makas" };
		}
	}
};

class Computer : public Players {
private:
	moves computer_move;
	moves make_move()override
	{
		std::cout << "Computer is making his move..\n";
		computer_move = static_cast<moves>(rand() % 3);

		std::cout << "Computer's move :" << move_to_str(computer_move) << "\n";
		return computer_move;
	}
	friend class Game;
};

class Player : public Players {
private:
	moves player_move;
	moves make_move()override
	{
		int player_input{};
		do {
			std::cout << "It's your turn. Make your move (Tas=0,Kagit=1, Makas=2) : ";
			std::cin >> player_input;
		} while (player_input < 0 || player_input > 2);
		player_move = static_cast<moves>(player_input);
		std::cout << "Your move is " << move_to_str(player_move) << "\n";

		return player_move;
	}
	friend class Game;
};

class Game {
private:
	Player player;
	Computer computer;
	int game_count;
	int player_score = 0;
	int computer_score = 0;

	const char* who_wins(moves computer, moves player)
	{

		if (computer == player)
			return "No one wins\n";

		switch (computer) {
		case moves::Tas:
			if (player == moves::Kagit) {
				player_score++;
				return "Player won!\n";
			}
			else if (player == moves::Makas) {
				computer_score++;
				return "Computer won\n";
			}
			break;
		case moves::Kagit:
			if (player == moves::Tas) {
				computer_score++;
				return "Computer won\n";
			}
			else if (player == moves::Makas) {
				player_score++;
				return "Player won!\n";
			}
			break;
		case moves::Makas:
			if (player == moves::Kagit) {
				computer_score++;
				return "Computer won\n";
			}
			else if (player == moves::Tas) {
				player_score++;
				return "Player won!\n";
			}
			break;
		}
	}

public:
	void start_game()
	{
		srand(time(nullptr));
		std::cout << "How many turns you want to play? : ";
		std::cin >> game_count;

		while (game_count) {
			moves player_move = player.make_move();
			moves computer_move = computer.make_move();
			std::cout << who_wins(computer_move, player_move) << "\n";
			//std::cout << who_wins(player.make_move(), computer.make_move()); // Ambiguity: It depends on the compiler which argument is called first.
			std::cout << "Stats = Computer(" << computer_score << ")" << " Player(" << player_score << ")";
			std::cout << ",  " << --game_count << " games left!\n\n";
		}

		std::cout << "TOTAL RESULTS  :  ";
		if (player_score > computer_score)
			std::cout << "Player Won!\n";
		else if (player_score < computer_score)
			std::cout << "Computer Won!\n";
		else if (player_score == computer_score)
			std::cout << "The game ended in a draw.\n";
	}
};

int main()
{
	Game game;
	game.start_game();
}
