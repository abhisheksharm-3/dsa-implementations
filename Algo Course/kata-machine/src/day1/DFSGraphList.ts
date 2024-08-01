function walk(
    graph: WeightedAdjacencyList,
    current: number,
    seen: boolean[],
    path: number[],
    needle: number,
): boolean {
    if (seen[current]) {
        return false;
    }
    seen[current] = true;
    path.push(current);
    if (current === needle) {
        return true;
    }

    const list = graph[current];
    for (let i = 0; i < list.length; i++) {
        const edge = list[i];
        if (walk(graph, edge.to, seen, path, needle)) {
            return true;
        }
    }

    path.pop();
    return false;
}

export default function dfs(
    graph: WeightedAdjacencyList,
    source: number,
    needle: number,
): number[] | null {
    const seen: boolean[] = new Array(graph.length).fill(false);
    const path: number[] = [];
    walk(graph, source, seen, path, needle);
    return path.length === 0 ? null : path;
}
