#ifndef DIRECTION
#define DIRECTION

#include <iostream>
#include <cassert>
#include "random_mt.h"

class Direction
{
public:
    enum Type
    {
        up,
        down,
        left,
        right,
        maxDirections,
    };

    Direction(Type type)
        :m_type(type) {}

    Type getType() const{ return m_type; }

    static Direction getRandomDirection();

private:
    Type m_type{};
};

inline Direction Direction::getRandomDirection()
{
    Type random{ static_cast<Type>(Random::get(0, Type::maxDirections - 1)) };
    return Direction{ random };
}

inline std::ostream& operator<<(std::ostream& stream, Direction dir)
{
    switch (dir.getType())
    {
    case Direction::up:     return (stream << "up");
    case Direction::down:   return (stream << "down");
    case Direction::left:   return (stream << "left");
    case Direction::right:  return (stream << "right");
    default:                break;
    }

    assert(0 && "Unsupported direction was passed!");
    return (stream << "unknown direction");
}
#endif
