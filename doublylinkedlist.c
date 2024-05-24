#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
}node ;

node *head_ref;

node *GetNewNode(int x) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
    
}


// adds to the head of the list
void InsertAtHead(int x) {
    node *temp = GetNewNode(x);
    if(head_ref == NULL) {
        head_ref = temp;
        return;
    }
    head_ref->prev = temp;
    temp->next = head_ref;
    head_ref = temp;
}
// adds to the tail of the list
void Append(int x) {
    node* curr = head_ref;
    node *temp = GetNewNode(x);
    temp->data = x;
    temp->next = NULL;
    temp->prev = NULL;

    // finds a tail of the list 
    while(curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = temp;
    curr->prev = temp;

}

// inserts node at a given postition
void InsertAtPos(int x, int pos) {
    node* temp = GetNewNode(x);
    node *curr = head_ref;

    if (pos == 1) {
        InsertAtHead(x);
        return;
    }
    for (int i = 0; i < pos - 2; i++) {
        curr = curr->next;
    }
    temp->next=curr->next;
    temp->prev = curr->prev;
    curr->next = temp;
    curr->prev = temp;

}

// deletes node with a given value
void delete(int x) {
    node *curr = head_ref;

    while(curr->data != x) {
        curr = curr->next;
        if(curr->data == x) {
            break;
        }
    }
        
    node *temp2 = curr->next;
    curr->prev = temp2->prev;
    curr->next = temp2->next;
    
    free(temp2);
    return;

}

void Print() {
    node *curr = head_ref;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}

int main() {
    head_ref = NULL;
    

    InsertAtHead(23);
    InsertAtHead(234);
    InsertAtHead(54);
    Append(678);
    Append(90000);
    InsertAtPos(333,3);
    delete(333);
    Print();
    return 0;
}
