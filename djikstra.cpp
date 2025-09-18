#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;


struct Par{
    int vertDestino, valRisco;
};

struct Comparador {
    bool operator()(const Par &a, const Par &b) {
        return a.valRisco > b.valRisco;
    }
};


vector<int> dijkstra(int V, vector<vector<Par>> grafo, int origem) {

    vector<int> distancias(V, INT_MAX);
    distancias[origem] = 0;
    priority_queue<Par, vector<Par>, Comparador> pq;
    pq.push({origem, 0});

    while(!pq.empty()) {
        Par atual = pq.top();
        pq.pop();

        int vertDestAtual = atual.vertDestino;
        int riscoDestAtual = atual.valRisco;

        if(riscoDestAtual > distancias[vertDestAtual]) continue;



    }



    
}


vector<vector<Par>> capturaGrafo(int numVertTotal, int numArestTotal)
{
    vector<vector<Par>> grafo(numVertTotal);
    
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

    vector<vector<Par>> grafo = capturaGrafo(numVertTotal, numArestTotal);

}