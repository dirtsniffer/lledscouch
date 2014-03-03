
#import <UIKit/UIKit.h>
@class CBLDatabase, RootViewController;


@interface DemoAppDelegate : NSObject <UIApplicationDelegate, UIAlertViewDelegate>

@property (nonatomic, strong) CBLDatabase *database;

@property (nonatomic, strong) IBOutlet UIWindow *window;
@property (nonatomic, strong) IBOutlet UINavigationController *navigationController;

- (void)showAlert: (NSString*)message error: (NSError*)error fatal: (BOOL)fatal;

@end

