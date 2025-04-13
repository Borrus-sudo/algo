export function combos(vectors: string[], dim: number, currIter = 2, currRes: string[] = [...vectors]): string[] {
    const res: string[] = [];
    currRes.forEach(val => res.push(...vectors.map(v => val + v)))
    if (currIter === dim) {
        return res;
    }
    return combos(vectors, dim, ++currIter, res)
}

export function combosWithBitManip(vectors: string[], dim: number) {
    const radix = vectors.length;
    let maxNumber = parseInt((radix - 1).toString().repeat(dim), radix)
    let res = [];
    while (maxNumber >= 0) {
        let thisCombo = [...maxNumber.toString(radix).padStart(dim, '0')].map(_ => vectors.at(+_)).join("")
        res.push(thisCombo)
        maxNumber--;
    }
    return res.reverse();

}

if (import.meta.main) {
    console.log(combos(['+', "*"], 3))
    console.log(combosWithBitManip(['+', '*'], 3))
}

