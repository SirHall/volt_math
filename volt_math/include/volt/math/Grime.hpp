#pragma once
#ifndef VOLT_MATH_GRIME_HPP
#define VOLT_MATH_GRIME_HPP

#include <cstdint>
#include <string>

namespace volt::math
{
    enum class GrimeDice
    {
        Blue,
        Magenta,
        Olive,
        Red,
        Yellow
    };

    std::uint8_t RollGrimeDice(GrimeDice dice);

    std::string const &GrimeDiceName(GrimeDice dice);

    // Each die is beats two other die, the value returned here is the sum of
    // the probabilities that dice A beats the only other two dice that it can
    // 'reliably' beat.
    // For example, the blue die is only better than the olive, and the magenta.
    // By extension, the blue die beats the olive die 58% of the time, and beats
    // magenta 67% of the time. The value returned here are these two
    // probabilities - summed.
    // This gives a die's additive-only value.
    double GrimeDicePriceAdditive(GrimeDice dice);

    // Each die can be beat more realiably by 2 other die, these two values are
    // added together to give a die's 'negative price'
    double GrimeDicePriceSubtractive(GrimeDice dice);

    // This returns a die's additive price, subtract its subtractive price
    double GrimeDicePriceTotal(GrimeDice dice);

} // namespace volt::math
#endif
