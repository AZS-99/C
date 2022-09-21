//
// Created by Adam Saher on 2022-08-11.
//

#include <cmath>
#include "J2.h"

/*
IDEA:
Let I be the initially infected population
Let r represent the spreadability

The number of patients every day follows the formula:

Sn = I * r^0 + I * r^1 + .... + I * r^pens_count

∴ Sn = I (r^0 + r^1 + .... + r^pens_count)
∴ Sn = I (1 + r^1 + .... + r^pens_count)
∴ Sn * r = I (r^1 + r^2 + .... + r^(pens_count+1))
∴ Sn * r = Sn - I + r^(pens_count+1)
∴ Sn (r - 1) = r^(pens_count+1) - I
∴ Sn (r - 1) + I = r^(pens_count+1)
∴ log(Sn (r - 1) + I) = (pens_count+1) log r
∴ pens_count = [log(Sn (r - 1) + I) / log r] - 1


*/

double count_days(const unsigned& final_population, const unsigned& initial, const unsigned& r) {
    return std::log(final_population * (r - 1) + initial) / std::log(r);
}
