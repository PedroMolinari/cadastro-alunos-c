#include <stdio.h>
#include <string.h>

#define MAX_LIVROS 100
#define MAX_USUARIOS 100
#define MAX_EMPRESTIMOS 100

// --------------------
// STRUCTS SIMPLES
// --------------------

typedef struct {
    int codigo;
    char titulo[50];
    char autor[50];
    int quantidade;
} Livro;

typedef struct {
    int matricula;
    char nome[50];
} Usuario;

typedef struct {
    int codigoLivro;
    int matriculaUsuario;
    int ativo; // 1 = emprestado | 0 = devolvido
} Emprestimo;

// --------------------
// VARIÁVEIS GLOBAIS
// --------------------

Livro livros[MAX_LIVROS];
Usuario usuarios[MAX_USUARIOS];
Emprestimo emprestimos[MAX_EMPRESTIMOS];

int totalLivros = 0;
int totalUsuarios = 0;
int totalEmprestimos = 0;

// --------------------
// CADASTRAR LIVRO
// --------------------

void cadastrarLivro() {
    printf("\n--- CADASTRAR LIVRO ---\n");

    printf("Codigo: ");
    scanf("%d", &livros[totalLivros].codigo);

    printf("Titulo: ");
    scanf(" %[^\n]", livros[totalLivros].titulo);

    printf("Autor: ");
    scanf(" %[^\n]", livros[totalLivros].autor);

    printf("Quantidade: ");
    scanf("%d", &livros[totalLivros].quantidade);

    totalLivros++;

    printf("Livro cadastrado com sucesso!\n");
}

// --------------------
// CADASTRAR USUARIO
// --------------------

void cadastrarUsuario() {
    printf("\n--- CADASTRAR USUARIO ---\n");

    printf("Matricula: ");
    scanf("%d", &usuarios[totalUsuarios].matricula);

    printf("Nome: ");
    scanf(" %[^\n]", usuarios[totalUsuarios].nome);

    totalUsuarios++;

    printf("Usuario cadastrado com sucesso!\n");
}

// --------------------
// LISTAR LIVROS
// --------------------

void listarLivros() {
    printf("\n--- LISTA DE LIVROS ---\n");

    for(int i = 0; i < totalLivros; i++) {
        printf("Codigo: %d\n", livros[i].codigo);
        printf("Titulo: %s\n", livros[i].titulo);
        printf("Autor: %s\n", livros[i].autor);
        printf("Quantidade: %d\n", livros[i].quantidade);
        printf("-----------------------\n");
    }
}

// --------------------
// REALIZAR EMPRESTIMO
// --------------------

void emprestarLivro() {
    int codigoLivro, matriculaUsuario;
    int encontrou = 0;

    printf("\n--- EMPRESTIMO ---\n");

    printf("Codigo do livro: ");
    scanf("%d", &codigoLivro);

    printf("Matricula do usuario: ");
    scanf("%d", &matriculaUsuario);

    for(int i = 0; i < totalLivros; i++) {
        if(livros[i].codigo == codigoLivro) {
            if(livros[i].quantidade > 0) {

                livros[i].quantidade--;

                emprestimos[totalEmprestimos].codigoLivro = codigoLivro;
                emprestimos[totalEmprestimos].matriculaUsuario = matriculaUsuario;
                emprestimos[totalEmprestimos].ativo = 1;

                totalEmprestimos++;

                printf("Emprestimo realizado!\n");
                encontrou = 1;
            } else {
                printf("Livro indisponivel!\n");
                encontrou = 1;
            }
        }
    }

    if(!encontrou) {
        printf("Livro nao encontrado!\n");
    }
}

// --------------------
// DEVOLVER LIVRO
// --------------------

void devolverLivro() {
    int codigoLivro;

    printf("\n--- DEVOLUCAO ---\n");

    printf("Codigo do livro: ");
    scanf("%d", &codigoLivro);

    for(int i = 0; i < totalEmprestimos; i++) {
        if(emprestimos[i].codigoLivro == codigoLivro && emprestimos[i].ativo == 1) {

            emprestimos[i].ativo = 0;

            for(int j = 0; j < totalLivros; j++) {
                if(livros[j].codigo == codigoLivro) {
                    livros[j].quantidade++;
                }
            }

            printf("Livro devolvido!\n");
            return;
        }
    }

    printf("Emprestimo nao encontrado!\n");
}

// --------------------
// MENU
// --------------------

int main() {

    int opcao;

    do {
        printf("\n===== SISTEMA BIBLIOTECA =====\n");
        printf("1 - Cadastrar Livro\n");
        printf("2 - Cadastrar Usuario\n");
        printf("3 - Listar Livros\n");
        printf("4 - Emprestar Livro\n");
        printf("5 - Devolver Livro\n");
        printf("0 - Sair\n");

        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: cadastrarLivro(); break;
            case 2: cadastrarUsuario(); break;
            case 3: listarLivros(); break;
            case 4: emprestarLivro(); break;
            case 5: devolverLivro(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opcao invalida!\n");
        }

    } while(opcao != 0);

    return 0;
}
