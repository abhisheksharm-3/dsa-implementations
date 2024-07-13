type Node<T> = {
    data: T;
    next: Node<T> | null;
    prev: Node<T> | null;
};

export default class DoublyLinkedList<T> {
    public length: number;
    private head: Node<T> | null;
    private tail: Node<T> | null;

    constructor() {
        this.length = 0;
        this.head = null;
        this.tail = null;
    }

    prepend(item: T): void {
        const newNode: Node<T> = { data: item, next: this.head, prev: null };
        if (this.head) {
            this.head.prev = newNode;
        } else {
            this.tail = newNode; // If the list was empty
        }
        this.head = newNode;
        this.length++;
    }

    insertAt(item: T, idx: number): void {
        if (idx < 0 || idx > this.length) {
            throw new Error("Index out of bounds");
        }

        if (idx === 0) {
            this.prepend(item);
            return;
        } else if (idx === this.length) {
            this.append(item);
            return;
        }

        let curr = this.head;
        for (let i = 0; i < idx; i++) {
            curr = curr!.next;
        }

        const newNode: Node<T> = { data: item, next: curr, prev: curr!.prev };
        if (curr!.prev) {
            curr!.prev.next = newNode;
        }
        curr!.prev = newNode;
        this.length++;
    }

    append(item: T): void {
        const newNode: Node<T> = { data: item, next: null, prev: this.tail };
        if (this.tail) {
            this.tail.next = newNode;
        } else {
            this.head = newNode; // If the list was empty
        }
        this.tail = newNode;
        this.length++;
    }

    remove(item: T): T | undefined {
        let curr = this.head;
        while (curr) {
            if (curr.data === item) {
                if (curr.prev) {
                    curr.prev.next = curr.next;
                } else {
                    this.head = curr.next; // Removing the head
                }

                if (curr.next) {
                    curr.next.prev = curr.prev;
                } else {
                    this.tail = curr.prev; // Removing the tail
                }

                this.length--;
                return curr.data;
            }
            curr = curr.next;
        }
        return undefined;
    }

    get(idx: number): T | undefined {
        if (idx < 0 || idx >= this.length) {
            return undefined;
        }

        let curr = this.head;
        for (let i = 0; i < idx; i++) {
            curr = curr!.next;
        }
        return curr?.data;
    }

    removeAt(idx: number): T | undefined {
        if (idx < 0 || idx >= this.length) {
            return undefined;
        }

        let curr = this.head;
        for (let i = 0; i < idx; i++) {
            curr = curr!.next;
        }

        if (curr) {
            if (curr.prev) {
                curr.prev.next = curr.next;
            } else {
                this.head = curr.next; // Removing the head
            }

            if (curr.next) {
                curr.next.prev = curr.prev;
            } else {
                this.tail = curr.prev; // Removing the tail
            }

            this.length--;
            return curr.data;
        }

        return undefined;
    }
}
