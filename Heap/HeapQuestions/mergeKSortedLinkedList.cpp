#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

// 'compare' function used to build
// up the priority queue
struct compare
{
    bool operator()(
        struct node *a, struct node *b)
    {
        return a->data > b->data;
    }
};

node *mergeSortedList(node *arr[], int k)
{
    // min heap for node -> Hence used compare instead of greater.
    priority_queue<node *, vector<node *>, compare> pq;

    for (int i = 0; i < k; i++)
    {
        if (arr[i] != NULL)
        {
            pq.push(arr[i]);
        }
    }

    // If there is no node in pq -> than if means arrays are empty.
    if (pq.empty())
    {
        return NULL;
    }

    node *dummy = new node(-1);
    node *last = dummy;

    while (!pq.empty())
    {
        node *curr = pq.top();
        pq.pop();
        if (curr != NULL)
        {
            last->next = curr;
            last = last->next;
        }
        if (curr->next != NULL)
        {
            curr = curr->next;
            pq.push(curr);
        }
    }

    // If we return dummy then our linked list will start
    // from -1(Because its aur first value of dummy list).
    return dummy->next;
}

void printList(node *head)
{
    while (head != NULL)
    {
        cout << head->data << "-> ";
        head = head->next;
    }
}

int main(int argc, char const *argv[])
{
    // Number of linked lists
    int k = 3;

    // Number of elements in each list
    int n = 4;

    // An array of pointers storing the
    // head nodes of the linked lists
    node *arr[k];

    // Creating k = 3 sorted lists
    arr[0] = new node(1);
    arr[0]->next = new node(3);
    arr[0]->next->next = new node(5);
    arr[0]->next->next->next = new node(7);

    arr[1] = new node(2);
    arr[1]->next = new node(4);
    arr[1]->next->next = new node(6);
    arr[1]->next->next->next = new node(8);

    arr[2] = new node(0);
    arr[2]->next = new node(9);
    arr[2]->next->next = new node(10);
    arr[2]->next->next->next = new node(11);

    // Merge the k sorted lists
    node *head = mergeSortedList(arr, k);
    printList(head);
    return 0;
}
