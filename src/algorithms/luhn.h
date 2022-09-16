// Copyright (c) 2022 fsb3rke
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT


#pragma once

#include <string.h>
#include <stdio.h>

#define MAX_IDENTIFICATION_DIGIT_LENGTH 19

void checkLuhn(char* sum) {
    int validStatus;
    int sumLength = strlen(sum);
    printf("%d\n", sumLength);
    
    // ! We need to split 'sum' string to integer digit list
    int integerSumArray[MAX_IDENTIFICATION_DIGIT_LENGTH];
    int integerSum;
    for (int i = 0; i < sumLength; i++) {
        if (sum[i] != ' ') {
            integerSum = sum[i] - '0';
            integerSumArray[i] = integerSum;
        }
    }

    // ! Create a digit list (only include 2, 1 digits)
    static int integerSumArrayLength = sizeof(integerSumArray) / sizeof(integerSumArray[0]);
    int digitArray[integerSumArrayLength];
    for (int i = 0; i < integerSumArrayLength; i++) {
        if (i % 2 == 0) digitArray[i] = 2;
        else if (i % 2 == 1) digitArray[i] = 1;

        printf("%d\n", digitArray[i]);
    }

    // ! Multiply integer sum array to digit list
    
}