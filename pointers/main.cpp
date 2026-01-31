#include <iostream>

struct Foo {
  int y{0};
};

/* using pure pointers in c++ requires foresight into
 * the life time and execution of the pointer
 * this causes potential memory missmanagment
 * thats why smart pointers are used to dynmaically
 * deallocate the memory*/

void someFunction() {
  Foo *ptr = new Foo();

  int x;
  std::cout << "Enter an integer: ";
  std::cin >> x;

  if (x == 0) return;  // the function returns early, and ptr won’t be deleted!

  // do stuff with ptr here

  delete ptr;
}

/*smart pointers work smililarly to a destructors for objects as in once the ptr
 * goes out of scope it gets deallocated */

// example use and limitation of destructor
template <typename T>
class Auto_ptr1 {
  T *m_ptr{};

 public:
  Auto_ptr1(T *ptr = nullptr) : m_ptr(ptr) {}

  ~Auto_ptr1() { delete m_ptr; }
  // to use objs like ptrs
  T &operator*() const { return *m_ptr; }
  T *operator->() const { return m_ptr; }
};

class Resource {
 public:
  Resource() { std::cout << "Resource acquired\n"; }
  ~Resource() { std::cout << "Resource destroyed\n"; }
};

int main() {
  /*we make an object from Auto_ptr1 class of argument <Resource> which is also
   * a class the object is res and in res we pass new Resource to the
   * constructor of Auto_ptr1 where new Resource() creates an unamed object from
   * the constructor of the Resource class the new keyword is used to return the
   * address of constructed obj now in the constructor of Auto_ptr1 we have a
   * template/genric T thus taking type Resource and then assigning m_ptr
   * contained within res to the Resource
   */

  // res1 and res2 hold the address of a created ---  std::cout << "Resource
  // acquired\n"; -- m_ptr within both of these objects point to the same object
  // Resource

  Auto_ptr1<Resource> res1(new Resource());
  Auto_ptr1<Resource> res2(res1);
  // Alternatively, don't initialize res2 and then assign res2 = res1;

  return 0;
}  // res1 and res2 go out of scope here

// CPU memory is considered stack and heap is for RAM
/* since res1 and res2 containted ptrs point to the same obj resource
 * once res2 is destruced (defined last so deted first) --delete m_ptr-- takes
 * the address from m_ptr and deletes the data in the ram or heap
 * res1 ends up dangling as in pointing to an adress containg nothing a trying
 * to wipe that memory THIS CAN CAUSE UNDEFINED BEHAVIOUR AND ERRORS*/

/*the adress and adress conating objects themselves get deleted once the
 * destructor is finished from the stack cpu */
