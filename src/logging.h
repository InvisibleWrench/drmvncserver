#pragma once

#include <stdio.h> // Include necessary header for fprintf

// Define error_print macro
#define error_print(...) \
    do \
    { \
        fprintf(stderr, __VA_ARGS__); \
    } while (0)

// Define info_print macro
#define info_print(...) \
    do \
    { \
        fprintf(stderr, __VA_ARGS__); \
    } while (0)

// Declare extern variable 'verbose'
extern int verbose;

// Define debug_print macro
#define debug_print(...) \
    do \
    { \
        if (verbose) \
            fprintf(stderr, __VA_ARGS__); \
    } while (0)
