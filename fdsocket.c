#include "Python.h"
#include <sys/socket.h>

static int getfamily(int fd)
{
	struct sockaddr addr;
	socklen_t len = sizeof(addr);
	getsockname(fd, &addr, &len);
	if (len < 0)
		return 0;
	return (int) addr.sa_family;
}

PyDoc_STRVAR(fdsocket_doc, "Tool for determining socket family of a file descriptor.");
PyDoc_STRVAR(getfamily_doc, "Determines and returns the address family of an already opened socket with given file descriptor.");

static PyObject* py_getfamily(PyObject* self, PyObject* args)
{
	int fd, family;

	if (!PyArg_ParseTuple(args, "i:getfamily", &fd))
		return NULL;

	family = getfamily(fd);

	return PyLong_FromLong(family);
}

static PyMethodDef fdsocket_methods[] = {
	{"getfamily", py_getfamily, METH_VARARGS, getfamily_doc},
	{NULL, NULL}
};

static struct PyModuleDef fdsocket_module = {
	PyModuleDef_HEAD_INIT,
	"fdsocket",
	fdsocket_doc,
	-1,
	fdsocket_methods
};

PyMODINIT_FUNC PyInit_fdsocket(void)
{
	return PyModule_Create(&fdsocket_module);
}
