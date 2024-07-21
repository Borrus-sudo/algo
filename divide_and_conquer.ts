// tail recursion (not supported!)
export function sumTailRecursive(arr: number[], total: number = 0): number {
    if (arr.length === 0) return 0;
    if (arr.length === 1) return arr[0] + total;
    return sumTailRecursive(arr.slice(1), arr[0] + total);
}

// normal recursion
export function sumNormalRecursive(arr: number[]): number {
    if (arr.length === 0) return 0;
    if (arr.length === 1) return arr[0];
    return arr[0] + sumNormalRecursive(arr.slice(1));
}

export function binarySearch(arr: number[]):number {
    return 1;
}


