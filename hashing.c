#include <stdio.h>

int arr[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

void insert(int element) {
    int key = element % 10; // Use modulo 10 to fit within the array size

    if (arr[key] == -1) {
        arr[key] = element;
        printf("%d Inserted at arr[%d]\n", element, key);
    } else {
        printf("Collision Occurred\n");
        while (arr[key] != -1) {
            key = (key + 1) % 10;
        }
        arr[key] = element;
        printf("%d Inserted at arr[%d]\n", element, key);
    }
}

void del(int element) {
    int key = element % 10; // Use modulo 10 to fit within the array size

    if (arr[key] == element) {
        arr[key] = -1;
        printf("%d Deleted from arr[%d]\n", element, key);
    } else {
        printf("%d Not Found in arr[%d]\n", element, key);
    }
}

int search(int element) {
    int key = element % 10; // Use modulo 10 to fit within the array size

    if (arr[key] == element) {
        printf("Element %d Found at arr[%d]\n", element, key);
        return 1;
    } else {
        printf("Element %d Not Found!\n", element);
        return 0;
    }
}

int main() {
    insert(21);
    insert(32);
    insert(10);

    del(21);
    del(22); // Test with an element that doesn't exist
    search(22);
    search(32);

    return 0;
}
