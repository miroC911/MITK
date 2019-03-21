#include "mitkRESTManagerQt.h"
#include <mitkCommon.h>
#include <mitkRESTUtil.h>

mitk::RESTManagerQt::RESTManagerQt() {}

mitk::RESTManagerQt::~RESTManagerQt() {}

void mitk::RESTManagerQt::ReceiveRequest(const web::uri &uri, mitk::IRESTObserver *observer)
{
  // New instance of RESTServer in m_ServerMap, key is port of the request
  int port = uri.port();

  // Checking if port is free to add a new Server
  if (0 == m_ServerMap.count(port))
  {
    mitk::RESTManager::AddObserver(uri, observer);

    // creating server instance
    auto server = new RESTServerQt(uri.authority());
    // add reference to server instance to map
    m_ServerMap[port] = server;

    // Move server to seperate Thread and create connections between threads
    m_ServerThreadMap[port] = new QThread;
    server->moveToThread(m_ServerThreadMap[port]);

    connect(m_ServerThreadMap[port], &QThread::finished, server, &QObject::deleteLater);

    // starting Server
    m_ServerThreadMap[port]->start();
    QMetaObject::invokeMethod(server, "OpenListener");

    MITK_INFO << "new server " << mitk::RESTUtil::convertToUtf8(uri.authority().to_string()) << " at port " << port;
  }
  // If there is already a server under this port
  else
  {
    mitk::RESTManager::RequestForATakenPort(uri, observer);
  }
}

void mitk::RESTManagerQt::HandleDeleteObserver(IRESTObserver *observer, const web::uri &uri = L"")
{

  for (auto it = m_Observers.begin(); it != m_Observers.end();)
  {
    mitk::IRESTObserver *obsMap = it->second;
    // Check wether observer is at this place in map
    if (observer == obsMap)
    {
      // Check wether it is the right uri to be deleted
      if (uri.is_empty() || uri.path() == it->first.second)
      {
        int port = it->first.first;
        bool noObserverForPort = mitk::RESTManager::DeleteObserver(it, uri);
        if (noObserverForPort)
        {
          //  there isn't an observer at this port, delete m_ServerMap entry for this port
          // close listener
          QMetaObject::invokeMethod(static_cast<mitk::RESTServerQt *>(m_ServerMap[port]), "CloseListener");
          // end thread
          m_ServerThreadMap[port]->quit();
          m_ServerThreadMap[port]->wait();
 
          // delete server from map
          m_ServerMap.erase(port);
        }
      }
      else
      {
        ++it;
      }
    }
    else
    {
      ++it;
    }
  }
}
