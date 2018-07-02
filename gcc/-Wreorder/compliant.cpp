class C
{
    int someVal;
    int dependsOnSomeVal;
    

  public:
    C(int val) : someVal(val), dependsOnSomeVal(someVal + 1) {}
};

int main()
{
    return 0;
}
