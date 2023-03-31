//
//  CfTimer.h
//

#import <Foundation/Foundation.h>

@interface CfTimer : NSObject

/*! @brief 创建一个带block的定时器
 *。
 * @param task 在定时器上需要执行的任务
 * @param start  几秒后开始
 * @param interval  每次执行间隔时间
 * @param repeats  是否重复执行
 * @param async  同步还是异步（同步在主线程中执行、异步在子线程中执行）
 * @return 返回定时器的唯一标识，在cancelTask方法中传入可停止定时器。
 */
+ (NSString *)execTask:(void(^)(void))task
                 start:(NSTimeInterval)start
              interval:(NSTimeInterval)interval repeats:(BOOL)repeats async:(BOOL)async;


/*! @brief 创建一个方法定时器
 *。
 * @param target 目标地
 * @param selector 执行的方法
 * @param start  几秒后开始
 * @param interval  每次执行间隔时间
 * @param repeats  是否重复执行
 * @param async  同步还是异步（同步在主线程中执行、异步在子线程中执行）
 * @return 返回定时器的唯一标识，在cancelTask方法中传入可停止定时器。
 */
+ (NSString *)execTask:(id)target
              selector:(SEL)selector
                 start:(NSTimeInterval)start
              interval:(NSTimeInterval)interval repeats:(BOOL)repeats async:(BOOL)async;


/*! @brief 取消定时器方法
 * @param name 定时器唯一标识，由上述两个方法调用所得
 */
+ (void)cancelTask:(NSString *)name;

@end



/*
 使用示例
__block int timeout = 100;
[CfTimer execTask:^{
    if (timeout == 0) {
        [CfTimer cancelTask:@""];
    }else {
        timeout--;
    }
    dispatch_async(dispatch_get_main_queue(), ^{
        
    });
} start:1 interval:1 repeats:YES async:NO];*/
