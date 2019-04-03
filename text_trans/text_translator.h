#ifndef _text_string_define_h_
#define _text_string_define_h_


#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>
#include <QObject>
#include <QPushButton>
#include <QDialog>
#include <QLabel>
#include <QString>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QProgressBar>
#include <qmovie.h>
#include <QSplitter>
#include <QDialog>
#include <QLineEdit>
#include <QSlider> 
#include <QCheckBox>
#include <QTimer>
#include <map>
#include <QGroupBox>
#include <QRegExpValidator>
#include <QFileDialog>
#include <QSlider>
#include <qmenu.h>
#include <qtabbar.h>
#include <qtabwidget.h>

using namespace std;

namespace Sn3DConsumerScanner{
	 
#define NEXT_STEP_PROMT_NO_CONNECT_DEVICE					0	 //设备类型对话框
#define NEXT_STEP_PROMT_NO_CALIRATE_DATA					1
#define NEXT_STEP_PROMT_CALIRATE_DATA_LOST					2
#define NEXT_STEP_PROMT_PLEASE_DISABLE_BUILD_CAMERA			3
#define NEXT_STEP_PROMT_PLE_ERROR							4
#define NEXT_STEP_PROMT_NOT_CONNECT_TURTABLE				5
#define LOADING_STRING										6
#define NEXT_STEP_STRING									7
#define PREVIOUS_STRING										8
#define CALIBRATE_STRING									9
#define NO_CONNECT_S_DEVICE							       10
#define NO_CONNECT_SE_DEVICE							   11
#define NO_CONNECT_SP_DEVICE						       12
#define NO_CONNECT_PRO_DEVICE						       13
#define NO_CONNECT_PRO_PLUS_DEVICE					       14
#define DEVICE_TYPE_CHOOSE_S							   15
#define DEVICE_TYPE_CHOOSE_SE							   16
#define DEVICE_TYPE_CHOOSE_SP							   17
#define DEVICE_TYPE_CHOOSE_PRO							   18
#define DEVICE_TYPE_CHOOSE_PRO_PLUS						   19
#define NULL_TEXT										   20
#define CHOOSE_DEVCIE_TYPE								   21
#define CHOOSE_SCAN_MODE								   22//选择扫描模式对话框
#define CHOOSE_FIXED_SCAN								   23
#define CHOOSE_AUTO_SCAN									24
#define CHOOSE_HANDLE_RAPID_SCAN							25
#define CHOOSE_HANDLE_HD_SCAN							    26
#define CURRENT_STATE_HD                                    27
#define CURRENT_STATE_RAPID                                 28
#define CURRENT_STATE_AUTO_SCAN                             29
#define CURRENT_STATE_FIXED_SCAN                            30
#define CURRENT_STATE_S_CALIBRATE                           31
#define CURRENT_STATE_SE_CALIBRATE                          32
#define CURRENT_STATE_SP_CALIBRATE                          33
#define CURRENT_STATE_PRO_CALIBRATE                         34
#define CURRENT_STATE_PRO_PLUS_CALIBRATE                    35
#define TEXT_WARNING                                        36//消息框文本
#define TEXT_NOTICE                                         37
#define TEXT_YES											38
#define TEXT_NO											    39
#define TEXT_SCAN											40
#define TEXT_CANCEL											41
#define TEXT_NEW_VERSION									42//主窗口文字信息结束 42
#define TEXT_LEFT_MOUSE										43
#define TEXT_MIDDLE_MOUSE									44
#define TEXT_RIGHT_MOUSE									45
#define TEXT_SHIFT_LEFT_MOUSE								46
#define TEXT_SHIFT_LEFT_MOUSE_ALIGN							47
#define TEXT_DELETE_KEY										48
#define TEXT_EXPORT_FAILED									49
#define TEXT_3DPRINT										50
#define TEXT_3DPRINT_FAILED									51
#define TEXT_PROGRAM_CLOSE									52
#define TEXT_OPEN_CONFIG									53
#define TEXT_INFORMATION									54
#define TEXT_MUST_MESH_FIRST								55
#define TEXT_OK												56
#define TEXT_NO_WARTERTIGHT_DATA							57//主窗口文字信息结束 57
#define TEXT_DEL_ALL										58
#define TEXT_PROMT											59
#define TEXT_WARTWETIGHT									60
#define TEXT_UNWARTWETIGHT									61
#define TEXT_VERIFY											62
#define TEXT_ROTATE_MOVE_ZOOM							    63
#define TEXT_CURRENT_POINT									64
#define TEXT_CURRENT_TRIANGLES								65
#define TEXT_QUICK_MESH										66
#define TEXT_OPEN_PROJECT									67
#define TEXT_NEW_PROJECT									68
#define TEXT_MESH_PROGRESS									69
#define TEXT_SAVE_PROGRESS									70
#define TEXT_POINT_PROCESSING_PROGRESS						71
#define TEXT_SCANING_PROGRESS								72
#define TEXT_EDIT_DESELECT									73//编辑按钮 73
#define TEXT_EDIT_REVERT									74
#define TEXT_EDIT_DELETE									75
#define TEXT_EDIT_REDO										76
#define TEXT_EDIT_UNDO										77
#define TEXT_EDIT_TEXTURE									78
#define TEXT_START_SCAN									    79// 79
#define TEXT_MESH											80
#define TEXT_SAVE											81
#define TEXT_BACK_HOME										82
#define TEXT_DELETE										    83
#define TEXT_PAUSE											84
#define TEXT_PROJECT										85
#define TEXT_ALIGN											86
#define TEXT_SHARE											87
#define TEXT_ADJUST_BRIGHTNESS								88
#define TEXT_BTN_3DPRINT									89
#define TEXT_RESTART_WB_TEST								90//白平衡对话框90
#define TEXT_WB_TESTING										91
#define TEXT_MORE_THAN_ONE									92
#define TEXT_REEIZE_RATION									93
#define TEXT_REEIZE_SCAL									94
#define TEXT_REEIZE_ORGIN									95
#define TEXT_PRO_HIGHT										96
#define TEXT_PRO_MID										97
#define TEXT_PRO_LOW										98
#define TEXT_S_HIGHT										99
#define TEXT_S_MID											100
#define TEXT_S_LOW											101
#define TEXT_INFO_SELECT_DETAIL								102//S扫描配置对话框102
#define TEXT_APPLY											103
#define TEXT_SELECT_TEXTURE									104
#define TEXT_HIGH_DETAIL									105
#define TEXT_LOW_DETAIL										106
#define TEXT_MID_DETAIL										107
#define TEXT_SCAN_UNWARTERTIGHT								108
#define TEXT_SCAN_WARTERTIGHT								109
#define TEXT_SEL_SCAN_DETAIL								110
#define TEXT_SEL_MESH_MODE									111
#define TEXT_TETURE										    112
#define TEXT_NOTEXTURE										113
#define TEXT_OPEN_MARK_FILE									114//PRO 固定扫描对话框
#define TEXT_MARK_FILE_FORMAT								115
#define TEXT_MARK_FILE_ERROR								116
#define TEXT_BROWES											117
#define TEXT_OPEN_MARK_FILE_COLON							118
#define TEXT_PRO_TEXTURE									119
#define TEXT_PRO_UNTEXTURE									120
#define TEXT_RATION_RANGE									121//简化对话框
#define TEXT_SUGGEST_RANGE									122
#define TEXT_STL											123
#define TEXT_OBJ											124
#define TEXT_ORIGIN_SIZE									125
#define TEXT_POST_SIMPLE									126
#define TEXT_POLYGONS										127
#define TEXT_SIMPLIFY										128
#define TEXT_HOLE_PERIMER									129
#define TEXT_MM												130
#define TEXT_FILL_WHOLE										131
#define TEXT_WHOLE_MARK_POINT								132
#define TEXT_SIMPLIFY_RATION								133
#define TEXT_SEL_RESOLUTION_PROMPT							134//PRO手持扫描配置对话框
#define TEXT_OTHERS											135
#define TEXT_HIGHT_RESOLUTION								136
#define TEXT_MID_RESOLUTION									137
#define TEXT_LOW_RESOLUTION									138
#define TEXT_SEL_RESOLUTION									139
#define TEXT_FEATURE									    140
#define TEXT_BRIGHT											141//亮度调节对话框
#define TEXT_DARK											142
#define TEXT_DARK_PLAINT									143
#define TEXT_BRIGHT_DARK									144
#define TEXT_MID_BRIGHT										145
#define TEXT_SEL_SHADE										146
#define TEXT_HEIGHT_BRIGHT									147
#define TEXT_TRACK_LOST										148//手持扫描界面
#define TEXT_TOO_NEAR										149
#define TEXT_TOO_FAR										150
#define TEXT_TRACK_LOST_HELP								151
#define TEXT_DONE											152
#define TEXT_PREDICTED_SCAN									153
#define TEXT_SNAP											154//s 标定
#define TEXT_EXIT											155
#define TEXT_SKIP											156
#define TEXT_CHECK_ACCURACY									157
#define TEXT_CALIBRATE_OK_CLOSE								158
#define TEXT_WB_CALIBRATE_OK								159
#define TEXT_CAPTURE_PROGRESS								160
#define TEXT_CALIBRATE_PROGRESS								161
#define TEXT_S_NOTE											162
#define TEXT_LOADING										163
#define TEXT_FIGURE_A										164
#define TEXT_A_CAPTURE_PROGRESS0							165
#define TEXT_FIGURE_B										166
#define TEXT_B_CAPTURE_PROGRESS0							167
#define TEXT_FIGURE_C										168
#define TEXT_C_CAPTURE_PROGRESS0							169
#define TEXT_CALIBRATE_PROGRESS0							170
#define TEXT_CALIBRATE_FAILED								171
#define TEXT_CALIBRATE_OK									172
#define TEXT_WB_TEST										173
#define TEXT_S_WB_TESTING									174
#define TEXT_PRO_CAM_DIRECT									175
#define TEXT_SNAP_ON										176
#define TEXT_SNAP_OFF										177
#define TEXT_CAM_CALIBRATION								178
#define TEXT_HD_CALIBRATION									179
#define TEXT_COLOR_CAM_WB									180
#define TEXT_CALIBRATE_BOARD_SN								181
#define TEXT_HD_CALIBRATE_COMPLETE							182
#define TEXT_CAM_CALIBRATE_OK								183
#define TEXT_WITH_TURNTABLE									184
#define TEXT_WITHOUT_TURNTABLE								185
#define TEXT_WHITE_BALANCE									186
//#define TEXT_CALIBRATE_CAMRA_STEP1							187
//#define TEXT_CALIBRATE_CAMRA_STEP2_5						188
#define TEXT_START_PRESCAN									187 //开始预扫
#define TEXT_WB_EXPLAINT									188 //白平衡放置白纸
#define TEXT_ACCURACY_TEST_RESULT							189 //精度检测结果
#define TEXT_HD_TIPS										190 //HD 标定提示文字
#define TEXT_CAM_TIPS										191 //相机 标定提示文字
#define TEXT_WB_TIPS										192 //WB 标定提示文字
#define TEXT_FILL_WHOLE_LENTH								193
#define TEXT_FILL_WHOLE_LOAD								194
#define TEXT_FILL_WHOLE_NEW 								195
#define TEXT_PROJECT_FAILED 								196
#define TEXT_STRIPE_DEL 									197
#define TEXT_CLICK_HERE 									198
#define TEXT_DEVICE_OFFINE 									199
#define TEXT_HD_ADJUST_BRIGHTNESS 							200
#define TEXT_SPEAKER_ADJUST_BRIGHTNESS 						201
#define TEXT_DOUBLE_CLICK_ADJUST_BRIGHTNESS 				202
#define TEXT_CLICK_MESH 									203
#define TEXT_NEW_VERSION_DOWNLOAD							204 
#define CHOOSE_COLOR_CAM_TYPE								205//选择彩色相机类型
#define CHOOSE_SCAN_WITH_COLOR_CAME							206//使用彩色相机扫描
#define CHOOSE_SCAN_WITHOUT_COLOR_CAME						207//不使用彩色相机扫描
#define CHOOSE_COLOR_CAM_SCAN_TYPE							208//选择彩色相机扫描模式
#define DEVICE_OFFLINE_STATE								209//设备离线状态
#define CURRENT_STATE_SELECT_JOB_MODE						210//固定扫描选择工作模式
#define SELECT_JOB_MODE										211//固定扫描选择工作模式
#define CURRENT_STATE_STOUP_CALIBRATE						212//TOUP标定
#define DEVICE_TYPE_CHOOSE_STOUP							213//TOUP设备类型选择
#define NO_CONNECT_STOUP_DEVICE							    214//TOUP设备没有连接
#define HIGHT_QUALITY_TEXTURE							    215//高质量纹理
#define HIGHT_QUALITY_TEXTURE_EXPLAINT						216//高质量纹理详细描述
#define SPACE_KEY_END_EDIT_PROMPT							217//空格快捷键提示信息
#define SPACE_KEY_START_SCAN_PROMPT							218//空格快捷键提示信息
#define SCANNING_WITH_MARKER							    219//标志点扫描物体必须有标志点
#define ALIGEN_ERROR_TOO_FLAT							    220//物体太平 拼接不了 建议贴标志点
#define TEXT_PREVIEW										221//预扫
#define TEXT_PREVIEW_WITH_MARKER							222//预扫带标志点物体
#define TEXT_INSUFFICIENT_MEMORY							223//内存不足
#define TEXT_INSUFFICIENT_DISK_SPACE						224//磁盘空间不足
#define TEXT_MSG_INSUFFICIENT_MEMORY_SCAN					225//扫描内存不足消息框文字
#define TEXT_MSG_INSUFFICIENT_MEMORY_MESH					226//封装内存不足消息框文字
#define CALIBRATE_2PLUS2_STRING								227//
#define MARKER_OR_FEATURE_CHANGING							228//拼接模式切换中
#define HD_PRIME_SCAN										229//Prime
#define TEXT_BTN_SOLIDEDGE									230//solid edge
#define TEXT_NO_MESH_DATA									231//没有封装提示
#define HIGHT_QUALITY_TEXTURE_EXTEND						232//
#define TEXT_LAMP_HOUSE										233
#define TEXT_NO_LAMP_HOUSE									234
#define  AFTER_EDIT_APPLY									235
#define NO_PRIME_CALIRATE_DATA                              236
#define PRIME_PLE_ERROR										237
#define DISCOVERY_PLE_ERROR									238//
#define DISCOVERY_USB2_ERROR							    239//usb需要切换到3.0
#define PRIME_NO_MARKER_ERROR							    240//没有检测到标识点
#define PRIME_NOT_SCAN_DATA							        241//没有扫描到数据
#define CALIB_DATA_EXCEPTION							    242//标定数据异常
#define PLEASE_INPUT_PERIMETER							    243//请输入补洞周长
#define DEVICE_RECONNECTING									244//设备断线 重连中
 

#define GUID_PAGE_END									    299
					
 
#define S_SCAN_BEGIN									   	300			
#define S_TURTABLE_PAUSING									(S_SCAN_BEGIN+0)
#define S_SCAN_WEB_UI										(S_SCAN_BEGIN+1)
#define S_SCAN_WEB_TESTING									(S_SCAN_BEGIN+2)
#define S_SCAN_BRIGHTNESS									(S_SCAN_BEGIN+3)
#define S_FREE_SCAN_AFTER_PROJECT							(S_SCAN_BEGIN+4)
#define S_SE_TURTABLE_SCAN_AFTER_PROJECT					(S_SCAN_BEGIN+5)
#define PRO_SP_TURTABLE_SCAN_AFTER_PROJECT					(S_SCAN_BEGIN+6)
#define S_SCANING											(S_SCAN_BEGIN+7)
#define S_SINGLE_EDIT_STATE									(S_SCAN_BEGIN+8)
#define S_GROUP_EDIT_STATE									(S_SCAN_BEGIN+9)
#define S_MANUL_ALIGN									    (S_SCAN_BEGIN+10)
#define S_MESH_UI											(S_SCAN_BEGIN+11)
#define S_MESH_RESOLUTION_UI							    (S_SCAN_BEGIN+12)
#define S_MESHING											(S_SCAN_BEGIN+13)
#define S_SIMPLE_DATA_PROCESS_UI							(S_SCAN_BEGIN+14)
#define S_SAVE_PROCESSING								    (S_SCAN_BEGIN+15)
#define S_AFTER_MESH										(S_SCAN_BEGIN+16)
#define FIX_CONTINUE_SCAN									(S_SCAN_BEGIN+17)
#define S_WB_RESTART										(S_SCAN_BEGIN+18)
#define EDIT_DELTEING										(S_SCAN_BEGIN+19)
#define FIX_ALIGING											(S_SCAN_BEGIN+20)
#define SE_SP_HANDLE_AJUST_BRIGHTNESS						(S_SCAN_BEGIN+21)
#define OFFLINE_EDIT_MESH									(S_SCAN_BEGIN+22)


#define S_SCAN_END									   		599

#define PRO_SCAN_BEGIN									   	600			
#define PRO_ENTER_SCAN_UI									(PRO_SCAN_BEGIN+0)
#define PRO_RAPID_SCAN_CONFIG								(PRO_SCAN_BEGIN+1)
#define PRO_FREE_SCAN_AFTER_PROJECT							(PRO_SCAN_BEGIN+2)
#define PRO_TURTABLE_SCAN_AFTER_PROJECT						(PRO_SCAN_BEGIN+3)
#define PRO_HD_SCAN_AFTER_PROJECT							(PRO_SCAN_BEGIN+4)
#define PRO_FIX_SCANING										(PRO_SCAN_BEGIN+5)
#define PRO_HANDLE_SCANING									(PRO_SCAN_BEGIN+6)
#define PRO_HANDLE_SCAN_PAUSE								(PRO_SCAN_BEGIN+7)
#define PRO_HANDLE_SCAN_TICK								(PRO_SCAN_BEGIN+8)
#define PRO_MESH_UI											(PRO_SCAN_BEGIN+9)
#define PRO_MESH_RESOLUTION_UI								(PRO_SCAN_BEGIN+10)
#define PRO_SIMPLE_DATA_PROCESS_UI							(PRO_SCAN_BEGIN+11)
#define PRO_AFTER_MESH_THEN_SAVE							(PRO_SCAN_BEGIN+12)
#define PRO_SVAE_SCALE_UI									(PRO_SCAN_BEGIN+13)
#define PRO_SKETCHFAB_UI									(PRO_SCAN_BEGIN+14)
#define PRO_START_PRESCAN									(PRO_SCAN_BEGIN+15)
#define PRO_PRESCANING										(PRO_SCAN_BEGIN+16)
#define PRO_SCANING										    (PRO_SCAN_BEGIN+17)
#define PRO_PAUSE										    (PRO_SCAN_BEGIN+18)
#define PRO_AFTER_DONE										(PRO_SCAN_BEGIN+19)
#define PRO_MESHING										    (PRO_SCAN_BEGIN+20)
#define PRO_SIMPLIFYING										(PRO_SCAN_BEGIN+21)
#define PRO_AFTERMESH										(PRO_SCAN_BEGIN+22)
#define PRO_SAVING										    (PRO_SCAN_BEGIN+23)
#define PRO_SAVE_PROJECT_PROCESSING							(PRO_SCAN_BEGIN+24)
#define PRO_SCAN_PAUSING_PROCESSING							(PRO_SCAN_BEGIN+25)
#define SE_SP_PRESCANING									(PRO_SCAN_BEGIN+26)
#define OFFLINE_MESH										(PRO_SCAN_BEGIN+27)
#define SCAN_NO_MARKER										(PRO_SCAN_BEGIN+28)


#define PRO_SCAN_END									   	899	

	//class   text_translator : public QObject
	//{
	//	Q_OBJECT
	//public:
	//	static text_translator* instance();
	//	static void un_instance();

	//	QString get_text_string(int type);

	//protected:
	//	explicit text_translator();
	//	~text_translator();

	//};
}

//#define EINSCAN_TRANS(x)  text_translator::instance()->get_text_string(x)

#endif 