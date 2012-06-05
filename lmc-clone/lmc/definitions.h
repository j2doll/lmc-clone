/****************************************************************************
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


#ifndef DEFINITIONS_H
#define DEFINITIONS_H

//	Information about the application
#define IDA_TITLE		"LAN Messenger"
#ifdef Q_WS_WIN
#define IDA_PRODUCT		"LAN Messenger"
#define IDA_COMPANY		"LAN Messenger"
#else
#define IDA_PRODUCT		"lmc"
#define IDA_COMPANY		"lmc"
#endif
#define IDA_VERSION		"2.0.0"
#define IDA_DESCRIPTION	"LAN Messenger is a free peer-to-peer messaging application for intra-network communication "\
						"and does not require a server.\n"\
						"LAN Messenger works on essentially every popular desktop platform."
#define IDA_COPYRIGHT	"Copyright (C) 2010-2012 Qualia Digital Solutions."
#define IDA_CONTACT		"qualiatech@gmail.com"
#define IDA_DOMAIN		"http://lanmsngr.sourceforge.net"

#if defined Q_WS_WIN
#define IDA_PLATFORM	"Windows"
#elif defined Q_WS_MAC
#define IDA_PLATFORM	"Macintosh"
#elif defined Q_WS_X11
#define IDA_PLATFORM	"Linux"
#endif

#define DELIMITER		"||"
#define DELIMITER_ESC	"\\|\\|"

/****************************************************************************
**	Message type definitions
**	The enum and the string array should always be synced
****************************************************************************/
enum MessageType {
    MT_Blank = 0,
    MT_Announce,
    MT_Depart,
    MT_UserData,
    MT_Broadcast,
    MT_Status,
    MT_Avatar,
    MT_UserName,
    MT_Ping,
    MT_Message,
    MT_GroupMessage,
    MT_PublicMessage,
    MT_File,
    MT_Acknowledge,
    MT_Failed,
    MT_Error,
    MT_OldVersion,
    MT_Query,
    MT_Info,
    MT_ChatState,
    MT_Note,
    //	These are used only for local communication between layers
    MT_Group,
    MT_Version,
    MT_WebFailed,
    MT_LocalFile,
    MT_LocalAvatar,
    MT_Refresh,
    MT_Join,
    MT_Leave,
    MT_Max
};

const QString MessageTypeNames[] = {
	"",
	"announce",
	"depart",
	"userdata",
	"broadcast",
	"status",
	"avatar",
	"name",
	"ping",
	"message",
	"groupmessage",
	"publicmessage",
	"file",
	"acknowledge",
	"failed",
	"error",
	"oldversion",
	"query",
	"info",
	"chatstate",
	"note",
	//	These are used only for local communication between layers
	"group",
	"version",
	"webfailed",
	"localfile",
	"localavatar",
	"refresh",
	"join",
	"leave"
};

enum FileMode {
	FM_Blank = 0,
	FM_Send,
	FM_Receive,
	FM_Max
};

const QString FileModeNames[] = {
	"",
	"send",
	"receive"
};

/****************************************************************************
**	File operation definitions
**	The enum and the string array should always be synced
****************************************************************************/
enum FileOp {
	FO_Blank = 0,
	FO_Request,
	FO_Accept,
	FO_Decline,
	FO_Cancel,
	FO_Progress,
	FO_Error,
	FO_Abort,
	FO_Complete,
	FO_Max
};

const QString FileOpNames[] = {
	"",
	"request",
	"accept",
	"decline",
	"cancel",
	"progress",
	"error",
	"abort",
	"complete"
};

/****************************************************************************
**	File operation definitions
**	The enum and the string array should always be synced
****************************************************************************/
enum FileType {
	FT_None = 0,
	FT_Normal,
	FT_Avatar,
	FT_Max
};

const QString FileTypeNames[] = {
	"",
	"normal",
	"avatar"
};

/****************************************************************************
**	Query operation definitions
**	The enum and the string array should always be synced
****************************************************************************/
enum QueryOp {
	QO_None = 0,
	QO_Get,
	QO_Result,
	QO_Max
};

const QString QueryOpNames[] = {
	"",
	"get",
	"result"
};

/****************************************************************************
**	Group Message operation definitions
**	The enum and the string array should always be synced
****************************************************************************/
enum GroupMsgOp {
	GMO_None = 0,
	GMO_Request,
	GMO_Join,
	GMO_Message,
	GMO_Leave,
	GMO_Max
};

const QString GroupMsgOpNames[] = {
	"",
	"request",
	"join",
	"message",
	"leave"
};

enum GroupOp {
	GO_None = 0,
	GO_New,
	GO_Rename,
	GO_Move,
	GO_Delete,
	GO_Max
};

enum TrayMessageType {
	TM_Connection,
	TM_Status,
	TM_Transfer,
	TM_Minimize,
	TM_Max
};
enum TrayMessageIcon {
	TMI_Info,
	TMI_Warning,
	TMI_Error,
	TMI_Max
};

//	User status definitions
enum StatusType {
	StatusTypeOnline = 0,
	StatusTypeBusy,
	StatusTypeOffline,
	StatusTypeAway,
	StatusTypeMax
};

#define ST_COUNT	6
const QString statusCode[] = {
	"chat",
	"busy",
	"dnd",
	"brb",
	"away",
	"gone"
};
const int statusType[] = {
	StatusTypeOnline,
	StatusTypeBusy,
	StatusTypeBusy,
	StatusTypeAway,
	StatusTypeAway,
	StatusTypeOffline
};

#define GRP_DEFAULT		"General"
#define GRP_DEFAULT_ID	"1CD75C10048C4E65F6082539A32DC111"

#define GROUPMSGVERSION	"1.2.16"

#define AUTO_CONNECTION	"Auto"

#define LMC_TRUE	"true"
#define LMC_FALSE	"false"

#endif // DEFINITIONS_H