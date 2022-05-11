//
//  SecondVC.m
//  Demo
//
//  Created by Zhuo,Chuncai on 2019/1/19.
//  Copyright © 2019 Zhuo,Chuncai. All rights reserved.
//

#import "SecondVC.h"

typedef void(^MyBlock)(void);

@interface SecondVC ()

@property int testval; //(nonatomic, assign)

@property MyBlock mblock;

@end

@implementation SecondVC

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
//    [self testNotifications];
//    [self addNotifications];
    self.mblock = ^(void) {
        NSLog(@"testval:%d", self.testval);
        return;
    };
   
}

- (void) viewWillAppear:(BOOL)animated{
    [[NSNotificationCenter defaultCenter] postNotificationName:@"test" object:nil];
    
}

- (void)viewDidAppear:(BOOL)animated {
    [self addNotifications];
}

- (void)testNotifications {
//    NSNotificationCenter addObserverForName:object:queue:usingBlock
    [[NSNotificationCenter defaultCenter] addObserverForName:@"test" object:nil queue:[NSOperationQueue mainQueue] usingBlock:^(NSNotification * _Nonnull note) {
        NSLog(@"testNotifications:%d", self.testval);
    }];
    
}

- (void)addNotifications {
//    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(notificationOccurred) name:@"NotiTest" object:nil];
}

- (void)notificationOccurred {
    NSLog(@"notificationOccurred");
    
}

- (void)dealloc {
    NSLog(@"dealloc_SecondVC");
//    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
