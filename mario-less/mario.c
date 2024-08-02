#include <cs50.h>
#include <stdio.h>

void print_row(int ponto, int tamanho);


int main(void)
{
    // Pergunte ao usuario o tamanho da piramide
    int altura;
    do
    {
        altura = get_int(" Height: ");
    }
    while(altura < 1);

    //Mostre o tamanho da piramide
    for (int i = 0; i < altura; i++)
    {
        //Mostre a linha de #
        print_row(i + 1 , altura);
    }
}

void print_row(int ponto, int tamanho)

{
   for (int i = 0; i < tamanho - ponto ; i++)
   {
        printf(" ");
   }
   for(int i = 0; i < ponto; i++)
   {
        printf("#");
   }
   printf("\n");

}
