#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

int detectCycle(struct Node *head) {
    struct Node *slow = head;
    struct Node *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return 1;
        }
    }

    return 0;
}

int main() {
    struct Node *head = NULL, *temp, *newNode;
    int n, i, pos;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter data: ");
        scanf("%d", &newNode->data);

        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
            newNode->prev = temp;
        }

        temp = newNode;
    }

    printf("Enter position to create cycle (0 for no cycle): ");
    scanf("%d", &pos);

    if (pos > 0 && pos <= n) {
        temp->next = head;

        for (i = 1; i < pos; i++) {
            head = head->next;
        }

        temp->next = head;
        head->prev = temp;
    }

    if (detectCycle(pos > 0 ? (pos <= n ? (temp->next) : head) : head))
        printf("Cycle detected\n");
    else
        printf("No cycle detected\n");

    return 0;
}
