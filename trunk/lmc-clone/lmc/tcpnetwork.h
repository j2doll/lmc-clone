﻿/****************************************************************************
**
** This file is part of LAN Messenger.
** 
** Copyright (c) 2010 - 2012 Qualia Digital Solutions.
** 
** Contact:  qualiatech@gmail.com
** 
** LAN Messenger is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** LAN Messenger is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with LAN Messenger.  If not, see <http://www.gnu.org/licenses/>.
**
****************************************************************************/


#ifndef TCPNETWORK_H
#define TCPNETWORK_H

#include <QtGlobal>
#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include <QMap>
#include <QList>

#include "trace.h"
#include "crypto.h"
#include "xmlmessage.h"
#include "settings.h"

#include "datagram.h"
#include "netstreamer.h"

class lmcTcpNetwork : public QObject
{
	Q_OBJECT

public:
	lmcTcpNetwork(void);
    ~lmcTcpNetwork(void);

public:
	void init(int nPort = 0);
	void start(void);
	void stop(void);
	void setLocalId(QString* lpszLocalId);
	void setCrypto(lmcCrypto* pCrypto);
	void addConnection(QString* lpszUserId, QString* lpszAddress);
	void sendMessage(QString* lpszReceiverId, QString* lpszData);
	void initSendFile(QString* lpszReceiverId, QString* lpszAddress, QString* lpszData);
	void initReceiveFile(QString* lpszSenderId, QString* lpszAddress, QString* lpszData);
	void fileOperation(FileMode mode, QString* lpszUserId, QString* lpszData);
	void settingsChanged(void);
	void setIPAddress(const QString& szAddress);

signals:
	void newConnection(QString* lpszUserId, QString* lpszAddress);
	void connectionLost(QString* lpszUserId);
	void messageReceived(DatagramHeader* pHeader, QString* lpszData);
	void progressReceived(QString* lpszUserId, QString* lpszData);

protected slots:
	void server_newConnection(void);
	void socket_readyRead(void);
	void msgStream_connectionLost(QString* lpszUserId);
	void update(FileMode mode, FileOp op, FileType type, QString* lpszId, QString* lpszUserId, QString* lpszData);
	void receiveMessage(QString* lpszUserId, QString* lpszAddress, QByteArray& data);

protected:
	void addFileSocket(QString* lpszId, QTcpSocket* pSocket);
	void addMsgSocket(QString* lpszUserId, QTcpSocket* pSocket);
	void sendPublicKey(QString* lpszUserId);
	void sendSessionKey(QString* lpszUserId, QByteArray& publicKey);
	FileSender* getSender(QString id);
	FileReceiver* getReceiver(QString id);

    void addHeader( DatagramType type, QByteArray& baData );
    bool getHeader( QByteArray& baDatagram, DatagramHeader** ppHeader );
    QByteArray getData( QByteArray& baDatagram );
    int indexOf(const QString array[], int size, const QString& value);

	QTcpServer*				  server;
	QList<FileSender*>		  sendList;
	QList<FileReceiver*>	  receiveList;
	QMap<QString, MsgStream*> messageMap;
	MsgStream*				  locMsgStream;
	lmcSettings*			  pSettings;
	bool					  isRunning;
	int						  tcpPort;
	QString					  localId;
	lmcCrypto*				  crypto;
	QHostAddress			  ipAddress;

};

#endif // TCPNETWORK_H