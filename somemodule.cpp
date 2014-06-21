#include "nr3python.h"  

// this is what "Hello, world" looks like
static PyObject* somefunction(PyObject *self, PyObject *pyargs) {
  printf("Hello, world!\n");
  return NRpyObject();
}

// standard boilerplate (don't worry, we'll explain)
static PyMethodDef somemodule_methods[] = {
  {"somefunction", somefunction, METH_VARARGS, "somefunction() doc string"},
  {NULL, NULL, 0, NULL}
};
PyMODINIT_FUNC initsomemodule(void) {
  import_array();
  Py_InitModule("somemodule", somemodule_methods);
}