#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>
using namespace std;

class Produto {
public:
    string nome;
    string categoria;
    double preco;
    int estoque;

    Produto(string n = "", string c = "", double p = 0, int e = 0)
        : nome(n), categoria(c), preco(p), estoque(e) {}
};

#endif
