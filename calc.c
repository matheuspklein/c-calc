#include <stdio.h>
#include <stdlib.h>

void limparTela(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
} 

float add(float a, float b){
    return a + b;
}

float subt(float a, float b){
    return a - b;
}

float mult(float a, float b){
    return a * b;
}

float divi(float a, float b){
    return a / b;
}

int lerOpcao(){
    int op;
    char ch;
    if(scanf("%d", &op) != 1){
        while ((ch = getchar()) != '\n' && ch != EOF);
        return -1;
    }
    ch = getchar();
    if(ch != '\n'){
        while (ch != '\n' && ch != EOF){
            ch = getchar();
        }
    }
    return op;
}

float lerNumero(const char* mensagem){
    float num;
    char ch;
    while (1) {
        printf("%s", mensagem);
        if(scanf("%f", &num) == 1){
            ch = getchar();
            if(ch == '\n'){
                return num;
            }
            while(ch != '\n' && ch != EOF){
                ch = getchar();
            }
        } else {
            while((ch = getchar()) != '\n' && ch != EOF);
        }
        printf("Entrada inválida. Digite um número decimal válido: ");
    }
}

int outraop(){
    char oop;
    char ch;
    while (1){
        printf("Deseja realizar outra operação? (s/n): ");
        if (scanf(" %c", &oop) == 1){
            while((ch = getchar()) != '\n' && ch != EOF);
            if(oop == 'n' || oop == 'N'){
                printf("Obrigado por usar a calculadora! Até a próxima.\n");
                return 0;
            } else if (oop == 's' || oop == 'S'){
                limparTela();
                return 1;
            }
        } else {
            while((ch = getchar()) != '\n' && ch != EOF);
        }
        printf("Opção inválida! Por favor, responda apenas com 's' ou 'n'.\n");
    }
}

int main(){
    int op;
    float a, b;
    do {
        printf("===============================\n");
        printf("       Calculadora Simples     \n");
        printf("===============================\n");
        printf("Selecione uma operação:\n");
        printf("1. Adição\n");
        printf("2. Subtração\n");
        printf("3. Multiplicação\n");
        printf("4. Divisão\n");
        printf("5. Sair\n");
        printf("Opção: ");
        op = lerOpcao();
        if(op == 5){
            printf("Obrigado por usar a calculadora! Até a próxima.\n");
            break;
        }
        if(op < 1 || op > 5){
            printf("Opção inválida! Por favor, escolha um número entre 1 e 5.\n\n");
            continue;
        }
        a = lerNumero("Digite o primeiro número: ");
        b = lerNumero("Digite o segundo número: ");
        if(op == 1){
            float sum = add(a, b);
            printf("Resultado: %.2f + %.2f = %.2f\n", a, b, sum);
            if(outraop() == 0) break;
        } else if(op == 2){
            float sub = subt(a, b);
            printf("Resultado: %.2f - %.2f = %.2f\n", a, b, sub);
            if(outraop() == 0) break;
        } else if(op == 3){
            float mul = mult(a, b);
            printf("Resultado: %.2f * %.2f = %.2f\n", a, b, mul);
            if(outraop() == 0) break;
        } else if(op == 4){
            if(b == 0){
                printf("Erro: Divisão por zero não é permitida.\n");
                if(outraop() == 0) break;
            } else {
                float div = divi(a, b);
                printf("Resultado: %.2f / %.2f = %.2f\n", a, b, div);
                if (outraop() == 0) break;
            }
        }
    } while (1);
    return 0;
}
