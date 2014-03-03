## Devise Tracker for iOS

This is a simple demo app showing how to use the [Couchbase Lite][1] framework to embed a nonrelational ("NoSQL"), document-oriented database in an iOS app and sync it with a database server in "the cloud".

Here's the "user story":

> "This is a very simple app that tracks an iOS devise and retains all info on location.  The story is, I lost my phone and I want to know the last place it was at before it turned off.  Sure use the FREE "find ME" apps out there but you will be out of luck because they delete all data older than a couple days.  WHY???? 


The app just syncs a local database to a realtime Server onewith all other users who are synced with the same cloud database.

Syncing is not enabled by default. To enable it, press the "Configure" button and enter the URL of a [Couchbase Sync Gateway](http://www.couchbase.com/communities/couchbase-sync-gateway) (or [Couchbase Cloud](http://console.couchbasecloud.com/index/), or [Apache CouchDB][2]) database. For more info about setting up the Sync Gateway, [read the getting started guide](https://github.com/couchbase/sync_gateway/wiki/Installing-And-Upgrading).

## Building & Running The App

These instructions assume you are familiar with building and running an iOS app.

If you have questions or get stuck or just want to say hi, please visit the [Mobile-Couchbase group][4] on Google Groups.

Prerequisite: Xcode 4.6 or later with the SDK for iOS 6 or later.

### Get the main repository

    git clone git://github.com/couchbaselabs/iOS-Couchbase-Demo.git

### Get the Couchbase Lite framework

1. [Download][1] Couchbase Lite for iOS.
2. Copy `CouchbaseLite.framework` into the `Frameworks` directory of this repo.

### Open the Xcode workspace

    open GrocerySync.xcodeproj

### Build and run

1. Select the appropriate destination (an iOS device or simulator) from the pop-up menu in the Xcode toolbar.
2. Click the Run button

That's it! Now that you're set up, you can just use the Run command again after making changes to the demo code.

### Configuring sync

As configured, the app doesn't sync anywhere by default. The user can tap the "Configure" button and enter the URL of a remote database to sync with. To experiment with this, you can use `http://sync.couchbasecloud.com/grocery-sync/`, which is a database we've set up in Couchbase Cloud for this purpose. Or if you set up your own local Sync Gateway, you'd use a URL like `http://mycomputer.local:4984/grocery-sync/` (filling in your computer's hostname or IP address.)


## Adding Couchbase Lite to your existing Xcode project

Please see the documentation for [Couchbase Lite][6].


## License

Released under the Apache license, 2.0.

Copyright 2011-2013, Couchbase, Inc.

[1]: http://www.couchbase.com/communities/couchbase-lite
[2]: http://couchdb.apache.org
[4]: https://groups.google.com/group/mobile-couchbase
[5]: https://github.com/couchbase/couchbase-lite-ios/wiki/Building-Couchbase-Lite#building-the-framework
[6]: http://docs.couchbase.com/couchbase-lite/cbl-ios/#adding-couchbase-lite-to-your-app