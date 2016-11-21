#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

long long MaxPairwiseProduct(const vector<int>& numbers) {
  int result = 0;
  int n = numbers.size();
  if(n<=0)
      return result; 
  int i1 = 0, i2 = 1;
  for (int i = 0; i < n; ++i) {
      if(i!=i1 && numbers[i] >= numbers[i1]){
          i2 = i1;
          i1 = i;
          cout << "i1, i2 = " << i1 << ", " << i2 << endl;
      } else if(i!=i2 && numbers[i] >= numbers[i2]){
          i2 = i;
          cout << "i2 = " << i2 << endl;
      }

  }
  return (long long) numbers[i1]*numbers[i2]; 
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    long long result = MaxPairwiseProduct(numbers);
    cout << result << "\n";
    return 0;
}
