#include<iostream>
#include<string>
using namespace std;
struct Node
{
	string Name;
	string reg_no;
	float CGPA;
	string department;
	string program;
	Node* Next;
	Node* Previous;
};
class Students
{
	string Name;
	string reg_no;
	float CGPA;
	string department;
	string program;
	Node* Next;
	Node* Previous;
public:
	Students()
	{
		Name = '\0';
		reg_no = '\0';
		CGPA = 0.0;
		department = '\0';
		program = '\0';
	}
	void setName(string Name)
	{
		this->Name = Name;
	}
	void setreg_no(string reg_no)
	{
		this->reg_no = reg_no;
	}
	void setCGPA(float CGPA)
	{
		this->CGPA = CGPA;
	}
	void setdepartment(string department)
	{
		this->department = department;
	}
	void setprogram(string program)
	{
		this->program = program;
	}
	string getName()
	{
		return Name;
	}
	string getreg_no()
	{
		return reg_no;
	}
	float getCGPA()
	{
		return CGPA;
	}
	string getdepartment()
	{
		return department;
	}
	string getprogram()
	{
		return program;
	}
};
class Dlist  // for doubly list
{
	Node* head;
public:
	Dlist()
	{
		head = NULL;
	}
	int search(string Name)
	{
		int count = 0;
		Node* N = head;
		while (N != NULL)
		{
			if (N->Name == Name)
			{
				count++;
			}
			N = N->Next;
		}
		return count;
	}
	bool searchreg(string reg_no)
	{
		int count = 0;
		Node* N = head;
		while (N != NULL)
		{
			if (N->reg_no == reg_no)
			{
				count++;
			}
			N = N->Next;
		}
		return count == 0 ? false : true;
	}
	void insertionatend(Students S, string Name)
	{
		if (head == NULL)
		{
			Node* N = new Node();
			N->Name = S.getName();
			N->reg_no = S.getreg_no();
			N->CGPA = S.getCGPA();
			N->department = S.getdepartment();
			N->program = S.getprogram();
			N->Next = NULL;
			N->Previous = NULL;
			head = N;
		}
		else if (search(Name) == 0 && !searchreg(S.getreg_no()))
		{
			Node* M = head;
			Node* N = new Node();
			while (M->Next != NULL)
			{
				M = M->Next;
			}
			N->Name = S.getName();
			N->reg_no = S.getreg_no();
			N->CGPA = S.getCGPA();
			N->department = S.getdepartment();
			N->program = S.getprogram();
			N->Next = NULL;
			M->Next = N;
			N->Previous = M;
		}
		else if (search(Name) == 1)
		{
			Node* M = head;
			Node* N = new Node();
			while (M != NULL)
			{
				if (M->Name == Name)
				{
					break;
				}
				M = M->Next;
			}
			if (M->Next != NULL)
			{
				Node* nxt = M->Next;
				N->Name = S.getName();
				N->reg_no = S.getreg_no();
				N->CGPA = S.getCGPA();
				N->department = S.getdepartment();
				N->program = S.getprogram();
				N->Next = nxt;
				nxt->Previous = N;
				M->Next = N;
				N->Previous = M;
			}
			else
			{
				N->Name = S.getName();
				N->reg_no = S.getreg_no();
				N->CGPA = S.getCGPA();
				N->department = S.getdepartment();
				N->program = S.getprogram();
				N->Next = NULL;
				N->Previous = M;
				M->Next = N;
			}
		}
		else if (search(Name) > 1)
		{
			string Reg;
			cout << "Enter Registration Number you want to insert after\n";
			cin >> Reg;
			Node* N = new Node();
			Node* M = head;
			while (M != NULL)
			{
				if (M->reg_no == Reg)
				{
					break;
				}
				M = M->Next;
			}
			if (M->Next != NULL)
			{
				Node* nxt = M->Next;
				N->Name = S.getName();
				N->reg_no = S.getreg_no();
				N->CGPA = S.getCGPA();
				N->department = S.getdepartment();
				N->program = S.getprogram();
				N->Next = nxt;
				nxt->Previous = N;
				M->Next = N;
				N->Previous = M;
			}
			else
			{
				N->Name = S.getName();
				N->reg_no = S.getreg_no();
				N->CGPA = S.getCGPA();
				N->department = S.getdepartment();
				N->program = S.getprogram();
				N->Next = NULL;
				N->Previous = M;
				M->Next = N;
			}

		}
	}
	float highest()
	{
		Node* N = head;
		float max = INT_MIN;
		while (N != NULL)
		{
			if (N->CGPA > max)
			{
				max = N->CGPA;
			}
			N = N->Next;
		}
		return max;
	}
	void topper()
	{
		Node* N = head;
		while (N != NULL)
		{
			if (N->CGPA == highest())
			{
				cout << "The name of the student is " << N->Name << endl;
				cout << "The Registration Number of the student is " << N->reg_no << endl;
				cout << "The department of the student is " << N->department << endl;
				cout << "The program of the student is " << N->program << endl;
				cout << "The CGPA of the student is " << N->CGPA << endl;
				cout << endl;
			}
			N = N->Next;
		}
	}
	void deletion(string reg_no)
	{
		Node* M = head;
		Node* P = head;
		Node* N = head;
		if (searchreg(reg_no))
		{
			while (N != NULL)
			{
				if (N->reg_no == reg_no)
				{
					break;
				}
				N = N->Next;
			}
			if (N == head)
			{
				cout << "No student exists before this registration number\n";
				return;
			}
			M = N->Previous;
			if (M == head)
			{
				head = head->Next;
				head->Previous = NULL;
				free(M);
				return;
			}
			P = M->Previous;
			P->Next = N;
			N->Previous = P;
			free(M);
		}
		else
		{
			cout << "Entered registration number does not exist\n";
		}
	}
	void display()
	{
		Node* N = head;
		while (N != NULL)
		{
			cout << "The name of the student is " << N->Name << endl;
			cout << "The Registration Number of the student is " << N->reg_no << endl;
			cout << "The department of the student is " << N->department << endl;
			cout << "The program of the student is " << N->program << endl;
			cout << "The CGPA of the student is " << N->CGPA << endl;
			cout << endl;
			N = N->Next;
		}

	}
};
int main()
{
	Node* Head = NULL;
	Students S;
	Dlist l;
	string name;
	string reg_no;
	string program;
	string department;
	float cgpa;
	char ch;
	do {
	jump:
		cout << "Press [I] for inserting after your desired name of student\n";
		cout << "Press [D] to delete the student before your enetered registration number\n";
		cout << "Press [T] to print all the student with the highest CGPA\n";
		cout << "Press [S] to show all the students\n";
		cout << "Please enter your choice\n";
		cin >> ch;
		ch = toupper(ch);
		switch (ch)
		{
		case 'I':
			cout << "Enter student name \n";
			cin.ignore();
			getline(cin, name);
			cout << "Enter student registration number\n";
			cin >> reg_no;
			cout << "Enter Program of the student\n";
			cin.ignore();
			getline(cin, program);
			cout << "Enter Department of the student\n";
			cin.ignore();
			getline(cin, department);
			cout << "Enter CGPA of the student\n";
			cin >> cgpa;
			S.setName(name);
			S.setreg_no(reg_no);
			S.setdepartment(department);
			S.setprogram(program);
			S.setCGPA(cgpa);
			cout << "Enter name you wnat to insert the student after\n";
			getline(cin, name);
			l.insertionatend(S, name);
			break;
		case 'D':
			cout << "Enter registration number you want to enter\n";
			cin >> reg_no;
			l.deletion(reg_no);
			break;
		case 'T':
			l.topper();
			break;
		case 'S':
			l.display();
			break;
		default:
			cout << "Wrong choice entered\n";
			goto jump;
			break;
		}
		cout << "if you want to continue press [y]\n";
		cin >> ch;
	} while (ch == 'y');
	system("pause");
	return 0;
}
