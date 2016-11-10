#include <iostream>
#include "fin.hpp"

using namespace std;

int main()
{
  getfin fin(true);

  int x, y, z;
  cout << "Enter ";
  fin() >> x >> y >> z;
  cout << "Get " << x << ' ' << y << ' ' << z << endl;

  int k[10];
  //for(int i=0; i<10; i++)
  //{
  //  fin('\0','|') >> k[i];
  //} fin('\0','\n');

  //move constructor used
  _fin f = fin('|','\n');
  for(int i=0; i<10; i++)
  {
    //move constructor used
    f = (f >> k[i]);
  }
  //not moved, destructor called

  return 0;
}
