#include <gb/gb.h>
#include "snakeTileSet.c"

void init();
void updateSwitches();
void performantDelay(UINT8);
void checkInput();
void drawScreen();
void reset();
void move();
void eat();

UINT8 score;  // Amount of pizza eaten
UINT8 length; // Length of the snakes body, not including head and tail

enum direction
{
    up,   // 0
    down, // 1
    left, // 2
    right // 3
};

typedef struct
{
    UINT8 x;
    UINT8 y;
    UINT8 direction;
} Coordinate;

Coordinate target, head, body[50], tail, food;

void main()
{
    init();

    while (1)
    {
        reset();

        while (1)
        {
            checkInput();
            updateSwitches();
            move();

            if (head.x == food.x && head.y == food.y)
            {
                eat();
            }
        }
    }
}

void init()
{
    SHOW_BKG;
    DISPLAY_ON;

    set_sprite_data(0, 15, snakeTileSet);

    for (UINT8 i = 0; i < 16; i++)
    {
        set_sprite_tile(i, i);
    }
}

void updateSwitches()
{
    HIDE_WIN;
    SHOW_SPRITES;
    SHOW_BKG;
}

void performantDelay(UINT8 numloops)
{
    UINT8 i;
    for (i = 0; i < numloops; i++)
    {
        wait_vbl_done();
    }
}

void checkInput()
{
    if (joypad() & J_UP)
    {
        target.direction == up;
    }

    if (joypad() & J_DOWN)
    {
        target.direction == down;
    }

    if (joypad() & J_LEFT)
    {
        target.direction == left;
    }

    if (joypad() & J_RIGHT)
    {
        target.direction == right;
    }
}

void drawScreen()
{
    // Draw head
    for (UINT8 i = 0; i <= length; i++) // Draw body
    {
    }
    // Draw tail
}

void reset()
{
    length = 1;

    head.direction = right;
    head.x = 4;
    head.y = 4;

    body[0].direction = right;
    body[0].x = 3;
    body[0].y = 4;
}

void move()
{
    switch (target.direction)
    {
    case up:
        /* code */
        break;
    
    case down:
        break;
    
    case left:
        break;
    
    case right:
        break;
    
    default:
        break;
    }
    
}

void eat()
{
    length++;
}