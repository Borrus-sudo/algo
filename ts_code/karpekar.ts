

export function karperkar(input: number) {
    let payload = input * input;
    let left = 0, right = 0;
    const halfway = Math.floor(payload.toString().length / 2);
    [...payload.toString()].map(_ => +_).forEach((num, idx) => { if (idx + 1 <= halfway) { left = left * 10 + num; } else { right = right * 10 + num; } });
    return (left + right) === input;

}