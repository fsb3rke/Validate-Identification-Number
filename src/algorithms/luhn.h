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
        integerSum = sum[i] - '0';
        integerSumArray[i] = integerSum;
    }

    // ! Create a digit list (only include 2, 1 digits)
    // static int integerSumArrayLength = sizeof(integerSumArray) / sizeof(integerSumArray[0]);
    int digitArray[MAX_IDENTIFICATION_DIGIT_LENGTH];
    for (int i = 0; i < sumLength; i++) {
        if (i % 2 == 0) digitArray[i] = 2;
        else if (i % 2 == 1) digitArray[i] = 1;

        printf("%d\n", digitArray[i]);
    }

    // ! Multiply integer sum array to digit list
    int resultArray[MAX_IDENTIFICATION_DIGIT_LENGTH];
    for (int i = 0; i < sumLength; i++) {
        int sum;
        int multiplyValue = integerSumArray[i] * digitArray[i];
        printf("%d\n", multiplyValue);
        char* value = multiplyValue + '0';
        if (strlen(value) == 2) {
            char* splittedValue = value[0] + value[1];
            sum = splittedValue - '0';
        }
        else if (strlen(value) == 1) {
            sum = multiplyValue;
        }
        resultArray[i] = sum;
    }
}