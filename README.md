# Cadastro de Alunos em C

Aplicação desenvolvida em linguagem C com o objetivo de implementar um sistema simples de gerenciamento de alunos via terminal.

## Descrição Técnica

O programa utiliza estruturas de dados (`struct`) para representar entidades do tipo Aluno, armazenando atributos como nome, idade e nota.  
Os registros são mantidos em um vetor estático com capacidade para até 50 alunos.

Permitindo a execução de diferentes operações conforme a escolha do usuário.

## Funcionalidades

- Cadastro de novos alunos
- Armazenamento em array de structs
- Listagem completa dos registros cadastrados
- Cálculo da média aritmética das notas

## Conceitos Aplicados

- Estruturas (`struct`)
- Vetores
- Manipulação de strings
- Operações matemáticas básicas

## Compilação e Execução

```bash
gcc cadastro_aluno.c -o cadastro
./cadastro

## Autor
Pedro Molinari
