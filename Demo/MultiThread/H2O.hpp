//
//  H2O.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2020/1/4.
//  Copyright © 2020 Zhuo,Chuncai. All rights reserved.
//

#ifndef H2O_hpp
#define H2O_hpp

#include <stdio.h>
#include <pthread.h>

#include <condition_variable>

using namespace std;

class FooBar {
private:
    int n;
    atomic_int is_first_turn;  //whether it is the turn of the first player
    mutex m;
    condition_variable cv;
public:
    FooBar(int n) {
        this->n = n;
        this->is_first_turn = 1;
    }
    
//    FooBar(FooBar &foobar) {
//        this->n = foobar.n;
//        this->is_first_turn = foobar.is_first_turn;
//    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(m);

            cv.wait(lock, [this] { return is_first_turn == 1 ? true : false; });
            is_first_turn--;

            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(m);

            cv.wait(lock, [this] { return is_first_turn == 0 ? true : false; });
            is_first_turn++;

            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            cv.notify_one();
        }
    }
};

#endif /* H2O_hpp */
