//
// Created by Adam Saher on 2022-04-17.
//

#include <vector>
#include "S2_goldbachs_conjecture.h"

std::vector<bool> sieve(const unsigned& num) {
    std::vector<bool> primes(num, true);

    primes[0] = primes[1] = false;
    auto index = 2u;
    while (index < num) {
        for (auto i = index * index; i < num; i += index) primes[i] = false;
        while (!primes[++index]); //Step first, because the index is still at i = 2
    }
    return primes;
}


std::pair<unsigned, unsigned> find_prime_pair(const unsigned& num) {
    auto primes = sieve(num * 2 + 1);
    auto size = primes.size();
    for (auto i = 0u; i < size / 2; ++i) {
        if (primes[i] && primes[size - i - 1])
            return std::make_pair(i, size - i - 1);
    }
    return std::make_pair(0, 0);
}