#include <iostream>
#include <limits>
#include "board.h"
#include "direction.h"

namespace UserInput{
    bool ValidateChar(char c){
        if(std::cin.fail()){
            if(std::cin.eof()){
                std::exit();
            }
            std::cin.clear();
            return false;
        }
        if(std::cin.peek() != '\n'){
            return false;
        }

        return c == 'w' || c == 'a' || c == 'd' || c == 's' 
                                                || c == 'q';
    }

    char getInput(){
        while(true){
            char c {};
            std::cin >> c;

            if(ValidateChar(c)) break;

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid characters !!! Try again :";
        }
        return c;
    }

    Direction charToDirection(char ch)
    {
        switch (ch)
        {
        case 'w': return Direction{ Direction::up };
        case 's': return Direction{ Direction::down };
        case 'a': return Direction{ Direction::left };
        case 'd': return Direction{ Direction::right };
        }

        assert(false && "Unsupported direction was passed!");
        return Direction{ Direction::up };
    }

}


int main()
{
    Board board{};
    board.randomize();
    std::cout << board;
 
    while (true)
    {
        std::cout << "Enter a command: ";
        const char command{ UserInput::getInput() };

        // Handle non-direction commands
        if (command == 'q')
        {
            std::cout << "\n\nBye!\n\n";
            return 0;
        }

        // Handle direction commands
        const Direction direction{ UserInput::charToDirection(command) };
        board.slideTiles(direction);
        std::cout << "You entered direction: " << direction << '\n';
        std::cout << board;

        //Win Condition
        if( board.winCondition() ){
            std::cout << "You have won!!!!!!!!!!!!\n";
            break;
        }
    }

    return 0;
}
