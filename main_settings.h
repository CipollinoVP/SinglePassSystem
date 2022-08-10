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

int id_worker;

int id_user;

std::ofstream journal("./log.txt",std::ios::app);

void journal_init(){
    if (!journal) {
        journal = std::ofstream("./log.txt");
    }
}

//Основное соединение приложения
PGconn* conn;

struct s_single_pass{
    int id = 0;
    std::string surname;
    std::string name;
    std::string fathername;
    bool status_factory = false;
    int id_director = 0;
    std::string type_document;
    std::string number_document;
    bool status_pass = false;
    std::string organization;
    std::string date_query;
    std::string time_query;
    std::string date_pass;
    std::string time_pass;
    std::string enter_time;
    std::string exit_time;
    bool pass_using = false;
    bool driver = false;
    std::string num_auto;
    std::string organization_custom;
    int status_appology = -1;
    std::string commentary;
    bool no_single = false;
    std::string mark_auto;
    std::string cargo;
    std::string finish_time;
    std::string commentary_decline;
};

char* const path_glade = "./Application.glade";

#endif //INC_345MF_POSTGRES_H
