/*
 * This source file was generated by the Gradle 'init' task
 */

#include "build.h"
#include <cassert>

int main() {
    build::Greeter greeter;
    assert(greeter.greeting().compare("Hello, World!") == 0);
    return 0;
}
