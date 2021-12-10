from distutils.core import setup, Extension
setup(name='Hello', version='1.0',  \
      ext_modules=[Extension('Hello', ['hello.cpp'])])

setup(name='spam', version='1.0',  \
      ext_modules=[Extension('spam', ['hello.cpp'])])