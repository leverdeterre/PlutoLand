//
//  PLImageClient.h
//  PlutoLand
//
//  Created by xu xhan on 7/15/10.
//  Copyright 2010 xu han. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLImageRequest.h"

#define NOTICE_IMAGE_LOADER_SUCCEEDED @"NOTICE_IMAGE_LOADER_SUCCEEDED"

@interface PLImageLoader : PLImageRequest<PLImageRequestDelegate> {

	UIImage* _image;
	
	UIImageView* _imageView;
	UIButton* _storeButton;
	UIControlState _buttonState;
	
	BOOL _isCacheEnable;
	BOOL _isFreshOnSucceed;

	NSDictionary* _info;
}

@property (nonatomic, copy) NSDictionary *info;

- (void)fetchForImageView:(UIImageView*)imageView URL:(NSString*)url cacheEnable:(BOOL)cacheEnable userInfo:(NSDictionary*)info;

- (void)fetchForImageView:(UIImageView *)imageView URL:(NSString *)url  freshOnSucceed:(BOOL)isFresh cacheEnable:(BOOL)cacheEnable userInfo:(NSDictionary *)info;

@end


