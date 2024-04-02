//
// Created by admin on 2024/3/23.
//

#ifndef PRIMER_BASKET_H
#define PRIMER_BASKET_H

#include "string"
#include "memory"
#include "set"
#include "iostream"

using namespace std;

class Quote {
public:
    string isbn() {
        return bookNo;
    }

    virtual Quote* clone() const &{
        return new Quote(*this);
    }

    virtual Quote* clone() &&{
        return new Quote(std::move(*this));
    }

private:
    string bookNo;
};

class Bulk_quote : public Quote {
    Bulk_quote* clone() const & override {
        return new Bulk_quote(*this);
    }

    Bulk_quote* clone() && override {
        return new Bulk_quote(std::move(*this));
    }
};

/**
 * oop的工具集-basket
 */
class Basket {
public:
    void add_item(const Quote &); // copy add

    void add_item(Quote &&); // move add

    double total_receipt(ostream &) const;

    // bool条件判断
    operator bool() const{
        return true;
    }

    // function object
    void operator()(){

    }
private:
    static bool compare(const shared_ptr<Quote> &lhs, const shared_ptr<Quote> &rhs) {
        return lhs->isbn() < rhs->isbn();
    }

    multiset<shared_ptr<Quote>, decltype(compare)*> items{compare};
};

double print_total(ostream &, Quote &, size_t);

double Basket::total_receipt(ostream &os) const {
    double sum = 0.0;

    for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter)) {
        sum += print_total(os, **iter, items.count(*iter));
    }

    return sum;
}

void Basket::add_item(const Quote &obj) {

//    items.insert(make_shared<Quote>(obj));  // 此种添加方法会导致Quote derived class will be sliced down
    items.insert(shared_ptr<Quote>(obj.clone()));
}

void Basket::add_item(Quote &&obj) {
    items.insert(shared_ptr<Quote>(std::move(obj).clone())); // 要注意虽然obj是右值引用,但obj是lvalue!!!
}

#endif //PRIMER_BASKET_H
