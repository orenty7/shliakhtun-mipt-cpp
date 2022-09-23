#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<sstream>

#include "point.h"


using namespace std;

class Rectangle {
    Point cors;
public:
    Rectangle(int x, int y): cors(Point(x, y)) {}

    Rectangle(Point point): cors(point) {}
    
    Rectangle operator+(const Rectangle &other) const {
	Point res = other.cors.maxx(this->cors).maxy(this->cors);
	return Rectangle(res);
    }

    Rectangle operator*(const Rectangle &other) const {
	Point res = other.cors.minx(this->cors).miny(this->cors);
	return Rectangle(res);
    }
    friend ostream& operator<<(ostream &out, const Rectangle &rect) {
	out << rect.cors;
	return out;
    }
};


vector<string> split(string expr_, char delimiter) {
    stringstream expr(expr_);
    string word;
    
    vector<string> res;
    while(!expr.eof()) {
	getline(expr, word, delimiter);
	res.push_back(word);
    }
    return res;
}
    
[[noreturn]] void fail(string err_msg) {
    cerr << err_msg << endl;
    exit(1);
}


#define SKIP_SPACES while(isspace(expr[pos])) pos ++
#define TEST(sym) if(expr[pos] != sym) fail("Invalid expression")

Point parsePoint(string expr) {
    
    int pos = 0;

    SKIP_SPACES;
    TEST('(');
    pos++;    
    SKIP_SPACES;

    string n1;
    while(isdigit(expr[pos])) {
	n1 += expr[pos];
	pos ++;
    }

    SKIP_SPACES;
    TEST(',');
    pos++;
    SKIP_SPACES;

    string n2;
    while(isdigit(expr[pos])) {
	n2 += expr[pos];
	pos ++;
    }

    SKIP_SPACES;
    TEST(')');
        
    return Point(stoull(n1), stoull(n2));
}

Rectangle eval(string expr) {
    vector<string> exprs = split(expr, '+');
    if(exprs.size() > 1) {
	Rectangle res = eval(exprs[0]);
	for(int i = 1; i < exprs.size(); i ++) {
	    res = res + eval(exprs[i]);
	}
	return res;
    }
    
    exprs = split(expr, '*');
    if(exprs.size() > 1) {
	Rectangle res = eval(exprs[0]);
	for(int i = 1; i < exprs.size(); i ++) {
	    res = res * eval(exprs[i]);
	}
	return res;
    }
    
    return parsePoint(expr);
}
    

int main() {
    string expression;
    getline(cin, expression);
    cout << eval(expression) << endl;
    return 0;
}
