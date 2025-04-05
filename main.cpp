#include <cmath>
#include <iostream>

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
std::string poweroftwoloop(int n) {
    if (n <= 1) {return "FAIL!";}
    while (n > 1) {
        if (n % 2 == 0) {n = n / 2;}
        else {return "FAIL!";}
    }
    return "PASS!";
}

std::string poweroftwonoloop(int n) {
    std::string result = "FAIL!";
    if (n > 1 && n % 2 == 0 && n % 3 != 0
        && n % 5 != 0) {result = "PASS!";}
    return result;
}

// made faster with help from GPT using sqrt(n) in the for loop instead of i < n
std::string checkprimenum(int n) {
    std::string result = "PASS!";
    if (n <= 1) {result = "FAIL!";}
    for (int i = 2; i <= std::sqrt(n) && result == "PASS!"; i++) {
        if (n % i == 0) {result = "FAIL!";}
    }
    return result;
}

class Fraction {
public:
    int numerator;
    int denominator;

    Fraction(int numerator, int denominator)
        : numerator(numerator),
          denominator(denominator) {}

    std::string to_string() {
        return std::to_string(numerator) + "/" + std::to_string(denominator);
    }

    // operator overload
    bool operator==(Fraction &other) {
        return this->numerator == other.numerator &&
            this->denominator == other.denominator;
    }

};

Fraction reduce(Fraction input) {
    int divider = 2;
    while (divider <= input.numerator && divider <= input.denominator) {
        if (input.numerator % divider == 0 && input.denominator % divider == 0) {
            input.numerator /= divider;
            input.denominator /= divider;
            continue;
        }
        divider++;
    }
    return input;
}

void poweroftwotest();

void primetest();

void fractiontest();

int main() {
    poweroftwotest();
    primetest();
    fractiontest();
}

void poweroftwotest() {
    // check of a number is a power of two using both functions
    int inputs[8] = {2, 3, 10, 16, 24, 25, 256, 320};

    for (int i = 0; i < 8; i++) {
        std::cout << inputs[i] << " power of 2 w/ loop: "
        << poweroftwoloop(inputs[i]) << std::endl;
    }

    for (int i = 0; i < 8; i++) {
        std::cout << inputs[i] << " power of 2 no loop: "
        << poweroftwonoloop(inputs[i]) << std::endl;
    }
}

void primetest() {
    // check if a given number is a prime number or not
    int inputs[14] = {-5, -1, 0, 1, 2, 3, 5, 7, 11, 14, 15, 16, 19, 25};

    for (int i = 0; i < 14; i++) {
        std::cout << inputs[i] << " prime number: " << checkprimenum(inputs[i]) << std::endl;
    }
}

void fractiontest() {
    // reduce given fraction to minimum terms
    // 1/2 -> 1/2
    // 2/4 -> 1/2
    // 4/2 -> 2/1
    // 6/8 -> 3/4

    // given an input, the actual output should match the expected output
    Fraction inputs[4] = {Fraction(1,2),
        Fraction(2,4),
        Fraction(4,2),
        Fraction(6,8)};
    Fraction outputs[4] = {Fraction(1,2),
        Fraction(1,2),
        Fraction(2,1),
        Fraction(3,4)};

    // call the function
    for (int i = 0; i < 4; i++) {
        Fraction input = inputs[i];
        Fraction expect = outputs[i];

        Fraction actual = reduce(input);

        // compare expected vs actual
        if (expect == actual) {
            std::cout << "PASS!" << std::endl;
        } else {
            std::cout << "FAIL! case is: " << input.to_string() << std::endl;
        }
    }

}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.