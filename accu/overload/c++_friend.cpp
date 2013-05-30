#include <iostream>

class Storage {
private:
  int m_nValue;
  double m_dValue;
public:
  Storage(int nValue, double dValue) {
    m_nValue = nValue;
    m_dValue = dValue;
  }

  friend class Display;
};

class Display {
private:
  bool m_bDisplayIntFirst;
public:
  Display(bool bDisplayIntFirst) {
    m_bDisplayIntFirst = bDisplayIntFirst;
  }

  void DisplayItem(const Storage &cStorage) {
    if(m_bDisplayIntFirst) {
      std::cout << cStorage.m_nValue << " " << cStorage.m_dValue << std::endl;
    } else {
      std::cout << cStorage.m_dValue << " " << cStorage.m_nValue << std::endl;
    }
  }
};

int main() {
  Storage cStorage(5, 6.7);
  Display cDisplay(false);

  cDisplay.DisplayItem(cStorage);

  return 0;
}
