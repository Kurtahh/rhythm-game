#include "raylib.h"
#define WINDOW_W 1920
#define WINDOW_H 1080

void drawCentre()
{
    int rectW = 400;
    int rectH = 50;
    DrawRectangle(
        WINDOW_W/2 - rectW/2,
        WINDOW_H/2 - rectH/2,
        rectW,
        rectH,
        BLACK
    );
    DrawRectangle(
        WINDOW_W/2 - rectH/2,
        WINDOW_H/2 - rectW/2,
        rectH,
        rectW,
        BLACK
    );

    int squareSize = 100;
    DrawRectangle( //RIGHT
        WINDOW_W/2 + rectW/2 - squareSize/2,
        WINDOW_H/2 - squareSize/2,
        squareSize,
        squareSize,
        BLACK
    );
    DrawRectangle( //LEFT
        WINDOW_W/2 - rectW/2 - squareSize/2,
        WINDOW_H/2 - squareSize/2,
        squareSize,
        squareSize,
        BLACK
    );
    DrawRectangle( //DOWN
        WINDOW_W/2 - squareSize/2,
        WINDOW_H/2 + rectH + squareSize,
        squareSize,
        squareSize,
        BLACK
    );
    DrawRectangle( //UP
        WINDOW_W/2 - squareSize/2,
        WINDOW_H/2 - rectW/2 - squareSize,
        squareSize,
        squareSize,
        BLACK
    );  
}

void draw()
{
    ClearBackground(RAYWHITE);

    drawCentre();
}

int main(){
    InitWindow(WINDOW_W, WINDOW_H, "Proof of concept");
    SetTargetFPS(60);

    while(!WindowShouldClose()){
        BeginDrawing();
            draw();
        EndDrawing();
    }

    return 0;
}