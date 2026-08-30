#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include<vector>
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    public:
    Node(int value, Node* n){
        data = value;
        next = n;
    }

    Node(int value){
        data = value;
        next = nullptr;
    }
    
};

class LinkedList {
    Node* head;
    public:
    LinkedList();
    LinkedList(int);
    Node* append(int);
    Node* append(Node*);
    Node* convertArrayToLL(vector<int>);
    Node* getHead();
    void setHead(Node*);
    Node* remove_head();
    Node* delete_tail();
    Node* delete_at_index(int);
    Node* delete_element(int);
    Node* insert_at_head(int);
    Node* insert_at_tail(int);
    Node* insert_at_index(int, int);
    Node* insert_before_value(int, int);
    void print();
};
#endif