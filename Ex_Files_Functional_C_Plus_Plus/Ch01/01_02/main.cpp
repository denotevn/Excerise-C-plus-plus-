// 01_04 Unit Testing FP

// Tells Catch to provide a main()
#define CATCH_CONFIG_MAIN
<<<<<<< HEAD
#include <catch2/catch_all.hpp>
=======
#include "catch.hpp"
>>>>>>> 333aea449a577c75a6e55b8520bd0a9a22f73205

// a pure function without side effects
int fibonacci(int n) {
  if (n <= 1) {
    return (n);
  }
  return (fibonacci(n - 1) + fibonacci(n - 2));
}

TEST_CASE("Fibonacci series", "[fibonacci]") {
  REQUIRE(fibonacci(0) == 0);
  REQUIRE(fibonacci(1) == 1);
  REQUIRE(fibonacci(2) == 1);
  REQUIRE(fibonacci(3) == 2);
  REQUIRE(fibonacci(4) == 3);
  REQUIRE(fibonacci(5) == 5);
  REQUIRE(fibonacci(12) == 144);
}