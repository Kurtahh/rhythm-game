#include "note_queue.h"
#include <stdbool.h>

static NoteQueue notes;
static bool isQueue = false;

void enqueue(Note note)
{
    if(!isQueue){
        Node newNode;
        newNode.data = note;
        notes.front = &newNode;
    }
}