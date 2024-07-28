function walk(current: BinaryNode<number> | null, result: number[]): number[] {
    if (!current) {
        return result;
    }
    walk(current.left, result);
    result.push(current.value);
    walk(current.right, result);
    return result;
}
export default function in_order_search(head: BinaryNode<number>): number[] {
    return walk(head, []);
}