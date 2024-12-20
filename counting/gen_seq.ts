function combos(initial: number): number[] {
    if (initial === 1)
        return [10];
    let res: number[] = [];
    for (let i = 0; i < initial; i++)
        res.push(initial * 10 + i)
    return res.concat(combos(initial - 1).map(_ => _ + initial * Math.pow(10, _.toString().length)))

}

if (import.meta.main) {
    console.log(combos(4))
}

