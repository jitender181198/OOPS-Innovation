#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
//base class
class board
{
  public:
	int e_year;
	char b_name[10];
	int b_code;
	void showboard()
	{
		cout << "===================================================================================";		cout <<
"\n                                  BOARD INFORMATION                                      \n";
		cout << "===================================================================================";		cout << "\nPlease enter board  name:";
		cin >> b_name;
		cout << "Please enter board code:";
		cin >> b_code;
	}
};
//Single level inheritance
class centre : public board
{
  public:
	char c_name[20];
	int e_year, t_student, a_can, p_student, a_student;
	void cen_info()
	{
		cout << "\n\ncentre informaton";
		cout << "\nPlease enter centre name:";
		cin >> c_name;
		cout << "Please enter the exam year:";
		cin >> e_year;
	}
	void grade_info()
	{
		cout << "enter number A+ candidates:";
		cin >> a_can;
		cout << "enter number of B to E candidates:";
		cin >> p_student;
		cout << "enter number of F candidates:";
		cin >> a_student;
		t_student = a_can + p_student + a_student;
		cout << "total student is:";
		cout << t_student;
	}
};
//Heirarchical Inheritance
class student : public board
{
	char s_name[15];
	char s_id[10];
	float s_gpa;

  public:
	void getinfo()
	{
		char name[15], id[10];
		cout << "\n\nstudents result information";
		cout << "\nPlease insert students name:";
		cin >> name;
		//use of copy string to display full name
		strcpy(s_name, name);
		cout << "Please insert students roll no.:";
		cin >> id;
		strcpy(s_id, id);
	}
	void showinfo()
	{
		cout << "\n\n INFORMATION\n\n";
		cout << "Name:" << s_name << "\n\n";
		cout << "Roll no.:" << s_id << "\n\n";
		cout << "CGPA:" << s_gpa << "\n\n";
	}
	float showgrade(int s);
	//Use of inline function
	inline void calculate()
	{
		float gp, sum = 0;
		int s;
		cout << "\nenter score in English:";
		cin >> s;
		gp = showgrade(s);
		sum = sum + gp;

		cout << "\nenter score in Computer Science:";
		cin >> s;
		gp = showgrade(s);
		sum = sum + gp;

		cout << "\nenter score in Math:";
		cin >> s;
		gp = showgrade(s);
		sum = sum + gp;

		cout << "\nenter score in Physics:";
		cin >> s;
		gp = showgrade(s);
		sum = sum + gp;

		cout << "\nenter score in Chemistry:";
		cin >> s;
		gp = showgrade(s);
		sum = sum + gp;

		s_gpa = sum / 5;
	}
};
//working outside the class
float student::showgrade(int s)
{
	float g;
	if ((s >= 90) && (s <= 100))
		g = 10.0;
	else if ((s < 90) && (s >= 80))
		g = 9.00;
	else if ((s < 80) && (s >= 70))
		g = 8.0;
	if ((s < 70) && (s >= 60))
		g = 7.00;
	else if ((s < 60) && (s >= 50))
		g = 6.00;
	else if ((s < 50) && (s >= 33))
		g = 5.00;
	else if ((s < 30) && (s >= 0))
		g = 0.00;
	return g;
}
//multilevel inheritense
class System : public centre
{
  public:
	//Using of constructor
	System()
	{
		cen_info();
	}
	//Using of destructor
	~System()
	{
	}
};
//multiple inheritance
//also hybrid inheritance(board class to student and centre class and
//--from that two to data class)
class data : public student, public centre
{
  public:
	void showdata()
	{
		grade_info();
	}
	void display()
	{
		getinfo();
		calculate();
		showinfo();
	}
};
void main()
{
	clrscr();
	int i = 1, n = 1;
	board b;
	data t, d[60];
	b.showboard();
	System s;
	t.showdata();
start:
{
	d[i].display();
	i++;
}
start1:
	cout << "\n\t1 to continue\n\t0 to quit\nenter your choice:  ";
	cin >> n;
	if (n == 1)
	{
		goto start;
	}
	else if (n == 0)
		exit(0);
	else
	{
		cout << "Enter the correct choice!!";
		goto start1;
	}
	getch();
}
