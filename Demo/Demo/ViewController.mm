//
//  ViewController.m
//  Demo
//
//  Created by Zhuo,Chuncai on 2019/1/17.
//  Copyright © 2019 Zhuo,Chuncai. All rights reserved.
//

#import "ViewController.h"
#import "SecondVC.h"
#import "MultiThread.h"
#include "AtomicTest.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include "TargetSum.hpp"
#include <string>
#include <vector>
#include "H2O.hpp"
#include "OperationComplexityO1.hpp"
#include "LFUCache.hpp"
#include "AllOne.hpp"
#include "FindMedian.hpp"
#include <ctime>
#import "LCDesign.h"
#import "BinaryTreeTraversal.h"
#import "LCSort.h"
#import "LCFind.h"
#import "LCDP.h"
#import "LCArray.h"
#import "LCGreedy.h"
#import "LCBacktracking.h"
#import "LCStack.h"
#import "DevideAndConquer.h"
#import "CPPBaseFunctionTest.hpp"
#import "ACNewPractice.h"
#import "LCList.h"
#import "LCPercentile.h"
#import "LCClassification.h"
#import "CPPTest.h"
#import "OCTest.h"
#include <iomanip>
#import "NSThreadTest.h"

//#define f(a,b) a##b
//#define g(a)   #a
//#define h(a) g(a)
using namespace std;
struct str{
    int len;
    char s[0];
};

struct foo {
    struct str *a;
};

struct test{
    int i;
    short c;
    char *p;
    char s[10];
};


typedef struct bitTestStruct{
    short int fst:7;
    short int scd:9;
} bitTestStruct;


@interface ViewController ()
{
    NSLock *_lock;
    NSThread *_thread;
    BOOL _isStopped;
    
    id _testInstance;
}
@end

@implementation ViewController

- (void)testForFun {
//    ["RandomizedSet","insert","remove","insert","getRandom","remove","insert","getRandom"]
//    [[],[1],[2],[2],[],[1],[2],[]]
    RandomizedSet* obj = new RandomizedSet();
    bool param_1 = obj->insert(1);
    bool param_2 = obj->remove(2);
    bool param_3 = obj->insert(2);
    int param_4 = obj->getRandom();
    
    bool param_5 = obj->remove(1);
    bool param_6 = obj->insert(2);
    int param_7 = obj->getRandom();
    
}


- (void)testForLC_Median {
//    ["MedianFinder","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian"]
//    [[],[-1],[],[-2],[],[-3],[],[-4],[],[-5],[]]
    
    MedianFinder *finder = new MedianFinder();

    finder->addNum(-1);
    double num1 = finder->findMedian();
    
    finder->addNum(-2);
    double num2 = finder->findMedian();

    finder->addNum(-3);
    double num3 = finder->findMedian();
    
    finder->addNum(-4);
    double num4 = finder->findMedian();
    
    finder->addNum(-5);
    double num5 = finder->findMedian();
    
    NSLog(@"num1:%.2f num2:%.2f num3:%.2f num4:%.2f num5:%.2f ", num1,  num2,  num3,  num4,  num5);
}



- (void)testForLC_Allone2 {
    AllOne* obj = new AllOne();

    
    obj->inc("a");
    obj->inc("b");
    obj->inc("b");
    obj->inc("b");
    obj->inc("b");
    
    obj->dec("b");
    obj->dec("b");

    string param_2 = obj->getMinKey();
    NSLog(@"getMinKey:%s", param_2.c_str());

    obj->dec("a");

    string param_3 = obj->getMaxKey();
    NSLog(@"getMaxKey:%s", param_3.c_str());

    string param_4 = obj->getMinKey();
    NSLog(@"getMinKey:%s", param_4.c_str());

}


- (void)testForLC_Allone {
    AllOne* obj = new AllOne();
//    obj->inc("h");
//    obj->inc("g");
//    obj->inc("h");
//    obj->inc("h");
//
//    string param_1 = obj->getMaxKey();
//    NSLog(@"getMaxKey:%s", param_1.c_str());
    
    obj->inc("a");
    obj->inc("b");
    obj->inc("b");
    
    obj->inc("c");
    obj->inc("c");
    obj->inc("c");
    
    obj->dec("b");
    obj->dec("b");

    string param_2 = obj->getMinKey();
    NSLog(@"getMinKey:%s", param_2.c_str());

    obj->dec("a");

    string param_3 = obj->getMaxKey();
    NSLog(@"getMaxKey:%s", param_3.c_str());

    string param_4 = obj->getMinKey();
    NSLog(@"getMinKey:%s", param_4.c_str());

}


- (void)testForLC_LFU2 {
//    ["LFUCache","get","put","get","put","put","get","get"]
//    [[2],[2],[2,6],[1],[1,5],[1,2],[1],[2]]
    
    LFUCache* obj = new LFUCache(2);
    int param_1 = obj->get(2);
    obj->put(2,6);
    int param_2 = obj->get(1);
    obj->put(1,5);
    obj->put(1,2);
    int param_3 = obj->get(1);
    int param_4 = obj->get(2);
    
    NSLog(@"param_1:%d param_2:%d param_3:%d param_4:%d", param_1, param_2, param_3, param_4);
}


- (void)testForLC_LFU {
    
//    ["LFUCache","put","put","put","put","get","get"]
//    [[2],[2,1],[1,1],[2,3],[4,1],[1],[2]]
    
    LFUCache* obj = new LFUCache(2);
    obj->put(2,1);
    obj->put(1,1);
    obj->put(2,3);
    obj->put(4,1);

    int param_1 = obj->get(1);
    
    int param_2 = obj->get(2);
    NSLog(@"param_1:%d param_2:%d", param_1, param_2);
}

//MARK: - LC_ALL entrance
- (void)testForLC_Entrance {
    LCClassification *classification = [LCClassification new];
    
    // list
    LCList *list = [LCList new];
    
    LCPercentile *percentile = [LCPercentile new];

    // design
    LCDesign *design = [LCDesign new];
    ACNewPractice *practice = [ACNewPractice new];
    
    [BinaryTreeTraversal new];
//    [_testInstance testForLC_Traversal];
//    
    LCSort *sort = [LCSort new];
    LCFind *find = [LCFind new];
    
    LCDP *dp = [LCDP new];
    LCArray *array = [LCArray new];
    
    LCGreedy *greedy = [LCGreedy new];
    LCBacktracking *tracking = [LCBacktracking new];
    DevideAndConquer *devide = [DevideAndConquer new];
}

- (void)testForLC_cpp {
    base *pBase = new derived;
    cout << "---" << endl;
    delete pBase;
    
    CPPTest *test = [CPPTest new];
    
}

//MARK: - OC
//OCTest
- (void)testForOC {
    OCTest *test = [OCTest new];
//    [OCTest printClassName];
}

- (void)handleNotification:(id) sender{
    NSLog(@"handleNotification");
}

- (void)testForLC_noti {
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(handleNotification:) name:@"TestNotification" object:@1];
}

template< typename T >
std::string int_to_hex( T i )
{
  std::stringstream stream;
  stream << std::setfill ('0') << std::setw(sizeof(T)*2)
         << std::hex << i;
  return stream.str();
}

void test() {
    char test_str[] = "115200";
    int test_int_d;
    sscanf(test_str, "%d", &test_int_d);
    printf("int_to_hex:%s\r\n", int_to_hex(test_int_d).c_str());
}

void test2() {
    char test_str[] = "124";
    string str(test_str);
    printf("str:%s\r\n", str.c_str());
}

int func(int x){
    int countx = 0;

    while(x) {
        countx ++;
        x = x&(x-1);
    }
    return countx;
}

int testReference(int &x) {
    
    int (* (*fp3() ) [10]) () ;
    
    int (* (*fp4())[10])();
    char str1[] = "abc";
    char str2[] = "abc";

    const char str3[] = "abc";
    const char str4[] = "abc";

    const char *str5 = "abc";
    const char *str6 = "abc";

    char *str7 = "abc";
    char *str8 = "abc";
    printf("s1:%p s2:%p \r\n ", str1, str2);
    cout << ( str1 == str2 ) << endl;//0  分别指向各自的栈内存
    cout << ( str3 == str4 ) << endl;//0  分别指向各自的栈内存
    cout << ( str5 == str6 ) << endl;//1指向文字常量区地址相同

    cout << ( str7 == str8 ) << endl;//1指向文字常量区地址相同
    
    return 0;
}

- (void)test_block {
    
    __block int test = 0;
    __weak void (^myBlock0)(void) = ^{   // stack
        test++;
    };
    NSLog(@"block0:%@",myBlock0);

    __block int temp = 10;
    NSLog(@"block1: %@",^{NSLog(@"*******%d %p",temp++,&temp);}); // malloc
    
    NSLog(@"block2: %@",^{NSLog(@"******* test");});  // global
    
    __block int static_k = 3;
    __weak void (^myBlock)(void) = ^{   // stack
        static_k++;
    };
//    myBlock();
    NSLog(@"block3:%@",myBlock);

}


- (void)test_add {
    int a = INT_MIN;
    int b = INT_MAX;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    printf("test_add %d %d \r\n", a, b);
}


- (void)viewDidLoad {
    [super viewDidLoad];

    [self test_add];
    [self test_block];
//    dispatch_async(dispatch_get_global_queue(0, 0), ^{
//        char dp[590 * 1024] = {0};
//    });
    
//    [NSThread sleepForTimeInterval:0.2];
    [self testForLC_noti];

    [NSNotificationCenter.defaultCenter postNotificationName:@"TestNotification" object:nil];

    [self testForOC];

    [self testForLC_cpp];

    multimap<int, int> map;
    map.insert(make_pair(1, 1));
    map.insert(make_pair(1, 2));
    map.insert(make_pair(2, 2));
    map.insert(make_pair(2, 1));

    [self testForLC_Entrance];
    
    
    
    
    
//    std::time_t result = std::time(nullptr);
//    NSLog(@"unix_ts:%s", std::asctime(std::localtime(&result)));
    
//    [self testForLC_Median];
    
//    NSLog(@"std::chrono::system_clock::now:%lu", std::chrono::system_clock::now);

    
//    Solution sol = Solution();
//
//    std::map<char,std::string> mymap{std::make_pair('d', "a")};
//
//    printf(" mymap.size():%d \r\n",  mymap.size());
//
//    mymap['a']="an element";
//    printf(" mymap.size():%d \r\n",  mymap.size());
//
//    mymap['b']="another element";
//    printf(" mymap.size():%d \r\n",  mymap.size());
//
//    mymap['c']=mymap['b'];
//
//    printf(" mymap.size():%d \r\n",  mymap.size());

//    std::cout << "mymap['a'] is " << mymap['a'] << '\n';
//    std::cout << "mymap['b'] is " << mymap['b'] << '\n';
//    std::cout << "mymap['c'] is " << mymap['c'] << '\n';
//    std::cout << "mymap['d'] is " << mymap['d'] << '\n';

    

//    vector<vector<int>>vtest = {{0, 1}, {1, 0}};
//    sol.canFinish(2, vtest);
    
//    ret = sol->coinChange(num, 9);
//    NSLog(@"ret2:%d", ret);
    // Do any additional setup after loading the view, typically from a nib.
//    NSArray *ipArray = @[@"111.2.3.0",
//                         @"266.445.44.3",
//                         @"abc.ddd.3d.3",
//                         @"2001:db8:3:4::192.0.2.33",
//                         @"64:ff9b::192.0.2.33",
//                         @"2001:0db8:0000:0042:0000:8a2e:0370:7334",//2001:0db8:85a3:0000:0000:8a2e:0370:7334
//                         @"ee3:ff2:gg1:hh0:ii0:jj0:kk0:821"];
//    [ipArray enumerateObjectsUsingBlock:^(NSString  * obj, NSUInteger idx, BOOL * _Nonnull stop) {
//        NSLog(@"%@ is_valid_ip :%d", obj, is_numeric(obj.UTF8String));
//    }];
//    NSLog(@"test");
   //ipv4,6 list to test
//    atomicTest();
    
//    _thread = [[NSThread alloc] initWithTarget:self selector:@selector(threadTest) object:nil];
//    [_thread start];

    [self threadTest];
}

- (void)test_trie {
    //    //app , apple , beer , add , jam , rental
    //    trie.insert("app");
    //    trie.insert("apple");
    //    trie.insert("beer");
    //    trie.insert("add");
    //    trie.insert("jam");
    //    trie.insert("rental");
    //
    //    trie.search("apple");   // returns true
    //    trie.search("app");     // returns false
    //
    //    trie.startsWith("app"); // returns true
    //    trie.search("app");     // returns true
    //    trie.startsWith("jan");     // returns true
}


- (void)threadTest{
    NSThreadTest * test = [NSThreadTest sharedInstance];
    
    int i = 0;
//    while (true) {
//        NSLog(@"loop:%d",i);
//        [NSThread sleepForTimeInterval:1];
//        if (i++ > 100) {
//            break;
//        }
//    }
}


- (void)pause
{
    
    @synchronized(_lock) {
        if (_isStopped)
            return;
    }
    NSLog(@"___________________paused");
}


- (void)stop
{
    
    
    @synchronized(_lock) {
        if (_isStopped)
            return;
        
        _isStopped = YES;
    }
    
    NSLog(@"___________________stopped");

    // do not lock AudioQueueStop, or may be run into deadlock
//    AudioQueueStop(_audioQueueRef, true);
//    AudioQueueDispose(_audioQueueRef, true);
}


bool  is_numeric(const char* host)
{
    return is_ipv4_address(host) || is_ipv6_address(host);
    //    const char *pstr = host.c_str();
    //    long length = strlen(pstr);
    //    for (int i=0; i < length; i++) {
    //        if (pstr[i] != '.' && (pstr[i] < '0' || pstr[i] > '9')) {
    //            return false;
    //        }
    //    }
    //
    //    return true;
}

bool  is_ipv4_address(const char* str)
{
    struct sockaddr_in sa;
    return inet_pton(AF_INET, str , &(sa.sin_addr)) != 0;
}

bool  is_ipv6_address(const char* str)
{
    struct sockaddr_in6 sa;
    return  inet_pton(AF_INET6, str , &(sa.sin6_addr)) != 0;
}

- (void)test:(NSDictionary*)dict {
    NSDictionary *dict2 = @{@"remove_shutdown_onPlayerReachEnd":@(1)};
    BOOL invokeShutdownFunc = [dict2[@"remove_shutdown_onPlayerReachEnd"] intValue] != 1;
    NSLog(@"shutdownInvoked:%d",invokeShutdownFunc);
}


- (void)testForNotification {
    SecondVC *vc = [SecondVC new];
    [self.navigationController pushViewController:vc animated:NO];
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.25 * NSEC_PER_SEC)), dispatch_get_global_queue(0, 0), ^{
        [[NSNotificationCenter defaultCenter] postNotificationName:@"NotiTest" object:nil];
    });
    
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        [self.navigationController popViewControllerAnimated:NO];
    });
}


@end
