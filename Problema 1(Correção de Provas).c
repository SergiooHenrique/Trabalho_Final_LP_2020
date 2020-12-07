#include <stdio.h>
#include <stdlib.h>

struct Candidatos
{
    int codigo;
    char respostas[50];
    int notaFinal;
};

int main()
{
    int qtdCandidatos = 1;
    int i, j;

    printf("Digite a quantidade de candidatos: ");
    scanf("%d", &qtdCandidatos);

    struct Candidatos pontuacao[qtdCandidatos];

    char gabarito[51] = "abcdeedcbaabcdeedcbaabcdeedcbaabcdeedcbaabcdeedcba\0";

    for(i = 1; i <= qtdCandidatos; i++)
    {
        struct Candidatos candidato;
        printf("Codigo do candidato: ");
        scanf("%d", &candidato.codigo);
        printf("Respostas dadas do candidato: ");
        scanf(" %s", &candidato.respostas);
        candidato.notaFinal = 0;
        for(j = 1; j <= 50; j++)
        {
            if(candidato.respostas[j] == gabarito[j])
            {
                candidato.notaFinal += 1;
            }
        }
        pontuacao[i].codigo = candidato.codigo;
        pontuacao[i].notaFinal = candidato.notaFinal;
    }

    for(i = 1; i <= qtdCandidatos; i++)
    {
        for (j = 1; j <= i; j++)
        {
            if (pontuacao[i].notaFinal > pontuacao[j].notaFinal)
            {
                int resultadoTemp = pontuacao[i].notaFinal;
                pontuacao[i].notaFinal = pontuacao[j].notaFinal;
                pontuacao[j].notaFinal = resultadoTemp;
            }
        }
    }

    printf("\n ----- PONTUACAO FINAL -----\n\n");

    for(i = 1; i <= qtdCandidatos; i++)
    {
        printf("%d %d\n", pontuacao[i].codigo, pontuacao[i].notaFinal);
    }
    printf("\n");
}
