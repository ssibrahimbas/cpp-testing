#include "internal/user/user.h"
#include "internal/fs/fsHelper.h"
#include "internal/engine/GameEngine.h"
#include "internal/table/Table.h"
#include "internal/printer/IPrinter.h"
#include "list"

int main() {
    srand(time(nullptr));
    FsHelper fsHelper;
    IPrinter printer;
    std::list<User> users = fsHelper.getUsers("./users");
    Table table = Table(users);
    GameEngine gameEngine(table, printer);

    gameEngine.start();


    return 0;
}
