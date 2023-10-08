#include <iostream>

int main() {
    long long number; // Input number
    std::cout << "Enter a number: ";
    std::cin >> number;

    int sum = 0;

    // Take the absolute value to handle negative numbers
    number = std::abs(number);

    while (number > 0) {
        int digit = number % 10; // Extract the last digit
        sum += digit;           // Add the digit to the sum
        number /= 10;           // Remove the last digit
    }

    std::cout << "Sum of the digits: " << sum << std::endl;

    return 0;
}
