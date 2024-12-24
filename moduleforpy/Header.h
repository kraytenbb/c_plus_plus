#pragma once

#include <Python.h>

static PyObject* Distinct(PyObject* self, PyObject* args);

static PyMethodDef ModuleMethods[] = {
    {"Distinct", Distinct, METH_VARARGS, "Returns a list of distinct elements from the input list"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef ModuleDefinition = {
    PyModuleDef_HEAD_INIT,
    "distinct_module", // Čě˙ ěîäóë˙
    "Module to find distinct elements of a list",
    -1,
    ModuleMethods
};

PyMODINIT_FUNC PyInit_distinct_module();
