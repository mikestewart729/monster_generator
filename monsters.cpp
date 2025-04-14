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
    MonsterType m_type {};
    std::string m_name {""};
    std::string m_roar {""};
    int m_hit_points {};
};