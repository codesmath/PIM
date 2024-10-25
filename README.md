# PIM
Projeto integrado multidisciplinar realizado no segundo semestre da universidade paulista de Análise e Desenvolvimento de Sistemas.



# Desenvolvedores
Victor Teixeira Mendes & Matheus Oliveira

# Documentação do Sofware

## Propósito:

O software desenvolvido no Projeto Integrado Multidisciplinar (PIM) tem como objetivo ser um software funcional para um sistema de biblioteca, no qual existem funções como adicionar livros / usuários, listar livros / usuários, realizar gerenciamento de empréstimos como devolver livro, contabilizar empréstimo e listar os empréstimos realizados. 

## Documentação do projeto:

Foi desenvolvido para ser um software simples, prático e intuitivo, para facilitar o gerenciamento dos processos do bibliotecário com um menu elegante e intuitivo.

Para a instalação do software é disponibilizado um arquivo com extensão “.exe” para fazer o download na máquina. Clicando duas vezes em cima do arquivo irá executa-lo.

## Sobre o Código:

Como falado a cima, foram utilizadas 3 bibliotecas para o desenvolvimento.

A biblioteca "stdio.h” exibe e recebe dados dos usuários através das funções "printf” (Exibindo algo na tela para o usuário) e "scanf” (Solicitando que o usuário digite algo e armazenando esse dado em uma variável), além disso, realiza operações de formatação e conversão de dados para melhor entrada e saída de informação.

"string.h” foi utilizada para fazer comparações de strings, conseguindo realizar funções de Token para verificação de login e senha do software (Login e senha já definidos pelo usuário).

"stdlib.h” para manipulação de processos, sendo as funções "system("cls”);” e "system("clear”);” realizando a limpeza da tela do software a cada chamada de função.

Para definição de login, senha, máximo de livros, máximo de usuários e etc… foi utilizado "#define” definindo os valores limitados para cada ação, a vantagem de usar essa diretiva é a facilidade de manutenção, pois se precisar fazer alguma alteração é só ir diretamente no "#define” e o seu valor será substituído em todas as estruturas do código, e tem um melhor desempenho por não ter uso de memória, já que não é criada uma variável e somente uma substituição.

Definindo as variáveis consideramos mais viável o uso da estrutura "struct”, podendo fazer o armazenamento de "subdados” de uma variável, como por exemplo a struct de "Usuario”, contendo ID, nome e email tudo dentro de "Usuario”. Para uma melhor legibilidade do código optamos por incluir "typedef struct”, assim não é preciso declarar "struct” toda vez que for chamar a estrutura, melhorando a legibilidade e simplificando a sintaxe do código, ao invés de "struct Usuario usuario;” podemos utilizar somente "Usuario usuario;”.

- Funções para Adicionar Livro e Adicionar Usuário

Foi utilizado "if e else” para tomada de decisão da função, sendo adicionar o livro somente se o total de livros (total_livros) ser menor (<) que o número máximo permitido na biblioteca (MAX_LIVROS), em adicionar usuários é a mesma função mas com total de usuários (total_usuarios) e máximo de usuários permitidos (MAX_USUARIOS). Para definir as ID's de cada livro ou usuário foi utilizado uma operação de ID = total + 1, começando em 0, e todo livro adicionado recebe o número 1 na categoria disponível (1 para disponível e 0 para emprestado).

- Funções para Listar Livros, Usuários e Empréstimos

Foi utilizado "for” como estrutura de controle de fluxo permitindo ele repetir o bloco de código várias vezes com base em uma condição, sendo ela, listar todos os livros ou usuários cadastrados, desde que seja menor que o total de livros. Para a listagem de empréstimos é utilizado a mesma estrutura "for”, porém listando o livro com sua respectiva ID e o usuário emprestado com sua respectiva ID.

- Função para realizar empréstimo

É solicitado a ID do livro e ID do usuário para realizar o empréstimo e é utilizado "if e else” para tomada de decisão da função, sendo realizar o empréstimo somente se o id do usuário e id do livro ser existente na memória do software e quando o empréstimo é bem sucedido, substitui o número 1 por 0 em disponível (no livro), definindo que não está disponível.

- Função para Devolver Livro

É solicitado a ID do livro a ser devolvido e a data que o livro foi devolvido para o usuário, se a id for correspondente a um livro que estava emprestado, o livro é devolvido com sucesso. Se o ID não for encontrado, aparece que o livro não foi encontrado ou que ele já está disponível.

- Função para Limpar a Tela

Função para chamar outras funções para limpar a tela do menu, utilizando system("cls”) para windows e system("clear”) para MacOs.

- Função de Menu Inicial

Contendo todo o menu do software  utilizando uma estrutura "do while” onde cada parte do menu faz uma chamada para outra função da seu respectivo caso

- Função para Verificar Login

Juntamente da biblioteca "string.h” foi utilizado a função para fazer a verificação e o login e senha definido esta correto com o que foi solicitado ao usuário, para fazer a comparação é utilizado a função "strcmp”

- Função Main (Principal)

Contém o menu básico de login e senha, com uma estrutura "if e else” onde se tiver correto o login e senha, ele chama a função para o menu inicial. Se estiver errado, ele não chama a função e aparece usuário ou senha incorretos.