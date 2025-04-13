export function search(
    text: string,
    pattern: string,
    vocabLength: number
): number {
    let numberOfInstances = 0;
    if (text.length < pattern.length) {
        return numberOfInstances;
    }
    const payload = hash(pattern, vocabLength);
    let rollingHash = -1;
    for (let i = 0; i <= text.length - pattern.length; i++) {
        const nextChunk = text.slice(i, i + pattern.length);
        if (rollingHash === -1) rollingHash = hash(nextChunk, vocabLength);
        else {
            rollingHash -=
                (text.codePointAt(i - 1) || 0) *
                Math.pow(vocabLength, pattern.length - 1);
            rollingHash *= vocabLength;
            rollingHash += text.codePointAt(i + pattern.length - 1) || 0;
        }
        if (rollingHash === payload) {
            if (pattern === nextChunk) {
                numberOfInstances++;
            }
        }
    }
    return numberOfInstances;
}

function hash(input: string, vocabLength: number) {
    let hash: number = 0;
    for (let i = 0; i < input.length; i++) {
        hash +=
            (input[i].codePointAt(0) || 0) *
            Math.pow(vocabLength, input.length - i - 1);
    }
    return hash;
}

function HelloWorld() {
    console.log("Hello World!!!!")
}