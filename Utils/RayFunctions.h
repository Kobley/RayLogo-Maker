#ifndef RAYFUNCTIONS_H
#define RAYFUNCTIONS_H

#include <raylib.h>
#include <raymath.h>
#include <math.h>

// Look at rotates an object to point/look at a given point. It returns an angle in degrees

float RfuncLookAt(Vector2 pos, Vector2 target)
{
    return atan2(pos.y - target.y, pos.x - target.x) * RAD2DEG;

}

// Move towards makes an object move towards a given point. It returns a Vector2

Vector2 RfuncMoveTowards(Vector2 pos, Vector2 target, float speed)
{
    Vector2 results = Vector2Normalize((Vector2) {target.x - pos.x, target.y - pos.y});
    Vector2 new_pos = (Vector2) {results.x * speed, results.y * speed};
    return (Vector2) {pos.x + new_pos.x, pos.y + new_pos.y};
}

#endif