#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
using namespace std;

struct Prato{
    int prioridade;
    int tempo;
    string nome;
};

bool auxiliar(const Prato& prato1, const Prato& prato2){
    bool prato1bubble = (prato1.nome.find("bubble") < prato1.nome.size());
    bool prato2bubble = (prato2.nome.find("bubble") < prato2.nome.size());

    if (prato1bubble && !prato2bubble)
    return true;
    if (prato2bubble && !prato1bubble)
    return false;
    if (prato1.prioridade != prato2.prioridade)
        return prato1.prioridade > prato2.prioridade;
    return prato1.tempo < prato2.tempo;
}

void trocar_pratos(Prato& prato1, Prato& prato2){
    Prato temporario = prato1;
    prato1 = prato2;
    prato2 = temporario;
}