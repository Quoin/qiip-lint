#include <memory>
#include <stdlib.h>
  
struct Base {
  virtual void f();
};
  
struct Derived : Base {};
  
void f() {
  std::unique_ptr<Base> b = std::make_unique<Derived()>();
}
int main(){
    return 0;
}
