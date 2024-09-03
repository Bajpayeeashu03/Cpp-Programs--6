#include <iostream>
#include <vector>
using namespace std;
class Test 
{
    private:
        vector<int> marks;
    public:
        void input() 
        {
            int n;
            cout << "Enter the number of subjects: ";
            cin >> n;
            for (int i = 0; i < n; i++) 
            {
                int m;
                cout << "Enter marks for subject " << i + 1 << ": ";
                cin >> m;
                while (m < 0) 
                {
                    cout << "Marks cannot be negative";
                    cin >> m;
                }
                marks.push_back(m);
            }
        }
        int& operator[](int subject) 
        {
            return marks[subject];
        }
        void compare(Test &obj) 
        {
            if (marks.size() != obj.marks.size()) 
            {
                cout << "Error! Both objects must have the same number of subjects." << endl;
                return;
            }
            for (int i = 0; i < marks.size(); i++) 
            {
                if (this->operator[](i) > obj[i])
                {
                    cout << "Subject " << i + 1 << ": First object has more marks." << endl;
                } else if (this->operator[](i) < obj[i]) 
                {
                    cout << "Subject " << i + 1 << ": Second object has more marks." << endl;
                } else 
                {
                    cout << "Subject " << i + 1 << ": Both objects have the same marks." << endl;
                }
            }
        }
};
int main()
{
    Test obj1, obj2;
    cout << "Enter Marks for First Object" << endl;
    obj1.input();
    cout << "Enter Marks for Second Object" << endl;
    obj2.input();
    obj1.compare(obj2);
    return 0;
}