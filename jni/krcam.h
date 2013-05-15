//libvpx
#define fourcc    0x30385056

#define IVF_FILE_HDR_SZ  (32)
#define IVF_FRAME_HDR_SZ (12)

//libvpx ugly globals
//FILE                *infile, *outfile;
kr_mkv_t			*kr_stream;
int					video_track;
vpx_codec_enc_cfg_t  cfg;
int                  frame_cnt = 0;
vpx_image_t          raw;
vpx_codec_ctx_t      codec;

static void deinterleave(const uint8_t *srcAB, uint8_t *dstA, uint8_t *dstB, size_t srcABLength);
static void deinterleave_no_neon(const uint8_t *srcAB, uint8_t *dstA, uint8_t *dstB, size_t srcABLength);
static void deinterleave_neon(const uint8_t *srcAB, uint8_t *dstA, uint8_t *dstB, size_t srcABLength);