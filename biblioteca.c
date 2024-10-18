#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define USUARIO_CORRETO "admin123"
#define SENHA_CORRETA "senha321"
#define MAX_LIVROS 100
#define MAX_USUARIOS 100
#define MAX_NOME 50

char usuario[50];
char senha[50];

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



// FUNCOES
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




// LIMPAR TELA
void limpar_tela() {
    system("cls");
    system("clear");
}

// ABRIR MENU 
void menu_inicial() {
    int opcao;
    do {
        printf("\n=== Biblioteca ===\n");
        printf("1. Adicionar Livro\n");
        printf("2. Listar livros\n");
        printf("3. Adicionar Usuarios\n");
        printf("4. Listar Usuarios\n");
        printf("5. Sair\n");
        printf("Escolha opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                limpar_tela();
                adicionar_livros();
                break;
            
            case 2:
                limpar_tela();
                listar_livros();
                break;

            case 3:
                limpar_tela();
                adicionar_usuario();
                break;

            case 4:
                limpar_tela();
                listar_usuarios();
                break;

            case 5:
                limpar_tela();
                printf("Saindo...");
                break;

            default:
                printf("Opcao inválida! Tente novamente. \n");
        }
    } while (opcao != 5);
}


// VERIFICACAO DE LOGIN
int verificar_login(const char *usuario, const char *senha) {
    return strcmp(usuario, USUARIO_CORRETO) == 0 && strcmp(senha, SENHA_CORRETA) == 0;
}


int main() {

    printf("------------------------\n");
    printf("\n Login Biblioteca \n");
    printf("\n------------------------\n");
    printf("Login: ");
    scanf(" %s", &usuario);
    printf("Senha: ");
    scanf(" %s", &senha);

    if(verificar_login(usuario, senha)) {
        limpar_tela();
        menu_inicial();
    } else {
        printf("Usuário ou senha incorretos.\n");
    }


    return 0;
}