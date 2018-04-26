#include<iostream>
#include<vector>
using namespace std;

class A
{
    public:
        A(){
            callA = 0;
        }
    private:
        int callA;
        void inc(){
            callA++;
        }

    protected:
        void func(int & a)
        {
            a = a * 2;
            inc();
        }
    public:
        int getA(){
            return callA;
        }
};

class B
{
    public:
        B(){
            callB = 0;
        }
    private:
        int callB;
        void inc(){
            callB++;
        }
    protected:
        void func(int & a)
        {
            a = a * 3;
            inc();
        }
    public:
        int getB(){
            return callB;
        }
};

class C
{
    public:
        C(){
            callC = 0;
        }
    private:
        int callC;
        void inc(){
            callC++;
        }
    protected:
        void func(int & a)
        {
            a = a * 5;
            inc();
        }
    public:
        int getC(){
            return callC;
        }
};
// My Implementation
vector<int> get_prime(int n);
class D :virtual public A,virtual public B,virtual public C
{

    int val;
    public:
        //Initially val is 1
         D()
         {
            val = 1;
         }


         //Implement this function
         void update_val(int new_val)
         {
         vector<int> v=get_prime(new_val);
         for(vector<int>::iterator it=v.begin();it!=v.end();++it){

            switch(*it){
            case 2: A::func(val);
            break;
            case 3: B::func(val);
            break;
            case 5: C::func(val);
            break;
            default:
            cout<<"In Default\n";
            }
        }//for

         }
         //For Checking Purpose
         void check(int); //Do not delete this line.
};

vector<int> get_prime(int n){
    vector<int>v;
    while(n%2==0){
        v.push_back(2);
        n/=2;
    }
    for(int i=3;i<=5;i+=2){
        while(n%i==0){
            v.push_back(i);
            n/=i;
        }
    }

    return v;

}
void D::check(int new_val)
{
    update_val(new_val);
    cout << "Value = " << val << endl << "A's func called " << getA() << " times " << endl << "B's func called " << getB() << " times" << endl << "C's func called " << getC() << " times" << endl;
}


int main()
{
    D d;
    int new_val;
    cin >> new_val;
    d.check(new_val);

}
