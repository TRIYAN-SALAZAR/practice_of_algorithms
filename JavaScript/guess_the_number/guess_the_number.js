'use strict';

let candidates = null;
let lastGuess = null;

function countExactMatches(guess, code) {
    let count = 0;
    for (let i = 0; i < 4; i++) {
        if (guess[i] === code[i]) {
            count++;
        }
    }
    return count;
}

function generateAllCodes() {
    let res = [];
    for (let a = 0; a < 10; a++) {
        for (let b = 0; b < 10; b++) {
            if (b === a) continue;
            for (let c = 0; c < 10; c++) {
                if (c === a || c === b) continue;
                for (let d = 0; d < 10; d++) {
                    if (d === a || d === b || d === c) continue;
                    res.push([a, b, c, d]);
                }
            }
        }
    }
    return res;
}

function game(matches) {
    if (matches === -1) {
        candidates = generateAllCodes();
        lastGuess = [0, 1, 2, 3];
        return lastGuess;
    }

    candidates = candidates.filter(code => countExactMatches(lastGuess, code) === matches);

    if (candidates.length === 0) {
        lastGuess = [0, 0, 0, 0];
        return lastGuess;
    }

    if (candidates.length === 1) {
        lastGuess = candidates[0];
        return lastGuess;
    }

    let bestGuess = null;
    let bestWorstCase = Infinity;

    for (let i = 0; i < candidates.length; i++) {
        let g = candidates[i];
        let groups = [0, 0, 0, 0, 0];
        for (let j = 0; j < candidates.length; j++) {
            let c = candidates[j];
            let r = countExactMatches(g, c);
            groups[r]++;
        }
        let worstCase = Math.max(...groups);
        if (worstCase < bestWorstCase) {
            bestWorstCase = worstCase;
            bestGuess = g;
        }
    }

    lastGuess = bestGuess;
    return bestGuess;
}