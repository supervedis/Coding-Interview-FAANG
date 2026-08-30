#include "problems_ll.h"
// #include<iostream>

/*Add the contents in reverse a two different linked list that stores integers and return a linked list with containint the sum in reverse
with the contents being each digit in the sum.
 input 1: 1->2->3->null becomes 3->2->1-
 input 2: 4->5->6->null

 reverse list then add:
   321+654 = 975

output: 9->7->5->null*/

int main()
{
    LinkedList list1;
    LinkedList list2;
    LinkedList list3;
    
    list1.append(1);list1.append(3);list1.append(5);
    list2.append(2);list2.append(4);list2.append(6);list2.append(8);
    //list1.append(1);list1.append(2);list1.append(3);list1.append(4);//list1.append(5);list1.append(6);list1.append(7);list1.append(8);
    /*list2.append(6);list2.append(7);list2.append(8);list2.append(list1.getHead());*/
    /* list3.append(4);list3.append(7);list3.append(8);list3.append(9);
    list1.append(list3.getHead());
    list2.append(list3.getHead()); */

     //list1.append(9); list1.append(9); list1.append(9); 
     /*list1.append(9);
    list2.append(3); list2.append(5);
     LinkedList* list3 = sum_LL(list1.getHead(), list2.getHead());
     (*list3).print(); */
    /*  for (size_t i = 1; i < 6; i++)
    {
        list1.append(i);
    } */
    // list1.append(1);
    // list1.append(2);
    // list1.append(3);
    // //list1.append(3);
    // list1.append(2);
    // list1.append(1);
    // //list1.append(1);
    //list1.print();
    /* list2.print();
    list3.print(); */
    //Node *head = group_odd_even_rev_two(list1.getHead());
    //Node* head = sort_LL_OfZeros_OnesTwos(list1.getHead());
    //Node* head = delete_nth_node_from_end(list1.getHead(),5);
    //Node* head = reverse_LL_recursively(list1.getHead());
    //string palindrome = is_LL_palindrome(list1.getHead()) ? "YES" : "NO";
    //cout<<"Is this a palindrome? "<< palindrome<<endl;
    //Node* head = add_one_to_LL(list1.getHead());
    //Node* node = find_intercesction_of_YLL_Revised(list1.getHead(), list2.getHead());
    //Node* node = find_middle_of_LL(list1.getHead());
    //string is_cyclic = is_cycle_in_LL(list1.getHead())?"Cyclic Linked List":"Non-Cyclic Linked List.";
    //Node* deleted_node = delete_mid_node_of_LL(list1.getHead());
    //Node* starting_point = find_starting_point_of_cyclic_LL(list2.getHead());
    //cout<<starting_point->data<<endl;
    list1.print();
    list2.print();
    //Node* new_head = reverse_nodes_in_k_group(list1.getHead(),3);
    //list1.setHead(new_head);
    //Node* head = rotate_a_LL_by_K(list1.getHead(), 3);
    //list1.setHead(head);
    //list1.print();
    Node* head = merge_two_sorted_LL(list1.getHead(), list2.getHead());
    
     while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    } 
    cout << endl;
    /*// Node* head = list.getHead();
    // list.remove_head();
    // list.delete_tail();
    // list.delete_at_index(2);
    // list.delete_element(1);
    // list.insert_at_head(1);
    // list.insert_at_tail(3);
    // list.insert_at_index(4,7);
    // list.insert_before_value(5,9);
    // list.print();*/
    return 0;
}