#include "MyString.h"


MyString::MyString(){
    len = 0;
    _capacity = 1;
    string = new char[_capacity];
    string[0] = '\0';
}

MyString::MyString(const char* str)
    :MyString(str, strlen(str)){};

MyString::MyString(const std::string &str)
    : MyString(str.c_str()){};

MyString::MyString(const char *str, int n) 
    : MyString()
{
    if (!str)
        return;
    unsigned int len = strlen(str) < n ? strlen(str) : n;
    this->len = len;
    this->string = new char[len + 1];
    for (int i = 0; i < n; i++)
        this->string[i] = str[i];
    this->string[len] = '\0';
    this->_capacity = len + 1;
}

MyString::MyString(int n, const char c)
    : MyString()
{
    if (!c || n < 0)
        return;
    unsigned int len = n;
    this->len = len;
    this->string = new char[len + 1];
    for(int i = 0; i < n; i++)
        this->string[i] = c;
    this->string[len] = '\0';
    this->_capacity = len + 1;
}

MyString::MyString(const MyString &str) {
    this->len = str.length();
    this->_capacity = str.capacity();
    this->string = new char[this->_capacity];
    memcpy(this->string, str.c_str(), this->len);
    this->string[this->len] = '\0';
}

MyString::~MyString(){
    delete[] this->string;
}

MyString MyString::operator+(const MyString &str){
    MyString out_str(this->string);
    out_str.insert(this->len, str.c_str());
    return out_str;
}

MyString MyString::operator+(const char *str){
    MyString str1(this->string);
    MyString str2(str);
    return str1 + str2;
}


MyString MyString::operator+(const std::string &str){
    return this->operator+(str.c_str());
}

MyString& MyString::operator+=(const char *str){
    this->append(str);
    return *this;
}

MyString& MyString::operator+=(const std::string &str){
     return this->operator+=(str.c_str());
}
    
MyString &MyString::operator+=(const MyString& str){
    return this->operator+=(str.c_str());
}

void MyString::operator=(const char c){
    char *tmp = new char[2];
    tmp[0] = c;
    tmp[1] = '\0';
    this->operator=(tmp);
    delete[] tmp;
}

void MyString::operator=(const char *str){
    this->replace(0, this->len, str);
}

void MyString::operator=(const std::string &str){
    this->operator=(str.c_str());
}

void MyString::operator=(const MyString &str){
    this->operator=(str.c_str());
}

char& MyString::operator[](int n){
    if (n < 0 || n >= this->len)
        throw -1;
    return this->string[n];
}

int MyString::operator>(const MyString &str){
    if(strcmp(this->string, str.c_str()) > 0)
        return 1;
    return 0;
}

int MyString::operator<(const MyString &str){
    if(strcmp(this->string, str.c_str()) < 0)
        return 1;
    return 0;
}

int MyString::operator>=(const MyString &str){
    if(strcmp(this->string, str.c_str()) >= 0)
        return 1;
    return 0;
}

int MyString::operator<=(const MyString &str){
    if(strcmp(this->string, str.c_str()) <= 0)
        return 1;
    return 0;
}

int MyString::operator!=(const MyString &str){
    MyString tmp(this->string);
    return (tmp == str)? 0 : 1;
}

int MyString::operator==(const MyString &str){
    if(strcmp(this->string, str.string) == 0)
        return 1;
    return 0;
}

char *MyString::data(){
    return this->string;
}

bool MyString::empty(){
    return (len == 0) ? true:false;
}

unsigned int MyString::length() const{
    return this->len;
}

unsigned int MyString::size() const{
    return this->length();
}

void MyString::shrink_to_fit(){
    this->_capacity = this->len + 1;
    char *tmp = new char[this->_capacity];
    memcpy(tmp, this->string, this->len);
    tmp[this->_capacity] = '\0';
    delete[] this->string;
    this->string = tmp;
}

void MyString::clear(){
    for(int i = 0; i < this->len; i++)
        this->string[i] = '\0';
    this->len = 0;
}

const char * MyString::c_str() const{
    return &this->string[0];
}

unsigned int MyString::capacity() const{
    return this->_capacity;
}

void MyString::erase(int index, int n){
    if (index + n > this->len)
        return;
    unsigned int new_len = this->len - n;
    char *tmp = new char[_capacity];
    memcpy(tmp, this->string, index);
    memcpy(tmp + index, this->string + index + n, new_len - index);
    tmp[new_len] = '\0';
    this->len = new_len;
    delete[] this->string;
    this->string = tmp;
}

std::ostream& operator<<(std::ostream& out, MyString& s){
    out << s.data();
    return out;
}
std::istream& operator>>(std::istream& in, MyString& s){
    std::string buff;
    in >> buff;
    for(auto c: buff)
        s.append(1, c);
    return in;
}

void MyString::insert(unsigned int index, unsigned int n, const char c){
    char *tmp = new char[n + 1];
    for(int i = 0; i < n; i++)
        tmp[i] = c;
    tmp[n] = '\0';
    this->insert(index, tmp);
    delete[] tmp;
}

void MyString::insert(int index, const char *str){
    this->insert(index, str, strlen(str));
}

void MyString::insert(int index, const char *str, int n){
    unsigned int len_old = this->len;
    unsigned int len_str = strlen(str) < n ? strlen(str): n;
    unsigned int len_new = len_old + len_str;
    char *tmp = new char[len_new + 1];
    memcpy(tmp, this->string, index);
    memcpy(tmp + index, str, len_str);
    memcpy(tmp + index + len_str, this->string + index, len_old - index);
    tmp[len_new] = '\0';
    this->len = len_new;
    this->string = tmp;  
    this->_capacity = this->_capacity > len_new + 1? this->_capacity:(len_new + 1); 
}

void MyString::insert(int index, const std::string &str){
    this->insert(index, str.c_str());
}

void MyString::insert(int index, const std::string &str, int n){
    this->insert(index, str.c_str(), n);
}

void MyString::append(int count, const char c){
    this->insert(this->len, count, c);
}

void MyString::append(const char * str){
    this->insert(this->len, str);
}

void MyString::append(const char* str, int index, int count){
    this->insert(this->len, str + index, count);
}

void MyString::append(std::string &str){
    this->append(str.c_str());
}

void MyString::append(std::string &str, int index, int count){
    this->append(str.c_str(), index, count);
}

void MyString::replace(int index, int count, const char*str){
    this->erase(index, count);
    this->insert(index, str);
}

void MyString::replace(int index, int count, std::string &str){
    this->replace(index, count, str.c_str());
}

MyString MyString::substr(int index){
    return this->substr(index, this->len - index);
}

MyString MyString::substr(int index, int count){
    MyString tmp(this->string + index, count);
    return tmp;
}

int MyString::find(const char *str, int index){
    return strstr(this->string + index, str) - this->string;
}

int MyString::find(const char *str){
    return this->find(str, 0);
}

int MyString::find(std::string &str){
    return this->find(str.c_str(), 0);
}

int MyString::find(std::string &str, int index){
    return this->find(str.c_str(), index);
}
