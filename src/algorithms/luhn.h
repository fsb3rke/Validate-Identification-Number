// Copyright (c) 2022 fsb3rke
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT


#pragma once

#include <stdio.h>
#include <string.h>

#define MAX_IDENTIFICATION_DIGIT_LENGTH 16
#define SPLIT_MAGIC_NUMBER 9

int checkLuhn(char* sum) {
    int validStatus;
    validStatus = 1;
    int sumLength = strlen(sum);
    // printf("%d\n", sumLength);
    
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

        // printf("%d : %d\n", i, digitArray[i]);
    }

    // ! Multiply integer sum array to digit list
    int resultArray[MAX_IDENTIFICATION_DIGIT_LENGTH];
    int m_sum;
    int multiplyValue;
    for (int i = 0; i < sumLength; i++) {
        m_sum = 0;
        multiplyValue = integerSumArray[i] * digitArray[i];
        if (multiplyValue >= 10) {
            m_sum = multiplyValue - 9;
        }
        else {
            m_sum = multiplyValue;
        }
        // printf("\n%d\n", m_sum);
        resultArray[i] = m_sum;
    }

    // ! Add up all the numbers
    int resultNumber;
    resultNumber = 0;
    for (int i = 0; i < sumLength; i++) {
        resultNumber += resultArray[i];
    }
    // printf("%d\n", resultNumber);

    // ! Check, if number is divisible by ten (10)
    if (resultNumber % 10 == 0) validStatus = 0;
    else validStatus = 1;

    return validStatus;
}