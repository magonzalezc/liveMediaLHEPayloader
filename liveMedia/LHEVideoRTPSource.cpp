// LHE Video RTP Sources
// Implementation

#include "LHEVideoRTPSource.hh"


LHEVideoRTPSource*
LHEVideoRTPSource::createNew(UsageEnvironment& env, Groupsock* RTPgs,
			      unsigned char rtpPayloadFormat,
			      unsigned rtpTimestampFrequency) {
  return new LHEVideoRTPSource(env, RTPgs, rtpPayloadFormat,
				rtpTimestampFrequency);
}

LHEVideoRTPSource::LHEVideoRTPSource(UsageEnvironment& env,
				       Groupsock* RTPgs,
				       unsigned char rtpPayloadFormat,
				       unsigned rtpTimestampFrequency)
  : MultiFramedRTPSource(env, RTPgs,
			 rtpPayloadFormat, rtpTimestampFrequency) {
}

LHEVideoRTPSource::~LHEVideoRTPSource() {
}

char const* LHEVideoRTPSource::MIMEtype() const {
  return "video/LHE";
}

Boolean LHEVideoRTPSource
::processSpecialHeader(BufferedPacket* packet,
		       unsigned& resultSpecialHeaderSize) {
  unsigned char* headerStart = packet->data();
  unsigned packetSize = packet->dataSize();
  
  if (packetSize == 0) return False;
  resultSpecialHeaderSize = 0; // unless we learn otherwise

  //u_int8_t const byte1 = *headerStart;
  //Boolean const Start = (byte1&0x10) != 0;

  //fCurrentPacketBeginsFrame = Start == 0;

  fCurrentPacketCompletesFrame = packet->rtpMarkerBit();

  return True;
}


