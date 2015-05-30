#ifndef RX_H
#define RX_H

#include <netdb.h>
#include <string.h>
#include <alsa/asoundlib.h>
#include <opus/opus.h>
#include <ortp/ortp.h>
#include <sys/socket.h>
#include <sys/types.h>

#include "defaults.h"
#include "device.h"
#include "notice.h"
#include "sched.h"

static void timestamp_jump(RtpSession *session, ...);
static RtpSession* create_rtp_recv(const char *addr_desc, const int port,
		unsigned int jitter);
static int play_one_frame(void *packet,
		size_t len,
		OpusDecoder *decoder,
		snd_pcm_t *snd,
		const unsigned int channels);
static int run_rx(RtpSession *session,
		OpusDecoder *decoder,
		snd_pcm_t *snd,
		const unsigned int channels,
		const unsigned int rate);

#endif
