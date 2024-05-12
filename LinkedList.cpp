#include <iostream>
using namespace std;

// Part 2A: Convert Node class to a class template
template <typename T>
class Node {
public:
    T m_iData;  // The data stored in the node
    Node<T>* mp_nodeNext;  // Pointer to the next node

    // Constructor to initialize the node with data
    Node(T data) : m_iData(data), mp_nodeNext(nullptr) {}

    // Part 2A: Convert displayList into a member of a template class
    // Display the list of nodes starting from the head
    static void displayList(Node<T>* p_nodeHead) {
        Node<T>* p_node = p_nodeHead;
        while (p_node != nullptr) {
            cout << p_node->m_iData << " ";  // Display the data
            p_node = p_node->mp_nodeNext;  // Move to the next node
        }
        cout << endl;
    }
};

int main() {
    // Part 2B: Use the class template with int
    Node<int>* p_node1 = new Node<int>(10);
    Node<int>* p_node2 = new Node<int>(20);
    Node<int>* p_node3 = new Node<int>(30);

    p_node1->mp_nodeNext = p_node2;  // Append p_node2 to the list of Node objects after p_node1.
    p_node2->mp_nodeNext = p_node3;  // Append p_node3 to the list of Node objects after p_node2.
    p_node3->mp_nodeNext = nullptr;  // The end of the list is indicated by a mp_nodeNext value of nullptr.

    Node<int>::displayList(p_node1);  // Display the list of nodes to standard output.

    // Part 2D: Modify the main function for double
    Node<double>* d_node1 = new Node<double>(10.1);
    Node<double>* d_node2 = new Node<double>(20.2);
    Node<double>* d_node3 = new Node<double>(30.3);

    d_node1->mp_nodeNext = d_node2;
    d_node2->mp_nodeNext = d_node3;
    d_node3->mp_nodeNext = nullptr;

    Node<double>::displayList(d_node1);  // Display the list of double nodes.

    // Clean up heap memory
    delete p_node1;
    delete p_node2;
    delete p_node3;
    delete d_node1;
    delete d_node2;
    delete d_node3;

    return 0;
}
