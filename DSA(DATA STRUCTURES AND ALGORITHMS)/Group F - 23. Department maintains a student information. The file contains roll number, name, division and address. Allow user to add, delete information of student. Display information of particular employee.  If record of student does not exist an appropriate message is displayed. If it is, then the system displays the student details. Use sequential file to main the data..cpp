/* Group F - 23.
Department maintains a student information. The file contains roll number, name, division and address. Allow user to add, delete information
of student. Display information of particular employee.  If record of student does not exist an appropriate message is displayed. If it is, then
the system displays the student details. Use sequential file to main the data. */


#include<iostream>
#include<fstream>
#include<string.h>
#include<iomanip>
#include<stdlib.h>
using namespace std;

class record
{
	int roll;
	string div,name,address;

public:
	int l;

	record()
	{
		l=roll;
	}
	void accept();
	void display();
	int search(int);
};

void record::accept()
{
	cout<<endl<<"Enter name: ";
	cin>>name;
	cout<<"Enter roll number: ";
	cin>>roll;
	l=roll;
	cout<<"Enter address: ";
	cin>>address;
	cout<<"Enter division: ";
	cin>>div;
}

void record::display()
{
	cout<<endl<<roll<<setw(15)<<name<<setw(12)<<address<<setw(16)<<div;
}

int record::search(int x)
{
	if(roll==x)
		return 1;
	return 0;
}

int main()
{
	record r1[10],r2[20];

	int ch,n;

	do
	{
		cout<<endl<<endl<<"1.Add Record"<<endl<<"2.Display Record"<<endl<<"3.Search Record"<<endl<<"4.Delete"<<endl<<"5.Exit"<<endl<<"Enter your choice: ";
		cin>>ch;

		switch(ch)
		{
			case 1:
			{
				cout<<endl<<"Enter the number of records: ";
				cin>>n;

				ofstream fout;
				fout.open("records",ios::binary|ios::out);
				if(fout.fail())
				{
					cout<<endl<<"Error in opening the file !!";
					return 1;
				}

				for(int i=0; i<n; i++)
				{
					r1[i].accept();
					fout.write((char*)&r1[i],sizeof(r1[i]));
				}
				fout.close();
				break;
			}


			case 2:
			{
				ifstream fin;
				fin.open("records");

				cout<<endl<<endl<<"STUDENT DATABASE"<<endl;
				cout<<endl<<"Roll no."<<setw(10)<<"Name"<<setw(15)<<"Address"<<setw(17)<<"Division";
				for(int i=0; i<n; i++)
				{
					fin.read((char*)&r2,sizeof(r2));
					r2[i].display();
				}
				fin.close();
				cout<<endl;
				break;
			}


			case 3:
			{
				ifstream fin;
				fin.open("records");

				int r,z,s;
				cout<<endl<<"Enter the roll number you want to search: ";
				cin>>r;

				for(int i=0; i<n; i++)
				{
					fin.read((char*)&r2,sizeof(r2));
					z=r2[i].search(r);
					s=i;
					if(z==1)
						break;
				}

				if(z==1)
				{
					cout<<"Record found";
					cout<<endl<<"Roll no."<<setw(10)<<"Name"<<setw(15)<<"Address"<<setw(17)<<"Division";
					r2[s].display();
				}
				else
					cout<<"Record not present";

				fin.close();
				break;
			}


			case 4:
			{
				int d;
				cout<<endl<<"Enter the roll number you want to delete: ";
				cin>>d;
				cout<<"Record deleted";

				ofstream o("temp",ios::out|ios::binary);
				ifstream i("records",ios::in|ios::binary);

				record r3;
				while(i.read((char*)&r3,sizeof(r3)))
					if(r3.l!=d)
						o.write((char*)&r3,sizeof(r3));

				o.close();
				i.close();

				o.open("records",ios::binary|ios::out);
				i.open("temp",ios::in|ios::binary);

				while(i.read((char*)&r3,sizeof(r3)))
					o.write((char*)&r3,sizeof(r3));

				o.close();
				i.close();

				n=n-1;
				break;
			}


			case 5:
			 exit(0);		 
		}
	}while(ch>0 && ch<5);
}



/* OUTPUT


C:\Users\Sakshi Sutar\codes\ads>g++ -o seqFile seqFile.cpp

C:\Users\Sakshi Sutar\codes\ads>seqFile


1.Add Record
2.Display Record
3.Search Record
4.Delete
5.Exit
Enter your choice: 1

Enter the number of records: 3

Enter name: n1
Enter roll number: 1
Enter address: a1
Enter division: d1

Enter name: n2
Enter roll number: 2
Enter address: a2
Enter division: d2

Enter name: n3
Enter roll number: 3
Enter address: a3
Enter division: d3


1.Add Record
2.Display Record
3.Search Record
4.Delete
5.Exit
Enter your choice: 2


STUDENT DATABASE

Roll no.      Name        Address         Division
1             n1          a1              d1
2             n2          a2              d2
3             n3          a3              d3


1.Add Record
2.Display Record
3.Search Record
4.Delete
5.Exit
Enter your choice: 3

Enter the roll number you want to search: 1
Record found
Roll no.      Name        Address         Division
1             n1          a1              d1

1.Add Record
2.Display Record
3.Search Record
4.Delete
5.Exit
Enter your choice: 4

Enter the roll number you want to delete: 2
Record deleted

1.Add Record
2.Display Record
3.Search Record
4.Delete
5.Exit
Enter your choice: 2


STUDENT DATABASE

Roll no.      Name        Address         Division
1             n1          a1              d1
3             n3          a3              d3


1.Add Record
2.Display Record
3.Search Record
4.Delete
5.Exit
Enter your choice: 5

C:\Users\Sakshi Sutar\codes\ads>
*/
