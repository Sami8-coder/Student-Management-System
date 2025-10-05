#include<bits/stdc++.h>
using namespace std;
class students{
    public:
    string name;
    int roll;
    string dept;
    float cgpa;
    void inputdata()
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter your Name:" << endl;
        getline(cin,name);
       // cin.ignore();
        cout << "Please enter your Dept:"<<endl;
getline(cin,dept);
//cin.ignore();
        cout<<"Please enter your Roll:"<<endl;
        cin>>roll;     
        cout << "Please enter your CGPA:"<<endl;
        cin>>cgpa;
    }
    void displaydata(){
       
cout<<"Your Info:"<<endl;
cout << "Name:" << name << endl;
cout << "Dept:" << dept << endl;
cout<<"Roll:"<<roll<<endl;
cout << "CGPA:" << cgpa << endl;
 cout<<" "<<endl;
    }
};
int main()
{
vector<students>student;
int choice;
do{
    cout << "--^--Student Management System--^--"<<endl;
    cout << "1. Add Student"<<endl;
    cout << "2. Show All Students"<<endl;
    cout << "3. Search Student by name"<<endl;
    cout << "4. Search Student by CGPA"<<endl;
    cout << "5. Search Student by Dept" << endl;
    cout << "6. Search Student by Roll"<<endl;
    cout << "7. Update Student by Roll\n";
    cout << "8. Delete Student by Roll\n";
    cout << "9. Show Average, Highest & Lowest CGPA" << endl;
    cout << "10. Exit"<<endl;
    cout<<"Please Enter Your Choice:"<<endl;
    cout<<" "<<endl;
    cin>>choice;
    cin.ignore();
     if(choice==1)
     {
        students s;
        s.inputdata();
        student.push_back(s);
        cout << "('-') Student Added Successfully!\n"
             << endl;
        cout<<" "<<endl;
     }
     else if(choice==2){
         cout << "\n--- Student List ---\n";
         for(auto &s:student)
         {
            s.displaydata();
         }

     }
     else if(choice==3)
     {
        string name;
        //cin.ignore();
         cout << "Enter Name to Search: ";
         getline(cin,name);
         bool found =false;
         for(auto &s:student)
         {
            if(s.name==name)
            {
                s.displaydata();
                found =true;
               // break;
            }
         }
         if(!found)
             cout << ":) Student Not Found!\n";
     }
     else if(choice==4)
     {
       float cgpa;
        bool found=false;
         cout << "Enter CGPA to Search: ";
         cin >> cgpa;
         for (auto &s : student)
         {
             if (s.cgpa == cgpa)
             {
s.displaydata();
found =true;
//break;
             }
        }
        if (!found)
            cout << ":) Student Not Found!\n";
     }
     else if(choice==5)
    {
        cin.ignore();
        string dept;
        cout << "Enter Dept to Search: ";
        getline(cin,dept);
        bool found=false;
        for(auto &s:student)
        {
            if(s.dept==dept)
            {
                s.displaydata();
                found=true;
                //break;
            }
        }
        if (!found)
            cout << ":) Student Not Found!\n";
    }

     else if(choice==6)
     {
        int roll;
        cout<<"Enter Roll to Search:"<<endl;
        cin>>roll;
        bool found=false;
        for(auto &s:student)
        {
            if(s.roll==roll)
            {
            s.displaydata();
            found=true;
            //break;
            }
        }
        if(!found)
        {
            cout << ":) Student Not Found!\n";
        }
        
     }
     else if(choice==7)
     {
         int roll;
         cout << "Enter Roll to Update: "<<endl;
         cin >> roll;
         bool found = false;
         for(auto &s:student)
         {
            if(s.roll==roll)
            {
                cout << "Enter New Details:\n";
                s.inputdata();
                cout << "('-') Student Updated Successfully!\n"
                     << endl;
                found=true;


            }
         }
         if (!found)
             cout << ":) Student Not Found!\n";
     }
     else if(choice==8)
     {
        int roll;
        cout << "Enter Roll to Delete: ";
        cin>>roll;
        bool found=false;
        for(auto it=student.begin();it!=student.end();++it)
        {
if(it->roll==roll)
{
    student.erase(it);
    cout << "|_-_| Student Deleted Successfully!\n";
    found = true;
    break;
}
        }
        if (!found)
            cout << ":) Student Not Found!\n";
     }
 else if(choice==9)
 {
    if(student.empty())
    {
        cout << ":) No data to calculate CGPA stats!\n";
    }
    else {
        float sum=0;
        float highest=student[0].cgpa,lowest=student[0].cgpa;
        string highname=student[0].name,lowname=student[0].name;
        for(auto &s:student)
        {
            sum+=s.cgpa;
            if(s.cgpa>highest)
            {
                highest=s.cgpa;
                highname=s.name;
            }
         if(s.cgpa<lowest){
            lowest=s.cgpa;
            lowname=s.name;
            }
        }
   
    float avg=sum/student.size();
    cout << "\n CGPA Statistics:" << endl;
    cout << "Average CGPA: " << avg << endl;
    cout<<"Highest CGPA: "<<highest<<"("<<highname<<")"<<endl;
    cout<<"Lowest CGPA: "<<lowest<<"("<<lowname<<")"<<endl;
    }
}
     else if(choice==10)
     {
         cout << "Exiting...\n";
     }
     else
         cout << ":) Invalid";
}
while(choice!=10);
return 0;
}