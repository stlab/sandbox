# Add source to this project's executable.
# Note: We're taking an opinionated approach here by using GLOB and CONFIGURE_DEPENDS.
# The discussion is well-summarized here:
# https://stackoverflow.com/questions/1027247/is-it-better-to-specify-source-files-with-glob-or-each-file-individually-in-cmak/18538444#18538444
# and here:
# https://discourse.cmake.org/t/is-glob-still-considered-harmful-with-configure-depends/808/6
# In short, the tradeoff is between a simpler add-file flow (just add a file to the appropriate directory), and
# 1. future compatibility with generators unable to support CONFIGURE_DEPENDS,
# 2. theoretical configure-time performance overhead (actual measurements are required here)
# Since this project is intended for rapid experimentation and "it just works" configuration for small projects,
# these two drawbacks are acceptable; we know our current generator (ninja) supports CONFIGURE_DEPENDS, and we
# expect our project sizes to be consistently small to make the overhead in 2) imperceptible.
file(GLOB_RECURSE sources CONFIGURE_DEPENDS "*.cpp")
file(GLOB_RECURSE headers_h CONFIGURE_DEPENDS "*.h")
file(GLOB_RECURSE headers_hpp CONFIGURE_DEPENDS "*.hpp")
add_executable (Sandbox ${sources} ${headers_h} ${headers_hpp})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Sandbox PROPERTY CXX_STANDARD 20)
endif()

find_package(doctest CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(stlab CONFIG REQUIRED)
find_package(ZLIB REQUIRED)

target_link_libraries(Sandbox PRIVATE doctest::doctest fmt::fmt stlab::stlab ZLIB::ZLIB)
