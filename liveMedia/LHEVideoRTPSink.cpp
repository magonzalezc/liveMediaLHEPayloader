// RTP sink for LHE video
// Implementation

#include "LHEVideoRTPSink.hh"

LHEVideoRTPSink
::LHEVideoRTPSink(UsageEnvironment& env, Groupsock* RTPgs)
  : VideoRTPSink(env, RTPgs, 69, 90000, "LHE") {
}

LHEVideoRTPSink::~LHEVideoRTPSink() {
}

LHEVideoRTPSink*
LHEVideoRTPSink::createNew(UsageEnvironment& env, Groupsock* RTPgs) {
  return new LHEVideoRTPSink(env, RTPgs);
}