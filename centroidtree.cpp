#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1024;
int N = 16;

vector<vector<int>> tree(MAXN, vector<int>(0));
vector<vector<int>> ctree(MAXN, vector<int>(0));
vector<bool> iscentroid(MAXN, false);

void addEdge(int i, int j)
{
    tree[i].push_back(j);
    tree[j].push_back(i);
}

int decompose(int root);
void dfs(int root, vector<bool> &visited, vector<int> &subtsz, int &n1t);
int getctrd(int root);
int searchctrd(int root, vector<bool> &visited, vector<int> &subtsz, int n1t);

int getctrd(int root)
{
    // prepare subset size in this tree of forest
    vector<bool> visited(MAXN, false);
    vector<int> subtsz(MAXN, 0);
    int n1t = 0;
    dfs(root, visited, subtsz, n1t);
    for (int i = 0; i < MAXN; i++)
    {
        visited[i] = false;
    }
    int ctrd = searchctrd(root, visited, subtsz, n1t);
    iscentroid[ctrd] = true;
    return ctrd;
}

int searchctrd(int root, vector<bool> &visited, vector<int> &subtsz, int n1t)
{
    // check if this node is centroid, otherwise like dfs go to its greatest neighbour
    bool isctrd = true;
    visited[root] = true;

    int greatestchild = INT_MIN;

    for (int i = 0; i < tree[root].size(); i++)
    {
        if (!visited[tree[root][i]] && !iscentroid[tree[root][i]])
        {
            if (subtsz[tree[root][i]] > n1t / 2)
            {
                isctrd = false;
            }

            if (greatestchild == INT_MIN || subtsz[tree[root][i]] > subtsz[greatestchild])
            {
                greatestchild = tree[root][i];
            }
        }
    }

    if (isctrd && n1t - subtsz[root] <= n1t / 2)
    {
        return root;
    }

    return searchctrd(greatestchild, visited, subtsz, n1t);
}

int main()
{
    addEdge(1, 4);
    addEdge(2, 4);
    addEdge(3, 4);
    addEdge(4, 5);
    addEdge(5, 6);
    addEdge(6, 7);
    addEdge(7, 8);
    addEdge(7, 9);
    addEdge(6, 10);
    addEdge(10, 11);
    addEdge(11, 12);
    addEdge(11, 13);
    addEdge(12, 14);
    addEdge(13, 15);
    addEdge(13, 16);

    decompose(1);
    cout << "\n";
    return 0;
}

int decompose(int root)
{
    // first get the centroid for the tree rooted at root
    int centroid = getctrd(root);

    cout << centroid << " ";

    // go through all neighbours of centroid
    // let those neighbours be the root of their subtree
    // get the centroids for those subtrees too and they will be children of this centroid
    for (int i = 0; i < tree[centroid].size(); i++)
    {
        if (!iscentroid[tree[centroid][i]])
        {
            int subtctrd = decompose(tree[centroid][i]);
            ctree[centroid].push_back(subtctrd);
            ctree[subtctrd].push_back(centroid);
        }
    }
    return centroid;
}

void dfs(int root, vector<bool> &visited, vector<int> &subtsz, int &n1t)
{
    // perform dfs and size of subtree for this node is sum of sizes of its children subtrees + 1
    visited[root] = true;
    // increase the number of nodes of this subtree
    n1t++;
    subtsz[root] = 1;

    for (int i = 0; i < tree[root].size(); i++)
    {
        // go to next adjacent node only if it is not visited yet(obviously) and also if its not a centroid yet
        if (!visited[tree[root][i]] && !iscentroid[tree[root][i]])
        {
            dfs(tree[root][i], visited, subtsz, n1t);
            subtsz[root] += subtsz[tree[root][i]];
        }
    }
}