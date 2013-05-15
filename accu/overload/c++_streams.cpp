#include <iostream>    // std::cout, std::endl, std::ios_base, std::fixed, std::showpoint, std::streambuf, std::streamsize
#include <iomanip>    // std::setiosflags, std::setprecision
#include <sstream>    // std::ostringstream
//using namespace std;

int main() {

  /* 
    The standard C string codes such as \n can still be used, however, 
    it is preferred to use 'endl' (endline) to force end of line 
    (equivalent of \n & flush).
  */
  int myvalue = 10;
  std::cout << "This is line 1" << std::endl 
	    << "This is line 2 with a value of " << myvalue << std::endl;

  /*
    Examples of stream manipulations
  */
  float my_float = 22.9756;
  // using ios_base::fmtflags
  std::cout.setf(std::ios_base::scientific, std::ios_base::floatfield);
  std::cout.setf(std::ios_base::showpoint);
  std::cout << my_float << std::endl;
  std::cout.unsetf(std::ios_base::scientific);
  std::cout << my_float << std::endl;

  // using manipulators
  std::cout << std::fixed << std::showpoint << my_float << std::endl;
  std::cout << std::setiosflags(std::ios_base::fixed | std::ios_base::showpoint)
	    << std::setprecision(2) << my_float << std::endl;

  /* input hex output decimal
  int k = 0;
  std::cin >> std::hex >> k;
  std::cout << "The value entered is " << k << std::endl;
  */

  /* 
    sprintf is replaced by the ostrstream class. ostrstream has been deprecated since C++98, std::ostringstream and boost::iostreams::array_sink are the recommended replacements. Note: The 'ends' stream manipulator (end string) is the equivalent of '\0' the string terminator.
  */
  std::ostringstream buffer;
  const float PI = 3.14159265;
  const float r = 10.5;
  buffer << "The area of the circle of radius " << r
	 << " = " << PI*r*r << std::ends;
  std::cout << buffer.str() << std::endl;

  /* TODO: manual memory allocation using std::ostringstream */

  /* 
    memory reading. An istream object is set up and used in a similar manner to cin. The only awkward bit is reading in strings. For this you have to remember to remove whitespace and to use the get() or getline() member functions of the stream to copy the string to the target variable.
  */
  char memory_info[] = "100 200 22.995 hello fred";
  int i1, i2;
  float f1;
  char ws;
  char s1[10], s2[10];
  std::istringstream stringstream(memory_info);
  std::streamsize size;

  if (stringstream.good()) {
    std::streambuf* pbuf = stringstream.rdbuf();
    size = pbuf->in_avail();
    std::cout << "size = " << size << std::endl;
    stringstream >> i1 >> i2 >> f1;
    size = pbuf->in_avail();
    std::cout << "size = " << size << std::endl;
    stringstream >> ws;
    size = pbuf->in_avail();
    std::cout << "size = " << size << std::endl;
    stringstream.putback(ws);
    stringstream.get(s1, 10, ' ');
    size = pbuf->in_avail();
    std::cout << "size = " << size << std::endl;
    stringstream >> ws;
    size = pbuf->in_avail();
    std::cout << "size = " << size << std::endl;
    stringstream.putback(ws);
    stringstream.get(s2, 10, ' ');
    size = pbuf->in_avail();
    std::cout << "size = " << size << std::endl;
    std::cout << "i1 = " << i1 << std::endl
	    << "i2 = " << i2 << std::endl
	    << "f1 = " << f1 << std::endl
	    << "s1 = " << s1 << std::endl
	    << "s2 = " << s2 << std::endl;
  }
  return 0;
}
