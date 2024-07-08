# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "src/Desktop/CMakeFiles/TNGemBrowser_autogen.dir/AutogenUsed.txt"
  "src/Desktop/CMakeFiles/TNGemBrowser_autogen.dir/ParseCache.txt"
  "src/Desktop/TNGemBrowser_autogen"
  "src/core/CMakeFiles/core_autogen.dir/AutogenUsed.txt"
  "src/core/CMakeFiles/core_autogen.dir/ParseCache.txt"
  "src/core/core_autogen"
  "tests/CMakeFiles/GemBrowserTests_autogen.dir/AutogenUsed.txt"
  "tests/CMakeFiles/GemBrowserTests_autogen.dir/ParseCache.txt"
  "tests/GemBrowserTests_autogen"
  )
endif()
