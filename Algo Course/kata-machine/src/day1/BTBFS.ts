export default function bfs(head: BinaryNode<number>, needle: number): boolean {
    const queue: BinaryNode<number>[] = [head];
    while (queue.length > 0) {
        const current = queue.shift();
        if (!current) {
            continue;
        }
        if (current.value === needle) {
            return true;
        }
        if (current.left !== null) {
            queue.push(current.left);
        }
        if (current.right !== null) {
            queue.push(current.right);
        }
    }
    return false;
}