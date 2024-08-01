export default function bfs(graph: WeightedAdjacencyMatrix, source: number, needle: number): number[] | null {
    const seen = new Array(graph.length).fill(false);
    const prev = new Array(graph.length).fill(-1);

    seen[source] = true;
    const q: number[] = [source];
    while (q.length > 0) {
        const current = q.shift() as number;
        if (current === needle) {
            break;
        }
        for (let i = 0; i < graph.length; i++) {
            if (graph[current][i] !== 0 && !seen[i]) {
                seen[i] = true;
                prev[i] = current;
                q.push(i);
            }
        }
        seen[current] = true;
    }
    let current = needle;
    const path: number[] = [];


    while (prev[current] !== -1) {
        path.push(current);
        current = prev[current];
    }
    if (path.length === 0) {
        return null;
    }
    return [source, ...path.reverse()];
}