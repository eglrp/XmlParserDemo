// MainDlg.h : interface of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include "WangYingXmlParser/WangYingXmlParser.h"
class CMainDlg : public SHostWnd
{
public:
	CMainDlg();
	~CMainDlg();

	void OnClose();
	void OnMaximize();
	void OnRestore();
	void OnMinimize();
	void OnSize(UINT nType, CSize size);
	void OnBtnMsgBox();
	int OnCreate(LPCREATESTRUCT lpCreateStruct);
	BOOL OnInitDialog(HWND wndFocus, LPARAM lInitParam);

protected:// 操作响应

	// 按钮：解析 xml 代码
	HRESULT OnButtonParseXmlCode();

protected:// 逻辑相关

	// Scintilla：获取文本
	HRESULT _GetScintillaText(std::string *pstrText);

	// Scintilla：设置文本
	HRESULT _SetScintillaText(std::string strText);

	// 显示：解析树
	HRESULT _ShowParseXmlTree(WangYingXmlParser::CDocument xmlDocument);

	// 显示：解析项目
	HRESULT _ParseSubItem(WangYingXmlParser::CItem subItem, SOUI::HTREEITEM treeItem, SOUI::STreeCtrl *pTreeCtrl);

	// 清除：清除字符串中的 \r\n 空白字符
	HRESULT _ClearUnusefulChar(std::string &strXmlCode);

protected:
	//soui消息
	EVENT_MAP_BEGIN()
		EVENT_NAME_COMMAND(L"btn_close", OnClose)
		EVENT_NAME_COMMAND(L"btn_min", OnMinimize)
		EVENT_NAME_COMMAND(L"btn_max", OnMaximize)
		EVENT_NAME_COMMAND(L"btn_restore", OnRestore)
		EVENT_NAME_COMMAND(L"button_parse_xml_code", OnButtonParseXmlCode);
	EVENT_MAP_END()

	//HostWnd真实窗口消息处理
	BEGIN_MSG_MAP_EX(CMainDlg)
		MSG_WM_CREATE(OnCreate)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_CLOSE(OnClose)
		MSG_WM_SIZE(OnSize)
		CHAIN_MSG_MAP(SHostWnd)
		REFLECT_NOTIFICATIONS_EX()
	END_MSG_MAP()

private:
	BOOL m_bLayoutInited;
};
