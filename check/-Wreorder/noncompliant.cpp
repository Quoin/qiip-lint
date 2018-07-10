class C
{
    int dependsOnSomeVal;
    int someVal;

  public:
    C(int val) : someVal(val), dependsOnSomeVal(someVal + 1) {}
};

int main()
{
    return 0;
}
