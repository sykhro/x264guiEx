﻿//  -----------------------------------------------------------------------------------------
//    拡張 x264 出力(GUI) Ex  v1.xx/2.xx by rigaya
//  -----------------------------------------------------------------------------------------
//   ソースコードについて
//   ・無保証です。
//   ・本ソースコードを使用したことによるいかなる損害・トラブルについてrigayaは責任を負いません。
//   以上に了解して頂ける場合、本ソースコードの使用、複製、改変、再頒布を行って頂いて構いません。
//  -----------------------------------------------------------------------------------------

#ifndef _CONVERT_H_
#define _CONVERT_H_

#include <Windows.h>

typedef	struct {
	short	y;					//	画素(輝度    )データ (     0 ～ 4096 )
	short	cb;					//	画素(色差(青))データ ( -2048 ～ 2048 )
	short	cr;					//	画素(色差(赤))データ ( -2048 ～ 2048 )
								//	画素データは範囲外に出ていることがあります
								//	また範囲内に収めなくてもかまいません
} PIXEL_YC;

typedef struct {
	int   count;       //planarの枚数。packedなら1
	BYTE *data[3];     //planarの先頭へのポインタ
	int   size[3];     //planarのサイズ
	int   total_size;  //全planarのサイズの総和
} CONVERT_CF_DATA;


//音声16bit->8bit変換
typedef void (*func_audio_16to8) (BYTE *dst, short *src, int n);

void convert_audio_16to8(BYTE *dst, short *src, int n);
void convert_audio_16to8_sse2(BYTE *dst, short *src, int n);

void split_audio_16to8x2(BYTE *dst, short *src, int n);
void split_audio_16to8x2_sse2(BYTE *dst, short *src, int n);

#if (_MSC_VER >= 1700)
void convert_audio_16to8_avx2(BYTE *dst, short *src, int n);
void split_audio_16to8x2_avx2(BYTE *dst, short *src, int n);
#endif

//動画変換
typedef void (*func_convert_frame) (void *frame, CONVERT_CF_DATA *pixel_data, const int width, const int height);

void copy_yuy2(void *frame, CONVERT_CF_DATA *pixel_data, const int width, const int height);
void copy_yuy2_sse2(void *frame, CONVERT_CF_DATA *pixel_data, const int width, const int height);

void copy_rgb(void *frame, CONVERT_CF_DATA *pixel_data, const int width, const int height);
void copy_rgb_sse2(void *frame, CONVERT_CF_DATA *pixel_data, const int width, const int height);

void convert_yuy2_to_nv12(void *frame, CONVERT_CF_DATA *pixel_data, const int width, const int height);
void convert_yuy2_to_nv12_i(void *frame, CONVERT_CF_DATA *pixel_data, const int width, const int height);

void convert_yuy2_to_nv12_sse2_mod16(void *frame, CONVERT_CF_DATA *pixel_data, const int width, const int height);
void convert_yuy2_to_nv12_sse2(void *frame, CONVERT_CF_DATA *pixel_data, const int width, const int height);
void convert_yuy2_to_nv12_i_sse2_mod16(void *frame, CONVERT_CF_DATA *pixel_data, const int width, const int height);
void convert_yuy2_to_nv12_i_sse2(void *frame, CONVERT_CF_DATA *pixel_data, const int width, const int height);

void convert_yuy2_to_nv12_i_ssse3_mod16(void *frame, CONVERT_CF_DATA *pixel_data, const int width, const int height);
void convert_yuy2_to_nv12_i_ssse3(void *frame, CONVERT_CF_DATA *pixel_data, const int width, const int height);

#if (_MSC_VER >= 1600) //AVX のサポートはVC++2010(VS10)から
void convert_yuy2_to_nv12_avx_mod16(void *frame, CONVERT_CF_DATA *pixel_data, const int width, const int height);
void convert_yuy2_to_nv12_avx(void *frame, CONVERT_CF_DATA *pixel_data, const int width, const int height);
void convert_yuy2_to_nv12_i_avx_mod16(void *frame, CONVERT_CF_DATA *pixel_data, const int width, const int height);
void convert_yuy2_to_nv12_i_avx(void *frame, CONVERT_CF_DATA *pixel_data, const int width, const int height);
#endif //_MSC_VER >= 1600

#if (_MSC_VER >= 1700)
void convert_yuy2_to_nv12_avx2_mod32(void *frame, CONVERT_CF_DATA *pixel_data, const int width, const int height);
void convert_yuy2_to_nv12_avx2(void *frame, CONVERT_CF_DATA *pixel_data, const int width, const int height);
void convert_yuy2_to_nv12_i_avx2_mod32(void *frame, CONVERT_CF_DATA *pixel_data, const int width, const int height);
void convert_yuy2_to_nv12_i_avx2(void *frame, CONVERT_CF_DATA *pixel_data, const int width, const int height);
#endif //_MSC_VER >= 1700

void convert_yc48_to_nv12_16bit(void *pixel, CONVERT_CF_DATA *pixel_data, const int width, const int height);
void convert_yc48_to_nv12_i_16bit(void *pixel, CONVERT_CF_DATA *pixel_data, const int width, const int height);

#if (_MSC_VER >= 1600)
void convert_yc48_to_nv12_16bit_avx(void *pixel, CONVERT_CF_DATA *pixel_data, const int width, const int height);
void convert_yc48_to_nv12_i_16bit_avx(void *pixel, CONVERT_CF_DATA *pixel_data, const int width, const int height);
void convert_yc48_to_nv12_16bit_avx_mod8(void *pixel, CONVERT_CF_DATA *pixel_data, const int width, const int height);
void convert_yc48_to_nv12_i_16bit_avx_mod8(void *pixel, CONVERT_CF_DATA *pixel_data, const int width, const int height);
#endif //_MSC_VER >= 1600

#if (_MSC_VER >= 1700)
void convert_yc48_to_nv12_16bit_avx2(void *pixel, CONVERT_CF_DATA *pixel_data, const int width, const int height);
void convert_yc48_to_nv12_i_16bit_avx2(void *pixel, CONVERT_CF_DATA *pixel_data, const int width, const int height);
void convert_yc48_to_nv12_16bit_avx2_mod16(void *pixel, CONVERT_CF_DATA *pixel_data, const int width, const int height);
void convert_yc48_to_nv12_i_16bit_avx2_mod16(void *pixel, CONVERT_CF_DATA *pixel_data, const int width, const int height);
#endif //_MSC_VER >= 1700

void convert_yc48_to_nv12_16bit_sse4_1(void *pixel, CONVERT_CF_DATA *pixel_data, const int width, const int height);
void convert_yc48_to_nv12_i_16bit_sse4_1(void *pixel, CONVERT_CF_DATA *pixel_data, const int width, const int height);
void convert_yc48_to_nv12_16bit_sse4_1_mod8(void *pixel, CONVERT_CF_DATA *pixel_data, const int width, const int height);
void convert_yc48_to_nv12_i_16bit_sse4_1_mod8(void *pixel, CONVERT_CF_DATA *pixel_data, const int width, const int height);

void convert_yc48_to_nv12_16bit_ssse3(void *pixel, CONVERT_CF_DATA *pixel_data, const int width, const int height);
void convert_yc48_to_nv12_i_16bit_ssse3(void *pixel, CONVERT_CF_DATA *pixel_data, const int width, const int height);
void convert_yc48_to_nv12_16bit_ssse3_mod8(void *pixel, CONVERT_CF_DATA *pixel_data, const int width, const int height);
void convert_yc48_to_nv12_i_16bit_ssse3_mod8(void *pixel, CONVERT_CF_DATA *pixel_data, const int width, const int height);

void convert_yc48_to_nv12_16bit_sse2(void *pixel, CONVERT_CF_DATA *pixel_data, const int width, const int height);
void convert_yc48_to_nv12_i_16bit_sse2(void *pixel, CONVERT_CF_DATA *pixel_data, const int width, const int height);
void convert_yc48_to_nv12_16bit_sse2_mod8(void *pixel, CONVERT_CF_DATA *pixel_data, const int width, const int height);
void convert_yc48_to_nv12_i_16bit_sse2_mod8(void *pixel, CONVERT_CF_DATA *pixel_data, const int width, const int height);

void convert_yuy2_to_nv16(void *pixel, CONVERT_CF_DATA *pixel_data, const int width, const int height);
void convert_yuy2_to_nv16_sse2(void *pixel, CONVERT_CF_DATA *pixel_data, const int width, const int height);
#if (_MSC_VER >= 1600)
void convert_yuy2_to_nv16_avx(void *pixel, CONVERT_CF_DATA *pixel_data, const int width, const int height);
#endif
#if (_MSC_VER >= 1700)
void convert_yuy2_to_nv16_avx2(void *pixel, CONVERT_CF_DATA *pixel_data, const int width, const int height);
#endif

void convert_yc48_to_nv16_16bit(void *pixel, CONVERT_CF_DATA *pixel_data, const int width, const int height);

void convert_yc48_to_nv16_16bit_sse2(void *pixel, CONVERT_CF_DATA *pixel_data, const int width, const int height);
void convert_yc48_to_nv16_16bit_ssse3(void *pixel, CONVERT_CF_DATA *pixel_data, const int width, const int height);
void convert_yc48_to_nv16_16bit_sse4_1(void *pixel, CONVERT_CF_DATA *pixel_data, const int width, const int height);
#if (_MSC_VER >= 1600)
void convert_yc48_to_nv16_16bit_avx(void *pixel, CONVERT_CF_DATA *pixel_data, const int width, const int height);
#endif
#if (_MSC_VER >= 1700)
void convert_yc48_to_nv16_16bit_avx2(void *pixel, CONVERT_CF_DATA *pixel_data, const int width, const int height);
#endif

void convert_yc48_to_yuv444(void *pixel, CONVERT_CF_DATA *pixel_data, const int width, const int height);
void convert_yc48_to_yuv444_16bit(void *pixel, CONVERT_CF_DATA *pixel_data, const int width, const int height);

void convert_yc48_to_yuv444_sse2(void *pixel, CONVERT_CF_DATA *pixel_data, const int width, const int height);

void convert_yc48_to_yuv444_16bit_sse2(void *pixel, CONVERT_CF_DATA *pixel_data, const int width, const int height);
void convert_yc48_to_yuv444_16bit_sse4_1(void *pixel, CONVERT_CF_DATA *pixel_data, const int width, const int height);
#if (_MSC_VER >= 1600)
void convert_yc48_to_yuv444_16bit_avx(void *pixel, CONVERT_CF_DATA *pixel_data, const int width, const int height);
#endif
#if (_MSC_VER >= 1700)
void convert_yc48_to_yuv444_16bit_avx2(void *pixel, CONVERT_CF_DATA *pixel_data, const int width, const int height);
#endif

#endif //_CONVERT_H_
