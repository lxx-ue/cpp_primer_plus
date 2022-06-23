// a.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#include <stdio.h>

#include <iostream>
#include <array>
#include <fstream>
#include <string>
#include <cstring> 
#include <new>
#include <cstdlib>
#include <ctime>
#include <cmath>

#include "chapter9/ch9_1.h"
#include "chapter9/ch9_4.h"
#include "chapter11/ch11_1.h"
#include "chapter11/ch11_4.h"
#include "chapter11/ch11_5.h"
#include "chapter11/ch11_6.h"
#include "chapter12/ch12_1.h"
#include "chapter12/ch12_2.h"
#include "chapter12/ch12_3.h"
//#include "chapter12/ch12_4.h"
#include "chapter12/ch12_5.h"
#include "chapter13/ch13_1.h"
#include "chapter13/ch13_3.h"
#include "chapter13/ch13_4.h"
#include "chapter14/virtual_base_inherit.h"
#include "chapter14/stack_template.h"
#include "chapter14/dynamic_stack_template.h"
#include "chapter14/member_template.h"
#include "chapter14/ch14_1.h"
#include "chapter14/ch14_2.h"
#include "chapter14/ch14_3.h"

using namespace std;

#pragma region prototype_ch6
struct bop {
	char fullname[10];
	char title[10];
	char bopname[10];
	int preference;
};
struct metsenat {
	char name[10];
	double donate;
};
struct metsenates {
	std::string name;
	double donate;
};
#pragma endregion

#pragma region prototype_ch7
// #1
double garmon(double, double);
const int Len = 130;
const int Divs = 7;

// #2
void fill_games(int arr[], int size);
void show_games(int arr[], int size);
double avg_games(int arr[], int size);

// #3
struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};
void show_box(box b);
void volume_box(box* b);

// #4
long double probaЬility(unsigned numbers, unsigned picks, unsigned diap);

// #5
int fact(int n);

// #6
int fill_array(double arr[], int size);
void show_array(double arr[], int size);
void reverse_array(double arr[], int size);

// #7
double* fill_array2(double* begin, double* end);
void show_array2(const double* begin, const double* end);
void revalue(double* begin, double* end, double r);

// #8
const int Seasons = 4;
const char* ses[Seasons] = { "Spring",  "Summer", "Autumn" , "Winter" };
struct ses_array {
	double aue[4];
};
void fill_seasons(double pa[]);
void show_seasons(const double da[]);
void fill_seasons(ses_array* pa);
void show_seasons(const ses_array* pa);

// #9
const int SLEN = 30;
struct student {
	char fullname[SLEN] = { "" };
	char hobby[SLEN];
	int ooplevel;
};
int getinfo(student ра[], int n);
void display1(student st);
void display2(const student* ps);
void displayЗ(const student ра[], int n);

// #10
double calculate(double (*pf)(double, double), double, double);
double summation(double, double);
double subtraction(double, double);
double multiplication(double, double);
double division(double, double);
#pragma endregion

#pragma region prototype_ch8
// #1
int call_count = 0;
void print_str(const char*);
void print_str(const char*, int);
// #2
struct CandyBar
{
	const char* name;
	double weight;
	int cal;
};
void fill_candybar(CandyBar&, const char* n = "Millennium Munch", double  w = 2.85, int c = 350);
void show_candybar(const CandyBar&);
// #3
void upper_string(string&);
// #4
struct _string
{
	char* str;
	int ct;
};
void _string_set(_string&, char* chr);
void _string_show(const _string&, int count = 1);
void _string_show(const char* chr, int count = 1);
// #5
template <class T>
T max5(T[5]);
// #6
template <class T>
T maxn(T[], int);
template <> char* maxn<char*>(char* [], int);
// #7
struct debts
{
	char name[50];
	double amount;
};
template <typename T>
T SumArray(T arr[], int n);
template <typename T>
T* SumArray(T* arr[], int n);
#pragma endregion

#pragma region prototype_ch9
// #2
void strcount(string str);
// #3
const int STRUCTSIZE = 2;       // размер массива структур
const int BUFFSIZE = 50;        // размер массива buffer
char buffer[BUFFSIZE];          // блок памяти под буфер
struct chaff {                   // определение структуры
	char dross[20];
	int slag;
};
#pragma endregion

#pragma region prototype_ch10
// #1
class BankAccount
{
public:
	BankAccount();
	BankAccount(string name, string num, long double balance);
	~BankAccount();
	void show();
	void plus_sum(double sum);
	void minus_sum(double sum);
private:
	string name;
	string num;
	long double balance;
};
BankAccount::BankAccount()
{
	name = "None";
	num = "None";
	balance = 0.0;
}
BankAccount::BankAccount(string name, string num, long double balance)
{
	this->name = name;
	this->num = num;
	this->balance = balance;
}
void BankAccount::show()
{
	cout << "Account keeper: " << name << "; Account num " << num << "; Balance $" << balance << endl;
}
void BankAccount::plus_sum(double sum)
{
	balance += sum;
}
void BankAccount::minus_sum(double sum)
{
	balance -= sum;
}
BankAccount::~BankAccount()
{
	cout << "Bye!";
}

// #2
class Person
{
private:
	static const int LIMIT = 25;
	string lname;
	char fname[LIMIT];
public:
	Person()
	{
		lname = "";
		fname[0] = '\0';
	}
	Person(const string& ln, const char* fn = "Heyyou")
	{
		lname = ln;
		strcpy(fname, fn);
	}
	void Show() const
	{
		cout << fname << " " << lname << endl;
	}
	void FormalShow() const
	{
		cout << lname << " " << fname << endl;
	}
};

// #3
class Golf {
private:
	static const int gLen = 40;
	char fullname[gLen];
	int handicap;
public:
	Golf(const char* name, int hc)
	{
		strcpy_s(fullname, name);
		handicap = hc;
	}
	Golf(Golf& g)
	{
		strcpy_s(fullname, g.fullname);
		handicap = g.handicap;
	}
	void changeHandicap(int hc)
	{
		this->handicap = hc;
	}
	void showGolf()
	{
		std::cout << "Name: " << fullname << "\t handicap: " << handicap << std::endl;
	}
};

// #4
namespace SALES {
	class _Sales
	{
	private:
		static const int QUARTERS = 4;
		double sales[QUARTERS];
		double average;
		double max;
		double min;
		void detect_variables()
		{
			double min = sales[0], max = sales[0], avg = 0;
			for (int i = 0; i < QUARTERS; i++)
			{
				avg += sales[i];
				if (min > sales[i]) min = sales[i];
				if (max < sales[i]) max = sales[i];
			}
			avg /= 4;
			this->average = avg;
			this->max = max;
			this->min = min;
		}
	public:
		_Sales(const double ar[])
		{
			for (int i = 0; i < QUARTERS; i++)
			{
				sales[i] = ar[i];
			}
			detect_variables();
		}
		_Sales(Sales& s)
		{
			for (int i = 0; i < QUARTERS; i++)
			{
				this->sales[i] = s.sales[i];
			}
			detect_variables();
		}
		void showSales()
		{
			cout << sales[0] << " " << sales[1];
			cout << " " << sales[2] << " " << sales[3];
			cout << "\taverage=" << average << "\tmax=";
			cout << max << "\tmin=" << min << endl;
		}
	};
}

// #5
/*
struct Customer
{
	char fullname[35];
	double payment;
};
typedef Customer Item;
class Stack
{
private:
	static const int MAX = 10;
	Item items[MAX];
	int top;
	double sum;
public:
	Stack()
	{
		top = 0;
		sum = 0.0;
	}
	bool is_empty() const
	{
		return top == 0;
	}
	bool is_full() const
	{
		return top == MAX;
	}
	bool push(const Item& item)
	{
		if (top < MAX)
		{
			items[top++] = item;
			return true;
		}
		else return false;
	}
	bool pop(Item& item)
	{
		if (top > 0)
		{
			item = items[--top];
			sum += item.payment;
			return true;
		}
		else return false;
	}
	void show_sum() const
	{
		cout << "All sum is: " << sum;
	}
};
*/
// #6
class Move
{
private:
	double x, y;
public:
	Move(double a = 0, double b = 0)
	{
		x = a;
		y = b;
	}
	void showMove() const
	{
		cout << "x = " << x << "; y = " << y << endl;
	}
	Move add(const Move& m) const
	{
		Move tmp{ this->x + m.x, this->y + m.y };
		return tmp;
	}
	void reset(double a = 0, double b = 0)
	{
		x = a;
		y = b;
	}
};

// #7
class Plorg
{
private:
	char name[20];
	int CI;
public:
	Plorg(const char* name = "Plorga", int CI = 50)
	{
		strcpy_s(this->name, name);
		this->CI = CI;
	}
	void changeCI(int CI)
	{
		this->CI = CI;
	}
	void showPlorg()
	{
		cout << "Name: " << name << "; CI = " << CI << endl;
	}
};
#pragma endregion

#pragma region prototype_ch11
// #5
void display(const Stonewt& st, int n);
#pragma endregion

#pragma region prototype_ch12
// #5
bool newcustomer(double x);
#pragma endregion

#pragma region prototype_ch13
// #1
void Bravo(const Cd& disk);
#pragma endregion

int main()
{
	setlocale(0, "");

#pragma region chapter6
	// #1
	//char ch;
	//cout << "enter: \n";
	//cin.get(ch);
	//while (ch != '@')
	//{
	//    if (islower(ch))
	//    {
	//        ch = toupper(ch);
	//    }
	//    else
	//    {
	//        ch = tolower(ch);
	//    }
	//    if(!isdigit(ch))
	//    cout << ch;
	//    cin.get(ch);
	//}

	// #2
	//const int don_size = 10;
	//int donates[don_size] = {};               //массив цен предметов торговли
	//int i = 0, vushe_srednego_count = 0;                          //счётчик цикла
	//cout << "donate N_" << i + 1 << ": ";          //диалог на экран
	//while (i<don_size && cin >> donates[i]) {
	//    i++;                                         //не забываем, что у while надо изменять счётчик
	//    if (i < don_size) {                                  //чтобы не выводило лишнюю строчку
	//        cout << "Product N_" << i + 1 << ": ";
	//    }
	//}
	//float total = 0;        //Оценка средней стоимости
	///*считаем всю сумму на товары*/
	//for (int j = 0; j < i; j++) {
	//    total = total + donates[j];
	//}
	///*считаем среднюю стоимость*/
	//total = total / i;
	//for (int j = 0; j < i; j++) {
	//    if (donates[j] > total) vushe_srednego_count++;
	//}
	//cout << "\nwill pay summ: " << total << '\n';     //Вывод оплачиваемой суммы
	//cout << "vushe_srednego_count:" << vushe_srednego_count<<endl;

	// #3
	//char choice;
	//cout << "Please enter one of the following choices: \nc) carnivore\t p) pianist\nt) tree\t\t g) game\n";
	//cin >> choice;
	//while (true)
	//{
	//    if (choice != 'c' && choice != 'p' && choice != 't' && choice != 'g')
	//    {
	//        cout << "Please enter a c, p, t, or g: ";
	//        cin >> choice;
	//    }
	//    else {
	//        break;
	//    }
	//}
	//switch (choice)
	//{
	//case 'c':
	//    cout << "\nARRRRHHH";
	//    break;
	//case 'p':
	//    cout << "\ntu tutu ttuuu tu";
	//    break;
	//case 't':
	//    cout << "\nu can just chill here";
	//    break;
	//case 'g':
	//    cout << "\ngonna start a game...wait...";
	//    break;
	//}

	// #4
	//array<bop, 4> bops;
	//bops[0] = { "name0", "title0", "bop0", 0 };
	//bops[1] = { "name1", "title1", "bop1", 1 };
	//bops[2] = { "name2", "title2", "bop2", 2 };
	//bops[3] = { "name3", "title3", "bop3", 0 };
	//char choice;
	//cout << "Choose display order: \na) display by name\t b) display by title\nc) display by bopname\t d) display by preference\nq) quit\n";
	//cin >> choice;
	//while (true)
	//{
	//    if (choice != 'a' && choice != 'b' && choice != 'c' && choice != 'd' && choice != 'q')
	//    {
	//        cout << "Please enter a a, b, c, d or q: ";
	//        cin >> choice;
	//    }
	//    else {
	//        break;
	//    }
	//}
	//switch (choice)
	//{
	//case 'q':
	//    cout << "Bye!";
	//    return 0;
	//case 'a':
	//    for (int i = 0; i < bops.size(); i++)
	//    {
	//        cout << bops[i].fullname << endl;
	//    }
	//    break;
	//case 'b':
	//    for (int i = 0; i < bops.size(); i++)
	//    {
	//        cout << bops[i].title << endl;
	//    }
	//    break;
	//case 'c':
	//    for (int i = 0; i < bops.size(); i++)
	//    {
	//        cout << bops[i].bopname << endl;
	//    }
	//    break;
	//case 'd':
	//    for (int i = 0; i < bops.size(); i++)
	//    {
	//        switch (bops[i].preference)
	//        {
	//        case 0:
	//            cout << bops[i].fullname << endl;
	//            break;
	//        case 1:
	//            cout << bops[i].title << endl;
	//            break;
	//        case 2:
	//            cout << bops[i].bopname << endl;
	//            break;
	//        }
	//    }
	//    break;
	//}

	// #5
	//int sum;
	//double nalog = 0.0f;
	//cin >> sum;
	//if (sum <= 5000) {
	//    nalog = 0.0f;
	//}
	//else
	//{
	//    sum -= 5000;
	//    if (sum <= 10000)
	//    {
	//        nalog += sum * 0.1;
	//    }
	//    else
	//    {
	//        nalog += 10000 * 0.1;
	//        sum -= 10000;
	//        if (sum <= 20000)
	//        {
	//            nalog += sum * 0.15;
	//        }
	//        else
	//        {
	//            nalog += 20000 * 0.15;
	//            sum -= 20000;
	//            nalog += sum * 0.2;
	//        }
	//    }
	//}
	//cout << nalog;

	// #6
	//cout << "enter count: ";
	//int count;
	//cin >> count;
	//metsenat *metsenats = new metsenat[count];
	//for (int i = 0; i < count; i++)
	//{
	//    cout << "metsenat #" << i + 1 << endl;
	//    cout << "name: ";
	//    cin >> metsenats[i].name;
	//    cout << "donate: ";
	//    cin >> metsenats[i].donate;
	//}
	//int pat = 0, grpat = 0;
	//for (int i = 0; i < count; i++) {
	//    if (metsenats[i].donate >= 10000) grpat++;
	//    else pat++;
	//}
	//if (!grpat || !pat) cout << "none";
	//else {
	//    cout << "grand patrons: \n";
	//    for (int i = 0; i < count; i++)
	//    {
	//        if (metsenats[i].donate >= 10000) cout << metsenats[i].name << "\t" << metsenats[i].donate << endl;
	//    }
	//    cout << "patrons: \n";
	//    for (int i = 0; i < count; i++)
	//    {
	//        if (metsenats[i].donate < 10000) cout << metsenats[i].name << "\t" << metsenats[i].donate << endl;
	//    }
	//}

	//#7
	//char ch;
	//bool is_new = true;
	//int words = 0, other = 0, sogl = 0, gl = 0;
	//cout << "enter: \n";
	//cin.get(ch);
	//while (ch != '@')
	//{
	//    if (is_new)
	//    {
	//        words++;
	//        is_new = !is_new;
	//        if (isdigit(ch))
	//        {
	//            other++;
	//        }
	//        else 
	//        {
	//            if ((ch + 0) == 97 || (ch + 0) == 101 || (ch + 0) == 105 || (ch + 0) == 111 || (ch + 0) == 117)
	//            {
	//                gl++;
	//            }
	//            else
	//            {
	//                sogl++;
	//            }
	//        }
	//    }
	//    if (ch == ' ') is_new = true;
	//    else is_new = false;
	//    cout << ch;
	//    cin.get(ch);
	//}
	//if (is_new) words--;
	//cout << endl << other;
	//cout << endl << gl;
	//cout << endl << sogl;

	// #8
	//int count=0;
	//char ch;
	//ifstream fin;
	//fin.open("C:\\Users\\lx\\Desktop\\a.txt");
	//if (fin.is_open())
	//{
	//    fin >> ch;
	//    while (fin.good())
	//    {
	//        count++;
	//        fin >> ch;
	//    }
	//}
	//cout << count;
	//fin.close();

	// #9
	//string path("a.txt");
	//ifstream fin;
	//fin.open(path);
	//metsenates* metsenats;
	//string str;
	//int count, num = 0, aaa = 0;
	//if (!fin.is_open())
	//{
	//    cout << "ошибка" << endl;
	//}
	//else
	//{
	//    cout << "открыт" << endl;
	//   
	//    getline(fin, str);
	//    count = stoi(str);
	//    metsenats = new metsenates[count];
	//    bool isnum = false;
	//    while (!fin.eof())
	//    {
	//        str = "";
	//        getline(fin, str);
	//        if (!isnum)
	//        {
	//            metsenats[num].name = str;
	//        }
	//        else
	//        {
	//            aaa = stoi(str);
	//            metsenats[num].donate = aaa;
	//            num++;
	//        }
	//        isnum = !isnum;
	//    }
	//    int pat = 0, grpat = 0;
	//    for (int i = 0; i < count; i++) {
	//        if (metsenats[i].donate >= 10000) grpat++;
	//        else pat++;
	//    }
	//    if (!grpat || !pat) cout << "none";
	//    else {
	//        cout << "grand patrons: \n";
	//        for (int i = 0; i < count; i++)
	//        {
	//            if (metsenats[i].donate >= 10000) cout << metsenats[i].name << "\t" << metsenats[i].donate << endl;
	//        }
	//        cout << "patrons: \n";
	//        for (int i = 0; i < count; i++)
	//        {
	//            if (metsenats[i].donate < 10000) cout << metsenats[i].name << "\t" << metsenats[i].donate << endl;
	//        }
	//    }
	//}
	//fin.close();
#pragma endregion

#pragma region chapter7
	// #1
	//double x, y;
	//cout<<"Введите 2 числа: ";
	//cin>>x>>y;
	//while (!(x == 0 || y == 0))
	//{
	//    cout<<garmon(x, y)<<"\nВведите 2 числа: ";
	//    cin>>x>>y;
	//}

	// #2
	//const int golf_size = 10;
	//int games[golf_size] = {};              
	//int i = 0;                          
	//fill_games(games, golf_size);
	//show_games(games, golf_size);
	//cout<<"average is: "<< avg_games(games, golf_size)<< endl;

	// #3
	//box boxy = { "name\0", 1, 2 , 3, 4 };
	//show_box(boxy);
	//volume_box(&boxy);
	//show_box(boxy);

	// #4
	//double total, choices, second;
	//cout << "Enter the total numЬer of choices on the game card and\ n"
	//" the number of picks allowed:\n";
	//while ((cin >> total >> choices>> second) && choices <= total && second <= total)
	//{
	//    cout << " You have one chance in ";
	//    cout << probaЬility(total, choices, second);
	//    cout << " of winning . \n";
	//    cout << "Next two numbers (q to qu it) : ";
	//}
	//cout << "bye\n";

	// #5
	//int num;
	//cout << "Enter num to factorial: ";
	//while (cin >> num)
	//{
	//    if (num < 0) num *= -1;
	//    cout <<num<< " factorial = " << fact(num) << endl;
	//    cout << "Next number : ";
	//}
	//cout << "bye\n";

	// #6
	//const int size = 6;
	//int real;
	//double arr[size];
	//real = fill_array(arr, size);
	//show_array(arr, real);
	//reverse_array(arr, real);
	//show_array(arr, real);

	// #7
	//const int Мах = 5;
	//double properties[Мах];
	//double * end = fill_array2(properties, properties+Мах);
	//show_array2(properties, end);
	//if (end > properties)
	//{
	//    cout << " Enter revaluation factor: ";
	//    double factor;
	//    while (!(cin >> factor))
	//    {
	//        cin.clear();
	//        while (cin.get() != '\n')
	//            continue;
	//        cout << "Bad input; Please enter а number: ";
	//    }
	//    revalue(properties, end, factor);
	//    show_array2(properties, end);
	//}
	//cout << " Done.\n ";
	//cin.get();

	// #8
	//double aue[4];
	//fill_seasons(aue);
	//show_seasons(aue);
	//ses_array st_ses;
	//fill_seasons(&st_ses);
	//show_seasons(&st_ses);

	// #9
	//cout << "Enter class size: ";
	//int class_size;
	//cin >> class_size;
	//while (cin.get() != '\n')
	//    continue;
	//student* ptr_stu = new student[class_size];
	//cout << endl;
	//int entered = getinfo(ptr_stu, class_size);
	//cout << "You entered "<<entered<<" students\n";
	//for (int i = 0; i < entered; i++)
	//{
	//    display1(ptr_stu[i]);
	//    display2(&ptr_stu[i]);
	//}
	//displayЗ(ptr_stu, entered);
	//delete[] ptr_stu;
	//cout << "Done\n";

	// #10
	//double a, b;
	//cout << "Enter two numbers: ";
	//while (cin >> a >> b)
	//{
	//    cout << "summation is = " << calculate(summation, a, b) << endl;
	//    cout << "subtraction is = " << calculate(subtraction, a, b) << endl;
	//    cout << "multiplication is = " << calculate(multiplication, a, b) << endl;
	//    cout << "division is = " << calculate(division, a, b) << endl;
	//    cout << "Enter two numbers again: ";
	//}
#pragma endregion

#pragma region chapter8
	// #1
	//print_str("shesh");
	//print_str("shesh",5);
	//print_str("shesh",5);
	//print_str("shesh",5);
	//print_str("shesh");

	// #2
	//CandyBar cb;
	//fill_candybar(cb);
	//show_candybar(cb);
	//fill_candybar(cb, "alpen gold", 100);
	//show_candybar(cb);

	// #3
	//string s;
	//cout << "Enter a string: ";
	//while (getline(cin, s) && s != "q")
	//{
	//	upper_string(s);
	//	cout << s <<endl;
	//	cout << "Enter a string: ";
	//}
	//cout << "Bye";

	// #4
	//_string beany;
	//char testing[] = "Reality isn't what it used to bе.";
	//_string_set(beany, testing); // первым аргументом является ссылка,
	//// Выделяет пространство для хранения копии testing,
	//// использует элемент типа str структуры beany как указатель
	//// на новый блок, копирует testing в новый блок и
	//// создает элемент ct структуры beany
	//_string_show(beany); // выводит строковый член структуры один раз
	//_string_show(beany, 2); // выводит строковый член структуры два раза
	//testing[0] = 'D';
	//testing[1] = 'u';
	//_string_show(testing);
	//_string_show(testing, 3);
	//_string_show("Done!");
	//delete beany.str;

	// #5
	//int arr[5] = { 1, 5, 6, 7, 9};
	//cout << max5(arr) << endl;
	//double arr2[5] = { 1.4, 5.6, 2.6, 5.7, 0.9 };
	//cout << max5(arr2) << endl;

	// #6
	//int arr[6] = { 1, 15, 32, 2, 6, 7};
	//cout << maxn(arr, 6) << endl;
	//double arr2[4] = { 1.4, 5.6, 5.7, 7.9 };
	//cout << maxn(arr2, 4) << endl;
	//char* B[3];
	//for (int i = 0; i < 3; i++) {
	//	B[i] = new char[6];
	//}
	//strcpy(B[0], "Wake");
	//strcpy(B[1], "upppp");
	//strcpy(B[2], "Neo");
	//cout << maxn(B,3) << endl;

	// #7
	//int things[6] = { 13, 31, 103, 301, 310, 130 };
	//struct debts mr_E[3] =
	//{
	//{ "Ima Wolfe", 2400.0 },
	//{ "Ura Foxe" , 1300.0 },
	//{ "Iby Stout" , 1800.0 }
	//};
	//double* pd[3];
	//for (int i = 0; i < 3; i++)
	//	pd[i] = &mr_E[i].amount;
	//cout << "Listing Mr.Е's counts of things: \n";
	//cout << SumArray(things, 6) << endl;
	//cout << "Listing Mr.Е's debts: \n";
	//cout << *(SumArray(pd, 3)) << endl;
#pragma endregion

#pragma region chapter9
	// #1
	//golf g1;
	//setGolf(g1);
	//showGolf(g1);
	//handicap(g1, 5);
	//showGolf(g1);

	// #2
	//string s;
	//char next;
	//cout << "Enter a line: \n";
	//getline(cin, s);
	//while (s != "")
	//{
	//	strcount(s);
	//	cout << "Enter next line (empty line to quit):\n";
	//	getline(cin, s);
	//}
	//cout << "Bye\n";

	// #3
	//chaff* pchaff = new (buffer) chaff[STRUCTSIZE];    // выделение памяти с размещением
	//													// в массиве buffer
	//strcpy(pchaff[0].dross, "one");   // инициализация массива структур
	//strcpy(pchaff[1].dross, "two");
	//pchaff[0].slag = 1;
	//pchaff[1].slag = 2;
	//std::cout << "Address of buffer: " << &buffer
	//	<< "\nSize of buffer: " << sizeof buffer << "\n";
	//std::cout << "Address of &pchaff[0]: " << &pchaff[0]
	//	<< "\nSize of pchaff: " << sizeof pchaff << "\n";
	//std::cout << "Size of pchaff[0]: " << sizeof pchaff[0] << "\n";
	//std::cout << "Address of &pchaff[1]: " << &pchaff[1] << "\n";
	//for (int i = 0; i < STRUCTSIZE; i++) {           // отображение массива структур
	//	std::cout << pchaff[i].dross << "\n"
	//		<< pchaff[i].slag << "\n";
	//}

	// #4
	//double arr[SALES::QUARTERS] = { 2.2, 3.3, 4.4, 5.5 };
	//SALES::Sales s1, s2;
	//SALES::setSales(s1,arr);
	//for (int i = 0; i < SALES::QUARTERS; i++)
	//{
	//	s2.sales[i] = arr[i] * 2;
	//}
	//SALES::setSales(s2);

#pragma endregion

#pragma region chapter10
	// #1
	//BankAccount ba, ba2 {"Julia", "#00001", 99999};
	//ba.show();
	//ba2.show();
	//ba2.minus_sum(400);
	//ba2.show();
	//ba2.plus_sum(5);
	//ba2.show();

	// #2
	//Person one, two{ "Smythecraft" }, three{ "Dimwiddy", "Sam" };
	//one.Show();
	//one.FormalShow();
	//two.Show();
	//two.FormalShow();
	//three.Show();
	//three.FormalShow();

	// #3
	//Golf gg("Name", 15);
	//gg.showGolf();
	//gg.changeHandicap(14);
	//Golf golf(gg);
	//golf.showGolf();

	// #4
	//double arr[SALES::QUARTERS] = { 2.2, 3.3, 4.4, 5.5 };
	//SALES::_Sales s1(arr);
	//s1.showSales();
	//SALES::_Sales s2(s1);
	//s2.showSales();

	// #5
	//Stack st;
	//Customer ct[3] = { Customer{ "name", 12 }, Customer{ "name", 13 }, Customer{ "name", 14 } };
	//st.push(ct[0]);
	//st.push(ct[1]);
	//st.push(ct[2]);
	//st.pop(ct[0]); // lifo
	//st.show_sum();

	// #6
	//Move mv;
	//Move mv2(3, 5);
	//mv.showMove();
	//mv2.showMove();
	//mv.reset(10, 10);
	//Move mv3 = mv.add(mv2);
	//mv3.showMove();
	//mv2.reset();
	//mv2.showMove();

	// #7
	//Plorg prg("New", 34);
	//prg.showPlorg();
	//prg.changeCI(90);
	//prg.showPlorg();
#pragma endregion

#pragma region chapter11
	// #1-2
	/*using VECTOR::Vector;
	srand(time(0));
	double direction, target, dstep;
	Vector step, result(0.0, 0.0);
	unsigned long steps = 0;
	ofstream fout;
	fout.open("random_walk.txt");
	cout << "See random_walk.txt for details\nEnter target distance (q to quit): ";
	while (cin >> target)
	{
		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;
		fout << "Target Distance: " << target << ", Step Size: " << dstep << endl;
		fout <<"0: "<< result << endl;
		while (result.magval() < target)
		{
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::Mode::POL);
			result = result + step;
			steps++;
			fout << steps<<": "<<result << endl;
		}
		cout << "After " << steps << " steps, the subject has the following location:\n";
		cout << result << endl;
		fout << "Total steps: " << steps << ", Location: " << result <<
			"\nAverage distance per step: " << result.magval() / steps << "\n\n";
		result.polar_mode();
		cout << "or\n" << result;
		cout << "\nAverage outward distance per steps = " << result.magval() / steps << endl;
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "Enter target distance (q to quit): ";
	}
	cout << "Bye!\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;*/

		// #3
		//using VECTOR::Vector;
		//srand(time(0));
		//double direction, target, dstep;
		//Vector step, result(0.0, 0.0);
		//unsigned long steps = 0, tries = 0;

		//cout << "Enter target distance (q to quit): ";
		//cin >> target;
		//cout << "Enter step length: ";
		//cin >> dstep;
		//cout << "Enter tries: ";
		//cin >> tries;
		//int* arr = new int[tries];
		//for (int i = 0; i < tries; i++)
		//{
		//	while (result.magval() < target)
		//	{
		//		direction = rand() % 360;
		//		step.reset(dstep, direction, Vector::Mode::POL);
		//		result = result + step;
		//		steps++;
		//	}
		//	arr[i] = steps;
		//	steps = 0;
		//	result.reset(0.0, 0.0);
		//}
		//int min = arr[0], max = arr[0], avg = 0;
		//for (int i = 0; i < tries; i++)
		//{	
		//	avg += arr[i];
		//	if (min > arr[i]) min = arr[i];
		//	if (max < arr[i]) max = arr[i];
		//}
		//avg /= tries;
		//cout << "max = "<<max<<endl;
		//cout << "min = " << min << endl;
		//cout << "avg = " << avg << endl;
		//delete[] arr;

		// #4
		//Time aida(3, 35);
		//Time tosca(2, 48);
		//Time temp;
		//cout << "Aida and Tosca:\n";
		//cout << aida << "; " << tosca << endl;
		//temp = aida + tosca;
		//cout << "Aida + Tosca: " << temp << endl;
		//temp = aida * 1.17;
		//cout << "Aida * 1.17: " << temp << endl;
		//cout << "10.0 * Tosca: " << 10.0 * tosca << endl;

		// #5
		//Stonewt incognito = 275;
		//Stonewt wolfe(285.7);
		//Stonewt taft(21, 8);
		//cout << "The celebrity weighed ";
		//cout << incognito;
		//cout << "The detective weighed ";
		//cout << wolfe;
		//cout << "The president weighed ";
		//cout << taft;
		//incognito = 276.8;
		//cout << taft;
		//cout << "After dinner, the celebrity weighed ";
		//cout << incognito;
		//cout << "After dinner, the president weighed ";
		//cout << taft;
		//taft.set_mode(Stonewt::Mode::lbs);
		//cout << "or\n" << taft;
		//display(taft, 2);
		//cout << "The wrestler weighed even more.\n";
		//display(422, 2);
		//cout << "No more left unerned\n";

		// #6
		//Stonewt incognito = 275; //not explicit!
		//Stonewt taft = incognito;
		//incognito = 14;
		//if (!(incognito == taft)) cout << "They r equal!\n";
		//else cout << "They r not!\n";
		//if (incognito > taft) cout << "incognito bigger than taft!\n";
		//else cout << "taft bigger than incognito!\n";

		//Stonewt arr[6]{ 144, 12 , 15 };
		//Stonewt empty{ 0 };

		//for (int i = 0; i < 6; i++)
		//{
		//	if (arr[i] == empty)
		//	{
		//		cout << "Enter " << i+1 << "th element : ";
		//		double temp = 0.0;
		//		while (cin>>temp)
		//		{
		//			if (temp != 0.0) break;
		//		}
		//		arr[i] = temp;
		//	}
		//}
		//Stonewt min = arr[0], max = arr[0];
		//empty = 11;
		//int count = 0;
		//for (int i = 0; i < 6; i++)
		//{
		//	if (min > arr[i]) min = arr[i];
		//	if (max < arr[i]) max = arr[i];
		//	if (arr[i] >= empty) count++;
		//}
		//cout << "Smallest: " << min << "Largest: " << max <<
		//	"Bigger than 11: " << count;

		// #7
		//Complex0 a(3.0, 4.0);
		//Complex0 c;
		//cout << "Enter a complex number (q to quit):\n";
		//while (cin >> c)
		//{
		//	cout << "c is " << c << endl;
		//	cout << "complex conjugate is " << -c << endl;
		//	cout << "a is " << a << endl;
		//	cout << "a + c is " << a + c << endl;
		//	cout << "a - c is " << a - c << endl;
		//	cout << "a * c is " << a * c << endl;
		//	cout << "2 * c is " << 2 * c << endl;
		//	cout << "Enter a complex number (q to quit):\n";
		//}
		//cout << "Done!\n";

#pragma endregion

#pragma region chapter12
	// #1
	//Cow bella;
	//bella.ShowCow();

	//Cow stella("stella", "reading", 600 );
	//stella.ShowCow();
	//bella = stella;
	//cout << endl;
	//bella.ShowCow();

	// #2
	//String s1(" and I am a C++ student.");
	//String s2 = "Please enter your name: ";
	//String s3;
	//cout << s2;
	//cin >> s3;
	//s2 = "My name is " + s3;
	//cout << s2 << ".\n";
	//s2 += s1;
	//s2.string_up();
	//cout << "The string\n" << s2 << "\ncontains " << s2.has('A')
	//	<< " 'A' characters in it.\n";
	//s1 = "red";
	//String rgb[3]{ String{s1}, String("green"), String{"blue"} };
	//cout << "Enter the name of a primary color for mixing light: ";
	//String ans;
	//bool succes = false;
	//while (cin >> ans)
	//{
	//	ans.string_low();
	//	for (int i = 0; i < 3; i++)
	//	{
	//		if (ans == rgb[i])
	//		{
	//			cout << "That's right!\n";
	//			succes = true;
	//			break;
	//		}
	//	}
	//	if (succes) break;
	//	else cout << "Try again!\n";
	//}
	//cout << "Bye.\n";

	// #3
	//Stock stocks[4] = { 
	//	Stock("NanoSmart", 12, 20.0),
	//	Stock("Boffo Objects", 200, 2.0),
	//	Stock("Monolithic Obelisks", 130, 3.25),
	//	Stock("Fleep Enterprises", 60, 6.5)
	//};
	//cout << "Stock holdings:\n";
	//int st;
	//for (st = 0; st < 4; st++)
	//	cout << stocks[st];
	//const Stock* top = &stocks[0];
	//for (st = 1; st < 4; st++)
	//	top = &top->topval(stocks[st]);
	//cout << "\nMost valuable holding:\n";
	//cout << *top;

	// #4
	//Stack1 st;
	//char ch;
	//unsigned long po;
	//cout << "Please enter A to add a purchase,\n"
	//	<< "P to process a PO, or Q to quit.\n";
	//while (cin >> ch && toupper(ch) != 'Q')
	//{
	//	while (cin.get() != '\n')
	//		continue;
	//	if (!isalpha(ch))
	//	{
	//		cout << '\a';
	//		continue;
	//	}
	//	switch (toupper(ch))
	//	{
	//	case 'A':cout << "Enter a PO number to add: ";
	//		cin >> po;
	//		if (st.is_full())
	//			cout << "stack already full\n";
	//		else st.push(po);
	//		break;
	//	case 'P':
	//		if (st.is_empty())
	//			cout << "stack already empty\n";
	//		else {
	//			st.pop(po);
	//			cout << "PO #" << po << " popped\n";
	//		}
	//		break;
	//	}
	//	cout << "Please enter A to add a purchase order,\n"
	//		<< "P to process a PO, or Q to quit.\n";
	//}
	//cout << "Bуе\n";

	// #5
	//std::srand(std::time(0));
	//int qs = 10, hours = 100;
	//long cyclelimit = 60 * hours;
	//double perhour = 18;
	//Queue line(qs);
	//cout << "Enter a range of people per hour: ";
	//int min_ph, max_ph;
	//while (cin >> min_ph >> max_ph)
	//{
	//	if (min_ph < max_ph && min_ph>0) break;
	//	else cout << "Enter correct range of people per hour: ";
	//}
	//int array_size = max_ph - min_ph + 1;
	//double* results = new double[array_size];
	//for (int ph = min_ph, i = 0; ph <= max_ph; ph++, i++)
	//{
	//	double min_per_cust;
	//	min_per_cust = 60 / ph;
	//	Item temp;
	//	long turnaways = 0;
	//	long customers = 0;
	//	long served = 0;
	//	long sum_line = 0;
	//	int wait_time = 0;
	//	long line_wait = 0;
	//	for (int cycle = 0; cycle < cyclelimit; cycle++)
	//	{
	//		if (newcustomer(min_per_cust))
	//		{
	//			if (line.isfull())
	//				turnaways++;
	//			else {
	//				customers++;
	//				temp.set(cycle);
	//				line.enqueue(temp);
	//			}
	//		}
	//		if (wait_time <= 0 && !line.isempty())
	//		{
	//			line.dequeue(temp);
	//			wait_time = temp.ptime();
	//			line_wait += cycle - temp.when();
	//			served++;
	//		}
	//		if (wait_time > 0)
	//			wait_time--;
	//		sum_line += line.queuecount();
	//	}
	//	results[i] = abs(1 - ((double)line_wait / served));
	//}
	//double min = results[0];
	//int min_index = 0;
	//for (int i = 1; i < array_size; i++)
	//{
	//	if (min > results[i])
	//	{
	//		min = results[i];
	//		min_index = i;
	//	}
	//}
	//delete[] results;
	//cout << "Need "<<min_index<< " people per hour!\n";
#pragma endregion

#pragma region chapter13
	// #1
	//Cd c1("Beatles", "Capitol", 14, 35.5);
	//Classic c2 = Classic("Piano", "Alfred Brendel", "Philips", 2, 57.17);
	//Cd* pcd = &c1;
	//cout << "Using object directly:\n";
	//c1.Report();
	//c2.Report();
	//cout << "Using type cd * pointer to objects: \n";
	//pcd->Report();
	//pcd = &c2;
	//pcd->Report();
	//cout << "Calling a function with a Cd reference argument:\n";
	//Bravo(c1);
	//Bravo(c2);
	//cout << "Testing assigment: ";
	//Classic copy;
	//copy = c2;
	//copy.Report();

	// #3
	//BaseDMA shirt("portabelly", 8);
	//LacksDMA balloon("red", "Blimpo", 4);
	//HasDMA map("Mercator", "Buffali Keys", 5);
	//DMA* ref[4]{ &shirt, &balloon, &map };
	//cout << "Choose a class: 1 - baseDMA, 2 - lacksDMA, 3 hasDMA\n";
	//int n;
	//cin >> n;
	//switch (n)
	//{
	//case 1:	ref[3] = new BaseDMA();
	//	break;
	//case 2:	ref[3] = new LacksDMA();
	//	break;
	//case 3:	ref[3] = new HasDMA();
	//	break;
	//}
	//for (int i = 0; i < 4; i++)
	//{
	//	ref[i]->View();
	//}
	//delete ref[3];

	// #4
	//Port wine("santa", "stefano");
	//cout << wine << endl;
	//Port wine2(wine), wine3;
	//wine2 += 3;
	//wine2.Show();
	//wine3 = wine2;
	//wine3 -= 2;
	//wine3 += 100;
	//cout << wine3 << endl;
	//VintagePort vw("a", 2,"b",199);
	//cout << vw << endl;
	//VintagePort vw2;
	//cout << vw2;
#pragma endregion

#pragma region chapter14

	////// virtual_base_inherit ///////

	//Worker* lolas[5];
	//int ct;
	//for (ct = 0; ct < 5; ct++)
	//{
	//	char choice;
	//	cout << "Enter the employee category:\n"
	//		<< "w: waiter s: singer "
	//		<< "t: singing waiter q: quit\n";
	//	cin >> choice;
	//	while (strchr("wstq", choice) == NULL)
	//	{
	//		cout << "Please enter a w, s, t or q: ";
	//		cin >> choice;
	//	}
	//	if (choice == 'q') break;
	//	switch (choice)
	//	{
	//	case 'w': lolas[ct] = new Waiter;
	//		break;
	//	case 's': lolas[ct] = new Singer;
	//		break;
	//	case 't': lolas[ct] = new SingerWaiter;
	//		break;
	//	}
	//	cin.get();
	//	lolas[ct]->Set();
	//}
	//cout << "\nHere is your staff:\n";
	//int i;
	//for (i = 0; i < ct; i++)
	//{
	//	cout << endl;
	//	lolas[i]->Show();
	//}
	//for (i = 0; i < ct; i++)
	//	delete lolas[i];
	//cout << "Bye!";

	////// stack_template ///////

	//TemplateStack<string> st;
	//char ch;
	//string po;
	//cout << "Please enter A to add a purchase order, \n"
	//	<< "P to process a PO, or Q to quit.\n";
	//while (cin >> ch && toupper(ch) != 'Q')
	//{
	//	while (cin.get() != '\n')
	//		continue;
	//	if (!isalpha(ch))
	//	{
	//		cout << '\a';
	//		continue;
	//	}
	//	switch (toupper(ch))
	//	{
	//	case 'A':
	//		cout << "Enter a PO number to add: ";
	//		cin >> po;
	//		if (st.isfull())
	//			cout << "stack already full\n";
	//		else
	//			st.push(po);
	//		break;

	//	case 'P':
	//		if (st.isempty())
	//			cout << "stack alreafy empty\n";
	//		else
	//		{
	//			st.pop(po);
	//			cout << "PO #" << po << " popped\n";
	//		}
	//		break;
	//	}
	//	cout << "Please enter A to add a purchase order, \n"
	//		<< "P to process a PO, or Q to quit.\n";
	//}

	////// dynamic_stack_template ///////

	//srand(time(0));
	//cout << "Please enter stack size: ";
	//int stacksize;
	//cin >> stacksize;
	//DynamicTemplateStack<const char*> st(stacksize);
	//const int num = 10;
	//const char* in[num] = {
	//	" 1: Hank Gilgamesh", " 2: Kiki Ishtar",
	//	" 3: Betty Rocker", " 4: Ian Flagranti",
	//	" 5: Wolfgang Kibble", " 6: Portia Koop",
	//	" 7: Joy Almondo", " 8: Xaverie Paprika",
	//	" 9: Juan Moore", " 10: Misha Mache"
	//};
	//const char* out[num];
	//int processed = 0;
	//int nextin = 0;
	//while (processed < num)
	//{
	//	if (st.isempty())
	//		st.push(in[nextin++]);
	//	else if (st.isfull())
	//		st.pop(out[processed++]);
	//	else if (rand() % 2 && nextin < num)
	//		st.push(in[nextin++]);
	//	else
	//		st.pop(out[processed++]);
	//}
	//for (int i = 0; i < num; i++)
	//	cout << out[i] << endl;
	//cout << "Bye!";

	////// member_template ///////

	//beta<double> guy(3.5, 3);
	//cout << "T was set to double\n";
	//guy.Show();
	//cout << "V was set to T, which is double, then V was set to int\n";
	//cout << guy.blab(10, 2.3) << endl;
	//cout << "U w as set to int\n";
	//cout << guy.blab(10.0, 2.3) << endl;
	//cout << "U w as set to double\n";

	// #1 2
	//cout << "Enter name of wine: ";
	//char lab[50];
	//cin.getline(lab, 50);
	//cout << "Enter number of years: ";
	//int yrs;
	//cin >> yrs;
	//Wine2 holding(lab, yrs);
	//holding.GetBottles();
	//holding.Show();
	//const int YRS = 3;
	//int y[YRS] = { 1993, 1995, 1998 };
	//int b[YRS] = { 48,60,72 };
	//Wine2 more("Grape Red", YRS, y, b);
	//more.Show();
	//cout << "Total bottles for " << more.Label()
	//	<< ": " << more.sum() << endl;
	//cout << "Bye\n";

	// #3
	QueueTp<Worker*> line(3);
	int ct;
	Worker* newworker;
	while (!line.isfull())
	{
		char choice;
		std::cout << "Enter the employee category:\n"
			<< "w: waiter s: singer "
			<< "t: singing waiter q: quit\n";
		cin >> choice;
		while (strchr("wstq", choice) == NULL)
		{
			std::cout << "Please enter a w, s, t or q: ";
			cin >> choice;
		}
		if (choice == 'q') break;
		switch (choice)
		{
		case 'w': newworker = new Waiter;
			break;
		case 's': newworker = new Singer;
			break;
		case 't': newworker = new SingerWaiter;
			break;
		}
		line.enqueue(newworker);
		cin.get();
		newworker->Set();
	}

	std::cout << "\nQueue is full!\n\n";
	while (!line.isempty())
	{
		line.dequeue(newworker);
		cout << newworker->getName() << " deleted\n";
	}

#pragma endregion
}

#pragma region func_ch7
// #1
double garmon(double x, double y)
{
	return 2.0 * x * y / (x + y);
}
// #2
void fill_games(int arr[], int size)
{
	int i = 0;
	cout << "game N_" << i + 1 << ": ";
	while (i<size && cin >> arr[i]) {
		i++;
		if (i < size) {
			cout << "game N_" << i + 1 << ": ";
		}
	}
}
void show_games(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
double avg_games(int arr[], int size)
{
	double avg = 0.0f;
	for (int i = 0; i < size; i++)
	{
		avg += arr[i];
	}
	return avg / size;
}
// #3
void show_box(box b) {
	cout << "maker: " << b.maker << "\theight: " << b.height << "\twidth: " << b.width << "\tlenth: " << b.length << "\tvolume: " << b.volume << endl;
}
void volume_box(box* b)
{
	b->volume = b->height * b->length * b->width;
}
// #4
long double probaЬility(unsigned numbers, unsigned picks, unsigned diap)
{
	if (diap == 0) return 0;
	long double result = 1.0, n, tmp;
	unsigned р;
	for (n = numbers, р = picks; р > 0; n--, р--)
		result = result * n / р;
	tmp = result / diap;
	return tmp;
}
// #5
int fact(int n)
{
	if (n == 0 || n == 1) return 1;
	if (n > 0) return n * fact(n - 1);
}
// #6
int fill_array(double arr[], int size)
{
	int i = 0;
	cout << "N_" << i + 1 << ": ";
	while (i<size && cin >> arr[i]) {
		i++;
		if (i < size) {
			cout << "N_" << i + 1 << ": ";
		}
	}
	return i;
}
void show_array(const double arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void reverse_array(double arr[], int size)
{
	double tmp;
	for (int i = 0; i < size / 2; i++)
	{
		tmp = arr[size - i - 1];
		arr[size - i - 1] = arr[i];
		arr[i] = tmp;
	}
}
// #7
double* fill_array2(double* begin, double* end)
{
	double temp;
	int i = 0;
	double* tmp;
	for (tmp = begin; tmp != end; tmp++)
	{
		cout << "Enter value #" << (i + 1) << " : ";
		cin >> temp;
		if (!cin)
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input; Input process terminated. \n";
			break;
		}
		else if (temp < 0)
			break;
		*tmp = temp;
		i++;
	}
	return tmp;
}
void show_array2(const double* begin, const double* end)
{
	const double* tmp;
	int i = 0;
	for (tmp = begin; tmp != end; tmp++)
	{
		cout << "Property #" << (i + 1) << ": $";
		cout << *tmp << endl;
		i++;
	}
}
void revalue(double* begin, double* end, double r)
{
	for (double* tmp = begin; tmp != end; tmp++)
		*tmp *= r;
}
// #8
void fill_seasons(double pa[])
{
	for (int i = 0; i < Seasons; i++)
	{
		cout << "Enter " << ses[i] << " expenses: ";
		cin >> pa[i];
	}
}
void show_seasons(const double da[])
{
	double total = 0.0;
	cout << "\nEXPENSES\n";
	for (int i = 0; i < Seasons; i++)
	{
		cout << ses[i] << ": $" << da[i] << endl;
		total += da[i];
	}
	cout << " Total Expenses: $" << total << endl;
}
void fill_seasons(ses_array* pa)
{
	for (int i = 0; i < Seasons; i++)
	{
		cout << "Enter " << ses[i] << " expenses: ";
		cin >> pa->aue[i];
	}
}
void show_seasons(const ses_array* pa)
{
	double total = 0.0;
	cout << "\nEXPENSES\n";
	for (int i = 0; i < Seasons; i++)
	{
		cout << ses[i] << ": $" << pa->aue[i] << endl;
		total += pa->aue[i];
	}
	cout << " Total Expenses: $" << total << endl;
}
// #9
int getinfo(student pa[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		char tmp[SLEN];
		cout << "St #" << i + 1 << ".\n\tEnter name: ";
		if (cin >> tmp)
		{
			*pa[i].fullname = *tmp;
			cout << "\tEnter hobby: ";
			cin >> pa[i].hobby;
			cout << "\tEnter oop: ";
			cin >> pa[i].ooplevel;
		}
		else {
			cin.clear();
			return i;
		}
	}
	return i;
}
void display1(student st)
{
	cout << "Name: " << st.fullname << endl;
	cout << "Hobby: " << st.hobby << endl;
	cout << "OOP: " << st.ooplevel << endl;
}
void display2(const student* ps) {
	cout << "Name: " << ps->fullname << endl;
	cout << "Hobby: " << ps->hobby << endl;
	cout << "OOP: " << ps->ooplevel << endl;
}
void displayЗ(const student ра[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "Name: " << ра[i].fullname << endl;
		cout << "Hobby: " << ра[i].hobby << endl;
		cout << "OOP: " << ра[i].ooplevel << endl;
	}
}
// #10
double calculate(double (*pf)(double, double), double x, double y)
{
	return (*pf)(x, y);
}
double summation(double x, double y)
{
	return x + y;
}
double subtraction(double x, double y)
{
	return x - y;
}
double multiplication(double x, double y)
{
	return x * y;
}
double division(double x, double y)
{
	return (y == 0) ? 0 : x / y;
}

#pragma endregion

#pragma region func_ch8
// #1
void print_str(const char* str)
{
	cout << str << endl;
	call_count++;
}
void print_str(const char* str, int n)
{
	if (n != 0)
		for (int i = 0; i < call_count; i++)
			cout << str << endl;
	else cout << str << endl;
	call_count++;
}
// #2
void fill_candybar(CandyBar& candy, const char* n, double  w, int c)
{
	candy.name = n;
	candy.weight = w;
	candy.cal = c;
}
void show_candybar(const CandyBar& c)
{
	cout << " name is: " << c.name;
	cout << "\t weight is: " << c.weight;
	cout << "\t calories is: " << c.cal << endl;
}
// #3
void upper_string(string& str)
{
	for (int i = 0; i < str.size(); i++)
	{
		str[i] = toupper(str[i]);
	}
}
// #4
void _string_set(_string& str, char* chr)
{
	str.str = new char[strlen(chr) + 1];
	strcpy(str.str, chr);
	str.ct = strlen(chr);
}
void _string_show(const _string& str, int count)
{
	for (int n = 0; n < count; n++)
	{
		for (int i = 0; i < str.ct; i++)
		{
			cout << str.str[i];
		}
		cout << endl;
	}
}
void _string_show(const char* chr, int count)
{
	for (int n = 0; n < count; n++)
	{
		cout << chr << endl;
	}
}
// #5
template <class T>
T max5(T arr[5])
{
	T temp = arr[0];
	for (int i = 1; i < 5; i++)
	{
		if (arr[i] > temp) temp = arr[i];
	}
	return temp;
}
// #6
template <class T>
T maxn(T arr[], int n)
{
	T temp = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > temp) temp = arr[i];
	}
	return temp;
}
template <> char* maxn<char*>(char* arr[], int n)
{
	char* temp = arr[0];
	int longest = strlen(arr[0]);
	for (int i = 1; i < n; i++)
	{
		if (strlen(arr[i]) > longest)
		{
			temp = arr[i];
			longest = strlen(arr[i]);
		}
	}
	return temp;
}
// #7
template <typename T>
T SumArray(T arr[], int n)
{
	cout << "template A\n ";
	T temp = 0;
	for (int i = 0; i < n; i++)
		temp += arr[i];
	return temp;
}
template <typename T>
T* SumArray(T* arr[], int n)
{
	cout << "template B\n ";
	T* temp = arr[0];
	for (int i = 1; i < n; i++)
		*temp += *arr[i];
	return temp;
}
#pragma endregion

#pragma region func_ch9
// #2
void strcount(string str)
{
	static int total = 0;
	int count = 0, i = 0;
	cout << "\"" << str << "\" contains\n";
	while (str[i++])
		count++;
	total += count;
	cout << count << " characters\n";
	cout << total << " characters total\n";
}
#pragma endregion

#pragma region func_ch11
// #5
void display(const Stonewt& st, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Wow! ";
		cout << st;
	}
}
#pragma endregion

#pragma region func_ch12
// #5
bool newcustomer(double x)
{
	return (std::rand() * x / RAND_MAX < 1);
}
#pragma endregion

#pragma region func_ch13
// #1
void Bravo(const Cd& disk)
{
	disk.Report();
}
#pragma endregion
