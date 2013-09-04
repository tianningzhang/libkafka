///////////////////////////////////////////////////////////////////////////
//
// libkafka - C/C++ client for Apache Kafka v0.8+
//
// David Tompkins -- 8/8/2013
// tompkins@adobe_dot_com
//
///////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2013 Adobe Systems Incorporated. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
///////////////////////////////////////////////////////////////////////////

#include <string>
#include <gtest/gtest.h>
#include "BaseTest.h"

namespace {

  class OffsetResponseTest : public BaseTest {
    protected:

      OffsetResponseTest() { }
      virtual ~OffsetResponseTest() { }
      virtual void SetUp() { } 
      virtual void TearDown() { }
  };

  TEST_F(OffsetResponseTest, Constructor) {
    
    OffsetResponse *or1 = createOffsetResponse();
    EXPECT_NE(or1, (void*)0);
    unsigned char * message = or1->toWireFormat();
    int size = or1->getWireFormatSize(true);
    EXPECT_EQ(or1->size(), size);

    OffsetResponse *or2 = new OffsetResponse(message); 
    EXPECT_NE(or2, (void*)0);
    EXPECT_EQ(or2->size(), or1->size());
    EXPECT_EQ(or2->offsetResponseTopicArraySize, or1->offsetResponseTopicArraySize);
    for (int i=0; i<or2->offsetResponseTopicArraySize; i++) {
      EXPECT_EQ(*(or2->offsetResponseTopicArray[i]), *(or1->offsetResponseTopicArray[i]));
    }

    delete or1;
    delete or2;
  }

}  // namespace
