/*
 Copyright (c) 2016-present, salesforce.com, inc. All rights reserved.
 
 Redistribution and use of this software in source and binary forms, with or without modification,
 are permitted provided that the following conditions are met:
 * Redistributions of source code must retain the above copyright notice, this list of conditions
 and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice, this list of
 conditions and the following disclaimer in the documentation and/or other materials provided
 with the distribution.
 * Neither the name of salesforce.com, inc. nor the names of its contributors may be used to
 endorse or promote products derived from this software without specific prior written
 permission of salesforce.com, inc.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
 IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY
 WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import <Foundation/Foundation.h>
#import <SalesforceSDKCore/SFEncryptionKey.h>
#import <SalesforceSDKCore/SFCryptChunks.h>
#import <SalesforceSDKCore/SalesforceSDKConstants.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * `SFDecryptStream` implements an input stream that decrypts data immediately after it's read.
 * It uses `SFCryptChunks` to perform the decryption.
 */
SFSDK_DEPRECATED(9.2, 10.0, "Will be used internally for upgrade steps only. Use SFSDKDecryptStream instead")
@interface SFDecryptStream : NSInputStream <SFCryptChunksDelegate>

/**
 *  Setup for decryption. Always call either this method or `setupWithKey:andInitializationVector:` 
 *  before using this stream. 
 *  @param decKey Decryption key.
 */
- (void)setupWithDecryptionKey:(SFEncryptionKey* )decKey;

/**
 *  Setup for decryption. Always call either this method or `setupWithDecryptionKey:` 
 *  before using this stream. Internally, this method initializes the decryption key using `key` and `iv` and then calls 
 *  `setupWithDecryptionKey:`. 
 *  @param key Cipher key.
 *  @param iv  Initialization vector. Its size must match `SFCryptChunksCipherBlockSize`.
 */
- (void)setupWithKey:(NSData *)key andInitializationVector:(nullable NSData *)iv;

@end

NS_ASSUME_NONNULL_END
