#ifndef MODEL_H
#define MODEL_H

#define SIZE 9

extern int grid[SIZE][SIZE];
extern int solution[SIZE][SIZE];

void load_mfield(const char *filename);
void generate_random_mfield();
int init_grid();
#endif