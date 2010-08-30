//
//  PLOG.h
//  Apollo
//
//  Created by xhan on 10-8-30.
//  Copyright 2010 Baidu.com. All rights reserved.
//

/*
 some codes & ideas borrowed from  http://borkware.com/rants/agentm/mlog/
*/


#import <Foundation/Foundation.h>

#define ENABLE_PLOG
#ifdef ENABLE_PLOG

#define PLOGENV(_env_, _s_, ...) \
[PLLOG logForEnv:_env_ file:__FILE__ line:__LINE__ \
method:__PRETTY_FUNCTION__ message:_s_, ##__VA_ARGS__] 

#else

#define PLOGENV(_env_,_s_,...) ((void)0)

#endif


#define PLOG(_s_,...) PLOGENV(0, _s_, ##__VA_ARGS__)

#define PLOGWARNING(_s_,...) PLOGENV(1, _s_), ##__VA_ARGS__)

#define PLOGERROR(_s_,...) PLOGENV(2, _s_, ##__VA_ARGS__)

//TODO: add debug object, rect, position


typedef enum{
	PLOG_FORMAT_DATE = 1<<0,
	PLOG_FORMAT_TIME = 1<<1,
	PLOG_FORMAT_FILE = 1<<2,
	PLOG_FORMAT_FUNCTION = 1<<3,
	PLOG_FORMAT_LINE = 1<<4,
	PLOG_FORMAT_ENV = 1<<5
}PLOG_FORMAT;

typedef unsigned int PLOG_ENV ;

extern const int PLOG_ENV_GLOBAL; 

@interface PLLOG : NSObject 

//not works at first version
+ (void)configForEnv:(PLOG_ENV)env key:(PLOG_FORMAT)key enable:(BOOL)isEnable;

+ (void)configFormatkey:(PLOG_FORMAT)key enable:(BOOL)isEnable;


+ (void)logForEnv:(PLOG_ENV)env file:(const char*)fileName line:(int)line method:(const char*)method message:(NSString *)format, ...; 


+ (void)setLog:(PLOG_ENV)env State:(BOOL)enable;

+ (void)addEnv:(PLOG_ENV)env name:(NSString*)name;

@end