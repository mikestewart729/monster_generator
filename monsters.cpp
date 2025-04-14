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
public: 
    enum Type 
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

    Monster(Type type, std::string_view name, std::string_view roar, int hit_points)
        : m_type { type }
        , m_name { name }
        , m_roar { roar }
        , m_hit_points { hit_points }
    {
    }

    constexpr std::string_view getTypeString() const
    {
        switch (m_type)
        {
        case dragon:    return "dragon";
        case goblin:    return "goblin";
        case ogre:      return "ogre";
        case orc:       return "orc";
        case skeleton:  return "skeleton";
        case troll:     return "troll";
        case vampire:   return "vampire";
        case zombie:    return "zombie";
        default:        return "unknown";
        }
    }

    void print() const 
    {
        std::cout << m_name << " the " << getTypeString();

        if (m_hit_points <= 0)
        {
            std::cout << " is dead.\n";
        }
        else
        {
            std::cout << " has " << m_hit_points << " and says " << m_roar << ".\n";
        }
    }

private:
    Type m_type {};
    std::string m_name {""};
    std::string m_roar {""};
    int m_hit_points {};
};

namespace MonsterGenerator
{
    Monster generate()
    {
        return Monster { Monster::skeleton, "Bones", "*rattle*", 4 };
    }
}

int main() 
{
    // Monster skeleton { Monster::skeleton, "Bones", "*rattle*", 4 };
    // skeleton.print();

    // Monster vampire { Monster::vampire, "Nibblez", "*hiss*", 0 };
    // vampire.print();

    Monster m { MonsterGenerator::generate() };
    m.print();

    return 0;
}