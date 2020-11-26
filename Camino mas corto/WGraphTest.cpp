/* 
programa para probar la funcionalidad del grafo con peso
javier alejandro martinez noe y Jorge Becker
27/9/20
*/
#include <string>

#include "WGraph.hpp"

using namespace std;

// esta funcion parmite probar la funcionalidad del programa
int main() {
    GraphWeighted<string> graph;
    graph.add_node("Hotel Nacional");
    graph.add_node("Capitolio");
    graph.add_node("El Morro");
    graph.add_node("La Catedral");
    graph.add_node("La Rampa");
    graph.add_node("Plaza Vieja");
    graph.add_node("Floridita");
    graph.add_node("El Prado");

    graph.add_edge(0, 1, 12);
    graph.add_edge(0, 5, 4);
    graph.add_edge(1, 5, 3);
    graph.add_edge(1, 2, 2);
    graph.add_edge(1, 4, 21);
    graph.add_edge(2, 3, 2);
    graph.add_edge(4, 6, 15);
    graph.add_edge(3, 6, 1);
    graph.add_edge(3, 7, 10);
    graph.add_edge(5, 7, 15);

    int start_vertex = 1;
    map<string, float> dist = graph.pathFinding(start_vertex);
    cout << "Shortest path cost from " << graph.get_node_val(start_vertex) << endl;
    for (auto &x : dist) {
        cout << "\t" << x.first << ": " << x.second << ", ";
    }

    return 0;
}