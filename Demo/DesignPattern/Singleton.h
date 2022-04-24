//
//  Singleton.h
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/4/22.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef Singleton_h
#define Singleton_h
namespace Singleton {

class SingletonTest {
private:
    SingletonTest() {}                    // Constructor? (the {} brackets) are needed here.

    // C++ 03
    // ========
    // Don't forget to declare these two. You want to make sure they
    // are inaccessible(especially from outside), otherwise, you may accidentally get copies of
    // your singleton appearing.
    SingletonTest(SingletonTest const&);              // Don't Implement
    
    void operator=(SingletonTest const&);   // Don't implement

    // C++ 11
    // =======
    // We can use the better technique of deleting the methods
    // we don't want.
public:
    SingletonTest& getInstance() {
        static SingletonTest instance;
        return instance;
    }
};


}

#endif /* Singleton_h */
