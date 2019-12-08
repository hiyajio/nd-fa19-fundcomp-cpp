/* Developer: Juan Sergio Buenviaje
 * Lab: Tuesdays 2:25 - 3:15pm
 * Program: bounce.cpp
 * Description: Implementation of Bouncing Ball using gfx library
 */
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <time.h>
#include "gfx.h"

int main()
{
    const int XSIZE = 500, YSIZE = 300, SIZE = 50;
    unsigned int delay = 10000;
    char c;
    int x, y, a, xa, ya, response;
    int counter = 0;
    a = rand() % 10 + 1; // Get random seed
    xa = a;
    ya = a;
    x = 250; // Start from center of window
    y = 150;

    gfx_open(XSIZE, YSIZE, "Bouncing Ball"); // Open a new window for drawing.
    gfx_color(200, 200, 200);

    while (true)
    {
        response = gfx_event_waiting();

        if (response) // Wait for key press or mouse click
        {
            gfx_clear();
            c = gfx_wait();
            x = gfx_xpos();
            y = gfx_ypos();
            if (c == 1) // White circle on mouse click
            {
                a = rand() % 10 + 1;
                xa = a;
                ya = a;
                gfx_circle(x, y, SIZE / 2);
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
            if ((x > 500) || (x < 0)) // Bounce off left/right walls
            {
                xa = -xa;
            }
            if ((y > 300) || (y < 0)) // Bounce off top/bottom walls
            {
                ya = -ya;
            }
            x += xa; // Update circle position
            y += ya;
            gfx_circle(x, y, SIZE / 2);
            usleep(delay);
        }
    }
}
