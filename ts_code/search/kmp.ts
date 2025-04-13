export function kmp(pattern: string, text: string): number {
    // COMPUTE THE LPS
    let lps = [];
    lps[0] = 0;
    let i = 0;
    let j = 1;
    while (j < pattern.length) {
        if (pattern[i] === pattern[j]) {
            // match
            lps[j] = i;
        }

    }


}