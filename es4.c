#include <stdio.h>
#include <limits.h>

int Menu()
{
    int scelta;
    printf("premere 1 per mostrare il contenuto dell'array\n");
    printf("premere 2 per inserire un elemento in coda\n");
    printf("premere 3 per modificare un elemento, se presente\n");
    printf("premere 4 per eliminare un elemento, se presente\n");
    printf("premere 5 per ricercare un elemento\n");
    printf("premere 6 per inserire un elemento in una certa posizione\n");
    printf("premere 7 per mostrare il contenuto dell'array all'inverso\n");
    printf("premere 8 per mostrare il valore massimo dell'array\n");
    printf("premere 0 per terminare\n");
    scanf("%d", &scelta);
    return scelta;
}

void Stampa(int vettore[], int j)
{
    for (int i = 0; i < j; i++)
    {
        printf("%d\n", vettore[i]);
    }
}

int Inserimento(int numero, int n, int vet[])
{
    vet[n] = numero;
    return n + 1;
}

void StampaInverso(int v[], int h)
{
    for (int i = h - 1; i >= 0; i--)
    {
        printf("%d \n", v[i]);
    }
}

int Ricerca(int ricerca, int ve[], int g)
{
    int uguale = ricerca;
    int trovato = 0;
    for (int i = 0; i < g; i++)
    {
        if (ve[i] == ricerca)
        {
            trovato = 1;
            break;
        }
    }
    return trovato;
}
int Max(int vet[], int k)
{
    int max = vet[0];
    for (int i = 1; i < k; i++)
    {
        if (vet[i] > max)
        {
            max = vet[i];
        }
    }
    return max;
}

int main(int argc, char *argv[])
{
    int array[SHRT_MAX];
    int i = 0;
    int num;
    int scelta, ricerca, trovato;

    do
    {
        printf("Inserisci un numero (inserisci -1 per terminare):\n");
        scanf("%d", &num);
        if (num != -1)
        {
            array[i] = num;
            i++;
        }
    } while (num != -1);

    do
    {
        scelta = Menu();
        if (scelta == 1)
        {
            Stampa(array, i);
        }
        else if (scelta == 2)
        {
            printf("Quale elemento vuoi inserire?\n");
            scanf("%d", &num);
            i = Inserimento(num, i, array);
        }
        else if (scelta == 7)
        {
            StampaInverso(array, i);
        }
        else if (scelta == 0)
        {
            printf("Programma finito\n");
        }
        else if (scelta == 5)
        {
            printf("Quale elemento vuoi ricercare?\n");
            scanf("%d", &ricerca);
            trovato = Ricerca(ricerca, array, i);
            if (trovato == 1)
            {
                printf("Elemento trovato");
            }
            else
            {
                printf("Elemento NON trovato");
            }
        }
        else if (scelta == 8)
        {
            int massimo = Max(array, i);
            printf("Il numero massimo all'interno dell'array è: %d \n", massimo);
        }
    } while (scelta != 0);

    return 0;
}
