# C++_Primer_plus

C++学习笔记 

# 第一章 基础知识 

C++是在C的基础上添加了面向对象编程和泛型编程。 

# 第二章 开始学习

C++基础

```C++
#include <iostream>
int main()
{
	using namespace std;
    cout << "Hello, world!"  << endl << "Welcome to study C++.";
    return 0;
}
```

# 第三章 数据类型

C++基本类型分为两种：

- 整型 ：bool、char、signed char、unsigned char、short、unsigned short、int、unsigned int、long、unsigned long
- 浮点型：float、double、long double

# 第四章 复合类型

常见的复合类型：数组，字符串，结构，共用体，枚举

## 数组

储存多个相同类型的值。

`````c++
// typeName arrayName[arraySize]
int int_name[10];
int int_name1[10] = {1,2,3,4,5,6,7,8,9,10}; // =  is optional
std::cout << name1[1];
`````

## 字符串

一个方便好用的字符数组，智能识别和使用

```c++
#include <cstring> //要引用头文件string
sting name;
string str1;
stirng str2 = "This is a example.";
string str3;
str3 = str2;
str1 =str2 + str3;
```



## 结构体与共用体

**结构体（struct）：**
每个成员都有自己独立的内存空间，结构体的总大小是所有成员大小之和（考虑对齐填充）。这意味着你可以同时访问所有成员，并且它们各自保存独立的数据。

**共用体（union）：**
共用体的所有成员共用同一块内存，内存大小等于其中最大成员的大小。一次只能正确存储和使用其中一个成员，因为写入一个成员会覆盖其他成员的值。

---

## 指针

指针指向的是一个地址，对指针解除引用就获得了指针指向的值。**格式**：*typeName \* pointerName;*

`int* p = &a;` p是指针，&a是指针指向的地址，a和*p都代表地址上储存的值。

### 声明指针

```c++
int * p; //声明了一个指向int类型的指针，空格是可选的
int *p; //传统C语言写法，强调*p是是int类型的值
int* p; //C++写法，强调int* 是一种类型，指向int的指针。
int a = 5;
int* p = &a; //声明一个指向int类型的指针，并初始化指针。
double* p_d;//声明一个指double类型的指针
char* p_ch;//声明一个指向char类型的指针
```

> **Note**
>
> *在对指针进行解除引用之前(\*p),一定要将**指针初始化**为一个确定的，合适的地址。*
>
> ```c++
> int* p;
> p = &a;// 重要，不然就是野指针
> cout << *p;
> ```



### new和delete分配内存

`new`和`delete`配合可以进行动态内存分配。

```c++
int* p = new int;   // 分配内存
*p = 20;            // 赋值
delete p;           // 释放内存
p = nullptr;        // 避免悬空指针
```

- **内存泄漏**：忘记 `delete` 会导致内存无法回收。
- **重复释放**：多次 `delete` 同一指针会崩溃

> 使用new和delete的规则：
>
> - 不要使用delete释放不是new分配的内存
> - 不要使用delete释放同一内存两次
> - 如果使用new []为数组分配内存，应使用delete[]来释放
> - 如果使用new为实体分配内存，应使用delete(没有方括号)释放内存
> - 对空指针使用delete是安全的

### 指针、数组和指针算术

数组名就是指针名。

|   **特性**   |         **指针**          |           **数组名**           |
| :----------: | :-----------------------: | :----------------------------: |
|   **本质**   |    变量，存储内存地址     |   符号，代表数组首元素的地址   |
| **内存分配** |   可指向动态或静态内存    |    静态分配（如栈或全局区）    |
|   **类型**   | 单独变量类型（如 `int*`） | 隐式指针类型（如 `int(*)[5]`） |
| **可修改性** |    可重新指向其他地址     |     不可修改（是常量指针）     |

- **核心区别：**数组名是常量符号，携带类型和大小信息；指针是变量，仅存储地址。

## 类型组合

数组，结构，指针之间可以随意组合。

```c++
struct year_m  //定义一个结构
{
    int year;
    int month;
};
year_m s01,s02,s03; //s01,s02,s03都是结构体
s01.year = 1997;
year_m* p =&s02;//指向结构的指针
p->year =1998;
year_m ym[3];//结构数组
ym[0].year = 2025;// ym是一个数组，ym[0]是一个结构，所以ym[0].year是结构成员
(ym+1)->year = 2026; //数组名代表的是地址，也就是一个指针，所以应该使用间接成员运算符，相当于ym[1].year =2026;
const year_m* arp[3] {&s01,&s02,&s03};//指针数组  arp是指针数组，所以arp[1]就是一个指针,指向s02
std::cout << arp[1]->year << std::endl;//输出的是结构体s02的成员year
const year_m** ppa = arp;//指向上述指针数组的指针
auto ppb =arp;// C++自动推断类型
std::cout << (*ppa)->year << std::endl;//ppa是一个指向结构指针的指针，所以*ppa是一个结构指针，所以应该用间接访问符->访问
std::cout << (*(ppb+1))->year << std::endl;//ppb+1指向arp[1]，也就是&s02
```

## 数组、vector和array

**vector：**

```c++
#include <vector>
using namespace std;
vector<double> vt(10); //vector<typeName> arrayName(n_elem);(n is optional)
vector<int> vi;
```

**array：**

```c++
#include <array>
#include <array>
using namespace std;
array<double,10> arr; //varray<typeName,n_elem> arrayName;
array<int,3> arr1 {5,6,8};
```

**核心区别：**

|    **特性**    |            **原生数组**             |          **`std::vector`**           |           **`std::array`**           |
| :------------: | :---------------------------------: | :----------------------------------: | :----------------------------------: |
|  **内存分配**  |     栈或静态存储区（固定大小）      |       堆（动态分配，自动扩容）       |      栈或静态存储区（固定大小）      |
| **大小可变性** |             ❌ 固定大小              |              ✅ 动态扩容              |              ❌ 固定大小              |
|  **边界检查**  |    ❌ 无（越界访问是未定义行为）     |        ✅ 通过 `at()` 提供检查        |        ✅ 通过 `at()` 提供检查        |
|  **内存管理**  | 手动管理（若为堆数组需 `delete[]`） |        自动管理（RAII 机制）         |    自动管理（栈内存无需手动释放）    |
|    **性能**    |       ⚡ 最高效（无额外开销）        |     ⚠️ 动态扩容可能触发内存重分配     | ⚡ 接近原生数组（固定大小无扩容开销） |
| **接口丰富性** |            ❌ 无成员方法             | ✅ 丰富（`push_back()`, `size()` 等） |  ✅ 支持迭代器、`size()` 等 STL 接口  |
|  **传递方式**  |     退化为指针（丢失大小信息）      |           可传递副本或引用           |   可传递副本或引用（保留大小信息）   |

# 第五章 循环和关系表达式

## for 循环

![for循环](https://github.com/IdealistLee/C-_Primer_plus/blob/main/img/for%E5%BE%AA%E7%8E%AF.jpg "for循环")

```c++
for (i=1;i<5;i++) 
    cout << i;  
for (initialization; test_experssion; update_experssion)
	body
```

for 和括号之间一般加一个空格，函数之间省略空格 ，视觉上强化函数调用和控制语句的区别。

```c++
for (···)；
cin.getline(···)；
```

> **NOTE**
>
> a++和++a，a++是先使用a的表达式，之后将a的值+1；++a是先将a的值+1
>
> ```c++
> int x = 5;
> int y = ++x; // change x,then assign to y
> 			 // y is 6, x is 6
> int z = 5;
> int y = Z++; // assign to y,then change z
> 			 // y is 5, z is 6
> ```

## while循环

![while循环](https://github.com/IdealistLee/C-_Primer_plus/blob/main/img/while%E5%BE%AA%E7%8E%AF.jpg "while循环")

> **NOTE：**设计循环时的原则
>
> - 指定循环终止的条件
> - 首次循环开始之前初始化条件
> - 条件再次被测试之前更新条件

## do while循环

![do while循环](https://github.com/IdealistLee/C-_Primer_plus/blob/main/img/do%20while%E5%BE%AA%E7%8E%AF.jpg "do while循环")

- for循环和while循环是入口条件（entry condition），do while循环是出口条件（exit condition）。

## 嵌套循环和二维数组

二维数组有数据行和数据列

- **二维数组的定义：**

```c++
int temps[4][5];  // row = 4 ,col =5
```

- **二维数组的赋值：**

```c++
int temps[4][5] =
{
    {1,2,3,4,5};
    {21,22,23,24,25};
    {31,32,33,34,35};
    {41,42,43,44,45}
};
```

- **for循环打印内容：**

```c++
for (int row = 0;row < 4;++row)
{
	for (int col = 0;col < 5;++col)
		cout << temp[row][col]<< "\t";
	cout endl;
}
```



# 第六章 分支语句和逻辑运算符

## if语句

### if

![if语句结构](https://github.com/IdealistLee/C-_Primer_plus/blob/main/img/if.jpg "if结构")

```C++
if (test-condition)
	statement
```

### if else

![if else语句结构](https://github.com/IdealistLee/C-_Primer_plus/blob/main/img/if_else.jpg "if else结构")

```C++
	if (test-condition)
        statement1
    else
        statement2          
```

### if else if else

if else if else结构实际上一个if else被包含在另一个if else里面。

```c++
if (ch == 'A')
    a++;
else if (ch == 'B')
    b++;
else 
    other++;
```

## 逻辑表达式

逻辑运算符有逻辑OR(`||`)、逻辑AND(`&&`)、逻辑NOT(`!`)。

### 逻辑OR(`||`)

- OR表示只要有一个为真，结果就为真。

- **`||`在C++中是一个顺序点，先修改左侧的值，再对右侧的值进行判定。如果左侧表达式为真，则不会对右侧进行判断。**

### 逻辑AND(`&&`)

- AND表示两个都为真，结果才为真。
- **`&&`也是一个顺序点，即首先判定左侧，右侧被判定之前产生所有的副作用。如果左侧为false，则不会判定右侧。**

### 逻辑NOT(`!`)

- **`!`** 对后面的表达式取反 

- **`!`运算符优先级高于所有关系运算符和算术运算符。**

> **NOTE**
>
> 逻辑AND的优先级高于逻辑OR
>
> 使用括号将测试条件进行分组，程序更加易读，也不容易出错
>
> 逻辑符号也可以用`and or not`表示，C语言中需要包含头文件iso646.h，C++不需要头文件

## `?:`运算符

通用格式：

```C++
expression1 ? expression2 : expression3
```

如果expression1的表达式为真，则表达式的值为expression2的值，否则为expression3的值。

```C++
5 > 3 ? 10 : 12 ; // 5>3 is true, so expression value is 10
3 == 9 ? 25 : 18; // 3==9 is false, so expression value is 18
```

## `switch`语句

通用格式

```C++
switch (integer-experssion)
{
    case label1 : statement(s)
    case label2 : statement(s)
            ···
    default : statement(s)
}
```

![switch语句结构](https://github.com/IdealistLee/C-_Primer_plus/blob/main/img/switch.jpg "switch语句结构")

> switch只能处理单独的值，无法处理浮点值。case标签必须是常量。

## `break`和`continue`语句

`break`跳过循环，`continue`跳过循环体中余下代码，并开始新一轮循环。

![break和continue](https://github.com/IdealistLee/C-_Primer_plus/blob/main/img/break%20continue.jpg "break continue结构")

## 简单文件输入和输出

### 写入文本文件

> **写入到文本文件的主要步骤：**
>
> 1. 包含头文件fstream
> 2. 创建一个ofstream对象
> 3. 将该ofstream对象同一个文件关联起来
> 4. 像使用cout一样使用ofstream对象

```C++
ofstream outFile; //create aobject for output
outFile.open("carinfo.txt"); // associate with a file 
cout << "Hello";
outFile << "Hello too";
cout.precision(2);		//use a precision of 2 for the display
outFile.precision(4);	//use a precision of 4 for file output
···
outFile.close();
```

> **NOTE:**
>
> ***打开已有文件接受输出时，默认会清空文件原来的内容。***

### 读取文本文件

> **读取文本文件的主要步骤：**
>
> 1. 包含头文件fstream
> 2. 创建一个ifstream对象
> 3. 将该ifstream对象同一个文件关联起来
> 4. 像使用cin一样使用ofstream对象

```C++
ifstream inFile; //inFile an ifstream object
inFile.open("bowling.txt"); // associate with a file 
double wt;
inFile >> wt;  //read a number from bowling.txt
···
inFile.close();
```

**检查文件是否被成功打开**

```C++
inFile.open("bowling.txt");
if (!inFile.is_open())
{
    exit(EXIT_FALLURE)  // <cstdlib>
}
```

# 第七章 函数

## 函数基础知识

**创建函数基础流程：**

- 提供函数定义
- 提供函数原型
- 调用函数

### 定义函数

没有返回值的函数和有返回值的函数。

没有返回值的函数，也叫**void函数**：

```c++
void functionName(parameterList)
{
    statement(s)
    return;  // optional
}
```

有返回值的函数，会生成一个值，返回给调用函数：

```c++
typeName functionName(parameterList)
{
    statement(s)
    return value; // value is type cast to type typeName
}
```

>  **NOTE：**
>
>  - 有返回值的函数，必须使用返回语句
>  - 返回值可以是常量、变量、表达式
>  - 返回值类型必须为typeName类型或者可以被转换为typeName
>  - C++不可以返回数组，其他任何类型都可以(整数、浮点数、指针、结构和对象等)

### 函数原型和函数调用

- 函数原型描述了函数到编译器的接口
- 原型的功能
  - 编译器正确处理函数返回值
  - 编译器检查使用的参数数目是否正确
  - 编译器检查使用的参数类型是否正确。如果不正确，则转换为正确的类型（如果可能）。

## 函数参数和按值传递

C++按值传递参数。用于接收传递值得变量被称为形参，传递给函数得值为实参。C++标准用参数(argument)表示实参，用参量(parameter)表示形参。参数传递将参数赋给参量。

- 函数中声明的变量为函数私有，是局部变量，也是自动变量。

### 多个参数

函数可以有多个参数，调用函数时，用逗号将参数分开即可。

- 函数的两个参数类型相同时，必须分别指定每个参数的类型。

```c++
double melon_density(double weight,double volume);
```

 ## 函数与数组

 在C++中，数组名被视为指针。

```c++
int sum_arr(int arr[],int n); // prototype  int sum_arr(int* arr,int n); 
...
int sum = sum_arr(cookies,ArSize); 
// cookies =  &cookies[0]
arr[i] == *(ar+i); // values in two notations
&arr[i] == ar + i; // address in two notations
```

**NOTE**:

- 指针加1，实际上是加了一个与指针指向类型（字节单位）的长度相等的值。
- 可以通过传递两个指针来指定元素区间（range），一个指针标识数组的开头，一个指针标识数组的尾部。

### 指针和const

>  将const用于指针的两种方式。
>
>  - 让指针指向一个常量对象
>  - 将指针本身声明为一个常量

```c++
int age = 20;
const int *pt = age; 
/* pt指向一个const int，不能用pt的来修改age的值，或者说*pt的值为const，不能修改*/
```

指向const的指针和const指针：

```c++
int sloth = 3;
const int* ps = &sloth; // a pointer to const int
int* const finger = &sloth; // a const pointer to int
```

**总结：**finger和*ps都是const，*finger和ps不是。

![const和指针](https://github.com/IdealistLee/C-_Primer_plus/blob/main/img/const%E5%92%8C%E6%8C%87%E9%92%88.jpg "指向const的指针和const指针")

## 函数和二维数组

将二维数组作为参数时，注意正确的声明指针。

```C++
int data[3][4] = {{1,2,3,4},{9,8,7,6},{2,4,6,8}};
int total = sum(data,3);  
int sum(int(*ar2)[4], int size); //声明了一个指针，指向由4个int组成的数组。
int sum(int ar2[][4], int size); // ✅
int sum(int *ar2[4], int size); //❌ 声明了一个4个指向int的指针数组，且函数参数不能是数组
```

## 函数和C风格字符串

将字符串作为参数传递给函数的三种方式：

- char数组；
- 用括号引起的字符串常量（字符串常量）;
- 被设置为字符串地址的char指针

```C++
char * str = "minimum";
while (*str){
	statements
    str++;
}  //处理字符串的标准方式
```

## 函数和结构

结构比较小时，按值传递结构最合理。

```C++
struct travel_time
{
    int hours;
    int minus;
}

travel_time sum(travel_time tl, travel_time t2);
//travel_time 就像一个标准类型名，可以用来声明变量、函数返回类型和函数的参数类型
```

传递结构的地址可以节省时间和空间。

```c++
void rect_to_polar(const rect * pxy,polar * pda);
```

- 调用函数时，要传递结构的地址
- 因为形参是指针，所以要用间接运算符->

## 函数和string对象

string对象和C风格字符串相比，string对象和结构更相似。可以将string对象赋给另一个string对象，可以传递string对象，需要多个字符串时，可以声明一个string对象组。

## 递归

C++函数可以调用自己（main()函数不允许调用自己）。

```c++
void recurs(argumentlist)
{
    statements_1;
    if (test)
        recurs(arguments);
    statements_2
}
```

如果if语句为true，每个recus()调用都会执行statements_1，然后再调用recusant()，所以不会执行statements_2。当if语句为false时，当前调用会执行statements_2，之后结束，控制权返回上一层调用...

因此，假设recus()进行了5次递归，statements_1将按顺序执行5次，然后statements_2将以与函数调用相反的顺序执行5次。

**NOTES：**每次递归都会创建自己的一套变量，当递归层数变多时，可能导致栈溢出，性能也会下降。

## 函数指针

**函数指针**是指向**函数的指针**，它保存着函数在内存中的地址，从而允许通过指针来调用函数。

**定义函数指针:**

假设有一个返回类型为`int`，参数为`int`和`float`的函数，那么函数指针的定义如下：

```C++
int (*func_ptr)(int, float);
```

- `int`：表示函数返回类型。
- `(*func_ptr)`：表示指针变量（`*func_ptr`是指针解引用）。
- `(int, float)`：表示函数参数列表。

C++函数指针的基本使用

```c++
#include <iostream>
using namespace std;

int add(int a, int b) {
    return a + b;
}

int main() {
    // 声明一个函数指针
    int (*func_ptr)(int, int);
    func_ptr = add;  // 将指针指向add函数

    // 调用函数的两种方式
    int result1 = func_ptr(3, 5);   // 直接调用
    int result2 = (*func_ptr)(3, 5); // 解引用调用

    cout << "Result1: " << result1 << endl;
    cout << "Result2: " << result2 << endl;

    return 0;
}
```

###  **如何理解函数指针**

**1. 指针是地址**

函数指针本质上是一个变量，保存了**函数的地址**，和普通指针类似。

**2. 函数的入口地址**

每个函数在编译时都被分配了一个**入口地址**，函数指针指向这个入口地址。

 **3. 通过指针调用函数**

使用`func_ptr()`或`(*func_ptr)()`来调用指针指向的函数。

### **函数指针数组**

```c++
#include <iostream>
using namespace std;

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }

int main() {
    // 声明一个函数指针数组
    int (*operations[3])(int, int) = {add, sub, mul};
	// (*operations[3])中[]的优先级高，先表明operations[3]是一个包含三个元素的数组，*表明元素类型为指针
    // (*operations[3])是函数指针数组
    // 每个指针指向的函数接收两个int参数并返回一个int值
    for (int i = 0; i < 3; i++) {
        cout << "Result: " << operations[i](5, 3) << endl;
    }

    return 0;
}

```

### 使用typedef简化函数指针

```c++
#include <iostream>
using namespace std;

// 使用typedef简化函数指针声明
typedef int (*Operation)(int, int);

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }

void execute(Operation op, int x, int y) {
    cout << "Result: " << op(x, y) << endl;
}

int main() {
    execute(add, 10, 5);
    execute(sub, 10, 5);
    return 0;
}
```

# 第八章 函数探幽

## C++内联函数

在 C++ 中，**内联函数（Inline Function）** 是一种通过编译器优化减少函数调用开销的机制。它的核心思想是将函数体直接嵌入调用处，避免传统函数调用时的压栈、跳转和返回等额外开销。

![内联函数](https://github.com/IdealistLee/Cpp_Primer_Plus/blob/main/img/inline_function.jpg "inline_Function")

使用方法：

- 函数声明前加上inline
- 函数定义前加上inline

```c++
inline int add(int a, int b) { return a + b; } //常用写法
// 调用 add(3,4) 会被替换为 (3 + 4)
```

## 引用变量

引用变量是已定义变量的别名。主要用途是用于用作函数的形参，将引用变量作为参数，函数将直接使用原始数据。对于设计类，引用必不可少。

#### 创建引用变量

C++通过&声明引用。

```c++
int rats;
int & rodents = tats; // make rodents an alias for rats
```

`int &`表明这是指向int的引用，可以将rats和rodents互换——他们指向相同的值和内存单元。

**NOTE：**必须在声明引用变量时对其初始化

#### 将引用作为函数参数

引用被用作函数参数时，函数中的变量名成为了调用程序中变量的别名。这种方式叫按引用传递，这允许调用函数使用调用函数中的变量，起到了按指针传递的作用。

函数声明：

```c++
void swapr(int &,int &);
```

![函数传递](https://github.com/IdealistLee/Cpp_Primer_Plus/blob/main/img/%E6%8C%89%E5%80%BC%E4%BC%A0%E9%80%92%E5%92%8C%E6%8C%89%E5%BC%95%E7%94%A8%E4%BC%A0%E9%80%92.jpg "传递")

> 引用传递和传递指针的区别：
>
> - 声明函数参数方式不同 
>
> ```c++
> void swapr(int & a,int & b); 
> void swapp(int * p,int * q);
> ```
>
> - 传递指针在函数使用`p`和`q`时要使用解引用运算符`*`

**const、引用参数和临时变量**

实参与引用参数不匹配时，C++将生成临时变量，但是只有参数为const引用时才会这样。

如果引用参数是const，下面两种情况会生成临时变量：

- 实参类型正确，但不是左值
- 实参类型不正确，但可以转换成正确的类型

生成临时变量之后，函数不会改变原始数据，行为类似于按值传递。旧的实现可能不报错，可能导致函数行为与预期不符。

**引用参数使用const的好处：**

- 使用const可以避免无意中修改数据的编程错误
- 使用const使函数能处理const和非const实参，否则只能接受非const数据
- 使用const引用使函数能去正确生成并使用临时变量

#### 引用与结构

引用非常适合用于结构和类。

使用结构引用的方式和引用基本变量相同；

```C++
struct free_throws
{
    std::string name;
    int made;
    int attempts;
    float percent;
};
void set_pc(free_throws & ft); // use aa reference to a structure
void display(const free_throws & ft); // don't allow changes to structure
```

#### 引用与类对象

通过引用，函数可以将string、ostream、istream、ofstream、ifstream等类的对象作为参数。

```c++
string version_1(const string & s1,const string & s2);
```

##### 对象、继承与引用

参数类型为ostream &的函数可以接受ostream对象（如cout）或者已声明的ofstream对象。

```c++
void file_it(ostream & os,double fo,const double fe[],int n);
file_it(cout , objective , eps , limit);
file_it(fout , objective , eps , limit);
```

##  默认参数

默认参数是函数调用时，省略实参时自动使用的一个值。

```c++
char * left(const char * str,int n = 1);
```

- 添加默认值时，必须从右向左添加默认值
- 实参从左到右依次赋给相应的形参，不能跳过任何形参

## 函数重载

函数多态是C++在C语言的基础上新增的功能。默认参数可以使用不同数目的参数调用同一个函数，而函数多态（函数重载）可以使用多个同名的函数。C++允许定义名称相同的函数，条件是它们的特征标不同。如果参数数目和/或参数类型不同，则特征标也不同。例如：

```c++
void print(const char * str,int width);
void print(double d,int width);
void print(const char * str);
```

## 函数模板

现在的C++编译器实现了C++新增的一项特性——函数模板。函数模板使用泛型来定义函数，其中的泛型可用具体的类型（如int或double）替换。通过将类型作为参数传递给模板，可使编译器生成该类型的函数。由于模板允许以泛型（而不是具体类型）的方式编写程序，因此有时也被称为通用编程。由于类型是用参数表示的，因此模板特性有时也被称为参数化类型（parameterized types）。

```C++
template <typename AnyType>  // 类型名AnyType可以任意选择 template、typename、<> 是必需的
// template <class AnyType> C++98之前用关键字class创建模板
void Swap(AnyType &a , AnyType &b )
{
    AnyType temp;
    temp = a;
    a = b;
    b = temp;
}
```

### 模板重载

可以像重载常规函数定义那样重载模板定义，和常规重载一样，被重载的模板的函数特征标必须不同。

```C++
template	<typename T>	// original	template
void Swap(T &a,	T &b);
template	<typename T>	// new template
void Swap(T *a, T *b,	int n);
```

### 显式具体化

>  C++98标准的具体化方法：
>
>  - 对于给定的函数名，可以有非模板函数、模板函数和显式具体化模板函数以及它们的重载版本。
>  - 显式具体化的原型和定义应以template<>打头，并通过名称来指出类型。
>  - 具体化优先于常规模板，而非模板函数优先于具体化和常规模板。

```C++
// non template function prototype
void Swap(job &, job &);

// template prototype
template <typename T>
void Swap(T &, T &);

// explicit specialization for the job type
template <> void Swap<job>(job &, job &);  // template <> void Swap(job &, job &); <job> is optional
```

### 实例化和具体化

函数模板本身并不会生成函数定义，编译器使用模板函数为特定类型生成函数定义时，生成函数示例（instantiation）。这种实例化方式叫隐式实例化（implicit instantiation）。

C++现在允许显示实例化（explicit instantiation），可以直接通过命令是编译器直接生成特定的示例。语法如下：

用`<>`指示类型，并在声明前加上关键字template

```c++
template void Swap<int>(int ,int ); // explicit specialization
```

也可以在程序中使用函数创建显式实例化。

```c++
template <class T>
T Add(T a,T b)
{
    return a+b;
}
...
int m =6;
double x = 10.2;
cout << Add<double>(x,m) <<endl; // explicit instantiation
```

`Add<double>(x,m)`会强制为double类型实例化，将m强制转换成double类型。

隐式实例化、显式实例化和显式具体化都是具体化（specialization），通过前缀`template`和`template<>`区分显式实例化和显式具体化。

```c++
template <class T>
    void Swap (T & ,T &); //template prototype

template <> void Swap<job>(job &,job &); // explicit specialization for job
int main(void)
{
    template void Swap<char>(char &,char &); // explicit instantiation for char
    short a,b;
    ...
    Swap(a,b); // implicit template instantiation for short 
    job n,m;
    ...
    Swap(n,m); // use explicit specialization for job 
    char g,h;
    ...
    Swap(g,h); // use explicit template instantiation for char
    ...
}
```

### 编译器选择函数的顺序

编译器决定使用哪一个函数定义的过程叫重载函数（overloading resolution）。

- 第1步：创建候选函数列表。其中包含与被调用函数的名称相同的函数和模板函数。
- 第2步：使用候选函数列表创建可行函数列表。这些都是参数数目正确的函数，为此有一个隐式转换序列，其中包括实参类型与相应
  的形参类型完全匹配的情况。例如，使用float参数的函数调用可以将该参数转换为double，从而与double形参匹配，而模板可以为
  float生成一个实例。
- 第3步：确定是否有最佳的可行函数。如果有，则使用它，否则该函数调用出错。

确定最佳可行函数时，最佳到最差的顺序如下：

1. 完全匹配，但常规函数优先于模板。
2. 提升转换（例如，char和shorts自动转换为int，float自动转换为double）。
3. 标准转换（例如，int转换为char，long转换为double）。
4. 用户定义的转换，如类声明中定义的转换。

***从完全匹配到最佳匹配***

如果有多个匹配的原型，编译器无法完成重载解析，编译器可能返回“ambiguous（二义性）”之类的错误消息。不过，如果是指向非const的指针和引用与指向const的指针和引用，指向非const的指针和引用优先与指向const的指针和引用，但只适用于**指针**和**引用**。

**表8.1 完全匹配允许的无关紧要转换 **

| 从实参                 | 到形参                    |
| ---------------------- | ------------------------- |
| `Type`                 | `Type&`                   |
| `Type&`                | `Type`                    |
| `Type[]`               | `*Type`                   |
| `Type (argument-list)` | `Type (*)(argument-list)` |
| `Type`                 | `const Type`              |
| `Type`                 | `volatile Type`           |
| `Type*`                | `const Type*`             |
| `Type*`                | `volatile Type*`          |

**注释说明：**

1. **`Type` ↔ `Type&`**
   - 允许在引用和非引用类型间隐式转换（例如实参是值类型，形参是引用类型，反之亦然）。
2. **数组退化为指针**
   - `Type[]` → `*Type`：数组名隐式转换为指向首元素的指针。
3. **函数到函数指针**
   - `Type (argument-list)` → `Type (*)(argument-list)`：函数名隐式转换为函数指针。
4. **限定符添加**
   - `Type` → `const Type` / `volatile Type`：允许添加 `const` 或 `volatile` 限定符。
   - `Type*` → `const Type*` / `volatile Type*`：指针类型添加底层限定符。

> [!CAUTION]
>
> 完全匹配优于另一个完全匹配的情况：
>
> - 非模板函数优于模板函数（包括显式具体化）
> - 都是模板函数时，较具体的模板函数优先；因此，显式具体化优于隐式具体化
>   - 最具体（most specialized）指编译器推断使用哪种类型时执行的转换最少。

**自定义选择函数**

`less<>(x,y)`让编译器选择模板函数。

`less<int>(x,y)`将使用显式实例化函数，x，y将会被强制转换成int。

### 进阶->模板中的类型确定

#### 关键字decltype

语法：

```c++
int x;
decltype(x) y;  // make y the same as x
decltype(x + y) xpy ; //make xpy the same as x + y
xpy = x + y;
decltype(x + y) xpy = x + y;
```

`decltype`确定类型的顺序：

假设以下声明：

```c++
delctype(experssion) var;
```

- step1：如果expression是没有用括号括起来的标识符，var的类型与标识符的类型相同，包含const等限定符；
- step2：如果expression是函数调用，var与函数的返回类型相同；
- step3：如果expression是一个左值且expression是括号括起来的标识符时，var是指向其类型的引用；
- step4：如果前面三条都不满足，var的类型和expression的类型相同。

#### C++11后置返回类型

语法原理：

```c++
double h(int x,float y);
auto h(int x,float y) -> double; 
```

`->double`为后置返回类型（trailing return type），其中`auto`是一个占位符，表示后置返回类型提供的类型。

这种语法也可以用于函数定义：

```c++
template<class T1, class T2>
auto gt(T1 x,T2 y)  -> decltype(x +y)
{
    ...
    return x + y;
}
```

# 第九章 内存模型和名称空间

## 单独编译

C++允许甚至鼓励程序员将组件函数放在独立的文件中。C++可以单独编译这些文件，然后将它们链接成可执行的程序。通常因此，可以将原来的程序分成三部分：

- **头文件**：包含结构声明和使用这些结构的函数的原型。
- **源代码文件**：包含与结构有关的函数的代码。
- **源代码文件**：包含调用与结构相关的函数的代码。

不要将函数定义或变量声明放到头文件中，除非函数是内联的，否则可能同一个程序中将包含同一个函数的两个定义，头文件中常包含的内容：

- 函数原型。
- 使用#define或const定义的符号常量。
- 结构声明。
- 类声明。
- 模板声明。
- 内联函数。

**头文件管理**

>  在同一个文件中只能将同一个头文件包含一次。预处理器编译指令#ifndef（即if not defined）可以避免多次包含同一个头文件。下面的代码片段意味着仅当以前没有使用预处理器编译指令#define定义名称COORDINH时，才处理#ifndef和#endif之间的语句：
>
>  ```c++
>  #ifndef COORDIN_H_
>  ...
>  #endif
>  ```
>
>  如果在同一个文件中遇到其他包含coordin.h的代码，编译器将知道COORDINH已经被定义了，从而跳到#endfi后面的一行上。注意，这种方法并不能防止编译器将文件包含两次，而只是让它忽略除第一次包含之外的所有内容。大多数标准C和C++头文件都使用这种防护（guarding）方案。否则，可能在一个文件中定义同一个结构两次，这将导致编译错误。

## 储存持续性、作用域和链接性

C++有三种（C++11是四种）存储数据的方案：

- 自动存储持续性：在**函数定义中声明的变量**（包括函数参数）的存储持续性为自动的。它们在程序开始执行其所属的函数或**代码块时**被创建，在执行完函数或代码块时，它们使用的内存被释放。C++有两种存储持续性为自动的变量。
- 静态存储持续性：在**函数定义外定义的变量**和使用关键字**static定义的变量**的存储持续性都为静态。它们在程序整个运行过程中都存在。C++有3种存储持续性为静态的变量。
- 线程存储持续性（C++11）：当前，多核处理器很常见，这些CPU可同时处理多个执行任务。这让程序能够将计算放在可并行处理的不同线程中。如果变量是使用**关键字thread_local声明**的，则其生命周期与所属的线程一样长。
- 动态存储持续性：用**new运算符**分配的内存将一直存在，直到使用delete运算符将其释放或程序结束为止。这种内存的存储持续性为动态，有时被称为自由存储（free store）或堆（heap）。

### 作用域和链接

作用域（scope）描述了名称在文件（翻译单元）的多大范围内可见。例如，函数中定义的变量可在该函数中使用，但不能在其他函数中使用；而在文件中的函数定义之前定义的变量则可在所有函数中使用。

链接性（linkage）描述了名称如何在不同单元间共享。链接性为外部的名称可在文件间共享，链接性为内部的名称只能由一个文件中的函数共享。自动变量的名称没有链接性，因为它们不能共享。

### 自动存储持续性

在默认情况下，在函数中声明的函数参数和变量的存储持续性为自动，作用域为局部，没有链接性。

新的定义会隐藏了（hide）以前的定义，新定义可见，旧定义暂时不可见。在程序离开该代码块时，原来的定义又重新可见（参见下图）。

![代码块与作用域](https://github.com/IdealistLee/Cpp_Primer_Plus/blob/main/img/%E4%BB%A3%E7%A0%81%E5%9D%97%E4%B8%8E%E4%BD%9C%E7%94%A8%E5%9F%9F.jpg "作用域")

### 静态持续变量

和C语言一样，C++也为静态存储持续性变量提供了3种链接性：外部链接性（可在其他文件中访问）、内部链接性（只能在当前文件中访
问）和无链接性（只能在当前函数或代码块中访问）。

要想创建链接性为外部的静态持续变量，必须在代码块的外面声明它；要创建链接性为内部的静态持续变量，必须在代码块的外面声明它，并使用static限定符；要创建没有链接性的静态持续变量，必须在代码块内声明它，并使用static限定符。

```c++
...
int global =1000;  //static duration, external linkage
static int one_file =50;  // static duration ，internal linkage
int main()
{
    ...
}
void funct1(int n)
{
    static int count = 0;  // static duration，no linkage
    int llama = 0;
    ...
}
void funct2(int q)
{
    ...
}
```

所有的静态持续变量都有下述初始化特征：未被初始化的静态变量的所有位都被设置为0。这种变量被称为零初始化的（zeroinitialized）。

**5种变量存储方式**

| 存储描述         | 持续性 | 作用域 | 链接性 | 如何声明                                           |
| ---------------- | ------ | ------ | ------ | -------------------------------------------------- |
| 自动             | 自动   | 代码块 | 无     | 在代码块中                                         |
| 寄存器           | 自动   | 代码块 | 无     | 在代码块中，使用关键字 `register`（C++11中已废弃） |
| 静态，无链接性   | 静态   | 代码块 | 无     | 在代码块中，使用关键字 `static`                    |
| 静态，外部链接性 | 静态   | 文件   | 外部   | 不在任何函数内                                     |
| 静态，内部链接性 | 静态   | 文件   | 内部   | 不在任何函数内，使用关键字 `static`                |

前C++标准（截至2025年）的变量存储方式分类及特性：

| 存储方式         | 持续性   | 作用域     | 链接性 | 声明方式与特性                            | 典型场景                   |
| ---------------- | -------- | ---------- | ------ | ----------------------------------------- | -------------------------- |
| **自动存储**     | 自动     | 代码块     | 无     | 函数内局部变量（默认无需显式声明）        | 循环计数器、临时变量       |
| **静态存储**     |          |            |        |                                           |                            |
| - 无链接性       | 静态     | 代码块     | 无     | 代码块内加`static`（如函数内静态变量）    | 函数间状态保留             |
| - 外部链接性     | 静态     | 文件       | 外部   | 全局变量（无`static`修饰）                | 跨文件共享数据             |
| - 内部链接性     | 静态     | 文件       | 内部   | 全局作用域加`static`                      | 文件内私有全局变量         |
| **动态存储**     | 动态     | 程序员控制 | 无     | `new`/`malloc`分配，需手动`delete`/`free` | 运行时不确定大小的数据结构 |
| **线程局部存储** | 线程周期 | 线程内     | 无     | `thread_local`修饰（C++11引入）           | 多线程独立数据副本         |

### 静态持续性、外部链接性

链接性为外部的变量通常简称为外部变量，它们的存储持续性为静态，作用域为整个文件。可以在文件中位于外部变量定义后面的任何函数中使用它，因此外部变量也称全局变量（相对于局部的自动变量）。

在每个使用外部变量的文件中，都必须声明它；另一方面，C++有“单定义规则”（One Definition Rule，ODR）。在其他文件引用声明时使用关键字`extern`，且不进行初始化；否则，声明为定义，导致分配存储空间。

如果要在多个文件中使用外部变量，只需在一个文件中包含该变量的定义（单定义规则），但在使用该变量的其他所有文件中，都必须使
用关键字`extern`声明它。

定义与全局变量同名的局部变量后，局部变量将隐藏全局变量。C++比C语言更进了一步——它提供了作用域解析运算符（`::`）。放在变量名前面时，该运算符表示使用变量的全局版本。

### 静态持续性、内部链接性

将static限定符用于作用域为整个文件的变量时，该变量的链接性将为内部的。但如果文件定义了一个静态外部变量，其名称与另一个文件中声明的常规外部变量相同，则在该文件中，**静态变量将隐藏常规外部变量**。

> [!CAUTION]
>
> 在多文件程序中，可以在一个文件（且只能在一个文件）中定义一个外部变量。使用该变量的其他文件必须使用关键字extern声明它。

### 静态存储持续性、无链接性

将static限定符用于在代码块中定义的变量。在代码块中使用`static`时，将导致局部变量的存储持续性为静态的。这意味着虽然该变量只在该代码块中可用，但它在该代码块不处于活动状态时仍然存在。因此在两次函数调用之间，静态局部变量的值将保持不变。

### 说明符和限定符

C++使用存储说明符（storage class specifier）或cv限定符（cv-qualifier）来提供存储的类型信息。

**存储说明符：**

- auto（在C++11中不再是说明符）；
- register；
- static；
- extern；
- thread_local（C++11新增的）；
- mutable。

在同一个声明中不能使用多个说明符，但thread_local除外，它可与static或extern结合使用。在C++11之前，可以在声明中使用关键字auto指出变量为自动变量；但在C++11中，auto用于自动类型推断。关键字register用于在声明中指示寄存器存储，而在C++11中，它只是显式地指出变量是自动的。关键字static被用在作用域为整个文件的声明中时，表示内部链接性；被用于局部声明中，表示局部变量的存储持续性为静态的。关键字extern表明是引用声明，即声明引用在其他地方定义的变量。关键字thread_local指出变量的持续性与其所属线程的持续性相同。thread_local变量之于线程，犹如常规静态变量之于整个程序。关键字mutable的含义将根据const来解释。
1．cv-限定符

- const
- volatile

关键字`volatile`表明，即使程序代码没有对内存单元进行修改，其值也可能发生变化。例如，可以将一个指针指向某个硬件位置，其中包含了来自串行端口的时间或信息。在这种情况下，硬件（而不是程序）可能修改其中的内容。或者两个程序可能互相影响，共享数据。将变量声明为volatile，相当于告诉编译器，不要进行优化，这种优化假设变量的值在这两次使用之间不会变化。

2. mutable

`mutable`用来指出，即使结构（或类）变量为const，其中某个成员也可以被修改。

3. const

在C++（但不是在C语言）中，const限定符对默认存储类型稍有影响。在默认情况下全局变量的链接性为外部的，但const全局变量的链接性为内部的。这样是为了常量定义可以放在头文件中。

如果希望某个常量的链接性为外部的，则可以使用`extern`关键字来覆盖默认的内部链接性：

```C++
extern const int states = 50; // definition with external linkage
```

此时，必须在所有使用该常量的文件中使用extern关键字来声明它。

### 函数和链接性

和C语言一样，C++不允许在一个函数中定义另外一个函数，因此所有函数
的存储持续性都自动为静态的，链接性为外部的。也可以使用关键字`static`将函数的链接性设置为内部的，使之只能在一个文件中使用。必须同时在原型和函数定义中使用该关键字：

```C++
static int private(double x);
...
static int private(double x)
{
    ...
}
```

这意味着该函数只在这个文件中可见，还意味着可以在其他文件中定义同名的的函数。和变量一样，在定义静态函数的文件中，静态函数将覆盖外部定义，因此即使在外部定义了同名的函数，该文件仍将使用静态函数。

### 语言链接性

链接程序寻找与C++函数调用匹配的函数时，使用的方法与C语言不同。但如果要在C++程序中使用C库中预编译的函数，需要用函数原型来指出要使用的约定：

```C++
// Use C protocol for name look-up
extern "C" void spiff(int i);
// Use C++ protocol for name look-up
extern void spoff(int i);
// Use C++ protocol for name look-up
extern "C++" void spaff(int i);
```

### 储存方案和动态分配

通常，编译器使用三块独立的内存：一块用于静态变量（可能再细分），一块用于自动变量，另外一块用于动态存储。

假设在一个函数中包含下面的语句：

```c++
float * p_fees = new float [20];
```

由new分配的80个字节（假设float为4个字节）的内存将一直保留在内存中，直到使用delete运算符将其释放,但当包含该声明的语句块执行完毕时，p_fees指针将消失。如果希望另一个函数能够使用这80个字节中的内容，则必须将其地址传递或返回给该函数。另一方面，如果将p_fees的链接性声明为外部的，则文件中位于该声明后面的所有函数都可以使用它。另外，通过在另一个文件中使用下述声明，便可在其中使用该指针：

```c++
extern float * p_fees ;
```

1. 使用`new`运算符初始化

   如果要为内置的标量类型（如int或double）分配存储空间并初始化，可在类型名后面加上初始值，并将其用括号括起：

   ```c++
   int *pi = new int (6); // *pi set to 6
   double *pd = new double (99.99); // *pd set to 99.99
   ```

   要初始化常规结构或数组，需要使用大括号的列表初始化(列表初始化单值变量也可以），这要求编译器支持C++11:

   ```C++
   struct where{double x;double y; double z;};
   where *one = new where {2.5, 5.3, 7.2}; // C++11
   int *ar = new int [4] {2,4,6,7}
   ```

2. `new`失败

   `new`可能找不到请求的内存量。在最初的10年中，C++在这种情况下让new返回空指针，但现在将引发异常std::bad_alloc。

3. `new`：运算符、函数和替换函数

   运算符new和new []分别调用如下函数：

   ```c++
   void * operator new(std::size_t);    // used by new
   void * operator new[](std::size_t);  // used by new[]
   ```

   这些函数被称为分配函数（alloction function），它们位于全局名称空间中。同样，也有由`delete`和`delete []`调用的释放函数（deallocation function）。C++将这些函数称为可替换的（replaceable）。如果您有足够的知识和意愿，可为new和delete提供替换函数，并根据需要对其进行定制。例如，可定义作用域为类的替换函数，并对其进行定制，以满足该类的内存分配需求。在代码中，仍将使用new运算符，但它将调用您定义的new()函数。

4. 定位`new`运算符

   通常，new负责在堆（heap）中找到一个足以能够满足要求的内存块。new运算符还有另一种变体，被称为定位（placement）new运算符，它让您能够指定要使用的位置。程序员可能使用这种特性来设置其内存管理规程、处理需要通过特定地址进行访问的硬件或在特定位置创建对象。

   要使用定位new特性，首先需要包含头文件new，它提供了这种版本的new运算符的原型；然后将new运算符用于提供了所需地址的参数。除需要指定参数外，句法与常规new运算符相同。具体地说，使用定位new运算符时，变量后面可以有方括号，也可以没有。下面的代码段演示了new运算符的4种用法：

```c++
#include <new>

struct chaff
{
    char dross[20];
    int slag;
};

char buffer1[50];
char buffer2[500];

int main()
{
    chaff *p1, *p2;
    int *p3, *p4;

    // 常规new操作
    p1 = new chaff;        // 在堆中分配结构体
    p3 = new int[20];      // 在堆中分配int数组

    // 定位new操作
    p2 = new (buffer1) chaff;   // 在buffer1中分配结构体
    p4 = new (buffer2) int[20]; // 在buffer2中分配int数组
}
```

## 名称空间

在 C++ 中，**名称空间（namespace）** 主要是为了解决 **命名冲突** 和 **代码组织** 问题。

`namespace` 在 C++ 中主要用于：

1. **避免命名冲突**（不同库或模块可能定义相同名称）。
2. **组织代码**，提高可读性和可维护性。
3. **扩展性**，C++ 标准库使用 `std` 命名空间避免污染全局作用域。

### 传统的C++名称空间

在 C++ 中，有**声明区域（declaration region）**、**潜在作用域（potential scope）** 和 **作用域（scope）**，从范围来看，三者的包含关系为：
**声明区域 ⊇ 潜在作用域 ⊇ 作用域**

1. **声明区域（Declaration Region）**

- 定义：标识符可以被声明的位置范围。例如：
  - 全局变量的声明区域是整个文件；
  - 局部变量的声明区域是其所在的代码块（如函数体或`{}`括起的区域）
- **特点**：声明区域是标识符存在的最大物理范围，但标识符不一定在整个区域中都可见。例如，全局变量 `int a;` 的声明区域是整个文件，但其实际作用域可能被同名局部变量覆盖。

2. **潜在作用域（Potential Scope）**

- 定义 ：从标识符的声明点开始，直到其声明区域结束的范围。
- 特点：
  - 潜在作用域是声明区域的一个子集，且标识符必须遵循“先声明后使用”的原则。
  - 例如，在函数内声明的变量 `int x;`，其潜在作用域从声明点开始，到函数结束为止。

3. **作用域（Scope）**

-  定义 ：标识符对程序可见的实际范围 。
-  特点：
   - 作用域可能比潜在作用域更小，因为嵌套的同名标识符会隐藏外层标识符。

### 新的名称空间特性

C++通过定义一种新的声明区域来创建命名的名称空间防止不同库或模块中的标识符（变量、函数、类等）命名冲突。C++ 使用 `namespace` 关键字定义名称空间：

```c++
namespace A {
    void print() {
        std::cout << "This is function A" << std::endl;
    }
}

namespace B {
    void print() {
        std::cout << "This is function B" << std::endl;
    }
}
```

这里，`A::print()` 和 `B::print()` 是两个独立的函数，分别属于 `A` 和 `B` 名称空间，不会冲突。

### **访问名称空间中的成员**

有多种方法访问名称空间中的元素：

 **方法 1：使用 `::` 作用域解析运算符**

```C++
int main() {
    A::print();  // 访问 A 名称空间中的 print()
    B::print();  // 访问 B 名称空间中的 print()
    return 0;
}
```

 **方法 2：使用 `using namespace` 语句（using编译）**

```
using namespace A;  // 现在可以直接使用 A 里的内容

int main() {
    print();  // 等价于 A::print()
    B::print();  // 仍然需要 B::
    return 0;
}
```

**注意**：

- 局部名称会覆盖名称空间版本
- `using namespace` 会引入整个名称空间的所有成员，可能导致命名冲突，不建议在大型项目中使用。

 **方法 3：使用 `using` 关键字（推荐）（`using`声明）**

```C++
using A::print;  // 只引入 A::print()，不会影响 B::print()

int main() {
    print();  // 现在 print() 代表 A::print()
    B::print();  // 仍然可以访问 B::print()
    return 0;
}
```

这样可以避免 `using namespace` 带来的潜在冲突。

### **名称空间的嵌套**

名称空间可以嵌套使用：

```cpp
namespace X {
    namespace Y {
        void sayHello() {
            std::cout << "Hello from X::Y" << std::endl;
        }
    }
}

int main() {
    X::Y::sayHello();  // 访问嵌套的名称空间
    return 0;
```

### **名称空间的别名**

如果名称空间名太长，可以使用 **别名**：

```CPP
namespace VeryLongNamespaceName {
    void func() {
        std::cout << "Function in VeryLongNamespaceName" << std::endl;
    }
}

// 创建别名
namespace VLN = VeryLongNamespaceName;

int main() {
    VLN::func();  // 等价于 VeryLongNamespaceName::func()
    return 0;
}
```

### **匿名名称空间**

如果不希望某些变量或函数被其他文件访问，可以使用 **匿名名称空间**：

```
cpp复制编辑namespace {
    int hiddenVar = 10;
    void hiddenFunction() {
        std::cout << "This is a hidden function" << std::endl;
    }
}

int main() {
    std::cout << hiddenVar << std::endl;
    hiddenFunction();
    return 0;
}
```

匿名名称空间的内容 **只能在当前文件中访问**，相当于 `static` 作用域。

********

**名称空间的核心作用**： 

 ✅ 组织代码，防止命名冲突
 ✅ 提高代码的可读性和可维护性
 ✅ 允许模块化开发，便于团队协作

**最佳实践**：

- 小规模项目可使用 `using namespace`，但大型项目应避免，改用 `using` 关键字或显式使用 `::`
- `std` 名称空间应谨慎使用 `using namespace std;`
- 可以使用嵌套名称空间和别名来提高代码的清晰度
- 匿名名称空间适用于限制文件作用域的变量和函数

# 第十章 抽象和类

面向对象编程（OOP）是一种特殊的、设计程序的概念性方法，也是C++和C的重要区别。下面是最重要的OOP特性：

- 抽象；
- 封装和数据隐藏；
- 多态；
- 继承；
- 代码的可重用性。

C++通过类来实现OOP特性。

## 抽象和类

### what is？

**类（Class）** 是 C++ 面向对象编程的核心概念，用于描述具有相同属性和行为的对象的抽象模板。它可以将数据（成员变量）和操作数据的方法（成员函数）封装在一起，实现代码的组织和复用。
**通俗理解**：类就像是设计图纸，对象则是根据图纸制造的具体产品。例如，“汽车”是一个类，而“某辆红色轿车”就是它的对象。

### How to do?

#### 1. **基本语法**

使用 `class` 关键字定义类，包含 **访问修饰符**（`public`、`private`、`protected`）和成员声明：

```cpp
class ClassName {
public:    // 公有成员，外部可直接访问
    // 成员函数（方法）
    void setData(int value) { 
        _data = value; 
    }
    int getData() { 
        return _data; 
    }

private:   // 私有成员，仅类内部可访问
    // 成员变量（属性）
    int _data; 
};
```

#### 2. **关键点**

- 成员变量：描述对象的属性，通常设为`private`以实现封装。
- 成员函数：定义对象的行为，通过公有接口（如`setData` 、`getData`）操作私有数据。
- 访问修饰符：
  - `public`：外部代码可直接访问（如对象调用方法）。
  - `private` ：仅在类内部访问（默认修饰符，若未显式指定）。
  - `protected`：类内部和派生类可访问。

#### 3. **类与结构体的区别**

- 默认访问权限：
  - `class`默认为`private`，适合封装复杂行为。
  - `struct`默认为`public`，适合简单数据聚合（兼容C语言用法）
- 用途：结构体常用于轻量级数据存储，类用于复杂逻辑封装。

#### 4.实现类成员函数

成员函数定义与常规函数定义非常相似，它们有函数头和函数体，也可以有返回类型和参数。但是它们还有两个特殊的特
征：

- 定义成员函数时，使用作用域解析运算符（`::`）来标识函数所属的类；
- 类方法可以访问类的private组件。

首先，成员函数的函数头使用作用域运算符解析（`::`）来指出函数所属的类。例如，update( )成员函数的函数头如下：

```c++
void Stock::update(double price)
```

其定义位于类声明中的函数都将自动成为内联函数。

### how to use

#### 1. **实例化对象**

通过类名创建具体对象：

```cpp
ClassName obj;         // 栈上创建对象
ClassName* pObj = new ClassName();  // 堆上动态创建对象
```

#### 2. **访问成员**

- **普通对象**：使用 `.` 运算符（如 `obj.setData(10)`）
- **对象指针**：使用 `->` 运算符（如 `pObj->getData()`）

```c++
#include <iostream>
using namespace std;

class Person {
public:
    void init(const char* name, int age) {
        strcpy(_name, name);  // 操作私有变量
        _age = age;
    }
    void print() {
        cout << "姓名：" << _name << "，年龄：" << _age << endl;
    }
private:
    char _name[20];
    int _age;
};

int main() {
    Person p1;                // 实例化对象
    p1.init("张三", 25);       // 调用公有方法初始化数据
    p1.print();                // 输出：姓名：张三，年龄：25
    return 0;
}
```

> [!CAUTION]
>
> - **类**是对象的抽象模板，包含数据和方法。
> - **定义类**需明确访问权限，通常将数据设为私有，方法设为公有。
> - **使用类**时通过实例化对象并调用成员函数操作数据。
> - **封装**提升了代码的安全性和可维护性。
>   - **数据保护**：私有成员变量无法被外部直接修改，避免误操作
>   - **接口统一**：通过公有方法规范数据操作（如校验输入合法性）
>   - **代码维护性**：修改内部实现时不影响外部调用

## 类的构造函数和析构函数

**构造函数（Constructor）**和**析构函数（Destructor）**是 C++ 类中两种特殊的成员函数，分别负责对象的**初始化**和**资源清理**。它们是面向对象编程中资源管理的关键机制。

### 构造函数（Constructor）

构造函数在**对象创建时自动调用**，用于初始化对象的成员变量或执行必要的初始化操作（如分配内存、打开文件等）。其名称与类名相同，没有返回值类型（连 `void` 也不允许）。

#### **特点**

-  **自动调用**：对象创建时由编译器自动触发，无需手动调用 。
-  **可重载** ：一个类可以有多个构造函数（参数不同），例如默认构造函数、带参数的构造函数、拷贝构造函数等 。
-  **默认构造函数**：若未显式定义，编译器会自动生成一个无参构造函数；但若用户定义了带参数的构造函数，则默认构造函数不再生成。

####  常见类型

- **默认构造函数** ：`ClassName() {}`（无参数） 。
- **带参数的构造函数** ：` ClassName(int a, string b) { ... }`（用于属性初始化） 。
- **拷贝构造函数**：` ClassName(const ClassName& other) { ... }`（复制对象状态）。
- **移动构造函数（C++11）**：`ClassName(ClassName&& other)`（高效转移资源） 。

#### **应用场景**

-  **初始化成员变量**：例如设置对象的初始属性值 。
-  **动态分配资源**：如打开数据库连接、分配堆内存 。

```c++
class Database {
public:
    Database(const string& host) { 
        // 构造函数中建立数据库连接
        connect(host); 
    }
};
```

### 析构函数（Destructor）

析构函数在**对象销毁时自动调用**（如作用域结束或执行 `delete`），用于释放对象占用的资源（如关闭文件、释放内存等）。其名称是类名前加 `~`，无参数且不能重载。

#### 特点

- **自动调用**：对象生命周期结束时由编译器触发 。

- **唯一性**：一个类只能有一个析构函数 。

- **默认析构函数**：若未显式定义，编译器会生成一个空的析构函数，但无法释放动态分配的资源 。

####  应用场景

- 释放动态内存：例如释放  new  分配的堆内存 。
- 清理资源：如关闭文件、断开网络连接等。

```C++
class FileHandler {
public:
    ~FileHandler() { 
        // 析构函数中关闭文件
        fclose(file); 
    }
};
```

## this指针

**`this` 指针**是 C++ 类中一个隐含的指针，指向当前对象实例的地址。它是成员函数中访问对象自身成员的桥梁，由编译器自动生成并传递，无需手动声明。

> [!NOTE]
>
> 每个成员函数（包括构造函数和析构函数）都有一个this指针。this指针指向调用对象。如果方法需要引用整个调用对象，则可以使用表达式`*this`。在函数的括号后面使用`const`限定符将`this`限定为`const`，这样将不能使用`this`来修改对象的值。然而，要返回的并不是`this`，因为`this`是对象的地址，而是对象本身，即`*this`（将解除引用运算符*用于指针，将得到指针指向的值）。现在，可以将`*this`作为调用对象的别名来完成前面的方法定义。

### `this` 的核心用途

#### 1. **解决名称冲突**

当成员变量与函数参数同名时，用 `this->` 明确指定访问对象成员：

```cpp
class Student {
private:
    int age;  // 成员变量
public:
    void setAge(int age) { 
        this->age = age;  // this->age 指向成员变量
    }
};
```

#### 2. **返回对象自身引用**

在链式调用（连续操作）中，返回 `*this` 可实现连续调用：

```cpp
class Counter {
    int count = 0;
public:
    Counter& increment() { 
        count++; 
        return *this;  // 返回当前对象的引用
    }
    Counter& reset() { 
        count = 0; 
        return *this; 
    }
};

Counter c;
c.increment().reset();  // 链式调用
```

#### 3. **在成员函数中访问其他成员**

明确调用对象自身的其他成员函数：

```cpp
class Printer {
public:
    void printA() { /* ... */ }
    void printB() { 
        this->printA();  // 显式调用同类函数
    }
};
```

## 对象数组

声明对象数组的方法与声明标准类型数组相同：

```c++
const int STKS =4;
Stock stocks[STKS]={
    Stock("one",11,12),
    Stock("two",23.2,14.8),
    Stock("three",156.0,12.36),
    Stock("four",16.9,156.2),
}
```

对象数组的使用也和标准类型数组相同，通过下标访问元素，再操作其成员变量或函数。对象数组是多个对象的集合，内存连续，每个对象独立存在。若使用隐式初始化（如 `MyClass arr[5]`），类必须提供默认构造函数。

## 类作用域

类作用域。在类中定义的名称（如类数据成员名和类成员函数名）的作用域都为整个类，作用域为整个类的名称只在该类中是已知的，在类外是不可知的。类作用域意味着不能从外部直接访问类的成员，公有成员函数也是如此。也就是说，要调用公有成员函数，必须通过对象。

### 类中的符号常量

因为声明类只是描述了对象的形式，并没有创建对象。因此，在创建对象前，将没有用于存储值的空间。有两种方式可以实现在类声明中创建符号常量：

1. 在类中声明一个枚举：

```C++
class Bakery
{
    private:
    	enum {Months = 12};
    	double costs[Months];
    ...
}
```

用这种方式声明枚举并不会创建类数据成员。也就是说，所有对象中都不包含枚举。另外，Months只是一个符号名称，在作用域为整个类的代码中遇到它时，编译器将用30来替换它。

2. 使用关键字static：

```C++
class Bakery
{
    private:
    	static const int MOnths = 12;
    	double costs[Months];
    ...
}
```

这将创建一个名为Months的常量，该常量将与其他静态变量存储在一起，而不是存储在对象中。

### 作用域内枚举

传统的枚举中两个枚举定义中的枚举量的名称不可以相同，否则会发生冲突。，C++11提供了一种新枚举，其枚举量的作用域为类，其声明如下：

```c++
enum class egg { Small, Medium, Large, Jumbo};
enum class t_shirt { Small, Medium, Large, Xlarge};
```

也可使用关键字struct代替class。无论使用哪种方式，都需要使用枚举名来限定枚举量：

```c++
egg choice = egg::Large;  // the Large enumerator of the egg enum
t_shirt Floyd = t_shirt::Large;  // the Large enumerator of the t_shirt enum
```

C++11还提高了作用域内枚举的类型安全。作用域内枚举不能隐式地转换为整型，必要时，可进行显式类型转换。

## 抽象数据类型

类方法非常适用于ADT方法

# 第十一章 使用类



## 运算符重载

运算符重载是一种形式的C++多态。运算符重载的核心目的应使代码更清晰。

C++允许将运算符重载扩展到用户定义的类型，例如，允许使用+将两个对象相加。要重载运算符，需使用被称为运算符函数的特殊函数形式。运算符函数的格式如下：

```c++
operatorop(argument-list)
```

例如，operator +( )重载+运算符，operator *( )重载*运算符。op必须是有效的C++运算符，不能虚构一个新的符号。

**示例 ：重载 `+` 运算符（成员函数）**

```cpp
class Complex {
public:
    double real;
    double imag;

    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // 重载 + 运算符（成员函数）
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }
};

int main() {
    Complex c1(1, 2), c2(3, 4);
    Complex c3 = c1 + c2;  // 等价于 c1.operator+(c2)
    cout << c3.real << " + " << c3.imag << "i";  // 输出 4 + 6i
    return 0;
}
```

### 重载运算符的限制

1. 重载后的运算符必须至少有一个操作数是用户定义的类型，这将防止用户为标准类型重载运算符。因此，不能将减法运算符（−）重
   载为计算两个double值的和，而不是它们的差。虽然这种限制将对创造性有所影响，但可以确保程序正常运行。

2. 使用运算符时不能违反运算符原来的句法规则。例如，不能将求模运算符（%）重载成使用一个操作数。同样，不能修改运算符的优先级。因此，如果将加号运算符重载成将两个类相加，则新的运算符与原来的加号具有相同的优先级。

3. 不能创建新运算符。例如，不能定义operator **( )函数来表示求幂。

4. 不能重载下面的运算符。

   - `sizeof`：sizeof运算符。
   - `.`：成员运算符。
   - `. *`：成员指针运算符。
   - `::`：作用域解析运算符。
   - `?:`：条件运算符。
   - `typeid`：一个RTTI运算符。
   - `const_cast`：强制类型转换运算符。
   - `dynamic_cast`：强制类型转换运算符。
   - `reinterpret_cas`：强制类型转换运算符。
   - `static_cast`：强制类型转换运算符。

   **C++ 可重载运算符表**

   | 运算符   | 名称             | 可重载 | 备注       |
   | :------- | ---------------- | ------ | ---------- |
   | +        | 加               | ✅      |            |
   | -        | 减               | ✅      |            |
   | *        | 乘               | ✅      |            |
   | /        | 除               | ✅      |            |
   | %        | 取模             | ✅      |            |
   | ^        | 按位异或         | ✅      |            |
   | &        | 按位与           | ✅      |            |
   | \|       | 按位或           | ✅      |            |
   | ~        | 按位取反         | ✅      | 一元运算符 |
   | !        | 逻辑非           | ✅      | 一元运算符 |
   | =        | 赋值             | ✅      |            |
   | <        | 小于             | ✅      |            |
   | >        | 大于             | ✅      |            |
   | +=       | 加等于           | ✅      |            |
   | -=       | 减等于           | ✅      |            |
   | *=       | 乘等于           | ✅      |            |
   | /=       | 除等于           | ✅      |            |
   | %=       | 取模等于         | ✅      |            |
   | ^=       | 异或等于         | ✅      |            |
   | &=       | 与等于           | ✅      |            |
   | \|=      | 或等于           | ✅      |            |
   | <<       | 左移             | ✅      |            |
   | >>       | 右移             | ✅      |            |
   | <<=      | 左移等于         | ✅      |            |
   | >>=      | 右移等于         | ✅      |            |
   | ==       | 等于             | ✅      |            |
   | !=       | 不等于           | ✅      |            |
   | <=       | 小于等于         | ✅      |            |
   | >=       | 大于等于         | ✅      |            |
   | ++       | 自增             | ✅      | 前/后置    |
   | --       | 自减             | ✅      | 前/后置    |
   | ,        | 逗号运算符       | ✅      |            |
   | ->       | 成员访问（指针） | ✅      |            |
   | ->*      | 指向成员指针     | ✅      |            |
   | ()       | 函数调用         | ✅      |            |
   | []       | 下标访问         | ✅      |            |
   | new      | 动态分配         | ✅      |            |
   | new[]    | 动态分配数组     | ✅      |            |
   | delete   | 动态释放         | ✅      |            |
   | delete[] | 释放数组         | ✅      |            |

5. 大多数运算符都可以通过成员或非成员函数进行重载，但下面的运算符只能通过成员函数进行重载。

   - `=`：赋值运算符。
   - `( )`：函数调用运算符。
   - `[ ]`：下标运算符。
   - `->`：通过指针访问类成员的运算符。

## 友元

友元的作用：**让外部函数或类访问你的私有成员**。常在以下两种情况需要友元：

- 重载运算符（如 `<<` 输出运算符），这个函数需要访问类的私有数据。
- 让某个工具函数或另一个类直接操作你的私有数据。

### 创建友元

创建友元函数的第一步是将其原型放在类声明中，并在原型声明前加上关键字friend。

第二步是编写函数定义。因为它不是成员函数，所以不要使用Classname::限定符。另外，不要在定义中使用关键字friend。

假设我们有一个 `Student` 类，私有成员是成绩。我们想让一个外部函数 `printGrade` 直接打印成绩，但成绩是私有的。这时候需要友元:

```c++
#include <iostream>
using namespace std;

class Student {
private:
    int grade;  // 私有成员，外部无法直接访问

public:
    Student(int g) : grade(g) {}

    // 声明友元函数：允许这个外部函数访问私有成员
    friend void printGrade(Student s);
};

// 外部函数（不是 Student 的成员函数！）
void printGrade(Student s) {
    // 直接访问私有成员 grade
    cout << "学生的成绩是：" << s.grade << endl;
}

int main() {
    Student stu(90);
    printGrade(stu);  // 输出：学生的成绩是：90
    return 0;
}
```

### 常用友元：重载`<<`运算符

为使`<<`运算符可以实现`cout << x << y `类似的功能，重载函数应该返回ostream对象：

```c++
#include <iostream>

using namespace std;

class Time {
private:
    int hours;
    int minutes;
public:
    Time(int h = 0, int m = 0);
    // 友元函数声明：重载 << 运算符
    friend ostream& operator<<(ostream& os, const Time& t);
};

Time::Time(int h, int m) {
    hours = h;
    minutes = m;
}

// 友元函数定义：实现 Time 类对象的输出
ostream& operator<<(ostream& os, const Time& t) {
    os << t.hours << " hours, " << t.minutes << " minutes";
    return os;
}

int main() {
    Time t1(5, 30);
    Time t2(2, 45);
    cout << "t1 = " << t1 << "; t2 = " << t2 << endl;
    return 0;
}
```

## 一个矢量类

矢量可以用两种形式表示：

```c++
// vect.h -- Vector类（动态数组）的声明和定义
#ifndef VECT_H_
#define VECT_H_

#include <iostream>

namespace VECTOR {
    class Vector {
    public:
        enum Mode {RECT, POL};  // 坐标系模式：直角坐标/极坐标

    private:
        double x;       // 直角坐标x
        double y;       // 直角坐标y
        double mag;     // 极坐标模长
        double ang;     // 极坐标角度
        Mode mode;      // 当前坐标系模式

        // 私有方法：根据x和y计算mag和ang
        void set_mag();
        void set_ang();
        void set_x();
        void set_y();

    public:
        // 构造函数
        Vector();
        Vector(double n1, double n2, Mode form = RECT);
        // 析构函数
        ~Vector();

        // 重置向量值
        void reset(double n1, double n2, Mode form = RECT);

        // 运算符重载
        Vector operator+(const Vector & b) const;  // 向量加法
        Vector operator-(const Vector & b) const;  // 向量减法
        Vector operator-() const;                  // 取反
        Vector operator*(double n) const;          // 标量乘法

        // 友元函数重载运算符
        friend Vector operator*(double n, const Vector & a);  // 标量乘法（左乘）
        friend std::ostream & operator<<(std::ostream & os, const Vector & v);  // 输出向量
    };

}  // 结束命名空间 VECTOR

#endif
```

 **关键特性说明：**

1. **坐标系模式**：
   - 通过`Mode`枚举类型支持**直角坐标（RECT）**和**极坐标（POL）**两种模式。
   - 私有成员`x`, `y`, `mag`, `ang`分别存储两种坐标系下的值。
2. **数据封装**：
   - 成员变量（如`x`, `y`, `mag`, `ang`）被声明为`private`，外部无法直接访问。
   - 提供`reset()`方法重置向量值，确保数据安全。
3. **运算符重载**：
   - 重载`+`, `-`, `*`运算符实现向量加减法和标量乘法。
   - 友元函数`operator*`支持标量左乘（如`5 * vector`）。
   - `operator<<`重载输出流，支持直接输出向量内容。
4. **实现细节**：
   - 构造函数和`reset()`方法会根据坐标系模式自动计算其他坐标值。
   - 私有方法（如`set_mag()`, `set_ang()`）用于内部坐标转换。
