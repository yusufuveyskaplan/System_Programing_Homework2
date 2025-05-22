
#include <gtk/gtk.h>
#include "model.h"
#include "view.h"
#include <stdio.h>

/**
 * @brief 
 * 
 * @param app 
 * @param user_data 
 */
static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window = create_main_window(app);
    gtk_window_present(GTK_WINDOW(window));
}

/**
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char **argv) {
    if (argc > 1) {
        load_mfield(argv[1]); // CSV dosyasını yükle
    } else {
        generate_random_mfield(20); // %20 mayın ile rastgele oluştur
    }

    GtkApplication *app = gtk_application_new("org.example.minefield",
                            G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}
