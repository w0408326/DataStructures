#include <iostream>
#include <regex>
#include <string>
#include <fstream>

// Linked list code referenced from www.geeksforgeeks.org and Hal's in class material

using namespace std;

// A linked list node
struct Node
{
    int data;
    struct Node *next;
};

/* insert new node at the end of the linked list */
void append(struct Node** head, int node_data)
{
/* 1. create and allocate node */
    auto* newNode = new Node;

    struct Node *last = *head; /* used in step 5*/

/* 2. assign data to the node */
    newNode->data = node_data;

/* 3. set next pointer of new node to null as its the last node*/
    newNode->next = nullptr;

/* 4. if list is empty, new node becomes first node */
    if (*head == nullptr)
    {
        *head = newNode;
        return;
    }

/* 5. Else traverse till the last node */
    while (last->next != nullptr)
        last = last->next;

/* 6. Change the next of last node */
    last->next = newNode;
}

int getNode(Node* head, int index)
{
    Node* current = head;

    int count = 0;
    while (current != nullptr)
    {
        if (count == index)
            return(current->data);
        count++;
        current = current->next;
    }
}

int deleteNode(Node* head,int index)
{
    Node* current = head;

    int count = 0;
    while (current != nullptr)
    {
        if (count == index) {
            current->data = 0;
            return (current->data);
        }
        count++;
        current = current->next;
    }
}

int substituteNode(Node* head, int index, int substitute) {
    Node* current = head;

    int count = 0;
    while (current != nullptr)
    {
        if (count == index) {
            current->data = substitute;
            return (current->data);
        }
        count++;
        current = current->next;
    }
}

int resetNodes(Node* head)
{
    Node* current = head;

    int count = 0;
    while (current != nullptr)
    {
        current->data = 0;
        if (count == 6)
            return(current->data);
        count++;
        current = current->next;
    }
}

string displayLock(struct Node *node)
{
    stringstream lock;

    while (node != nullptr) {
        for (int i = 0; i < 7; i++) {
            if (i % 2 == 0) {
                lock << "R" << node->data << " ";
            } else {
                lock << "L" << node->data << " ";
            }
            node = node->next;
        }
    }

    lock << endl << endl;

    return lock.str();
}

string nodeDirection(int currentNode)
{
    if (currentNode % 2 == 0) {
        return "R";
    } else {
        return "L";
    }
}

void displayWorkingLock(Node *head, int currentNode)
{
    cout << "Current Working Lock: Position " << currentNode+1  << " Value: "<< nodeDirection(currentNode) << getNode(head,currentNode) << endl;
}

/* main program for linked list*/
int main()
{
/* empty list */
    struct Node* head = nullptr;
    int currentNode = 0;

// Insert .
    append(&head, 0);
    append(&head, 0);
    append(&head, 0);
    append(&head, 0);
    append(&head, 0);
    append(&head, 0);
    append(&head, 0);

    displayWorkingLock(head, currentNode);
    cout<<"Current Lock Combination: " << displayLock(head);

    regex substituteCommand("[Ss] ([1-4][0-9]|[0-9])");
    regex gotoCommand("[Gg] [1-7]");

    string command;;

    cout << "Enter command: ";
    getline(cin,command);

    for_each(command.begin(), command.end(), [](char & c){
        c = ::toupper(c);
    });

    while(command != "Q") {
        if (regex_match(command,gotoCommand)) {
            command.erase(0,2);
            currentNode = stoi(command) -1;
        } else if (command == "D"){
            deleteNode(head,currentNode);
        } else if (command == "R"){
            currentNode = 0;
            resetNodes(head);
        } else if (command == "E"){
            string fileName;
            string dotTxt = ".txt";
            ofstream myFile;

            cout << "Enter the name of the file to store the final combination: ";
            getline(cin,fileName);

            fileName.append(dotTxt);

            myFile.open(fileName);
            myFile << displayLock(head);
            myFile.close();

            return 0;
        } else if (command == "Q"){
            return 0;
        } else if (regex_match(command,substituteCommand)){

            command.erase(0,2);
            int substitute = stoi(command);

            cout << substitute << endl;

            if(substitute >= 0 && substitute <=49){
                substituteNode(head,currentNode,substitute);
            }
        }else{
            cout << "Please enter a valid command" << endl;
        }

        displayWorkingLock(head, currentNode);
        cout<<"Current Lock Combination: " << displayLock(head);

        cout << "Enter command: ";
        getline(cin,command);

        for_each(command.begin(), command.end(), [](char & c){
            c = ::toupper(c);
        });
    }

    return 0;
}