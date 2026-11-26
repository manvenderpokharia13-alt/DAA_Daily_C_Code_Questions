#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Insert node at end
struct Node* insert(struct Node *head, int data) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    struct Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;

    return head;
}

// Display linked list
void display(struct Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Normal Approach: Two Traversals
struct Node* removeNormal(struct Node *head, int n) {
    int length = 0;

    struct Node *temp = head;

    while (temp != NULL) {
        length++;
        temp = temp->next;
    }

    if (n < 1 || n > length)
        return head;

    int position = length - n;

    if (position == 0) {
        temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    temp = head;

    for (int i = 1; i < position; i++)
        temp = temp->next;

    struct Node *deleteNode = temp->next;
    temp->next = deleteNode->next;

    free(deleteNode);

    return head;
}

// Optimized Approach: Two Pointers
struct Node* removeOptimized(struct Node *head, int n) {
    struct Node dummy;
    dummy.next = head;

    struct Node *slow = &dummy;
    struct Node *fast = &dummy;

    if (n < 1)
        return head;

    for (int i = 0; i < n; i++) {
        fast = fast->next;

        if (fast == NULL)
            return head;
    }

    while (fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    struct Node *deleteNode = slow->next;
    slow->next = deleteNode->next;

    free(deleteNode);

    return dummy.next;
}

int main() {
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;

    int n, size, value;

    printf("Enter number of nodes: ");
    scanf("%d", &size);

    printf("Enter linked list elements:\n");

    for (int i = 0; i < size; i++) {
        scanf("%d", &value);

        head1 = insert(head1, value);
        head2 = insert(head2, value);
    }

    printf("Enter N: ");
    scanf("%d", &n);

    head1 = removeNormal(head1, n);
    head2 = removeOptimized(head2, n);

    printf("\nNormal Approach: ");
    display(head1);

    printf("Optimized Approach: ");
    display(head2);

    return 0;
}
