
// find the errors in this programm
#include <iostream>
#include <vector>
#include <cstring>

struct Cat {
  Cat() : name(""), color(""), age(0), weight(0) {}
  Cat(std::string n, std::string c, int a, int w) : name(std::move(n)), color(std::move(c)), age(a), weight(w) {}
  std::string name;
  std::string color;
  int age;
  int weight;
};

void too_many_cats() {
  Cat houseCats[] = {{"Meowmix",    "black", 9, 12},
                     {"Thundercat", "grey",  4, 16}};
  std::cout << houseCats[0].name << std::endl;
  std::cout << houseCats[1].name << std::endl; // loi 1 o day fix =  houeCats[1]
}

void write_file(const char *str) {
  char *buff = new char[8];
  strcpy(buff, str);

  FILE *file = fopen("out.txt", "w");
  if (!file)
    return;  // error memory leaks

  for (char *c = buff; *c; ++c) {
    fputc((int) *c, file);
  }
  delete[] buff;
}

void vector_check() {
  std::vector<int> items;
  items.push_back(1);
  items.push_back(2);
  items.push_back(3);
  std::vector<int>::iterator iter;
  for (iter = items.begin(); iter != items.end(); ++iter) { // Using iterator to local container 'items' that may be invalid
                                                    // Sử dụng trình lặp cho các 'mục' vùng chứa cục bộ có thể không hợp lệ
                                                    // nen tao bo ap chua vung chua trong vong for luon
    int a = *iter;
    if (a == 2) {
      items.erase(iter); // After calling 'erase', iterators or references to the container's data may be invalid .
    }
  }
}

int main() {
  too_many_cats();
  write_file(static_cast<const char *>("Hello World"));
  vector_check();
}
