

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
#include <qdebug.h>

#include "text_translator.h"
using namespace std;

namespace Sn3DConsumerScanner{


	static const char* text_and_id[] = {
		//% "WARNING: Cannot establish connection to 3D Scanner."
		QT_TRID_NOOP("device_disconnected"),
		//% "WARNING: NO calibration data .Please calibrate the scanner."
		QT_TRID_NOOP("not_calibrate"),
		//% "WARNING:Calibration data lost"
		QT_TRID_NOOP("calibrate_data_lost"),
		//% "WARNING: The license file doesn't match the scanner.\nPlease disable the built - in cameras first and try."
		QT_TRID_NOOP("ple_error_with_build_cam"),
		//% "WARNING: The license file doesn't match the scanner."
		QT_TRID_NOOP("ple_error"),
		//% "WARNING: The turntable is disconnected. Please check connection."
		QT_TRID_NOOP("turntable_disconnect"),
		//% "Loading"
		QT_TRID_NOOP("loading"),
		//% "Next"
		QT_TRID_NOOP("next"),
		//% "Previous"
		QT_TRID_NOOP("last"),
		//% "Calibrate"
		QT_TRID_NOOP("calibrate"),
		//% "WARNING: ( EinScan-S ) Cannot establish connection to 3D Scanner."
		QT_TRID_NOOP("s_disconnect"),
		//% "WARNING: ( EinScan-SE ) Cannot establish connection to 3D Scanner."
		QT_TRID_NOOP("se_disconnect"),
		//% "WARNING: ( EinScan-SP ) Cannot establish connection to 3D Scanner."
		QT_TRID_NOOP("sp_disconnect"),
		//% "WARNING: ( EinScan-Pro ) Cannot establish connection to 3D Scanner."
		QT_TRID_NOOP("pro_disconnect"),
		//% "WARNING: ( EinScan-Pro+ ) Cannot establish connection to 3D Scanner."
		QT_TRID_NOOP("plus_disconnect"),
		//% "EinScan-S\n"
		QT_TRID_NOOP("ensican_s"),
		//% "EinScan-SE\n"
		QT_TRID_NOOP("ensican_se"),
		//% "EinScan-SP\n"
		QT_TRID_NOOP("ensican_sp"),
		//% "EinScan-Pro\n"
		QT_TRID_NOOP("ensican_pro"),
		//% "EinScan-Pro+\n"
		QT_TRID_NOOP("ensican_plus"),
		//% ""
		QT_TRID_NOOP("null_text"),
		//% "Choose Device Type"
		QT_TRID_NOOP("choose_device_type"),
		//% "Choose Scan Mode"
		QT_TRID_NOOP("shoose_scan_mode"),
		//% "Fixed Scan"
		QT_TRID_NOOP("fix_scan"),
		//% "Auto Scan"
		QT_TRID_NOOP("auto_scan"),
		//% "Handheld Rapid Scan\n"
		QT_TRID_NOOP("handle_rapid_scan"),
		//% "Handheld HD Scan\n"),
		QT_TRID_NOOP("handle_hd_scan"),
		//% "%1 Current Status: Handheld HD Scan"
		QT_TRID_NOOP("state_handle_hd_scan"),
		//% "%1 Current Status: Handheld Rapid Scan"
		QT_TRID_NOOP("state_handle_rapid_scan"),
		//% "%1 Current Status: White Light Fixed Scan"
		QT_TRID_NOOP("state_fixed_scan"),
		//% "EinScan-S Current Status: Calibration"
		QT_TRID_NOOP("state_s_calibrate"),
		//% "EinScan-SE Current Status: Calibration"
		QT_TRID_NOOP("state_se_calibrate"),
		//% "EinScan-SP Current Status: Calibration"
		QT_TRID_NOOP("state_sp_calibrate"),
		//% "EinScan-Pro Current Status: Calibration"
		QT_TRID_NOOP("state_pro_calibrate"),
		//% "EinScan-Pro+ Current Status: Calibration"
		QT_TRID_NOOP("state_plus_calibrate"),
		//% "Yes"
		QT_TRID_NOOP("Yes"),
		//% "No"
		QT_TRID_NOOP("No"),
		//% "Start Scan"
		QT_TRID_NOOP("start_scan"),
		//% "Cancel"
		QT_TRID_NOOP("cancel"),
		//% "A new version has been detected,install now?"
		QT_TRID_NOOP("new_version_update"),
		//% "Left Mouse : Rotate"
		QT_TRID_NOOP("left_mouse_rotate"),
		//% "Middle Mouse:Pan"
		QT_TRID_NOOP("mid_mouse_pan"),
		//% "Scroll Wheel:Zoom"
		QT_TRID_NOOP("wheel_zoom"),
		//% "Shift+Left Mouse:Select | Ctrl+Left Mouse:Unselect"
		QT_TRID_NOOP("shift_or_ctrl_and_left_mouse"),
		//% "Ctrl+Left Mouse:Select"
		QT_TRID_NOOP("ctrl_and_left_mouse"),
		//% "Shift+Left Mouse:Select point to start manual align"
		QT_TRID_NOOP("ctrl_and_left_mouse"),
		//% "Delete:Delete selected"
		QT_TRID_NOOP("delete_select"),
		//% "Export model failed!"
		QT_TRID_NOOP("export_failed"),
		//% "3DPrint"
		QT_TRID_NOOP("3dprint"),
		//% "Start 3DPrint software failure, please verify that the 3DPrint software is installed!"
		QT_TRID_NOOP("start_3dprint_failed"),
		//% "Exiting the program will cause data loss.Please wait."
		QT_TRID_NOOP("exit_warning"),
		//% "Open"
		QT_TRID_NOOP("open"),
		//% "Please create mesh data first"
		QT_TRID_NOOP("please_mesh"),
		//% "OK"
		QT_TRID_NOOP("ok"),
		//% "Please create watertight model data first"
		QT_TRID_NOOP("please_watertight_mesh"),
		//% "YES, delete all project scans?"
		QT_TRID_NOOP("yes_to_del_scan"),
		//% "promt"
		QT_TRID_NOOP("prompt"),
		//% "Watertight Model\n"
		QT_TRID_NOOP("watertight_mode"),
		//% "Unwatertight Model\n"
		QT_TRID_NOOP("unwatertight_mode"),
		//% "Verifying..."
		QT_TRID_NOOP("verifying"),
		//% "ROTATE:pressing the left mouse button | MOVE:CTRL + drag the left mouse button | ZOOM:scroll the mouse scroll wheel"
		QT_TRID_NOOP("rotate_move_zoom_short_key"),
		//% "Points"
		QT_TRID_NOOP("points"),
		//% "Triangles"
		QT_TRID_NOOP("triangles"),
		//% "End Scan(Quick Mesh)")
		QT_TRID_NOOP("quick_mesh"),
		//% "\n\n\n\n\n\n\n\nOpen Project   "
		QT_TRID_NOOP("open_project"),
		//% "\n\n\n\n\n\n\n\nNew Project   "
		QT_TRID_NOOP("new_project"),
		//% "Mesh PointClound... %p%"
		QT_TRID_NOOP("mesh_clound"),
		//% "PointCloundProcessing... %p%"
		QT_TRID_NOOP("point_clound_processing"),
		//% "SaveProcessing... %p%"
		QT_TRID_NOOP("save_processing"),
		//% "Scaning... %p%"
		QT_TRID_NOOP("scaning"),
		//% "Deselect"  
		QT_TRID_NOOP("deselect"),
		//% "Revert"
		QT_TRID_NOOP("revert"),
		//% "Delete"
		QT_TRID_NOOP("delete"),
		//% "Redo"
		QT_TRID_NOOP("redo"),
		//% "Undo"
		QT_TRID_NOOP("undo"),
		//% "Show/Hide Stripes"
		QT_TRID_NOOP("show_hide_stripes"),
		//% "Mesh"
		QT_TRID_NOOP("mesh"),
		//% "Save Your Scan"
		QT_TRID_NOOP("save_your_scan"),
		//% "Back to Home"
		QT_TRID_NOOP("back_to_home"),
		//% "Delete Your Scan"),//Delete
		QT_TRID_NOOP("delete_scan"),
		//% "Pause"
		QT_TRID_NOOP("pause"),
		//% "Project"
		QT_TRID_NOOP("project"),
		//% "Align"
		QT_TRID_NOOP("align"),
		//% "Share Your Scan"
		QT_TRID_NOOP("share_scan"),
		//% "Adjust Brightness"
		QT_TRID_NOOP("adjust_brightness"),
		//% "Print Your Scan"
		QT_TRID_NOOP("print_your_scan"),
		//% "Start white balance"
		QT_TRID_NOOP("start_white_balance"),
		//% "White balance test, please wait"
		QT_TRID_NOOP("please_wait_wb_test"),
		//% "Make sure the input value >=1"   
		QT_TRID_NOOP("input_greate_1"),
		//% "Scaling ratio"
		QT_TRID_NOOP("scaling_ratio"),
		//% "After scaling(mm)"
		QT_TRID_NOOP("after_scaling"),
		//% "Original size(mm)"
		QT_TRID_NOOP("original_size"),
		//% "\n\n\n\n\n\n\nHigh detail"
		QT_TRID_NOOP("high_detail"),
		//% "\n\n\n\n\n\n\nMedium detail"
		QT_TRID_NOOP("medium_detail"),
		//% "\n\n\n\n\n\n\nLow detail"
		QT_TRID_NOOP("low_detail"),
		//% "Please select detail" //s固定扫描配置对话框102
		QT_TRID_NOOP("please_sel_detail"),
		//% "Apply"
		QT_TRID_NOOP("apply"),
		//% "Select Texture"
		QT_TRID_NOOP("sel_texture"),
		//% "Choose high detail"
		QT_TRID_NOOP("choose_high_detail"),
		//% "Choose low detail"
		QT_TRID_NOOP("choose_low_detail"),
		//% "Choose medium detail"
		QT_TRID_NOOP("choose_medium_detail"),
		//% "Select detail of scaning"),
		QT_TRID_NOOP("choose_medium_detail"),
		//% "Select Mesh Mode"
		QT_TRID_NOOP("sel_mesh_mode"),
		//% "Texture Scan"
		QT_TRID_NOOP("texture_scan"),
		//% "Non-texture Scan"
		QT_TRID_NOOP("non_texture_scan"),
		//% "Open global markers file"),//PRO固定扫描配置 114
		QT_TRID_NOOP("open_global_markers_file"),
		//% "All(*.p3 *.asc *.txt)"
		QT_TRID_NOOP("file_p3_asc_txt"),
		//% "Global markers file is not exist"
		QT_TRID_NOOP("global_markers_file_not_exist"),
		//% "Browse"
		QT_TRID_NOOP("browse"),
		//% "Open global markers file:"
		QT_TRID_NOOP("open_global_markers_file_colon"),
		//% "Make sure simplification ratio 1 - 100")
		QT_TRID_NOOP("simply_ration_rang"),
		//% "Suggested perimeter range 10 - 100mm"
		QT_TRID_NOOP("perimeter_rang"),
		//% "STL (MB):"
		QT_TRID_NOOP("stl_mb"),
		//% "OBJ (MB):"
		QT_TRID_NOOP("obj_mb"),
		//% "Original size"
		QT_TRID_NOOP("original_size"),
		//% "Post Simplification"
		QT_TRID_NOOP("post_simply"),
		//% "Polygons:"
		QT_TRID_NOOP("polygons"),
		//% "Simplification"
		QT_TRID_NOOP("simplification"),
		//% "Hole-filling:choose 10-100mm perimeter to fill the hole"
		QT_TRID_NOOP("hole_fill_perimeter"),
		//% "mm"
		QT_TRID_NOOP("mm"),
		//% "Hole Filling"
		QT_TRID_NOOP("hole_fill"),
		//% "Markers"
		QT_TRID_NOOP("markers"),
		//% "Simplification ratio"
		QT_TRID_NOOP("simply_ration"),
		//% "Please select resolution first"  //PRO手持扫描配置对话框 134
		QT_TRID_NOOP("please_select_resolution"),
		//% "More setting of Resolution"  //Others
		QT_TRID_NOOP("setting_of_resolution"),
		//% "Select Resolution"
		QT_TRID_NOOP("select_resolution"),
		//% "Feature"
		QT_TRID_NOOP("feature"),
		//% "Bright" //亮度调节对话框 141
		QT_TRID_NOOP("bright"),
		//% "Dark"
		QT_TRID_NOOP("dark"),
		//% "Dark/difficult to scan:<font  size='2'><br>Choose for objects difficult to scan, such as dark, gloomy, shiny or fuzzy.</font>"
		QT_TRID_NOOP("dark_explaint"),
		//% "Bright&Dark:<font size = '2'><br><br>Choose for objects bright and dark< / font>"
		QT_TRID_NOOP("bright_dark_explaint"),
		//% "Medium:<font   size='2'><br><br>Choose for objects neither bright or dark</font>"
		QT_TRID_NOOP("medium_explaint"),
		//% "Select the shade that most closely matches your object"
		QT_TRID_NOOP("shade_explaint"),
		//% "Bright:<font  size='2'><br><br>Choose for light color objects</font>"
		QT_TRID_NOOP("bright_explaint"),
		//% "Tracking Lost" //手持扫描界面 148
		QT_TRID_NOOP("tracking_lost"),
		//% "Too Close"
		QT_TRID_NOOP("too_close"),
		//% "Too Far"
		QT_TRID_NOOP("too_far"),
		//% "Tracking Lost\nMove back to the scanned area and stay 3s"
		QT_TRID_NOOP("tracking_lost_handle"),
		//% "Generate point clouds" //Finish Scan
		QT_TRID_NOOP("generate_point_cloud"),
		//% "Predicted Scan"
		QT_TRID_NOOP("predicted_scan"),
		//% "Snap"
		QT_TRID_NOOP("snap"),
		//% "Exit"
		QT_TRID_NOOP("exit"),
		//% "Skip"
		QT_TRID_NOOP("skip"),
		//% "Accuracy\nDiagnostic"
		QT_TRID_NOOP("accuracy"),
		//% "Calibration success, the window will close..."
		QT_TRID_NOOP("calibration_success"),
		//% "WB Calibration is OK"
		QT_TRID_NOOP("wb_calibration_ok"),
		//% "Capturing...\nCurrent progress:%1 %"
		QT_TRID_NOOP("capturing_progress"),
		//% "Calibrating...\nCurrent progress:%1%" // padding=\"0\" padding=\"0\"border-spacing=\"0
		QT_TRID_NOOP("calibrating_progress"),
		//% "<br/><table border = \"0\" cellspacing=\"0\" ><tr><td align=\"left\">To ensure successful calibration:</td></tr></table><table border = \"0\" cellspacing=\"0\" ><tr><td width=\"30px\">1.</td><td align=\"left\">Do not move the calibration board when calibrating.</td><td></td></tr><tr><td width=\"30px\">2.</td><td align=\"left\">Make sure the calibration board is not damaged.</td></tr><tr><td width=\"30px\">3.</td><td align=\"left\">Make sure the pattern is facing the scanner.</td></tr><tr><td width=\"30px\">4.</td><td align=\"left\">Rotate the calibration board, but ensure the stand doesn't move.</td></tr></table>"),
		QT_TRID_NOOP("s_calibrate_explaint"),
		//% "Loading..." //163
		QT_TRID_NOOP("loading_and_dot"),
		//% "Place the Calibration support and board in the center of the turntable as shown in Figure A."
		QT_TRID_NOOP("s_calibrate_a"),
		//% "Group A Capturing...\nCurrent progress:0%" //165
		QT_TRID_NOOP("s_calibrate_capture_a"),
		//% "Rotate the Calibration Board as shown in Figure B."
		QT_TRID_NOOP("s_calibrate_b"),
		//% "Group B Capturing...\nCurrent progress:0%"
		QT_TRID_NOOP("s_calibrate_capture_b"),
		//% "Rotate the Calibration Board as shown in Figure C."
		QT_TRID_NOOP("s_calibrate_c"),
		//% "Group C Capturing...\nCurrent progress:0%"
		QT_TRID_NOOP("s_calibrate_capture_c"),
		//% "Calibrating...\nCurrent progress:0%" //170
		QT_TRID_NOOP("calibrate_progress0"),
		//% "Calibration failed.\nPlease follow the instrution and recalibrate."
		QT_TRID_NOOP("s_calibrate_failed"),
		//% "Calibration Success"
		QT_TRID_NOOP("s_calibrate_success"),
		//% "White balance test,please click snap"
		QT_TRID_NOOP("wb_test_prompt"),
		//% "White balance testing,please wait..." //174
		QT_TRID_NOOP("wb_testint"),
		//% "Snap State: on"
		QT_TRID_NOOP("snap_on"),
		//% "Snap State: off"
		QT_TRID_NOOP("snap_off"),
		//% "Camera\nCalibration"
		QT_TRID_NOOP("camera_calib"),
		//% "HD Calibration"
		QT_TRID_NOOP("hd_calib"),
		//% "Color Camera white balance"
		QT_TRID_NOOP("color_cam_wb"),
		//% "Calibration Board SN:"
		QT_TRID_NOOP("calibrate_board_sn"),
		//% "HD Calibration complete\nHD Calibration Tolerance: %1 mm"
		QT_TRID_NOOP("hd_calibrate_tolerance"),
		//% "Camera Calibration success \nCamera Calibration Tolerance: %1 Pixel"
		QT_TRID_NOOP("cam_calibrate_tolerance"),
		//% "( with turntable )"
		QT_TRID_NOOP("with_turntable"),
		//% "( without turntable )"
		QT_TRID_NOOP("without_turntable"),
		//% "White Balance"
		QT_TRID_NOOP("white_balance"),
		//% "Preview"//187-Start Scan Preview
		QT_TRID_NOOP("preview"),
		//% "Place a white paper to do white balance testing" //188
		QT_TRID_NOOP("wb_instrument"),
		//% "Test Tolerance:%1mm" //189
		QT_TRID_NOOP("test_tolerance"),
		//% "<table border=\"0\"><tr><td>1.</td><td>Place the calibration board flat on the table back side up as shown.</td></tr><tr><td>2.</td><td>Point the scanner to the calibration board, click <img  width=25 height=25 src=\"res/background/Calib/on_off.png\"> to capture images.</td></tr><tr><td>3.</td><td>Hold the scanner and move from the bottom up steadily till each box is ticked.</td></tr></table>"
		QT_TRID_NOOP("pro_cam_calib_explaint"),
		//% "<table border = \"0\"><tr><td>1.</td><td>Place the calibration board as shown on the screen.Please note the direction of the 4 big white circles.</td></tr><tr><td>2.</td><td>Point the scanner to the calibration board, shooting the cross onto the white box.</td></tr><tr><td>3.</td><td>Click <img width=25 height=25 src = \"res/background/Calib/on_off.png\"> to capture images.</td></tr><tr><td>4.</td><td>Hold the scanner and move from the bottom up steadily till each box is ticked.</td></tr></table>"
		QT_TRID_NOOP("pro_hd_calib_explaint"),
		//% "<table border=\"0\"><tr><td>1.</td><td>Place the calibration board flat on the table back side up as shown</td></tr><tr><td>2.</td><td>Point the scanner to the calibration board, click <img  width=25 height=25 src = \"res/background/Calib/on_off.png\"> to capture images.</td></tr><tr><td>3.</td><td>Hold the scanner and move from the bottom up steadily till one box is ticked.</td></tr></table>"
		QT_TRID_NOOP("pro_wb_calib_explaint"),
		//% "Hole Length" //193
		QT_TRID_NOOP("hole_length"),
		//% "Project Loading " //194
		QT_TRID_NOOP("project_loading"),
		//% "New Project " //195
		QT_TRID_NOOP("new_project_only"),
		//% "Cannot Scan" //196
		QT_TRID_NOOP("cannot_scan"),
		//% "Delete the current data" //197
		QT_TRID_NOOP("del_scan"),
		//% "Click Here" //197
		QT_TRID_NOOP("click_here"),
		//% "The device's cable is loose, please reconnect it and reopen the software." //TEXT_DEVICE_OFFINE
		QT_TRID_NOOP("device_offline"),
		//% "Click <img  width=25 height=25 src = \"res/background/Calib/device_add.png\"> or <img  width=25 height=25 src = \"res/background/Calib/device_sub.png\"> of scanner to adjust brighness.Adjust until lines all appear on the object and can be seen completely."),//TEXT_HD_ADJUST_BRIGHTNESS
		QT_TRID_NOOP("hd_adjust_bright"),
		//% "Click <img  width=25 height=25 src = \"res/background/Calib/device_add.png\"> or <img  width=25 height=25 src = \"res/background/Calib/device_sub.png\"> of scanner to adjust brighness.Adjust until speckle pattern is clear, the object appears red slightly"),//TEXT_SPEAKER_ADJUST_BRIGHTNESS
		QT_TRID_NOOP("speckle_adjust_bright"),
		//% "Double-click <img  width=25 height=25 src = \"res/background/Calib/on_off.png\"> of scanner to adjust brighness."),//TEXT_DOUBLE_CLICK_ADJUST_BRIGHTNESS
		QT_TRID_NOOP("adjust_bright"),
		//% "Click here after all scans are done"
		QT_TRID_NOOP("click_after_scan_done"),
		//% "A new version has been detected,download now?"
		QT_TRID_NOOP("new_version_for_dowload"),
		//% "Discovery Scan"
		QT_TRID_NOOP("discovery_scan"),
		//% "General Scan" 
		QT_TRID_NOOP("general_scan"),
		//% "The device is Offline"
		QT_TRID_NOOP("device_is_offline"),
		//% "%1 Current Status : Choose Working Mode"
		QT_TRID_NOOP("state_choose_working_mode"),
		//% "Choose Working Mode"
		QT_TRID_NOOP("choose_working_mode"),
		//% "EinScan-Discovery Current Status: Calibration"
		QT_TRID_NOOP("state_discovery_calibrate"),
		//% "EinScan-Discovery\n"
		QT_TRID_NOOP("einscan_discovery"),
		//% "WARNING: ( EinScan-Discovery) Cannot establish connection to 3D Scanner."
		QT_TRID_NOOP("discovery_disconnect"),
		//% "Optimize the texture"
		QT_TRID_NOOP("optimize_texture"),
		//% "It takes more time to optimize the texture"),
		QT_TRID_NOOP("optimize_texture_note"),
		//% "Space Key: End Editting"
		QT_TRID_NOOP("space_key_end_edit"),
		//% "Space Key: Start Scan"
		QT_TRID_NOOP("space_key_start_scan"),
		//% "Scanning"
		QT_TRID_NOOP("scaning"),
		//% "Markers are required to scan flat objects"
		QT_TRID_NOOP("markers_to_scan_flat"),
		//% "Preview object with markers"
		QT_TRID_NOOP("preview_with_marker"),
		//% "Insufficient memory"
		QT_TRID_NOOP("insufficient_memory"),
		//% "Insufficient disk space"
		QT_TRID_NOOP("insufficient_disk"),
		//% "The memory is insufficient, do you want save the project?"
		QT_TRID_NOOP("memory_insufficient_to_save"),
		//% "The memory is insufficient, please change to a computer with higher configuration."
		QT_TRID_NOOP("memory_insufficient_prompt"),
		//% "Discovery Calibrate"
		QT_TRID_NOOP("discovery_calibrate"),
		//% "Switching to feature scan"
		QT_TRID_NOOP("switching_to_feature_scan"),
		//% "Prime"
		QT_TRID_NOOP("prime"),
		//% "SolidEdge"
		QT_TRID_NOOP("solidedge"),
		//% "Please create mesh model data first"
		QT_TRID_NOOP("please_mesh_mode"),
		//% "Texture layout optimization")
		QT_TRID_NOOP("texture"),
		//% "\n\n\n\n\n\nUsing Light Box"
		QT_TRID_NOOP("use_light_box"),
		//% "\n\n\n\n\n\nNo Light Box"
		QT_TRID_NOOP("no_light_box"),
		//% "Save Project"
		QT_TRID_NOOP("save_project"),
		//% "WARNING: NO Prime calibration data .Please calibrate the scanner."
		QT_TRID_NOOP("no_prime_calib_data"),
		//% "WARNING: The license file doesn't match the Prime."
		QT_TRID_NOOP("prime_license_error"),
		//% "WARNING: The discovery license file doesn't match the scanner."
		QT_TRID_NOOP("discovery_license_error"),
		//% "WARNING: Please change to USB3.0"
		QT_TRID_NOOP("change_to_usb3"),
		//% "No markers detected"
		QT_TRID_NOOP("no_markers"),
		//% "No data scanned"
		QT_TRID_NOOP("no_data_scanned"),
		//% "Calibrate Data Exception,Please ReCalibrate"
		QT_TRID_NOOP("please_recalibrate"),
		//% "Please input 10-100mm perimeter to fill the hole"
		QT_TRID_NOOP("please_input_perimeter"),
		//% "The device's cable is loose, please reconnect it; Software is reconnecting."
		QT_TRID_NOOP("offline_reconnecting"),
		//% "Scanning Pause"
		QT_TRID_NOOP("scanning_pause"),
		//% "Place a white paper and click the button"
		QT_TRID_NOOP("fix_wb_note"),
		//% "Do not move object or scanner during scanning"
		QT_TRID_NOOP("fix_scanning_note"),
		//% "Place object, adjust distance and brightness"
		QT_TRID_NOOP("fix_note_before_scan"),
		//% "Start scan/Set turntable steps"
		QT_TRID_NOOP("start_scan_set_turntable_steps"),
		//% "Start scan/Set turntable steps/Choose align mode"
		QT_TRID_NOOP("set_turntable_steps_and_align_mode"),
		//% "Edit Data"
		QT_TRID_NOOP("edit_data"),
		//% "Continue Scan/Mesh"
		QT_TRID_NOOP("continue_scan_mesh"),
		//% "In the panes on the left, click three common points between A and B"
		QT_TRID_NOOP("manua_align"),
		//% "Watertight:is useful for 3d printing Unwateright: for design"
		QT_TRID_NOOP("watertight_explaint"),
		//% "That the higher the level of detail, the larger file size will be"
		QT_TRID_NOOP("higher_detail_note"),
		//% "Meshing"
		QT_TRID_NOOP("meshing"),
		//% "Post Processing"
		QT_TRID_NOOP("post_processing"),
		//% "Save Processing"
		QT_TRID_NOOP("save_processing")
		//% "Save/Share the Data"
		QT_TRID_NOOP("save_share_data"),
		//% "Continue Scan"
		QT_TRID_NOOP("continue_scan"),
		//% "Restarting white balance"
		QT_TRID_NOOP("restart_wb"),
		//% "Deleting"
		QT_TRID_NOOP("deleting"),
		//% "Group Aligning"
		QT_TRID_NOOP("group_align"),
		//% "Adjust brightness"
		QT_TRID_NOOP("addjust_brightness"),
		//% "Data Editing/Meshing"
		QT_TRID_NOOP("data_editing_meshing"),
		//% "Choose align mode,texture and resolution"
		QT_TRID_NOOP("choose_align_texture_resolution"),
		//% "Place object,adjust distance and brightness\nStart scan"
		QT_TRID_NOOP("object_adjust_distance_brightness_to_scan"),
		//% "Place object,adjust distance and brightness\nSet turntable steps and choose align mode\nStart scan"
		QT_TRID_NOOP("adjust_distance_brightness_turntable_to_scan"),
		//% "Adjust distance and brightness\nStart scan"
		QT_TRID_NOOP("adjust_distance_brightness_to_scan"),
		//% "Adjust brightness according to the object"
		QT_TRID_NOOP("adjust_brightness_to_object"),
		//% "Hold shift+left mouse to select excess parts, and delete;\nSave data"
		QT_TRID_NOOP("edit_and_save"),
		//% "Data Saving"
		QT_TRID_NOOP("data_saving"),
		//% "Start Scan Preview"
		QT_TRID_NOOP("start_scan_preview"),
		//% "Double-click to adjust brightness. Click SCAN to start"
		QT_TRID_NOOP("doubleclick_adjust_brightness"),
		//% "Data Editing/Save Project"
		QT_TRID_NOOP("editing_or_save"),
		//% "Continue Scan/Meshing"
		QT_TRID_NOOP("continue_scan_or_meshing"),
		//% "Data Processing"
		QT_TRID_NOOP("handle_meshing"),
		//% "Pause Processing:Save project"
		QT_TRID_NOOP("pause_processing"),
		//% "Adjust brightness. Click SCAN to start"
		QT_TRID_NOOP("se_sp_prescaning"),
		QT_TRID_NOOP("se_sp_prescaning"),
		0
	};
}

