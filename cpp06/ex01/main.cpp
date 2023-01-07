#include "Data.hpp"

uintptr_t serialize(Data *ptr) { return reinterpret_cast<uintptr_t>(ptr); }

Data *deserialize(uintptr_t raw) { return reinterpret_cast<Data *>(raw); }

int main() {
  Data *data = new Data;

  uintptr_t ptr = serialize(data);
  Data     *new_data = deserialize(ptr);

  std::cout << "data : " << data << ", new data : " << new_data << std::endl;
}