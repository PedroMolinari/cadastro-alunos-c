# Cadastro de Alunos em C

Aplicação desenvolvida em linguagem C com o objetivo de implementar um sistema simples de gerenciamento de alunos via terminal.

## Descrição Técnica

O programa utiliza estruturas de dados (`struct`) para representar entidades do tipo Aluno, armazenando atributos como nome, idade e nota.  
Os registros são mantidos em um vetor estático com capacidade para até 50 alunos.

A aplicação é controlada por um menu interativo implementado com `switch-case`, permitindo a execução de diferentes operações conforme a escolha do usuário.

## Funcionalidades

- Cadastro de novos alunos
- Armazenamento em array de structs
- Listagem completa dos registros cadastrados
- Cálculo da média aritmética das notas
- Controle de fluxo por laço `do-while`

## Conceitos Aplicados

- Estruturas (`struct`)
- Vetores
- Manipulação de strings
- Controle de fluxo (`switch`, `if`, `for`, `do-while`)
- Entrada e saída padrão (`scanf`, `printf`)
- Operações matemáticas básicas

## Compilação e Execução

```bash
gcc cadastro_aluno.c -o cadastro
./cadastro

## Autor
Pedro Molinari
