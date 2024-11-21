#include <stdio.h>
#include <stdlib.h>

double f(int x);
double fCauda(int x);
double fSem(int f);

int main()
{
    int posicao, resp;
    printf("Sequência de Fibonacci com recursiva simples.\n");
    do
    {
        printf("Qual posição deseja saber? \n");
        scanf("%d", &posicao);

        if (posicao < 0)
        {
            printf("Posicao invalida, encerrando programa...");
            exit(0);
        }

        printf("O valor da posicao %dº eh: %.0lf\n", posicao, f(posicao));

        printf("Quer saber mais alguma posicao com recursividade simples?\n1 - Sim\n2 - Nao\n");
        scanf("%d", &resp);
        if (resp != 1 && resp != 2)
        {
            do
            {
                printf("Resposta invalida, tente novamente.\n");
                printf("Quer saber mais alguma posicao com recursividade?\n1 - Sim\n2 - Nao\n");
                scanf("%d", &resp);
            } while (resp == 1 && resp == 2);
        }

    } while (resp != 2);

    printf("Agora usando recursiva em cauda.\n");
    do
    {
        printf("Qual posição deseja saber? ");
        scanf("%d", &resp);
        if (resp < 0)
        {
            printf("Posicao invalida, encerrando programa...");
            exit(0);
        }

        printf("O valor da posicao %dº eh: %.0lf\n", resp, fCauda(resp));

        printf("Quer saber mais alguma posicao usando a recursiva em cauda?\n1 - Sim\n2 - Nao\n");
        scanf("%d", &resp);
        if (resp != 1 && resp != 2)
        {
            do
            {
                printf("Resposta invalida, tente novamente.\n");
                printf("Quer saber mais alguma posicao sem recursividade?\n1 - Sim\n2 - Nao\n");
                scanf("%d", &resp);
            } while (resp == 1 && resp == 2);
        }

    } while (resp != 2);


    printf("Agora sem usar uma função recursiva.\n ");
    do
    {
        printf("Qual posição deseja saber? ");
        scanf("%d", &resp);
        if (resp < 0)
        {
            printf("Posicao invalida, encerrando programa...");
            exit(0);
        }

        printf("O valor da posicao %dº eh: %.0lf\n", resp, fSem(resp));

        printf("Quer saber mais alguma posicao sem recursividade?\n1 - Sim\n2 - Nao\n");
        scanf("%d", &resp);
        if (resp != 1 && resp != 2)
        {
            do
            {
                printf("Resposta invalida, tente novamente.\n");
                printf("Quer saber mais alguma posicao sem recursividade?\n1 - Sim\n2 - Nao\n");
                scanf("%d", &resp);
            } while (resp == 1 && resp == 2);
        }

    } while (resp != 2);

    return 0;
}
// recursiva Simples
double f(int x)
{
    if (x == 0) return 1;
    if (x == 1) return 2;
    return f(x - 1) + f(x - 2);
}
// Recursiva em Cauda
double fCaudaAux(int x, double a, double b)
{
    double k = x;
    if(k == 0) return a;
    if(k == 1) return b;

    return fCaudaAux(k-1, b, a+b);
}
double fCauda(int x)
{
    return fCaudaAux(x, 1, 2);
}

// Loop
double fSem(int f)
{
    double a = 0, b = 1, c;

    for (int x = 0; x <= f; x++)
    {
        c = a + b;
        a = b;
        b = c;
    }

    return c;
}
