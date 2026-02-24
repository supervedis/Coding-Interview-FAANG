class Node{
    constructor(value){
    this.value = value;
    this.next = null;
    }
}

class LinkedList{
    constructor(){
        this.head = null;
        this.tail = null;
        this.length = 0;
    }

    isEmpty(){ return this.length === 0;}
    size() {return this.length;}

    append(value){
        const new_node = new Node(value);

        if(!this.head){
            this.head = new_node;
            this.tail = new_node;
        }else{
            this.tail.next = new_node;
            this.tail = new_node;
        }

        this.length++;
        return this;
    }

    prepend(value){
        const node = new Node(value);
        if(!this.head){
            this.head = node;
            this.tail = node;
        }else{
            node.next = this.head;
            this.head = node;
        }

        this.length++;
        return this;
    }

    insert(index, value){
        if(index < 0 || index > this.length)
            throw new Error("Index out of bounds");

        if(index === 0) return this.prepend(value);
        if(index ===this.length)return this.append(value);

        const node = new Node(value);
        let current = this.head;
        for(let i=0; i < index - 1;i++){
            current = current.next;
        }

        node.next = current.next;
        current.next = node;
        this.length++;
        return this;
    }

    removeFirst(){
        if(!this.head) return null;
        const deleted_node = this.head;
        if(this.head === this.tail){
            this.head = null;
            this.tail = null;
        }else{
            this.head = this.head.next;
        }
        this.length--;
        return deleted_node.value;
    }

    removeLast(){
        if(!this.head) return null;
        let deleted_node = this.head;
        if(this.head === this.tail){
            this.head = null;
            this.tail = null;
            this.length--;
            return deleted_node.value;
        }

        let current = this.head;
        while(current.next !== this.tail){
            current = current.next;
        }
        deleted_node = this.tail;
        current.next = null;
        this.tail = current;
        this.length--;
        return deleted_node.value;
    }

    removeAt(index){
        if(index < 0 || index > this.length) throw new Error("Index Out Of Bounds");
        if(index === 1)
            return this.removeFirst();

        let current = this.head;
        for (let i = 1; i < index-1; i++) {
            current = current.next;
        }
        const to_delete = current.next;
        if(to_delete === this.tail){
            current.next = null;
            this.tail = current;
            return to_delete.value;
        }else{
            const to_link_to = to_delete.next;
            current.next = to_link_to;
        }
        return to_delete.value;
    }

    search(value){
        if(this.length >= 1 && value===this.head.value) return true;

        let current = this.head;
        for (let index = 0; index < this.length-1; index++) {
            current = current.next;
            if(current.value === value) return true;
        }
        return false;

    }

    get(index){
        index = index - 1;
        if(index < 0 || index > this.length) return null;

        let current = this.head;
        for (let i = 0; i < index; i++) {
            current = current.next;
        }
        return current.value;
    }

    indexOf(value){
        let current = this.head;
        if(!current) return -1;
        let count = 1;
        while(current){
            if(current.value === value) return count;
            count++;
            current = current.next;
        }
        return -1;
    }
    
    contains(value){
        return this.search(value);
    }

    set(index, value){
        return this.insert(index, value);
    }

    toArray(){
        const array = [];
        let current = this.head;
        while(current){
            array.push(current.value);
            current = current.next;
        }
        return array;
    }

    reverse(){
        if(!this.head || !this.head.next) return this; //Empyt or single element list.

        let previous = null;
        let current = this.head;
        let nextNode = current.next;
        this.tail = this.head;

        while(current){
            nextNode = current.next;
            current.next = previous;
            previous = current;
            current = nextNode;
        }
        this.head = previous;
    }

    display(){
        let values = [];
        let current = this.head;
        if(!this.head) return "Empty list";

        while(current){
            values.push(String(current.value));
            current = current.next;
        }
        return values.join("->")+"->null";
    }
}

const list = new LinkedList();
for (let index = 1; index < 20; index++) {
    list.append(index);
}

console.log(list.display());
// console.log(list.removeAt(10));
// console.log(list.display());
console.log(list.reverse());
console.log(list.display());