#include <iostream>
void print_narcis() {
    for (int a = 1; a <= 999 ; a++) {
        for (int b = 0; b <= 999; b++) {
            for (int c=0; c <= 999; c++) {
                auto abc = a * 100 + b * 10 + c;
                auto arm = a * a * a + b * b * b + c * c * c;
                if (abc == arm) {
                    std::cout << arm << std::endl;
                }
            }
        }
    }
}
int main() {
    print_narcis();
}