#include <stdio.h>

int tamanho(char string[10001])
{
    int i = 0;
    int cont = 0;
    while (string[i] != '\0')
    {
        cont++;
        i++;
    }
    return cont;
}

void inverter_1 (char mensagem[], char nova_msg[], int tam)
{
    int i, j;

    for (i=0, j=tam-1; i<tam; i++, j--) nova_msg[i] = mensagem[j];

    nova_msg[tam] = '\0';
}

void desloca_2(char *s, int n, int tamanho) 
{
    int i;
    int nLetras = n % 26;
    int nNumeros = n % 10;
    
    if (nLetras < 0) nLetras += 26;
    if (nNumeros < 0) nNumeros += 10;
    
    for (i = 0; i < tamanho; i++) {
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] = 'a' + (s[i] - 'a' + nLetras) % 26;
        else if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = 'A' + (s[i] - 'A' + nLetras) % 26;
        else if (s[i] >= '0' && s[i] <= '9')
            s[i] = '0' + (s[i] - '0' + nNumeros) % 10;
    }
}

void trocarParesImpares_3(char *A, int tamanho) 
{
    int i;
    char I;

    for (i = 0; i < tamanho; i += 2) {
        if (tamanho%2 != 0) {
            if (i == (tamanho - 1)) {
                A[i];
            }
            else {
                I = A[i];
                A[i] = A[i + 1];
                A[i + 1] = I;
            }
        }
        else {
            I = A[i];
            A[i] = A[i + 1];
            A[i + 1] = I;
        }
    }
}

void inverterCaixa_4(char *s, int tam)
{
    int i;

    for (i=0; i< tam; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
        else if (s[i] >= 'a' && s[i] <= 'z') s[i] -= 32;
    }
}

void rotacionar_5(char *s, int n, int tam)
{
    int i;
    int nova_posicao;
    char nova[10001];

    n = n % tam;

    if (n < 0) {
        n = n + tam;
    }

    for (i=0; i<tam; i++)
    {
        nova[i] = s[(i - n + tam)%tam];
    }
    for (i=0; i<tam; i++)
    {
        s[i] = nova[i];
    }
    s[tam] = '\0';
    
}

void trocarMetades(char *s, int tamanho) {
    int i;
    char temporaria;
    
    if (tamanho%2 == 0) {
        for (i = 0; i < tamanho/2; i++) {
            temporaria = s[i];
            s[i] = s[i + (tamanho/2)];
            s[i + (tamanho/2)] = temporaria;
        }
    }
    else {
        for (i = 0; i < tamanho/2; i++) {
            temporaria = s[i];
            s[i] = s[i + ((tamanho/2) + 1)];
            s[i + ((tamanho/2) + 1)] = temporaria;
        }
    }
}

int main()
{
    int tam;
    int n, n2, n5, i;
    char mensagem[10001];
    char resultado[10001];

    scanf("%[^\n]%*c", mensagem);
    tam = tamanho(mensagem);

    while(scanf("%d", &n) == 1 && n >= 1 && n <= 6) {
        
        if (n == 1) {
            inverter_1(mensagem, resultado, tam);
            for (i = 0; i <= tam; i++) mensagem[i] = resultado[i];
        }
        else if (n == 2) {
            scanf("%d", &n2);
            desloca_2(mensagem, n2, tam);
        }
        else if (n == 3) {
            trocarParesImpares_3(mensagem, tam);
        }
        else if (n == 4) {
            inverterCaixa_4(mensagem, tam);
        }
        else if (n == 5) {
            scanf("%d", &n5);
            rotacionar_5(mensagem, n5, tam);
        }
        else if (n == 6) {
            trocarMetades(mensagem, tam);
        }
        
    }

    printf("%s\n", mensagem);

    return 0;
}