#ifndef TOY_LANG_ERROR
#define TOY_LANG_ERROR

#include <stdexcept>

struct SyntaxError : public std::runtime_error {
  using std::runtime_error::runtime_error;
};

struct RuntimeError : public std::runtime_error {
  using std::runtime_error::runtime_error;
};

struct NameError : public std::runtime_error {
  using std::runtime_error::runtime_error;
};

#endif