/* This serves as a file with the program parameters,
 * like an input file for a computational chemistry calculation/simulation
 * Constraints on these params are enfored by static_assert calls in main.cpp
 * Parameters below WARP_SIZE should not be changed
 */

#ifndef _CONFIG_H_
#define _CONFIG_H_

// includes, system
#include <stddef.h>

//----------------------------------------------------------------------------//
/*@param TARGET_LENGTH  Length of target string, must be in {4,8}
 *@param REDUCTION_VEC_SIZE  Number of targets to be loaded with vectorized
 *                           memory access, must be in {4,8,16}
 *@param MATCH_VEC_SIZE  Number of contiguous matchees to be evaluated with
 *                       vectorized memory access, must be in {2,4}
 *@param ALPHABET  Which alphabet to use, must be in {0,1,2}
 *                 [0] lower case only
 *                 [1] lower and upper case
 *                 [2] all letters and symbols (most ASCII)
 *@param RUN_TESTS  If 1, verify:
 *                  -Uniformity of rng distribution
 *                  -gpu results match cpu results
 *                  -gpu is faster than cpu
 *@param BLOCK_SIZE_X/Y  Each must be a power of 2, and their product is the 
 *                       number of threads per block, N_THREADS
 *                       Also, N_THREADS must be in {16,32,64,128,256,512}
 *@param SEED  Seed for curand: results are deterministic for a fixed seed
 *             Setting this to zero will initialize curand with clock()
 *@param N_NUMS  How many numbers generated by each GPU per iteration
 *               Make sure to not exceed max GPU memory
 *               Must be divisible by: N_THREADS, 
 *               (N_THREADS*MATCH_VEC_SIZE), and TARGET_LENGTH
 *@param WARP_SIZE  Hardware has fixed this at 32 for years
 *                  Only used in reduction_kernels.cuh for unrolling,
 *                  so changing its value according to hardware is easy
 */

#define TARGET_LENGTH 4
#define REDUCTION_VEC_SIZE 8
#define MATCH_VEC_SIZE 4
#define ALPHABET 0
#define RUN_TESTS 0
constexpr unsigned int BLOCK_SIZE_X = 8;
constexpr unsigned int BLOCK_SIZE_Y = 8;
constexpr unsigned int SEED = 0;
constexpr size_t N_NUMS = (1 << 18);
constexpr unsigned int WARP_SIZE = 32;

//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//


constexpr unsigned int N_THREADS = BLOCK_SIZE_X*BLOCK_SIZE_Y;
constexpr char outDir[16] = "./output/";
constexpr char inpDir[16] = "./textFiles/";


#endif  // #ifndef _CONFIG_H_
