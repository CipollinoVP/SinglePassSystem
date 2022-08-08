#include "LoginApp.h"
#include "SinglePassApp.h"

int get_id_worker(){
    std::stringstream query;
    query << "SELECT id_workers FROM registers_user WHERE login_database = '"
    << login << "';";
    PGresult *res = PQexec(conn,query.str().c_str());
    int n = PQntuples(res);
    if (n != 0) {
        return std::stoi(std::string(PQgetvalue(res,0,0)));
    } else return -1;
}

int get_id_user(){
    std::stringstream query;
    query << "SELECT id FROM registers_user WHERE login_database = '"
          << login << "';";
    PGresult *res = PQexec(conn,query.str().c_str());
    int n = PQntuples(res);
    if (n != 0) {
        return std::stoi(std::string(PQgetvalue(res,0,0)));
    } else return -1;
}

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Russian");
    journal_init();
    login_window(argc,argv);
    id_worker = get_id_worker();
    id_user = get_id_user();
    SinglePassApp(argc,argv);
    PQfinish(conn);
    return 0;
}
