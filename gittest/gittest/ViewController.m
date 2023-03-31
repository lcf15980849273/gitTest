//
//  ViewController.m
//  gittest
//
//  Created by newyea on 2023/3/3.
//

#import "ViewController.h"
#import "Cftimer.h"
#import "Action.pbobjc.h"
@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    NSLog(@"第一次提交");
    NSLog(@"第二次提交");
    NSLog(@"第三次提交");
    
    
//    [CfTimer execTask:^{
//        NSLog(@"打印");
//    } start:1.0 interval:1.0 repeats:YES async:normal];
    
    NSLog(@"修改git.ignore文件，且让文件生效");

    ActionReqPraise *praise = [[ActionReqPraise alloc]init];
    praise.roomId = @"123";
    NSData *data = [praise data];
    
    ActionReqPraise *newPraise = [ActionReqPraise parseFromData:data error:nil];

    NSLog(@"%@",newPraise);
    
}


@end
