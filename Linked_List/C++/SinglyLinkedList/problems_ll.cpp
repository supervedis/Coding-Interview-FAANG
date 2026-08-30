#include "problems_ll.h"
#include <math.h>
#include<map>

int reverse_number(int);
int extract_digit(Node *);
LinkedList *append_sum(int);
void create_node(Node *head, Node *&curr);

LinkedList *add_LL_and_reverse(LinkedList l1, LinkedList l2)
{
    Node *head1 = l1.getHead();
    Node *head2 = l2.getHead();
    if (head1 == NULL && head2 == NULL)
        return NULL;

    int number1 = 0;
    int number2 = 0;
    if (head1 == NULL || head2 == NULL)
        return NULL;

    number1 = extract_digit(head1);
    number2 = extract_digit(head2);

    cout << "number1: " << number1 << " number2: " << number2 << " number1 + number2 = " << number1 + number2 << endl;
    int sum = number1 + number2;
    LinkedList *list = append_sum(sum);
    return list;
}

int extract_digit(Node *list)
{
    int number = 0;
    while (list != NULL)
    {
        number = number * 10 + list->data;
        list = list->next;
    }
    number = reverse_number(number);
    return number;
}

int reverse_number(int n)
{
    int number = 0;
    int pow = 0;
    int ten_pow = 0;
    float powers_of_ten = 10;
    while (n != 0)
    {
        number = number * 10 + n % 10;
        n = n / 10;
        ten_pow = powf(powers_of_ten, pow);
        pow++;
    }

    return number;
}

int sum_divider(int n)
{
    int pow = 0;
    int ten_pow = 0;
    float powers_of_ten = 10;
    while (n != 0)
    {
        n = n / 10;
        ten_pow = powf(powers_of_ten, pow);
        pow++;
    }

    return ten_pow;
}

LinkedList *append_sum(int sum)
{
    int divisor = sum_divider(sum);
    int digit = 0;
    LinkedList *list = new LinkedList();
    while (sum != 0)
    {
        digit = sum / divisor;
        sum = sum % divisor;
        divisor = divisor / 10;
        (*list).append(digit);
    }
    return list;
}

LinkedList *sum_LL(Node *head1, Node *head2)
{
    Node *dummy = new Node(-1);
    Node *current = dummy;
    LinkedList *list = new LinkedList();
    int carry = 0;
    int sum = 0;
    while (head1 != NULL || head2 != NULL)
    {
        sum = carry;
        if (head1)
            sum += head1->data;
        if (head2)
            sum += head2->data;
        // Node* node = new Node(sum%10);
        list->append(sum % 10);
        carry = sum / 10;
        /*  current->next = node;
         current = node; */
        if (head1)
            head1 = head1->next;
        if (head2)
            head2 = head2->next;
    }

    if (carry)
        list->append(carry);
    return list;
}

Node *group_odd_even(Node *head)
{
    Node *dummyOdd = new Node(-1);
    Node *dummyEven = new Node(-1);
    Node *currOdd = dummyOdd;
    Node *currEven = dummyEven;
    int counter = 1;
    while (head != NULL)
    {
        if (counter % 2 == 0)
            create_node(head, currEven);
        else
            create_node(head, currOdd);
        head = head->next;
        counter++;
    }
    cout << endl;
    currOdd->next = dummyEven->next;
    return dummyOdd->next;
}

void create_node(Node *head, Node *&curr)
{
    int value = head->data;
    Node *node = new Node(value);
    curr->next = node;
    curr = node;
}

Node *group_odd_even_rev(Node *head)
{
    Node *temp = head;
    vector<int> lst;
    while (temp != NULL && temp->next != NULL)
    {
        lst.push_back(temp->data);
        temp = temp->next->next;
    }

    if (temp)
        lst.push_back(temp->data);
    temp = head->next;

    while (temp != NULL && temp->next != NULL)
    {
        lst.push_back(temp->data);
        temp = temp->next->next;
    }
    if (temp)
        lst.push_back(temp->data);

    temp = head;
    for (size_t i = 0; i < lst.size(); i++)
    {
        temp->data = lst[i];
        temp = temp->next;
    }
    return head;
}

Node *group_odd_even_rev_two(Node *head)
{
    Node *odd = head;
    Node *even = head->next;
    Node *even_start = head->next;
    while (even != NULL && even->next != NULL)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }

    odd->next = even_start;
    return head;
}

/*BEGIN:================================================================================
Sort the given Linked List consisting of only 0's, 1's and 2's into 0's, 1's and 2's*/

Node *sort_LL_OfZeros_OnesTwos(Node *head)
{
    if (head == NULL)
        return head;

    Node *iter = head;
    Node *zeroStart = new Node(-1);
    Node *zero = zeroStart;
    Node *oneStart = new Node(-1);
    Node *one = oneStart;
    Node *twoStart = new Node(-1);
    Node *two = twoStart;
    int data = 0;
    while (iter != NULL)
    {
        data = iter->data;
        if (data == 0)
        {
            link_like_data(iter, zero);
        }

        if (data == 1)
        {
            link_like_data(iter, one);
        }

        if (data == 2)
        {
            link_like_data(iter, two);
        }
        iter = iter->next;
    }

    // zeroStart = zeroStart->next;
    oneStart = oneStart->next;
    twoStart = twoStart->next;
    zero->next = oneStart ? oneStart : twoStart;
    one->next = twoStart;
    two->next = nullptr;
    zeroStart = zeroStart->next;
    head = zeroStart;
    return head;
}

void link_like_data(Node *iter, Node *&data)
{
    data->next = iter;
    data = data->next;
}

/*========================================================================================:END*/

/*Delete the nth node from the end of the linked list.*/
Node *delete_nth_node_from_end(Node *head, int index)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *slow = head;
    Node *fast = head;

    for (int i = 0; i < index; i++)
    {
        fast = fast->next;
    }

    if (fast == NULL)
        return head->next;

    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    Node *to_delete = slow->next;
    slow->next = to_delete->next;
    delete to_delete;
    return head;
}
/*====================================================*/

/*Reverse a linked list*/
Node *reverse_linked_list(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *prev = nullptr;
    Node *front = nullptr;
    Node *temp = head;
    while (temp != NULL)
    {
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }

    head = prev;
    return head;
}

Node *reverse_LL_recursively(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *new_head = reverse_LL_recursively(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = nullptr;
    return new_head;
}
/*====================================================*/

/*Check if Linked List is a palindrome.*/
bool is_LL_palindrome(Node *head)
{
    if (head == NULL || head->next == NULL)
        return true;
    Node *slow = head;
    Node *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *new_head = reverse_LL_recursively(slow->next);
    Node *iter = new_head;
    slow = head;
    while (iter != NULL)
    {
        if (slow->data != iter->data)
        {
            reverse_LL_recursively(new_head);
            return false;
        }

        iter = iter->next;
        slow = slow->next;
    }

    reverse_LL_recursively(new_head);
    return true;
}
/*==========================================END*/

/*Add to a number stored in a linked list
   input: 1->2->3->4
   output: i->2->3->5

   input: 1->2->3->9
   output: 1->2->4->0
    */

Node *add_one_to_LL(Node *head)
{
    if (head == NULL)
        return head;
    LinkedList *list = new LinkedList();
    int sum = 0;
    int carry = 1;
    head = reverse_linked_list(head);
    Node *temp = head;
    while (temp != NULL)
    {
        sum = carry;
        if (temp)
            sum += temp->data;
        // list->append(sum%10);
        temp->data = sum % 10;
        carry = sum / 10;
        if (!carry)
            break;
        temp = temp->next;
    }
    if (carry)
    {
        Node *node = new Node(carry);
        head = reverse_linked_list(head);
        node->next = head;
        head = node;
        return head;
    }
    head = reverse_linked_list(head);
    return head;
}
/*===========================================END*/

/*Add one to a number stored in a linked list using recursion to avoid reversing the bumber before addition
   input: 1->2->3->4
   output: i->2->3->5

   input: 1->2->3->9
   output: 1->2->4->0
    */

int add_one_helper(Node *head)
{
    if (head == NULL)
        return 1;
    int carry = add_one_helper(head->next);
    int sum = head->data + carry;
    head->data = sum % 10;
    carry = sum / 10;
    return carry;
}

Node *add_one_to_LL_recursive(Node *head)
{
    int carry = add_one_helper(head);
    if (carry)
    {
        Node *node = new Node(carry);
        node->next = head;
        return node;
    }
    return head;
}
/*===========================================END*/

/*Find the node at the intersection of two linked Lists
   Input:
     1->2->3
            \
             4->7->8->9->null
            /
        5->6

   Output:
      4
     */

Node* collision_point(Node* temp, Node* temp2, int len){
    for (size_t i = 0; i < len; i++)
            temp = temp->next;
        while (temp != NULL)
        {
            if (temp == temp2)
                return temp;
            temp = temp->next;
            temp2 = temp2->next;
        }
        return nullptr;
}

Node *find_intercesction_of_YLL(Node *head1, Node *head2)
{
    if (head1 == head2)
        return head1;
    if (head1 == NULL || head2 == NULL)
        return NULL;

    int len_h1 = 0;
    Node *temp = head1;
    while (temp != NULL)
    {
        len_h1++;
        temp = temp->next;
    }

    int len_h2 = 0;
    temp = head2;
    while (temp != NULL)
    {
        len_h2++;
        temp = temp->next;
    }

    if (len_h1 == len_h2)
    {
        Node *temp2 = head2;
        temp = head1;
        return collision_point(temp, temp2, len_h1);
    }
    else if (len_h1 < len_h2)
    {
        Node *temp2 = head2;
        temp = head1;
        int len = len_h2 - len_h1;
        return collision_point(temp, temp2, len);
    }else
    {
        Node *temp2 = head2;
        temp = head1;
        int len = len_h1 - len_h2;
        return collision_point(temp, temp2, len);
    }
    return NULL;
}


Node* find_intercesction_of_YLL_Revised(Node* head1, Node* head2){
    if (head1 == head2)
        return head1;
    if (head1 == NULL || head2 == NULL)
        return NULL;

    Node* temp = head1;
    Node* temp2 = head2;

    while(temp != temp2){
        temp = temp->next;
        temp2 = temp2->next;
        //if(temp == temp2) return temp;
        if(temp==NULL) temp = head2;
        if(temp2 == NULL) temp2 = head1;
    }
    return temp;
}
/*===================================================END*/

/*Find the middle of a given linked list*/
Node* find_middle_of_LL(Node* head){
    if(head == NULL || head->next==NULL) return head;
    Node* slow = head;
    Node* fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
/*===================================================END*/

/*Detect loop in a Linked List*/

bool is_cycle_in_LL(Node* head){
    if(head == NULL || head->next==NULL) return head;
    Node* slow = head;
    Node* fast = head;
    while (fast!= NULL && fast->next != NULL)
    {
        if(slow==fast) return true;
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}
/*===================================================END*/

/*Find the length of a loop in a linked list*/
int count_length(Node* slow, Node* fast){
    int counter = 0;
    fast = fast->next;
    while(fast != slow){
        counter++;
        fast = fast->next;
    }
    return counter;
}

int find_length_of_loop_in_LL(Node* head){
    if(head == NULL || head->next == NULL) return 0;
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow)
            return count_length(slow,fast);
    }
    return 0;
}
/*===================================================END*/

/*Delete the middle node of a Linked List.*/
Node* delete_mid_node_of_LL(Node* head){
    if(head == NULL || head->next == NULL) return NULL;

    Node* fast = head;
    Node* slow = head;
    Node* prev = slow;
    while (fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if(slow->next != NULL){
        prev->next = slow->next;
        Node* temp = slow;
        free(temp);
    }
    return head;
}
/*===================================================END*/

/*Find the starting point a cyclic Linked List.*/

Node* get_meeting_point(Node* slow, Node* fast){
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

Node* find_starting_point_of_cyclic_LL(Node* head){
    if(head == NULL || head->next == NULL) return NULL;

    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            slow = head;
            return get_meeting_point(slow,fast);
        }
    }
    
    return NULL;
}
/*===================================================END*/

/*Reverse Nodes in K groups.*/
Node* reverse_nodes_in_k_group(Node* head, int k){
    if(head == NULL || head->next == NULL) return head;
    Node* temp = head;
    Node* new_head = nullptr;
    Node* old_head = nullptr;
    while(temp != NULL){
        Node* end_node = temp;
        int i=1;
        while(i < k && end_node->next != NULL){
            end_node = end_node->next;
            i++;
        }
        Node* next_node = end_node->next;
        end_node->next = nullptr;
        new_head  = i == 3 ? reverse_linked_list(temp) : temp;
        if(temp==head) head = new_head;
        else old_head->next = new_head;
        old_head = temp;
        temp = next_node;
    }
    return head;
}
/*===================================================END*/

/*Rotate a Linked List by K number of times*/

Node* findKthPosition(Node* head, int k){
    int counter = 0;
    while (head != NULL)
    {
        counter++;
        if(counter == k) return head;
        head = head->next;
    }
    return NULL;
}

Node* rotate_a_LL_by_K(Node* head, int k){
    if(head == NULL || head->next == NULL) return head;

    Node* old_head = head;
    Node* iter = head;
    int size = 1;
    while(iter->next != NULL){
        size++;
        iter = iter->next;
    }

    int kth_position = k % size;
    if(kth_position == 0) return head;

    Node* tail = findKthPosition(head, size-kth_position);
    iter->next = head;
    head = tail->next;
    tail->next = NULL;
    /*int counter = 0;
    iter = head;

    while (iter != NULL)
    {
        counter++;
        if(counter == kth_position){
            Node* temp = iter;
            head = temp->next;
            while(iter->next !=  NULL){
                iter = iter->next;
            }

            temp->next = nullptr;
            iter->next = old_head;
            break;
        }
        iter = iter->next;
    }*/
    return head;
}
/*===================================================END*/

/*Merge two sorted Linked Lists and leave them in ascending order*/
Node* merge_two_sorted_LL(Node* l1, Node* l2){
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;

    Node* temp_l1 = l1;
    Node* temp_l2 = l2;
    Node* head_l1 = l1;
    Node* head_l2 = l2;
    Node* iter = temp_l1->data <= temp_l2->data ? temp_l1 : temp_l2;

    while (temp_l1 != NULL && temp_l2 != NULL)
    {
        if(temp_l1->data <= temp_l2->data){
            temp_l1 = temp_l1->next;
            iter->next = temp_l2;
            iter = temp_l2;
        }else
        {
            temp_l2 = temp_l2->next;
            iter->next = temp_l1;
            iter = temp_l1;
        }
        
    }
    return head_l1 <= head_l2 ? head_l1 : head_l2;
    
}
/*============================================================END*/