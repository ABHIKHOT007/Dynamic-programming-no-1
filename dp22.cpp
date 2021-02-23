#include <bits/stdc++.h>
using namespace std;

//Larget independent set problem.
//Expoential time complexity.
/*
int max(int x, int y)
{
    return (x>y)?x:y;
}

class node
{
    public:
    int data;
    node *left;
    node *right;
};

int LISS(node *root)
{
    if(root==NULL){
        return 0;
    }

    int size_excl=LISS(root->left)+LISS(root->right);
    int size_incl=1;
    if(root->left!=0){
        size_incl+=LISS(root->left->left)+LISS(root->right->right);
    }
    if(root->right!=0){
        size_incl+=LISS(root->right->left)+LISS(root->right->right);
    }
    return max(size_incl,size_excl);
}

node *newNode(int data)
{
    node *temp=new node();
    temp->data = data;
    temp->right = temp->right = NULL;
    return temp;
}

int main()
{
    node *root = newNode(20);
    root->left=newNode(8);
    root->left->left=newNode(4);
    root->right->right=newNode(12);
    root->right->left=newNode(12);
    root->left->right->left=newNode(10);
    root->left->right->right=newNode(14);
    root->right=newNode(22);
    root->right->right=newNode(25);

    cout<<LISS(root);
    return 0;
}
*/
//Memoization method.
//o(n)

#include <bits/stdc++.h>
using namespace std;

int max(int x, int y)
{
    return (x > y) ? x : y;
}

class node
{
public:
    int data;
    int liss;
    node *left;
    node *right;
};

int LISS(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->liss)
    {
        return root->liss;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return (root->liss = 1);
    }
    int liss_excl = LISS(root->left) + LISS(root->right);

    int liss_incl = 1;
    if (root->left)
    {
        liss_incl += LISS(root->left->left) + LISS(root->left->right);
    }
    if (root->right)
    {
        liss_incl += LISS(root->right->left) + LISS(root->right->left);
    }
    root->liss = max(liss_incl, liss_excl);
    return root->liss;
}

node *newNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int main()
{
    node *root = newNode(22);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->left = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);
    cout << LISS(root);
    return 0;
}