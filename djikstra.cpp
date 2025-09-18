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

            }
        }

    }



    
}


vector<vector<Aresta>> capturaGrafo(int numVertTotal, int numArestTotal)
{
    vector<vector<Aresta>> grafo(numVertTotal);
    
    for(int i = 0; i < numArestTotal; i++){
        int vertOrigem, vertDestino, valRisco;
        cout << "Informe a aresta (formato: origem destino valorRisco): ";
        cin >> vertOrigem >> vertDestino >> valRisco;
        if(vertOrigem < 1 || vertOrigem > numVertTotal || vertDestino < 1 || vertDestino > numVertTotal || valRisco < 0){
            cout << "Aresta invalida!" << endl;
            i--;
            continue;
        }
        grafo[vertOrigem-1].push_back({vertDestino, valRisco});
        grafo[vertDestino-1].push_back({vertOrigem, valRisco});
    }


    return grafo;
}

int main() {
    
    int numVertTotal, numArestTotal;
    cout << "Informe o numero total de vertices e arestas: ";
    cin >> numVertTotal >> numArestTotal;

    vector<vector<Aresta>> grafo = capturaGrafo(numVertTotal, numArestTotal);

}