#include <iostream>

using namespace std;

class _fin {
  bool n,h;
  bool p;
  char c,e;
public:
  istream& i;
  ostream& o;
  _fin(bool v,char w,char x,istream& y,ostream& z)
    :n(false),h(true),p(v),c(w),e(x),i(y),o(z) {}
  _fin(_fin& f):n(false),h(f.h),p(f.p),c(f.c),e(f.e),i(f.i),o(f.o)
  {f.n=true;}
  //FIXME what if f is not using cin and cout?
  _fin(_fin&& f):n(false),h(f.h),p(f.p),c(f.c),e(f.e),i(f.i),o(f.o)
  {f.n=true;}
  //void operator= (_fin& f)
  //{ n=false; h=f.h; p=f.p; c=f.c; e=f.e; f.n=true; }
  void operator= (_fin&& f)
  { n=false; h=f.h; p=f.p; c=f.c; e=f.e; f.n=true; }
  ~_fin(){if(!n)o<<e;}
  bool first(){return h?!(h=false):h;}
  bool piped(){return p;}
  char split(){return c;}
};

class getfin {
public:
  const bool p;
  istream& i;
  ostream& o;
  getfin(bool x, istream& y=cin, ostream& z=cout):p(x),i(y),o(z) {}
  _fin operator()(char c=' ',char e='\n')
  {return _fin(p,c,e,i,o);}
};

template<class T> _fin operator>> (_fin f, T& x)
{
  if(f.piped() && !f.first()) f.o << f.split();
  f.i >> x;
  if(f.piped()) f.o << x;
  return f;
}
