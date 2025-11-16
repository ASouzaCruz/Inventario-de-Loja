Sistema simples de inventário desenvolvido em C++ com modularização, classes e Makefile.

Sobre o projeto

Este projeto implementa um sistema de inventário para uma loja, permitindo cadastrar produtos, consultar categorias, registrar vendas e salvar/ler dados em arquivo.
O código foi modularizado usando pastas src/ e include/ e o build é feito via Makefile.


Funcionalidades

Adicionar produtos ao inventário

Buscar produto pelo nome

Listar produtos por categoria

Listar todas as categorias

Registrar vendas

Exibir histórico de vendas

Mostrar valor total do inventário

Salvar dados em arquivo

Carregar dados automaticamente ao iniciar
Como compilar

No PowerShell:
make

Como executar
make run
Ou diretamente:

./build/inventario.exe

Dependências

Compilador C++ (g++, MinGW ou similar)

Pontos Positivos do Projeto

Código modular organizado em headers e cpp

Makefile funcional com criação automática da pasta build

Suporte a persistência de dados via arquivo

Uso de classes que deixa o código mais limpo

Sistema de vendas com histórico

Compilação simples com apenas um comando

Pontos Negativos / Melhorias Futuras

Sem tratamento avançado de erros (entradas inválidas, arquivo corrompido, etc)

Interface somente via terminal, pode ser melhorada para 

Persistência simples, ideal evoluir  banco de dados

Faltam validações (estoque negativo, nomes repetidos, etc.)

Busca por nome não é flexível (exige nome exato)
