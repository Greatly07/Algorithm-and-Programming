#include <stdio.h>
#include "SimpleCar.h"

int main()
{
    int forward, backward;
    scanf("%d %d", &forward, &backward);

    SimpleCar car = InitCar();

    car = Drive(forward, car);
    car = Reverse(backward, car);

    HonkHorn(car);
    Report(car);

    return 0;
}