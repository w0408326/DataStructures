#include <iostream>
#include <regex>
using namespace std;

// A linked list node
struct Node
{
    int data;
    struct Node *next;
};
//insert a new node in front of the list
void push(struct Node** head, int node_data)
{
    /* 1. create and allocate node */
    struct Node* newNode = new Node;

    /* 2. assign data to node */
    newNode->data = node_data;

    /* 3. set next of new node as head */
    newNode->next = (*head);

    /* 4. move the head to point to the new node */
    (*head) = newNode;
}

//insert new node after a given node
void insertAfter(struct Node* prev_node, int node_data)
{
    /*1. check if the given prev_node is NULL */
    if (prev_node == NULL)
    {
        cout<<"the given previous node is required,cannot be NULL"; return; }

    /* 2. create and allocate new node */
    struct Node* newNode =new Node;

    /* 3. assign data to the node */
    newNode->data = node_data;

    /* 4. Make next of new node as next of prev_node */
    newNode->next = prev_node->next;

    /* 5. move the next of prev_node as new_node */
    prev_node->next = newNode;
}

/* insert new node at the end of the linked list */
void append(struct Node** head, int node_data)
{
/* 1. create and allocate node */
    struct Node* newNode = new Node;

    struct Node *last = *head; /* used in step 5*/

/* 2. assign data to the node */
    newNode->data = node_data;

/* 3. set next pointer of new node to null as its the last node*/
    newNode->next = NULL;

/* 4. if list is empty, new node becomes first node */
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

/* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;

/* 6. Change the next of last node */
    last->next = newNode;
    return;
}

int getNode(Node* head, int index)
{

    Node* current = head;

    // the index of the
    // node we're currently
    // looking at
    int count = 0;
    while (current != NULL)
    {
        if (count == index)
            return(current->data);
        count++;
        current = current->next;
    }

}

void displayLock(struct Node *node)
{
    while (node != NULL) {
        for (int i = 0; i < 7; i++) {
            if (i % 2 == 0) {
                cout << "R" << node->data << " ";
            } else {
                cout << "L" << node->data << " ";
            }
            node = node->next;
        }
    }

    cout << endl;
}

/* main program for linked list*/
int main()
{
/* empty list */
    struct Node* head = NULL;

// Insert 10.
    append(&head, 0);
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);
    append(&head, 6);

    cout<<"Current Lock Combination: "<<endl;
    displayLock(head);

    regex regexCombo ();

    string myCombo;

    cout << "Please enter new combination: ";
    getline(cin,myCombo);

    if(regex_match(myCombo,regexCombo)){
        cout << "match!";
    }

    return 0;
}