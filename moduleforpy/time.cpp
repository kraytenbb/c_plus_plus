#include <Python.h>
#include <set>
#include <chrono>
#include <iostream>

static PyObject* Distinct(PyObject* self, PyObject* args) {
    PyObject* inputList;

    if (!PyArg_ParseTuple(args, "O", &inputList)) {
        return NULL;
    }

    if (!PyList_Check(inputList)) {
        PyErr_SetString(PyExc_TypeError, "Argument must be a list");
        return NULL;
    }

    std::set<long> uniqueElements;
    Py_ssize_t listSize = PyList_Size(inputList);

    // Начало замера времени
    auto start = std::chrono::high_resolution_clock::now();

    for (Py_ssize_t i = 0; i < listSize; i++) {
        PyObject* item = PyList_GetItem(inputList, i);
        if (PyLong_Check(item)) {
            uniqueElements.insert(PyLong_AsLong(item));
        }
        else {
            PyErr_SetString(PyExc_TypeError, "List must contain only integers");
            return NULL;
        }
    }

    PyObject* resultList = PyList_New(uniqueElements.size());
    Py_ssize_t index = 0;
    for (const auto& element : uniqueElements) {
        PyList_SetItem(resultList, index, PyLong_FromLong(element));
        index++;
    }

    // Конец замера времени
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    // Вывод времени выполнения
    std::cout << "Время выполнения Distinct: " << elapsed.count() << " секунд" << std::endl;

    return resultList;
}
