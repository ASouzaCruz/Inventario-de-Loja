#include "Inventario.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

// ---------- PERSISTÊNCIA ----------
void Inventario::salvarEmArquivo() {
    ofstream arq("produtos.txt");
    for (const auto& p : produtos) {
        arq << p.nome << ";" << p.categoria << ";" << p.preco << ";" << p.estoque << "\n";
    }
    arq.close();

    ofstream hist("historico.txt");
    for (const auto& h : historicoVendas) {
        hist << h << "\n";
    }
    hist.close();
}

void Inventario::carregarDeArquivo() {
    ifstream arq("produtos.txt");
    string linha;
    while (getline(arq, linha)) {
        if (linha.empty()) continue;
        stringstream ss(linha);
        string nome, categoria, precoStr, estoqueStr;
        getline(ss, nome, ';');
        getline(ss, categoria, ';');
        getline(ss, precoStr, ';');
        getline(ss, estoqueStr, ';');

        if (nome.empty() || categoria.empty() || precoStr.empty() || estoqueStr.empty()) {
            cerr << "Linha inválida ignorada: " << linha << endl;
            continue;
        }

        try {
            double preco = stod(precoStr);
            int estoque = stoi(estoqueStr);
            adicionarProduto(Produto(nome, categoria, preco, estoque), false);
        } catch (...) {
            cerr << "Erro ao converter dados: " << linha << endl;
        }
    }
    arq.close();

    ifstream hist("historico.txt");
    string venda;
    while (getline(hist, venda)) {
        if (!venda.empty())
            historicoVendas.push_back(venda);
    }
    hist.close();
}

// ---------- FUNÇÕES PRINCIPAIS ----------
void Inventario::adicionarProduto(const Produto& p, bool mostrarMsg) {
    produtos.push_back(p);
    categorias.insert(p.categoria);
    contagemPorCategoria[p.categoria]++;
    valorTotalPorCategoria[p.categoria] += p.preco * p.estoque;
    if (mostrarMsg)
        cout << "Produto \"" << p.nome << "\" adicionado com sucesso.\n";
}

Produto* Inventario::buscarProduto(const string& nome) {
    for (auto& p : produtos)
        if (p.nome == nome)
            return &p;
    return nullptr;
}

void Inventario::listarPorCategoria(const string& categoria) {
    cout << "\n--- Produtos da categoria " << categoria << " ---\n";
    bool achou = false;
    for (const auto& p : produtos) {
        if (p.categoria == categoria) {
            cout << "- " << p.nome << " | R$" << p.preco << " | Estoque: " << p.estoque << "\n";
            achou = true;
        }
    }
    if (!achou)
        cout << "Nenhum produto encontrado nessa categoria.\n";
}

void Inventario::listarCategorias() {
    cout << "\nCategorias disponíveis:\n";
    for (const auto& c : categorias)
        cout << "- " << c << "\n";
}

double Inventario::calcularValorTotal() {
    double total = 0.0;
    for (const auto& [categoria, valor] : valorTotalPorCategoria)
        total += valor;
    return total;
}

void Inventario::registrarVenda(const string& nome, int quantidade) {
    Produto* p = buscarProduto(nome);
    if (p && p->estoque >= quantidade) {
        p->estoque -= quantidade;
        valorTotalPorCategoria[p->categoria] -= p->preco * quantidade;
        historicoVendas.push_back(nome + " x" + to_string(quantidade));
        cout << "Venda registrada: " << nome << " (" << quantidade << " un)\n";
    } else {
        cout << "Erro: estoque insuficiente ou produto inexistente.\n";
    }
}

void Inventario::mostrarHistorico() {
    cout << "\nHistorico de vendas:\n";
    if (historicoVendas.empty()) {
        cout << "Nenhuma venda registrada ainda.\n";
        return;
    }
    for (const auto& h : historicoVendas)
        cout << "- " << h << "\n";
}

void Inventario::listarTodosProdutos() {
    cout << "\n--- Todos os produtos ---\n";
    if (produtos.empty()) {
        cout << "Nenhum produto cadastrado.\n";
        return;
    }
    for (const auto& p : produtos)
        cout << "- " << p.nome << " (" << p.categoria << ") R$" << p.preco
             << " | Estoque: " << p.estoque << "\n";
}
