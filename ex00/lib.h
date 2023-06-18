#include "includes.h"

size_t ft_strlen(char *str);

void ft_putstr(char *str);

int *permute(int *prev, int *next, size_t size);

int ft_power(int b, unsigned int e);

unsigned int factorial(unsigned int n);

int *rev_int_arr(int *arr, size_t size);

unsigned int choose(unsigned int n, unsigned int k);

void ft_putchar(char c);

void rev_tab(int *tab, int size);

int count_view(int *ch);

void print_tab(int *arr, size_t size);

void count_row(int arr[4][4]);

void    transp_matrix(int arr[4][4]);

int **transpose_arr(const int arr[4][4], int transp_arr[4][4]);

bool check_string(char* str, unsigned int n);

bool check_num(int *arr, int n, size_t size);

void print_matrix(int **arr, size_t rows, size_t cols);

int	ft_intcmp(int *s1, int *s2);

void ft_puterr(char* error_detail);

char*	ft_findspc(char* str);

int	ft_countspc(char* str);