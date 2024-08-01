function hasUnvisited(seen: boolean[], dist: number[]): boolean {
    return seen.some((v, i) => !v && dist[i] !== Infinity);
}

function getLowestUnvisited(seen: boolean[], dist: number[]): number {
    let min = Infinity;
    let minIndex = -1;
    for (let i = 0; i < dist.length; i++) {
        if (!seen[i] && dist[i] < min) {
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

export default function dijkstra_list(source: number, sink: number, arr: WeightedAdjacencyList): number[] {
    const seen = new Array(arr.length).fill(false);
    const prev = new Array(arr.length).fill(-1);
    const dist = new Array(arr.length).fill(Infinity);
    dist[source] = 0;
    while (hasUnvisited(seen, dist)) {
        const current = getLowestUnvisited(seen, dist);
        seen[current] = true;
        const neighbors = arr[current];
        for(let i = 0; i < neighbors.length; i++) {
            const edge = neighbors[i];
            if (seen[edge.to]) {
                continue;
            }
            const newDist = dist[current] + edge.weight;
            if (newDist < dist[edge.to]) {
                dist[edge.to] = newDist;
                prev[edge.to] = current;
            }
        }
    }
    const path = [];
    let current = sink;
    while (prev[current] !== -1) {
        path.push(current);
        current = prev[current];
    }
    return [source, ...path.reverse()];
}