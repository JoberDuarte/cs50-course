#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            uint8_t media = (uint8_t) ((image[i][j].rgbtRed + image[i][j].rgbtGreen +image[i][j].rgbtBlue )/ 3);
            image[i][j].rgbtRed = media;
            image[i][j].rgbtGreen = media;
            image[i][j].rgbtBlue = media;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float red =  (0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
            float green = (0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            float blue =  (0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);

            if (red > 255) red = 255;
            if (green > 255) green = 255;
            if (blue > 255) blue = 255;

            image[i][j].rgbtRed = (uint8_t) red;
            image[i][j].rgbtGreen = (uint8_t) green;
            image[i][j].rgbtBlue = (uint8_t) blue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width / 2); j++)
        {
            int buffer_r = image[i][j].rgbtRed;
            image[i][j].rgbtRed = image[i][ width - 1 - j ].rgbtRed;
            image[i][ width - 1 - j].rgbtRed = buffer_r;

            int buffer_g = image[i][j].rgbtGreen;
            image[i][j].rgbtGreen = image[i][ width - 1 - j ].rgbtGreen;
            image[i][ width - 1 - j ].rgbtGreen = buffer_g;

            int buffer_b = image[i][j].rgbtBlue;
            image[i][j].rgbtBlue = image[i][ width - 1 - j ].rgbtBlue;
            image[i][ width - 1 - j ].rgbtBlue = buffer_b;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    float sum_red = 0;
    float sum_green = 0;
    float sum_blue = 0;
    float pixels_count = 0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j].rgbtRed = image[i][j].rgbtRed;
            copy[i][j].rgbtGreen = image[i][j].rgbtGreen;
            copy[i][j].rgbtBlue = image[i][j].rgbtBlue;

            for (int a = -1 ; a < 1 ; a++)
            {
                for (int b = -1; b < 1; b++)

                int a = i;
                int b = j;


                pixels_count +=1;
                sum_red += copy[a][b].rgbtRed;
                sum_green += copy[a][b].rgbtGreen;
                sum_blue += copy[a][b].rgbtRed;

            }
        copy[i][j].rgbtRed = ( sum_red / pixels_count);
        copy[i][j].rgbtGreen = ( sum_green / pixels_count);
        copy[i][j].rgbtBlue = ( sum_blue / pixels_count);

        }
    }

    return;
}
