#define PY_SSIZE_T_CLEAN
#include <Python.h>

static PyObject* spam_system(PyObject* self, PyObject* args) {
    const char *command;
    int status;

    if(!PyArg_ParseTuple(args, "s", &command))
        return NULL;
    status = system(command);
    return PyLong_FromLong(status);
}

static PyMethodDef SpamMethods[] = {
    {"system", spam_system, METH_VARARGS, "Execute a shell command."},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef spammodule = {
    PyModuleDef_HEAD_INIT,
    "spam", /*name of module*/
    NULL, /* spam_doc-> module documentatio, Null if none*/
    -1, /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    SpamMethods 
};

// The initialization function must be named PyInit_name(), where name is the name of the module, and should be the only non-static item defined in the module file

PyMODINIT_FUNC PyInit_spam(void) {
    return PyModule_Create(&spammodule);
}

