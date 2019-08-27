from distutils.core import setup, Extension
# building C/C++ extension modules for Python
# https://docs.python.org/3/extending/building.html#building

module1 = Extension('spam', sources=['spammodule.c'])

setup (name = 'spam',
        version = '0.1',
        description = 'spam package allows system calls',
        ext_modules = [module1])


