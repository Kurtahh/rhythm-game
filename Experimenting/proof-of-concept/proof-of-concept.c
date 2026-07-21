#include "raylib.h"
#include "note.h"
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
        WINDOW_W/2 + rectW/2,
        WINDOW_H/2 - squareSize/2,
        squareSize,
        squareSize,
        BLACK
    );
    DrawRectangle( //LEFT
        WINDOW_W/2 - rectW/2 - squareSize,
        WINDOW_H/2 - squareSize/2,
        squareSize,
        squareSize,
        BLACK
    );
    DrawRectangle( //DOWN
        WINDOW_W/2 - squareSize/2,
        WINDOW_H/2 + rectW/2,
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

void drawNote(Vector2 pos)
{
    const int noteSize = 100;
    const char* letter = "A"; 
    const int fontSize = 75;
    int textWidth = MeasureText(letter, fontSize);
    Vector2 textPos = {
        pos.x + noteSize/2 - textWidth/2,
        pos.y + noteSize/2 - fontSize/2
    };

    DrawRectangle(pos.x, pos.y, noteSize, noteSize, BLACK);
    DrawText("A", textPos.x, textPos.y, 75, WHITE);
}

void updateIncomingNotes()
{

}

void update()
{
    updateIncomingNotes();
}

void drawIncomingNotes()
{

}

void draw()
{
    BeginDrawing();
        //static
        ClearBackground(RAYWHITE);
        drawCentre();

        //dynamic
        drawNote((Vector2){100, 150});
    EndDrawing();
}

int main(){
    InitWindow(WINDOW_W, WINDOW_H, "Proof of concept");
    SetTargetFPS(60);

    while(!WindowShouldClose()){
        update();
        draw();
    }

    return 0;
}