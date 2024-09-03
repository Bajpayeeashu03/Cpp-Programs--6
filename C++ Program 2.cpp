#include <iostream>
#include <cmath>
#include <exception>
using namespace std;
class invalid : public exception
{
   public :
   const char* what() const throw()
   {
       return "Sum Of Two Sides Must Be Greater Than The Third Side";
   }
};
double calculate(double a, double b, double c) 
{
    if (a + b <= c || b + c <= a || c + a <= b) 
    {
        throw invalid();
    }
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}
int main() {
    double a, b, c;
    cout << "Enter the sides :" << endl;
    cout << "Side a: ";
    cin >> a;
    cout << "Side b: ";
    cin >> b;
    cout << "Side c: ";
    cin >> c;
    try {
        double area = calculate(a, b, c);
        cout << "Area is: " << area << endl;
    }
    catch (exception& a) 
{
        cout << a.what() << endl;
}
    return 0;
}