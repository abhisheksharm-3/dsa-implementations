function quick_sort_helper(arr: number[], low: number, high: number): void {
    if (low < high) {
        let pi = partition(arr, low, high);
        quick_sort_helper(arr, low, pi - 1);
        quick_sort_helper(arr, pi + 1, high);
    }
}

function partition(arr: number[], low: number, high: number): number {
    let pivot = arr[high];
    let i = low - 1;
    for (let j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            let temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    let temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}


export default function quick_sort(arr: number[]): void {
    quick_sort_helper(arr, 0, arr.length - 1);
}