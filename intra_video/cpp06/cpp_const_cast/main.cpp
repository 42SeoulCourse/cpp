int main(void) {
  int a = 42;

  int const *b = &a;
  // int  *c = b;
  int  *d = const_cast<int *>(b);

  return 0;
}