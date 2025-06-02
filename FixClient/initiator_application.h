#pragma once

#include <quickfix/Application.h>

using namespace FIX;

class InitiatorApplication: public Application
{
public:
    InitiatorApplication();
    ~InitiatorApplication();
public:
  /// Notification of a session begin created
  virtual void onCreate(const SessionID &);
  /// Notification of a session successfully logging on
  virtual void onLogon(const SessionID &);
  /// Notification of a session logging off or disconnecting
  virtual void onLogout(const SessionID &);
  /// Notification of admin message being sent to target
  virtual void toAdmin(Message &, const SessionID &);
  /// Notification of app message being sent to target
  virtual void toApp(Message &, const SessionID &) EXCEPT(DoNotSend);
  /// Notification of admin message being received from target
  virtual void fromAdmin(const Message &, const SessionID &)
      EXCEPT(FieldNotFound, IncorrectDataFormat, IncorrectTagValue, RejectLogon);
  /// Notification of app message being received from target
  virtual void fromApp(const Message &, const SessionID &)
      EXCEPT(FieldNotFound, IncorrectDataFormat, IncorrectTagValue, UnsupportedMessageType);
};