function addWithSurcharge(first, second) {
    return first + second + (first > 10 ? 2 : 1) + (second > 10 ? 2 : 1);
}

console.log(addWithSurcharge(5, 15));