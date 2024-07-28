function walk(current: BinaryNode<number> | null, result: number[]): number[] {
    if (!current) {
        return result;
    }
    result.push(current.value);
    walk(current.left, result);
    walk(current.right, result);
    return result;
}

export default function pre_order_search(head: BinaryNode<number>): number[] {
    return walk(head, []);
}
