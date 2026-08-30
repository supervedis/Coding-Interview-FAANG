#include "problems.h"

Node *delete_Key_InDLL(Node *head, int key)
{
    if (head != NULL && head->next == NULL && head->data == key)
        return NULL;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            if (temp == head)
            {
                head = head->next;
            }
            Node *prev_node = temp->previous;
            Node *next_node = temp->next;

            if (next_node)
                next_node->previous = prev_node;
            if (prev_node)
                prev_node->next = next_node;

            delete temp;
            temp = next_node;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}

/*Find all Pairs with given sum in Dynamic Linked List*/
vector<tuple<int, int>> find_pairs_with_sum_inDLL(Node *head, int sum)
{
    vector<tuple<int, int>> pairs;
    if (head == NULL || head->next == NULL)
    {
        tuple<int, int> pair(0, 0);
        pairs.push_back(pair);
        return pairs;
    }
    Node *right = head;
    for (; right->next != NULL; right = right->next)
        ;

    Node *left = head;
    while (right->data >= left->data)
    {
        if (left->data + right->data == sum)
        {
            tuple<int, int> pair(left->data, right->data);
            pairs.push_back(pair);
            left = left->next;
            right = right->previous;
        }
        else if (left->data + right->data < sum)
        {
            left = left->next;
        }
        else
            right = right->previous;
    }
    return pairs;
}
//======================================================END

/*Remove duplicate nodes from a sorted Dynamically Linked List*/
Node* remove_duplicates_from_DLL(Node* head){
    if(head == NULL || head->next == NULL) return head;
    
    Node* prev = head;
    Node* temp = head->next;
    while (temp != NULL)
    {
        if(prev->data != temp->data){
            prev->next = temp;
            temp->previous = prev;
            prev = temp;
            temp = temp->next;
        }else{
            Node* to_delete = temp;
            temp = temp->next;
            if(temp == NULL) prev->next = nullptr;
            delete to_delete;
        }
    }
    return head;
}

Node* remove_duplicates_from_DLL_Sol2(Node* head){
    if(head == NULL || head->next == NULL) return head;
    
    Node* prev = head;
    while (prev != NULL && prev->next != NULL)
    {
        Node* temp = prev->next;
        while (temp != NULL && temp->data == prev->data)
        {
            Node* duplicate = temp;
            temp = temp->next;
            delete duplicate;
        }
        prev->next = temp;
        if(temp) temp->previous = prev;
        prev = prev->next;
    }
    return head;
}
//======================================================END