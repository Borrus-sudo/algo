class Vector {
    x;
    y;
    constructor(x, y) {
        this.x = x;
        this.y = y;
    }
    add(v) {
        this.x += v.x;
        this.y += v.y;
    }
    clockwise_rotation() {
        const [x, y] = [this.x, this.y];
        this.x = y;
        this.y = x * -1;
    }
}
const matrix = [
    [1, 2, 3, 4],
    [5, 6, 7, 8],
    [9, 10, 11, 12],
    [13, 14, 15, 16],
];
function spiral_print() {
    const dim = matrix.length * matrix[0].length;
    const len = matrix.length;
    console.log(dim);
    let counter = 0;
    const linear_order = [];
    const curr_pos = new Vector(0, 0);
    const add_vec = new Vector(0, 1);
    const visited = [];
    const within_limits = () => {
        if (curr_pos.x + add_vec.x > len - 1) return false;
        if (curr_pos.y + add_vec.y > len - 1) return false;
        if (curr_pos.x + add_vec.x < 0) return false;
        if (curr_pos.y + add_vec.y < 0) return false;
        if (
            visited.includes(
                (curr_pos.x + add_vec.x) * (dim + 2) + curr_pos.y + add_vec.y
            )
        )
            return false;
        return true;
    };
    while (++counter <= dim) {
        if (within_limits()) {
            linear_order.push(matrix[curr_pos.x][curr_pos.y]);
            visited.push(curr_pos.x * (dim + 2) + curr_pos.y);
            curr_pos.add(add_vec);
        } else {
            add_vec.clockwise_rotation();
            if (within_limits()) counter--;
        }
        // else
    }
    linear_order.push(matrix[curr_pos.x][curr_pos.y]);
}

spiral_print();
