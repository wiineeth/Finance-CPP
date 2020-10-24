#include <iostream>

#include <memory>

template <typename T> using SP = std::shared_ptr<T>;

template <typename T> struct Deleter {

  void operator()(T *t) const {

    std::cout << "delete memory from function object \n";

    delete t;

  }

};



SP<double> sp1;                      // empty shared pointer

SP<double> sp2 = nullptr;            // empty shared ptr for Nullptr

SP<double> sp3(new double(148.143)); // ptr owning raw pointer

SP<double> sp4 = sp3;                // share ownership with sp3;

SP<double> sp5 = sp4;                // share ownership with sp4 and sp3;



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

  SP<double> sp6(new double(148.413), Deleter<double>());

  // Deleter as lambda Function

  SP<double> sp7(new double(159.153), [](double *p) {

    std::cout << "bye from lambda function\n";

    delete p;

  });

  // Stored lambda function as a deleter

  auto deleter = [](double *p) {

    std::cout << "bye from stored lambda\n";

    delete p;

  };

  SP<double> sp8(new double(169.693), deleter);
//reseting shared pointers
sp2.reset(new double(420));
std::cout << "sp2 sole owner? " << std::boolalpha << sp2.unique() << '\n';
}