#include <bits/stdc++.h>
using namespace std;

//vertex cover problem prerequisite.
/*
class Graph
{
    int V;
    list<int> *adj;
public:
    Graph(int V);
    void addEdge(int v, int w);
    void printvertexCover();
};

Graph::Graph(int V)
{
    this->V=V;
    adj=new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::printvertexCover()
{
    bool visiited[V];
    for(int i=0;i<V;i++){
        visiited[i]=false;
    }

    list<int>::iterator i;
    for(int u=0;u<V;u++){
        if(visiited[u]==false){
            for(i=adj[u].begin();i!=adj[u].end();i++){
                int v=*i;
                if(visiited[v]==false){
                    visiited[v]=true;
                    visiited[u]=true;
                    break;
                }
            }
        }
    }
    for(int i=0;i<V;i++){
        if(visiited[i]){
            cout<<i<<" ";
        }
    }
}

int main()
{
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(5,6);
    g.printvertexCover();
    return 0;
}
*/

struct node
{
    int data;
    int vc;
    struct node *left, *right;
};

int VCover(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 0;
    }

    if (root->vc != 0)
    {
        return root->vc;
    }

    int size_incl = 1 + VCover(root->left) + VCover(root->right);

    int size_excl = 0;
    if (root->left)
    {
        size_excl += 1 + VCover(root->left->left) + VCover(root->left->right);
    }
    if (root->right)
    {
        size_excl += 1 + VCover(root->right->left) + VCover(root->right->left);
    }

    return root->vc;
}

struct node *newNode(int data)
{
    struct node *temp = new node;
    temp->data = data;
    temp->left = temp->right = NULL;
    temp->vc = 0;
    return temp;
}

int main()
{
    struct node *root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->right = newNode(14);
    root->right->right = newNode(25);
    cout << VCover(root);
    return 0;
}
