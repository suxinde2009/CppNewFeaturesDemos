//
//  main.cpp
//  2_2
//
//  Created by SuXinDe on 2021/11/27.
//

#include <thread>
#include <iostream>

using namespace std;


bool isWaiting = false;

void do_something(int& i) {
    printf("%d\n", i);
    ++i;
}

struct func {
    int& i;
    
    func(int& i_): i(i_) {
        isWaiting = true;
    }
    
    void operator()() {
        for(unsigned j = 0; j < 1000; ++j) {
            do_something(i);
        }
        isWaiting = false;
    }
};

void do_something_in_current_thread() {
    
}

void f() {
    int some_local_state = 0;
    func my_func(some_local_state);
    std::thread my_thread(my_func);
    
    try {
        do_something_in_current_thread();
    } catch(...) {
        my_thread.join();
        throw;
    }
    my_thread.join();
}



int main(int argc, const char * argv[]) {
    
    f();
    
    while (isWaiting) {
        
    }
    
    return 0;
}
