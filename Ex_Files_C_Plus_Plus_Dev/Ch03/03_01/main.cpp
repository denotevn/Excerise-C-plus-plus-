#include <iostream>
#include <vector>


int main(){
  std::vector<int> alpha{1, 2, 3};
  // auto beta{1, 2, 3}; // error: initializer for variable 'beta' with type 'auto' contains multiple expressions
  auto gamma = {1, 2, 3}; // can do this, but... wrong type
  auto delta = std::vector<int>{1, 2, 3};
  std::vector<int> epsilon;
  // auto zeta;  // error: declaration of variable 'zeta' with deduced type 'auto' requires an initializer
}