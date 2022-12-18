#include <iostream>
#include "Sample.class.hpp"

int main(void) {
    Sample test;

    test.bar('a');
    test.bar(1);
    test.bar((float)3.14);
    test.bar(test);
}
