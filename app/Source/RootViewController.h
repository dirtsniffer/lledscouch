
#import <UIKit/UIKit.h>
#import <Couchbaselite/CBLUITableSource.h> // NOTE: If this import fails, make sure you have copied
// (or symlinked) CouchbaseLite.framework into the "Frameworks" subdirectory, as per the README.
@class CBLDatabase, CBLReplication;


@interface RootViewController : UIViewController <CBLUITableDelegate, UITextFieldDelegate>
{
    CBLDatabase *database;
    NSURL* remoteSyncURL;
    CBLReplication* _pull;
    CBLReplication* _push;
    NSError* _syncError;
    
    UITableView *tableView;
    IBOutlet UIProgressView *progress;
    BOOL showingSyncButton;
    IBOutlet UITextField *addItemTextField;
    IBOutlet UIImageView *addItemBackground;
}

@property(nonatomic, strong) IBOutlet UITableView *tableView;
@property(nonatomic, strong) IBOutlet CBLUITableSource* dataSource;

-(void)useDatabase:(CBLDatabase*)theDatabase;

- (IBAction)configureSync:(id)sender;
- (IBAction) deleteCheckedItems:(id)sender;

@end
