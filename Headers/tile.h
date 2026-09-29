#ifndef TILE
#define TILE

#include <iostream>


class Tile{
public:
    Tile() = default;
    constexpr explicit Tile(int num) : m_num{ num } {}
    constexpr bool isEmpty() const { return m_num == 0; }
    constexpr int getNum() const { return m_num; }
    
private:
    int m_num {};
};

inline std::ostream& operator<<(std::ostream& out, const Tile& tile){
    if (tile.getNum() > 9) // if two digit number
        out << " " << tile.getNum() << " ";
    else if (tile.getNum() > 0) // if one digit number
        out << "  " << tile.getNum() << " ";
    else if (tile.getNum() == 0) // if empty spot
        out << "    ";
    return out;

}





#endif
