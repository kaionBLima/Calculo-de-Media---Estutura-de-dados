#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct {
    char nome[100];
    float telefone;
    char curso[20];
    float nota1;
    float nota2;
} DadosAluno;

double calculaMedia(float nota1, float nota2) {
    return (nota1 + nota2) / 2.0;
}

const char* verSituacao(float media) {
    if (media >= 7.0) {
        return "APROVADO";
    } else {
        return "REPROVADO";
    }
}

int main() {
    DadosAluno X;
    FILE *EntradaDeDados, *SaidaDeDados;

    EntradaDeDados = fopen("DadosEntrada.csv", "r");
    if (EntradaDeDados == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    SaidaDeDados = fopen("SituacaoFinal.csv", "w");
    if (SaidaDeDados == NULL) {
        printf("Erro ao criar o arquivo de saída.\n");
        fclose(EntradaDeDados);
        return 1;
    }

    while (fscanf(EntradaDeDados, "%s %f %s %f %f\n", X.nome, &X.telefone, X.curso, &X.nota1, &X.nota2) != EOF) {
        float media = calculaMedia(X.nota1, X.nota2);
        const char* situacao = verSituacao(media);

        fprintf(SaidaDeDados, "%s, %.2f, %s\n", X.nome, media, situacao);
    }

    fclose(EntradaDeDados);
    fclose(SaidaDeDados);

    printf("Arquivo SituacaoFinal.csv gerado com sucesso.\n");

    return 0;
}
