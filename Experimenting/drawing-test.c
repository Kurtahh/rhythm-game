#include "raylib.h"

#define increment 100

void update(Vector2* pos)
{
    if(IsKeyDown(KEY_A))
        pos->x -= increment; 
    if(IsKeyDown(KEY_W))
        pos->y -= increment;
    if(IsKeyDown(KEY_D))
        pos->x += increment;
    if(IsKeyDown(KEY_S))
        pos->y += increment;
}

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Controllable square");

    Vector2 pos = {screenWidth/2 - 50, screenHeight/2 - 50};

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE);

            update(&pos);

            DrawRectangle(pos.x, pos.y, 100, 100, BLACK);

        EndDrawing();
    }
    CloseWindow();

    return 0;
}

