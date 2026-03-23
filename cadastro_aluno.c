#include <stdio.h>
#include <string.h>

    struct Aluno {
        char nome[50];
        int idade;
        float nota;
        };

int main()
{
    struct Aluno Cadastro[50];
    
    int totalAlunos = 0;
    
    int opção;
    
    float soma = 0;
    float media;
    
    int i;
    
    do {
        printf("Escolha uma opção\n");
        printf("1- Cadastrar novo aluno.\n");
        printf("2- Listar os alunos.\n");
        printf("3- Calcular media dos alunos.\n");
        printf("4- Sair.\n");
        scanf("%d", &opção);
        
        switch(opção){
            case 1:
            printf("Cadastrar aluno\n");
            if(totalAlunos < 50) {
                printf("Nome do aluno:\n");
                scanf("%s", Cadastro[totalAlunos].nome);
                printf("Idade do aluno:\n");
                scanf("%d", &Cadastro[totalAlunos].idade);
                printf("Nota do aluno:\n");
                scanf("%f", &Cadastro[totalAlunos].nota);
                totalAlunos++;
                printf("Pressione Enter para voltar ao menu...");
                fflush(stdin);
                getchar();
                getchar();
            }
            break;
            case 2:
            printf("Listar alunos\n");
            if(totalAlunos == 0){
                printf("Nenhum aluno foi cadastrado!\n");
            } else {
                for(i = 0; i < totalAlunos; i++){
                    printf("Nome: %s,\n Idade: %d,\n nota: %.1f \n", Cadastro[i].nome, Cadastro[i].idade, Cadastro[i].nota);
                }
                printf("Pressione Enter para voltar ao menu...");
                fflush(stdin);
                getchar();
                getchar();
            }
            break;
            case 3:
            printf("Calcular média dos alunos\n");
            if(totalAlunos == 0){
                printf("nenhum aluno cadastrado!\n");
            } else {
                for(i = 0; i < totalAlunos; i++){
                    soma = soma + Cadastro[i].nota;
                } 
                media = soma / totalAlunos;
                    printf("Media: %.2f\n", media);
                printf("Pressione Enter para voltar ao menu...");
                fflush(stdin);
                getchar();
                getchar();
            }
            break;
            case 4:
            printf("Sair");
            break;
            default:
            printf("Opção invalida!");
        } 
    } while(opção != 4);
    

    return 0;
}
