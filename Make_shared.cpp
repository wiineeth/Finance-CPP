#include <iostream>

#include <memory>



struct Point2d {

  double x, y;

  Point2d() : x(0.0), y(0.0) {} // constructor

  Point2d(double xVal, double yVal) : x(xVal), y(yVal) {}

  void print() const { std::cout << "(" << x << " , " << y << ")\n"; }

  ~Point2d() { std::cout << "point destroyed\n"; }

};

int main() {

  // more efficient way to construct shared pointers

  auto ms = std::make_shared<int>(42);

  (*ms)++;

  std::cout << "ms: " << *ms << "\n"; // 43



  auto ms2 = std::make_shared<Point2d>(-1.0, 2.0);

  (*ms2).print(); //(-1,2)



  auto ms3 = std::make_shared<Point2d>();

  (*ms3).print(); //(0,0)



  // More efficient ways to construct shared pointers

  auto ms4 = std::allocate_shared<int>(std::allocator<int>(), 42);

  (*ms4)++;

  std::cout << "ms4: " << *ms4 << "\n";

  auto ms5 = std::allocate_shared<Point2d>(std::allocator<int>(), -1.0, 2.3);

  (*ms5).print();

}