#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;


struct Aresta{
    int vertDestino, valRisco;
};

struct Comparador {
    bool operator()(const Aresta &a, const Aresta &b) {
        return a.valRisco > b.valRisco;
    }
};


vector<int> dijkstra(int V, vector<vector<Aresta>> grafo, int origem) {

    vector<int> vetRiscos(V, INT_MAX);
    vetRiscos[origem] = 0;
    priority_queue<Aresta, vector<Aresta>, Comparador> pq;
    pq.push({origem, 0});

    while(!pq.empty()) {
        Aresta atual = pq.top();
        pq.pop();

        int vertDestAtual = atual.vertDestino;
        int riscoDestAtual = atual.valRisco;

        if(riscoDestAtual > vetRiscos[vertDestAtual]) continue;

        for(auto &e : grafo[vertDestAtual]) {
            int vizinho = e.vertDestino - 1;
            int vizinhoRisco = e.valRisco;
            if(vetRiscos[vertDestAtual] + vizinhoRisco < vetRiscos[vizinho]){

                vetRiscos[vizinho] = vetRiscos[vertDestAtual] + vizinhoRisco;
                pq.push({vizinho, vetRiscos[vizinho]});
            }
        }
    }

    return vetRiscos;
}


vector<vector<Aresta>> capturaGrafo(int numVertTotal, int numArestTotal)
{
    vector<vector<Aresta>> grafo(numVertTotal);
    
    for(int i = 0; i < numArestTotal; i++){
        int vertOrigem, vertDestino, valRisco;
        cout << "Informe a aresta [formato: origem destino valorRisco(entre 0 e 10)]: ";
        cin >> vertOrigem >> vertDestino >> valRisco;
        if(vertOrigem < 1 || vertOrigem > numVertTotal || vertDestino < 1 || vertDestino > numVertTotal || valRisco < 0 || valRisco > 10){
            cout << "Aresta invalida!" << endl;
            cout << "Valide o formato e tente novamente." << endl;
            i--;
            continue;
        }
        grafo[vertOrigem-1].push_back({vertDestino, valRisco});
        grafo[vertDestino-1].push_back({vertOrigem, valRisco});
    }


    return grafo;
}

void imprimeRiscos(vector<int> vetRiscos, int vertInicial) {
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "Riscos mínimos do vértice " << vertInicial << " para os outros vértices:" << endl;
    cout << "Risco == -1 significa que o vértice é inalcançável." << endl;
    cout << "Risco == 0 significa que o caminho é seguro." << endl;
    cout << "Risco > 0 significa que o caminho tem perigo." << endl;
    cout << "Risco == 10 significa que o caminho tem um perigo extremo." << endl;
    int k = 1;
    for(auto i : vetRiscos) {
        cout << vertInicial << " -> " << k << " = " << (i == INT_MAX ? -1 : i) << endl;
        k++;
    }
    cout << "-----------------------------------------------------------" << endl;
}

int main() {
    
    int numVertTotal, numArestTotal, vertInicial;
    cout << "Informe os vértices no formato de números ex: 1, 2, 3..." << endl;
    cout << "Os vértices devem ser numerados de 1 a n, onde n é o número total de vértices." << endl;
    cout << "Informe o numero total de vertices e arestas: ";
    cin >> numVertTotal >> numArestTotal;
    
    vector<vector<Aresta>> grafo = capturaGrafo(numVertTotal, numArestTotal);
    
    cout << "Informe o vertice inicial(" <<1 << "-" << numVertTotal << "): ";
    cin >> vertInicial;
    
    vector<int> vetRiscos = dijkstra(numVertTotal, grafo, vertInicial-1);

    imprimeRiscos(vetRiscos, vertInicial);
}