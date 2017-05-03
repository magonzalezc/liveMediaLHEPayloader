// RTP sink for MLHE video
// Implementation
// Comentario

#include "MLHEVideoRTPSink.hh"

MLHEVideoRTPSink
::MLHEVideoRTPSink(UsageEnvironment& env, Groupsock* RTPgs)
  : VideoRTPSink(env, RTPgs, 70, 90000, "MLHE") {
}

MLHEVideoRTPSink::~MLHEVideoRTPSink() {
}

MLHEVideoRTPSink*
MLHEVideoRTPSink::createNew(UsageEnvironment& env, Groupsock* RTPgs) {
  return new MLHEVideoRTPSink(env, RTPgs);
}

void MLHEVideoRTPSink::doSpecialFrameHandling(unsigned fragmentationOffset,
					   unsigned char* frameStart,
					   unsigned numBytesInFrame,
					   struct timeval framePresentationTime,
					   unsigned numRemainingBytes) {
/*	if (fragmentationOffset == 0)  {
  	//u_int8_t lhePayloadDescriptor = fragmentationOffset == 0 ? 0x10 : 0x00;
    // Start = 1 iff this is the first (or only) fragment of the frame
  //setSpecialHeaderBytes(&lhePayloadDescriptor, 1);
	 //std::cout << "Adding fragmentation offset\n" << std::endl;
	}*/

	if (numRemainingBytes == 0) {
		// This packet contains the last (or only) fragment of the frame.
		// Set the RTP 'M' ('marker') bit:
		setMarkerBit();
	}

	setTimestamp(framePresentationTime);
}

Boolean MLHEVideoRTPSink::
frameCanAppearAfterPacketStart(unsigned char const* /*frameStart*/,
			       unsigned /*numBytesInFrame*/) const {
  return False;
}


/*unsigned LHEVideoRTPSink::specialHeaderSize() const {
  return 0;
}*/
