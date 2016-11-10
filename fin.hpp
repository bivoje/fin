#include <iostream>

using namespace std;

class _fin {
  bool empty; //is it moved?
  bool h; //is this the first printing?
public:
  const bool p;
  const char c, e;
  istream& i;
  ostream& o;
  //this is called when 'fin() >>'
  _fin(bool _p, char _c, char _e, istream& _i, ostream& _o)
    : empty(false), h(true), p(_p), c(_c), e(_e), i(_i), o(_o)
  {
    //cerr << "new _fin with " << bool(p) << ' ' << int(c) << ' ' << int(e) << endl;
  }
  //this is called when streaming(<<) happens
  _fin(_fin&& f)
    : empty(false), h(f.h), p(f.p), c(f.c), e(f.e), i(f.i), o(f.o)
  {
    f.empty = true;
  }

  bool first() {bool tb=h; h=false; return h;}

  ~_fin()
  {
    if(!empty) //not moved, no more streaming
      o << e;
    //cerr << "_fin dead with " << bool(p) << ' ' << int(c) << ' ' << int(e) << endl;
  }
};

class getfin {
private:
  const bool p;
  istream& i;
  ostream& o;

public:
  getfin(bool _p, istream& _i=cin, ostream& _o=cout)
    : p(_p), i(_i), o(_o) {}
  _fin operator() (char c=' ', char e='\n')
  { return _fin(p, c, e, i, o); }
};

//TODO what if we use rvalue at here? .. like
//_fin&& operator>> (_fin&& f, T& x)
template <class T>
_fin operator>> (_fin f, T& x)
{
  //splitter
  //do this before the element to prevent printing it out at the last
  if(f.p && !f.first()) //if this is not the first of stream
    f.o << f.c; //print the splitter

  //get the value
  f.i >> x;

  //print the element
  if(f.p)
    f.o << x;

  return f;
}
