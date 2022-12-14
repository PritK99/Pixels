#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "image.h"

float get_pixel(image im, int x, int y, int c)
{
    /*im.data is nothing but a 1D array where data of pixels is arranged row wise*/
    return im.data[x + y * im.w + c * im.w * im.h];
}

void set_pixel(image im, int x, int y, int c, float v)
{
    /*im.data is nothing but a 1D array where data of pixels is arranged row wise*/
    im.data[x + y * im.w + c * im.w * im.h] = v;
}

image copy_image(image im)
{
    image copy = make_image(im.w, im.h, im.c);
    /*im.data is nothing but a 1D array with maximum size of no_of_rows * no_of_colums * no_ofchannels */
    for (int i = 0; i <= im.c * im.h * im.w; i++)
    {
        copy.data[i] = im.data[i];
    }
    return copy;
}

image rgb_to_grayscale(image im)
{
    assert(im.c == 3);
    image gray = make_image(im.w, im.h, 1);

    /*Please note that the Graycscale image has only one channel unlinke RGB , which has 3 channels
    Formula for the conversion is : Y' = 0.299 R' + 0.587 G' + .114 B'
    Y' is the only channel as output , where R' , G' , B' are to be used as input simultanously*/
    for (int i = 0; i < im.h; i++)
    {
        for (int j = 0; j < im.w; j++)
        {
            gray.data[j + i * im.w] = (0.299 * im.data[j + i * im.w + 0 * im.w * im.h]) + (0.587 * im.data[j + i * im.w + 1 * im.w * im.h]) + (0.114 * im.data[j + i * im.w + 2 * im.w * im.h]);
        }
    }
    return gray;
}

void shift_image(image im, int c, float v)
{
    for (int i = 0; i < im.h * im.w; i++)
    {
        im.data[i + c * im.h * im.w] = im.data[i + c * im.h * im.w] + v;
    }
}

void clamp_image(image im)
{
    for (int i = 0; i < im.h * im.c * im.w; i++)
    {
        if (im.data[i] > 1)
        {
            im.data[i] = 1;
        }
        else if (im.data[i] < 0)
        {
            im.data[i] = 0;
        }
        else
        {
            continue;
        }
    }
}

float three_way_max(float a, float b, float c)
{
    return (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
}

float three_way_min(float a, float b, float c)
{
    return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
}

void rgb_to_hsv(image im)
{
    float value, m, C, saturation, hue, hue_bar;
    for (int i = 0; i < im.w * im.h; i++)
    {
        // get value
        value = three_way_max(im.data[i], im.data[i + im.w * im.h], im.data[i + 2 * im.w * im.h]);

        // get saturation with special condition that if all R , G ,B values are 0
        if (im.data[i] == 0 && im.data[i + im.w * im.h] == 0 && im.data[i + 2 * im.w * im.h] == 0)
        {
            saturation = 0;
            C = 0;
        }
        else
        {
            m = three_way_min(im.data[i], im.data[i + im.w * im.h], im.data[i + 2 * im.w * im.h]);
            C = value - m;
            saturation = C / value;
        }

        // get hue
        if (C == 0)
        {
            hue_bar = 0;
        }
        else if (value == im.data[i])
        {
            hue_bar = (im.data[i + im.w * im.h] - im.data[i + 2 * im.w * im.h]) / C;
        }
        else if (value == im.data[i + im.w * im.h])
        {
            hue_bar = ((im.data[i + 2 * im.w * im.h] - im.data[i]) / C) + 2;
        }
        else if (value == im.data[i + 2 * im.w * im.h])
        {
            hue_bar = ((im.data[i] - im.data[i + im.w * im.h]) / C) + 4;
        }

        if (hue_bar < 0)
        {
            hue = (hue_bar / 6) + 1;
        }
        else
        {
            hue = hue_bar / 6;
        }

        im.data[i] = hue;
        im.data[i + im.w * im.h] = saturation;
        im.data[i + 2 * im.w * im.h] = value;
    }
}

void hsv_to_rgb(image im)
{
    float R, G, B, m, M, z;

    for (int i = 0; i < im.w * im.h; i++)
    {
        M = 255 * im.data[i + 2 * im.h * im.w];
        m = M * (1 - im.data[i + im.h * im.w]);

        z = (M - m) *(1 - fabs(remainder(60 * im.data[i], 2) - 1));

        float h = im.data[i] * 360;

        if (h >= 0 && h < 60)
        {
            R = M;
            G = z + m;
            B = m;
        }
        else if (h >= 60 && h < 120)
        {
            R = z + m;
            G = M;
            B = m;
        }
        else if (h >= 120 && h < 180)
        {
            R = m;
            G = M;
            B = z + m;
        }
        else if (h >= 180 && h < 240)
        {
            R = m;
            G = z + m;
            B = M;
        }
        else if (h >= 240 && h < 300)
        {
            R = z + m;
            G = m;
            B = M;
        }
        else
        {
            R = M;
            G = m;
            B = z + m;
        }

        im.data[i] = R/255 ;
        im.data[i + im.w*im.h] = G/255 ;
        im.data[i + 2*im.w*im.h] = B / 255 ;
    }
}
