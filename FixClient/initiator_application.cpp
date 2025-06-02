#include "initiator_application.h"
#include <iostream>
#include <quickfix/SessionID.h>

using namespace std;

InitiatorApplication::InitiatorApplication()
{
}

InitiatorApplication::~InitiatorApplication()
{
}

/// Notification of a session begin created
void InitiatorApplication::onCreate(const SessionID &session)
{
    cout << "onCreate: " << session.toString() << endl;
}

/// Notification of a session successfully logging on
void InitiatorApplication::onLogon(const SessionID &session)
{
    cout << "onLogon: " << session.toString() << endl;
}

/// Notification of a session logging off or disconnecting
void InitiatorApplication::onLogout(const SessionID &session)
{
    cout << "onLogout: " << session.toString() << endl;
}

/// Notification of admin message being sent to target
void InitiatorApplication::toAdmin(Message &msg, const SessionID &session)
{
    cout << "toAdmin: " << session.toString() << endl;
}

/// Notification of app message being sent to target
void InitiatorApplication::toApp(Message &msg, const SessionID &session) EXCEPT(DoNotSend)
{
    cout << "toApp: " << session.toString() << endl;
}

/// Notification of admin message being received from target
void InitiatorApplication::fromAdmin(const Message &msg, const SessionID &session)
    EXCEPT(FieldNotFound, IncorrectDataFormat, IncorrectTagValue, RejectLogon)
{
    cout << "fromAdmin: " << session.toString() << endl;
}

/// Notification of app message being received from target
void InitiatorApplication::fromApp(const Message &msg, const SessionID &session)
    EXCEPT(FieldNotFound, IncorrectDataFormat, IncorrectTagValue, UnsupportedMessageType)
{
    cout << "fromApp: " << session.toString() << endl;
}