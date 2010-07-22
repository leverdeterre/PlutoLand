    //
//  PLTabBarController.m
//  PlutoLand
//
//  Created by xu xhan on 7/22/10.
//  Copyright 2010 xu han. All rights reserved.
//

#import "PLTabBarController.h"


@interface PLTabBarController(Private)

- (void)changeViewToIndex:(int)index;

@end



@implementation PLTabBarController

@dynamic selectedVC;
@synthesize selectedIndex = _selectedIndex;

- (id)initWithTabBar:(PLSegmentView*)tabBar viewControllers:(NSArray*)aviewControllers
{
	if (self = [super init]) {
		tabBarView = [tabBar retain];
		tabBarView.delegate = self;
		viewControllers = [aviewControllers retain];
		[self setWantsFullScreenLayout:YES];
		containerView = nil;
		_selectedIndex = -1;
	}
	return self;
}

- (void)dealloc {
	[tabBarView release] , tabBarView = nil;
	[viewControllers release], viewControllers = nil;
    [super dealloc];
}


#pragma mark -


- (void)loadView {
	[super loadView];
	[self.view insertSubview:tabBarView atIndex:NSIntegerMax];
	
	[self updateViewAndTabBarToIndex:0];
}



- (void)viewDidLoad {
    [super viewDidLoad];
}



- (void)didReceiveMemoryWarning {
    // Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
    
    // Release any cached data, images, etc that aren't in use.
}

- (void)viewDidUnload {
    [super viewDidUnload];
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}


#pragma mark -
#pragma mark Action


- (UIViewController*)selectedVC
{
	return [viewControllers objectAtIndex:self.selectedIndex];
}


#pragma mark -
#pragma mark private

- (void)updateViewAndTabBarToIndex:(int)index
{
	[self changeViewToIndex:index];
	tabBarView.selectedIndex = index;
	
}

- (void)changeViewToIndex:(int)index
{
	if (index == _selectedIndex) 	return;

	
	[containerView removeFromSuperview];
	containerView = [(UIViewController*)[viewControllers objectAtIndex:_selectedIndex] view];
	[self.view insertSubview:containerView atIndex:1];
	
}

#pragma mark -
#pragma mark delegate of segment view

- (void)segmentClickedAtIndex:(int)index onCurrentCell:(BOOL)isCurrent
{
	[self changeViewToIndex:index];
}

@end
