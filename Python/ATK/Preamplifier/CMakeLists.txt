
FILE(GLOB_RECURSE
  PYTHON_MODULE_PREAMPLIFIER_SRC
  *.cpp
)

FILE(GLOB_RECURSE
  PYTHON_MODULE_PREAMPLIFIER_HEADERS
  *.h
)

SET(PYTHON_MODULE_PREAMPLIFIER_DEFINITIONS)
SET(PYTHON_MODULE_PREAMPLIFIER_INCLUDE)
SET(PYTHON_MODULE_PREAMPLIFIER_LIBRARIES ATKCore ATKPreamplifier ATKUtility)

SET(PYTHON_MODULE_PREAMPLIFIER_NAME PythonPreamplifier)
SET(PYTHON_MODULE_PREAMPLIFIER_FOLDER Preamplifier)

ATK_add_python_module(PYTHON_MODULE_PREAMPLIFIER)
