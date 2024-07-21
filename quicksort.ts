export function quickSort(arr: number[]): number[] {
    if (arr.length < 2) {
        return arr;
    }
    if (arr.length === 2) {
        return [Math.min(...arr), Math.max(...arr)];
    }
    const pivot = arr[Math.ceil(arr.length / 2)];
    const less: number[] = [],
        more: number[] = [],
        same: number[] = [];
    arr.forEach((elem) =>
        elem < pivot
            ? less.push(elem)
            : elem > pivot
            ? more.push(elem)
            : same.push(elem)
    );
    return [...quickSort(less), ...same, ...quickSort(more)];
}
