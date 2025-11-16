#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <vector>
#include <set>
#include <map>
#include <list>
#include <string>
#include "Produto.h"
using namespace std;

class Inventario {
private:
    vector<Produto> produtos;
    set<string> categorias;
    map<string, int> contagemPorCategoria;
    map<string, double> valorTotalPorCategoria;
    list<string> historicoVendas;

public:
    void salvarEmArquivo();
    void carregarDeArquivo();
    void adicionarProduto(const Produto& p, bool mostrarMsg = true);
    Produto* buscarProduto(const string& nome);
    void listarPorCategoria(const string& categoria);
    void listarCategorias();
    double calcularValorTotal();
    void registrarVenda(const string& nome, int quantidade);
    void mostrarHistorico();
    void listarTodosProdutos();
};

#endif