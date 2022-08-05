//
// Created by vadik on 27.07.22.
//

#ifndef INC_345MF_POSTGRES_H
#define INC_345MF_POSTGRES_H

#include <libpq-fe.h>
#include "fstream"
#include <string>
#include "sstream"
#include <unistd.h>
#include <gtk/gtk.h>
#include <vector>

#define CHECKPOINT_AFOOT 1
#define CHECKPOINT_CAR 2
#define ORDER_BOSS 3
#define ORDER_TENANT 4
#define MATCHING_BOSS 5
#define ADMIN 6
#define CLOSE_LOGIN_APP 0

int type_user = 0;

std::string login;

int id_user;

std::ofstream journal("./log.txt",std::ios::app);

void journal_init(){
    if (!journal) {
        journal = std::ofstream("./log.txt");
    }
}

//Основное соединение приложения
PGconn* conn;

char* const path_glade = "./Application.glade";

#endif //INC_345MF_POSTGRES_H
