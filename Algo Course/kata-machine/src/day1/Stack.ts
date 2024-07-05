type StackNode<T> = { value: T; prev?: StackNode<T> };

export default class Stack<T> {
    public length: number;
    private head?: StackNode<T>;

    constructor() {
        this.length = 0;
        this.head = undefined;
    }

    push(item: T): void {
        const node = { value: item } as StackNode<T>;
        node.prev = this.head;
        this.head = node;
        this.length++;
    }
    pop(): T | undefined {
        let value = this.head?.value;
        this.head = this.head?.prev;
        if (value) {
            this.length--;
        }
        return value;
    }
    peek(): T | undefined {
        return this.head?.value;
    }
}
