/*
 * Copyright (c) 2015-2017, ARM Limited and Contributors. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * Neither the name of ARM nor the names of its contributors may be used
 * to endorse or promote products derived from this software without specific
 * prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <assert.h>

/* mbed TLS headers */
#include <mbedtls/memory_buffer_alloc.h>

/*
 * mbed TLS heap
 */
#if (TBBR_KEY_ALG_ID == TBBR_ECDSA)
#define MBEDTLS_HEAP_SIZE		(14*1024)
#elif (TBBR_KEY_ALG_ID == TBBR_RSA)
#define MBEDTLS_HEAP_SIZE		(8*1024)
#endif
static unsigned char heap[MBEDTLS_HEAP_SIZE];

/*
 * mbed TLS initialization function
 */
void mbedtls_init(void)
{
	static int ready;

	if (!ready) {
		/* Initialize the mbed TLS heap */
		mbedtls_memory_buffer_alloc_init(heap, MBEDTLS_HEAP_SIZE);
		ready = 1;
	}
}