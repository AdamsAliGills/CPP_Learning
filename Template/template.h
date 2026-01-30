#pragma once

/*BEST PRACTICE Use function templates to write generic code that can work
 * with a wide variety of types whenever you have the need.*/

/*modular template use is exclusivley in .h file
  because linker wont understad otherwise in .cpp file
  templates are used for functions that can work for many types
  or even for classes - they genteerate the function for its respective called
  type*/

/*The compiler sees you used max_int_only
 (assumes usecase of func is called) It effectively pauses, "writes"
 separate functions for you*/

// HAS TO BE DECLATED EACH USE
template <typename T>  // sometimes typname is aslo refered to class aswell
T max_int_only(T x, T y) {
  return (x < y) ? y : x;  // condition ? value_if_true : value_if_false (fancy
                           // but efectivley the same way of if else)
}

// for more than one type use auto keyword and mupltiple typnames
template <typename T, typename U>
auto max_multi_type(T x, U y) {
  return (x < y) ? y : x;
}
// classes and structs work much the same way more instantiations
// class type have to use < > when initilizing object
template <typename T, typename U>
struct Pair {
  T one{};
  U two{};
};

template <typename T, typename U>
constexpr auto max_pair(Pair<T, U> p) {
  return (p.one < p.two) ? p.two : p.one;
}

/*if an non template function exists and we have correct arguments in a call
  the compile will prefer the already existing fuction over the template*/

/*Favor the normal function call syntax when making calls to a function
  instantiated from a function template (unless you need the function template
  version to be preferred over a matching non-template function) i.e max<int>(1,
  2).*/
