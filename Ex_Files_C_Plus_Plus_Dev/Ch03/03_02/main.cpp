#include <iostream>
#include <vector>
#include <map>

int main() {
  std::vector<int> v{0, 1, 2, 3, 4, 5};
  for (auto i : v) {
    std::cout << i << ' ';
  }
  std::cout << std::endl;

  for (int n : {9, 8, 7, 6, 5, 4}) {
    std::cout << n << ' ';
  }
  std::cout << std::endl;

  int a[]{0, 1, 2, 3, 4, 5};
  for (auto n : a) {
    std::cout << n << ' ';
  }
  std::cout << std::endl;

  std::string str{"Modern C++"};
  for (auto ch : str) {
    std::cout << ch << ' ';
  }
  std::cout << std::endl;

  std::map<int, std::string> nicknames{{1, "biz"},
                                        {2, "fox"},
                                        {3, "wiz"}};
  for (auto ndx : nicknames) {
    std::cout << ndx.first << ", " << ndx.second << std::endl;
  }
}