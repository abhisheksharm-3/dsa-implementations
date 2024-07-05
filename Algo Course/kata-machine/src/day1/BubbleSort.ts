export default function bubble_sort(arr: number[]): void {
    let swapped = true;
    while (swapped) {
        swapped = false;
        let size = arr.length;
        for (let i = 1; i < size; i++) {
            if (arr[i - 1] > arr[i]) {
                const temp = arr[i - 1];
                arr[i - 1] = arr[i];
                arr[i] = temp;
                swapped = true;
            }
            if(swapped || size === 1){
                size--;
            }
        }
    }
}