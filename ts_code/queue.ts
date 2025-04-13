export class ArrayQueue<T> {
    constructor(private list: T[] = []) {}
    enqueue(item: T) {
        this.list.push(item);
    }
    dequeue(): T {
        const payload = this.list[0];
        delete this.list[0];
        return payload;
    }
}

class Node<T> {
    next?: Node<T>;
    constructor(public value: T) {}
    append(node: Node<T>) {
        this.next = node;
    }
}

export class LinkedQueue<T> {
    private tail?: Node<T>;
    private head?: Node<T>;
    constructor() {}
    enqueue(value: T) {
        const next = new Node(value);
        if (!this.tail) {
            this.tail = next;
        } else if (!this.head) {
            this.head = next;
        } else {
            this.head.next = next;
            this.head = next;
        }
    }
    dequeue(): T {
        if (this.tail) {
            const payload = this.tail.value;
            this.tail = this.tail.next;
            return payload;
        } else if (this.head) {
            return this.head.value;
        } else {
            throw new Error('please input elements to dequeue them');
        }
    }
}
