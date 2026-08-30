class Node:
    def __init__(self, value):
        self.value = value
        self.next = None
        self.previous = None


class DoublyLinkedList:
    def __init__(self):
        self.head = None

    def append(self, value):
        node = Node(value)

        if not self.head:
            node.previous = None
            self.head = node
            return
        current = self.head
        while current.next:
            current = current.next
        node.previous = current
        current.next = node


    def display_forward(self):
        values = []
        current = self.head
        previous = None
        if not current:
            print("Empty List")
            return
        while current:
            value = current.value
            values.append(str(value))
            previous = current
            current = current.next
        self.head = previous
        return "->".join(values)+"->null"
    
    def display_reverse(self):
        values = []
        current = self.head
        if not current:
            print("Empty List")
            return
        while current:
            value = current.value
            values.append(str(value))
            current = current.previous
        return "->".join(values)+"->null"
    
if __name__ == '__main__':
    doubly_list = DoublyLinkedList()
    for i in range(20):
        doubly_list.append(i)
    print(doubly_list.display_forward())
    print(doubly_list.display_reverse())