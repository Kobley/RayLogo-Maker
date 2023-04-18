#include "include/raylib.h"
#include "Utils/Colors.h"
#include "Utils/AnimateUtil.h"
#include <string.h>

#define window_size 1024 // Change this if you want to change resolution of the output
#define l_color COLOR_BLACK
#define l_text_color COLOR_BLACK
#define l_text "raylib" //11 char recommended length with /8 text
#define l_text_size (window_size/(strlen(l_text)/1.2)) // I highly suggest 8 or 10 if your text is a little long. Bigger values = smaller text = straying from the original raylogo look
#define l_size_const (window_size/16)// Recommended to not change if you want the raylib look
#define l_size (window_size-l_size_const) // Recommended to not change

void DrawBox(int posX, int posY, int width, int height, int lineThickness, Color color) 
{
    DrawRectangle(posX, posY, width, height, color);
    DrawRectangle(posX+lineThickness, posY+lineThickness, width-lineThickness*2, height-lineThickness*2, COLOR_WHITE);
}

int main(void)
{
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(window_size, window_size, "RayLogo Maker");
    SetWindowState(FLAG_VSYNC_HINT);
    HideCursor();

    int screenFPS = 60;
    int frameTime = 0;

    while (!WindowShouldClose())
    {
        SetTargetFPS(screenFPS);
        frameTime += screenFPS;

        BeginDrawing();
            ClearBackground(COLOR_WHITE);

            DrawBox(l_size_const/2,
                    l_size_const/2,
                    l_size,l_size,
                    l_size_const, l_color);

            DrawText(l_text,
                    l_size-(MeasureText(l_text,l_text_size)+l_size_const),
                    l_size-(l_text_size+l_size_const), // adding getAnimation(frameTime, 16, 2, 1500) allows for a smooth up and down animation 
                    l_text_size, l_text_color);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}