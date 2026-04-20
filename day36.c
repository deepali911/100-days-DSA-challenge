// Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of elements to enqueue)
// - Second line: n space-separated integers
// - Third line: integer m (number of dequeue operations)

// Output:
// - Print queue elements from front to rear after operations, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 2

// Output:
// 30 40 50 10 20

// Explanation:
// Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. Display remaining elements in correct order.

#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = 0;

// Enqueue
void enqueue(int x) {
    queue[rear] = x;
    rear = (rear + 1) % MAX;
}

// Dequeue
void dequeue() {
    front = (front + 1) % MAX;
}

// Display
void display() {
    int i = front;

    while (i != rear) {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX;
    }
}

int main() {
    int n, m, x;

    // INPUT
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    printf("Enter number of dequeues: ");
    scanf("%d", &m);

    // Perform m dequeues
    for (int i = 0; i < m; i++) {
        dequeue();
    }

    // OUTPUT
    printf("Queue after operations: ");
    display();

    return 0;
}