
#import <UIKit/UIKit.h>
@class CBLServer;

@interface ConfigViewController : UIViewController

@property (nonatomic, readonly) IBOutlet UITextField* urlField;
@property (nonatomic, readonly) IBOutlet UILabel* versionField;
@property (nonatomic, readonly) IBOutlet UISwitch* autoSyncSwitch;

- (IBAction)learnMore:(id)sender;
- (IBAction)done:(id)sender;

@end
