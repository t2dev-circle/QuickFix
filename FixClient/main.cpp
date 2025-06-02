#include <memory>
#include <iostream>
#include <quickfix/SessionSettings.h>
#include <quickfix/FileStore.h>
#include <quickfix/SocketInitiator.h>
#include "initiator_application.h"

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
        SessionSettings settings("../fix_initiator.cfg");

        InitiatorApplication application;
        FileStoreFactory storeFactory(settings);
        ScreenLogFactory logFactory(settings);

        unique_ptr<Initiator> initiator;
        initiator = unique_ptr<Initiator>(new SocketInitiator(application, storeFactory, settings, logFactory));

        initiator->start();
        wait();
        initiator->stop();
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