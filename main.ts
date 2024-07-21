// import { Node, List } from './linkedlist.ts';
// import { selectionSort } from './selectionsort.ts';
import { sumTailRecursive, sumNormalRecursive } from './divide_and_conquer.ts';
import { quickSort } from './quicksort.ts';
import { selectionSort } from './selectionsort.ts';
import { LinkedQueue, ArrayQueue } from './queue.ts';

// const createNode = <T>(value: T) => new Node<T>(value);

// const list = new List();

// for (let i = 0; i <= 10; i++) {
//     list.insert(createNode('todo ' + (i + 1)));
// }

// for (const todo of list.traverse()) {
//     console.log('✔ ' + todo.value);
// }

// for (const todo of list.traverse()) {
//     console.log('✔ ' + todo.value);
// }

const range = {
    start: 1,
    *[Symbol.iterator](end: number = 900000000) {
        let counter = this.start;
        while (counter !== end) {
            yield Math.floor(Math.random() * end);
            counter++;
        }
        yield Math.floor(Math.random() * end);
    },
};

// const sameArray1 = [...range];
// const sameArray2 = [...sameArray1];

// console.time('Benchmark Quicksort');
// console.log(quickSort(sameArray1));
// console.timeEnd('Benchmark Quicksort');

// console.time('Benchmark Mergesort');
// console.log(selectionSort(sameArray2));
// console.timeEnd('Benchmark Mergesort');

// console.time('Benchmark Normal');
// console.log(sumNormalRecursive([...range]));
// console.timeEnd('Benchmark Normal');
// console.time('Benchmark Tail');
// console.log(sumTailRecursive([...range]));
// console.timeEnd('Benchmark Tail');

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
