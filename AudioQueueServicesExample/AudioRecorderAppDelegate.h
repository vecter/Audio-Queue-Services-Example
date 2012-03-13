//
//  AudioRecorderAppDelegate.h
//  AudioRecorder
//
//  Copyright TrailsintheSand.com 2008. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AudioToolbox/AudioQueue.h>
#import <AudioToolbox/AudioFile.h>

#define NUM_BUFFERS 3
#define SECONDS_TO_RECORD 10

// Struct defining recording state
typedef struct
{
    AudioStreamBasicDescription  dataFormat;
    AudioQueueRef                queue;
    AudioQueueBufferRef          buffers[NUM_BUFFERS];
    AudioFileID                  audioFile;
    SInt64                       currentPacket;
    bool                         recording;    
} RecordState;

// Struct defining playback state
typedef struct
{
    AudioStreamBasicDescription  dataFormat;
    AudioQueueRef                queue;
    AudioQueueBufferRef          buffers[NUM_BUFFERS];
    AudioFileID                  audioFile;
    SInt64                       currentPacket;
    bool                         playing;
} PlayState;

// The main application
@interface AudioRecorderAppDelegate : NSObject  <UIApplicationDelegate>
{
    UIWindow *window;
    UILabel* labelStatus;
    UIButton* buttonRecord;
    UIButton* buttonPlay;
	RecordState recordState;
    PlayState playState;
    CFURLRef fileURL;
}

@property (nonatomic, retain) UIWindow *window;

- (BOOL)getFilename:(char*)buffer maxLenth:(int)maxBufferLength;
- (void)setupAudioFormat:(AudioStreamBasicDescription*)format;
- (void)recordPressed:(id)sender;
- (void)playPressed:(id)sender;
- (void)startRecording;
- (void)stopRecording;
- (void)startPlayback;
- (void)stopPlayback;

@end
