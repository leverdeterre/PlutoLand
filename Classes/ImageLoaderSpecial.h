//
//  ImageLoaderSpecial.h
//  PlutoLand
//
//  Created by xu xhan on 7/16/10.
//  Copyright 2010 xu han. All rights reserved.
//

#import <UIKit/UIKit.h>


@interface ImageLoaderSpecial : UITableViewController {
	NSOperationQueue *queue;
	NSMutableArray* entries;
}

@property (nonatomic, copy) NSMutableArray *entries;
@property (nonatomic, retain) NSOperationQueue *queue;

@end


