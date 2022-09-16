// Copyright (c) 2022 fsb3rke
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT


#include "algorithms/luhn.h"
#include <stdio.h>

int main(void) {
    char* number;

    printf("Please enter identification number:\n");
    scanf("%d\n", &number);

    // if (checkLuhn(number) == 0) printf("VALID\n");
    // else printf("INVALID\n");

    checkLuhn(number);

    return 0;
}