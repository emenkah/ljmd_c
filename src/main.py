


from ctypes import *

# import shared object on POSIX compatible OS
dso = CDLL(“./hello.so”)

force=dso.force



# call symbol in shared object as function w/o args
dso.hello()

