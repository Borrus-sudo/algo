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

export function extendedEuclid(a: number, b: number, x: number = 0, y: number = 0): [number, number, number] {
    if (b == 0) {
        x = 1
        y = 0
        return [a, x, y];
    }
    const [ans, x1, y1] = extendedEuclid(b, a % b, x, y)
    x = y1;
    y = x1 - y1 * Math.floor(a / b);
    return [ans, x, y]
}


if (import.meta.main) {
    console.log(gcd(3, 9))
    console.log(gcd(9, 3))
    console.log(gcdNormalize(10, 15))
    console.log(lcm(10, 15))
    console.log(extendedEuclid(55, 80))
}