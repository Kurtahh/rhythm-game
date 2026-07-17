#include "raylib.h"
#include <stdio.h>

#define WINDOW_W 1920
#define WINDOW_H 1080

void UpdateTimer()
{
    static int start = 0;
    int clock = GetTime();   
    int counter = clock - start;
    int countdown = 10 - counter;
    
    if(counter == 10){
        start = clock;
        countdown = 1;
    }
    
    const char* text = TextFormat("%d", countdown);
    int textWidth = MeasureText(text, 200);

    DrawText(text, WINDOW_W/2 - textWidth/2, 0, 200, BLACK);
}

int main(){
    InitWindow(1920, 1080, "input-test");
    SetTargetFPS(60);

    while(!WindowShouldClose()){
        BeginDrawing();
            ClearBackground(RAYWHITE);

            UpdateTimer();
        EndDrawing();
    }

    return 0;
}