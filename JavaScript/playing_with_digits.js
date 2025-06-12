function digPow(n, p) {
    let powerResult = 0, index = 0;
    let split_number_digits = n.toString().split('').map(e => parseInt(e)); // split the number.

    while (index < split_number_digits.length) {
        powerResult += Math.pow(split_number_digits[index], p + index);
        index++;
    }

    if ((powerResult % n !== 0))
        return -1;

    let k = powerResult / n;
    return k;
}