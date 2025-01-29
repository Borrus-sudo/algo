'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', (inputStdin) => {
    inputString += inputStdin;
});

process.stdin.on('end', (_) => {
    inputString = inputString
        .trim()
        .split('\n')
        .map((string) => {
            return string.trim();
        });
    main();
});

function readline() {
    return inputString[currentLine++];
}

function main() {
    const numberOfLines = parseInt(readline(), 10);
    for (let i = 1; i <= numberOfLines; i++) {
        const numbers = readline()
            .split(' ')
            .map((_) => parseInt(_, 10));
        // how to count max number of duplicates?
        const possibleValues = [
            numbers[0] + numbers[1],
            numbers[3] - numbers[1],
            numbers[4] - numbers[3],
        ];
        const set = new Set(possibleValues);
        console.log(possibleValues.length - set.size + 1);
    }
}
