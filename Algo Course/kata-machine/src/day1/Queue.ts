type QueueNode<T> = { value: T; next?: QueueNode<T> };
export default class Queue<T> {
    public length: number;
    private head?: QueueNode<T>;
    private tail?: QueueNode<T>;

    constructor() {
        this.head = this.tail = undefined;
        this.length = 0;
    }

    enqueue(item: T): void {
        const node = { value: item } as QueueNode<T>;
        if (!this.tail) {
            this.head = this.tail = node;
        } else {
            this.tail.next = node;
            this.tail = node;
        }
        this.length++;
    }
    deque(): T | undefined {
        if (this.head === undefined) {
            return undefined;
        }
        this.length--;
        const value = this.head.value;
        this.head = this.head.next;
        return value;
    }
    peek(): T | undefined {
        return this.head?.value;
    }
}
