﻿// a.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <array>
#include <fstream>
#include <string>
#include <cstring> 
#include "ch9_1.h"
#include <new>
#include "ch9_4.h"

using namespace std;
#pragma warning(disable : 4996)


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
// #4
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
	double arr[SALES::QUARTERS] = { 2.2, 3.3, 4.4, 5.5 };
	SALES::Sales s1, s2;
	SALES::setSales(s1,arr);
	for (int i = 0; i < SALES::QUARTERS; i++)
	{
		s2.sales[i] = arr[i] * 2;
	}
	SALES::setSales(s2);
	
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