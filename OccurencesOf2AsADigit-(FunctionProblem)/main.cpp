/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* Counts the number of 2s in a number at d-th digit */
long long int count2sinRangeAtDigit(long long int number, long long int d) {
    long long int divisor = 1;
    long long int module = 1;
    long long int i = d;

    while (--i) divisor *= 10;
    module = divisor * 10;

    long long dDigitNumber = number % module;
    long long overDthDigit = number / module;
    int dthDigit = dDigitNumber / divisor;

    // cout << divisor << "\t" << overDthDigit << "\t" << dDigitNumber << "\t" << endl;

    if (dthDigit < 2) return divisor * overDthDigit;
    if (dthDigit > 2) return divisor * (overDthDigit + 1);

    return divisor * overDthDigit + (dDigitNumber % divisor) + 1;
}

/* Counts the number of '2' digits between 0 and n */
long long int numberOf2sinRange(long long int number) {
    long long int tmpNumber = number;
    long long int noDigits = 0;

    do {
        noDigits++;
        tmpNumber /= 10;
    } while (tmpNumber > 0);

    long long int counter = 0;
    for (int i = 1; i <= noDigits; i++) {
        counter += count2sinRangeAtDigit(number, i);;
    }

    return counter;
}