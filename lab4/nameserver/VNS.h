

#ifndef VNS_H
#define NAME_SERVER_INTERFACE_H

#include nameserverinterface.h
#include <vector>


class VNS {

public:
  virtual IPAddress lookup(const HostName&) const = 0;
  virtual void insert(const HostName&, const IPAddress&) = 0;
  virtual bool remove(const HostName&) = 0;


}
