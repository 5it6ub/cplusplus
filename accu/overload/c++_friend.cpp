#include <iostream>

// friend class
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

// friend function of more than one class
class Humidity;

class Temperature {
private:
  int m_nTmp;
public:
  Temperature(int nTmp) { m_nTmp = nTmp; }
  friend void PrintWeather(Temperature &cTemperature, Humidity &cHumidity);
};

class Humidity {
private:
  int m_nHumidity;
public:
  Humidity(int nHumidity) { m_nHumidity = nHumidity; }
  friend void PrintWeather(Temperature &cTemperature, Humidity &cHumidity);
};

void PrintWeather(Temperature &cTemperature, Humidity &cHumidity) {
  std::cout << "The temperature is " << cTemperature.m_nTmp <<
    " and the humidity is " << cHumidity.m_nHumidity << std::endl;
}

int main() {
  Storage cStorage(5, 6.7);
  Display cDisplay(false);

  cDisplay.DisplayItem(cStorage);

  Temperature cTemperature(28);
  Humidity cHumidity(80);

  PrintWeather(cTemperature, cHumidity);

  return 0;
}
