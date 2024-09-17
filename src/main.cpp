#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <tuple>
#include <numbers>

// Task 3, Task 4: timesTwo() here
auto timesTwo = [](auto n) {
    return n + n;
};

struct Rectangle {
    double length; // Data member, also known as a field
    double width = 1; // Field can have a default value
    // Fields must be explicitly typed, you cannot use type deduction here

    // Member function, also known as a method
    double calculateArea() {
        return length * width;
    }

    // Member function that modifies the state of an object
    void makeItASquare(double sideLength) {
        length = sideLength;
        width = sideLength;
    }

    // Task 5: calculatePerimeter() here
    int calculatePerimeter() {
        return length + length + width + width;
    }
};

// Task 6: struct Circle here
struct Circle {
    float radius;

    float calculateArea() {
        return std::numbers::pi * (radius * radius);
    }

    float calculatePerimeter() {
        return 2 * std::numbers::pi * radius;
    }
};

// Task 7:
void printShape(auto shape) {
    std::cout << "Area: " << shape.calculateArea() << "\nPerimeter: " << shape.calculatePerimeter() << std::endl;
}

// Task 9:
void inplaceTimesTwo(auto* somePointer) {
    // Your code here
    *somePointer = timesTwo(*somePointer);
}

// Task 10:
void doubleEachElement(auto& container) {
    // Your code here
    for (auto& x : container) {
        inplaceTimesTwo(&x);
    }
}

// Task 11-14:
std::vector<float> generateSequence(int n) {
    std::vector<float> sequence(n);
    double temp = 0;
    for (int i = 0; i < n; i++) {
        temp = 1.0/(i+1); // 1, 1/2, 1/3, ...
        sequence[i] = temp;
    }
    return sequence;
}
void verifySequence(std::vector<float>& seq) {
    // DO NOT TOUCH this function
    for (int i=0; i < seq.size(); i++) {
        if (std::abs(seq[i] -  1.0/(i+1)) > 1e-3) {
            std::cerr << "Output sequence is incorrect! It should be (1, 1/2, 1/3, ..., 1/n)" << std::endl;
            return;
        }
    }
    std::cout << "Output sequence is correct! Congrats on finishing the lab!" << std::endl;
}

int main() {
    // Task 2: write "Hello World!" in an std::cout << "" << std::endl; call
    std::cout << "Hello, world!" << std::endl;

    // Task 3:

    std::cout << timesTwo(21) << std::endl;

    // Task 4:
    std::cout << timesTwo(123) << std::endl;
    std::cout << timesTwo(3.14) << std::endl;
    std::cout << timesTwo(std::string{ "abc" }) << std::endl;

    // Task 5:
    Rectangle rect1 = Rectangle{ 7, 8 };
    std::cout << rect1.calculatePerimeter() << std::endl;

    // Task 6: create a few instances of Circle, and call their member functions
    // Tip: to use pi, use std::numbers::pi
    Circle c = Circle{.radius=5};
    Circle c2 = Circle{.radius=std::numbers::pi};
    std::cout << "c area: " << c.calculateArea() << ", perimeter: " << c.calculatePerimeter() << std::endl;
    std::cout << "c2 area: " << c2.calculateArea() << ", perimeter: " << c2.calculatePerimeter() << std::endl;

    // Task 7: call printShape with different Rectangle and Circle objects
    printShape(rect1);
    printShape(c);
    printShape(c2);
    // Task 8: create a container of strings, fill the container with some strings
    //         apply timesTwo to each string element in the container, print each string element in the container
    using namespace std::string_literals;
    std::vector<std::string> stringVec = std::vector{"hi"s, "koishi"s, "touhou"s};
    for (auto& s : stringVec) {
        s = timesTwo(s);
        std::cout << s << std::endl;
    }

    // Task 9:
    auto x = 21;
    auto y = std::string{ "abcd" };
    inplaceTimesTwo(&x);
    inplaceTimesTwo(&y);
    std::cout << x << std::endl; // you should see 42 here
    std::cout << y << std::endl; // you should see "abcdabcd" here

    // Task 10: pass different std::array and std::vector objects to doubleEachElement
    //          print the results after doubleEachElement calls
    auto a1 = std::array{3,4,5};
    auto a2 = std::vector{"cirno"s, "funny"s, "satori"s};
    doubleEachElement(a1);
    doubleEachElement(a2);
    for (auto i : a1) {
        std::cout << i << std::endl;
    }
    for (auto i : a2) {
        std::cout << i << std::endl;
    }

    // Task 11:
    std::vector<float> sequence = generateSequence(5);
    verifySequence(sequence);
}
