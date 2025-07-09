#include <iostream>
using namespace std;

class BinaryTreeArray {
private:
    int* tree;
    int size;
    int capacity;

public:
    // Constructor
    BinaryTreeArray(int cap) {
        capacity = cap;
        size = 0;
        tree = new int[capacity];
        for (int i = 0; i < capacity; i++)
            tree[i] = -1; // use -1 as placeholder for empty node
    }

    // Insert element (level-wise)
    void insert(int value) {
        if (size >= capacity) {
            cout << "Tree is full. Cannot insert " << value << endl;
            return;
        }
        tree[size] = value;
        size++;
    }

    // Display tree as array
    void displayArray() {
        cout << "Binary Tree (array format): ";
        for (int i = 0; i < size; i++) {
            cout << tree[i] << " ";
        }
        cout << endl;
    }

    // Inorder traversal
    void inorder(int index = 0) {
        if (index >= size || tree[index] == -1)
            return;

        inorder(2 * index + 1);           // Left
        cout << tree[index] << " ";       // Root
        inorder(2 * index + 2);           // Right
    }

    // Preorder traversal
    void preorder(int index = 0) {
        if (index >= size || tree[index] == -1)
            return;

        cout << tree[index] << " ";       // Root
        preorder(2 * index + 1);          // Left
        preorder(2 * index + 2);          // Right
    }

    // Postorder traversal
    void postorder(int index = 0) {
        if (index >= size || tree[index] == -1)
            return;

        postorder(2 * index + 1);         // Left
        postorder(2 * index + 2);         // Right
        cout << tree[index] << " ";       // Root
    }

    // Destructor
    ~BinaryTreeArray() {
        delete[] tree;
    }
};

// Main to test
int main() {
    BinaryTreeArray bt(10); // Capacity of 10

    // Insert elements level-wise
    bt.insert(1);
    bt.insert(2);
    bt.insert(3);
    bt.insert(4);
    bt.insert(5);
    bt.insert(6);

    bt.displayArray();

    cout << "Inorder Traversal: ";
    bt.inorder();
    cout << endl;

    cout << "Preorder Traversal: ";
    bt.preorder();
    cout << endl;

    cout << "Postorder Traversal: ";
    bt.postorder();
    cout << endl;

    return 0;
}
