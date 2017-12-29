#include <iostream>
#include <vector>
#include <queue>

const int NUM_NODES = 10;

class Graph
{
public:
    Graph();

    void addEdge(int from, int to); // (still an undirected graph though)

    void DFS(int node);

    void BFS(int node);

    void print();

private:
    std::vector<int> adj_array[NUM_NODES];

    std::vector<bool> visited;
};

Graph::Graph()
{
    visited = std::vector<bool>(NUM_NODES, false);
}

void Graph::addEdge(int from, int to)
{
    adj_array[from].push_back(to);
    adj_array[to].push_back(from);
}

void Graph::DFS(int node)
{
    std::cout << "DFS called with node: " << node << std::endl;

    visited[node] = true;

    std::vector<int> adj_nodes = adj_array[node];
    for (int i = 0; i < adj_nodes.size(); ++i)
    {
        int adj_node = adj_nodes[i];
        if (!visited[adj_node])
        {
            std::cout << "    from node: " << node << ", calling DFS on node: " << adj_node << std::endl;
            DFS(adj_node);
        }
        else
        {
            std::cout << "    from node: " << node << ", adjacent node: " << adj_node << " is already visited" << std::endl;
        }
    }
}

void Graph::BFS(int node)
{
    std::cout << "BFS:" << std::endl;

    std::queue<int> queue;

    visited[node] = true;
    queue.push(node);

    while (!queue.empty())
    {
        // dequeue:
        int next_node = queue.front();
        queue.pop();

        std::cout << "BFS next_node: " << next_node << std::endl;

        std::vector<int> adj_nodes = adj_array[next_node];
        int adj_node;
        for (int i = 0; i < adj_nodes.size(); ++i)
        {
            adj_node = adj_nodes[i];
            if (!visited[adj_node])
            {
                visited[adj_node] = true;
                queue.push(adj_node);
                std::cout << "   in next_node: " << next_node << ", adj_node: " << adj_node << " is pushed to queue" << std::endl;
            }
            else
            {
                std::cout << "   in next_node: " << next_node << ", adj_node: " << adj_node << " is already visited" << std::endl;
            }
        }
    }
}

void Graph::print()
{
    for (int i = 0; i < NUM_NODES; ++i)
    {
        std::cout << "Node " << i << ": ";
        for (auto j = adj_array[i].begin(); j != adj_array[i].end(); ++j)
        {
            std::cout << *j << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "######################" << std::endl;
}

int main()
{
    Graph graph;
    graph.addEdge(0, 2);
    graph.addEdge(0, 1);
    graph.addEdge(0, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 1);
    graph.addEdge(1, 2);
    graph.addEdge(5, 9);
    graph.addEdge(5, 7);
    graph.addEdge(9, 7);
    graph.addEdge(7, 8);
    graph.addEdge(1, 5);
    graph.print();

    //graph.DFS(0);
    //graph.DFS(5);

    graph.BFS(0);
    //graph.BFS(5);

    return 0;
}
