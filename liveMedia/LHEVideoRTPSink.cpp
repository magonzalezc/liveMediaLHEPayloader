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

void LHEVideoRTPSink::doSpecialFrameHandling(unsigned fragmentationOffset,
					   unsigned char* frameStart,
					   unsigned numBytesInFrame,
					   struct timeval framePresentationTime,
					   unsigned numRemainingBytes) {
	if (numRemainingBytes == 0) {
		// This packet contains the last (or only) fragment of the frame.
		// Set the RTP 'M' ('marker') bit:
		setMarkerBit();
	}
	
	setTimestamp(framePresentationTime);
}

Boolean SimpleRTPSink::
frameCanAppearAfterPacketStart(unsigned char const* /*frameStart*/,
			       unsigned /*numBytesInFrame*/) const {
  return False;
}