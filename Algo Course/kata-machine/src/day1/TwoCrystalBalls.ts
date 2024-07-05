export default function two_crystal_balls(breaks: boolean[]): number {
    const jumpAmount = Math.floor(Math.sqrt(breaks.length));
    let current = jumpAmount;
    let previous = 0;
    while (current < breaks.length && !breaks[current]) {
        previous = current;
        current += jumpAmount;
    }
    for (let i = previous; i < current; i++) {
        if (breaks[i]) {
            console.log(i);
            
            return i;
        }
    }
    return -1;
}