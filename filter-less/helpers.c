#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    uint8_t buffer_r;
    uint8_t buffer_g;
    uint8_t buffer_b;
    for(int i = 0, i < height, i++)
    {
        for (int j = 0, j < width, j++)
        {
            fread(&buffer_r, 1, 1, image[i][j].rgbtRed);
            fread(&buffer_g, 1, 1, image[i][j].rgbtGreen);
            fread(&buffer_b, 1, 1, image[i][j].rgbtBlue);
            fwrite((&buffer_r * 0.3), 1, 1, image[i][j].rgbRed);
            fwrite((&buffer_g * 0.59), 1, 1, image[i][j].rgbtGreen);
            fwrite((&buffer_b * 0.11), 1, 1, image[i][j].rgbtBlue);

        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
