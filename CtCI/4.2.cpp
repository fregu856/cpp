#include <iostream>
#include <vector>
#include <queue>

const int NUM_NODES = 5;

class DiGraph
{
public:
    DiGraph();

    void addEdge(int from, int to);

    bool isRoute(int from, int to);

    void print();

private:
    void DFS(int node);

    bool BFS(int from, int to);

    std::vector<int> adj_array[NUM_NODES];

    std::vector<bool> visited;
};

DiGraph::DiGraph()
{
    visited = std::vector<bool>(NUM_NODES, false);
}

void DiGraph::addEdge(int from, int to)
{
    adj_array[from].push_back(to);
}

bool DiGraph::isRoute(int from, int to)
{
    // DFS(from, to);
    //
    // return visited[to];

    return BFS(from, to);
}

void DiGraph::DFS(int node)
{
    visited[node] = true;

    std::vector<int> adj_nodes = adj_array[node];
    for (int i = 0; i < adj_nodes.size(); ++i)
    {
        int adj_node = adj_nodes[i];
        if (!visited[adj_node])
        {
            DFS(adj_node);
        }
    }
}

bool DiGraph::BFS(int from, int to)
{
    std::queue<int> queue;

    visited[from] = true;
    queue.push(from);
    while (!queue.empty())
    {
        // dequeue:
        int next_node = queue.front();
        queue.pop();

        std::vector<int> adj_nodes = adj_array[next_node];
        for (int i = 0;  i < adj_nodes.size(); ++i)
        {
            int adj_node = adj_nodes[i];

            if (adj_node == to)
            {
                return true;
            }

            if (!visited[adj_node])
            {
                visited[adj_node] = true;
                queue.push(adj_node);
            }
        }
    }

    return false;
}

void DiGraph::print()
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
    DiGraph graph;
    graph.addEdge(0, 2);
    graph.addEdge(2, 4);
    graph.addEdge(4, 1);
    graph.addEdge(1, 3);
    graph.addEdge(1, 0);
    graph.addEdge(2, 0);
    graph.print();

    if (graph.isRoute(0, 3))
    {
        std::cout << "Route!" << std::endl;
    }
    else
    {
        std::cout << "NO route!" << std::endl;
    }

    // if (graph.isRoute(3, 2))
    // {
    //     std::cout << "Route!" << std::endl;
    // }
    // else
    // {
    //     std::cout << "NO route!" << std::endl;
    // }

    return 0;
}
