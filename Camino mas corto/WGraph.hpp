/* 
programa para probar la funcionalidad del grafo con peso
javier alejandro martinez noe y Jorge Becker
27/9/20
*/
#ifndef _WGRAPH_HPP_
#define _WGRAPH_HPP_

#include <limits.h>

#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

template <class T>
class GraphVertexWeighted {
   private:
    T val;
    std::vector<std::pair<int, float>> adj;

   public:
    ~GraphVertexWeighted(){};
    GraphVertexWeighted(){};
    GraphVertexWeighted(T _val) { val = _val; };
    // este metodo te permite consegir el valor del nodo
    T get_val() { return val; };
    // este metodo permite establecer el valor de un nodo
    void set_val(T _val) { val = _val; };
    // este emtodo regresa los vecinos del nodo
    std::vector<std::pair<int, float>> get_adj() { return adj; };
    // este metodo permite añadir una arista entre los vectores
    void add_to_adj(int idx, float weight) { adj.push_back(std::make_pair(idx, weight)); };
};

template <class T>
class GraphWeighted {
   private:
    std::vector<GraphVertexWeighted<T>> nodes;
    bool is_directed;

   public:
    ~GraphWeighted(){};
    GraphWeighted() { is_directed = false; };
    // este metodo te permite agregar un vertice
    void add_node(T val) {
        GraphVertexWeighted<T> node(val);
        nodes.push_back(node);
    };
    // este metodo te permite agregar una arista entre dos vertices
    void add_edge(int src, int dst, float weight) {
        nodes[src].add_to_adj(dst, weight);
        if (!is_directed)
            nodes[dst].add_to_adj(src, weight);
    };
    // este metodo te prmite consegir el valor del nodo
    T get_node_val(int i) {
        return nodes[i].get_val();
    };
    /*ALGORITHM(G,s):
    Set all vertices to not-sure.
    d[v] = ∞ for all v in Vd[s] = 0
    while there are not-surenodes:
        pick the not-surenode u with smallest estimate d[u]
        for v in u.neighbors:
            d[v] ← min(d[v], d[u] + w(u,v)) // update step
        mark u as sure
    now all d[v] indeed equals the true distance d(s,v)*/
    // este metodo te permite mapear el grafo para encontrar los caminos mas eficientes a los vertices
    map<string, float> pathFinding(int s) {
        vector<int> notShure;
        vector<int> shure;
        //vector<pair<int, int>> d;
        map<int, float> d;
        map<string, float> Vval;
        int u;
        for (size_t i = 0; i < nodes.size(); i++) {
            d[i] = 100 * 100;
            notShure.push_back(i);
        }
        d[s] = 0;
        int indMin = s;
        while (!notShure.empty()) {
            vector<pair<int, float>> tempAdj = nodes[indMin].get_adj();

            for (size_t i = 0; i < tempAdj.size(); i++) {
                d[tempAdj[i].first] = std::min(d[tempAdj[i].first], d[indMin] + tempAdj[i].second);
            }

            auto it = find(notShure.begin(), notShure.end(), indMin);
            indMin = distance(notShure.begin(), it);
            notShure.erase(notShure.begin() + indMin);
            indMin = notShure.front();
            for (auto &x : d) {
                if (x.second < d[indMin] && count(notShure.begin(), notShure.end(), x.first)) {
                    indMin = x.first;
                }
            }
        }
        for (auto &x : d) {
            Vval[nodes[x.first].get_val()] = x.second;
        }
        return (Vval);
    }
};

#endif