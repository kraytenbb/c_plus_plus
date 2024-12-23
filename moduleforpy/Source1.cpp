#include "Header.h"
#include <set>
#include <vector>

static PyObject* Distinct(PyObject* self, PyObject* args) {
    PyObject* inputList; // Входящий список Python

    // Парсинг входящих аргументов
    if (!PyArg_ParseTuple(args, "O", &inputList)) {
        return NULL;
    }

    // Проверяем, является ли входящий объект списком
    if (!PyList_Check(inputList)) {
        PyErr_SetString(PyExc_TypeError, "Argument must be a list");
        return NULL;
    }

    std::set<long> uniqueElements; // Множество для хранения уникальных элементов
    Py_ssize_t listSize = PyList_Size(inputList);

    // Заполняем множество уникальными элементами из списка
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

    // Создаем Python-список из уникальных элементов
    PyObject* resultList = PyList_New(uniqueElements.size());
    Py_ssize_t index = 0;
    for (const auto& element : uniqueElements) {
        PyList_SetItem(resultList, index, PyLong_FromLong(element));
        index++;
    }

    return resultList; // Возвращаем результат
}

PyMODINIT_FUNC PyInit_distinct_module() {
    return PyModule_Create(&ModuleDefinition);
}
