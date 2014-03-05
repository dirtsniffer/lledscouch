
#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>//gps
#import <Couchbaselite/CBLUITableSource.h> // NOTE: If this import fails, make sure you have copied
// (or symlinked) CouchbaseLite.framework into the "Frameworks" subdirectory, as per the README.
#import <MapKit/MapKit.h>


@class CBLDatabase, CBLReplication;

@interface RootViewController : UIViewController <CBLUITableDelegate, UITextFieldDelegate, CLLocationManagerDelegate>
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

@property (weak, nonatomic) IBOutlet UILabel *Label;
@property(nonatomic, strong) IBOutlet UITableView *tableView;
@property(nonatomic, strong) IBOutlet CBLUITableSource* dataSource;
@property (strong, nonatomic) IBOutlet MKMapView *mapView;

-(void)useDatabase:(CBLDatabase*)theDatabase;

- (IBAction)configureSync:(id)sender;
- (IBAction) deleteCheckedItems:(id)sender;

//switch on and off
@property (strong, nonatomic) IBOutlet UISwitch *soundSwitch;
- (IBAction)saveSwitchState:(id)sender;


@end
