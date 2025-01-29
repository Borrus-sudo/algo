function reverse<T>(arr: T[]): T[] {
    let high = arr.length - 1;
    let low = 0;
    while (high > low) {
        const temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        high--;
        low++;
    }
    return arr;
}

console.log(reverse([1, 2, 3, 4]))
console.log(reverse([1, 2, 3, 4, 5]))

