**C语言的头文件不封装于`std`命名空间**

C++98 1.0版本

C++11 2.0版本

# 0、STL

- `P.J.版本`：windows vc++ 采用
- `RW版本`
- `SGI版本`：Linux下GCC采用。该版本可读性强 

# 1、Constructors

**std::string::string**

```cc
*	   default(1) string();
*		  copy(2) string (const string& str);
*	 substring(3) string (const string& str, size_t pos, size_t len = npos);
*from c-string(4) string (const char* s);
*from sequence(5) string (const char* s, size_t n);
*  		  fill(6) string (size_t n, char c);
		 range(7) template <class InputIterator>
 				 	string  (InputIterator first, InputIterator last);
```

## 1.1 default

```cc
string s;
string s();
```

## 1.2 有参构造（C字符串构造）

```cc
string s("hello");
string s = "hello"; // 先有参构造临时变量，再拷贝构造s。优化为直接有参构造s
```

## 1.3 copy

```cc
string s1 = s2;
string s1(s2);
```

## 1.4 字符填充构造

```c
*fill(6) string (size_t n, char c);

string s(3, 'a'); // aaa
```

## 1.5 序列构造(C字符串)

```cc
*from sequence(5) string (const char* s, size_t n);
// n是长度

string s("hello", 2); // he
```

## 1.6 substring

**默认从0开始**

```cc
*substring(3) string (const string& str, size_t pos, size_t len = npos);
// pos是位置，len是长度

string s1("hello");
string s2(s1, 1); // ello
string s2(s1, 1, 8); // ello
string s2(s1, 1, string::npos); // ello
```

# 2、std::string::npos

```cc
static const size_t npos = -1; // unsigned int最大值
```

# 3、operators overloading

## 3.1 std::string::operator+=

```cc
   string(1) string& operator+= (const string& str);
 c-string(2) string& operator+= (const char* s);
character(3) string& operator+= (char c);
```

## 3.2 std::string::operator[]

```cc
char& operator[] (size_t pos);
const char& operator[] (size_t pos) const;
```

# 4、Iterators

左闭右开：`[ )`

- const对象调用const迭代器
- 四种迭代器：iterator、const_iterator、reverse_iterator、const_reverse_iterator
- `*iterator`是一个`char`

## 4.1 std::string::begin

```cc
iterator begin();
const_iterator begin() const;
```

## 4.2 std::string::end

**指向最后一个元素的下一个位置**（符合左闭右开）

```cc
iterator end();
const_iterator end() const;
```

## 4.3 std::string::rbegin

```cc
reverse_iterator rbegin();
const_reverse_iterator rbegin() const;
```

## 4.4 std::string::rend

**指向第一个元素的前一个位置**（符合左闭右开）

```cc
reverse_iterator rend();
const_reverse_iterator rend() const;
```

# 5、范围for

`C++11`支持，**有迭代器就可以用范围`for`**（普通数组也行）

# 6、Capacity

```cc
size_t size() const;
size_t length() const;
size_t max_size() const; //4294967294，最后一个给 \0
size_t capacity() const; // 2倍增容
void reserve (size_t n = 0);
void clear(); // size变为0，capacity不变
bool empty() const;
```

## 6.1 std::string::resize

- `.resize(100)`, 让`.size()`变为`100`，`capacity>=100`。并且**初始化**
  - `string`初始化全为`0（\0'）`
- `.resize(<.size())`，截断

```cc
void resize (size_t n);
void resize (size_t n, char c);
```

# 7、Modifiers

## 7.1 std::string::push_back

```c
void push_back (char c);  // 不是字符串，只能字符
```

## 7.2 std::string::append

```cc
*   string(1) string& append (const string& str);
substring(2) string& append (const string& str, size_t subpos, size_t sublen);
* c-string(3) string& append (const char* s);
   buffer(4) string& append (const char* s, size_t n);
	 fill(5) string& append (size_t n, char c);
	range(6) template <class InputIterator>
   				string& append (InputIterator first, InputIterator last);
```

## 7.3 std::string::insert

**默认从0开始**

```cc
*      	   string(1) string& insert (size_t pos, const string& str);
        substring(2) string& insert (size_t pos, const string& str, size_t subpos, size_t sublen);
*		 c-string(3) string& insert (size_t pos, const char* s);
		   buffer(4) string& insert (size_t pos, const char* s, size_t n);
             fill(5) string& insert (size_t pos, size_t n, char c);
    				 void insert (iterator p, size_t n, char c);
*single character(6) iterator insert (iterator p, char c);
		   range (7) template <class InputIterator>
   			   		  void insert (iterator p, InputIterator first, InputIterator last);
```

## 7.4 std::string::erase

```cc
 sequence(1) string& erase (size_t pos = 0, size_t len = npos);
character(2) iterator erase (iterator p);
    range(3) iterator erase (iterator first, iterator last);
```

# 8、String operations

## 8.1 std::string::c_str

底层是一个**字符指针**，需要开空间时在**堆区**开

```c
const char* c_str() const;
```

```cc
string s = "hello";
// 获取字符数组首地址，以c字符串的形式遍历
const char* str = s.c_str();
while(*str)
{
    cout << *str << " ";
    ++str;
}

// 调用operator<<
cout << s << endl;
// 直接输出const char*
cout << s.c_str << endl;


s += '\0';
s += "world"
// 调用operator<<，将对象数组中的所有字符输出，size全部输出
cout << s << endl;
// 直接输出const char*, 遇到’\0‘结束
cout << s.c_str << endl; 
```

## 8.2 std::string::substr

```cc
string substr (size_t pos = 0, size_t len = npos) const;
```

## 8.3 std::string::find

- **默认0开始**

```cc
   string(1) size_t find (const string& str, size_t pos = 0) const;
 c-string(2) size_t find (const char* s, size_t pos = 0) const;
   buffer(3) size_t find (const char* s, size_t pos, size_t n) const; // n是长度
character(4) size_t find (char c, size_t pos = 0) const;

// 找不到返回std::string::npos
// 第三个参数n是要搜索的 子串的长度
```

## 8.4 例子

```cc
string s("s.c");

size_t pos = s.find('.'); // 1
if (pos != string::npos)
{
    cout << s.substr(pos) << endl; // .c
}
```

**数组下标相减，是 `i `到` j - 1` 的总个数**

```cc
void split_url(const string* url)
{
    // split: 协议 域名 资源名称
    // http://www.baidu.com/xxx
    size_t pos1 = url.find(':');
    if (posl != string::npos)
        cout << url.substr(0, pos1) << endl; // http
    
    size_t pos2 = url.find('/', pos1 + 3);
    if (pos2 != string::npos)
        cout << url.substr(pos1 + 3, pos2 - (pos1 + 3)) << endl;
    
    cout << url.substr(pos2 + 1) << endl; // xxx
}
```

# 9、std::find

**注意`[ )`**

```cc
template <class InputIterator, class T>
   InputIterator find (InputIterator first, InputIterator last, const T& val);
// 成功返回改位置迭代器
// 失败返回第二个参数
```

# 10、Non-member function overloads

## 10.1 std::swap(string)

```cc
void swap (string& x, string& y); // 所有内容都换了
```

```cc
template <class T>
void swap(T& a, T& b)
{
    T c(a);
    a = b;
    b = c;
}
```

## 10.2 std::operator+(string)

**pass by value**，not pass by reference（to const）

```cc
   string (1) string operator+ (const string& lhs, const string& rhs);
 c-string (2) string operator+ (const string& lhs, const char* rhs);
			  string operator+ (const char* lhs, const string& rhs);
character (3) string operator+ (const string& lhs, char rhs);
			  string operator+ (char lhs, const string& rhs);
```

## 10.3 std::getline(string)

此大标题是**非成员**函数重载

- 读取的内容转换为**`string类型`**

```cc
(1) istream& getline (istream& is, string& str, char delim); // 遇到参数字符delim停
(2) istream& getline (istream& is, string& str);  // 遇到\n停
// 文件结尾、输入期间发生错误，也会停
// 返回第一个参数

// 合并
istream& getline (istream& is, string& str, char delim = '\n'); 
```

## 10.3.1 std::istream::getline

```cc
istream& getline (char* s, streamsize n); // '\n' 停
istream& getline (char* s, streamsize n, char delim); // 字符delim停

// 合并
istream& getline (char* s, streamsize n, char delim = '\n'); // 字符delim停
```

```cc
// 由于是istream类中的函数。所以要对象.
cin.getline();
```

### 10.3.2 补充

- `cin`和`scanf`遇到空字符结束

- 6个空字符

  - ```
    水平制表符\t: ascii 9。使光标水平移动到下一个指标位
    \n: ascii 10 （LF）
    垂直制表符\v: ascii 11。通常在打印机使用，使光标垂直移动到下一个指标位
    换页\f: ascii 12。通常在打印机使用，表示换页
    回车\r: ascii 13。与\n一起用(CRLF)，光标移动到行首 （CR）
    空格“ ”：ascii 32
    ```

- **CR**：Carriage Return，对应ASCII中转义字符**\r**，表示回车
- **LF**：Linefeed，对应ASCII中转义字符**\n**，表示换行
- **CRLF**：Carriage Return & Linefeed，**\r\n**，表示回车并换行
- Windows  CRLF**；Unix/**Linux**/Mac OS 采用单个字符**LF 换行；MacIntosh（早期Mac操作系统）CR换行
- **LF（linux） -> CRLF（windows）**

# 11、std::reverse

注意：`[ )`

- 是对原有的操作

```cc
template <class BidirectionalIterator>
  void reverse (BidirectionalIterator first, BidirectionalIterator last);
```

# 12、std::to_string

```cc
#include <string>
string to_string (int val);
string to_string (long val);
string to_string (long long val);
string to_string (unsigned val);
string to_string (unsigned long val);
string to_string (unsigned long long val);
string to_string (float val);
string to_string (double val);
string to_string (long double val);
```

# 13、编码

```
GBK: 包含简体和繁体，一个汉字占2byte，定长编码。英文字符占1byte
Unicode: 万国码。utf-8是它的一种实现方式，英文字符1byte，汉字通常3byte

utf-8兼容ASCII
gbk不兼容ASCII

linux下utf8
windows下gbk(gb2312)
```

# 14、模拟实现

# 14.1 strlen()

```c
#include <string.h>

size_t strlen(const char *s);
```

- **`strlen(nullptr)`因为空指针解引用出错**
  - **`strlen("") `可以**，相当于对空字符串解引用，得到`'\0'`

## 14.2 返回引用问题

```cc
char& string::operator[](size_t i)
{
    return _str[i];
}
// 为什么可以返回引用? 因为_str的构造函数都是在堆上开空间
```

## 14.3 防止自己给自己赋值问题

```cc
string& string::operator=(const string& s)
{
    // if (s != *this)  //需要类中opserator!=
    if (&s != this) // 地址比较，不用重载运算符
    {
        // ...
    }
}
```