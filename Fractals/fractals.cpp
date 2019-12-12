/* Developer: Juan Sergio Buenviaje
 * Lab: Tuesdays 2:25 - 3:15pm
 * Program: fractals.cpp
 * Description: Implementation of Fractals using gfx library
 */
#include "gfx.h"
#include <math.h>
#include <cstdlib>

#define PI 3.14159265 // Constant variable

// Function prototypes
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3);
void drawSquare(int x, int y, double size);
void sierpinskiTriangle(int x1, int y1, int x2, int y2, int x3, int y3);
void shrinkingSquares(int x, int y, double size);
void spiralSquares(int x, int y, double r, double size, double angle);
void circularLace(int x, int y, double r);
void snowflake(double x, double y, double size);
void tree(double x, double y, double size, double angle);
void fern(double x, double y, double size, double angle);
void spiralOfSpirals(int x, int y, double size, double angle);

int main()
{
    int width = 700, height = 700; // Declare needed variables
    bool loop = true;
    double mrgn, r, size, angle;
    char c;

    gfx_open(width, height, "Fractals");

    while (loop)
    {
        c = gfx_wait();
        gfx_clear();
        switch (c)
        {
        case '1': // Sierpinski Triangle
            gfx_clear();
            mrgn = 20; // Initial variable/s
            sierpinskiTriangle(mrgn, mrgn, width - mrgn, mrgn, width / 2, height - mrgn);
            break;
        case '2': // Shrinking Squares
            gfx_clear();
            mrgn = width / 2; // Initial variable/s
            shrinkingSquares(width / 2, height / 2, mrgn);
            break;
        case '3': // Spiral Squares
            gfx_clear();
            r = 3; // Initial variable/s
            size = 2.0;
            angle = 0.0;
            spiralSquares(width / 2, height / 2, r, size, angle);
            break;
        case '4': // Circular Lace
            gfx_clear();
            r = 200; // Initial variable/s
            circularLace(width / 2, height / 2, r);
            break;
        case '5': // Snowflake
            gfx_clear();
            size = width / 3.0;
            snowflake(width / 2, height / 2, size);
            break;
        case '6': // Tree
            gfx_clear();
            angle = PI / 2.0; // Initial variable/s
            size = 0.8 * height / 2;
            tree(width / 2, height, size, angle);
            break;
        case '7': // Fern
            gfx_clear();
            angle = PI / 2.0; // Initial variable/s
            size = 0.6 * height;
            fern(width / 2.0, height, size, angle);
            break;
        case '8': // Spiral of Spirals
            gfx_clear();
            size = 750;
            angle = 165;
            spiralOfSpirals(width / 2, height / 2, size, angle);
            break;
        case 'q': // End program
            loop = false;
        default:
            break;
        }
    }

    return 0;
}

// Draw triangle
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
    gfx_line(x1, y1, x2, y2);
    gfx_line(x2, y2, x3, y3);
    gfx_line(x3, y3, x1, y1);
}

// Draw square
void drawSquare(int x, int y, double size)
{
    gfx_line(x - size / 2, y + size / 2, x + size / 2, y + size / 2);
    gfx_line(x + size / 2, y + size / 2, x + size / 2, y - size / 2);
    gfx_line(x + size / 2, y - size / 2, x - size / 2, y - size / 2);
    gfx_line(x - size / 2, y - size / 2, x - size / 2, y + size / 2);
}

// Sierpinski Triangle function
void sierpinskiTriangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
    // Base case
    if (abs(x2 - x1) < 5)
    {
        return;
    }

    // Draw triangle
    drawTriangle(x1, y1, x2, y2, x3, y3);

    // Recursive calls
    sierpinskiTriangle(x1, y1, (x1 + x2) / 2, (y1 + y2) / 2, (x1 + x3) / 2, (y1 + y3) / 2);
    sierpinskiTriangle((x1 + x2) / 2, (y1 + y2) / 2, x2, y2, (x2 + x3) / 2, (y2 + y3) / 2);
    sierpinskiTriangle((x1 + x3) / 2, (y1 + y3) / 2, (x2 + x3) / 2, (y2 + y3) / 2, x3, y3);
}

// Shrinking Squares function
void shrinkingSquares(int x, int y, double size)
{
    // Base case
    if (size < 3)
    {
        return;
    }

    // Draw square
    drawSquare(x, y, size);

    // Recursive calls
    shrinkingSquares(x - size / 2, y + size / 2, size / 2.2);
    shrinkingSquares(x + size / 2, y + size / 2, size / 2.2);
    shrinkingSquares(x + size / 2, y - size / 2, size / 2.2);
    shrinkingSquares(x - size / 2, y - size / 2, size / 2.2);
}

// Spiral Squares function
void spiralSquares(int x, int y, double r, double size, double angle)
{
    // Base case
    if (r > 350)
    {
        return;
    }

    // Draw square
    drawSquare(x + r * cos(angle), y - r * sin(angle), size);

    // Modify angle
    angle += (PI / 180.0) * 36;

    // Recursive calls
    spiralSquares(x, y, 1.1 * r, 1.08 * size, angle);
}

// Circular Lace function
void circularLace(int x, int y, double r)
{
    // Declare additional variable/s needed
    double angle = 0.0;

    // Base case
    if (r < 1)
    {
        return;
    }

    // Draw circle
    gfx_circle(x, y, r);

    // Recursive calls
    while (angle <= 2 * PI)
    {
        circularLace(x + r * cos(angle), y + r * sin(angle), r / 3);

        // Modify angle
        angle += (PI / 180.0) * 60.0;
    }
}

// Snowflake function
void snowflake(double x, double y, double size)
{
    // Declare additional variable/s needed
    double angle = 3. * PI / 2.;

    // Base case
    if (size < 1)
    {
        return;
    }

    while (angle <= 7.0 * PI / 2.0)
    {
        // Draw line
        gfx_line(x, y, x + size * cos(angle), y + size * sin(angle));

        // Recursive calls
        snowflake(x + size * cos(angle), y + size * sin(angle), size / 3);

        // Modify angle
        angle += (PI / 180.0) * 72.0;
    }
}

// Tree function
void tree(double x, double y, double size, double angle)
{
    // Base case
    if (size < 1)
    {
        return;
    }

    // Draw line
    gfx_line(x, y, x + size * cos(angle), y - size * sin(angle));

    // Recursive calls
    tree(x + size * cos(angle), y - size * sin(angle), 0.6 * size, angle + PI / 6);
    tree(x + size * cos(angle), y - size * sin(angle), 0.6 * size, angle - PI / 6);
}

// Fern function
void fern(double x, double y, double size, double angle)
{
    // Base case
    if (size < 3)
    {
        return;
    }

    // Draw line
    gfx_line(x, y, x + size * cos(angle), y - size * sin(angle));

    // Recursive calls
    for (int i = 1; i <= 4; i++)
    {
        fern(x + (size / 4) * i * cos(angle), y - (size / 4) * i * sin(angle), size / 2.8, angle + PI / 5);
        fern(x + (size / 4) * i * cos(angle), y - (size / 4) * i * sin(angle), size / 2.8, angle - PI / 5);
    }
}

// Spiral of Spirals function
void spiralOfSpirals(int x, int y, double size, double angle)
{
    // Base case
    if (size <= 1)
    {
        return;
    }

    // Declare additional variable/s needed
    double multi = 0.875;
    double phi = PI / 5;

    // Draw point
    gfx_point(x + size * cos(angle), y + size * sin(angle));

    // Recursive calls
    spiralOfSpirals(x, y, size * multi, angle + phi);
    spiralOfSpirals(x + size * cos(angle), y + size * sin(angle), size * 0.4, angle + phi);
}
