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

引用变量是已定义变量的别名。主要用途是用于用作函数的形参，将引用变量作为参数，函数将直接使用原始数据。对于涉及类，引用必不可少。

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

