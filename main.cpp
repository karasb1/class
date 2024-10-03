#include <iostream>
#include <Windows.h>
using namespace std;

enum MessageColor
{
	Basic = 7,
	Easy = 10,
	Difficult = 12,
	Debug = 13
};

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


class Subject
{
private:
	string subject;
	MessageColor type;
	void reset_color()
	{
		SetConsoleTextAttribute(hConsole, MessageColor::Basic);
	}
public:
	Subject()
	{
		subject = "";
		type = MessageColor::Basic;
	}
	Subject(string subject, MessageColor type)
	{
		this->subject = subject;
		this->type = type;
	}
	void setSubject(string subject) {
		this->subject = subject;
	}
	void setType(MessageColor type) {
		this->type = type;
	}
	string getSubject() {
		return subject;
	}
	MessageColor getType() {
		return type;
	}
	void print()
	{
		SetConsoleTextAttribute(hConsole, type);
		cout << subject;
		reset_color();
		cout << endl;
	}
	~Subject()
	{
		SetConsoleTextAttribute(hConsole, MessageColor::Debug);
		cout << "Destructor called" << endl;
		reset_color();
	}
};

int main()
{
	Subject* subject = new Subject("Math", MessageColor::Easy);
	subject->print();
	subject->setType(MessageColor::Difficult);
	subject->print();
	subject->setSubject("History");
	subject->print();
	return 0;
}