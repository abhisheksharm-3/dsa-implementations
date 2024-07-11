type Point = { x: number; y: number };

const dir = [
    [-1, 0],
    [1, 0],
    [0, -1],
    [0, 1],
];

function walk(
    maze: string[],
    wall: string,
    curr: Point,
    end: Point,
    seen: boolean[][],
    path: Point[],
): boolean {
    // Base case: off the map
    if (curr.x < 0 || curr.x >= maze[0].length || curr.y < 0 || curr.y >= maze.length) {
        return false;
    }
    // Base case: on a wall
    if (maze[curr.y][curr.x] === wall) {
        return false;
    }
    // Base case: on the end
    if (curr.x === end.x && curr.y === end.y) {
        path.push(end);
        return true;
    }
    // Base case: already seen
    if (seen[curr.y][curr.x]) {
        return false;
    }

    // Mark the current spot
    seen[curr.y][curr.x] = true;
    path.push(curr);

    // Recurse in each direction
    for (let i = 0; i < dir.length; i++) {
        const next = { x: curr.x + dir[i][0], y: curr.y + dir[i][1] };
        if (walk(maze, wall, next, end, seen, path)) {
            return true;
        }
    }

    // Unmark the current spot (backtrack)
    path.pop();
    return false;
}

export default function solve(
    maze: string[],
    wall: string,
    start: Point,
    end: Point,
): Point[] {
    const seen: boolean[][] = Array.from({ length: maze.length }, () => Array(maze[0].length).fill(false));
    const path: Point[] = [];

    walk(maze, wall, start, end, seen, path);
    return path;
}
