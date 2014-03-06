
#import "DemoAppDelegate.h"
#import "RootViewController.h"

#import <Couchbaselite/CouchbaseLite.h> // NOTE: If this import fails, make sure you have copied
// (or symlinked) CouchbaseLite.framework into the "Frameworks" subdirectory, as per the README.

// The name of the local database the app will create. This name is mostly arbitrary, but must not
// be changed after deploying your app, or users will lose their data!
// (Note that database names cannot contain uppercase letters.)
#define kDatabaseName @"lledscouch"

// The default remote database URL to sync with, if the user hasn't set a different one as a pref.
// If you define this, the app will sync "out of the box" without the user having to configure
// anything. Most real apps will do this.
// If you don't define this, the app will initially operate offline; to make it sync the user will
// have to go to the config view and enter the URL of a remote database.
//#define kDefaultSyncDbURL @"http://sync.couchbasecloud.com/grocery-sync/"
#define kDefaultSyncDbURL @"http://tribute.hdrinnovation.com:5984/lledscouch"
//#define kDefaultSyncDbURL @"http://lledmaps.iriscouch.com/lledscouch"
@implementation DemoAppDelegate

@synthesize window;
@synthesize navigationController;
@synthesize database;


// Override point for customization after application launch.
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    NSLog(@"------ application:didFinishLaunchingWithOptions:");

#ifdef kDefaultSyncDbURL
    // Register the default value of the pref for the remote database URL to sync with:
    NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
    NSDictionary *appdefaults = [NSDictionary dictionaryWithObject:kDefaultSyncDbURL forKey:@"syncpoint"];
    [defaults registerDefaults:appdefaults];
    [defaults synchronize];
#endif
    
    // Add the navigation controller's view to the window and display.
	[window addSubview:navigationController.view];
	[window makeKeyAndVisible];

    // Initialize Couchbase Lite and find/create my database:
    NSError* error;
    self.database = [[CBLManager sharedInstance] databaseNamed: kDatabaseName error: &error];
    if (!self.database)
        [self showAlert: @"Couldn't open database" error: error fatal: YES];
    
    // Tell the RootViewController about the database:
    RootViewController* root = (RootViewController*)navigationController.topViewController;
    [root useDatabase: database];
    return YES;
}


// Display an error alert, without blocking.
// If 'fatal' is true, the app will quit when it's dismissed.
- (void)showAlert: (NSString*)message error: (NSError*)error fatal: (BOOL)fatal {
    if (error) {
        message = [NSString stringWithFormat: @"%@\n\n%@", message, error.localizedDescription];
    }
    NSLog(@"ALERT: %@ (error=%@)", message, error);
    UIAlertView* alert = [[UIAlertView alloc] initWithTitle: (fatal ? @"Fatal Error" : @"Error")
                                                    message: message
                                                   delegate: (fatal ? self : nil)
                                          cancelButtonTitle: (fatal ? @"Quit" : @"Sorry")
                                          otherButtonTitles: nil];
    [alert show];
}

- (void)alertView:(UIAlertView *)alertView didDismissWithButtonIndex:(NSInteger)buttonIndex {
    exit(0);
}




@end

