export default class MinHeap {
    public length: number;
    private heap: number[];

    

    constructor() {
        this.length = 0;
        this.heap = [];
    }

    insert(value: number): void {
        this.heap[this.length] = value;
        this.heapifyUp(this.length);
        this.length++;
    }

    delete(): number {
        const min = this.heap[0];
        this.heap[0] = this.heap[this.length - 1];
        this.heapifyDown(0);
        this.length--;
        return min;
    }
private parent(index: number): number {
    return Math.floor((index - 1) / 2);
}
private leftChild(index: number): number {
    return 2 * index + 1;
}
private rightChild(index: number): number {
    return 2 * index + 2;
}
private heapifyUp(index: number): void {
    let currentIndex = index;
    while (currentIndex > 0 && this.heap[currentIndex] < this.heap[this.parent(currentIndex)]) {
        [this.heap[currentIndex], this.heap[this.parent(currentIndex)]] = [this.heap[this.parent(currentIndex)], this.heap[currentIndex]];
        currentIndex = this.parent(currentIndex);
    }
}
private heapifyDown(index: number): void {
    let currentIndex = index;
    while (this.leftChild(currentIndex) < this.length) {
        let smallerChildIndex = this.leftChild(currentIndex);
        if (this.rightChild(currentIndex) < this.length && this.heap[this.rightChild(currentIndex)] < this.heap[this.leftChild(currentIndex)]) {
            smallerChildIndex = this.rightChild(currentIndex);
        }
        if (this.heap[currentIndex] < this.heap[smallerChildIndex]) {
            break;
        }
        [this.heap[currentIndex], this.heap[smallerChildIndex]] = [this.heap[smallerChildIndex], this.heap[currentIndex]];
        currentIndex = smallerChildIndex;
    }
}
}