function combos(initial: number): number[] {
    if (initial === 0)
        return [];
    if (initial === 1)
        return [10];
    let res: number[] = [];
    for (let i = 0; i < initial; i++) {
        res.push(initial * 10 + i);
        res = res.concat(combos(i).map(payload => Math.pow(10, payload.toString().length) * initial + payload))
    }
    return res;
}

if (import.meta.main) {
    console.log(combos(4))
}

