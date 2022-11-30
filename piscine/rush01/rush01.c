#include <stdio.h> 
#include <stdlib.h>

void ft_recursive(int idx, int col, int i, int *input, int input_n, int result[9][9]);
int validate_overlap(int idx, int col, int num, int input_n, int result[9][9]);
int upcol_condition(int result[9][9], int* input, int input_n);
int downcol_condition(int result[9][9], int* input, int input_n);
int lrow_condition(int result[9][9], int* input, int input_n);
int rrow_condition(int result[9][9], int* input, int input_n);
void print_result(int result[9][9], int input_n);

int main(int argc, char *argv[])
{
    int input[36];
    int result[9][9];
    int i;

    i = 0;
    if (argc == 1)
        return (0);
    while (*argv[1])
    {
        if (*argv[1] != ' ')
        {
            input[i] = *argv[1] - '0';
            i++;
        }
        argv[1]++;
    }
    ft_recursive(0, 0, 1, input, i / 4, result);

    return 0;
}

void print_result(int result[9][9], int input_n)
{
    int i;
    int j;

    i = 0;
    while (i < input_n)
    {
        j = 0;
        while (j < input_n)
        {
            printf("%d ", result[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}

void ft_recursive(int idx, int col, int num, int *input, int input_n, int result[9][9])
{
    if (idx == input_n)
    {
	printf("here!!!!");
	

        if (upcol_condition(result, input, input_n) && downcol_condition(result, input, input_n) 
            && lrow_condition(result, input, input_n) && rrow_condition(result, input, input_n))
	{
            print_result(result, input_n);
	    return ;
	}
        else
            return;
    }
        
    if (col == input_n)
    {
        ft_recursive(idx + 1, 0, 1, input, input_n, result);

        return;
    }

    if (input[idx] >= 1 && input[idx] <= input_n)
    {
        for (; num <= input_n; ++num)
        {
            result[idx][col] = num;

            if (validate_overlap(idx, col, num, input_n, result)) {
                ft_recursive(idx, col + 1, 1, input, input_n, result);

                return;
            }
        }
    }
    else
        ft_recursive(idx, col + 1, 1, input, input_n, result);
}

int validate_overlap(int idx, int col, int num, int input_n, int result[9][9])
{
    for (int i = 0; i < input_n; ++i)
    {
        if (i != col && num == result[idx][i])
            return (0);
        if (i != idx && num == result[i][col])
            return (0);
    }

    return (1);
}

int upcol_condition(int result[9][9], int* input, int input_n)
{
    int row;
    int col;
    int box_count;
    int input_idx;

    col = 0;
    box_count = 1;
    input_idx = input_n * 0;
    while (col < input_n)
    {
        row = 0;
        while (row < input_n)
        {
            if (result[row][col] < result[row + 1][col])
                box_count++;
            row++;
        }
        col++;
        if (box_count == input[input_idx])
            input_idx++;
        else
            return (0);
    }
    return (1);
}

int downcol_condition(int result[9][9], int* input, int input_n)
{
    int row;
    int col;
    int box_count;
    int input_idx;

    col = 0;
    box_count = 1;
    input_idx = input_n * 1;
    while (col < input_n)
    {
        row = input_n - 1;
        while (row > 0)
        {
            if (result[row - 1][col] > result[row][col])
                box_count++;
            row--;
        }
        col++;
        if (box_count == input[input_idx])
            input_idx++;
        else
            return (0);
    }
    return (1);
}

int lrow_condition(int result[9][9], int* input, int input_n)
{
    int row;
    int col;
    int box_count;
    int input_idx;

    row = 0;
    box_count = 1;
    input_idx = input_n * 2;
    while (row < input_n)
    {
        col = 0;
        while (col + 1 < input_n)
        {
            if (result[row][col] < result[row][col + 1])
                box_count++;
            col++;
        }
        row++;
        if (box_count == input[input_idx])
            input_idx++;
        else
            return (0);
    }
    return (1);
}

int rrow_condition(int result[9][9], int* input, int input_n)
{
    int row;
    int col;
    int box_count;
    int input_idx;

    row = 0;
    box_count = 1;
    input_idx = input_n * 3;
    while (row < input_n)
    {
        col = input_n - 1;
        while (col > 0)
        {
            if (result[row][col - 1] > result[row][col])
                box_count++;
            col--;
        }
        row++;
        if (box_count == input[input_idx])
            input_idx++;
        else
            return (0);
    }
    return (1);
}
