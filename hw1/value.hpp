#ifndef VALUE_HPP
#define VALUE_HPP

enum Value_kind {
  int_val,
  bool_val,
};

union Value_data {
  int n;
  bool b;
};

// Discriminated union or variant.
struct Value {
  Value_kind kind;
  Value_data data;
};

#endif 
