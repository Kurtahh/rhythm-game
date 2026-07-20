#include "raylib.h"
#include <stdio.h>
#include <stdbool.h>

#define WINDOW_W 1920
#define WINDOW_H 1080

typedef enum {
    NONE,
    WRONG,
    RIGHT
} Timing;

static Timing state = NONE;
static KeyboardKey currentKey = 65;
static double countdown;

void drawCountdown()
{   
    const char* text = TextFormat("%d", (int)countdown+1);
    int textWidth = MeasureText(text, 200);
    DrawText(text, WINDOW_W/2 - textWidth/2, 0, 200, BLACK);
}

void updateCountdown()
{
    static int increment = 0;
    double currentTime = GetTime();   
    double counter = currentTime - increment;
    if(counter >= 10){
        increment = currentTime;
    }    
    countdown = 10 - counter;
}

void pollInput()
{
    if(countdown > 0 && countdown < 1 && IsKeyPressed(currentKey))
        state = RIGHT;
    else if(IsKeyPressed(currentKey)) 
        state = WRONG;
} 

void updateKey()
{
    if(currentKey == 91)
        currentKey = 65;
    else if(countdown == 10)
        currentKey++;
}

void update()
{
    updateCountdown();
    updateKey();
    pollInput();
}

void drawBackground()
{
    switch(state) {
        case NONE:
        ClearBackground(RAYWHITE);
        break;

        case RIGHT:
        ClearBackground(GREEN);
        break;

        case WRONG:
        ClearBackground(RED);
        break;
    }
}

void drawCurrentKey()
{
    char c = currentKey;
    const char* text = TextFormat("%c", c);
    int fontSize = 75;
    int textWidth = MeasureText(text, fontSize);
    DrawText(text, WINDOW_W/2 - textWidth/2, WINDOW_H/2 - fontSize/2, fontSize, BLACK);
}

void draw()
{
    BeginDrawing();
        drawBackground();
        drawCountdown();
        drawCurrentKey;
    EndDrawing();
}

int main(){
    InitWindow(1920, 1080, "input-test");
    SetTargetFPS(60);

    while(!WindowShouldClose()){
        update();
        draw();        
    }

    return 0;
}