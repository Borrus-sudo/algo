export function lineThroughPoints(points: number[][]) {
    // Write your code here.
    const cache: Map<string, number[]> = new Map();
    let computed = {};
    let result = 0;
    for (let i = 0; i < points.length; i++) {
        for (let j = i + 1; j < points.length; j++) {
            const [x1, y1] = points[i];
            const [x2, y2] = points[j];
            let slope = (y2 - y1) / (x2 - x1);
            if (computed[slope]) {
                // check if there is a common point between them
            } else {
                cache.set(points[j].toString() + slope, points[i]);
                computed[slope] = true;
            }
        }
    }
    return result;
}
