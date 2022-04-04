//
//  SecondVC.m
//  Demo
//
//  Created by Zhuo,Chuncai on 2019/1/19.
//  Copyright © 2019 Zhuo,Chuncai. All rights reserved.
//

#import "SecondVC.h"

@interface SecondVC ()

@end

@implementation SecondVC

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    
   
}

- (void) viewWillAppear:(BOOL)animated{
    [self addNotifications];
}

- (void)viewDidAppear:(BOOL)animated {
    [self addNotifications];
}

- (void)addNotifications {
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(notificationOccurred) name:@"NotiTest" object:nil];
}

- (void)notificationOccurred {
    NSLog(@"notificationOccurred");
    
}

- (void)dealloc {
    [[NSNotificationCenter defaultCenter] removeObserver:self];
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
