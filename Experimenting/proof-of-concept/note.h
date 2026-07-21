typedef enum {
    UP,
    RIGHT,
    DOWN,
    LEFT
} Direction;

typedef struct {
    char letter;
    Direction dir;
    int speed;
} Note;