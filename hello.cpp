
#define PY_SSIZE_T_CLEAN

#include <Python.h>

static PyObject* helloworld(PyObject* self) {

   return Py_BuildValue("s", "Hello, Python extensions!!");
}

static char helloworld_docs[] =
   "helloworld( ): Any message you want to put here!!\n";

// static PyMethodDef helloworld_funcs[] = {
//    {"helloworld", (PyCFunction)helloworld, 
//       METH_NOARGS, helloworld_docs},
//       {NULL}
// };
static PyMethodDef module_methods[] = {
    {"helloworld", (PyCFunction) helloworld, 
     METH_NOARGS, helloworld_docs},
    {NULL}
};


static struct PyModuleDef Hello =
{
    PyModuleDef_HEAD_INIT,
    "Hello", /* name of module */
    "usage: Hello.helloworld()\n", /* module documentation, may be NULL */
    -1,   /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    module_methods
};

PyMODINIT_FUNC PyInit_Hello(void)
{
    return PyModule_Create(&Hello);
}


// #include <Python.h>

// static PyObject* uniqueCombinations(PyObject* self)
// {
//     return Py_BuildValue("s", "uniqueCombinations() return value (is of type 'string')");
// }

// static char uniqueCombinations_docs[] =
//     "usage: uniqueCombinations(lstSortableItems, comboSize)\n";


// static PyMethodDef module_methods[] = {
//     {"uniqueCombinations", (PyCFunction) uniqueCombinations, 
//      METH_NOARGS, uniqueCombinations_docs},
//     {NULL}
// };



// static struct PyModuleDef Combinations =
// {
//     PyModuleDef_HEAD_INIT,
//     "Combinations", /* name of module */
//     "usage: Combinations.uniqueCombinations(lstSortableItems, comboSize)\n", /* module documentation, may be NULL */
//     -1,   /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
//     module_methods
// };

// PyMODINIT_FUNC PyInit_Combinations(void)
// {
//     return PyModule_Create(&Combinations);
// }


//spam.system(string)
static PyObject *SpamError; // create new exception
static char spam_doc[] =
   "Ps( ): Any message you want to put here!!\n";
static PyObject *
spam_system(PyObject *self, PyObject *args)

{
    const char *command;
    int sts;

    if (!PyArg_ParseTuple(args, "s", &command)) //how the function received value from python
        return NULL;
    sts = system(command); //perform code here example perform 
    // cout<<command<<endl;
    if (sts < 0) {
        PyErr_SetString(SpamError, "System command failed");
        return NULL;
    }
    return PyLong_FromLong(sts); // how function return value in python
}



//lists all method
static PyMethodDef SpamMethods[] = {
    {"system",  spam_system, METH_VARARGS,
     "Execute a shell command."},

    {NULL, NULL, 0, NULL}        /* Sentinel */
};
//initialize module
static struct PyModuleDef spammodule = {
    PyModuleDef_HEAD_INIT,
    "spam",   /* name of module */
    spam_doc, /* module documentation, may be NULL */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    SpamMethods
};




PyMODINIT_FUNC
PyInit_spam(void)
{
    PyObject *m;

    m = PyModule_Create(&spammodule);
    if (m == NULL)
        return NULL;

    SpamError = PyErr_NewException("spam.error", NULL, NULL); // create class of exception in python
    Py_XINCREF(SpamError);
    if (PyModule_AddObject(m, "error", SpamError) < 0) {
        Py_XDECREF(SpamError);
        Py_CLEAR(SpamError);
        Py_DECREF(m);
        return NULL;
    }

    return m;
}

















