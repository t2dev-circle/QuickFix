#include "acceptor_application.h"
#include <iostream>
#include <quickfix/SessionID.h>

using namespace std;

AcceptorApplication::AcceptorApplication()
{
}

AcceptorApplication::~AcceptorApplication()
{
}

/// Notification of a session begin created
void AcceptorApplication::onCreate(const SessionID &session)
{
    cout << "onCreate: " << session.toString() << endl;
}

/// Notification of a session successfully logging on
void AcceptorApplication::onLogon(const SessionID &session)
{
    cout << "onLogon: " << session.toString() << endl;
}

/// Notification of a session logging off or disconnecting
void AcceptorApplication::onLogout(const SessionID &session)
{
    cout << "onLogout: " << session.toString() << endl;
}

/// Notification of admin message being sent to target
void AcceptorApplication::toAdmin(Message &msg, const SessionID &session)
{
    cout << "toAdmin: " << session.toString() << endl;
}

/// Notification of app message being sent to target
void AcceptorApplication::toApp(Message &msg, const SessionID &session) EXCEPT(DoNotSend)
{
    cout << "toApp: " << session.toString() << endl;
}

/// Notification of admin message being received from target
void AcceptorApplication::fromAdmin(const Message &msg, const SessionID &session)
    EXCEPT(FieldNotFound, IncorrectDataFormat, IncorrectTagValue, RejectLogon)
{
    cout << "fromAdmin: " << session.toString() << endl;
}

/// Notification of app message being received from target
void AcceptorApplication::fromApp(const Message &msg, const SessionID &session)
    EXCEPT(FieldNotFound, IncorrectDataFormat, IncorrectTagValue, UnsupportedMessageType)
{
    cout << "fromApp: " << session.toString() << endl;
}