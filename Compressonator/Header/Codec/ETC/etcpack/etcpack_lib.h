// etcpack_lib.h
#ifndef H_TEX_ETCPACK_LIB_H
#define H_TEX_ETCPACK_LIB_H

#define ETCPACK_VERSION_S "2.74"

// data types
typedef unsigned char uint8;

// ETC1
void compressBlockDiffFlipFastPerceptual(uint8 *img, uint8 *imgdec, int width, int height, int startx, int starty, unsigned int &compressed1, unsigned int &compressed2);
void decompressBlockDiffFlip(unsigned int block_part1, unsigned int block_part2, uint8 *img, int width, int height, int startx, int starty);

bool readCompressParams(void);

// ETC2
#endif