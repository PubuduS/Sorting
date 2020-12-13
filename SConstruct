# To run this program using scons, please run scons.
# To clean the artifacts use scons -c.

CVersion = 'c++11'

# This means header file is in the same location as the .cpp file.
# HeaderPath = '.'
HeaderPath = 'include/'

# Some old SCon version do not support SCONS_CXX_STANDARD. If you are run into this problem,
# please upload scons version or use this CXXFLAGS="-std=c++0x"
print('Path:' + Dir('.').abspath)

env=Environment(CPPPATH=HeaderPath,
                CPPDEFINES=[],
                LIBS=[],
                SCONS_CXX_STANDARD= CVersion
                )

env.Program('sorting' , Glob('*.cpp') )
