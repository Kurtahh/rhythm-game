#include "note.h"

typedef struct {
    Note data;
    Node* next;
} Node;

typedef struct {
    Node* front;
    Node* back;
} NoteQueue;

void enqueue(Note note);
void dequeue();
Note getFront();
Note getBack();
