class Node:
    def __init__(self, value):
        self.value = value
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    def append(self, value):
        new_node = Node(value)

        if not self.head:
            self.head = new_node
            return
        current = self.head
        while current.next:
            current = current.next
        current.next = new_node
    
    def display(self):
        values = []
        current = self.head
        while(current):
            values.append(str(current.value))
            current = current.next
        return "->".join(values)+"->null"
    
    def reverse_list(self):
        previous = None
        current = self.head
        next_node = None
        while(current):
            next_node = current.next
            current.next = previous
            previous = current
            current = next_node
        self.head = previous

if __name__=='__main__':
    linked_list = LinkedList()
    for i in range(1,6):
        linked_list.append(i)
    print(linked_list.display())
    linked_list.reverse_list()
    print(linked_list.display())
