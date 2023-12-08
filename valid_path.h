#include <iostream>
#include <vector>
#include <utility>
#include <sstream>
#include <algorithm>
#include <map>

using std::map;

map<int, std::vector<int>> to;
bool found = false;

void recPathFind(int source, int destination){
    if (found)
        return;
    if(std::find(to[source].begin(), to[source].end(), destination) != to[source].end()){
        found = true;
        return;
    }
    for(int j = 0; j < to[source].size(); j++){
        recPathFind(to[source][j], destination);
    }
}

bool validPath(int n, std::vector<std::pair<int, int>> edges, 
                int source, int destination){

    for (int i = 0; i < edges.size(); i++){
        if(edges[i].first == source && edges[i].second == destination)
            return true;
        to[edges[i].first].push_back(edges[i].second);

        recPathFind(source, destination);

        if(found)
            return true;
    }

    return false;
}