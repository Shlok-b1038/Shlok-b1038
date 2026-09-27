#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node *head = NULL;
Node *nextNode = NULL;

void printList() {
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    };
    printf("\n");
};

void freeList() {
    Node *current = head;

    while (current != NULL) {
        Node *temp = current->next;
        free(current);
        current = temp;
    };

    head = NULL;
};

void insertHead(int nodeValue) {
    Node *newNode = malloc(sizeof(Node));
    newNode->value = nodeValue;
    newNode->next = head;
    head = newNode;
};

void insertTail(int nodeValue) {
    Node *newNode = malloc(sizeof(Node));
    newNode->value = nodeValue;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return; // So the code stops right here without going further
    }

    Node *current = head;
    while (current->next != NULL) current = current->next;
    current->next = newNode;
};

void deleteNode(int nodeValue) {
    Node *prev = NULL;
    Node *current = head;

    while (current != NULL && current->value != nodeValue) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("didn't find the node\n");
        return;
    }
    else if (current == head) {
        head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
}
int main() {
    head = malloc(sizeof(Node));
    nextNode = malloc(sizeof(Node));
    head->value = 5;
    nextNode->value = 10;
    head->next = nextNode;
    nextNode->next = NULL;

    // printList();
    // insertHead(15);
    // printList();
    //
    // insertTail(44);
    // printList();
    //
    // deleteNode(10);
    // printList();
    //
    // freeList();

    return 0;
};
