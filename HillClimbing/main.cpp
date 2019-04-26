#include "knight.h"
#include "ConsoleController.h"

using namespace std;

GRID m_grid;

const float initalTemp = 1000.0f;
const float finalTemp = 10.0f;
float currentTemp = 1000.0f;

//Draw the board
void DrawBoard() {
	for (unsigned i = 0; i < m_grid.grid.size(); i++) //y
	{
		for (unsigned j = 0; j < m_grid.grid.size(); j++)//x
		{
			int tmp = m_grid.grid.at(i).at(j);
			switch (tmp)
			{
			case BOARD::EMPTY: {
				Console_ColoredTEXT(" # ", 8);
				break;
			}
			case BOARD::KNIGHT: {
				Console_ColoredTEXT(" K ", 14);
				break;
			}
			default: {
				cout << "Unknown Value: " << tmp << endl;
				system("pause");
				break;
			}
			}
		}
		cout << endl;
	}
}

void InitBoard() {
	//Get Board Ready
	m_grid.grid.resize(m_grid.numOfKnights);
	for (signed i = 0; i < m_grid.numOfKnights; i++) {
		for (signed j = 0; j < m_grid.numOfKnights; j++) {
			m_grid.grid.at(i).push_back(BOARD::EMPTY);
		}
	}

	//Randomly Place Knights
	for (signed i = 0; i < m_grid.numOfKnights; i++)
	{
		int x = rand() % m_grid.numOfKnights;
		int y = rand() % m_grid.numOfKnights;
		while (m_grid.grid.at(y).at(x) == BOARD::KNIGHT) { //Make sure we do not overwrite any positions with a knight already in
			x = rand() % m_grid.numOfKnights;
			y = rand() % m_grid.numOfKnights;
		}
		m_grid.grid.at(y).at(x) = BOARD::KNIGHT;
	}

}

//Check if knights can attack, returns of a score of how many or checks if one knight can attack and how many
int CheckAttacks(int x, int y, GRID m_grid) {
	int m_score = 0;
	//GLOBAL CHECK
	if (x == -9999 && y == -9999) {
		for (unsigned i = 0; i < m_grid.grid.size(); i++) //y
		{
			for (unsigned j = 0; j < m_grid.grid.at(0).size(); j++) //x
			{
				if (m_grid.grid.at(i).at(j) == BOARD::KNIGHT) {
					unsigned checkx = 0;
					unsigned checky = 0;
					//ATTACK RUP
					checkx = j + 1;
					checky = i + 2;
					if (checkx >= 0 && checky >= 0) {
						if (checkx < m_grid.grid.at(0).size()) { //keep inside bounds
							if (checky < m_grid.grid.size()) {
								if (m_grid.grid.at(checky).at(checkx) == BOARD::KNIGHT) {
									m_score++;
								}
							}
						}
					}
					//ATTACK LUP
					checkx = j - 1;
					checky = i + 2;
					if (checkx >= 0 && checky >= 0) {
						if (checkx < m_grid.grid.at(0).size()) { //keep inside bounds
							if (checky < m_grid.grid.size()) {
								if (m_grid.grid.at(checky).at(checkx) == BOARD::KNIGHT) {
									m_score++;
								}
							}
						}
					}
					//ATTACK RIGHTL
					checkx = j + 2;
					checky = i + 1;
					if (checkx >= 0 && checky >= 0) {
						if (checkx < m_grid.grid.at(0).size()) { //keep inside bounds
							if (checky < m_grid.grid.size()) {
								if (m_grid.grid.at(checky).at(checkx) == BOARD::KNIGHT) {
									m_score++;
								}
							}
						}
					}
					//ATTACK RIGHTR
					checkx = j + 2;
					checky = i - 1;
					if (checkx >= 0 && checky >= 0) {
						if (checkx < m_grid.grid.at(0).size()) { //keep inside bounds
							if (checky < m_grid.grid.size()) {
								if (m_grid.grid.at(checky).at(checkx) == BOARD::KNIGHT) {
									m_score++;
								}
							}
						}
					}
					//ATTACK DOWNL
					checkx = j + 1;
					checky = i - 2;
					if (checkx >= 0 && checky >= 0) {
						if (checkx < m_grid.grid.at(0).size()) { //keep inside bounds
							if (checky < m_grid.grid.size()) {
								if (m_grid.grid.at(checky).at(checkx) == BOARD::KNIGHT) {
									m_score++;
								}
							}
						}
					}
					//ATTACK DOWNR
					checkx = j - 1;
					checky = i - 2;
					if (checkx >= 0 && checky >= 0) {
						if (checkx < m_grid.grid.at(0).size()) { //keep inside bounds
							if (checky < m_grid.grid.size()) {
								if (m_grid.grid.at(checky).at(checkx) == BOARD::KNIGHT) {
									m_score++;
								}
							}
						}
					}
					//ATTACK LEFTL
					checkx = j - 2;
					checky = i - 1;
					if (checkx >= 0 && checky >= 0) {
						if (checkx < m_grid.grid.at(0).size()) { //keep inside bounds
							if (checky < m_grid.grid.size()) {
								if (m_grid.grid.at(checky).at(checkx) == BOARD::KNIGHT) {
									m_score++;
								}
							}
						}
					}
					//ATTACK LEFTL
					checkx = j - 2;
					checky = i + 1;
					if (checkx >= 0 && checky >= 0) {
						if (checkx < m_grid.grid.at(0).size()) { //keep inside bounds
							if (checky < m_grid.grid.size()) {
								if (m_grid.grid.at(checky).at(checkx) == BOARD::KNIGHT) {
									m_score++;
								}
							}
						}
					}
				}
			}
		}
		return m_score; //return the score for globalcheck
	}

	//CHECK IF SINGLE KNIGHT CAN ATTACK
	else {
		if (m_grid.grid.at(y).at(x) == BOARD::KNIGHT) {
			unsigned checkx = 0;
			unsigned checky = 0;
			//ATTACK UPL
			checkx = x - 1;
			checky = y - 2;
			if ((checkx >= 0 && checky >= 0) && (checkx < m_grid.grid.at(0).size()) && (checky < m_grid.grid.size())) { //keep inside bounds
				if (m_grid.grid.at(checky).at(checkx) == BOARD::KNIGHT) { //is the spot a knight
					m_score++;
				}
			}
			//ATTACK UPR
			checkx = x + 1;
			checky = y - 2;
			if ((checkx >= 0 && checky >= 0) && (checkx < m_grid.grid.at(0).size()) && (checky < m_grid.grid.size())) { //keep inside bounds
				if (m_grid.grid.at(checky).at(checkx) == BOARD::KNIGHT) { //is the spot a knight
					m_score++;
				}
			}

			//ATTACK RIGHTL
			checkx = x + 2;
			checky = y - 1;
			if ((checkx >= 0 && checky >= 0) && (checkx < m_grid.grid.at(0).size()) && (checky < m_grid.grid.size())) { //keep inside bounds
				if (m_grid.grid.at(checky).at(checkx) == BOARD::KNIGHT) { //is the spot a knight
					m_score++;
				}
			}
			//ATTACK RIGHTR
			checkx = x + 2;
			checky = y + 1;
			if ((checkx >= 0 && checky >= 0) && (checkx < m_grid.grid.at(0).size()) && (checky < m_grid.grid.size())) { //keep inside bounds
				if (m_grid.grid.at(checky).at(checkx) == BOARD::KNIGHT) { //is the spot a knight
					m_score++;
				}
			}
			
			//ATTACK DOWNL
			checkx = x + 1;
			checky = y + 2;
			if ((checkx >= 0 && checky >= 0) && (checkx < m_grid.grid.at(0).size()) && (checky < m_grid.grid.size())) { //keep inside bounds
				if (m_grid.grid.at(checky).at(checkx) == BOARD::KNIGHT) { //is the spot a knight
					m_score++;
				}
			}
			//ATTACK DOWNR
			checkx = x - 1;
			checky = y + 2;
			if ((checkx >= 0 && checky >= 0) && (checkx < m_grid.grid.at(0).size()) && (checky < m_grid.grid.size())) { //keep inside bounds
				if (m_grid.grid.at(checky).at(checkx) == BOARD::KNIGHT) { //is the spot a knight
					m_score++;
				}
			}

			//ATTACK LEFTL
			checkx = x - 2;
			checky = y + 1;
			if ((checkx >= 0 && checky >= 0) && (checkx < m_grid.grid.at(0).size()) && (checky < m_grid.grid.size())) { //keep inside bounds
				if (m_grid.grid.at(checky).at(checkx) == BOARD::KNIGHT) { //is the spot a knight
					m_score++;
				}
			}
			//ATTACK LEFTR
			checkx = x - 2;
			checky = y - 1;
			if ((checkx >= 0 && checky >= 0) && (checkx < m_grid.grid.at(0).size()) && (checky < m_grid.grid.size())) { //keep inside bounds
				if (m_grid.grid.at(checky).at(checkx) == BOARD::KNIGHT) { //is the spot a knight
					m_score++;
				}
			}
		}
		else {
			cout << "ERR: NO KNIGHT FOUND AT X: " << x << " Y: " << y << endl;
		}
	}
	return m_score; //return the score
}

//RegenerateBoard takes two args, the attack value and mode which is false for hill climbing and true for annealing
GRID RegenerateBoard(int attack_value, bool mode) {
	
	//Make a new empty grid
	GRID newGrid;
	newGrid.numOfKnights = m_grid.numOfKnights;
	newGrid.grid.resize(newGrid.numOfKnights);
	for (signed i = 0; i < newGrid.numOfKnights; i++) {
		for (signed j = 0; j < newGrid.numOfKnights; j++) {
			newGrid.grid.at(i).push_back(BOARD::EMPTY);
		}
	}

	if (!mode) { //If we are hill climbing
		//Keep knights that don't attack and replace the ones that do
		for (size_t i = 0; i < newGrid.grid.size(); i++) //y
		{
			for (size_t j = 0; j < newGrid.grid.size(); j++) //x
			{
				if (m_grid.grid.at(i).at(j) == BOARD::KNIGHT) {
					int m_att = CheckAttacks(j, i, m_grid);
					//If this knight cannot attack anything keep
					if (m_att == 0) {
						newGrid.grid.at(i).at(j) = BOARD::KNIGHT;
					}
					//If this knight can attack anything move
					else {
						int x = rand() % m_grid.numOfKnights;
						int y = rand() % m_grid.numOfKnights;
						while (m_grid.grid.at(y).at(x) == BOARD::KNIGHT) { //Make sure we do not overwrite any positions with a knight already in
							x = rand() % m_grid.numOfKnights;
							y = rand() % m_grid.numOfKnights;
						}
						newGrid.grid.at(y).at(x) = BOARD::KNIGHT;
					}
				}
			}
		}

		//Check total attacks if there are more then do not return the new grid
		int att = CheckAttacks(-9999, -9999, newGrid);

		if (att > attack_value) {
			newGrid = m_grid;
		}
	}

	//If we are simulating annealing
	else {
		
		//Keep knights that don't attack and replace the ones that do
		for (size_t i = 0; i < newGrid.grid.size(); i++) //y
		{
			for (size_t j = 0; j < newGrid.grid.size(); j++) //x
			{
				if (m_grid.grid.at(i).at(j) == BOARD::KNIGHT) {
					int m_att = CheckAttacks(j, i, m_grid);
					//If this knight cannot attack anything keep
					if (m_att == 0) {
						newGrid.grid.at(i).at(j) = BOARD::KNIGHT;
					}
					//If this knight can attack anything move
					else {
						int x = rand() % m_grid.numOfKnights;
						int y = rand() % m_grid.numOfKnights;
						while (m_grid.grid.at(y).at(x) == BOARD::KNIGHT) { //Make sure we do not overwrite any positions with a knight already in
							x = rand() % m_grid.numOfKnights;
							y = rand() % m_grid.numOfKnights;
						}
						newGrid.grid.at(y).at(x) = BOARD::KNIGHT;
					}
				}
			}
		}
		//Check total attacks if there are more then do not return the new grid
		int c = CheckAttacks(-9999, -9999, newGrid) - CheckAttacks(-9999, -9999, m_grid);

		cout << "VALUE OF C IS: " << c << endl;

		if (c > 0) {
			newGrid = m_grid;
			currentTemp = currentTemp - 10.0f;
			return newGrid;
		}

		else {
			float m_rand = (rand() / (float)RAND_MAX * 1);
			float e = (exp(c / currentTemp));
			if (m_rand > e) {
				newGrid = m_grid;
				currentTemp = currentTemp - 10.0f;
				return newGrid;
			}
		}
		currentTemp = currentTemp - 10.0f;
	}

	return newGrid;
}

void solveNK() {
	int count = 0;
	Console_Clear();
	DrawBoard();
	int att = CheckAttacks(-9999, -9999, m_grid); //request global check
	while (att != 0) {
		count++;
		Console_Clear();
		m_grid = RegenerateBoard(att, false);
		DrawBoard();
		att = CheckAttacks(-9999, -9999, m_grid);

		for (signed i = 0; i < m_grid.numOfKnights; i++)
		{
			Console_ColoredTEXT("-", 12);
		}
		cout << endl << "ATTACKS: " << att << endl;
		cout << "ITERATIONS: " << count << endl;
	}
	Console_Clear();
	DrawBoard();
	Console_ColoredTEXT("", 10);
	for (signed i = 0; i < m_grid.numOfKnights; i++)
	{
		cout << "-";
	}
	cout << endl << "ATTACKS: " << att << endl;
	cout << "ITERATIONS: " << count << endl;
	cout << "Solved!";
	Console_ColoredTEXT("\n", 15); //reset color
}

void solveNKAnneal() {
	int count = 0;
	Console_Clear();
	DrawBoard();
	int att = CheckAttacks(-9999, -9999, m_grid); //request global check
	while (currentTemp > finalTemp) {
		//while (att != 0) {
			count++;

			Console_Clear();
			m_grid = RegenerateBoard(att, true);
			DrawBoard();
			att = CheckAttacks(-9999, -9999, m_grid);

			for (signed i = 0; i < m_grid.numOfKnights; i++)
			{
				Console_ColoredTEXT("-", 12);
			}
			cout << endl << "ATTACKS: " << att << endl;
			cout << "ITERATIONS: " << count << endl;
			cout << "TEMPERTURE: " << currentTemp << endl;
		//}
	}
	Console_Clear();
	DrawBoard();
	Console_ColoredTEXT("", 10);
	for (signed i = 0; i < m_grid.numOfKnights; i++)
	{
		cout << "-";
	}
	cout << endl << "ATTACKS: " << att << endl;
	cout << "ITERATIONS: " << count << endl;
	cout << "TEMPERTURE: " << currentTemp << endl;
	cout << "Solved!";
	Console_ColoredTEXT("\n", 15); //reset color
}

int main() {

	srand((unsigned int)time(NULL));

	Console_RainbowWrite("N Knights Problem \n~ Henry Oliver\n");

	cout << "Please Input Amount Of Knights: ";

	cin >> m_grid.numOfKnights;

	cout << "1. HillClimbing" << endl << "2. Annealing" << endl << "Please Select An Option: ";

	int tmp;
	cin >> tmp;

	while (tmp != 1 && tmp != 2)
	{
		cout << "Invalid Option! Please Select a valid option: ";
		cin >> tmp;
	}

	switch (tmp)
	{
		case 1: {
			InitBoard();
			solveNK();
			break;
		}
		case 2: {
			InitBoard();
			solveNKAnneal();
			break;
		}
		default: {
			cout << "Invalid Option! Terminating...";
			break;
		}
	}

	system("pause");

	return 0;
}