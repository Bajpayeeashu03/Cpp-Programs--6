#include <iostream>
#include<stdlib.h>
using namespace std;
class shape {
protected:
    int side;
public:
    void input() {
        try 
        {
            cout << "Enter the side: ";
            cin >> side;
            if (side <= 0) 
            {
                throw runtime_error("Side must be a positive integer.");
            }
        } catch (exception& a) 
        {
           cout<<a.what() << endl;
           exit(1);
        }
    }
};

class square : public shape {
public:
    void areasquare() {
        shape::input();
        cout << "The area of square is: " << side * side << endl;
    }
};

class rectangle : public shape {
private:
    int length;

public:
    void arearect() {
        shape::input();
        try 
        {
            cout << "Enter the length: ";
            cin >> length;
            if (length <= 0) 
            {
                throw runtime_error("Length must be a positive integer.");
            }
            cout << "The area of rectangle is: " << side * length << endl;
        } catch (exception& a) 
        {
            cout<<a.what()<< endl;
            exit(1);
        }
    }
};
int main() {
    try 
    {
        square obj1;
        rectangle obj2;
        obj1.areasquare();
        obj2.arearect();
    } catch (exception& a) 
    {
        cout<< a.what() << endl;
        exit(1);
    }
    return 0;
}