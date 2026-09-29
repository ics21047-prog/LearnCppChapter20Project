#ifndef BOARD
#define BOARD

#include <iostream>
#include <utility>
#include "tile.h"
#include "direction.h"

inline constexpr int g_consoleLines{ 25 };

class Board{
public:

    Board() = default;

    friend std::ostream& operator<<(std::ostream& out, const Board& board);
    void slideTiles( Direction direction );
    void randomize();
    bool winCondition() const;


    ////   int operator[](int row, int col) const { return m_tiles[row][col].getNum(); } 
    ////    Position getPosOf0() { return m_pos0; }
private:
    struct Position{
        int row {};
        int col {};
    };
    static bool isValidPosition(Position position);


    static constexpr int s_size { 4 };
    Tile m_tiles[s_size][s_size] {
        Tile{ 1 }, Tile { 2 }, Tile { 3 } , Tile { 4 },
        Tile { 5 } , Tile { 6 }, Tile { 7 }, Tile { 8 },
        Tile { 9 }, Tile { 10 }, Tile { 11 }, Tile { 12 },
        Tile { 13 }, Tile { 14 }, Tile { 15 }, Tile { 0 } 
    };
    Position m_pos0{ s_size - 1, s_size - 1 };
};

inline std::ostream& operator<<(std::ostream& out, const Board& board){
    for (int i = 0; i < g_consoleLines; ++i)
        std::cout << '\n';
    for (int y = 0; y < Board::s_size; ++y)
    {
        for (int x = 0; x < Board::s_size; ++x)
            out << board.m_tiles[y][x];
        out << '\n';
    }

    return out;
}    

inline bool Board::isValidPosition(Position position)
{
    return position.row >= 0 && position.row < s_size
        && position.col >= 0 && position.col < s_size;
}

inline void Board::slideTiles(Direction direction){
    Position next { m_pos0 };
    switch(direction.getType()){
    case Direction::up:    --next.row; break;
    case Direction::down:  --next.row; break;
    case Direction::left:  ++next.col; break;
    case Direction::right: --next.col; break;
    default: return;
    }
    if(!isValidPosition(next)) return;

    std::swap(m_tiles[ m_pos0.row ][ m_pos0.col ] , 
              m_tiles[ next.row ][ next.col ]);
    m_pos0 = next;
}

inline bool Board::winCondition() const {
    for(int i { 0 }; i < s_size * s_size - 1; ++i){
        if( m_tiles[i / s_size][i % s_size].getNum() != i + 1) return false;
    }
    return m_tile[s_size - 1][s_size - 1].isEmpty();
}

void randomize(){
    constexpr int numOfMixes { 1000 };
    for( int i { 0 }; i < numOfMixes; ++i ){
        slideTiles(Direction::getRandomDirection());
    }
}




#endif
