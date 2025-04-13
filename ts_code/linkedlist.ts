export class Node<T> {
    constructor(public value: T, public next?: Node<T>) { }
    append(next: Node<T>) {
        this.next = next;
    }
}

export class List<T> {
    private head?: Node<T>;
    constructor(private node?: Node<T>) {
        if (this.node) {
            this.head = this.node;
        }
    }
    *traverse() {
        let currNode = this.head;
        while (currNode?.next) {
            yield currNode;
            currNode = currNode.next;
        }
        return currNode;
    }
    append(newNode: Node<T>) {
        if (this.node) {
            this.node.append(newNode);
            this.node = newNode;
        } else {
            this.node = newNode;
            this.head = this.node;
        }
    }
}
