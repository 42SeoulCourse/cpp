int main(void) {
  float a = 420.042f;

  void *b = &a;
  int  *c = reinterpret_cast<int *>(b);
  int  &d = reinterpret_cast<int &>(b);

  return 0;
}