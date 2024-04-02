//
// Created by admin on 2024/3/19.
//

#include "Chapter12_dynMery.h"

#include "memory"
#include "string"
#include "vector"
#include "new"

using namespace std;

/**
 * 第十二章
 * Dynamic Memory - Smart Pointer
 * 动态内存可以使用指针机制来实现,并通过destruct析构方法来管理;
 * 1.用于多个对象分享状态
*/

void test_shared_ptr() {
    shared_ptr<string> ptr;
    auto vec_ptr = make_shared<vector<int>>();

    // allocate and delete dynamic memory
    // build-in type is not smart point!!! need manipulate free memory by delete it!
    int *p1 = new(nothrow) int();
    delete p1;

    unique_ptr<string> u_ptr;
    u_ptr = std::make_unique<string>("hello world");
}

void test_allocator() {
    allocator<vector<int>> alloc;
    vector<int> vi{1, 2, 3, 4, 5};

    auto p1 = alloc.allocate(10);
    for(int i=0; i<10; i++){
        alloc.construct(p1++,i);
    }

    alloc.destroy(--p1);
    alloc.deallocate(p1, 10);


    auto p = alloc.allocate(vi.size() * 2);
    auto q = uninitialized_copy(vi.begin(), vi.end(), p);
    uninitialized_fill_n(q, vi.size(), 42);
}

