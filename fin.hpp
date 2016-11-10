#include <iostream>

using namespace std;

class _fin {
  bool n,h;
public:
  const bool p;
  const char c,e;
  istream& i;
  ostream& o;
  _fin(bool v,char w,char x,istream& y,ostream& z)
    :n(false),h(true),p(v),c(w),e(x),i(y),o(z){}
  _fin(_fin&& f):n(false),h(f.h),p(f.p),c(f.c),e(f.e),i(f.i),o(f.o)
  {f.n=true;}
  _fin(_fin& f):n(false),h(f.h),p(f.p),c(f.c),e(f.e),i(f.i),o(f.o) {}
  ~_fin(){if(!n)o<<e;}
  bool first(){return h?!(h=false):h;}
};

class getfin {
private:
  const bool p;
  istream& i;
  ostream& o;
public:
  getfin(bool x, istream& y=cin, ostream& z=cout):p(x),i(y),o(z) {}
  _fin operator()(char c=' ',char e='\n')
  {return _fin(p,c,e,i,o);}
};

template<class T> _fin operator>> (_fin f, T& x)
{
  if(f.p && !f.first()) f.o << f.c;
  f.i >> x;
  if(f.p) f.o << x;
  return f;
}
