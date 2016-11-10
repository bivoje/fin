#include <iostream>

using namespace std;

class _ifin {
  bool p;
  char c;
  const static char sc = ' ';
public:
  _ifin(bool _p) : p(_p), c(sc) {}
  bool piped() {return p;}
  _ifin& operator() (char _c) {c=_c; return *this;}
  char token() {char tmp=c; c=sc; return tmp;}
};

template <class T>
_ifin& operator>>(_ifin& i, T& x) 
{
  cin >> x;
  if(i.piped())
    cout << x << i.token();
  return i;
}

_ifin& operator>>(_ifin& i, char c) 
{
  return i(c);
}
