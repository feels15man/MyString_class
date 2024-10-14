#ifndef INCLUDE_MYSTRING_H
#define INCLUDE_MYSTRING_H

#include <cmath>
#include <iostream>
#include <string>
#include <cstring>

class MyString {
private:
    char* string;
    unsigned int len;
    unsigned int _capacity;
public:
    MyString(void);
    MyString(const char *, int);
    MyString(int, const char);
    MyString(const MyString &);
    MyString(const char*);
    MyString(const std::string &);
    ~MyString();

    MyString operator+(const MyString &);
    MyString operator+(const char *);
    MyString operator+(const std::string &);

    MyString& operator+=(const char *);
    MyString& operator+=(const std::string &);
    MyString& operator+=(const MyString&);

    void operator=(const char);
    void operator=(const std::string &);
    void operator=(const char *);
    void operator=(const MyString &);

    char &operator[](int);
    int operator>(const MyString &);
    int operator<(const MyString &);
    int operator>=(const MyString &);
    int operator<=(const MyString &);
    int operator!=(const MyString &);
    int operator==(const MyString &);
    
    friend std::ostream& operator<<(std::ostream&, MyString&);
    friend std::istream& operator>>(std::istream&, MyString&);

    char *data();
    bool empty();
    void shrink_to_fit();
    void clear();
    void erase(int, int);

    unsigned int size() const;
    unsigned int length() const;
    const char *c_str() const;
    unsigned int capacity() const; 

    void insert(unsigned int, unsigned int, const char);
    void insert(int, const char *);
    void insert(int, const char *, int);
    void insert(int, const std::string &);
    void insert(int, const std::string &, int);

    void append(int, const char);
    void append(const char *);
    void append(const char *, int, int);
    void append(std::string &);
    void append(std::string &, int, int);

    void replace(int, int, const char *);
    void replace(int, int, std::string &); 

    MyString substr(int); 
    MyString substr(int, int); 

    int find(const char *);
    int find(const char *, int);
    int find(std::string &);
    int find(std::string &, int);
};  

#endif