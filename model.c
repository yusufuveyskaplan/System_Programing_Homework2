#include "model.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*1:indicates a mine in field[i][j]*/
int mfield[SIZE][SIZE] = {'\0'};


/*grid[i][j] indicates number of mines 
this should be calculated from mfield*/
int grid[SIZE][SIZE] = {'\0'};

/**
 * @brief 
 * 
 * @param filename 
 */
void load_mfield(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Dosya açılamadı");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (fscanf(file, "%d,", &mfield[i][j]) != 1) {
                printf("Dosya formatı hatalı!\n");
                fclose(file);
                exit(EXIT_FAILURE);
            }
        }
    }
    fclose(file);
    init_grid(); // Grid'i de başlat
}

/**
 * @brief 
 * 
 * @param mine_percentage 
 */
void generate_random_mfield(int mine_percentage) {
    srand(time(NULL)); // Rastgelelik için seed ayarla

    // Önce tüm alanı temizle
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            mfield[i][j] = 0;
        }
    }

    int total_mines = (SIZE * SIZE * mine_percentage) / 100; // Yerleştirilecek mayın sayısı

    int placed_mines = 0;
    while (placed_mines < total_mines) {
        int row = rand() % SIZE;
        int col = rand() % SIZE;

        if (mfield[row][col] == 0) { // Eğer zaten mayın yoksa
            mfield[row][col] = 1;
            placed_mines++;
        }
    }

    init_grid(); // Mayın sayılarını hesapla
}

/**
 * @brief 
 * 
 * @param row 
 * @param col 
 * @return int 
 */
int num_of_surrounding_mines(int row, int col) {
    int count = 0;

    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            int new_row = row + dx;
            int new_col = col + dy;

            // Kenarları kontrol et
            if (new_row >= 0 && new_row < SIZE && new_col >= 0 && new_col < SIZE) {
                if (mfield[new_row][new_col] == 1) { // Eğer mayın varsa
                    count++;
                }
            }
        }
    }

    return count;
}

/**
 * @brief 
 * 
 * @return int 
 */
int init_grid() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (mfield[i][j] == 1) {
                grid[i][j] = -1; // Mayın olan hücreleri işaretle
            } else {
                grid[i][j] = num_of_surrounding_mines(i, j); // Çevredeki mayınları hesapla
            }
        }
    }
    return 0;
}
