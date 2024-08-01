type Node<T> = {
    value: T;
    next: Node<T> | undefined;
    prev: Node<T> | undefined;
};

function createNode<T>(value: T): Node<T> {
    return { value, next: undefined, prev: undefined };
}

export default class LRU<K, V> {
    private length: number;
    private head: Node<V> | undefined;
    private tail: Node<V> | undefined;

    private lookup: Map<K, Node<V>> = new Map();
    private reverseLookup: Map<Node<V>, K> = new Map();

    constructor(private capacity: number = 10) {
        this.length = 0;
        this.head = this.tail = undefined;
        this.lookup = new Map<K, Node<V>>();
        this.reverseLookup = new Map<Node<V>, K>();
    }

    update(key: K, value: V): void {
        let node = this.lookup.get(key);
        if (!node) {
            node = createNode(value);
            this.length++;
            this.prepend(node);
            this.trimCache();
            this.lookup.set(key, node);
            this.reverseLookup.set(node, key);
        } else {
            this.detach(node);
            this.prepend(node);
            node.value = value;
        }
    }
    get(key: K): V | undefined {
        const node = this.lookup.get(key);
        if (!node) {
            return undefined;
        }
        this.detach(node);
        this.prepend(node);

        return node.value;
    }

    private detach(node: Node<V>): void {
        if (node.prev) {
            node.prev.next = node.next;
        }
        if (node.next) {
            node.next.prev = node.prev;
        }
        if (this.length === 1) {
            this.head = this.tail = undefined;
        }
        if (this.head === node) {
            this.head = node.next;
        }
        if (this.tail === node) {
            this.tail = node.prev;
        }
        node.next = node.prev = undefined;
    }
    private prepend(node: Node<V>): void {
        if (!this.head) {
            this.head = this.tail = node;
        } else {
            node.next = this.head;
            this.head.prev = node;
            this.head = node;
        }
    }

    private trimCache(): void {
        if (this.length <= this.capacity) {
            return;
        }
        const node = this.tail;
        if (!node) {
            return;
        }
        this.detach(node);
        const key = this.reverseLookup.get(node);
        if (key) {
            this.lookup.delete(key);
            this.reverseLookup.delete(node);
            this.length--;
        }
    }
}
