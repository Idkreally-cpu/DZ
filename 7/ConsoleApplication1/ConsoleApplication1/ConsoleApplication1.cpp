#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void DFS_recursive(int node, vector<bool>& visited, const vector<vector<int>>& graph) {
    visited[node] = true;
    cout << node << " ";
    
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            DFS_recursive(neighbor, visited, graph);
        }
    }
}

void DFS_iterative(int start, const vector<vector<int>>& graph) {
    vector<bool> visited(graph.size(), false);
    stack<int> st;
    
    st.push(start);
    visited[start] = true;
    
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        cout << node << " ";
        
        for (int i = graph[node].size() - 1; i >= 0; i--) {
            int neighbor = graph[node][i];
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                st.push(neighbor);
            }
        }
    }
}

int main() {
    vector<vector<int>> graph = {
        {1, 2},     
        {0, 3, 4},  
        {0, 5},     
        {1},        
        {1},        
        {2}         
    };
    
    vector<bool> visited(graph.size(), false);
    
    cout << "Рекурсивный DFS: ";
    DFS_recursive(0, visited, graph);
    cout << endl;
    
    cout << "Итеративный DFS: ";
    DFS_iterative(0, graph);
    cout << endl;
    
    return 0;
}
