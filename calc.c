#include <stdio.h>
#include <stdlib.h>

void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
} 

float add(float a, float b) {
    return a + b;
}

float subt(float a, float b) {
    return a - b;
}

float mult(float a, float b) {
    return a * b;
}

float divi(float a, float b) {
    return a / b;
}

int outraop(int op) {
    char oop;
    while(1){
        printf("Deseja realizar outra operação? (s/n): ");
        scanf(" %c", &oop);
        if (oop == 'n' || oop == 'N') {
            return 5;
        } else if (oop == 's' || oop == 'S') {
            limparTela();
            return op;
        } else {
            printf("Opção inválida! Por favor, responda apenas com 's' ou 'n'.\n");
        }
    }
}

int main() {
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
        if (scanf("%d", &op) != 1) {
            printf("Erro: Entrada inválida. Por favor, insira um número entre 1 e 5.\n");
            while (getchar() != '\n');
            continue;
        }
        if (op == 5) {
            printf("Obrigado por usar a calculadora! Até a próxima.\n");
            break;
        }
        if (op >= 1 && op <= 4) {
            printf("Digite o primeiro número: ");
            while (scanf("%f", &a) != 1) {
                printf("Entrada inválida. Digite um número decimal válido: ");
                while (getchar() != '\n');
            }
            printf("Digite o segundo número: ");
            while (scanf("%f", &b) != 1) {
                printf("Entrada inválida. Digite um número decimal válido: ");
                while (getchar() != '\n');
            }
        }
        if (op == 1) {
            float sum = add(a, b);
            printf("Resultado: %.2f + %.2f = %.2f\n", a, b, sum);
            op = outraop(op);
        } else if (op == 2) {
            float sub = subt(a, b);
            printf("Resultado: %.2f - %.2f = %.2f\n", a, b, sub);
            op = outraop(op);
        } else if (op == 3) {
            float mul = mult(a, b);
            printf("Resultado: %.2f * %.2f = %.2f\n", a, b, mul);
            op = outraop(op);
        } else if (op == 4) {
            if (b == 0) {
                printf("Erro: Divisão por zero não é permitida.\n");
                op = outraop(op);
            } else {
                float div = divi(a, b);
                printf("Resultado: %.2f / %.2f = %.2f\n", a, b, div);
                op = outraop(op);
            }
        } else {
            printf("Opção inválida!\n");
            op = outraop(op);
        }
        if (op == 5) {
            printf("Obrigado por usar a calculadora! Até a próxima.\n");
        }
    } while (op != 5);
    return 0;
}
