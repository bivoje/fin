#include <iostream>
#include "fin.hpp"

using namespace std;

int main()
{
  getfin fin(true);

  int x, y, z;
  cout << "Enter : ";
  fin() >> x >> y >> z;

  cout << "Enter 10 : ";
  int k[10];
  int i=0;
  for(_fin f = fin('|','\n'); i<10; i++)
    f = (f >> k[i]);

  return 0;
}
