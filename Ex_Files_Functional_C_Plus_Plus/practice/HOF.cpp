#include <functional>
#include <iostream>
#include<vector>

using namespace std;

function pickNumbers(maximum, pickingCondition) {
  const result = [];

  for (let i = 1; i <= maximum; i += 1) {
    if (pickingCondition(i)) result.push(i);
  }

  return result;
}

int main(){
        // Chọn ra những số lẻ
    pickNumbers(20, function(number) {
    return number % 2 === 1;
    });

    // Chọn ra những số mà gấp 3 số đó rồi trừ đi 2 thu số chẵn
    pickNumbers(20, function(number) {
    return ((number * 3) - 2) % 2 === 0;
    });

    return 0;
}