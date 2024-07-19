/*
 * platform_type.h
 *
 *  Created on: Dec 9, 2023
 *      Author: Abdelrhaman Maher
 */

/*
 *
 *  Type define based on AUTOSAR specifies.
 *
 */

#ifndef PLATFORM_TYPE_H_
#define PLATFORM_TYPE_H_


//tm4c123 (tiva c) fam specs.
#define CPU_TYPE 		  CPU_TYPE_32
#define CPU_BIT_ORDER	  LSB_FIRST
#define CPU_BYTE_FIRST    LOW_BYTE_FIRST


typedef enum {False,True}boolean;

typedef unsigned char 				uint8_t;
typedef signed char   				sint8_t;

typedef unsigned short 				uint16_t;
typedef signed short   				sint16_t;

typedef unsigned int 				uint32_t;
typedef signed int  			    sint32_t;

typedef unsigned long long 			uint64_t;
typedef signed long long   			sint64_t;

typedef float  						float32_t;
typedef double  					float64_t;


typedef unsigned char 				uint8_least_t;
typedef signed char   				sint8_least_t;

typedef unsigned short 				uint16_least_t;
typedef signed short   				sint16_least_t;

typedef unsigned int 				uint32_least_t;
typedef signed int   				sint32_least_t;



typedef volatile unsigned char 		vuint8_t;
typedef volatile signed char   		vsint8_t;

typedef volatile unsigned short 	vuint16_t;
typedef volatile signed short   	vsint16_t;

typedef volatile unsigned int 		vuint32_t;
typedef volatile signed int   		vsint32_t;

typedef volatile unsigned long long vuint64_t;
typedef volatile signed long long   vsint64_t;

#endif /* PLATFORM_TYPE_H_ */
