#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
struct Node {
    int key;
    int value;
    struct Node* next;
};
typedef struct Node*PNode;
// Structure for the hash table
struct HashTable {
    int size;
    PNode* table;
};
typedef struct HashTable * PHashTable;
// Function to create a new node
PNode createNode(int key, int value) {
    PNode newNode = (PNode)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to create a hash table
PHashTable createHashTable(int size) {
    PHashTable hashTable = (PHashTable)malloc(sizeof(struct HashTable));
    hashTable->size = size;
    hashTable->table = (PNode*)malloc(size * sizeof(PNode));
    for (int i = 0; i < size; i++) {
        hashTable->table[i] = NULL;
    }
    return hashTable;
}

// Function to calculate the hash value
int hashFunction(int key, int size) {
    return key % size;
}

// Function to insert a key-value pair into the hash table
void insert(PHashTable hashTable, int key, int value) {
    int index = hashFunction(key, hashTable->size);
    PNode newNode = createNode(key, value);
    if (hashTable->table[index] == NULL) {
        hashTable->table[index] = newNode;
    } else {
        PNode currentNode = hashTable->table[index];
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
}

// Function to retrieve the value associated with a key from the hash table
int get(PHashTable hashTable, int key) {
    int index = hashFunction(key, hashTable->size);
    PNode currentNode = hashTable->table[index];
    while (currentNode != NULL) {
        if (currentNode->key == key) {
            return currentNode->value;
        }
        currentNode = currentNode->next;
    }
    return -1;  // Key not found
}

// Function to delete a key-value pair from the hash table
void xoa(PHashTable hashTable, int key) {
    int index = hashFunction(key, hashTable->size);
    PNode currentNode = hashTable->table[index];
    PNode prevNode = NULL;
    while (currentNode != NULL) {
        if (currentNode->key == key) {
            if (prevNode == NULL) {
                hashTable->table[index] = currentNode->next;
            } else {
                prevNode->next = currentNode->next;
            }
            free(currentNode);
            return;
        }
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
}

// Function to display the hash table
void display(PHashTable hashTable) {
    for (int i = 0; i < hashTable->size; i++) {
        printf("Bucket %d: ", i);
        PNode currentNode = hashTable->table[i];
        while (currentNode != NULL) {
            printf("(%d, %d) ", currentNode->key, currentNode->value);
            currentNode = currentNode->next;
        }
        printf("\n");
    }
}

int main() {
    // Create a hash table with size 10
    struct HashTable* hashTable = createHashTable(10);
    
    // Insert key-value pairs into the hash table
    insert(hashTable, 1, 10);
    insert(hashTable, 2, 20);
    insert(hashTable, 3, 30);
    insert(hashTable, 11, 15);
    insert(hashTable, 22, 25);
    insert(hashTable, 33, 35);
    // Display the hash table
    display(hashTable);
    
    // Retrieve the value associated with key 2
    int value = get(hashTable, 2);
    printf("Value for key 2: %d\n", value);
    
    // Delete the key-value pair with key 2
    xoa(hashTable, 2);
    
    // Display the hash table after deletion
    display(hashTable);
    
    return 0;
}
