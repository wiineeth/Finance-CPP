
#include <bits/stdc++.h>

template <typename T> using UP = std::unique_ptr<T>;

struct Point2d {

  double x, y;

  Point2d() : x(0.0), y(0.0) {}

  Point2d(double xVal, double yVal) : x(xVal), y(yVal) {}

  void print() const { std::cout << "(" << x << " , " << y << ")\n"; }

  ~Point2d() { std::cout << "Point Destroyed \n"; }

};



int main() {



  try {

    // Unique pointers

    // Stored lambda function as deleter

    auto deleter = [](double *p) {

      std::cout << "bye, bye unique pointer\n";

      delete p;

    };

    std::unique_ptr<double, std::function<void(double *)>> sp32(

        new double(42.4242), deleter);



    throw -1;

  } catch (int &n) {

    std::cout << "error but memory is cleaned up\n";

  }

  auto up = std::make_unique<int>(42);

  (*up)++;

  std::cout << "up: " << *up << '\n'; // 43

  auto up2 = std::make_unique<Point2d>(-1.0, 2.0);

  (*up2).print(); // (-1, 2)

  auto up3 = std::make_unique<Point2d>();

  (*up3).print();



  UP<double> up1(new double(148.413));

  up1.reset();

  assert(up1 == nullptr);

  // std::cout << "reset: " << *up1 << '\n';

  up1.reset(new double(3.1415));

  std::cout << "reset: " << *up1 << '\n';

  // Give ownership back to caller without calling deleter

  std::cout << "Release unique pointer\n";

  auto unip = std::make_unique<Point2d>(42.0, 44.5);

  Point2d *fp = unip.release();

  assert(unip.get() == nullptr);

  std::cout << "No longer owned by unique_ptr...\n";

  (*fp).print();

  delete fp; // Destructor of Point2d called

}