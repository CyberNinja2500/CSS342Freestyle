#include <iostream>

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
bool poweroftwoloop(int n) {
    while (n > 1) {

    }
    return true;
}

bool poweroftwonoloop(int n) {
    if (n < 2) {return false;}
    if (n % 2 == 0) {return true;}
    return true;
}

bool checkprimenum(int n) {
    return true;
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
    return Fraction(-1,-1);
}

void test();

int main() {
    test();
}

void test() {
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