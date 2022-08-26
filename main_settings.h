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


//Режимы работы программы - какие права имеет пользователь
#define CHECKPOINT_AFOOT 1
#define CHECKPOINT_CAR 2
#define ORDER_BOSS 3
#define ORDER_TENANT 4
#define MATCHING_BOSS 5
#define ADMIN 6
#define CLOSE_LOGIN_APP 0

int type_user = 0;

//Логин для удобства хранится глобально
std::string login;

//id пользователя по таблице workers (с данными о всех сотрудниках)
int id_worker;

//id пользователя по таблице registers_user (с данными только о зарегистрированных сотрудниках)
//Модуль для регистрации не был написан ни на одном языке, проходила она с помощью pgAdmin или DataGrip
// (визуальных средств управления базами данных)
int id_user;

//Документ с ошибками и сбоями программы. Не проработано, используется мало.
std::ofstream journal("./log.txt",std::ios::app);

void journal_init(){
    if (!journal) {
        journal = std::ofstream("./log.txt");
    }
}

//Основное соединение приложения
PGconn* conn;

//Структура разового пропуска. fathername - отчество. patronymic не использовал, так как
// не знал правильный перевод отчества и не догадался посмотреть.
struct s_single_pass{
    int id = 0;
    std::string surname;
    std::string name;
    std::string fathername;
    bool status_factory = false; //Статус нахождения на предприятии
    int id_director = 0; //id заказчика по таблице workers
    std::string type_document;
    std::string number_document;
    bool status_pass = false; //Статус пропуска: активный или нет. Актуально для разовых
    std::string organization; //Организация, ЧЬИМ ПРЕДСТАВИТЕЛЕМ ЯВЛЯЕТСЯ ПОСЕТИТЕЛЬ
    std::string date_query; //Дата заказа
    std::string time_query;
    std::string date_pass; //Дата пропуска (для длительных - дата начала)
    std::string time_pass;
    std::string enter_time; //Время входа на предприятие
    std::string exit_time;
    bool pass_using = false; //Статус использования пропуска
    bool driver = false; //Водитель ли посетитель
    std::string num_auto;
    std::string organization_custom; //Организация, заказавшая пропуск
    int status_appology = -1; //Статус утверждения. -1 - не просмотрено
    // 0 - одобрено, 1 - отказано
    std::string commentary;
    bool no_single = false;
    std::string mark_auto;
    std::string cargo;
    std::string finish_time;
    std::string commentary_decline;
};

//Адрес информации о графическом интерфейсе
char* const path_glade = "./Application.glade";

#endif //INC_345MF_POSTGRES_H
