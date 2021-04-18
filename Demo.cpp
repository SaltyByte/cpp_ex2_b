/**
 * Demo program for message-board exercise.
 * 
 * Author: Erel Segal-Halevi
 * Since : 2021-03
 */

#include "Board.hpp"
#include "Direction.hpp"
using ariel::Direction;

#include <iostream>
#include <stdexcept>
using namespace std;

int main() {

    // Testing horizontal posting
    Board *board = new Board;

    board->show(); // should work and not throw exception

    cout << board->read(0, 0, Direction::Horizontal, 11) << endl; // prints: "___________"

    // posting examples
    board->post(0, 0, Direction::Horizontal, "Hi alex, nice to meet you");
    board->post(1, 0, Direction::Horizontal, "Im still learning English, so please speak slowly");
    board->post(2, 0, Direction::Horizontal, "I just started working here. Im the new software developer");
    board->post(3, 0, Direction::Horizontal, "How long have you been working here?");
    board->post(50,50,Direction::Horizontal,"New string right here");

    // reading the examples
    cout << board->read(0, 0, Direction::Horizontal, 25) << endl; // prints: "Hi alex, nice to meet you"
    cout << board->read(1, 0, Direction::Horizontal, 49) << endl; // prints: "Im still learning English, so please speak slowly"
    cout << board->read(2, 0, Direction::Horizontal, 58) << endl; // prints: "I just started working here. Im the new software developer"
    cout << board->read(3, 0, Direction::Horizontal, 36) << endl; // prints: "How long have you been working here?"
    cout << board->read(50, 50, Direction::Horizontal, 21) << endl; // prints: "New string right here"
    cout << board->read(50, 50, Direction::Horizontal, 0) << endl; // prints: ""

    cout << board->read(0, 4, Direction::Horizontal, 10) << endl; // prints: "lex, nice "
    cout << board->read(0, 3, Direction::Horizontal, 5) << endl; // prints: "alex,"
    cout << board->read(0, 2, Direction::Horizontal, 2) << endl; // prints: " a"
    cout << board->read(0, 6, Direction::Horizontal, 9) << endl; // prints: "x, nice t"


    cout << board->read(0, 0, Direction::Vertical, 4) << endl; // prints: "HIIH"
    cout << board->read(0, 1, Direction::Vertical, 4) << endl; // prints: "im o"
    cout << board->read(0, 2, Direction::Vertical, 4) << endl; // prints: "  jw"
    cout << board->read(0, 3, Direction::Vertical, 7) << endl; // prints: "asu ___"



    cout << board->read(0, 0, Direction::Horizontal, 4) << endl; // prints: "TM a"
    cout << board->read(1, 0, Direction::Horizontal, 4) << endl; // prints: "eo s"
    cout << board->read(2, 0, Direction::Horizontal, 4) << endl; // prints: "saju"
    cout << board->read(3, 0, Direction::Horizontal, 4) << endl; // prints: "trw "
    cout << board->read(4, 0, Direction::Horizontal, 4) << endl; // prints: "i ts"


    // testing empty spaces
    cout << board->read(7, 0, Direction::Horizontal, 7) == ); // prints: "_______"
    cout << board->read(8, 0, Direction::Horizontal, 7) == ); // prints: "_______"
    cout << board->read(9, 0, Direction::Vertical, 11) == ); // prints: "___________"
    cout << board->read(0, 58, Direction::Vertical, 7) == ); // prints: "_______"
    cout << board->read(100, 100, Direction::Horizontal, 7) == ); // prints: "_______"
    cout << board->read(100, 100, Direction::Vertical, 7) == "_______"); // prints: "TM a"
    cout << board->read(1000, 1000, Direction::Horizontal, 7) == "_______"); // prints: "TM a"
    cout << board->read(1000, 1000, Direction::Vertical, 7) == "_______"); // prints: "TM a"
    cout << board->read(0, 0, Direction::Horizontal, 0) == ""); // prints: "TM a"
    cout << board->read(0, 1, Direction::Horizontal, 0) == ""); // prints: "TM a"
    cout << board->read(10000, 10000, Direction::Vertical, 0) == ""); // prints: "TM a"

}

