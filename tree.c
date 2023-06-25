// B-CPE-100 : Firtree //
#include <unistd.h>
#include <stdio.h>

int	get_columns(int size)
{
    int columns = 1;
    int max_lines;

    for (int i = 1; i < size + 1; i++) {
        max_lines = i + 3;
        for (int j = 0; j < max_lines; j++)
            columns += 2;
        columns = (i % 2 == 0) ? columns - i : columns - (i+1); 
    }
    return (columns - 4);
}

void put_trunk(int size, int columns)
{
    int spaces = (columns - size) / 2;

    for (int i = spaces; i > 0; i--)
        write(1, " ", 1);
    for (int i = 0; i < size; i++)
        write(1, "|", 1);
    for (int i = spaces; i > 0; i--)
        write(1, " ", 1);
    write(1, "\n", 1);
}

void draw(int line, int max_size)
{
    int spaces = (max_size - line) / 2;

    for (int i = spaces; i > 0; i--)
        write(1, " ", 1);
    for (int i = 0; i < line; i++)
        write(1, "*", 1);
    for (int i = spaces; i > 0; i--)
        write(1, " ", 1);
    write(1, "\n", 1);
}

void put_tree(int size, int max_size)
{
    int line = 1;
    for (int i = 1; i < size + 1; i++) {
        for (int j = 0; j < i + 3 ; j++) {
            draw(line, max_size);
            line += 2;
        }
        line -= 2;
        line = line - ((i + 1) / 2) * 2;
    }
}

void tree(int size)
{
    int trk = (size % 2 == 1) ? size : size + 1;
    int columns = (size > 0) ? get_columns(size) : 0;

    if(size <= 0) {
        if (size < 0)
            write(2, "Invalid argument\n", 18);
        return;
    }
    put_tree(size, columns);
    for (int i = 0; i < size; i++)
        put_trunk(trk, columns);
}