#include <iostream>
#include <string>
#include <string_view>

enum class MonsterType 
{
    dragon,
    goblin,
    ogre,
    orc,
    skeleton,
    troll,
    vampire,
    zombie,
    maxMonsterTypes,
};

class Monster
{
private:
    MonsterType type {};
    std::string name {""};
    std::string roar {""};
    int hit_points {};
};