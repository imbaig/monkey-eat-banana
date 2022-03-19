#include <cctype>
#include <iostream>
#include <vector>
using namespace std;


void FindUpperLowerPermutations(string input, int index, string& slate, vector<string>& result)
{
  // Base case
  if (index == (int)input.size())
  {
    result.push_back(slate);
    return;
  }

  if (isalpha(input[index]))
  {
      slate[index] = std::toupper(input[index]);
      FindUpperLowerPermutations(input, index+1, slate, result);

      slate[index] = std::tolower(input[index]);
      FindUpperLowerPermutations(input, index+1, slate, result);
  }
  else 
  {
      slate[index] = input[index];
      FindUpperLowerPermutations(input, index+1, slate, result);
  }
}

// To execute C++, please define "int main()"
int main() {
  
  string input = "a12b3";

  vector<string> permutations;
  string slate = "";
  FindUpperLowerPermutations(input, 0, slate, permutations);

  for (auto perm : permutations)
  {
    cout << perm << endl;
  }
  return 0;
}
