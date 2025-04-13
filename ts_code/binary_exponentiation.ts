export function binaryExponentiate(a: number, b: number): number {
    if (b === 0)
        return 1;
    if (b & 1) {
        return a * binaryExponentiate(a, b / 2) ** 2;
    }
    else
        return (binaryExponentiate(a, Math.floor(b / 2)) ** 2)
}

export function normalExponentiate(a: number, b: number): number {
    let result = 1;
    while (b > 0) {
        result *= a;
        b--;
    }
    return result;
}

export function binaryExponentiate2(a: number, b: number): number {
    let result = 1;
    while (b > 0) {
        if (b & 1)
            result *= a;
        a *= a;
        b >>= 1;
    }
    return result;
}


if (import.meta.main) {
    const a = 13333332222;
    const b = 13333222233;

    console.time("binaryExponentiate")
    binaryExponentiate(a, b);
    console.timeEnd("binaryExponentiate")

    console.time("binaryExponentiate2")
    binaryExponentiate2(a, b);
    console.timeEnd("binaryExponentiate2")

    console.time("normalExponentiate")
    normalExponentiate(a, b);
    console.timeEnd("normalExponentiate")
}