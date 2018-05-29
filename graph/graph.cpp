#include <iostream>
#include "common.h"
#include <bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f

// https://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/
class Graph{
    int V;
    list<pair<int, int> > *adj_;

public:
    Graph(int v);

    void addEdge(int u, int v, int w);
    void shortestPathUsingSet(int s);
    void searchSS(int s);
};

Graph::Graph(int v) {
    this->V = v;
    adj_ = new list<pair<int, int> >[V];
}

void Graph::addEdge(int u, int v, int w) {
    adj_[u].push_back(make_pair(v, w));
    adj_[v].push_back(make_pair(u, w));
}

void Graph::shortestPathUsingSet(int src) {
    set<pair<int, int> > setds;
    vector<int> dist(V, INF);

    setds.insert(make_pair(0, src));
    dist[src] = 0;

    while(!setds.empty()) {

        for(auto s : setds){
            std::cout << s.first << "  " << s.second << std::endl;
        }
        std::cout << std::endl;
        pair<int, int> tmp = *(setds.begin());
        setds.erase(setds.begin());

        int u = tmp.second;
        list<pair<int, int> >::iterator iter;
        for(iter = adj_[u].begin(); iter != adj_[u].end(); iter++) {
            int v = (*iter).first;
            int weight = (*iter).second;
            if(dist[v] > dist[u]+weight) {
                if(dist[v] != INF) {
                    setds.erase(setds.find(make_pair(dist[v], v)));
                }
                dist[v] = dist[u] + weight;
                setds.insert(make_pair(dist[v], v));
            }
        }
    }
    // Print shortest distances stored in dist[]
       printf("Vertex   Distance from Source\n");
       for (int i = 0; i < V; ++i)
           printf("%d \t\t %d\n", i, dist[i]);


}

void Graph::searchSS(int s) {

    set<pair<int, int> > dist_and_v;
    dist_and_v.insert(make_pair(0, s));
    vector<int> dist(V, std::numeric_limits<int>::max());
    while(!dist_and_v.empty()) {

        auto tmp = (*dist_and_v.begin());
        dist_and_v.erase(dist_and_v.begin());

        list<pair<int, int> >::iterator iter;

        for( iter = adj_[tmp.second].begin(); iter != adj_[tmp.second].end(); iter++) {
            if(dist[iter->first] > iter->second +tmp.first) {
                if(dist[iter->first] != std::numeric_limits<int>::max()) {
                    dist_and_v.erase(dist_and_v.find(make_pair(dist[iter->first], iter->first)));
                }
                dist[iter->first] = tmp.first + iter->second;
                dist_and_v.insert(make_pair(dist[iter->first], iter->first));
            }
        }
    }
    // Print shortest distances stored in dist[]
       printf("Vertex   Distance from Source\n");
       for (int i = 0; i < V; ++i)
           printf("%d \t\t %d\n", i, dist[i]);

}

int main (int argc, char** argv)
{
    // create the graph given in above fugure
        int V = 9;
        Graph g(V);

        //  making above shown graph
        g.addEdge(0, 1, 4);
        g.addEdge(0, 7, 8);
        g.addEdge(1, 2, 8);
        g.addEdge(1, 7, 11);
        g.addEdge(2, 3, 7);
        g.addEdge(2, 8, 2);
        g.addEdge(2, 5, 4);
        g.addEdge(3, 4, 9);
        g.addEdge(3, 5, 14);
        g.addEdge(4, 5, 10);
        g.addEdge(5, 6, 2);
        g.addEdge(6, 7, 1);
        g.addEdge(6, 8, 6);
        g.addEdge(7, 8, 7);

        g.searchSS(0);
        g.shortestPathUsingSet(0);
    return (0);
}
