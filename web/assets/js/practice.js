function fizzbuzzPlus(n) {
    const output = {
        sequence: [],
        counts: [0, 0, 0],
    }

    if (!Number.isInteger(n) || n < 1)
        return null;

    for (let i = 1; i <= n; ++i) {
        if (i % 3 == 0 && i % 5 == 0) {
            output.sequence.push("FizzBuzz");
            ++output.counts[2];
            continue;
        }

        if (i % 3 == 0) {
            output.sequence.push("Fizz");
            ++output.counts[0];
            continue;
        }

        if (i % 5 == 0) {
            output.sequence.push("Buzz");
            ++output.counts[1];
            continue;
        }

        output.sequence.push(i.toString());
    }

    return output;
}

function mergeStats(...arrays) {
    let output = {
        unique: [],
        sum: 0,
        avg: null,
        min: null,
        max: null,
    }

    if (!arrays.length)
        return output;

    for (const array of arrays) {
        for (const element of array) {
            if (!Number.isFinite(element))
                continue;

            if (output.unique.includes(element))
                continue;

            output.unique.push(element);
            output.sum += element;
            ++output.avg;

            if (output.min === null) {
                output.min = element;
                output.max = element;
                continue;
            }

            if (element < output.min) {
                output.min = element;
                continue;
            }

            if (element > output.max)
                output.max = element;
        }
    }

    if (output.avg !== null)
        output.avg = output.sum / output.avg;

    return output;
}

const visitorForm = document.getElementById("visitor-form");
visitorForm.addEventListener("submit", (event) => {
    event.preventDefault();
    console.log("Ну... допустим форма отправлена на сервер");
});