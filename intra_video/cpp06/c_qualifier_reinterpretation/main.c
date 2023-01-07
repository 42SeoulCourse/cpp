int main(void) {
    int a = 42;
    int const *b = &a;
    int const *c = (int const *)&a;

    int const *d = &a;
    int       *e = d;
    int       *f = (int *)d;
    return (0);
}