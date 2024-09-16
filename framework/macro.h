#pragma once


#define VARIADIC_LENGTH(...) (sizeof((int[]) {__VA_ARGS__}) / sizeof(int))
