#include <iostream>

#include <memory>

template <typename T> using sp = std::shared_ptr<T>;

template <typename T> struct Deleter {

  void operator()(T *t) const {

    std::cout << "delete memory from function object \n";

    delete t;

  }

};



sp<double> sp1;                      // empty shared pointer

sp<double> sp2 = nullptr;            // empty shared ptr for Nullptr

sp<double> sp3(new double(148.143)); // ptr owning raw pointer

sp<double> sp4 = sp3;                // share ownership with sp3;

sp<double> sp5 = sp4;                // share ownership with sp4 and sp3;



int main() {

  std::cout << "sp2 shared # " << sp2.use_count() << '\n';

  std::cout << "sp3 shared # " << sp3.use_count() << '\n';

  std::cout << "sp4 shared # " << sp4.use_count() << '\n';

  std::cout << "sp5 shared # " << sp5.use_count() << '\n';

  sp3 = sp2; // sp3 now shares ownership with sp2 and no longer has ownership of

             // its previous resources;

  std::cout << "sp2 shared # " << sp2.use_count() << '\n';

  std::cout << "sp3 shared # " << sp3.use_count() << '\n';

  std::cout << "sp4 shared # " << sp4.use_count() << '\n';

  // Creating shared pointers with user-defined deleters

  // Deleter as function object

  sp<double> sp6(new double(148.413), Deleter<double>());

  // Deleter as lambda Function

  sp<double> sp7(new double(159.153), [](double *p) {

    std::cout << "bye from lambda function\n";

    delete p;

  });

  // Stored lambda function as a deleter

  auto deleter = [](double *p) {

    std::cout << "bye from stored lambda\n";

    delete p;

  };

  sp<double> sp8(new double(169.693), deleter);

}