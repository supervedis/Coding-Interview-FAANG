#include "doublylinkedlist.h"
//using namespace std;

DoublyLinkedList::DoublyLinkedList()
{
    head = NULL;
}

DoublyLinkedList::DoublyLinkedList(int value)
{
    Node *head = new Node(value);
}

DoublyLinkedList::DoublyLinkedList(int value, Node *n, Node *p)
{
    Node *head = new Node(value, n, p);
}

Node* DoublyLinkedList::get_head(){
    return head;
}

Node *DoublyLinkedList::append(int value)
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
    node->previous = current;
    return head;
}

Node *DoublyLinkedList::delete_head()
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        head = nullptr;
        return head;
    }

    Node *temp = head;
    head = temp->next;
    head->previous = nullptr;
    temp->next = nullptr;
    free(temp);
    return head;
}

Node *DoublyLinkedList::delete_tail()
{
    if (head == NULL || head->next == NULL)
        return NULL;

    Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    Node *to_be_deleted = current;
    Node *tail = current->previous;
    current->previous = nullptr;
    tail->next = nullptr;
    free(to_be_deleted);
    return head;
}

Node *DoublyLinkedList::delete_element_at(int index)
{
    if (head == NULL)
        return NULL;
    if (index > 1 && head->next == NULL)
        return head;
    if (index == 1)
        return delete_head();

    Node *current = head;
    index--;
    while (current != NULL)
    {
        if (index == 0)
        {
            Node *prev = current->previous;
            Node *nxt = current->next;
            if (nxt == NULL)
            {
                return delete_tail();
            }
            prev->next = nxt;
            nxt->previous = prev;
            current->next = nullptr;
            current->previous = nullptr;
            free(current);
            return head;
        }
        current = current->next;
        index--;
    }
    return head;
}

Node *DoublyLinkedList::delete_value(int value)
{
    if (head == NULL)
        return NULL;

    Node *current = head;
    while (current != NULL)
    {
        if (current->data == value)
        {
            Node *prev = current->previous;
            Node *nxt = current->next;
            if (nxt == NULL)
                return delete_tail();
            prev->next = nxt;
            nxt->previous = prev;
            current->next = nullptr;
            current->previous = nullptr;
            delete current;
            return head;
        }
        current = current->next;
    }
    return head;
}

Node *DoublyLinkedList::insert_before_head(int value)
{
    Node *node = new Node(value);
    if (head == NULL)
    {
        head = node;
        return head;
    }

    node->next = head;
    head->previous = node;
    head = node;
    return head;
}

Node *DoublyLinkedList::insert_before_tail(int value)
{
    Node *node = new Node(value);
    if (head == NULL)
    {
        head = node;
        return head;
    }

    if (head->next == NULL)
    {
        return insert_before_head(value);
    }

    Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    Node *prev = current->previous;
    prev->next = node;
    node->previous = prev;
    node->next = current;
    current->previous = node;
    return head;
}

Node *DoublyLinkedList::insert_before_index(int index, int value)
{
    Node *node = new Node(value);
    if (head == NULL)
    {
        head = node;
        return head;
    }

    if (head->next == NULL && index == 1)
        return insert_before_head(value);

    if (head->next == NULL && index >= 2)
        return head;

    Node* current = head;
    int count=0;
    while(current != NULL){
        count++;
        if(count == index){
            Node* prev = current->previous;
            prev->next = node;
            node->previous = prev;
            node->next = current;
            current->previous = node;
            break;
        }
        current = current->next;
    }
    return head;
}

Node* DoublyLinkedList::reverse_list(){
    if(head==NULL || head->next == NULL) return head;
    Node* current = head;
    Node* tempNext = current;
    Node* tempPrev = current;
    while(current->next != NULL){
        //current = current->next;
        tempNext = current->next;
        tempPrev = current->previous;
        current->next = current->previous;
        current->previous = tempNext;
        current = tempNext;
    }
    tempNext = current->next;
    current->next = current->previous;
    current->previous = tempNext;
    head = current;
    return head;

}

void DoublyLinkedList::print()
{
    if (head == NULL)
    {
        cout << "Empty List" << endl;
        return;
    }

    Node *current = head;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}