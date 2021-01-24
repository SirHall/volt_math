#include "volt/math/Grime.hpp"

#include <array>
#include <random>

using namespace volt::math;

// TODO: Use 'constinit'
static constexpr std::array<std::uint8_t, 5 * 6> grimeVals{// Blue
                                                           2, 2, 2, 7, 7, 7,
                                                           // Magenta
                                                           1, 1, 6, 6, 6, 6,
                                                           // Olive
                                                           0, 5, 5, 5, 5, 5,
                                                           // Red
                                                           4, 4, 4, 4, 4, 9,
                                                           // Yellow
                                                           3, 3, 3, 3, 8, 8};

static const std::array<std::string, 5> grimeNames{"Blue", "Magenta", "Olive",
                                                   "Red", "Yellow"};

std::uint8_t volt::math::RollGrimeDice(GrimeDice dice)
{
    // It is slow to re-construct the generator each time we need it, but for
    // now this helps keep this function thread-safe
    return grimeVals[(int(dice) * 6) + int(std::rand() % 6)];
}

std::string const &volt::math::GrimeDiceName(GrimeDice dice)
{
    return grimeNames[int(dice)];
}

static constexpr std::array<double, 5> grimeAddativePrice{// Blue
                                                          0.58 + 0.67,
                                                          // Magenta
                                                          0.56 + 0.72,
                                                          // Olive
                                                          0.56 + 0.69,
                                                          // Red
                                                          0.58 + 0.72,
                                                          // Yellow
                                                          0.56 + 0.67};

double volt::math::GrimeDicePriceAdditive(GrimeDice dice)
{
    return grimeAddativePrice[int(dice)];
}

static constexpr std::array<double, 5> grimeSubtractivePrice{// Blue
                                                             0.58 + 0.67,
                                                             // Magenta
                                                             0.56 + 0.67,
                                                             // Olive
                                                             0.58 + 0.72,
                                                             // Red
                                                             0.56 + 0.69,
                                                             // Yellow
                                                             0.56 + 0.72};

double volt::math::GrimeDicePriceSubtractive(GrimeDice dice)
{
    return grimeSubtractivePrice[int(dice)];
}

double volt::math::GrimeDicePriceTotal(GrimeDice dice)
{
    return volt::math::GrimeDicePriceAdditive(dice) -
           volt::math::GrimeDicePriceSubtractive(dice);
}
