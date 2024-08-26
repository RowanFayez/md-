#include <iostream>
using namespace std;

// Node class to represent linked list nodes
class Node
{
public:
    int row;    // Row index
    int col;    // Column index
    int value;  // Value of the non-zero element
    Node *next; // Pointer to the next node
    // Constructor
    Node(int r, int c, int v) : row(r), col(c), value(v), next(nullptr) {}
};

// Function to create a new node and add it to the linked list
void create_new_node(Node **p, int rowIndex, int colIndex, int value)
{
    Node *temp = *p; // Initialize temp to point to the head of the linked list
    Node *r;         // Pointer to a new node

    // If the linked list is empty, create the first node
    if (temp == nullptr)
    {
        *p = new Node(rowIndex, colIndex, value);
    }
    else
    {
        // Traverse to the end of the list
        while (temp->next != nullptr)
            temp = temp->next;

        // Create a new node and append it to the end of the list
        temp->next = new Node(rowIndex, colIndex, value);
    }
}

// Function to create a linked list from a 2D array
void createLinkedList(Node **head, int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] != 0)
            {
                create_new_node(head, i, j, matrix[i][j]);
            }
        }
    }
}

// Function to print the linked list
void printList(Node *start)
{
    Node *ptr = start;
    cout << "row position: ";
    while (ptr != nullptr)
    {
        cout << ptr->row << " ";
        ptr = ptr->next;
    }
    cout << endl;

    cout << "column position: ";
    ptr = start;
    while (ptr != nullptr)
    {
        cout << ptr->col << " ";
        ptr = ptr->next;
    }
    cout << endl;

    cout << "Value: ";
    ptr = start;
    while (ptr != nullptr)
    {
        cout << ptr->value << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

// Function to add two sparse matrices and return the result as a new linked list
Node *addSparseMatrices(Node *list1, Node *list2)
{
    Node *result = nullptr;
    Node *ptr1 = list1;
    Node *ptr2 = list2;

    while (ptr1 != nullptr && ptr2 != nullptr)
    {
        if (ptr1->row == ptr2->row && ptr1->col == ptr2->col)
        {
            // Same position, add values
            int sum = ptr1->value + ptr2->value;
            if (sum != 0)
                create_new_node(&result, ptr1->row, ptr1->col, sum);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if (ptr1->row < ptr2->row || (ptr1->row == ptr2->row && ptr1->col < ptr2->col))
        {
            create_new_node(&result, ptr1->row, ptr1->col, ptr1->value);
            ptr1 = ptr1->next;
        }
        else
        {
            create_new_node(&result, ptr2->row, ptr2->col, ptr2->value);
            ptr2 = ptr2->next;
        }
    }

    // Append remaining nodes from list1 or list2
    while (ptr1 != nullptr)
    {
        create_new_node(&result, ptr1->row, ptr1->col, ptr1->value);
        ptr1 = ptr1->next;
    }

    while (ptr2 != nullptr)
    {
        create_new_node(&result, ptr2->row, ptr2->col, ptr2->value);
        ptr2 = ptr2->next;
    }

    return result;
}

int main()
{
    int rows = 4;
    int cols = 5;

    // Allocate and initialize the first 2D array
    int **sparseMatrix = new int*[rows];
    for (int i = 0; i < rows; i++)
        sparseMatrix[i] = new int[cols] {0};

    // Example values for the first matrix
    sparseMatrix[0][2] = 3;
    sparseMatrix[0][4] = 4;
    sparseMatrix[1][2] = 5;
    sparseMatrix[1][3] = 7;
    sparseMatrix[3][1] = 2;
    sparseMatrix[3][2] = 6;
    sparseMatrix[3][3] = 6;
    
    // Create the first linked list
    Node *head = nullptr;
    createLinkedList(&head, sparseMatrix, rows, cols);

    // Allocate and initialize the second 2D array
    int **sparseMatrix_2 = new int*[rows];
    for (int i = 0; i < rows; i++)
        sparseMatrix_2[i] = new int[cols] {0};

    // Example values for the second matrix
    sparseMatrix_2[0][2] = 3;
    sparseMatrix_2[0][4] = 2;
    sparseMatrix_2[1][2] = 3;
    sparseMatrix_2[1][3] = 7;
    sparseMatrix_2[3][2] = 5;
    sparseMatrix_2[3][4] = 6;

    // Create the second linked list
    Node *head_2 = nullptr;
    createLinkedList(&head_2, sparseMatrix_2, rows, cols);

    // Add the two linked lists
    Node *result = addSparseMatrices(head, head_2);

    // Print the linked lists
    cout << "Linked List 1:" << endl;
    printList(head);
    cout << endl;
    cout << "Linked List 2:" << endl;
    printList(head_2);
    cout << endl;
    cout << "Result of Addition:" << endl;
    printList(result);

    // Deallocate the 2D arrays
    for (int i = 0; i < rows; i++)
        delete[] sparseMatrix[i];
    delete[] sparseMatrix;

    for (int i = 0; i < rows; i++)
        delete[] sparseMatrix_2[i];
    delete[] sparseMatrix_2;

    // Deallocate the linked lists
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    while (head_2 != nullptr)
    {
        Node *temp = head_2;
        head_2 = head_2->next;
        delete temp;
    }

    while (result != nullptr)
    {
        Node *temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}