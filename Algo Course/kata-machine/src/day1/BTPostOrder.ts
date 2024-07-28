function walk(current: BinaryNode<number> | null, result: number[]): number[] {
    if (!current) {
        return result;
    }

    walk(current.left, result);
    walk(current.right, result);
    result.push(current.value);
    return result;
}

export default function post_order_search(head: BinaryNode<number>): number[] {
    return walk(head, []);
}
