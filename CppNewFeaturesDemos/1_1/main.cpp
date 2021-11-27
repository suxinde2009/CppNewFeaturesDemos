//
//  main.cpp
//  1_1
//
//  Created by SuXinDe on 2021/11/27.
//

#include <iostream>
#include <thread>

//join的作用是让主线程等待，直到该子线程执行结束。
//需要注意的是线程对象执行了join后就不再joinable了，所以只能调用join一次。

void hello() {
    std::cout << "Hello Concurrent World\n";
}

int main(int argc, const char * argv[]) {
    
    std::thread t(hello);
    t.join();
    
    
    return 0;
}
