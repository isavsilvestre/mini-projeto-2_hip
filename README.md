# mini-projeto-2_ip
#include <stdio.h>

int tamanho(char string[10001])
{
    int i = 0;
    int cont;
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
    int posicao_atual;
    int nova_posicao;
    
    for (i = 0; i < tamanho; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            posicao_atual = s[i] - 'a';
            nova_posicao = (posicao_atual + n) % 26;
            s[i] = nova_posicao + 'a'; 
        }
        else if (s[i] >= 'A' && s[i] <= 'Z') {
            posicao_atual = s[i] - 'A';
            nova_posicao = (posicao_atual + n) % 26;
            s[i] = nova_posicao + 'A'; 
        }
        else if (s[i] >= '0' && s[i] <= '9') {
            posicao_atual = s[i] - '0';
            nova_posicao = (posicao_atual + n) % 10;
            s[i] = nova_posicao + '0';
        }
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

void rotacionar(char *s, int n, int tam)
{
    int i;
    int nova_posicao;
    char nova[10001];

   for (i=0; i<tam; i++)
    {
        nova[i] = s[(n*2 + i)%tam];
    }
    for (i=0; i<tam; i++)
    {
        s[i] = nova[i];
    }
    s[tam] = '\0';
    
}

int main()
{
    int tam;
    int n, n2;
    char mensagem[10001];
    char resultado[10001];

    scanf("%[^\n]%*c", mensagem);
    scanf("%d", &n);
    // scanf("%d", &n2);

    tam = tamanho(mensagem);
    /* inverter_1(mensagem, resultado, tam);
    desloca_2(resultado, n, tam);
    trocarParesImpares_3(mensagem, tam);
    inverterCaixa_4(mensagem, tam);  */
    rotacionar(mensagem, n, tam);
    printf("%s\n", mensagem);

    return 0;
}
