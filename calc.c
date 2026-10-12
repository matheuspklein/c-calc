#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int opcao = 0;
    char continuar;
    double num1, num2, resultado;
    char buffer[100];
    do{
        printf("==============================\n");
        printf("      Calculadora Simples     \n");
        printf("==============================\n");
        printf("Selecione uma operação:\n");
        printf("1. Adição\n");
        printf("2. Subtração\n");
        printf("3. Multiplicação\n");
        printf("4. Divisão\n");
        printf("5. Sair\n");
        printf("Opção: ");
        if(fgets(buffer, sizeof(buffer), stdin) == NULL){
            continue;
        }
        buffer[strcspn(buffer, "\n")] = 0;
        if(strlen(buffer) == 0){
            printf("Erro: Entrada inválida. Por favor, insira um número inteiro entre 1 e 5.\n\n");
            continue;
        }
        char *endptr;
        long val = strtol(buffer, &endptr, 10);
        char *p = endptr;
        while (*p == ' ' || *p == '\t') p++;
        if(endptr == buffer || *p != '\0'){
            printf("Erro: Entrada inválida. Por favor, insira um número inteiro entre 1 e 5.\n\n");
            continue;
        }
        opcao = (int)val;
        if(opcao == 5){
            printf("Obrigado por usar a calculadora! Até a próxima.\n");
            break;
        }
        if(opcao < 1 || opcao > 5){
            printf("Erro: Opção inválida. Por favor, insira um número entre 1 e 5.\n\n");
            continue;
        }
        int num_valido = 0;
        while(!num_valido){
            printf("Digite o primeiro número: ");
            if(fgets(buffer, sizeof(buffer), stdin) == NULL) continue;
            buffer[strcspn(buffer, "\n")] = 0;
            if(strlen(buffer) == 0) continue;
            double dval = strtod(buffer, &endptr);
            p = endptr;
            while(*p == ' ' || *p == '\t') p++;
            if(endptr == buffer || *p != '\0'){
                printf("Erro: Entrada inválida. Insira um número válido.\n");
                continue;
            }
            num1 = dval;
            num_valido = 1;
        }
        num_valido = 0;
        while(!num_valido){
            printf("Digite o segundo número: ");
            if (fgets(buffer, sizeof(buffer), stdin) == NULL) continue;
            buffer[strcspn(buffer, "\n")] = 0;
            if (strlen(buffer) == 0) continue;
            double dval = strtod(buffer, &endptr);
            p = endptr;
            while (*p == ' ' || *p == '\t') p++;
            if(endptr == buffer || *p != '\0'){
                printf("Erro: Entrada inválida. Insira um número válido.\n");
                continue;
            }
            num2 = dval;
            num_valido = 1;
        }
        switch(opcao){
            case 1:
                resultado = num1 + num2;
                printf("Resultado: %.2lf + %.2lf = %.2lf\n", num1, num2, resultado);
                break;
            case 2:
                resultado = num1 - num2;
                printf("Resultado: %.2lf - %.2lf = %.2lf\n", num1, num2, resultado);
                break;
            case 3:
                resultado = num1 * num2;
                printf("Resultado: %.2lf * %.2lf = %.2lf\n", num1, num2, resultado);
                break;
            case 4:
                if(num2 == 0){
                    printf("Erro: Divisão por zero não é permitida.\n");
                } else {
                    resultado = num1 / num2;
                    printf("Resultado: %.2lf / %.2lf = %.2lf\n", num1, num2, resultado);
                }
                break;
        }
        do{
            printf("Deseja realizar outra operação? (s/n): ");
            if(fgets(buffer, sizeof(buffer), stdin) == NULL) continue;
            buffer[strcspn(buffer, "\n")] = 0;
            if(strlen(buffer) != 1){
                printf("Resposta inválida. Por favor, digite 's' para sim ou 'n' para não.\n");
                continue;
            }
            continuar = buffer[0];
            if(continuar == 's' || continuar == 'S'){
                printf("\n");
                break;
            } else if(continuar == 'n' || continuar == 'N'){
                printf("Obrigado por usar a calculadora! Até a próxima.\n");
                opcao = 5;
                break;
            } else {
                printf("Resposta inválida. Por favor, digite 's' para sim ou 'n' para não.\n");
            }
        } while(1);
    } while(opcao != 5);
    return 0;
}
