#include <pybind11/pybind11.h>
#include <pybind11/embed.h>
#include <pybind11/numpy.h>

namespace py = pybind11;

class CallPy {
public:
    static py::scoped_interpreter guard;

    CallPy() = default;

    static void Call();
};
