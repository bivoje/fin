#include <iostream>
#include "fin.hpp"

using namespace std;

int main(int argc, char** argv)
{
  _ifin ifin(argc>1 && argv[1]==string("--piped"));

  int n, m;
  cout << "Enter : ";
  ifin >> n >> '\n' >> m;
  cout << "the value is " << n << ' ' << m << endl;

  return 0;
}
