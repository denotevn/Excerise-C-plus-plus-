#include <bits/stdc++.h>

using namespace std;

const int inf = 1000000;

const int maxn = 50000;
// dung de lay chu so cua day 10 chu so
long long pw[10]; // 1, 10, 100 ...
int cost[10];     // The costs of the prefix matchings

struct Node
{
    vector<pair<int, Node *>> v; // The vertices are reachable
    Node *parent;                // previous vertex measured on the shortest path
    int d;                       // Shortest time to transmit telegraph message
    bool visited;

}nodes[maxn];

// Save nodes
unordered_map<long long, Node *> m;

int getDigit(long long num, int i)
{
    return num / pw[i] % 10;
}

// Replace the i-th digit of num with n
long long setDigit(long long num, int i, int n)
{
    return num - ((long long)getDigit(num, i)) * pw[i] + n * pw[i];
}

// used to calculate how many prefixes are suitable for determining telegraph transit time
int matchPrefix(long long num1, long long num2)
{
    int matched = 0;
    for (int i = 10 - 1; i >= 0; i--)
    {
        if (getDigit(num1, i) == getDigit(num2, i))
            matched++;
        else
            break;
    }
    return matched;
}

// Build graphs 
void add(long long num, int id) // Adds this station into the graph at node #id
{
    vector<std::pair<int, Node*>> v; // The "neighboring" stations we find and their cost
    for(int i = 0; i < 10; i++) // Replace digit
    {
        for(int d = 0; d < 10; d++)
        {
            auto num2 = setDigit(num, i, d);
            auto it = m.find(num2);
            if(it != m.end())
            {
                int c = cost[matchPrefix(num, num2)];
                v.push_back( { c, (*it).second } );
            }
        }
    }
    for(int i = 0; i < 10; i++) // Switch two numbers
    {
        for(int j = i+1; j < 10; j++)
        {
            int di = getDigit(num, i);
            int dj = getDigit(num, j);
            auto num2 = setDigit(setDigit(num, j, di), i, dj);
            auto it = m.find(num2);
            if(it != m.end())
            {
                int c = cost[matchPrefix(num, num2)];
                v.push_back( { c, (*it).second } );
            }
        }
    }
    m[num] = &nodes[id];
    for(auto p : v) // Add all "neighbors" into the graph
    {
        p.second->v.push_back( { p.first, &nodes[id] } );
        nodes[id].v.push_back( { p.first, p.second } );
    }
}

void search(Node *start, int N) // Dijkstra
{
    using pin = pair<int, Node *>;

    priority_queue<pin, vector<pin>, greater<pin>> q; 

    for (int i = 0; i < N; i++){
        nodes[i].d = inf, nodes[i].visited = false;
    }   
    start->d = 0;

    q.push({0, start});
    while (!q.empty())
    {
        auto p = q.top();
        q.pop();
        auto node = p.second;
        if (node->visited)
            continue;
        node->visited = true;
        for (auto it = node->v.begin(); it < node->v.end(); it++)
        {
            auto n = (*it).second; //  dinh
            int cost = (*it).first; //  trong so
            if (!n->visited && n->d > node->d + cost)
            {
                n->parent = node;
                n->d = node->d + cost;
                q.push({n->d, n});
            }
        }
    }
}

int main()
{
    long long b = 1;

    for (int i = 0; i < 10; i++)
        pw[i] = b, b *= 10;

    int n;
    cin >> n;
    for (int i = 0; i < 10; i++){
        cin >> cost[i];
    }
        
    for (int i = 0; i < n; i++)
    {
        long long num;
        cin >> num;
        add(num, i);
    }
    vector<Node *> result;

    search(&nodes[0], n);
    if (!nodes[n - 1].visited){
        cout << "-1" << endl;
        return 0;
    }
    cout << nodes[n-1].d <<  endl;
   
    for (Node *node = &nodes[n - 1]; node; node = node->parent){
        result.push_back(node);
    }

    cout << result.size() << endl;
    for (auto it = result.rbegin(); it < result.rend(); it++){
        cout << ((*it) - nodes) + 1;
    }

    return 0;
}