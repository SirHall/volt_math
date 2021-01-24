#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <vector>
#include <volt/math.hpp>

using namespace volt::math;

int main(int argc, char *argv[])
{
    std::cout << std::setw(10) << "Die" << std::setw(4) << "Add" << std::setw(4)
              << "Sub" << std::setw(4) << "Sum" << std::endl;
    for (GrimeDice die = GrimeDice::Blue; die <= GrimeDice::Yellow;
         die           = GrimeDice(int(die) + 1))
        std::cout << std::setw(10) << GrimeDiceName(die) << std::setw(4)
                  << GrimeDicePriceAdditive(die) * 100.0 << std::setw(4)
                  << GrimeDicePriceSubtractive(die) * 100.0 << std::setw(4)
                  << GrimeDicePriceTotal(die) * 100.0 << std::endl;
    ;

    std::cout << std::endl;

    return 0;

    std::vector<std::uint64_t> wins = std::vector<std::uint64_t>();
    wins.resize(5);

    std::vector<GrimeDice> dice = {GrimeDice::Olive, GrimeDice::Red};

    std::srand(unsigned int(std::time(nullptr)));

    for (std::size_t i = 0; i < 1000000; i++)
    {
        std::uint8_t aRoll = RollGrimeDice(dice[0]);
        std::uint8_t bRoll = RollGrimeDice(dice[1]);

        // std::cout << GrimeDiceName(dice[0]) << " - " << int(aRoll) << "  "
        //           << GrimeDiceName(dice[1]) << " - " << int(bRoll) <<
        //           std::endl;

        if (aRoll > bRoll)
            wins[int(dice[0])]++;
        if (bRoll > aRoll)
            wins[int(dice[1])]++;
    }

    std::cout << std::setw(8) << GrimeDiceName(dice[0]) << ": "
              << wins[int(dice[0])] << std::endl;
    std::cout << std::setw(8) << GrimeDiceName(dice[1]) << ": "
              << wins[int(dice[1])] << std::endl;

    std::cout << std::endl;

    if (wins[int(dice[0])] == wins[int(dice[1])])
        std::cout << "Tie" << std::endl;
    else if (wins[int(dice[0])] > wins[int(dice[1])])
        std::cout << GrimeDiceName(dice[0]) << " wins" << std::endl;
    else
        std::cout << GrimeDiceName(dice[1]) << " wins" << std::endl;

    std::cout << "Win Ratio: "
              << 100.0 / (wins[int(dice[0])] + wins[int(dice[1])]) *
                     std::max(wins[int(dice[0])], wins[int(dice[1])])
              << '%' << std::endl;

    return 0;
}