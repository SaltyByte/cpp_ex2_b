#ifndef EX_2_A_BOARD_HPP
#define EX_2_A_BOARD_HPP

#include <string>
#include <vector>
#include <map>
#include <climits>
#include "Direction.hpp"

namespace ariel {
    class Board {
    public:
        std::string read(unsigned int row, unsigned int col, Direction direction, int length);
        void post(unsigned int row, unsigned int col, Direction direction, const std::string &word);
        void show();

    private:
        std::map<unsigned int,std::map<unsigned int,std::string>> board;
        unsigned int rowStart = UINT_MAX;
        unsigned int colStart = UINT_MAX;
        unsigned int colEnd = 0;
        unsigned int rowEnd = 0;
    };
}


#endif
