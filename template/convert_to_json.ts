const text = await Deno.readTextFile('./payload.cpp');
const lines = text
    .split('\n')
    .map((_) => _.trimEnd())
    .filter((_) => _ != '\n');
const output = JSON.stringify(lines);
await Deno.writeTextFile('./output.json', output);
