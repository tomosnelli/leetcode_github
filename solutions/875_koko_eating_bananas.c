/*
    875. Koko Eating Bananas
*/
#include "../utils/common.h"

int find_max(int* array, int size) {
    int max = 0;
    for (int i = 0; i < size; ++i) {
        max = max > array[i] ? max : array[i];
    }
    return max;
}

bool can_eat_all(int* piles, int pilesSize, int h, int k) {
    int hours = 0;
    for (int i = 0; i < pilesSize; ++i) {
        hours += (piles[i] + k - 1) / k;
    }
    return hours <= h;
}

int minEatingSpeed(int* piles, int pilesSize, int h) {
    int min_speed = 1;
    int max_speed = find_max(piles, pilesSize);

    while (min_speed < max_speed) {
        int average = min_speed + (max_speed - min_speed) / 2;
        if (can_eat_all(piles, pilesSize, h, average))
            max_speed = average;
        else
            min_speed = average + 1;
    }

    return min_speed;
}
