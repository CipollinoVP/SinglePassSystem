#include "LoginApp.h"
#include "SinglePassApp.h"

int main(int argc, char *argv[]) {
    journal_init();
    login_window(argc,argv);
    SinglePassApp(argc,argv);
    return 0;
}
