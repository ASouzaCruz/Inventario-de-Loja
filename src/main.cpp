#include <iostream>
#include "Inventario.h"
using namespace std;

int main() {
    Inventario loja;
    loja.carregarDeArquivo();   // Carrega produtos e histórico salvos anteriormente

    int opcao;
    do {
        // Menu principal
        cout << "\n======= SISTEMA DE INVENTÁRIO =======\n";
        cout << "1 - Adicionar produto\n";
        cout << "2 - Buscar produto por nome\n";
        cout << "3 - Listar produtos de uma categoria\n";
        cout << "4 - Listar todas as categorias\n";
        cout << "5 - Registrar venda\n";
        cout << "6 - Mostrar histórico de vendas\n";
        cout << "7 - Mostrar valor total do inventário\n";
        cout << "8 - Listar todos os produtos\n";
        cout << "0 - Salvar e sair\n";
        cout << "Escolha: ";
        cin >> opcao;
        cin.ignore();

        // Adicionar produto
        if (opcao == 1) {
            string nome, categoria;
            double preco;
            int estoque;

            cout << "Nome do produto: ";
            getline(cin, nome);

            cout << "Categoria: ";
            getline(cin, categoria);

            cout << "Preço: ";
            cin >> preco;

            cout << "Estoque: ";
            cin >> estoque;

            loja.adicionarProduto(Produto(nome, categoria, preco, estoque));
        }

        // Buscar produto
        else if (opcao == 2) {
            string nome;
            cout << "Nome do produto a buscar: ";
            getline(cin, nome);

            Produto* p = loja.buscarProduto(nome);
            if (p)
                cout << "Encontrado: " << p->nome << " | R$" << p->preco
                     << " | Estoque: " << p->estoque << "\n";
            else
                cout << "Produto não encontrado.\n";
        }

        // Listar produtos por categoria
        else if (opcao == 3) {
            string categoria;
            cout << "Digite o nome da categoria: ";
            getline(cin, categoria);

            loja.listarPorCategoria(categoria);
        }

        // Listar todas as categorias
        else if (opcao == 4) {
            loja.listarCategorias();
        }

        // Registrar venda
        else if (opcao == 5) {
            string nome;
            int qtd;

            cout << "Produto vendido: ";
            getline(cin, nome);

            cout << "Quantidade: ";
            cin >> qtd;

            loja.registrarVenda(nome, qtd);
        }

        // Mostrar histórico de vendas
        else if (opcao == 6) {
            loja.mostrarHistorico();
        }

        // Mostrar valor total do inventário
        else if (opcao == 7) {
            cout << "\nValor total do inventário: R$" 
                 << loja.calcularValorTotal() << "\n";
        }

        // Listar todos os produtos cadastrados
        else if (opcao == 8) {
            loja.listarTodosProdutos();
        }

        // Salvar e sair
        else if (opcao == 0) {
            loja.salvarEmArquivo();
            cout << "Dados salvos. Encerrando...\n";
        }

        // Entrada inválida
        else {
            cout << "Opção inválida.\n";
        }

    } while (opcao != 0);
}
