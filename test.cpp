#include <iostream>
#include "fin.hpp"

using namespace std;

int main(int argc, char** argv)
{
  _ifin ifin(argc>1 && argv[1]==string("--piped"));

  //o... okay
  int n, m;
  cout << "Enter : ";
  ifin >> n >> '\n' >> m;
  cout << "the value is " << n << ' ' << m << endl;

  //error
  char c = '\n';
  char n, m;
  cout << "Enter : ";
  ifin >> n >> c >> m;
  cout << "the value is " << n << ' ' << m << endl;

  //ifin.c is reset at every >>, 
  //so if I want '\t' to split each field
  ifin('\t') >> n >> '\t' >> m >> '\n' >> x;
  //what I wanted to do is let the user to set splitter 
  //every time like
  cout << "insert : ";
  ifin('\n') >> x;
  cout << "number : ";
  ifin('\n') >> n;
  for(int i=0; i<n; i++)
    ifin(' ') >> s;
  //but it makes trouble when getting more than 2 at once.
  //we can let ifin.c not reset, but ...
  //it would cause frequent bug if programmer forget to set it.
  ifin('\t') >> x >> y >> z; // split with tab
  .... // some work
  ifin >> n >> m; //still with tab.. 

  return 0;
}
