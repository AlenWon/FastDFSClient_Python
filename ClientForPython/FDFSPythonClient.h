#ifndef PYTHON_FDFS_CLIENT_H
#define PYTHON_FDFS_CLIENT_H

#include <Python.h>
#include "fdfs_client.h"
#include "fdfs_global.h"
#include "base64.h"
#include "sockopt.h"
#include "logger.h"
#include "FDFSClient.h"
#include <string>

//������
enum FSC_CODE
{
	FSC_ERROR_CODE_NONE = 0,				//û�д���
	FSC_ERROR_CODE_INIT_FAILED,				//��ʼ��ʧ��
	
	FSC_ERROR_CODE_PARAM_INVAILD,			//������Ч

	FSC_ERROR_CODE_CONNECT_TRACKER_FAIL,    //����ʧ��
	FSC_ERROR_CODE_QUERY_STORAGE_FAIL,		//��ѯstorage��ַʧ��
	FSC_ERROR_CODE_CONNECT_STORAGE_FAIL,	//����storageʧ��

	FSC_ERROR_CODE_DOWNLAOD_FILE_FAIL,		//�����ļ�ʧ��
	FSC_ERROR_CODE_DELETE_FILE_FAIL,		//ɾ���ļ�ʧ��
};

#ifdef __cplusplus
extern "C" 
{
#endif
//////////////////////////////////////////////////////////////////////////
//���ܣ���ʼ��fastdfs
//������
//      const char* sConfig IN FastDFS�����ļ�·�� ����:/etc/fdfs/client.conf 
//		int nLogLevel ��־�ȼ� ���õ���unix ��־�ȼ�
//  0: LOG_EMERG
//	1: LOG_ALERT
//	2: LOG_CRIT
//	3: LOG_ERR
//	4: LOG_WARNING
//	5: LOG_NOTICE
//	6: LOG_INFO
//	7: LOG_DEBUG

//���أ�int& anError OUT ������Ϣ

//��ע��
//      ע���ʼ��ʱ�����뱣֤conf�ļ���base_pathĿ¼����
//		���� base_path=/fastdfs/tracker, ��Ҫ��֤/fastdfs/tracker���ڣ�
//		������ �贴��mkdir /fastdfs/tracker
//////////////////////////////////////////////////////////////////////////
int fdfs_init(const char* sConfig, int nLogLevel);

//////////////////////////////////////////////////////////////////////////
//���ܣ������ļ�
//������
//      BufferInfo* pBuff OUT ���ص��ļ���Ϣ���ļ���С���Լ��ڴ��С
//      const char *group_name IN �洢����
//      const char* remote_filename IN �洢��
//      ���磺group2/M00/00/00/CgEIzVRhnJWAZfVkAAAsFwWtoVg250.png 
//		group_name:group2 
//		remote_filename: M00/00/00/CgEIzVRhnJWAZfVkAAAsFwWtoVg250.png 

// ���أ�0:�ɹ� ����ʧ�ܡ�
//////////////////////////////////////////////////////////////////////////
int fdfs_download(BufferInfo* pBuff, const char* group_name, const char* remote_filename);

//////////////////////////////////////////////////////////////////////////
//���ܣ��ϴ��ļ�
//������
//      char *file_content IN �ļ�����
//      const char *file_ext_name IN �ļ���չ��
//		int file_size IN �ļ���С
//		int& name_size	OUT ���ص��ļ�����С
//      char* remote_file_name OUT ���ص��ļ���
//      ���磺group2/M00/00/00/CgEIzVRhnJWAZfVkAAAsFwWtoVg250.png 

// ���أ�0:�ɹ� ����ʧ�ܡ�
//////////////////////////////////////////////////////////////////////////
int fdfs_upload(const char *file_content, const char *file_ext_name, int file_size, 
				  int& name_size, char*& remote_file_name);

//////////////////////////////////////////////////////////////////////////
//���ܣ�ɾ���ļ�
//������
//      const char *group_name IN �洢����
//      const char* remote_filename IN �洢��
//      ���磺group2/M00/00/00/CgEIzVRhnJWAZfVkAAAsFwWtoVg250.png 
//		group_name:group2 
//		remote_filename: M00/00/00/CgEIzVRhnJWAZfVkAAAsFwWtoVg250.png 

// ���أ�0:�ɹ� ����ʧ�ܡ�
//////////////////////////////////////////////////////////////////////////
int fdfs_delete(const char *group_name, const char* remote_filename);

//////////////////////////////////////////////////////////////////////////
//���ܣ���ȡ��������Ϣ
//������
//      BufferInfo* group_info OUT ��������Ϣ

// ���أ�0:�ɹ� ����ʧ�ܡ�
//////////////////////////////////////////////////////////////////////////

int list_all_groups(BufferInfo* group_info);

//////////////////////////////////////////////////////////////////////////
//���ܣ���ȡָ������Ϣ
//������
//		const char* group_name IN ���� �磺group1
//      BufferInfo* group_info OUT ��������Ϣ

// ���أ�0:�ɹ� ����ʧ�ܡ�
//////////////////////////////////////////////////////////////////////////
int list_one_group(const char* group_name, BufferInfo *group_info);

//////////////////////////////////////////////////////////////////////////
//���ܣ���ȡstorage��Ϣ
//������
//		const char* group_name IN ���� �磺group1
//		const char* storage_id IN ���� �磺storage ip
//      BufferInfo* storages_info OUT �洢��Ϣ

// ���أ�0:�ɹ� ����ʧ�ܡ�
//////////////////////////////////////////////////////////////////////////

int list_storages(const char* group_name, 
				  const char* storage_id, 
				  BufferInfo* storages_info);

#ifdef __cplusplus
}
#endif

#endif

