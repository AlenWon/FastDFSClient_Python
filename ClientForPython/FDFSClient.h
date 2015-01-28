#ifndef MY_FDFS_CLIENT_H
#define MY_FDFS_CLIENT_H

#include "fdfs_client.h"
#include "fdfs_global.h"
#include "base64.h"
#include "sockopt.h" 
#include "logger.h"
#include <string>

using namespace std;

class CFDFSClient
{
public:
	CFDFSClient(void);
	~CFDFSClient(void);

public:
	
	// ��ʼ���ͻ���
	int init(const char* sFDFSConfig, int nLogLevel);

	// �����ļ�
	int fdfs_dowloadfile(BufferInfo* pBuff, const char *group_name, const char* remote_filename);
	
	// �ϴ�
	int fdfs_uploadfile( const char *file_content, const char *file_ext_name, int file_size, 
		int& name_size, char*& remote_file_name);

	// ɾ��
	int fdfs_deletefile(const char *group_name, const char* remote_filename);

	// ��������Ϣ
	int list_all_groups(BufferInfo* group_info);

	// ָ������Ϣ
	int list_one_group(const char* group_name, BufferInfo *group_info);

	// storage��Ϣ
	int list_storages(const char* group_name, 
		const char* storage_id, 
		BufferInfo* storages_info);

private:
	void re_fastfds_client_init();

	int fastfdfs_client_init(const char* sFDFSConfig);

private:
	ConnectionInfo *m_pTrackerServer;
	BufferInfo m_RecvBufferInfo;
	char* m_pRemoteFileName;
	string m_strConfigPath;
	int	m_nLevelLog;
};

#endif

