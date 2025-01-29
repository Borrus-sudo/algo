export function gcd(a: number, b: number): number {
    return b ? gcd(b, a % b) : a;
}

export function gcdNormalize(a: number, b: number): number {
    while (b) {
        a %= b;
        [a, b] = [b, a];
    }
    return a;
}

export function lcm(a: number, b: number) {
    return a / gcd(a, b) * b;
}


if (import.meta.main) {
    console.log(gcd(3, 9))
    console.log(gcd(9, 3))
    console.log(gcdNormalize(10, 15))
    console.log(lcm(10, 15))
}