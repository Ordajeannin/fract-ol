#include "test.h"
#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <X11/keysym.h>
#include <X11/X.h>

# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF

//define a color : 0xTTRRGGBB, value from 0 to 255
int encode_trgb(int transparency, int red, int green, int blue)
{
    return (transparency << 24 | red << 16 | green << 8 | blue);
}


int get_transparency(int trgb)
{
    return ((trgb >> 24) & 0xFF);
}

int get_red(int trgb)
{
    return ((trgb >> 16) & 0xFF);
}

int get_green(int trgb)
{
    return ((trgb >> 8) & 0xFF);
}

int get_blue(int trgb)
{
    return (trgb & 0xFF);
}

int add_shade(double intensity, int color)
{
    int transparency;
    int r;
    int g;
    int b;

    transparency = intensity * 255;
    r = get_red(color);
    g = get_green(color);
    b = get_blue(color);

    return (transparency << 24 | r << 16 | g << 8 | b);
}

int get_complementary(int color)
{
    int t;
    int r;
    int g;
    int b;

    t = get_transparency(color);
    r = get_red(color);
    g = get_green(color);
    b = get_blue(color);

    r = 255 - r;
    g = 255 - g;
    b = 255 - b;

    return (t << 24 | r << 16 | g << 8 | b);
}