#include <stdio.h>


#define MAX_LIVROS 100
#define MAX_USUARIOS 100
#define MAX_NOME 50

typedef struct {
    int id;
    char titulo[MAX_NOME];
    char autor[MAX_NOME];
    int ano;
    int disponivel; //1 para disponivel, 0 para emprestado
} Livro;

typedef struct {
    int id;
    char nome[MAX_NOME];
    char email[MAX_NOME];
} Usuario;

typedef struct {
    int usuario_id;
    int livro_id;
} Emprestimo;

Livro biblioteca[MAX_LIVROS];
Usuario usuarios[MAX_USUARIOS];
Emprestimo emprestimos[MAX_LIVROS]; // definir limite para emprestimos (aprox 100)
int total_livros = 0;
int total_usuarios = 0;
int total_emprestimos = 0;

// funcoes

void adicionar_livros() {
    if (total_livros < MAX_LIVROS) {
        Livro livro;
        livro.id = total_livros + 1;
        printf("Título: ");
        scanf(" %[^\n]s", livro.titulo);
        printf("Autor: ");
        scanf(" %[^\n]s", livro.autor);
        printf("Ano: ");
        scanf("%d", &livro.ano);
        livro.disponivel = 1;

        biblioteca[total_livros++] = livro;
        printf("Livro adicionado com sucesso!\n");
    } else {
        printf("Limite de livros atingidos!\n");
    }
}

void listar_livros() {
    printf("Lista de livros:\n");
    for (int i = 0; i < total_livros; i++) {
        printf("ID: %d | Título: %s | Autor: %s | Ano: %d | Disponível: %s\n",
                biblioteca[i].id, biblioteca[i].titulo, biblioteca[i].autor,
                biblioteca[i].ano, biblioteca[i].disponivel ? "Sim" : "Não");
    }
}


void adicionar_usuario() {
    if (total_usuarios < MAX_USUARIOS) {
        Usuario usuario;
        usuario.id = total_usuarios + 1;
        printf("Nome: ");
        scanf(" %[^\n]s", usuario.nome);
        printf("Email: ");
        scanf(" %[^\n]s", usuario.email);

        usuarios[total_usuarios++] = usuario;
        printf("Usuário adicionado com sucesso!\n");
    } else {
        printf("Limite de usuarios atingidos!\n");
    }
}

void listar_usuarios() {
    printf("Lista de Usuarios:\n");
    for (int i = 0; i < total_usuarios; i++) {
        printf("ID: %d | Nome: %s | Email: %s\n",
                usuarios[i].id, usuarios[i].nome, usuarios[i].email);
    }
}

void menu() {
    int opcao;
    do {
        printf("\n=== Sistema de Biblioteca ===\n");
        printf("1. Adicionar Livro\n");
        printf("2. Listar livros\n");
        printf("3. Adicionar Usuarios\n");
        printf("4. Listar Usuarios\n");
        printf("5. Sair\n");
        printf("Escolha opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                adicionar_livros();
                break;
            
            case 2:
                listar_livros();
                break;

            case 3: 
                adicionar_usuario();
                break;

            case 4:
                listar_usuarios();
                break;

            case 5:
                printf("Saindo...");
                break;

            default:
                printf("Opcao inválida! Tente novamente. \n");
        }
    } while (opcao != 5);
}

int main() {
    menu();
    return 0;
}