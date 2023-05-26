#include <iostream>
using namespace std;
int s = 1 ;

struct student{
    int id ;
    int available_money ;
    string name ;
    int subject[3];
              };

student arr[100];

 // the first input option function - 1

void add_student(){
bool lessmoney=0;
if(s>100) cout<<"Error you exceeded the maximum number of students\n";
else {
    int id;
    bool flag=1;
    cout << "\t Adding a new student.\n";
    while(flag)
		{

        cout<< "Please enter id for a new student: " ;
        cin >> id ;
		flag = 0 ;

		//check if id is repeated
        for (int i = 1; i < s; i++) {
            if(id == arr[i].id)
                {
                    flag = 1 ; //to repeat again
                    cout << "Error there is a student with this id\n";
                }
                                    }
        }

        //storing the id,name,money in structure
		arr[s].id=id;
        cout << "Please Enter your first name: " ;
        cin >> arr[s].name ;
        cout << "Please Enter available money: ";
        cin >> arr[s].available_money ;

        // if money less than 2000 ask him to increase it or exit
        while (arr[s].available_money<2000)
        {
            cout<<"\nMoney isn't suffecient to register, Do you want to change it?\n1.Yes 2.NO\n";
            int ans=0;
            cin>>ans;
            if(ans==1)
            {
                               cout <<"\nPlease Enter available money: ";
                cin >> arr[s].available_money ;
            }
            else {
                lessmoney=1;
                break;
            }

        }
        if (lessmoney) return;

    // receiving the courses
    bool courses=true;
       while(courses)
    {
		int sum=0;
		cout << "The available subjects:\n"
        << "1) Programming languages.   Fee 1000\n"
        << "2) Technical writing.       Fee 400\n"
        << "3) Software Engineering.    Fee 1000\n"
        << "4) Database.                Fee 600\n"
        << "Please choose first subject number to enroll in: ";

    cin >> arr[s].subject[0] ;
    cout<< "Please choose second subject number to enroll in: " ;
    cin >> arr[s].subject[1] ;
    cout << "Please choose third subject number to enroll in: ";
    cin >> arr[s].subject[2] ;

    // calculating the cost of the chosen courses

     for(int i=0;i<3;i++)
   {
	if (arr[s].subject[i]==1||arr[s].subject[i]==3)
		sum+=1000;
	else if (arr[s].subject[i]==2)
		sum+=400;
	else if (arr[s].subject[i]==4)
		sum+=600;
   }
//comparing
     if(sum<=arr[s].available_money){ cout<<"student is successfully added\n\n";
			s++ ;
			break; }
    else if(sum>arr[s].available_money) {
    cout<<"\n\nError your fees is less than the total fees of subjects you want to enroll in\nPlease choose subjects to enroll in again\n\n";}
}

}}


// the second input option function

void edit_student(){
    cout << " \t Edit a student.\n";

		 int id;
		 bool flag=0;
         while(!flag)
{
		cout << "Please enter id for a student to edit:  " ;
        cin >> id ;
		// checking valid id
		flag = 0 ;
    for (int i = 1; i < s; i++) {
        if(id == arr[i].id){
            flag = 1 ;
						break;
						}
     }
		if (!flag) cout << "Error there is no student with this id\n";
}

		cout << "Please Enter your student new name: " ;
	    cin >> arr[s].name ;
        cout << "Please Enter your student new available money:  ";
	    cin >> arr[s].available_money ;

   while(true)
    {
		int sum=0;
		cout << "The available subjects:\n"
        << "1) Programming languages.   Fee 1000\n"
        << "2) Technical writing.       Fee 400\n"
        << "3) Software Engineering.    Fee 1000\n"
        << "4) Database.                Fee 600\n"
        << "Please choose first subject number to enroll in: ";
    cin >> arr[s].subject[0] ;
    cout << "Please choose second subject number to enroll in: " ;
    cin >> arr[s].subject[1] ;
    cout << "Please choose third subject number to enroll in: ";
    cin >> arr[s].subject[2] ;

    for(int i=0;i<3;i++)
{
	if (arr[s].subject[i]==1||arr[s].subject[i]==3)
		sum+=1000;
	else if (arr[s].subject[i]==2)
		sum+=400;
	else if (arr[s].subject[i]==4)
		sum+=600;
}

if(sum<=arr[s].available_money)
    { cout<<"student is successfully edited\n\n";
			break; }
else if(sum>arr[s].available_money)
{cout<<"\n\nError your fees is less than the total fees of subjects you want to enroll in\nPlease choose subjects to enroll in again\n\n";}
}
}

// third input option function
    void print_students(){

    for (int i = 1; i < s; ++i)
        {
        cout <<i<<") Name is "<< arr[i].name <<", and subjects are: (" ;
        for(int j=0; j<3; j++)
				{ if(arr[i].subject[j]==1)
						cout<<" Programming languages ";
					else if(arr[i].subject[j]==2)
						cout<<" Technical writing ";
					else if(arr[i].subject[j]==3)
						cout<<" Software Engineering ";
					else if(arr[i].subject[j]==4)
						cout<<" Database ";
					cout<<",";}
			cout<<")"<<endl;
			cout<<endl;
    }
}
int main() {
		int input;
        int ans=0;

		while (true) {

        cout << "\t --- Registration of students in college --- \t"<<endl;
        cout<< "1.  Add student.\n"<< "2.  Edit student"<<endl;
        cout<< "3.  Show all students in system.\n"<< "Please choose one from above choices:  \n";
        cin >> input ;

        if (input == 1) {
            add_student();

        } else if (input == 2) {
            edit_student();
        } else if (input == 3) {
            print_students();

        } else {
            cout << "you entered invalid number";
        }
        cout<<"\nDo You want to make another process?\n1.Yes 2.NO\n";
            ans=0;
            cin>>ans;
            if (ans!=1) { cout<<"Thank You!"; return 0;  }

        }


    return 0;
}
