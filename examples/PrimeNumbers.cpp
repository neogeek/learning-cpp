#include <iostream>

bool isPrime(int number) {

    if (number < 2) { return false; }

    for (int i = 2; i < number; i += 1) {

        if (number % 2 == 0) { return false; }

    }

    return true;

}

int main() {

    int primeNumbers[10];

    int lastNumber = 0;

    for (int i = 0; i < std::size(primeNumbers); i += 1) {

        do {
            lastNumber += 1;
        } while (!isPrime(lastNumber));

        primeNumbers[i] = lastNumber;

    }

    for (int i = 0; i < std::size(primeNumbers); i += 1) {

        std::cout << (int)primeNumbers[i] << std::endl;

    }

}
