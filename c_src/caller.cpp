#include "caller.hpp"

namespace py = pybind11;

// init
py::scoped_interpreter CallPy::guard = py::scoped_interpreter{};

void CallPy::Call() {
      auto printer = py::module_::import("fcpy");
      auto result = printer.attr("hola")().cast<py::array_t<double>>();
      py::print(result);
}


extern "C" {
  void callme() {
    CallPy::Call();
  }
}
