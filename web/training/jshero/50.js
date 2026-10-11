function addWithSurcharge(first, second) {
    return first + second + (first > 10 ? (first > 20 ? 3 : 2) : 1) + (second > 10 ? (second > 20 ? 3 : 2) : 1)
}

console.log(addWithSurcharge(10, 30));