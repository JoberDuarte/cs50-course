#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>



int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open this card\n");
        return 1;
    }

   uint8_t buffer[512];

   int count_image = 0;

   FILE *image = NULL;

while (fread(buffer, 1, 512, card) == 512)
{

    if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && ((buffer[3] & 0xf0)== 0xe0))
    {

         if(image != NULL)
         {
            fclose(image);
         }

         char filename[8];
         sprintf(filename,"%03i.jpg",count_image );
         count_image++;
         image = fopen(filename, "w");
    }


      if (image != NULL)
         {
               fwrite(&buffer, 1, 512, image);
         }


}

if (image != NULL)
   {
   fclose(image);
   }

fclose(card);
}
