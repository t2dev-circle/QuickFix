#include <memory>
#include <iostream>
#include <quickfix/SessionSettings.h>
#include <quickfix/FileStore.h>
#include <quickfix/SocketAcceptor.h>
#include "acceptor_application.h"

using namespace std;

static void wait()
{
    cout << "Type Ctrl-C to quit" << endl;
   
    while (true) 
    {
        FIX::process_sleep(1);
    }
}

int main(int argc, char **argv)
{
    try 
    {
        SessionSettings settings("../fix_acceptor.cfg");

        AcceptorApplication application;
        FileStoreFactory storeFactory(settings);
        ScreenLogFactory logFactory(settings);

        unique_ptr<Acceptor> acceptor;
        acceptor = unique_ptr<Acceptor>(new SocketAcceptor(application, storeFactory, settings, logFactory));

        acceptor->start();
        wait();
        acceptor->stop();
    } 
    catch (exception &e) 
    {
        cout << "exception: " << e.what() << endl;
    }
    catch (...)
    {
        cout << "exception: " << "unknown" << endl;
    }

    return 0;
}