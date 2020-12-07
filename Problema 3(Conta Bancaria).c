#include <stdio.h>
#include <stdlib.h>
 
struct Cliente
{
    char nome[256];
    int cpf;
};
 
struct Conta 
{
    int numero_conta;
    struct Cliente cliente;
    float saldo;
};
 
void menu(struct Conta cadastro);
void saldo(struct Conta cadastro);
void saque(struct Conta *cadastro, float valor);
void deposito(struct Conta *cadastro, float valor);
 
int main()
{
    struct Conta cadastro;
    printf("Digite seu primeiro nome: ");
    scanf("%s", &cadastro.cliente.nome);
    printf("Digite seu CPF: ");
    scanf("%d", &cadastro.cliente.cpf);
    printf("Digite o numero da sua conta: ");
    scanf("%d", &cadastro.numero_conta);
    printf("Digite seu saldo: ");
    scanf("%f", &cadastro.saldo);
    menu(cadastro);
}
 
void menu (struct Conta cadastro)
{
    int escolha = 0;
    float valor;
    printf("Digite 1 para saldo\n");
    printf("Digite 2 para saque\n");
    printf("Digite 3 para deposito\n");
    printf("Digite 4 para sair\n");
    scanf("%d", &escolha);
 
    switch(escolha)
    {
        case 1: 
            saldo(cadastro);
            break;
        case 2:
            printf("Digite o valor do saque: ");
            scanf("%f", &valor);
            saque(&cadastro, valor);
            break;
        case 3:
            printf("Digite o valor do deposito: ");
            scanf("%f", &valor);
            deposito(&cadastro, valor);
            break;
        
        case 4: 
            exit(1);

        default:
            printf("Escolha não valida");
            menu(cadastro);
        break;
    }
 
}
 
void saldo(struct Conta cadastro)
{
    printf("Seu saldo e de: %.2f\n", cadastro.saldo);
    menu(cadastro);
}
 
void saque(struct Conta *cadastro, float valor)
{
    if(valor <= cadastro->saldo)
    {
        cadastro->saldo -= valor;
        printf("Seu saque foi realizado com sucesso\n");
        saldo(*cadastro);
    }
}
 
void deposito(struct Conta *cadastro, float valor)
{
    if(valor > 0)
    {
        cadastro-> saldo += valor;
        printf("Seu deposito foi realizado com sucesso\n");
        saldo(*cadastro);
    }
}