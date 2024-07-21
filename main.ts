import { sumTailRecursive, sumNormalRecursive } from './divide_and_conquer.ts';
import { quickSort } from './quicksort.ts';
import { selectionSort } from './selectionsort.ts';
import { LinkedQueue, ArrayQueue } from './queue.ts';

const range = {
    start: 1,
    *[Symbol.iterator](end: number = 90000) {
        let counter = this.start;
        while (counter !== end) {
            yield Math.floor(Math.random() * end);
            counter++;
        }
        yield Math.floor(Math.random() * end);
    },
};

const input1 = [...range];
const input2 = [...input1];

/**
 * -----------------------------------------------
 *  SORTING ALGORITHMS CHECK
 * -----------------------------------------------
 */

console.time('Benchmark Quicksort');
console.log(quickSort(input1));
console.timeEnd('Benchmark Quicksort');

console.time('Benchmark Mergesort');
console.log(selectionSort(input2));
console.timeEnd('Benchmark Mergesort');

/**
 * -----------------------------------------------
 *  TAIL RECURSION IMPLEMENTATION CHECK
 * -----------------------------------------------
 */

console.time('Benchmark Normal Recursion');
sumNormalRecursive([...range[Symbol.iterator](7000)]);
console.timeEnd('Benchmark Normal Recursion');

console.time('Benchmark Tail Recursion check');
sumTailRecursive([...range[Symbol.iterator](7000)]);
console.timeEnd('Benchmark Tail Recursion check');

/**
 * ---------------------------------------------------
 *  LinkedList vs Array IMPLEMENTATION CHECK for Queue
 * ---------------------------------------------------
 */

console.time('Benchmark Linked');
const linkedQueue = new LinkedQueue();
for (const number of range) {
    linkedQueue.enqueue(number);
}
for (const _ of range) {
    linkedQueue.dequeue();
}
console.timeEnd('Benchmark Linked');

console.time('Benchmark Array');
const arrayQueue = new ArrayQueue();
for (const number of range) {
    arrayQueue.enqueue(number);
}
for (const _ of range) {
    arrayQueue.dequeue();
}
console.timeEnd('Benchmark Array');
