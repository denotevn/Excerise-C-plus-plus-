#include <iostream>
#include <vector>
#include <numeric>

int main() {
  auto header = [](std::string title){
    std::cout << "---- " << title << " ----" << '\n';
  };
  auto render = [](auto collection) {
    for (const auto &val: collection) {
      std::cout << val << '\n';
    }
  };

  header("map");
  std::vector<int> inCollection{11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
  std::vector<int> outCollection;
  transform(inCollection.begin(), inCollection.end(), back_inserter(outCollection),
            [](const int &value) { return value * 3; });
  render(outCollection);

  header("filter");
  std::vector<int> filteredCollection;

  copy_if(outCollection.begin(), outCollection.end(), back_inserter(filteredCollection),
          [](int &value) { return value % 2 != 0; });
  render(filteredCollection);

  header("reduce");
  int results = std::accumulate(filteredCollection.begin(), filteredCollection.end(),
                           0, [](int total, int current) {
        return total + current;
      });
  std::cout << "results: " << results << "\n";
  return 0;
}