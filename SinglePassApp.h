//
// Created by student on 04.08.2022.
//

#ifndef SINGLEPASSSYSTEM_SINGLEPASSAPP_H
#define SINGLEPASSSYSTEM_SINGLEPASSAPP_H

#include "main_settings.h"

//Виджеты окна разовых пропусков
GtkWidget *WindowMain;
GtkWidget *OrderSinglePassButton;
GtkWidget *ShowPersonalPassButton;
GtkWidget *HistoryPassesButton;
GtkWidget *ApprovalPassesButton;
GtkWidget *AdmitButton;
GtkWidget *LetButton;
GtkWidget *FuturePassButton;
GtkWidget *MessengerButton;
GtkWidget *ExitButton;
GtkWidget *AcceptButton;
GtkWidget *CancelButton;
GtkWidget *DeclineButton;
GtkWidget *SurnameSearchEntry;
GtkWidget *NameSearchEntry;
GtkWidget *FathernameSearchEntry;
GtkWidget *DocumentSearchEntry;
GtkWidget *CarNumberEntry;
GtkWidget *StatusLabel;
GObject *TypeDocumentColumn;
GObject *NumDocumentColumn;
GObject *NumCarColumn;
GObject *NameOrdererColumn;
GObject *StatusApologyColumn;
GObject *OrderOrganizationColumn;
GObject *EnteringOrganizationColumn;
GObject *DateOrderColumn;
GObject *TimeOrderColumn;
GObject *CommentaryColumn;
GObject *EnterTimeColumn;
GObject *ExitTimeColumn;
GtkWidget *HintLabel;

static void create_window_SinglePassApp();

int SinglePassApp(int argc, char *argv[]);

G_MODULE_EXPORT void window_single_pass_destroy();

int SinglePassApp(int argc, char *argv[]){
    gtk_init(&argc,&argv);
    create_window_SinglePassApp();
    gtk_widget_show(WindowMain);
    gtk_main();
}

static void create_window_SinglePassApp(){
    GtkBuilder *builder;
    GError* error = nullptr;

    builder = gtk_builder_new();
    if(!gtk_builder_add_from_file(builder, path_glade, &error)){
        g_critical("Не могу загрузить файл: %s", error->message);
        g_error_free(error);
    }

    gtk_builder_connect_signals(builder, nullptr);
    if(!(WindowMain = GTK_WIDGET(gtk_builder_get_object(builder, "WindowMain"))))
        g_critical("Ошибка при получении виджета окна\n");
    if(!(OrderSinglePassButton = GTK_WIDGET(gtk_builder_get_object(builder, "OrderSinglePassButton"))))
        g_critical("Ошибка при получении виджета окна\n");
    if(!(ShowPersonalPassButton = GTK_WIDGET(gtk_builder_get_object(builder, "ShowPersonalPassButton"))))
        g_critical("Ошибка при получении виджета окна\n");
    if(!(HistoryPassesButton = GTK_WIDGET(gtk_builder_get_object(builder, "HistoryPassesButton"))))
        g_critical("Ошибка при получении виджета окна\n");
    if(!(ApprovalPassesButton = GTK_WIDGET(gtk_builder_get_object(builder, "ApprovalPassesButton"))))
        g_critical("Ошибка при получении виджета окна\n");
    if(!(AdmitButton = GTK_WIDGET(gtk_builder_get_object(builder, "AdmitButton"))))
        g_critical("Ошибка при получении виджета окна\n");
    if(!(LetButton = GTK_WIDGET(gtk_builder_get_object(builder, "LetButton"))))
        g_critical("Ошибка при получении виджета окна\n");
    if(!(FuturePassButton = GTK_WIDGET(gtk_builder_get_object(builder, "FuturePassButton"))))
        g_critical("Ошибка при получении виджета окна\n");
    if(!(MessengerButton = GTK_WIDGET(gtk_builder_get_object(builder, "MessengerButton"))))
        g_critical("Ошибка при получении виджета окна\n");
    if(!(ExitButton = GTK_WIDGET(gtk_builder_get_object(builder, "ExitButton"))))
        g_critical("Ошибка при получении виджета окна\n");
    if(!(CancelButton = GTK_WIDGET(gtk_builder_get_object(builder, "CancelButton"))))
        g_critical("Ошибка при получении виджета окна\n");
    if(!(AcceptButton = GTK_WIDGET(gtk_builder_get_object(builder, "AcceptButton"))))
        g_critical("Ошибка при получении виджета окна\n");
    if(!(DeclineButton = GTK_WIDGET(gtk_builder_get_object(builder, "DeclineButton"))))
        g_critical("Ошибка при получении виджета окна\n");
    if(!(SurnameSearchEntry = GTK_WIDGET(gtk_builder_get_object(builder, "SurnameSearchEntry"))))
        g_critical("Ошибка при получении виджета окна\n");
    if(!(NameSearchEntry = GTK_WIDGET(gtk_builder_get_object(builder, "NameSearchEntry"))))
        g_critical("Ошибка при получении виджета окна\n");
    if(!(FathernameSearchEntry = GTK_WIDGET(gtk_builder_get_object(builder, "FathernameSearchEntry"))))
        g_critical("Ошибка при получении виджета окна\n");
    if(!(DocumentSearchEntry = GTK_WIDGET(gtk_builder_get_object(builder, "DocumentSearchEntry"))))
        g_critical("Ошибка при получении виджета окна\n");
    if(!(CarNumberEntry = GTK_WIDGET(gtk_builder_get_object(builder, "CarNumberEntry"))))
        g_critical("Ошибка при получении виджета окна\n");
    if(!(HintLabel = GTK_WIDGET(gtk_builder_get_object(builder, "HintLabel"))))
        g_critical("Ошибка при получении виджета окна\n");
    if(!(StatusLabel = GTK_WIDGET(gtk_builder_get_object(builder, "StatusLabel"))))
        g_critical("Ошибка при получении виджета окна\n");
    if(!(TypeDocumentColumn = gtk_builder_get_object(builder, "TypeDocumentColumn")))
        g_critical("Ошибка при получении виджета окна\n");
    if(!(NumDocumentColumn = gtk_builder_get_object(builder, "NumDocumentColumn")))
        g_critical("Ошибка при получении виджета окна\n");
    if(!(NameOrdererColumn = gtk_builder_get_object(builder, "NameOrdererColumn")))
        g_critical("Ошибка при получении виджета окна\n");
    if(!(OrderOrganizationColumn = gtk_builder_get_object(builder, "OrderOrganizationColumn")))
        g_critical("Ошибка при получении виджета окна\n");
    if(!(EnteringOrganizationColumn = gtk_builder_get_object(builder, "EnteringOrganizationColumn")))
        g_critical("Ошибка при получении виджета окна\n");
    if(!(DateOrderColumn = gtk_builder_get_object(builder, "DateOrderColumn")))
        g_critical("Ошибка при получении виджета окна\n");
    if(!(TimeOrderColumn = gtk_builder_get_object(builder, "TimeOrderColumn")))
        g_critical("Ошибка при получении виджета окна\n");
    if(!(CommentaryColumn = gtk_builder_get_object(builder, "CommentaryColumn")))
        g_critical("Ошибка при получении виджета окна\n");
    if(!(EnterTimeColumn = gtk_builder_get_object(builder, "EnterTimeColumn")))
        g_critical("Ошибка при получении виджета окна\n");
    if(!(ExitTimeColumn = gtk_builder_get_object(builder, "ExitTimeColumn")))
        g_critical("Ошибка при получении виджета окна\n");
    g_object_unref(builder);
}

#endif //SINGLEPASSSYSTEM_SINGLEPASSAPP_H
