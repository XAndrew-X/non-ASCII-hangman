#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>

void Ask(std::string answered, std::string_view chosenword, int guesses_left)
{
	char input {};
	// std::cout << words[chosenwordindex] << std::endl;
	std::cout << "Guess the Word: " << answered << std::endl;
	std::cin >> input;
	// CHECK: NEED STRING MANIPULATION 
	long unsigned int find { chosenword.find(input) };
	long unsigned int findincrement { chosenword.find(input,find+1) };
	long unsigned int findincrementincrement { chosenword.find(input,findincrement+1)  };
	if ( find != chosenword.npos  ) {
		if ( chosenword.find(input,find+1) == chosenword.npos ) // Only one occurence
			answered[find] = input;
		else {	//More than one occurence
			answered[find] = input;
			answered[findincrement] = input;
			if ( chosenword.find(input,findincrement+1) != chosenword.npos )
				 answered[findincrementincrement] = input;
		}
	}
	else if (guesses_left > 0)
		std::cout << guesses_left << " GUESSES LEFT!" << std::endl;
		guesses_left--;
		


	if (chosenword == answered)
	{
		std::cout << chosenword << std::endl;
		std::cout << "YOU WON!";
	} else if (guesses_left > 0)
		Ask(answered,chosenword,guesses_left);
	else
		std::cout << "Try again";

}


int main(int argc, char const *argv[])
{
	std::vector<std::string_view> words{ "COPY","COME","BELL","WORD","HUGE" };
	std::mt19937 mt{ std::random_device{}() };
	std::uniform_int_distribution rando{ 0, static_cast<int>(words.size()) };

	std::string answered { "xxxx" };

	std::string_view chosenword { words[ rando(mt) ] };
	// std::string_view chosenword { "BELL" };
	int guesses_left { 7 };
	Ask(answered,chosenword,guesses_left);

	return 0;
}