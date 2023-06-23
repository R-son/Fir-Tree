// B-CPE-100 : Firtree //
#include <unistd.h>
#include <stdio.h>

int check_size(int size)
{
    if (size < 0)
        write(2, "Invalid argument\n", 18);
    return (size < 0) ? (-1) : 0;
}

int	get_columns(int size)
{
    int columns = 1;
    int max_lines;

    for (int i = 0; i < size; i++) {
        max_lines = i + 3;
        for (int j = 0; j < max_lines; j++)
            columns += 2;
        columns = (i % 2 == 0) ? columns - i : columns - (i+1); 
    }
    return columns;
}

// void put_tree(int size, int columns)
// {
//     int spaces;

//     for (int i = 0; i < size; i++) {
//         spaces 
//     }
// }

void put_trunk(int size, int columns)
{
    int spaces;

    printf("Max size: %i", columns);
    spaces = (columns - size) / 2;
    for (int i = spaces; i > 0; i--)
        write(1, " ", 1);
    for (int i = 0; i < size; i++)
        write(1, "|", 1);
    for (int i = spaces; i > 0; i--)
        write(1, " ", 1);
    write(1, "\n", 1);
}

void tree(int size) //trunk size == size
{
    int trunk_size;
    int max_columns;
    int max_blk_size = size + 3;

    if(size == 0 || check_size(size) == -1)
        return;
    trunk_size = (size % 2 == 1) ? size : size + 1;
    max_columns = get_columns(size);
    // put_tree(size, max_columns);
    for (int i = 0; i < size; i++)
        put_trunk(trunk_size, max_columns);
}

int main()
{
    int a = 1;
    int b = 2;
    int c = 5;

    tree(a);
    tree(b);
    tree(c);
    return 0;
}