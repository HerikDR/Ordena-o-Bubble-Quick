#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
#include <chrono>
using namespace std;
using namespace chrono;

struct Prato{
    int prioridade;
    int tempo;
    string nome;
};

bool auxiliar(const Prato& prato1, const Prato& prato2){
    bool prato1bubble = (prato1.nome.find("bubble") < prato1.nome.size());
    bool prato2bubble = (prato2.nome.find("bubble") < prato2.nome.size());
    // quesito prioridade dado ao "bubble"
    if (prato1bubble && !prato2bubble)
    return true;
    if (prato2bubble && !prato1bubble)
    return false;
    if (prato1.prioridade != prato2.prioridade)
        return prato1.prioridade > prato2.prioridade;
    return prato1.tempo < prato2.tempo;
}

void trocar_ordem(Prato& prato1, Prato& prato2){
    Prato temporario = prato1;
    prato1 = prato2;
    prato2 = temporario;
}

void bubble(Prato* pratos, int num){
    for (int i = 0; i < num - 1; ++i){
        for (int j = 0; j < num - i - 1; ++j){
            if (!auxiliar (pratos[j], pratos[j + 1])){
                trocar_ordem(pratos[j], pratos[j + 1]);
            }
        }
    }
}

int selecionar_pivo(Prato* pratos, int inicio, int fim){
    Prato pivo = pratos[fim];
    int i = inicio - 1;
    for (int j = inicio; j < fim; ++j){
        if (auxiliar(pratos[j], pivo)){
            ++i;
            trocar_ordem(pratos[i], pratos[j]);
        }
    }
    trocar_ordem(pratos[i + 1], pratos[fim]);
    return i + 1;
}

void quick(Prato* pratos, int inicio, int fim){
    if (inicio < fim){
        int p = selecionar_pivo(pratos, inicio, fim);
        quick(pratos, inicio, p - 1);
        quick(pratos, p + 1, fim);
    }
}

string limpar_valores(const string& nome){
    string prato_final;
    for (char a : nome){
        if (!isdigit(a)){
            prato_final += a;
        }
    }
    return prato_final;
}

void printar(const string& sort, Prato* pratos, int n, int lim = 5000){ // limite para leitura do csv
    cout << "Resultado do " << sort << "\n";
    for (int i = 0; i < min(n, lim); ++i){
        string novo_prato = limpar_valores(pratos[i].nome);
        cout << novo_prato << "\n";
    }
}

int main(){
    ifstream arq("restaurante_pratos_teste_tempo.csv"); // arquivo CSV com os dados
    if (!arq.is_open()){
        cerr << "Erro" << endl;
        return 1;
    }

    string linha;
    getline(arq, linha);
    int num_pratos = 0;
    while (getline(arq, linha)){
        ++num_pratos;
    }

    arq.clear();
    arq.seekg(0, ios::beg);
    getline(arq, linha);

    Prato* pratos = new Prato[num_pratos];
    int id = 0;

    while (getline(arq, linha)){
        stringstream lin(linha);
        string palavra;
        getline(lin, palavra, ',');
        pratos[id].prioridade = stoi(palavra);
        getline(lin, palavra, ',');
        pratos[id].tempo = stoi(palavra);
        getline(lin, palavra, ',');
        pratos[id].nome = palavra;
        ++id;
    }
    arq.close();
    cout << "Pratos contados: " << num_pratos << endl;

    Prato* exec_quick = new Prato[num_pratos];
    for (int i = 0; i < num_pratos; ++i){
        exec_quick[i] = pratos[i];
    }
    auto inicio_quick = high_resolution_clock::now();
    quick(exec_quick, 0, num_pratos - 1);
    auto fim_quick = high_resolution_clock::now();
    auto duracao_quick = duration_cast<milliseconds>(fim_quick - inicio_quick);

    Prato* exec_bubble = new  Prato[num_pratos];
    for (int i = 0; i < num_pratos; ++i){
        exec_bubble[i] = pratos [i];
    }
    auto inicio_bubble = high_resolution_clock::now();
    bubble(exec_bubble, num_pratos);
    auto fim_bubble = high_resolution_clock::now();
    auto duracao_bubble = duration_cast<milliseconds>(fim_bubble - inicio_bubble);

    printar("Bubble", exec_bubble, num_pratos);
    printar("Quick", exec_quick, num_pratos);

    cout << "\nTempo de execução dos algoritmos:\n";
    cout << "Bubble: " << duracao_bubble.count() << "ms\n";
    cout << "Quick: " << duracao_quick.count() << "ms\n";

    delete[] pratos;
    delete[] exec_quick;
    delete[] exec_bubble;

    return 0;
}