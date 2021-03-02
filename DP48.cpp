
#include <bits/stdc++.h>
using namespace std;

//reverse a linked list.

struct Node
{
    int data;
    struct Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

struct LinkedList
{
    Node *head;
    LinkedList()
    {
        head = NULL;
    }

    void reverse()
    {
        Node *current = head;
        Node *prev = NULL;
        Node *next = NULL;
        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            next = next;
        }
        head = prev;
    }

    void print()
    {
        struct Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void push(int data)
    {
        struct Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};

int main()
{
    LinkedList ll;
    ll.push(10);
    ll.push(20);
    ll.push(30);
    ll.push(40);
    ll.push(50);

    cout << "Given linked list\n";
    ll.print();
    cout << "\n";
    ll.reverse();
    cout << "Reverse linked list\n";
    ll.print();
    return 0;
}