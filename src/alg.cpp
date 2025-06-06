// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
        uint64_t result = num;
        while (num != 1) {
                if (num % 2 == 0)
                        num = num / 2;
                else
                        num = 3 * num + 1;
                if (num > result)
                        result = num;
        }
        return result;
}

unsigned int collatzLen(uint64_t num) {
        unsigned int length = 1;
        while (num != 1) {
                if (num % 2 == 0)
                        num = num / 2;
                else
                        num = 3 * num + 1;
                length++;
        }
        return length;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
        unsigned int maxLength = 1;
        unsigned int numberWithMaxLength = lbound;
        for (uint64_t i = lbound; i <= rbound; i++) {
                unsigned int currentLength = collatzLen(i);
                if (currentLength > maxLength) {
                        maxLength = currentLength;
                        numberWithMaxLength = i;
                }
        }
        *maxlen = maxLength;
        return numberWithMaxLength;
}
