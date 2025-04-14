#include "random.h"
#include <iostream>
#include <string>
#include <string_view>

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
            std::cout << " has " << m_hit_points << " hit points and says " 
                      << m_roar << ".\n";
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
    // From problem statement, return a random name based on an integer 0-5 inclusive
    // in principle, can prevent "magic value" problems by setting this number as a 
    // variable, or otherwise handling it.
    std::string getName(int rand_index)
    {
        switch (rand_index)
        {
        case 0: return "Melvin";
        case 1: return "Snarkins";
        case 2: return "Mr. Bojangles";
        case 3: return "Horribilus";
        case 4: return "Evilina";
        case 5: return "Martin";
        default: return "?";
        }
    }

    // from problem statement, return a random roar based on an integer 0-5 inclusive
    std::string getRoar(int rand_index)
    {
        switch (rand_index)
        {
        case 0: return "*roar*";
        case 1: return "*shriek*";
        case 2: return "*screech*";
        case 3: return "*howl*";
        case 4: return "*ominous silence*";
        case 5: return "*boo*";
        default: return "";
        }
    }

    // make a variable to house the maximum of the health range for our monsters
    static int s_min_health { 0 };
    static int s_max_health { 100 };

    Monster generate()
    {
        return Monster { 
            static_cast<Monster::Type>(Random::get(0, Monster::maxMonsterTypes - 1)), 
            getName(Random::get(0, 5)), 
            getRoar(Random::get(0, 5)), 
            Random::get(MonsterGenerator::s_min_health, MonsterGenerator::s_max_health) 
        };
    }
}

int main() 
{
    Monster m { MonsterGenerator::generate() };
    m.print();

    return 0;
}