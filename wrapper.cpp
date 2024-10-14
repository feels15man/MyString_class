#include <pybind11/pybind11.h>
#include "MyString.h"

namespace py = pybind11;

PYBIND11_MODULE(MyString, m) {
    py::class_<MyString>(m, "MyString")
        .def(py::init<>())                    // Конструктор с параметром int
        .def(py::init<const char *, int>())   // Конструктор с параметром int
        .def(py::init<int, const char>())     // Конструктор с параметром int
        .def(py::init<const MyString &>())    // Конструктор с параметром int
        .def(py::init<const char *>())        // Конструктор с параметром int
        .def(py::init<const std::string &>()) // Конструктор с параметром int

        .def("data", &MyString::data)
        .def("clear", &MyString::clear)
        .def("length", &MyString::length)
        .def("empty", &MyString::empty)
        .def("shrink_to_fit", &MyString::shrink_to_fit)
        .def("size", &MyString::size)
        .def("capacity", &MyString::capacity)
        .def("c_str", &MyString::data)

        .def("insert", py::overload_cast<unsigned int, unsigned int, const char>(&MyString::insert))
        .def("insert", py::overload_cast<int, const char *>(&MyString::insert))
        .def("insert", py::overload_cast<int, const char *, int>(&MyString::insert))        // Явное указание на метод
        .def("insert", py::overload_cast<int, const std::string &>(&MyString::insert))      // Явное указание на метод
        .def("insert", py::overload_cast<int, const std::string &, int>(&MyString::insert)) // Явное указание на метод

        .def("append", py::overload_cast<int, const char>(&MyString::append))
        .def("append", py::overload_cast<const char *>(&MyString::append))
        .def("append", py::overload_cast<const char *, int, int>(&MyString::append))
        .def("append", py::overload_cast<std::string &>(&MyString::append))
        .def("append", py::overload_cast<std::string &, int, int>(&MyString::append))

        .def("erase", py::overload_cast<int, int>(&MyString::erase))

        .def("replace", py::overload_cast<int, int, const char *>(&MyString::replace))
        .def("replace", py::overload_cast<int, int, std::string &>(&MyString::replace))

        .def("substr", py::overload_cast<int>(&MyString::substr))
        .def("substr", py::overload_cast<int, int>(&MyString::substr))

        .def("find", py::overload_cast<const char *>(&MyString::find))
        .def("find", py::overload_cast<const char *, int>(&MyString::find))
        .def("find", py::overload_cast<std::string &>(&MyString::find))
        .def("find", py::overload_cast<std::string &, int>(&MyString::find))

        .def("__repr__", &MyString::c_str)
        .def("__len__", &MyString::length)
        .def("__lt__", &MyString::operator<, py::is_operator())
        .def("__le__", &MyString::operator<=, py::is_operator())
        .def("__eq__", &MyString::operator==, py::is_operator())
        .def("__gt__", &MyString::operator>, py::is_operator())
        .def("__ge__", &MyString::operator>=, py::is_operator())
        
        .def("__add__", py::overload_cast<const MyString &>(&MyString::operator+))
        .def("__add__", py::overload_cast<const std::string &>(&MyString::operator+))
        .def("__add__", py::overload_cast<const char *>(&MyString::operator+))

        .def("__iadd__", py::overload_cast<const char *>(&MyString::operator+=))
        .def("__iadd__", py::overload_cast<const std::string &>(&MyString::operator+=))
        .def("__iadd__", py::overload_cast<const MyString &>(&MyString::operator+=))

        .def("__ne__", &MyString::operator!=, py::is_operator());
}
