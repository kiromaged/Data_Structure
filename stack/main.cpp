#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;

string* Dtype = new string[4]{ "int","double","float","char" };
struct variable
{
	string name;
	string datatype;
	string value;

	variable(const string& n = " ", const string& dt = " ", const string& val = " ") : name(n), datatype(dt), value(val) {} //constructor to set values to zero

};

class node
{
public:
	variable data;
	node* next;

	node(const variable& d = variable("", "", "")) : data(d), next(NULL) {} //constructor to set values to zero


};

//class node {} , class stacklinkedlist { variable data , node*next push } , class stack { node* head } da rodyy



class stack
{
public:
	node* head;

	stack() : head(nullptr) {}

	void push(const string& datatype, const string& name, const string& value)
	{

		node* newnode = new node(variable(name, datatype, value));
		newnode->next = head;
		head = newnode;

	}

	void pop()
	{
		if (head == NULL)
		{
			cout << "Empty stack can not pop ..." << endl;
			return;
		}

		node* current = head;
		head = head->next;
		cout << "Popped element: (name: " << current->data.name << ", datatype: " << current->data.datatype << ", value: " << current->data.value << ")" << endl;
		delete current;
	}

	//void pop() //lsa 3yza a3mlha lma yshof return 0;
	//{
	//  node* current = head;

	//  if (head == NULL)
	//  {
	//    cout << " Empty stack can not pop ..." << endl;
	//  }
	//  while (current != NULL)
	//  {
	//    current->next = head->next;
	//    delete current;
	//  }

	//}

	void update(const string& name, const string& val)
	{
		node* current = head;
		while (current != nullptr)
		{

			if (current->data.name == name)
			{
				current->data.value = val;
				displaystack();
				return; //khlas l2aha w 3dlha
			}
			//displaystack();
			current = current->next; //3shan ymshe 3lstack
		}
		// displaystack();
		cout << "Variable " << name << " not found in the stack." << endl;


	}


	void displaystack()
	{
		node* dis = head;
		cout << "Current variables in the stack:" << endl;
		while (dis != NULL)
		{
			cout << " name: " << dis->data.name << ", ";
			cout << " datatype:" << dis->data.datatype << ", ";
			cout << " value:" << dis->data.value << endl;

			dis = dis->next;

		}
		cout << "-------------------------------------------------\n";
	}

	~stack()
	{
		while (head != nullptr)
		{
			node* current = head;
			head = head->next;
			delete current;

		}
	}


};


string* lineS(string line) //line da mkhzna feh line kolo as string w bmshy 3leh
//3yza afhm mn roudy eh hett string*
{
	string* arr = new string[3]; //array to put in datatype , name , value so it's size = 3
	int index_of_arr = 0; // arr[0]=data type , arr[1]=name , arr[2]=value
	string element;

	for (int i = 0; i < line.length(); i++)
	{

		if (line[i] != ' ' && line[i] != '/' && line[i] != '\n' && line[i] != '=' && line[i] != '\t' && line[i] != ';')
		{
			element += line[i]; //3shan l data type kolha tkon f arr[0] as the line is int x = 3;
			// w keda mn nafso hy skip l char dol except el single ' lsa ha handle it
		}
		else if (element != "") // law el element msh fady hydkhol hena as msln fe condition eno hybaa gwah x bas
		{
			if (element != "main()" || element != "{" || element != "}")
			{
				arr[index_of_arr] = element; // kda kda est7ala element ykon fady fa bakhzno fl array bt3te
				index_of_arr++; // bzawed index el arr 3shan l gya tkhzn haga tanya as trteb datatybe name value
				element = ""; // bfde el element 3shan b3d keda akhzn fe haga tanya
			}
			else
				element = "";
			continue;
		}


	}

	return arr;
}

void processLine(ifstream& file, stack& mystack)
{
	string line;
	while (getline(file, line))
	{
		string* arr = lineS(line);


		// Check if it's the end of the program will display all the stack
		if (arr[0] == "return " && arr[1] == "0")
		{
			mystack.pop();
			mystack.displaystack();
			return;

		}

		if (arr[2].empty()) // If value is empty, it's a assignment
		{
			mystack.update(arr[0], arr[1]);

		}
		else // it's a declaration
		{
			mystack.push(arr[0], arr[1], arr[2]);
			mystack.displaystack();
		}
	}
}

void processFile(const string& filename)
{
	stack mystack;
	ifstream file(filename);
	if (!file.is_open())
	{
		cerr << "Unable to open file " << filename << endl;
		return;
	}

	string line;

	// Process each line of code
	while (getline(file, line))
	{
		string* arr = lineS(line);

		if (arr[0] == "return" && arr[1] == "0")
		{
			// Pop all variables from the stack and make it empty
			mystack.pop();
			mystack.displaystack(); // Display the stack after popping
			break; // End of the program, exit the loop
		}

		processLine(file, mystack);
		mystack.displaystack(); // Display the stack after processing the file
	}

	file.close();
}

int main()
{
	processFile("code.txt");
	return 0;
}