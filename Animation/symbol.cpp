/* Developer: Juan Sergio Buenviaje
 * Lab: Tuesdays 2:25 - 3:15pm
 * Program: symbol.cpp
 * Description: Implementation of Symbolic Typewriter using gfx library
 */
#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "gfx.h"

void blue_square(const int, int, int);
void white_circle(const int, int, int);
void green_triangle(const int, int, int);
void polygon(const int, int, int, char);

#define PI 3.14159265

int main()
{
    const int XSIZE = 500, YSIZE = 500, SIZE = 50;
    char c;
    int x, y, k;

    gfx_open(XSIZE, YSIZE, "Symbolic Typewriter"); // Open a new window for drawing.

    while (true) // Loop infinitely until break
    {
        c = gfx_wait(); // Wait for the user to press a character.
        x = gfx_xpos();
        y = gfx_ypos();

        if (c == 1) // Blue square on mouse click
        {
            blue_square(SIZE, x, y);
        }
        else if (c == 'c') // White circle on 'c' press
        {
            white_circle(SIZE, x, y);
        }
        else if (c == 't') // Green triangle on 't' press
        {
            green_triangle(SIZE, x, y);
        }
        else if (c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9') // Purple n-sided regular polygon in circle on '3' - '9' press
        {
            polygon(SIZE, x, y, c);
        }
        else if (c == 27) // Clear screen on 'ESC' press
        {
            gfx_clear();
        }
        else if (c == 'q') // Quit program on 'q' press
        {
            break;
        }
    }
}

void blue_square(const int SIZE, int x, int y)
{
    gfx_color(0, 0, 200);
    gfx_line((x - (SIZE / 2)), (y + (SIZE / 2)), (x + (SIZE / 2)), (y + (SIZE / 2)));
    gfx_line((x + (SIZE / 2)), (y + (SIZE / 2)), (x + (SIZE / 2)), (y - (SIZE / 2)));
    gfx_line((x - (SIZE / 2)), (y - (SIZE / 2)), (x + (SIZE / 2)), (y - (SIZE / 2)));
    gfx_line((x - (SIZE / 2)), (y + (SIZE / 2)), (x - (SIZE / 2)), (y - (SIZE / 2)));
}

void white_circle(const int SIZE, int x, int y)
{
    gfx_color(200, 200, 200);
    gfx_circle(x, y, SIZE / 2);
}

void green_triangle(const int SIZE, int x, int y)
{
    gfx_color(0, 200, 0);
    gfx_line(x, (y - (SIZE / 2)), (x + ((SIZE / 4) * sqrt(3))), (y + (SIZE / 4)));
    gfx_line((x + ((SIZE / 4) * sqrt(3))), (y + (SIZE / 4)), (x - ((SIZE / 4) * sqrt(3))), (y + (SIZE / 4)));
    gfx_line((x - ((SIZE / 4) * sqrt(3))), (y + (SIZE / 4)), x, (y - (SIZE / 2)));
}

void polygon(const int SIZE, int x, int y, char c)
{
    gfx_color(200, 0, 200);
    switch (c)
    {
    case '3': // Equilateral & equiangular triangle
        for (int i = 0; i < 3; i++)
        {
            gfx_line((x - (SIZE / 2) * sin(i * 120.0 * (PI / 180.0))), (y - (SIZE / 2) * cos(i * 120.0 * (PI / 180.0))), (x - (SIZE / 2) * sin((i + 1) * 120.0 * (PI / 180.0))), (y - (SIZE / 2) * cos((i + 1) * 120.0 * (PI / 180.0))));
        }
        break;
    case '4': // Square
        for (int i = 0; i < 4; i++)
        {
            gfx_line((x - (SIZE / 2) * sin(i * 90.0 * (PI / 180.0))), (y - (SIZE / 2) * cos(i * 90.0 * (PI / 180.0))), (x - (SIZE / 2) * sin((i + 1) * 90.0 * (PI / 180.0))), (y - (SIZE / 2) * cos((i + 1) * 90.0 * (PI / 180.0))));
        }
        break;
    case '5': // Pentagon
        for (int i = 0; i < 5; i++)
        {
            gfx_line((x - (SIZE / 2) * sin(i * 72.0 * (PI / 180.0))), (y - (SIZE / 2) * cos(i * 72.0 * (PI / 180.0))), (x - (SIZE / 2) * sin((i + 1) * 72.0 * (PI / 180.0))), (y - (SIZE / 2) * cos((i + 1) * 72.0 * (PI / 180.0))));
        }
        break;
    case '6': // Hexagon
        for (int i = 0; i < 6; i++)
        {
            gfx_line((x - (SIZE / 2) * sin(i * 60.0 * (PI / 180.0))), (y - (SIZE / 2) * cos(i * 60.0 * (PI / 180.0))), (x - (SIZE / 2) * sin((i + 1) * 60.0 * (PI / 180.0))), (y - (SIZE / 2) * cos((i + 1) * 60.0 * (PI / 180.0))));
        }
        break;
    case '7': // Heptagon
        for (int i = 0; i < 7; i++)
        {
            gfx_line((x - (SIZE / 2) * sin(i * (360.0 / 7) * (PI / 180.0))), (y - (SIZE / 2) * cos(i * (360.0 / 7) * (PI / 180.0))), (x - (SIZE / 2) * sin((i + 1) * (360.0 / 7) * (PI / 180.0))), (y - (SIZE / 2) * cos((i + 1) * (360.0 / 7) * (PI / 180.0))));
        }
        break;
    case '8': // Octagon
        for (int i = 0; i < 8; i++)
        {
            gfx_line((x - (SIZE / 2) * sin(i * 45.0 * (PI / 180.0))), (y - (SIZE / 2) * cos(i * 45.0 * (PI / 180.0))), (x - (SIZE / 2) * sin((i + 1) * 45.0 * (PI / 180.0))), (y - (SIZE / 2) * cos((i + 1) * 45.0 * (PI / 180.0))));
        }
        break;
    case '9': // Nonagon
        for (int i = 0; i < 9; i++)
        {
            gfx_line((x - (SIZE / 2) * sin(i * 40.0 * (PI / 180.0))), (y - (SIZE / 2) * cos(i * 40.0 * (PI / 180.0))), (x - (SIZE / 2) * sin((i + 1) * 40.0 * (PI / 180.0))), (y - (SIZE / 2) * cos((i + 1) * 40.0 * (PI / 180.0))));
        }
        break;
    }
}
