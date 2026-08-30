#include "linkedlist.h"
#include <iostream>
LinkedList::LinkedList(int value)
{
    Node *node = new Node(value);
    head = node;
}

LinkedList::LinkedList()
{
    head = nullptr;
}

Node *LinkedList::append(int value)
{
    Node *node = new Node(value);
    if (head == NULL)
    {
        head = node;
        return head;
    }

    Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = node;
    return head;
}

Node *LinkedList::convertArrayToLL(vector<int> arr)
{
    if (arr.size() < 1)
        return nullptr;
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (size_t i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

Node *LinkedList::getHead()
{
    return head;
}

void LinkedList::setHead(Node* new_head){
    head = new_head;
}

Node *LinkedList::remove_head()
{
    Node *temp = getHead();
    head = head->next;
    free(temp);
    return head;
}

Node *LinkedList::delete_tail()
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        head = NULL;
        return NULL;
    }
    Node *slow = getHead();
    Node *fast = slow->next->next;
    while (fast != NULL)
    {
        slow = slow->next;
        fast = slow->next->next;
    }
    Node *to_be_deleted = slow->next;
    slow->next = nullptr;
    free(to_be_deleted);
    return head;
}

Node *LinkedList::delete_at_index(int index)
{
    if (index > 1 && head->next == NULL)
        return NULL;
    if (index == 1)
        return remove_head();
    if (head == NULL)
        return NULL;
    Node *current = head;
    int count = 1;
    while (current)
    {
        if ((count + 1) == index)
        {
            Node *to_delete = current->next;
            if (to_delete == NULL)
                return NULL;
            if (to_delete->next == NULL)
                return delete_tail();
            current->next = to_delete->next;
            free(to_delete);
            return head;
        }
        current = current->next;
        count++;
    }
    return head;
}

Node *LinkedList::delete_element(int value)
{

    if (head->data == value)
        return remove_head();
    if (head == NULL)
        return NULL;
    Node *current = head;
    Node *previous = current;
    while (current)
    {
        if (current->data == value)
        {
            previous->next = current->next;
            Node *to_delete = current;
            free(to_delete);
            return head;
        }
        previous = current;
        current = current->next;
    }
    return head;
}

Node *LinkedList::insert_at_head(int value)
{
    if (head == NULL)
        return NULL;
    Node *new_node = new Node(value);
    new_node->next = head;
    head = new_node;
    return head;
}

Node *LinkedList::insert_at_tail(int value)
{
    Node *node = new Node(value);
    if (head == NULL)
    {
        head = node;
        return NULL;
    }
    Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = node;
    return head;
}

Node *LinkedList::insert_at_index(int index, int value)
{
    Node *node = new Node(value);
    if (head == NULL)
    {
        if (index == 1)
        {
            head = node;
            return head;
        }
        else
            return NULL;
    }

    if (index == 1)
        return insert_at_head(value);

    Node *current = head;
    index--;
    while (current != NULL)
    {
        if (index < 1)
            return NULL;
        if (index == 1)
        {
            Node *temp = current->next;
            current->next = node;
            node->next = temp;
            return head;
        }
        index--;
        current = current->next;
    }
    return head;
}

Node *LinkedList::insert_before_value(int value, int new_value)
{
    Node *node = new Node(new_value);
    if (head == NULL)
        return NULL;
    if (head->data == value)
        return insert_at_index(1, new_value);

    Node *current = head;
    Node *prev = current;
    while (current != NULL)
    {
        if (current->data == value)
        {
            prev->next = node;
            node->next = current;
            return head;
        }
        prev = current;
        current = current->next;
    }
    return head;
}

void LinkedList::print()
{
    Node *current = getHead();
    if (current == NULL)
    {
        cout << "Empty list" << endl;
        return;
    }
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

Node* LinkedList::append(Node* node){
    Node* head = getHead();
    if(node == NULL) return head;
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = node;
    return head;
}