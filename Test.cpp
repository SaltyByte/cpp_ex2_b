#include "doctest.h"
#include "Board.hpp"
#include "Direction.hpp"
#include <stdlib.h>

using namespace std;
using namespace ariel;

TEST_CASE ("Testing Post and Read") {

    // Testing horizontal posting
    Board *board = new Board;

    board->post(0, 0, Direction::Horizontal, "Hi alex, nice to meet you");
    board->post(1, 0, Direction::Horizontal, "Im still learning English, so please speak slowly");
    board->post(2, 0, Direction::Horizontal, "I just started working here. Im the new software developer");
    board->post(3, 0, Direction::Horizontal, "How long have you been working here?");
    board->post(4, 0, Direction::Horizontal, "Lets get a coffee sometime");
    board->post(5, 0, Direction::Horizontal, "I know a good place nearby");
    board->post(6, 0, Direction::Horizontal, "If you have a moment, I would love your thoughts on this");
    board->post(50,50,Direction::Horizontal,"New string right here");

    CHECK(board->read(0, 0, Direction::Horizontal, 25) == "Hi alex, nice to meet you");
    CHECK(board->read(1, 0, Direction::Horizontal, 49) == "Im still learning English, so please speak slowly");
    CHECK(board->read(2, 0, Direction::Horizontal, 58) == "I just started working here. Im the new software developer");
    CHECK(board->read(3, 0, Direction::Horizontal, 36) == "How long have you been working here?");
    CHECK(board->read(4, 0, Direction::Horizontal, 26) == "Lets get a coffee sometime");
    CHECK(board->read(5, 0, Direction::Horizontal, 26) == "I know a good place nearby");
    CHECK(board->read(6, 0, Direction::Horizontal, 56) == "If you have a moment, I would love your thoughts on this");
    CHECK(board->read(50, 50, Direction::Horizontal, 21) == "New string right here");

    CHECK(board->read(0, 4, Direction::Horizontal, 10) == "lex, nice ");
    CHECK(board->read(0, 3, Direction::Horizontal, 5) == "alex,");
    CHECK(board->read(0, 2, Direction::Horizontal, 2) == " a");
    CHECK(board->read(0, 6, Direction::Horizontal, 9) == "x, nice t");

    CHECK(board->read(1, 6, Direction::Horizontal, 10) == "ll learnin");
    CHECK(board->read(1, 3, Direction::Horizontal, 9) == "still lea");
    CHECK(board->read(1, 2, Direction::Horizontal, 2) == " s");
    CHECK(board->read(1, 6, Direction::Horizontal, 14) == "ll learning En");


    CHECK(board->read(0, 0, Direction::Vertical, 7) == "HIIHLII");
    CHECK(board->read(0, 1, Direction::Vertical, 7) == "im oe f");
    CHECK(board->read(0, 2, Direction::Vertical, 7) == "  jwtk ");
    CHECK(board->read(0, 3, Direction::Vertical, 7) == "asu sny");
    CHECK(board->read(0, 4, Direction::Vertical, 7) == "ltsl oo");
    CHECK(board->read(0, 5, Direction::Vertical, 7) == "eitogwu");
    CHECK(board->read(0, 6, Direction::Vertical, 7) == "xl ne  ");
    CHECK(board->read(0, 7, Direction::Vertical, 7) == ",lsgtah");
    CHECK(board->read(0, 8, Direction::Vertical, 7) == "  t   a");
    CHECK(board->read(0, 9, Direction::Vertical, 7) == "nlahagv");
    CHECK(board->read(0, 10, Direction::Vertical, 7) == "iera oe");
    CHECK(board->read(0, 10, Direction::Vertical, 10) == "iera oe___");
    CHECK(board->read(0, 27, Direction::Vertical, 10) == "_s.i__l___");


    board->post(0, 0, Direction::Vertical, "Testing");
    board->post(0, 1, Direction::Vertical, "Moar te");

    CHECK(board->read(0, 0, Direction::Horizontal, 4) == "TM a");
    CHECK(board->read(1, 0, Direction::Horizontal, 4) == "eo s");
    CHECK(board->read(2, 0, Direction::Horizontal, 4) == "saju");
    CHECK(board->read(3, 0, Direction::Horizontal, 4) == "trw ");
    CHECK(board->read(4, 0, Direction::Horizontal, 4) == "i ts");


//    // testing empty spaces
    CHECK(board->read(7, 0, Direction::Horizontal, 7) == "_______");
    CHECK(board->read(8, 0, Direction::Horizontal, 7) == "_______");
    CHECK(board->read(9, 0, Direction::Vertical, 11) == "___________");
    CHECK(board->read(0, 58, Direction::Vertical, 7) == "_______");
    CHECK(board->read(100, 100, Direction::Horizontal, 7) == "_______");
    CHECK(board->read(100, 100, Direction::Vertical, 7) == "_______");
    CHECK(board->read(1000, 1000, Direction::Horizontal, 7) == "_______");
    CHECK(board->read(1000, 1000, Direction::Vertical, 7) == "_______");
    CHECK(board->read(0, 0, Direction::Horizontal, 0) == "");
    CHECK(board->read(0, 1, Direction::Horizontal, 0) == "");

    delete board;

    // Testing vertical posting
    Board *board2 = new Board;
    board2->post(0, 0, Direction::Vertical, "Hi alex, nice to meet you");
    board2->post(0, 1, Direction::Vertical, "Im still learning English, so please speak slowly");
    board2->post(0, 2, Direction::Vertical, "I just started working here. Im the new software developer");
    board2->post(0, 3, Direction::Vertical, "How long have you been working here?");
    board2->post(0, 4, Direction::Vertical, "Lets get a coffee sometime");
    board2->post(0, 5, Direction::Vertical, "I know a good place nearby");
    board2->post(0, 6, Direction::Vertical, "If you have a moment, I would love your thoughts on this");


    CHECK(board2->read(0, 0, Direction::Vertical, 25) == "Hi alex, nice to meet you");
    CHECK(board2->read(0, 1, Direction::Vertical, 49) == "Im still learning English, so please speak slowly");
    CHECK(board2->read(0, 2, Direction::Vertical, 58) == "I just started working here. Im the new software developer");
    CHECK(board2->read(0, 3, Direction::Vertical, 36) == "How long have you been working here?");
    CHECK(board2->read(0, 4, Direction::Vertical, 26) == "Lets get a coffee sometime");
    CHECK(board2->read(0, 5, Direction::Vertical, 26) == "I know a good place nearby");
    CHECK(board2->read(0, 6, Direction::Vertical, 56) == "If you have a moment, I would love your thoughts on this");

    CHECK(board2->read(4, 0, Direction::Vertical, 10) == "lex, nice ");
    CHECK(board2->read(3, 0, Direction::Vertical, 5) == "alex,");
    CHECK(board2->read(2, 0, Direction::Vertical, 2) == " a");
    CHECK(board2->read(6, 0, Direction::Vertical, 9) == "x, nice t");

    CHECK(board2->read(6, 1, Direction::Vertical, 10) == "ll learnin");
    CHECK(board2->read(3, 1, Direction::Vertical, 9) == "still lea");
    CHECK(board2->read(2, 1, Direction::Vertical, 2) == " s");
    CHECK(board2->read(6, 1, Direction::Vertical, 14) == "ll learning En");

    CHECK(board2->read(0, 0, Direction::Horizontal, 7) == "HIIHLII");
    CHECK(board2->read(1, 0, Direction::Horizontal, 7) == "im oe f");
    CHECK(board2->read(2, 0, Direction::Horizontal, 7) == "  jwtk ");
    CHECK(board2->read(3, 0, Direction::Horizontal, 7) == "asu sny");
    CHECK(board2->read(4, 0, Direction::Horizontal, 7) == "ltsl oo");
    CHECK(board2->read(5, 0, Direction::Horizontal, 7) == "eitogwu");
    CHECK(board2->read(6, 0, Direction::Horizontal, 7) == "xl ne  ");
    CHECK(board2->read(7, 0, Direction::Horizontal, 7) == ",lsgtah");
    CHECK(board2->read(8, 0, Direction::Horizontal, 7) == "  t   a");
    CHECK(board2->read(9, 0, Direction::Horizontal, 7) == "nlahagv");
    CHECK(board2->read(10, 0, Direction::Horizontal, 7) == "iera oe");
    CHECK(board2->read(10, 0, Direction::Horizontal, 10) == "iera oe___");
    CHECK(board2->read(27, 0, Direction::Horizontal, 10) == "_s.i__l___");

    delete board2;

}


TEST_CASE("Testing Throws") {
    Board *board = new Board;

    // test empty board
    CHECK_THROWS(board->read(0,0,Direction::Vertical,1));
    CHECK_THROWS(board->read(0,0,Direction::Horizontal,1));


    board->post(0, 0, Direction::Horizontal, "Hi alex, nice to meet you");
    board->post(1, 0, Direction::Horizontal, "Im still learning English, so please speak slowly");
    board->post(2, 0, Direction::Horizontal, "I just started working here. Im the new software developer");
    board->post(3, 0, Direction::Horizontal, "How long have you been working here?");
    board->post(4, 0, Direction::Horizontal, "Lets get a coffee sometime");
    board->post(5, 0, Direction::Horizontal, "I know a good place nearby");
    board->post(6, 0, Direction::Horizontal, "If you have a moment, I would love your thoughts on this");


    // test negative length
    CHECK_THROWS(board->read(1,0,Direction::Vertical,-1));
    CHECK_THROWS(board->read(0,1,Direction::Horizontal,-1));
    CHECK_THROWS(board->read(1,0,Direction::Vertical,-1));
    CHECK_THROWS(board->read(0,1,Direction::Horizontal,-1));

    delete board;
}