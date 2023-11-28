#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    Node* next;
};
typedef struct Node*PNode;


void insert(PNode* head, int data) {
    PNode newNode = (PNode)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}
void heapify(int arr[], int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }
    
    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }
    
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        
        heapify(arr, size, largest);
    }
}
void heapSort(PNode* head) {
    
    int size = 0;
    PNode current = *head;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    int* arr = (int*)malloc(size * sizeof(int));
    current = *head;
    for (int i = 0; i < size; i++) {
        arr[i] = current->data;
        current = current->next;
    }
    
    
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }
    
    
    for (int i = size - 1; i > 0; i--) {
        
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        
        
        heapify(arr, i, 0);
    }
    
    
    current = *head;
    for (int i = 0; i < size; i++) {
        current->data = arr[i];
        current = current->next;
    }
    
    free(arr);
}
void printList(PNode head) {
    PNode current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    
    PNode head = NULL;
    insert(&head, 4);
    insert(&head, 2);
    insert(&head, 8);
    insert(&head, 5);
    insert(&head, 1);
    
    
    printList(head);
    
    
    heapSort(&head);
    
    printf("Sorted Linked List: ");
    printList(head);
    
    return 0;
}
