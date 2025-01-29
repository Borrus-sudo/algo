let matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]];

const transposedMatrix = matrix[0].flatMap((_, col) => [matrix.map(row => row[col])])
console.log(transposedMatrix)