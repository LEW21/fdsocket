//  Copyright Joel de Guzman 2002-2004. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)
//  Hello World Example from the tutorial
//  [Joel de Guzman 10/9/2002]

#include <boost/python/module.hpp>
#include <boost/python/def.hpp>
#include <sys/socket.h>

int getfamily(int fd)
{
	sockaddr addr;
	socklen_t len = sizeof(addr);
	getsockname(fd, &addr, &len);
	if (len < 0)
		return 0;
	return int(addr.sa_family);
}

BOOST_PYTHON_MODULE(fdsocket)
{
	using namespace boost::python;
	def("getfamily", getfamily);
}
