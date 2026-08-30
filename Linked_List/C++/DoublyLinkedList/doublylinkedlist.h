#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include <iostream>
using namespace std;

 class Node{
    public:
    int data;
    Node* next;
    Node* previous;
    Node(int value): data(value), next(nullptr), previous(nullptr){}
    Node(int value, Node* nxt, Node* prev): data(value), next(nxt), previous(prev){}
 };

 class DoublyLinkedList {
    public:
    Node* head;
    DoublyLinkedList();
    DoublyLinkedList(int);

    DoublyLinkedList(int, Node*, Node*);

    Node* get_head();
    Node* append(int);
    Node* delete_head();
    Node* delete_tail();
    Node* delete_element_at(int);
    Node* delete_value(int);
    Node* insert_before_head(int);
    Node* insert_before_tail(int);
    Node* insert_before_index(int,int);
    Node* reverse_list();
    void print();
 };
#endif