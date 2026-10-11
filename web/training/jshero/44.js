function isEven(number) {
    return number % 2 === 0;
}

function isEvenOptimized(number) {
    return number & 1 == 0;
}

console.log(isEven(2));
console.log(isEven(3));