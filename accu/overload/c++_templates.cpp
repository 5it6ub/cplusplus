#include <iostream>

// template function
template <typename T>
T GetMax(T a, T b) {
  T result;
  result = (a>b)? a : b;
  return result;
}

// template class
template <typename T>
class mypair {
  T a, b;
public:
  mypair(T first, T second) {
    a = first;
    b = second;
  }
  T getmax();
};

// template function definition outside of declaration
template <typename T>
T mypair<T>::getmax() {
  T retval;
  retval = a>b ? a : b;
  return retval;
}

// template specialization
template <typename T>
class mycontainer {
  T element;
public:
  mycontainer(T arg) {
    element = arg;
  }
  T increase() {
    return ++element;
  }
};

template <>
class mycontainer<char> {
  char element;
public:
  mycontainer(char arg) {
    element = arg;
  }
  char uppercase() {
    if((element >= 'a')&&(element <= 'z')) {
      element += 'A'-'a';
    }
    return element;
  }
};

// sequence template
template <typename T=char, int N=10>
class mysequence {
  T memblock[N];
public:
  void setmember(int x, T value);
  T getmember(int x);
};

template <typename T, int N>
void mysequence<T, N>::setmember(int x, T value) {
  memblock[x] = value;
}

template <typename T, int N>
T mysequence<T, N>::getmember(int x) {
  return memblock[x];
}

int main() {
  int i=5, j=6, k;
  long l=10, m=5, n;
  k = GetMax<int>(i,j);
  n = GetMax<long>(l,m);
  std::cout << k << std::endl;
  std::cout << n << std::endl;

  mypair<int> myobject(100, 75);
  std::cout << myobject.getmax() << std::endl;

  mycontainer<int> myint(7);
  std::cout << myint.increase() << std::endl;
  mycontainer<char> mychar('b');
  std::cout << mychar.uppercase() << std::endl;

  mysequence<int, 5> myints;
  mysequence<double, 5> myfloats;
  mysequence<> mydefault;
  myints.setmember(0, 100);
  myfloats.setmember(3, 3.1416);
  mydefault.setmember(2, 'a');
  std::cout << myints.getmember(0) << std::endl;
  std::cout << myfloats.getmember(3) << std::endl;
  std::cout << mydefault.getmember(2) << std::endl;

  return 0;
}
