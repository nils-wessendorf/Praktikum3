/*
 * makro.h
 *
 *  Created on: 07.11.2023
 *      Author: tb171606
 */

#include <stdarg.h>
#include <assert.h>

#ifndef MAKRO_H_
#define MAKRO_H_

// Klassen
#define BEG_DEFINE_CLASS(T) \
typedef struct T##_Instance_struct *T; \
typedef struct T##_Class_struct { \

#define END_DEFINE_CLASS(T) \
}T##Class;

#define BEG_DEFINE_INSTANCE(T) \
typedef struct T##_Instance_struct  { \
	T##Class *class;

#define END_DEFINE_INSTANCE(T) \
} T##Instance; \
extern T new##T(int* args);


#define DEFINE_BASE_TYPE(T) \
	BEG_DEFINE_CLASS(T) \
		METHODS_##T() \
	END_DEFINE_CLASS(T) \
	BEG_DEFINE_INSTANCE(T) \
		ATTRIBUTE_##T() \
	END_DEFINE_INSTANCE(T)

#define DEFINE_EXTENDED_TYPE(T, E) \
	BEG_DEFINE_CLASS(T) EXTENDS(E) \
		METHODS_##T() \
	END_DEFINE_CLASS(T) \
	BEG_DEFINE_INSTANCE(T) INSTANCE_OF(E) \
		ATTRIBUTE_##T() \
	END_DEFINE_INSTANCE(T)

// Vererbung
#define EXTENDS(T) \
	METHODS_##T()
#define INSTANCE_OF(T) \
	ATTRIBUTE_##T()


// Debug
#define DEBUG 1

#ifdef DEBUG
#define debug(cond, msg) \
	if (!(cond)){ \
		printf("%s\n", msg); \
		assert(cond); \
	}
#else
#define debug(cond, msg)
#endif

#endif
