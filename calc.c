int main(){
    int opcao;
    char continuar;
    double num1, num2, resultado;
    do {
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
        if(scanf("%d", &opcao) != 1){
            printf("Erro: Entrada inválida. Por favor, insira um número entre 1 e 5.\n\n");
            while (getchar() != '\n');
            continue;
        }
        if(opcao == 5){
            printf("Obrigado por usar a calculadora! Até a próxima.\n");
            break;
        }
        if(opcao < 1 || opcao > 5){
            printf("Erro: Opção inválida. Por favor, insira um número entre 1 e 5.\n\n");
            continue;
        }
        printf("Digite o primeiro número: ");
        scanf("%lf", &num1);
        printf("Digite o segundo número: ");
        scanf("%lf", &num2);
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
        do {
            printf("Deseja realizar outra operação? (s/n): ");
            scanf(" %c", &continuar);
            if (continuar == 's' || continuar == 'S'){
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
