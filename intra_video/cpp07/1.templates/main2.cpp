#include <iostream>

template< typename T >
class List {
     public:
      List<T>(T const &content);
      List<T>(List<T> const &list);
     //  ~List<T>(void);
      T *getContent();

     private:
      T *_content;
      List<T> *_next;
};

template< typename T >
std::ostream &operator<<(std::ostream &o, const List<T>& src) {
      o << src;
      return (o);
}

template< typename T >
T *List<T>::getContent () {
      return _content;
}

// template< typename T >
// List<T>::List (T const &content) {
//      std::cout << this->_content << std::endl;
// }

int main(void) {
     List<int> a(42);
     std::cout << a.getContent() << std::endl;
     List<float> b(3.24f);
     std::cout << b.getContent() << std::endl;
     List<List<int> > c(a);
     std::cout << c.getContent() << std::endl;

     return 0;
}