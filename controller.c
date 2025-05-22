/**
 * @file controller.c
 * @author your name (you@domain.com)
 * @brief
 * - Handles the button click event.
 * - When a button is clicked,
 *  - it gets the position,
 *  - prompts for input, updates the model,
 *  - and then updates the view.
 * @version 0.1
 * @date 2025-02-14
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "controller.h"
#include "model.h"
#include "view.h"

#include <stdlib.h>

/**
 * @brief 
 * 
 * @param button 
 * @param data 
 */
void on_cell_clicked(GtkButton *button, gpointer data) {
    int *pos = (int *)data;
    int row = pos[0], col = pos[1];

    if (mfield[row][col] == 1) {  // Eğer mayınsa
        gameover = 1;
        gtk_widget_set_sensitive(grid_gui, FALSE); // Tüm butonları devre dışı bırak
    } else {  
        update_button_label(button, row, col); // Butonun etiketini güncelle

        if (grid[row][col] == 0) { // Eğer çevresinde hiç mayın yoksa
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    int new_row = row + dx;
                    int new_col = col + dy;
                    if (new_row >= 0 && new_row < SIZE && new_col >= 0 && new_col < SIZE) {
                        // Eğer buton zaten açıksa tekrar açma
                        if (grid[new_row][new_col] != -1) {
                            on_cell_clicked(button, (gpointer)(int[]){new_row, new_col});
                        }
                    }
                }
            }
        }
    }
}
