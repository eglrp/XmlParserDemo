// ����ģ��
#pragma once

// �Զ������ݽṹ
namespace WangYingXmlParser{
	// ����
	struct CAttribute {
		std::string name;		// ��������
		std::string value;		// ����ֵ
	};

	// ��Ŀ
	struct CItem {
		std::string name;				// ��Ŀ����
		std::vector<CItem> subitems;	// ����Ŀ
		std::vector<CAttribute> attributes;
	};

	// �ĵ�
	struct CDocument {
		std::vector<CItem> items;	// ��Ŀ�б�
	};
}

class CWangYingXmlParser {
public:
	CWangYingXmlParser();
	virtual ~CWangYingXmlParser();

public:// �ⲿ�ӿ�
	
	// �ⲿ�ӿڣ��������д��������Ͳ�������
	bool ParseXml(std::string strXml);

	// �ⲿ�ӿڣ���ó�����Ϣ
	bool GetErrorMessage(std::string *pstrErrorMessage);

	// �ⲿ�ӿڣ���ȡ��ǰ xml ������
	bool GetXmlDocument(WangYingXmlParser::CDocument *pXmlDocument);

	// �ⲿ�ӿڣ�����ǰ xml �����ݴ�ӡ����׼���
	void PrintXmlData(WangYingXmlParser::CDocument xmlDocument);

protected:// ������

	// ��飺�����ı��Ƿ�Ϸ�
	bool _CheckXmlValid(std::string strXml);

	// ��飺��ǩ�ԶԳ��Լ��
	bool _CheckTabSymmetry(std::string strXml, bool *pbIsSymmetry);

protected:// �������

	// �����������ı����� xml �ı�������һ��һ����Ŀ
	bool _ParseSource(std::string strXml);

	// ����������һ����Ŀ
	bool _ParseOneItem(std::string strOneItemXml, WangYingXmlParser::CItem *pItem);

	// ����������һ����Ŀ������Ŀ���� text ���ԣ�����Ŀ�ı�ǩ��֮�����Ϊ������Ŀ���� text ���ԣ�
	bool _ParseSubItem(std::string strOneItemXml, WangYingXmlParser::CItem *pItem);

	// ����������һ������
	bool _ParseOneAttribute(std::string strOneAttribute, WangYingXmlParser::CAttribute *pAttribute);

protected:// ��ӡ���

	// ��ӡ����ӡһ�� Item
	void _PrintOneItem(WangYingXmlParser::CItem item, int nSubLevel);

private:
	WangYingXmlParser::CDocument m_cDocument;	// ���棺���������ݽṹ
	std::string m_strErroMessage;				// ���棺����ʧ�ܵĴ�����Ϣ
};
