/* Developer: Juan Sergio Buenviaje
 * Lab: Tuesdays 2:25 - 3:15pm
 * Program: funanim.cpp
 * Description: Implementation of Rotating Animation using gfx library
 */
#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <cstdlib>
#include "gfx.h"

void yellow_square(const int, int, int);
void teal_circle(const int, int, int);
void magenta_triangle(const int, int, int);
void magenta_triangle_invert(const int, int, int);

#define PI 3.14159265

int main()
{
    const int XSIZE = 500, YSIZE = 500, SIZE = 50, BIGCIRCLER = 300, SMLCIRCLER = 250, TOPPOS = 49, BOTPOS = 451, RADIUS = 150;
    unsigned int delay = 10000;
    char c;
    int x = 250, y = 250, response;
    int counter = 0;
    int i = 72;

    gfx_open(XSIZE, YSIZE, "Rotating Animation"); // Open a new window for drawing.

    while (true)
    {
        response = gfx_event_waiting();

        yellow_square(RADIUS, x, TOPPOS); // Make watch
        yellow_square(RADIUS, x, BOTPOS);
        teal_circle(BIGCIRCLER, x, y);
        teal_circle(SMLCIRCLER, x, y);
        magenta_triangle(RADIUS, x, TOPPOS);
        magenta_triangle_invert(RADIUS, x, BOTPOS);
        magenta_triangle(RADIUS, x, BOTPOS);

        if (response) // Wait for key press or mouse click
        {
            gfx_clear();
            c = gfx_wait();
            if (c == 1) // On left click, change direction of hand
            {
                counter++;
            }
            else if (c == 'q')
            {
                break; // Quit if it is the letter q.
            }
            usleep(delay);
        }
        else
        {
            gfx_clear();
            gfx_color(200, 200, 200);
            gfx_line(x, y, (x - (RADIUS / 2) * sin((i + 1) * 5.0 * (PI / 180.0))), (y - (RADIUS / 2) * cos((i + 1) * 5.0 * (PI / 180.0))));
            if (counter % 2 == 0) // Rotate clockwise
            {
                i--;
                if (i == 1)
                {
                    i = 72;
                }
            }
            else // Rotate counterclockwise
            {
                i++;
                if (i == 71)
                {
                    i = 0;
                }
            }
            usleep(delay);
        }
    }
}

void yellow_square(const int SIZE, int x, int y)
{
    gfx_color(200, 200, 0);
    gfx_line((x - (SIZE / 2)), (y + (SIZE / 2)), (x + (SIZE / 2)), (y + (SIZE / 2)));
    gfx_line((x + (SIZE / 2)), (y + (SIZE / 2)), (x + (SIZE / 2)), (y - (SIZE / 2)));
    gfx_line((x - (SIZE / 2)), (y - (SIZE / 2)), (x + (SIZE / 2)), (y - (SIZE / 2)));
    gfx_line((x - (SIZE / 2)), (y + (SIZE / 2)), (x - (SIZE / 2)), (y - (SIZE / 2)));
}

void teal_circle(const int SIZE, int x, int y)
{
    gfx_color(0, 200, 200);
    gfx_circle(x, y, SIZE / 2);
}

void magenta_triangle(const int SIZE, int x, int y)
{
    gfx_color(200, 0, 200);
    gfx_line(x, (y - (SIZE / 2)), (x + ((SIZE / 4) * sqrt(3))), (y + (SIZE / 4)));
    gfx_line((x + ((SIZE / 4) * sqrt(3))), (y + (SIZE / 4)), (x - ((SIZE / 4) * sqrt(3))), (y + (SIZE / 4)));
    gfx_line((x - ((SIZE / 4) * sqrt(3))), (y + (SIZE / 4)), x, (y - (SIZE / 2)));
}

void magenta_triangle_invert(const int SIZE, int x, int y)
{
    gfx_color(200, 0, 200);
    gfx_line(x, (y + (SIZE / 2)), (x - ((SIZE / 4) * sqrt(3))), (y - (SIZE / 4)));
    gfx_line((x - ((SIZE / 4) * sqrt(3))), (y - (SIZE / 4)), (x + ((SIZE / 4) * sqrt(3))), (y - (SIZE / 4)));
    gfx_line((x + ((SIZE / 4) * sqrt(3))), (y - (SIZE / 4)), x, (y + (SIZE / 2)));
}
