//
//  main.m
//  AudioRecorder
//
//  Copyright TrailsintheSand.com 2008. All rights reserved.
//

#import <UIKit/UIKit.h>

int main(int argc, char *argv[])
{
    NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];
    int retVal = UIApplicationMain(argc, argv, nil, @"AudioRecorderAppDelegate");
    [pool release];
    return retVal;
}
