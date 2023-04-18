#ifndef ANIMATIEUTIL_H
#define ANIMATEUTIL_H

#include <math.h>

float Animate(float target, float current, float speed)
{
    int larger = 0;

    if(target > current)
    {
        larger = 1;
    } 
    else 
    {
        larger = 0;
    }

    if (speed < 0.0f)
    {
        speed = 5.0f;
    } 
    else if (speed > 1.0f)
    {
        speed = 1.0f;
    }

    float dif = fmaxf(target, current) - fminf(target, current);
    float factor = dif * speed;

    if (factor < 0.1f)
    {
        factor = 0.1f;
    }
    if (larger == 1)
    {
        current += factor;
    } 
    else 
    {
        current -= factor;
    }

    return current;
}

int getAnimation(int frameTime, float multiplier, float denominator, float piDenominator) 
{
    return multiplier*sin((frameTime/denominator)*(PI/piDenominator));
}

#endif // ANIMATeUTIL_H