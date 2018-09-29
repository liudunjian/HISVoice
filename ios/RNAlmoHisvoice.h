#if __has_include("RCTBridgeModule.h")
#import "RCTBridgeModule.h"
#else
#import <React/RCTBridgeModule.h>
#endif
#import <React/RCTEventDispatcher.h>
#import "HSSpeechRecognizer.h"

@interface RNAlmoHisvoice : NSObject<RCTBridgeModule>

@end

